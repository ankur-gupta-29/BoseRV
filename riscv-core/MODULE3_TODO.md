# Module 3 — 5-Stage Pipeline: Learning Checklist

Work top-to-bottom. Each assignment builds on the previous.
Rule: **you write all Verilog logic**. Ask teacher for hints if stuck.

---

## Assignment C1 — IF/ID Pipeline Register

**File:** `src/if_id.v`
**Goal:** Learn what a pipeline register IS and why it exists.

- [x] Read the comment in `if_id.v` — understand WHY pc and instr are stored
- [x] Implement `always @(posedge clk or posedge rst)` block
  - [x] On `rst`: set `pc_out = 0`, `instr_out = 0`
  - [x] On clock: latch `pc_in → pc_out`, `instr_in → instr_out`
- [x] **Test:** simulate manually — apply inputs, check outputs appear one cycle later

**Concept check (answer in your head before moving on):**
> If IF and ID share the same wires (no register between them), what happens when the PC advances to the next instruction mid-cycle?

---

## Assignment C2 — ID/EX Pipeline Register

**File:** `src/id_ex.v`
**Goal:** Pass ALL decoder outputs + register values to Execute stage.

- [x] Read the port list in `id_ex.v` — note rs1/rs2 addresses are also stored (why?)
- [x] Implement the `always` block — on rst zero everything, on clk latch everything
  - [x] Data signals: `pc`, `rs1_data`, `rs2_data`, `imm`, `rs1`, `rs2`, `rd`
  - [x] Control signals: `alu_op`, `alu_src`, `mem_read`, `mem_write`, `reg_write`, `wb_sel`, `branch`, `jump`, `jalr`, `auipc`, `lui`
- [x] **Key question:** why do we store `rs1` and `rs2` addresses (not just the data)?

**Concept check:**
> If you zero ALL control signals on reset, what does the pipeline see? Is that safe?

---

## Assignment C3 — EX/MEM and MEM/WB Registers

**Files:** `src/ex_mem.v`, `src/mem_wb.v`
**Goal:** Complete the pipeline register chain.

### EX/MEM (`ex_mem.v`)
- [ ] Implement the `always` block — rst zeros, clk latches
  - [ ] Data: `alu_result`, `rs2_data`, `pc_plus4`, `branch_target`, `jump_target`, `branch_taken`, `alu_zero`, `rd`
  - [ ] Control: `mem_read`, `mem_write`, `reg_write`, `wb_sel`, `jump`
- [ ] **Critical:** why must `mem_write_out` be 0 on reset?

### MEM/WB (`mem_wb.v`)
- [ ] Implement the `always` block — rst zeros, clk latches
  - [ ] Data: `alu_result`, `mem_read_data`, `pc_plus4`, `rd`
  - [ ] Control: `reg_write`, `wb_sel`
- [ ] **Concept:** at WB stage, how does `wb_sel` decide what to write to `rd`?

---

## Assignment C4 — Wire Everything into a Pipelined Top

**File:** `src/pipe_top.v` (new file — you will create this)
**Goal:** Connect all 4 pipeline registers into a working 5-stage processor.

### Step 1 — Create `pipe_top.v`
- [ ] Copy `top.v` as starting point
- [ ] Remove the direct wire connections between stages
- [ ] Instantiate `if_id`, `id_ex`, `ex_mem`, `mem_wb` between stages
- [ ] Fetch drives `if_id` inputs; `if_id` outputs drive decoder
- [ ] Decoder + regfile drive `id_ex` inputs; `id_ex` outputs drive ALU
- [ ] ALU drives `ex_mem` inputs; `ex_mem` outputs drive dmem
- [ ] dmem + `ex_mem` drive `mem_wb` inputs; `mem_wb` outputs drive regfile write

### Step 2 — Fix the PC update (branch/jump now arrive late)
- [ ] In single-cycle, branch_taken fed directly to fetch — in pipeline, EX result arrives 2 cycles after IF
- [ ] For now: use **flush** — when branch_taken comes from EX/MEM, zero out IF/ID and ID/EX (insert NOPs)
- [ ] Add `flush` input to `if_id` and `id_ex` — on flush, output = 0 (same as reset)

### Step 3 — Run the test suite
- [ ] Run `make py_top` — tests will likely fail (data hazards not handled yet)
- [ ] Identify which tests fail and why
- [ ] This is expected — hazard handling is Module 4

---

## Completion Gate

Before calling Module 3 done:
- [ ] `pipe_top.v` simulates without X-propagation on reset
- [ ] Pipeline register outputs are stable (verified with waveform or print statements)
- [ ] You can explain: what travels in each register and why

---

## Pipeline Register Summary (reference)

```
IF stage        ID stage        EX stage       MEM stage      WB stage
  |                |               |               |              |
fetch.v  →[IF/ID]→ decoder.v →[ID/EX]→ alu.v →[EX/MEM]→ dmem.v →[MEM/WB]→ regfile.v
           if_id.v              id_ex.v           ex_mem.v          mem_wb.v
```

| Register | Carries                                        |
|----------|------------------------------------------------|
| IF/ID    | pc, instr                                      |
| ID/EX    | pc, rs1_data, rs2_data, imm, rd, all controls |
| EX/MEM   | alu_result, rs2_data, branch_taken, rd, controls |
| MEM/WB   | alu_result, mem_read_data, pc+4, rd, controls |
