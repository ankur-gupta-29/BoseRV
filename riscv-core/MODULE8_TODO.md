# Module 8 — Core Peripherals (CLINT, UART, MMIO): Learning Checklist

Work top-to-bottom. Each assignment builds on the previous.
Rule: **you write all Verilog logic**. Ask teacher for hints if stuck.

---

## Why Do We Need This?

A processor alone can't do anything useful without I/O:
- **CLINT** (Core Local Interruptor): Timer that generates timer interrupts
- **UART** (Universal Asynchronous Receiver/Transmitter): Serial communication (printf-like output)
- **MMIO** (Memory-Mapped I/O): Peripherals appear at fixed memory addresses

```
CPU Memory Space:
0x00000000 - 0x7FFFFFFF  ← Normal RAM
0x02000000 - 0x0200FFFF  ← CLINT (timer, software interrupt)
0x10000000 - 0x10000100  ← UART (serial I/O)
0x80000000+              ← Kernel code (where OpenSBI runs)
```

---

## Assignment H1 — Memory-Mapped I/O (MMIO) Router

**File:** `src/mmio_router.v` (NEW — you create this)
**Goal:** Decode memory address, route reads/writes to correct peripheral.

### Concept: Address Decoding

Instead of "memory at address X", we now have "device at address range Y".

```
Address [31:28]:  Selects region
  0000 = Normal memory (0x00000000-0x0FFFFFFF)
  0010 = CLINT       (0x02000000-0x020FFFFF)
  1000 = Kernel      (0x80000000-0xFFFFFFFF)
  1000 = Undefined  → Error / exception
```

### Step 1 — Create `src/mmio_router.v`

- [ ] Declare module:
  - Inputs: `addr [31:0]`, `data_in [31:0]`, `mem_read`, `mem_write`
  - Outputs: `data_out [31:0]`, `device_sel [3:0]` (which peripheral), `device_read/write`

- [ ] Implement address decoding:
  ```verilog
  wire [3:0] region = addr[31:28];
  
  always @(*) begin
    case (region)
      4'h0: device_sel = 4'b0001;  // Normal memory
      4'h2: device_sel = 4'b0010;  // CLINT
      4'h1: device_sel = 4'b0100;  // UART
      4'h8: device_sel = 4'b1000;  // Kernel space (normal memory)
      default: device_sel = 4'b0000;  // Error
    endcase
  end
  ```

- [ ] Mux reads based on which device:
  ```verilog
  data_out = (device_sel == CLINT) ? clint_data :
             (device_sel == UART) ? uart_data :
             (device_sel == RAM) ? ram_data :
             32'hxxxxxxxx;
  ```

- [ ] **Test:** Run `make py_mmio` — address routing correct

**Concept check:**
> What happens if code at address 0x80000000 (kernel space) tries to write to 0x02000000 (CLINT)? Should it be allowed?

---

## Assignment H2 — CLINT (Core Local Interruptor / Timer)

**File:** `src/clint.v` (NEW — you create this)
**Goal:** Implement timer registers that generate timer interrupts.

### Concept: CLINT Registers

CLINT has 3 key registers (each 64-bit, but we're 32-bit so use pairs):

```
mtime     (0x0200BFF8): Current time (increments every cycle)
mtimecmp  (0x02004000): Timer compare register — when mtime >= mtimecmp, interrupt fires
msip      (0x02000000): Software interrupt (write 1 to raise, write 0 to clear)
```

When `mtime >= mtimecmp`, set `timer_interrupt` signal → CPU takes trap.

### Step 1 — Create `src/clint.v`

- [ ] Declare module:
  - Inputs: `clk, rst`, `addr [31:0]`, `data_in [31:0]`, `mem_read`, `mem_write`
  - Outputs: `data_out [31:0]`, `timer_interrupt`, `software_interrupt`
  > These are **separate** interrupt types with different mcause codes:
  > Timer: `mcause = 0x80000007`, Software: `mcause = 0x80000003`

- [ ] Implement 64-bit mtime counter:
  ```verilog
  reg [63:0] mtime;
  reg [63:0] mtimecmp;
  reg msip;
  
  always @(posedge clk or posedge rst) begin
    if (rst) begin
      mtime <= 64'h0;
      mtimecmp <= 64'hFFFFFFFFFFFFFFFF;
      msip <= 1'b0;
    end else begin
      mtime <= mtime + 1;  // Increment each cycle
      
      // Write mtime from CPU
      if (mem_write && addr[7:0] == 8'hF8) begin
        mtime <= {mtime[63:32], data_in};  // Write low 32 bits
      end
      if (mem_write && addr[7:0] == 8'hFC) begin
        mtime <= {data_in, mtime[31:0]};   // Write high 32 bits
      end
      
      // Write mtimecmp
      if (mem_write && addr[15:0] == 16'h4000) begin
        mtimecmp <= {mtimecmp[63:32], data_in};
      end
      if (mem_write && addr[15:0] == 16'h4004) begin
        mtimecmp <= {data_in, mtimecmp[31:0]};
      end
      
      // Write msip (software interrupt)
      if (mem_write && addr[15:0] == 16'h0000) begin
        msip <= data_in[0];
      end
    end
  end
  
  // Two separate interrupt signals — different mcause codes
  assign timer_interrupt    = (mtime >= mtimecmp);  // mcause = 0x80000007
  assign software_interrupt = msip;                  // mcause = 0x80000003
  ```

- [ ] Implement read logic (return mtime, mtimecmp, or msip based on address)

- [ ] **Test:** Run `make py_clint` — timer increments, interrupt fires when mtime >= mtimecmp

**Concept check:**
> If you set mtimecmp = 0, does the timer immediately fire forever? How would you clear it?

---

## Assignment H3 — UART (Simple Serial Output)

**File:** `src/uart.v` (NEW — you create this)
**Goal:** Simple UART that prints characters to stdout (for simulation).

### Concept: UART Registers

In simulation, we just write to stdout. Real UART has:

```
tx_data  (0x10000000): Write character here to transmit
tx_stat  (0x10000004): Status (ready to transmit?)
rx_data  (0x10000008): Read received character
rx_stat  (0x1000000C): Status (character available?)
```

### Step 1 — Create `src/uart.v`

- [ ] Declare module:
  - Inputs: `clk, rst`, `addr [31:0]`, `data_in [31:0]`, `mem_read`, `mem_write`
  - Outputs: `data_out [31:0]`

- [ ] Implement simple TX:
  ```verilog
  always @(posedge clk) begin
    if (mem_write && addr == 32'h10000000) begin
      // Write to TX data — print character
      $write("%c", data_in[7:0]);  // Print ASCII character
      $fflush();
    end
  end
  
  // Always ready (no buffering in simulation)
  assign data_out = (addr == 32'h10000004) ? 32'h00000001 : 32'h00000000;
  ```

- [ ] **Test:** Run simple program that writes characters via UART, see output

**Concept check:**
> In real hardware, why can't you transmit characters infinitely fast? What limits UART speed?

---

## Assignment H4 — Integrate Peripherals into Pipeline

**Goal:** Wire CLINT and UART into the memory system, receive timer interrupts.

### Step 1 — Replace Memory with MMIO Router

- [ ] In `pipe_top.v`, instead of direct dmem connection:
  ```verilog
  mmio_router router_inst (
    .addr(alu_result_MEM),
    .data_in(rs2_data_MEM),
    .mem_read(mem_read_MEM), .mem_write(mem_write_MEM),
    .data_out(mem_data),
    .clint_en(clint_en), .uart_en(uart_en), .ram_en(ram_en)
  );
  ```

### Step 2 — Connect CLINT

- [ ] Instantiate CLINT:
  ```verilog
  clint clint_inst (
    .clk(clk), .rst(rst),
    .addr(alu_result_MEM),
    .data_in(rs2_data_MEM),
    .mem_read(mem_read_MEM & clint_en),
    .mem_write(mem_write_MEM & clint_en),
    .data_out(clint_data),
    .timer_interrupt(timer_int)
  );
  ```

- [ ] Connect timer interrupt to exception handling:
  ```verilog
  timer_interrupt = timer_int;
  ```

### Step 3 — Connect UART

- [ ] Instantiate UART (prints to stdout in simulation):
  ```verilog
  uart uart_inst (
    .clk(clk), .rst(rst),
    .addr(alu_result_MEM),
    .data_in(rs2_data_MEM),
    .mem_read(mem_read_MEM & uart_en),
    .mem_write(mem_write_MEM & uart_en),
    .data_out(uart_data)
  );
  ```

### Step 4 — Test Peripherals

- [ ] Write test program:
  ```asm
  LUI x1, 0x02000  # Load CLINT base address
  LI x2, 0x10000  # Load value 100000 (for timer)
  SW x2, 0x4000(x1)  # Write to mtimecmp
  
  # Enable interrupts in mstatus
  LI x3, 0x8  # MIE = bit 3
  CSRRW x0, mstatus, x3
  
  # Enable timer interrupt in mie
  LI x4, 0x80  # Timer = bit 7 in mie
  CSRRW x0, mie, x4
  
  # Infinite loop
  LOOP: BEQ x0, x0, LOOP
  ```

- [ ] **Test:** Run `make py_pipe_top`, verify:
  - Timer increments
  - When mtime >= mtimecmp, timer_interrupt signal asserts
  - CPU takes trap, jumps to mtvec

**Concept check:**
> If the timer interrupt handler never runs, will the timer_interrupt keep firing every cycle?

---

## Completion Gate

Before calling Module 8 done:
- [ ] `make py_mmio` passes address routing tests
- [ ] `make py_clint` passes timer increment and interrupt tests
- [ ] `make py_uart` receives character output
- [ ] `make py_pipe_top` integrates all peripherals
- [ ] Timer interrupts are caught and trigger exception handler
- [ ] You can explain: why MMIO instead of separate I/O instructions?

---

## Files Changed in Module 8

| File | Change |
|------|--------|
| `src/mmio_router.v` | [NEW] Address decoder, routes to RAM/CLINT/UART |
| `src/clint.v` | [NEW] Timer (mtime, mtimecmp), software interrupt (msip) |
| `src/uart.v` | [NEW] UART TX (simple stdout write in sim) |
| `src/pipe_top.v` | [MODIFY] Replace dmem with MMIO router, connect CLINT/UART |

---

## MMIO Address Map

```
0x00000000 - 0x01FFFFFF  ← Normal RAM (32 MB)
0x02000000 - 0x0200FFFF  ← CLINT (timer, software interrupt)
  0x0200BFF8 ← mtime (low)
  0x0200BFFC ← mtime (high)
  0x02004000 ← mtimecmp (low)
  0x02004004 ← mtimecmp (high)
  0x02000000 ← msip (software interrupt)
0x10000000 - 0x10000FFF  ← UART (serial I/O)
  0x10000000 ← TX data (write to print)
  0x10000004 ← TX status (always ready in sim)
  0x10000008 ← RX data (not used in this course)
  0x1000000C ← RX status (not used)
0x80000000 - 0xFFFFFFFF  ← Kernel space (OpenSBI, Linux kernel)
```
