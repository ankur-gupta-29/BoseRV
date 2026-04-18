# BoseRV — Assignment B4 Checklist

Complete all the items below to finish your single-cycle RV32I processor.
Run `make py_top` after each group to watch the failure count drop!

---

## 📂 File: `src/decoder.v`

### Block 1: `OP_IMM` case (around line 83)
Add the missing `funct3` entries inside the existing `OP_IMM` case statement.

- [ ] `3'b010` → `SLTI`  → `alu_op = 4'b1000`
- [ ] `3'b011` → `SLTIU` → `alu_op = 4'b1001`
- [ ] `3'b100` → `XORI`  → `alu_op = 4'b0100`
- [ ] `3'b110` → `ORI`   → `alu_op = 4'b0011`
- [ ] `3'b111` → `ANDI`  → `alu_op = 4'b0010`
- [ ] `3'b001` → `SLLI`  → `alu_op = 4'b0101`
- [ ] `3'b101` → `SRLI/SRAI` → check `funct7[5]`: if 1 → `4'b0111` (SRA), else → `4'b0110` (SRL)

### Block 2: `OP_REG` case (around line 94)
Add the missing `funct3` entries inside the existing `OP_REG` case statement.

- [ ] `3'b001` → `SLL`       → `alu_op = 4'b0101`
- [ ] `3'b010` → `SLT`       → `alu_op = 4'b1000`
- [ ] `3'b011` → `SLTU`      → `alu_op = 4'b1001`
- [ ] `3'b100` → `XOR`       → `alu_op = 4'b0100`
- [ ] `3'b101` → `SRL/SRA`   → check `funct7[5]`: if 1 → `4'b0111` (SRA), else → `4'b0110` (SRL)
- [ ] `3'b110` → `OR`        → `alu_op = 4'b0011`
- [ ] `3'b111` → `AND`       → `alu_op = 4'b0010`

### Block 3: New Opcodes (add brand new `case` branches)

- [ ] `7'b0010111` → **AUIPC** — Set: `imm = imm_u`, `alu_op = 4'b0000` (ADD), `alu_src = 1`, `reg_write = 1`, `wb_sel = 2'b00`
  > ⚠️ AUIPC also needs the ALU's `a` input to be `PC` instead of `rs1`! Check `src/top.v` for a MUX.

- [ ] `7'b1101111` → **JAL** — Set: `imm = imm_j`, `jump = 1`, `reg_write = 1`, `wb_sel = 2'b10` (PC+4 saved to rd)

---

## ALU Op Code Reference
*(From `src/alu.v`)*

| Code | Operation |
|------|-----------|
| `4'b0000` | ADD |
| `4'b0001` | SUB |
| `4'b0010` | AND |
| `4'b0011` | OR |
| `4'b0100` | XOR |
| `4'b0101` | SLL |
| `4'b0110` | SRL |
| `4'b0111` | SRA |
| `4'b1000` | SLT (signed) |
| `4'b1001` | SLTU (unsigned) |

---

## ✅ Verification Command
```bash
make py_top
```
Your goal: go from **19 FAILED** → **0 FAILED**.
