# Graph Report - /home/ankur/workspace/BoseRV  (2026-04-19)

## Corpus Check
- 95 files · ~80,293 words
- Verdict: corpus is large enough that graph structure adds value.

## Summary
- 493 nodes · 716 edges · 69 communities detected
- Extraction: 85% EXTRACTED · 15% INFERRED · 0% AMBIGUOUS · INFERRED: 104 edges (avg confidence: 0.8)
- Token cost: 0 input · 0 output

## Community Hubs (Navigation)
- [[_COMMUNITY_Community 0|Community 0]]
- [[_COMMUNITY_Community 1|Community 1]]
- [[_COMMUNITY_Community 2|Community 2]]
- [[_COMMUNITY_Community 3|Community 3]]
- [[_COMMUNITY_Community 4|Community 4]]
- [[_COMMUNITY_Community 5|Community 5]]
- [[_COMMUNITY_Community 6|Community 6]]
- [[_COMMUNITY_Community 7|Community 7]]
- [[_COMMUNITY_Community 8|Community 8]]
- [[_COMMUNITY_Community 9|Community 9]]
- [[_COMMUNITY_Community 10|Community 10]]
- [[_COMMUNITY_Community 11|Community 11]]
- [[_COMMUNITY_Community 12|Community 12]]
- [[_COMMUNITY_Community 13|Community 13]]
- [[_COMMUNITY_Community 14|Community 14]]
- [[_COMMUNITY_Community 15|Community 15]]
- [[_COMMUNITY_Community 16|Community 16]]
- [[_COMMUNITY_Community 17|Community 17]]
- [[_COMMUNITY_Community 18|Community 18]]
- [[_COMMUNITY_Community 19|Community 19]]
- [[_COMMUNITY_Community 20|Community 20]]
- [[_COMMUNITY_Community 21|Community 21]]
- [[_COMMUNITY_Community 22|Community 22]]
- [[_COMMUNITY_Community 23|Community 23]]
- [[_COMMUNITY_Community 24|Community 24]]
- [[_COMMUNITY_Community 25|Community 25]]
- [[_COMMUNITY_Community 26|Community 26]]
- [[_COMMUNITY_Community 27|Community 27]]
- [[_COMMUNITY_Community 28|Community 28]]
- [[_COMMUNITY_Community 29|Community 29]]
- [[_COMMUNITY_Community 30|Community 30]]
- [[_COMMUNITY_Community 31|Community 31]]
- [[_COMMUNITY_Community 32|Community 32]]
- [[_COMMUNITY_Community 33|Community 33]]
- [[_COMMUNITY_Community 34|Community 34]]
- [[_COMMUNITY_Community 35|Community 35]]
- [[_COMMUNITY_Community 36|Community 36]]
- [[_COMMUNITY_Community 37|Community 37]]
- [[_COMMUNITY_Community 38|Community 38]]
- [[_COMMUNITY_Community 39|Community 39]]
- [[_COMMUNITY_Community 40|Community 40]]
- [[_COMMUNITY_Community 41|Community 41]]
- [[_COMMUNITY_Community 42|Community 42]]
- [[_COMMUNITY_Community 43|Community 43]]
- [[_COMMUNITY_Community 44|Community 44]]
- [[_COMMUNITY_Community 45|Community 45]]
- [[_COMMUNITY_Community 46|Community 46]]
- [[_COMMUNITY_Community 47|Community 47]]
- [[_COMMUNITY_Community 48|Community 48]]
- [[_COMMUNITY_Community 49|Community 49]]
- [[_COMMUNITY_Community 50|Community 50]]
- [[_COMMUNITY_Community 51|Community 51]]
- [[_COMMUNITY_Community 52|Community 52]]
- [[_COMMUNITY_Community 53|Community 53]]
- [[_COMMUNITY_Community 54|Community 54]]
- [[_COMMUNITY_Community 55|Community 55]]
- [[_COMMUNITY_Community 56|Community 56]]
- [[_COMMUNITY_Community 57|Community 57]]
- [[_COMMUNITY_Community 58|Community 58]]
- [[_COMMUNITY_Community 59|Community 59]]
- [[_COMMUNITY_Community 60|Community 60]]
- [[_COMMUNITY_Community 61|Community 61]]
- [[_COMMUNITY_Community 62|Community 62]]
- [[_COMMUNITY_Community 63|Community 63]]
- [[_COMMUNITY_Community 64|Community 64]]
- [[_COMMUNITY_Community 65|Community 65]]
- [[_COMMUNITY_Community 66|Community 66]]
- [[_COMMUNITY_Community 67|Community 67]]
- [[_COMMUNITY_Community 68|Community 68]]

## God Nodes (most connected - your core abstractions)
1. `10-Module RISC-V Curriculum` - 10 edges
2. `Single-Cycle Core (Module 1)` - 9 edges
3. `Instruction Decoder (src/decoder.v)` - 9 edges
4. `parse_reg()` - 8 edges
5. `assemble_line()` - 8 edges
6. `parse_reg()` - 8 edges
7. `assemble_line()` - 8 edges
8. `Vtb_alu___024root___eval_phase__act()` - 7 edges
9. `Vtb_top___024root___eval_phase__act()` - 7 edges
10. `Vtb_fetch___024root___eval_phase__act()` - 7 edges

## Surprising Connections (you probably didn't know these)
- `BoseRV Project` --references--> `BoseRV RISC-V Course Overview (README)`  [EXTRACTED]
  BoseRV_AI_Context.md → README.md
- `BoseRV Project` --references--> `CLAUDE.md: graphify knowledge graph rule for BoseRV`  [EXTRACTED]
  BoseRV_AI_Context.md → CLAUDE.md
- `Instruction Decoder (src/decoder.v)` --conceptually_related_to--> `Control Unit Decoder`  [EXTRACTED]
  BoseRV_AI_Context.md → BoseRV_Dashboard.md
- `Instruction Decoder (src/decoder.v)` --references--> `Decoder OP_IMM Block (SLTI SLTIU XORI ORI ANDI SLLI SRLI SRAI)`  [EXTRACTED]
  BoseRV_AI_Context.md → B4_Checklist.md
- `Instruction Decoder (src/decoder.v)` --references--> `Decoder OP_REG Block (SLL SLT SLTU XOR SRL SRA OR AND)`  [EXTRACTED]
  BoseRV_AI_Context.md → B4_Checklist.md

## Hyperedges (group relationships)
- **5-Stage Pipeline Register Chain** — module3_todo_if_id_pipeline_register, module3_todo_id_ex_pipeline_register, module3_todo_ex_mem_pipeline_register, module3_todo_mem_wb_pipeline_register, module3_todo_pipe_top [EXTRACTED 1.00]
- **Fetch-to-Decode Data Flow via IF/ID** — module3_todo_fetch_stage, module3_todo_if_id_pipeline_register, module3_todo_decode_stage [EXTRACTED 1.00]
- **Branch Flush Control Path in Pipeline** — module3_todo_branch_taken_signal, module3_todo_flush_mechanism, module3_todo_if_id_pipeline_register, module3_todo_id_ex_pipeline_register [EXTRACTED 0.95]

## Communities

### Community 0 - "Community 0"
Cohesion: 0.1
Nodes (34): Vtb_fetch___024root___eval_initial__TOP__Vtiming__0(), Vtb_top___024root___ctor_var_reset(), Vtb_top___024root___dump_triggers__act(), Vtb_top___024root___dump_triggers__stl(), Vtb_top___024root___eval_initial__TOP(), Vtb_top___024root___eval_phase__stl(), Vtb_top___024root___eval_settle(), Vtb_top___024root___eval_static() (+26 more)

### Community 1 - "Community 1"
Cohesion: 0.1
Nodes (36): ALU Opcode Reference Table, AUIPC Decoder Entry (opcode 0010111), Decoder OP_IMM Block (SLTI SLTIU XORI ORI ANDI SLLI SRLI SRAI), Decoder OP_REG Block (SLL SLT SLTU XOR SRL SRA OR AND), JAL Decoder Entry (opcode 1101111), ALU (src/alu.v), Rationale: AUIPC MUX wires PC to ALU input A instead of rs1, BoseRV Project (+28 more)

### Community 2 - "Community 2"
Cohesion: 0.09
Nodes (23): main(), main(), main(), main(), Vtop___024root___eval_final(), eventsPending(), final(), hierName() (+15 more)

### Community 3 - "Community 3"
Cohesion: 0.13
Nodes (31): Vtop___024root___dump_triggers__act(), Vtop___024root___dump_triggers__ico(), Vtop___024root___dump_triggers__stl(), Vtop___024root___eval_initial(), Vtop___024root___eval_initial__TOP(), Vtop___024root___eval_phase__stl(), Vtop___024root___eval_settle(), Vtop___024root___eval_static() (+23 more)

### Community 4 - "Community 4"
Cohesion: 0.13
Nodes (27): Vtb_alu___024root___ctor_var_reset(), Vtb_alu___024root___dump_triggers__act(), Vtb_alu___024root___dump_triggers__stl(), Vtb_alu___024root___eval_phase__stl(), Vtb_alu___024root___eval_settle(), Vtb_alu___024root___eval_static(), Vtb_alu___024root___eval_static__TOP(), Vtb_alu___024root___eval_stl() (+19 more)

### Community 5 - "Community 5"
Cohesion: 0.13
Nodes (27): Vtb_decoder___024root___ctor_var_reset(), Vtb_decoder___024root___dump_triggers__act(), Vtb_decoder___024root___dump_triggers__stl(), Vtb_decoder___024root___eval_phase__stl(), Vtb_decoder___024root___eval_settle(), Vtb_decoder___024root___eval_static(), Vtb_decoder___024root___eval_static__TOP(), Vtb_decoder___024root___eval_stl() (+19 more)

### Community 6 - "Community 6"
Cohesion: 0.13
Nodes (23): Vtb_fetch___024root___ctor_var_reset(), Vtb_fetch___024root___dump_triggers__act(), Vtb_fetch___024root___eval_initial__TOP(), Vtb_fetch___024root___eval_settle(), Vtb_fetch___024root___eval_static(), Vtb_fetch___024root___eval_static__TOP(), Vtb_fetch___024root____Vm_traceActivitySetAll(), Vtb_fetch___024root___eval() (+15 more)

### Community 7 - "Community 7"
Cohesion: 0.1
Nodes (16): Vtb_top___024root___eval_final(), final(), hierName(), name(), Vtb_top___024root__trace_const_0(), Vtb_top___024root__trace_const_0_sub_0(), Vtb_top___024root__trace_full_0(), Vtb_top___024root__trace_full_0_sub_0() (+8 more)

### Community 8 - "Community 8"
Cohesion: 0.1
Nodes (16): Vtb_fetch___024root___eval_final(), final(), hierName(), name(), Vtb_fetch___024root__trace_const_0(), Vtb_fetch___024root__trace_const_0_sub_0(), Vtb_fetch___024root__trace_full_0(), Vtb_fetch___024root__trace_full_0_sub_0() (+8 more)

### Community 9 - "Community 9"
Cohesion: 0.1
Nodes (16): Vtb_decoder___024root___eval_final(), final(), hierName(), name(), Vtb_decoder___024root__trace_const_0(), Vtb_decoder___024root__trace_const_0_sub_0(), Vtb_decoder___024root__trace_full_0(), Vtb_decoder___024root__trace_full_0_sub_0() (+8 more)

### Community 10 - "Community 10"
Cohesion: 0.1
Nodes (14): Vtb_alu___024root___eval_final(), final(), hierName(), name(), Vtb_alu___024root__trace_full_0(), Vtb_alu___024root__trace_full_0_sub_0(), Vtb_alu___024root__trace_init_sub__TOP__0(), Vtb_alu___024root__trace_init_top() (+6 more)

### Community 11 - "Community 11"
Cohesion: 0.09
Nodes (15): Vtb_alu__Syms(), eval_end_step(), _traceDumpClose(), Vtb_decoder__Syms(), eval_end_step(), _traceDumpClose(), Vtb_fetch__Syms(), eval_end_step() (+7 more)

### Community 12 - "Community 12"
Cohesion: 0.13
Nodes (24): branch_taken Signal from EX/MEM, Data Hazards (deferred to Module 4), ID (Decode) Stage — decoder.v, EX/MEM Pipeline Register, src/ex_mem.v, EX (Execute) Stage — alu.v, IF (Fetch) Stage — fetch.v, Pipeline Flush Mechanism for Branch/Jump (+16 more)

### Community 13 - "Community 13"
Cohesion: 0.44
Nodes (9): assemble_b(), assemble_i(), assemble_j(), assemble_l(), assemble_line(), assemble_r(), assemble_s(), assemble_u() (+1 more)

### Community 14 - "Community 14"
Cohesion: 0.51
Nodes (9): assemble_b(), assemble_i(), assemble_j(), assemble_l(), assemble_line(), assemble_r(), assemble_s(), assemble_u() (+1 more)

### Community 15 - "Community 15"
Cohesion: 0.4
Nodes (4): Read register idx from DUT regfile, always returns unsigned 32-bit int., Run test_full.asm on BoseRV and verify the final architectural state.      Prima, read_reg(), test_full_rv32i()

### Community 16 - "Community 16"
Cohesion: 0.4
Nodes (3): Test standard addition: 5 + 14 = 19, # TODO: Add more test cases here!, test_alu_addition()

### Community 17 - "Community 17"
Cohesion: 0.67
Nodes (2): Vtb_alu___024root__trace_chg_0(), Vtb_alu___024root__trace_chg_0_sub_0()

### Community 18 - "Community 18"
Cohesion: 0.67
Nodes (2): Vtb_top___024root__trace_chg_0(), Vtb_top___024root__trace_chg_0_sub_0()

### Community 19 - "Community 19"
Cohesion: 0.67
Nodes (2): Vtb_fetch___024root__trace_chg_0(), Vtb_fetch___024root__trace_chg_0_sub_0()

### Community 20 - "Community 20"
Cohesion: 0.67
Nodes (2): Vtb_decoder___024root__trace_chg_0(), Vtb_decoder___024root__trace_chg_0_sub_0()

### Community 21 - "Community 21"
Cohesion: 0.67
Nodes (2): Vtop___024root__trace_chg_0(), Vtop___024root__trace_chg_0_sub_0()

### Community 22 - "Community 22"
Cohesion: 1.0
Nodes (0): 

### Community 23 - "Community 23"
Cohesion: 1.0
Nodes (0): 

### Community 24 - "Community 24"
Cohesion: 1.0
Nodes (0): 

### Community 25 - "Community 25"
Cohesion: 1.0
Nodes (0): 

### Community 26 - "Community 26"
Cohesion: 1.0
Nodes (0): 

### Community 27 - "Community 27"
Cohesion: 1.0
Nodes (0): 

### Community 28 - "Community 28"
Cohesion: 1.0
Nodes (0): 

### Community 29 - "Community 29"
Cohesion: 1.0
Nodes (0): 

### Community 30 - "Community 30"
Cohesion: 1.0
Nodes (0): 

### Community 31 - "Community 31"
Cohesion: 1.0
Nodes (0): 

### Community 32 - "Community 32"
Cohesion: 1.0
Nodes (0): 

### Community 33 - "Community 33"
Cohesion: 1.0
Nodes (0): 

### Community 34 - "Community 34"
Cohesion: 1.0
Nodes (0): 

### Community 35 - "Community 35"
Cohesion: 1.0
Nodes (0): 

### Community 36 - "Community 36"
Cohesion: 1.0
Nodes (0): 

### Community 37 - "Community 37"
Cohesion: 1.0
Nodes (0): 

### Community 38 - "Community 38"
Cohesion: 1.0
Nodes (0): 

### Community 39 - "Community 39"
Cohesion: 1.0
Nodes (0): 

### Community 40 - "Community 40"
Cohesion: 1.0
Nodes (0): 

### Community 41 - "Community 41"
Cohesion: 1.0
Nodes (0): 

### Community 42 - "Community 42"
Cohesion: 1.0
Nodes (0): 

### Community 43 - "Community 43"
Cohesion: 1.0
Nodes (0): 

### Community 44 - "Community 44"
Cohesion: 1.0
Nodes (0): 

### Community 45 - "Community 45"
Cohesion: 1.0
Nodes (0): 

### Community 46 - "Community 46"
Cohesion: 1.0
Nodes (0): 

### Community 47 - "Community 47"
Cohesion: 1.0
Nodes (0): 

### Community 48 - "Community 48"
Cohesion: 1.0
Nodes (0): 

### Community 49 - "Community 49"
Cohesion: 1.0
Nodes (0): 

### Community 50 - "Community 50"
Cohesion: 1.0
Nodes (0): 

### Community 51 - "Community 51"
Cohesion: 1.0
Nodes (0): 

### Community 52 - "Community 52"
Cohesion: 1.0
Nodes (0): 

### Community 53 - "Community 53"
Cohesion: 1.0
Nodes (0): 

### Community 54 - "Community 54"
Cohesion: 1.0
Nodes (0): 

### Community 55 - "Community 55"
Cohesion: 1.0
Nodes (0): 

### Community 56 - "Community 56"
Cohesion: 1.0
Nodes (0): 

### Community 57 - "Community 57"
Cohesion: 1.0
Nodes (0): 

### Community 58 - "Community 58"
Cohesion: 1.0
Nodes (0): 

### Community 59 - "Community 59"
Cohesion: 1.0
Nodes (0): 

### Community 60 - "Community 60"
Cohesion: 1.0
Nodes (0): 

### Community 61 - "Community 61"
Cohesion: 1.0
Nodes (0): 

### Community 62 - "Community 62"
Cohesion: 1.0
Nodes (0): 

### Community 63 - "Community 63"
Cohesion: 1.0
Nodes (0): 

### Community 64 - "Community 64"
Cohesion: 1.0
Nodes (0): 

### Community 65 - "Community 65"
Cohesion: 1.0
Nodes (0): 

### Community 66 - "Community 66"
Cohesion: 1.0
Nodes (0): 

### Community 67 - "Community 67"
Cohesion: 1.0
Nodes (0): 

### Community 68 - "Community 68"
Cohesion: 1.0
Nodes (0): 

## Knowledge Gaps
- **19 isolated node(s):** `Test standard addition: 5 + 14 = 19`, `# TODO: Add more test cases here!`, `Read register idx from DUT regfile, always returns unsigned 32-bit int.`, `Run test_full.asm on BoseRV and verify the final architectural state.      Prima`, `Rationale: Tutor Mode — AI guides only, user writes all Verilog` (+14 more)
  These have ≤1 connection - possible missing edges or undocumented components.
- **Thin community `Community 22`** (2 nodes): `Vtb_top__Syms.h`, `name()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 23`** (2 nodes): `Vtb_fetch__Syms.h`, `name()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 24`** (2 nodes): `Vtb_decoder__Syms.h`, `name()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 25`** (2 nodes): `Vtb_fetch___024root.h`, `Vtb_fetch___024root()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 26`** (2 nodes): `Vtb_decoder___024root.h`, `Vtb_decoder___024root()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 27`** (2 nodes): `Vtb_alu___024root.h`, `Vtb_alu___024root()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 28`** (2 nodes): `Vtb_top___024root.h`, `Vtb_top___024root()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 29`** (2 nodes): `Vtb_alu__Syms.h`, `name()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 30`** (2 nodes): `Vtb_alu.h`, `eval_end_step()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 31`** (2 nodes): `Vtop__Syms.h`, `name()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 32`** (2 nodes): `Vtop___024root.h`, `Vtop___024root()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 33`** (2 nodes): `Vtop.h`, `eval_end_step()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 34`** (1 nodes): `decoder.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 35`** (1 nodes): `imem.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 36`** (1 nodes): `fetch.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 37`** (1 nodes): `ex_mem.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 38`** (1 nodes): `top.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 39`** (1 nodes): `dmem.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 40`** (1 nodes): `id_ex.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 41`** (1 nodes): `mem_wb.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 42`** (1 nodes): `if_id.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 43`** (1 nodes): `regfile.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 44`** (1 nodes): `alu.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 45`** (1 nodes): `tb_mem_wb.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 46`** (1 nodes): `tb_ex_mem.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 47`** (1 nodes): `tb_fetch.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 48`** (1 nodes): `tb_top.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 49`** (1 nodes): `tb_alu.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 50`** (1 nodes): `tb_if_id.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 51`** (1 nodes): `tb_id_ex.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 52`** (1 nodes): `tb_decoder.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 53`** (1 nodes): `Vtb_top__pch.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 54`** (1 nodes): `Vtb_alu__pch.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 55`** (1 nodes): `Vtb_decoder.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 56`** (1 nodes): `Vtb_top__ALL.cpp`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 57`** (1 nodes): `Vtb_fetch__ALL.cpp`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 58`** (1 nodes): `Vtb_alu__ALL.cpp`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 59`** (1 nodes): `Vtb_decoder__pch.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 60`** (1 nodes): `Vtb_top.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 61`** (1 nodes): `Vtb_fetch__pch.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 62`** (1 nodes): `Vtb_decoder__ALL.cpp`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 63`** (1 nodes): `Vtb_fetch.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 64`** (1 nodes): `Vtop__ALL.cpp`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 65`** (1 nodes): `Vtop__Dpi.cpp`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 66`** (1 nodes): `Vtop__ConstPool__0__Slow.cpp`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 67`** (1 nodes): `Vtop__Dpi.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 68`** (1 nodes): `Vtop__pch.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **What connects `Test standard addition: 5 + 14 = 19`, `# TODO: Add more test cases here!`, `Read register idx from DUT regfile, always returns unsigned 32-bit int.` to the rest of the system?**
  _19 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `Community 0` be split into smaller, more focused modules?**
  _Cohesion score 0.1 - nodes in this community are weakly interconnected._
- **Should `Community 1` be split into smaller, more focused modules?**
  _Cohesion score 0.1 - nodes in this community are weakly interconnected._
- **Should `Community 2` be split into smaller, more focused modules?**
  _Cohesion score 0.09 - nodes in this community are weakly interconnected._
- **Should `Community 3` be split into smaller, more focused modules?**
  _Cohesion score 0.13 - nodes in this community are weakly interconnected._
- **Should `Community 4` be split into smaller, more focused modules?**
  _Cohesion score 0.13 - nodes in this community are weakly interconnected._
- **Should `Community 5` be split into smaller, more focused modules?**
  _Cohesion score 0.13 - nodes in this community are weakly interconnected._