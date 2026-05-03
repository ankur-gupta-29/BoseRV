# Module 4 — Hazard Handling: Learning Checklist

Work top-to-bottom. Each assignment builds on the previous.
Rule: **you write all Verilog logic**. Ask teacher for hints if stuck.

---

## Why Do We Need This?

In Module 3 your pipeline runs, but back-to-back instructions that share registers
get the WRONG answer because the register file hasn't been written yet.

```
ADDI x1, x0, 15     ← writes x1 at WB (3 cycles later)
SUB  x4, x1, x2     ← reads x1 NOW — gets stale 0!    ← RAW hazard
```

Module 4 fixes this with two mechanisms:
  1. **Forwarding** — bypass the fresh result directly to the ALU (no stall needed)
  2. **Stall + Bubble** — for load-use hazards where forwarding is impossible

---

## Assignment D1 — Data Forwarding Unit

**File:** `src/forwarding.v` (NEW — you create this)
**Goal:** Detect RAW hazards and output a 2-bit MUX select to bypass the ALU inputs.

### Concept: EX-EX and MEM-EX forwarding paths

```
Cycle N:   ADD  x1, x2, x3   → alu_result lands in EX/MEM register
Cycle N+1: SUB  x4, x1, x5   → needs x1 in EX stage — forward from EX/MEM!

Cycle N:   ADD  x1, x2, x3   → result lands in MEM/WB register by N+2
Cycle N+2: AND  x6, x1, x7   → needs x1 in EX stage — forward from MEM/WB!
```

### Step 1 — Create `src/forwarding.v`
- [x] Declare the module with these ports:
  - Inputs: `rs1_EX [4:0]`, `rs2_EX [4:0]` — source regs of instruction in EX
  - Inputs: `rd_MEM [4:0]`, `reg_write_MEM` — destination of instruction in MEM
  - Inputs: `rd_WB [4:0]`, `reg_write_WB` — destination of instruction in WB
  - Outputs: `forward_A [1:0]`, `forward_B [1:0]` — MUX selects (00=regfile, 10=EX/MEM, 01=MEM/WB)

- [x] Implement EX-EX forwarding (highest priority):
  ```
  if reg_write_MEM AND rd_MEM != 0 AND rd_MEM == rs1_EX → forward_A = 2'b10
  if reg_write_MEM AND rd_MEM != 0 AND rd_MEM == rs2_EX → forward_B = 2'b10
  ```
- [x] Implement MEM-WB forwarding (lower priority, only if EX-EX didn't match):
  ```
  if reg_write_WB AND rd_WB != 0 AND rd_WB == rs1_EX AND rd_MEM != rs1_EX → forward_A = 2'b01
  if reg_write_WB AND rd_WB != 0 AND rd_WB == rs2_EX AND rd_MEM != rs2_EX → forward_B = 2'b01
  ```
- [x] Default: `forward_A = 2'b00`, `forward_B = 2'b00` (use register file output)

**Concept check:**
> Why must EX-EX forwarding have higher priority than MEM-WB forwarding?
> (Hint: what if two consecutive instructions both write x1?)

### Step 2 — Add forwarding MUXes in `pipe_top.v`

In the EX stage section, BEFORE the ALU instantiation:
- [ ] Add wires `fwd_rs1 [31:0]` and `fwd_rs2 [31:0]`
- [ ] Implement the 3-way MUX:
  ```
  fwd_rs1 = (forward_A==2'b10) ? alu_result_MEM :
            (forward_A==2'b01) ? writeback_data  : rs1_data_EX;
  fwd_rs2 = (forward_B==2'b10) ? alu_result_MEM :
            (forward_B==2'b01) ? writeback_data  : rs2_data_EX;
  ```
- [ ] Change the ALU `.a()` connection to use `fwd_rs1` (keep AUIPC/LUI MUX)
- [ ] Change ALU B input (`alu_b_EX`) to use `fwd_rs2` (keep alu_src MUX)
- [ ] Change `rs2_data_in` of `ex_mem_inst` to use `fwd_rs2` (for SW forwarding)
- [ ] Change JALR `jump_target` to use `fwd_rs1` (for JALR forwarding)
- [ ] Instantiate `forwarding forwarding_inst(...)` with the right ports

### Step 3 — Test D1
- [ ] Run `make py_pipe_top`
- [ ] R-type and I-type tests (1–24) should now pass
- [ ] Memory and branch tests may still fail (load-use hazard — that's D2)

---

## Assignment D2 — Hazard Detection Unit (Load-Use Stall)

**File:** `src/hazard.v` (NEW — you create this)
**Goal:** Detect when a LOAD is followed immediately by an instruction that reads its result,
and insert a one-cycle bubble (stall).

### Concept: Why forwarding can't save us here

```
LW   x1, 0(x0)      ← data comes from MEMORY — result not ready until end of MEM stage
ADD  x4, x1, x2     ← needs x1 at start of EX stage — memory hasn't responded yet!
```
Even if we forward, the data isn't available in time. We must stall 1 cycle.

### Step 1 — Create `src/hazard.v`
- [ ] Declare the module with ports:
  - Inputs: `mem_read_EX`, `rd_EX [4:0]`, `rs1_ID [4:0]`, `rs2_ID [4:0]`
  - Output: `stall` (1-bit)
- [ ] Implement load-use detection:
  ```
  stall = mem_read_EX AND rd_EX != 0 AND (rd_EX == rs1_ID OR rd_EX == rs2_ID)
  ```

### Step 2 — Add stall and flush support to pipeline registers

**Modify `src/if_id.v`:**
- [ ] Add `input flush` and `input stall` ports
- [ ] When `flush=1`: zero all outputs (same as rst) — control hazard NOP
- [ ] When `stall=1`: hold current values (don't latch new inputs)
- [ ] When neither: normal latch operation
- [ ] Priority order: `rst > flush > stall > normal`

**Modify `src/id_ex.v`:**
- [ ] Add `input flush` port
- [ ] When `flush=1` OR `stall=1` (bubble signal): zero all control outputs
- [ ] When neither: normal latch operation

**Concept check:**
> During a load-use stall, why does IF/ID *hold* its values but ID/EX gets *cleared*?

### Step 3 — Wire stall/flush in `pipe_top.v`
- [ ] Instantiate `hazard hazard_inst(...)` and `forwarding forwarding_inst(...)`
- [ ] Declare `wire stall`, `wire flush`
- [ ] Assign: `flush = branch_taken_EX | jump_EX`
- [ ] When `stall=1`: prevent PC from advancing (modify fetch or add enable to PC)
- [ ] Connect `stall` and `flush` to `if_id_inst`
- [ ] Connect `stall` (as bubble) and `flush` to `id_ex_inst`
- [ ] Add a `stall` enable input to `fetch.v` (or handle in pipe_top directly)

### Step 4 — Test D2
- [ ] Run `make py_pipe_top`
- [ ] All 56 tests should now pass: `x28=0, x31=1337`
- [ ] Run `make py_pipe_top` again to confirm it's stable

---

## Assignment D3 — Control Hazard Flush (Verification)

This is mostly already handled via the `flush` signal from D2, but verify:
- [ ] Branch-taken flushes correctly: BEQ/BNE/BLT/BGE/BLTU/BGEU all pass
- [ ] JAL flushes correctly (jump_EX signal)
- [ ] JALR flushes correctly (jump_EX signal, jalr_EX path)
- [ ] Backward branch loop (test 49) runs exactly 4 times

---

## Assignment D4 — 2-bit Branch Predictor (BHT) *(Optional / Bonus)*

**File:** `src/bht.v` (NEW)
**Goal:** Predict branch direction to reduce the 2-cycle penalty on taken branches.

*(This is an optional bonus — complete D1/D2/D3 first)*

---

## Completion Gate

Before calling Module 4 done:
- [ ] `make py_pipe_top` passes all 56 tests: `x28=0, x31=1337`
- [ ] No X-propagation in simulation
- [ ] You can explain: EX-EX vs MEM-EX forwarding priority
- [ ] You can explain: why LW→USE requires a stall even with forwarding

---

## Files Changed in Module 4

| File | Change |
|------|--------|
| `src/forwarding.v` | [NEW] Forwarding unit |
| `src/hazard.v` | [NEW] Load-use hazard detection |
| `src/if_id.v` | [MODIFY] Add stall + flush ports |
| `src/id_ex.v` | [MODIFY] Add flush/bubble port |
| `src/pipe_top.v` | [MODIFY] Wire forwarding MUXes, stall, flush |
| `src/fetch.v` | [MODIFY] Add PC stall enable |

---

## Pipeline Timing Reference

```
Cycle:    1     2     3     4     5     6
ADDI x1   IF    ID    EX    MEM   WB
SUB  x4         IF    ID    EX    MEM   WB
                      ^     ^
                      |     └── MEM→EX forward (if needed)
                      └──────── EX→EX forward (alu_result_MEM → fwd_rs1)
```

```
Cycle:    1     2     3     4     5     6
LW   x1   IF    ID    EX    MEM   WB
ADD  x4         IF    ID   [bubble]  EX   MEM   WB
                      ^              ^
                      stall here  forward from MEM/WB here
```
