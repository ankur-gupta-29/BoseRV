# Module 5 — M-Extension (Multiply/Divide): Learning Checklist

Work top-to-bottom. Each assignment builds on the previous.
Rule: **you write all Verilog logic**. Ask teacher for hints if stuck.

---

## Why Do We Need This?

The base RV32I has no multiplication or division. Multiplying two 32-bit numbers requires:
- **MUL**: combinational (1 cycle)
- **DIV**: iterative (up to 32 cycles) → stalls the pipeline while computing

M-Extension adds 8 new instructions, all with `funct7 = 0000001`:

```
MUL, MULH, MULHSU, MULHU  — multiplication (get low or high result)
DIV, DIVU                  — signed/unsigned division
REM, REMU                  — signed/unsigned remainder
```

---

## Assignment E1 — Multiplier Unit (Hardware Multiplication)

**File:** `src/multiplier.v` (NEW — you create this)
**Goal:** Build a 32×32 → 64-bit multiplier in one cycle.

### Concept: Multiplication Variants

M-Extension provides 4 multiply operations (all use same hardware, different output):

```
MUL     x3, x1, x2   → x3 = (x1 * x2)[31:0]        (low 32 bits)
MULH    x3, x1, x2   → x3 = (x1 * x2)[63:32]       (high 32 bits, signed)
MULHSU  x3, x1, x2   → x3 = (x1 * x2_unsigned)[63:32]  (x1 signed, x2 unsigned)
MULHU   x3, x1, x2   → x3 = (x1 * x2)[63:32]       (high 32 bits, unsigned)
```

Internally: use a single 32×32 multiplier, extract [63:32] or [31:0] based on funct3.

### Step 1 — Create `src/multiplier.v`

- [ ] Declare module:
  - Inputs: `a [31:0]`, `b [31:0]`, `funct3 [2:0]` (to select MUL vs MULH variants)
  - Output: `result [31:0]`

- [ ] Implement 32-bit × 32-bit → 64-bit multiplication:
  ```verilog
  wire [63:0] product = $signed(a) * $signed(b);  // Signed multiply
  ```

- [ ] Implement funct3 decoding:
  ```
  3'b000 (MUL)    → return product[31:0]
  3'b001 (MULH)   → return $signed(product[63:32])
  3'b010 (MULHSU) → return ($signed(a) * $unsigned(b))[63:32]
  3'b011 (MULHU)  → return $unsigned(product[63:32])
  ```

- [ ] **Test:** Run `make py_multiplier` — all multiply variants pass

**Concept check:**
> Why do we need separate signed, unsigned, and mixed variants? Why not just one multiply instruction?

---

## Assignment E2 — Divider Unit (Iterative Division)

**File:** `src/divider.v` (NEW — you create this)
**Goal:** Build a state machine that divides over 32 cycles.

### Concept: Long Division in Hardware

Division takes time — instead of a combinational circuit (huge and slow), we use a **state machine**:

```
Cycle 0: Load a, b, start dividing
Cycle 1-31: Shift and subtract iteratively
Cycle 32: Output quotient, remainder
```

Signals:
- `start` — pulse to begin division
- `busy` — 1 if dividing, 0 when result ready
- `done` — pulse when result is ready

### Step 1 — Create `src/divider.v`

- [ ] Declare module:
  - Inputs: `clk, rst`, `a [31:0]` (dividend), `b [31:0]` (divisor), `funct3 [2:0]`, `start`
  - Outputs: `result [31:0]` (quotient or remainder), `busy`, `done`

- [ ] Implement restoring bit-serial division (32 cycles — one dividend bit per cycle):
  ```verilog
  // Standard restoring division:
  // A[63:32] = partial remainder, A[31:0] = remaining dividend bits
  // Each cycle: shift A left by 1, test if upper 32 bits >= divisor
  // If yes: subtract divisor, set quotient bit
  reg [63:0] A;       // Working register
  reg [31:0] M;       // Divisor (unsigned)
  reg [5:0]  counter; // 0 = idle, 1-32 = active, 33 = done
  
  always @(posedge clk or posedge rst) begin
    if (rst) begin
      counter <= 0;
    end else if (start && counter == 0) begin
      A       <= {32'b0, a_unsigned};  // Load dividend into lower 32 bits
      M       <= b_unsigned;
      counter <= 1;
    end else if (counter >= 1 && counter <= 32) begin
      A <= A << 1;  // Shift left (bring next dividend bit into partial remainder)
      if (A[63:32] >= M) begin
        A[63:32] <= A[63:32] - M;
        A[0]     <= 1'b1;  // Set quotient bit
      end
      counter <= counter + 1;
    end else if (counter == 33) begin
      counter <= 0;  // Reset to idle
    end
  end
  
  // Quotient = A[31:0], Remainder = A[63:32]
  assign busy = (counter > 0 && counter < 33);
  assign done = (counter == 33);
  ```
  > Note: handle sign separately — negate inputs for signed ops, negate outputs as needed.

- [ ] Handle signed vs unsigned:
  ```
  funct3 = 3'b100 (DIV)   → signed division
  funct3 = 3'b101 (DIVU)  → unsigned division
  funct3 = 3'b110 (REM)   → signed remainder
  funct3 = 3'b111 (REMU)  → unsigned remainder
  ```

- [ ] **Test:** Run `make py_divider` — all divide/remainder operations pass

**Concept check:**
> Why does division take 32 cycles but multiplication takes 1? Could you make a faster divider?

---

## Assignment E3 — Update Decoder and Pipeline Control

**Goal:** Add M-Extension instructions to decoder, handle multi-cycle divider.

### Step 1 — Extend `src/decoder.v`

- [ ] Add opcode case for M-Extension (funct7 = 0000001, opcode = 0110011):
  ```verilog
  if (funct7 == 7'b0000001) begin
    case (funct3)
      3'b000: alu_op = MUL;     // MUL
      3'b001: alu_op = MULH;    // MULH
      3'b010: alu_op = MULHSU;  // MULHSU
      3'b011: alu_op = MULHU;   // MULHU
      3'b100: alu_op = DIV;     // DIV
      3'b101: alu_op = DIVU;    // DIVU
      3'b110: alu_op = REM;     // REM
      3'b111: alu_op = REMU;    // REMU
    endcase
    mul_or_div = 1;  // Signal this is M-extension
  end
  ```

### Step 2 — Handle Divider in Pipeline (pipe_top.v)

- [ ] Instantiate divider:
  ```verilog
  divider divider_inst (
    .clk(clk), .rst(rst),
    .a(rs1_data_EX), .b(rs2_data_EX),
    .funct3(funct3_EX),
    .start(is_div_EX & ~divider_busy),  // Start if div instruction and divider ready
    .result(div_result),
    .busy(divider_busy), .done(divider_done)
  );
  ```

- [ ] Stall pipeline while dividing:
  ```verilog
  divider_stall = is_div_EX & divider_busy;
  // Use this signal to prevent PC advance, stall IF/ID
  ```

- [ ] Mux divider result into EX/MEM path when done:
  ```verilog
  alu_result_to_mem = (divider_done) ? div_result : alu_result;
  ```

### Step 3 — Test M-Extension

- [ ] Run `make py_pipe_top` with new tests:
  - Test MUL: `3 * 7 = 21`
  - Test MULH: `(2^31 - 1) * 2` → get high 32 bits
  - Test DIV: `20 / 4 = 5`
  - Test REM: `20 % 3 = 2`
  - Verify pipeline stalls during division and resumes after

- [ ] **Test:** All M-Extension tests pass, pipeline stalls correctly

**Concept check:**
> If an instruction after a DIV tries to read the DIV result, what prevents a hazard?

---

## Completion Gate

Before calling Module 5 done:
- [ ] `make py_multiplier` passes all MUL/MULH/MULHSU/MULHU tests
- [ ] `make py_divider` passes all DIV/DIVU/REM/REMU tests
- [ ] `make py_pipe_top` still passes all base RV32I tests
- [ ] M-Extension instructions execute correctly in pipeline
- [ ] Pipeline stalls during division, resumes when done
- [ ] You can explain: why multiply is 1 cycle but divide is 32

---

## Files Changed in Module 5

| File | Change |
|------|--------|
| `src/multiplier.v` | [NEW] 32×32 multiplier, 1-cycle |
| `src/divider.v` | [NEW] 32-bit divider, 32-cycle iterative |
| `src/decoder.v` | [MODIFY] Add M-Extension opcode decoding |
| `src/pipe_top.v` | [MODIFY] Instantiate multiplier, divider, stall control |
| `src/alu.v` | [MODIFY] Route M-Extension ops to multiplier/divider |

---

## M-Extension Instruction Encoding

```
Opcode: 0110011 (R-type)
funct7:  0000001 (M-Extension marker)

MUL:    funct3 = 000
MULH:   funct3 = 001
MULHSU: funct3 = 010
MULHU:  funct3 = 011
DIV:    funct3 = 100
DIVU:   funct3 = 101
REM:    funct3 = 110
REMU:   funct3 = 111
```
