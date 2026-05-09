# Module 1 — Single-Cycle RV32I Core: Learning Checklist

Work top-to-bottom. Each assignment builds on the previous.
Rule: **you write all Verilog logic**. Ask teacher for hints if stuck.

---

## Why Do We Need This?

A RISC-V processor must:
1. **Fetch** the instruction from memory
2. **Decode** it (extract register addresses, immediates, control signals)
3. **Execute** (ALU computes the result)
4. **Access Memory** (if needed for loads/stores)
5. **Write Back** (save result to registers)

All 5 steps happen **in one clock cycle** — this is the single-cycle datapath.

```
PC → IMEM[PC] → Decode → ALU → DMEM → Register Write
          ↑                              ↓
          ←————————— Control Unit ————————
```

---

## Assignment A1 — 32-bit ALU

**File:** `src/alu.v` (NEW — you create this)
**Goal:** Build the arithmetic and logic engine.

### Concept: Op Encoding

The ALU takes a 4-bit `alu_op` and executes the corresponding operation:

```
alu_op [3:0]  | Operation
──────────────┼──────────────
    0000      | ADD   (a + b)
    0001      | SUB   (a - b)
    0010      | AND   (a & b)
    0011      | OR    (a | b)
    0100      | XOR   (a ^ b)
    0101      | SLL   (a << b[4:0])
    0110      | SRL   (a >> b[4:0], logical)
    0111      | SRA   (a >> b[4:0], arithmetic)
    1000      | SLT   (a < b ? 1 : 0, signed)
    1001      | SLTU  (a < b ? 1 : 0, unsigned)
```

### Step 1 — Create `src/alu.v`

- [ ] Declare module with ports:
  - Inputs: `alu_op [3:0]`, `a [31:0]`, `b [31:0]`
  - Output: `result [31:0]`, `zero` (1-bit, 1 if result==0)

- [ ] Implement combinational logic:
  ```verilog
  always @(*) begin
    case (alu_op)
      4'b0000: result = a + b;           // ADD
      4'b0001: result = a - b;           // SUB
      4'b0010: result = a & b;           // AND
      4'b0011: result = a | b;           // OR
      4'b0100: result = a ^ b;           // XOR
      4'b0101: result = a << b[4:0];     // SLL
      4'b0110: result = a >> b[4:0];     // SRL
      4'b0111: result = $signed(a) >>> b[4:0];  // SRA
      4'b1000: result = ($signed(a) < $signed(b)) ? 1 : 0;  // SLT
      4'b1001: result = (a < b) ? 1 : 0;  // SLTU
      default: result = 32'hxxxxxxxx;
    endcase
    zero = (result == 0);
  end
  ```

- [ ] **Test:** Run `make alu_sim` — all tests pass

**Concept check:**
> Why do SLT and SLTU use different comparison? What's the difference between signed and unsigned?

---

## Assignment A2 — Instruction Decoder

**File:** `src/decoder.v` (NEW — you create this)
**Goal:** Parse 32-bit instruction, extract register addresses, immediates, control signals.

### Concept: RISC-V Instruction Formats

RV32I has 6 instruction types, each with different field layouts:

```
R-type:  [funct7 (7) | rs2 (5) | rs1 (5) | funct3 (3) | rd (5) | opcode (7)]
  Example: ADD x1, x2, x3
  funct7=0000000, rs2=3, rs1=2, funct3=0, rd=1, opcode=0110011

I-type:  [imm[11:0] (12) | rs1 (5) | funct3 (3) | rd (5) | opcode (7)]
  Example: ADDI x1, x2, 100
  imm=100, rs1=2, rd=1, opcode=0010011

S-type:  [imm[11:5] (7) | rs2 (5) | rs1 (5) | funct3 (3) | imm[4:0] (5) | opcode (7)]
  Example: SW x3, 4(x2)
  
B-type:  [imm[12|10:5] (7) | rs2 (5) | rs1 (5) | funct3 (3) | imm[4:1|11] (5) | opcode (7)]
  Example: BEQ x1, x2, offset

U-type:  [imm[31:12] (20) | rd (5) | opcode (7)]
  Example: LUI x1, 0x12345

J-type:  [imm[20|10:1|11|19:12] (20) | rd (5) | opcode (7)]
  Example: JAL x1, offset
```

### Step 1 — Create `src/decoder.v`

- [ ] Declare module with ports:
  - Input: `instr [31:0]`
  - Outputs: `rs1 [4:0]`, `rs2 [4:0]`, `rd [4:0]`
  - Outputs: `imm [31:0]` (sign-extended), `alu_op [3:0]`
  - Outputs: `alu_src`, `mem_read`, `mem_write`, `reg_write`, `branch`, `jump`, `jalr`, `auipc`, `lui`, `wb_sel [1:0]`, `pc_src [1:0]`

- [ ] Extract instruction fields:
  ```verilog
  wire [6:0] opcode = instr[6:0];
  wire [4:0] rd = instr[11:7];
  wire [2:0] funct3 = instr[14:12];
  wire [4:0] rs1 = instr[19:15];
  wire [4:0] rs2 = instr[24:20];
  wire [6:0] funct7 = instr[31:25];
  ```

- [ ] Implement immediates (sign-extend all 5 formats):
  - **I-type:** `imm = {{20{instr[31]}}, instr[31:20]}`
  - **S-type:** `imm = {{20{instr[31]}}, instr[31:25], instr[11:7]}`
  - **B-type:** `imm = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0}`
  - **U-type:** `imm = {instr[31:12], 12'b0}`
  - **J-type:** `imm = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0}`

- [ ] Decode all 47 RV32I instructions by opcode and funct3/funct7:
  ```verilog
  always @(*) begin
    case (opcode)
      7'b0110111: begin  // LUI
        alu_op = 4'b0000;  imm_sel = I_U;  reg_write = 1;  wb_sel = 2'b11;
      end
      7'b0010111: begin  // AUIPC
        alu_op = 4'b0000;  imm_sel = I_U;  alu_src = 1;  reg_write = 1;  wb_sel = 2'b00;  auipc = 1;
      end
      7'b1101111: begin  // JAL
        reg_write = 1;  jump = 1;  wb_sel = 2'b10;  imm_sel = I_J;
      end
      // ... continue for all 47 instructions
    endcase
  end
  ```

- [ ] **Test:** Run `make decoder_sim` — all tests pass

**Concept check:**
> Why must immediate values be sign-extended? What happens if you don't sign-extend -1?

---

## Assignment A3 — Fetch Unit (Program Counter)

**File:** `src/fetch.v` (NEW — you create this)
**Goal:** Manage the Program Counter, fetch instructions from memory.

### Concept: PC Behavior

- On reset: `PC = 32'h00000000`
- Each cycle (if not branching): `PC <= PC + 4` (instructions are 32-bit = 4 bytes)
- On branch taken: `PC <= branch_target`
- On jump: `PC <= jump_target` (for JAL or JALR)

### Step 1 — Create `src/fetch.v`

- [ ] Declare module with ports:
  - Inputs: `clk, rst`, `branch_target [31:0]`, `jump_target [31:0]`, `branch_taken`, `jump`
  - Outputs: `pc [31:0]`, `instr [31:0]` (from instruction memory)

- [ ] Instantiate instruction memory:
  ```verilog
  imem imem_inst (
    .addr(pc),
    .data_out(instr)
  );
  ```

- [ ] Implement PC register:
  ```verilog
  reg [31:0] pc;
  always @(posedge clk or posedge rst) begin
    if (rst) begin
      pc <= 32'h00000000;
    end else begin
      if (jump) begin
        pc <= jump_target;
      end else if (branch_taken) begin
        pc <= branch_target;
      end else begin
        pc <= pc + 4;
      end
    end
  end
  ```

- [ ] **Test:** Run `make fetch_sim` — PC increments correctly, branches divert

**Concept check:**
> If you set `pc <= pc + 4` in the always block, when does the new PC take effect? Same cycle or next?

---

## Assignment A4 — Top-Level Single-Cycle Core

**File:** `src/top.v` (NEW — you create this)
**Goal:** Wire all modules together — one clock cycle per instruction.

### Step 1 — Create `src/top.v`

- [ ] Instantiate all modules:
  ```verilog
  fetch fetch_inst (...);
  decoder decoder_inst (...);
  regfile regfile_inst (...);
  alu alu_inst (...);
  dmem dmem_inst (...);
  ```

- [ ] Wire the datapath:
  - Fetch → PC and instruction
  - Decoder → extract rs1, rs2, rd, imm, control signals
  - Register File → read rs1_data, rs2_data at addresses rs1, rs2
  - ALU input selection:
    - `alu_a = (auipc) ? pc : rs1_data`  (for AUIPC, use PC instead of register)
    - `alu_b = (alu_src) ? imm : rs2_data`  (immediate or register)
  - Writeback MUX (wb_sel chooses what to write):
    ```verilog
    writeback_data = (wb_sel == 2'b00) ? alu_result :
                     (wb_sel == 2'b01) ? dmem_data :
                     (wb_sel == 2'b10) ? (pc + 4) :
                     32'hxxxxxxxx;
    ```

- [ ] Branch/Jump targets:
  ```verilog
  branch_target = pc + imm;
  jump_target = (jalr) ? (rs1_data + imm) : (pc + imm);
  ```

- [ ] Register writeback:
  ```verilog
  regfile_inst (
    .clk(clk),
    .rs1_addr(rs1), .rs1_data(rs1_data),
    .rs2_addr(rs2), .rs2_data(rs2_data),
    .rd_addr(rd), .rd_data(writeback_data), .reg_write(reg_write)
  );
  ```

- [ ] **Test:** Run `make top_sim` — execute a simple program:
  ```asm
  ADDI x1, x0, 15       # x1 = 15
  ADDI x2, x0, 20       # x2 = 20
  ADD  x3, x1, x2       # x3 = 35
  SW   x3, 0(x0)        # store x3 to memory[0]
  ```

---

## Completion Gate

Before calling Module 1 done:
- [x] `make alu_sim` passes all tests
- [x] `make decoder_sim` passes all tests
- [x] `make fetch_sim` passes all tests
- [x] `make top_sim` passes all tests
- [x] Single cycle datapath executes RV32I base instructions correctly
- [x] You can explain: how does the ALU know which operation to perform?
- [x] You can explain: why do we sign-extend immediates?

---

## Files Changed in Module 1

| File | Change |
|------|--------|
| `src/alu.v` | [NEW] 32-bit ALU with 10 operations |
| `src/decoder.v` | [NEW] RV32I instruction decoder, all 47 instructions |
| `src/fetch.v` | [NEW] Program Counter + instruction fetch |
| `src/top.v` | [NEW] Single-cycle core, wires all together |

---

## Pipeline Timing Reference (Single-Cycle)

```
Cycle:  1       2       3
ADDI    IF/ID/EX/MEM/WB   (all in cycle 1)
ADDI            IF/ID/EX/MEM/WB

Result appears in register at END of cycle 1.
Next instruction reads it at START of cycle 2.
```

All 5 stages happen in 1 clock → CPI = 1 (ideal, no stalls yet).
