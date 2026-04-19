# Graph Report - .  (2026-04-19)

## Corpus Check
- 93 files · ~50,000 words
- Verdict: corpus is large enough that graph structure adds value.

## Summary
- 461 nodes · 680 edges · 60 communities detected
- Extraction: 85% EXTRACTED · 15% INFERRED · 0% AMBIGUOUS · INFERRED: 102 edges (avg confidence: 0.8)
- Token cost: 0 input · 0 output

## Community Hubs (Navigation)
- [[_COMMUNITY_Top Testbench Root Logic|Top Testbench Root Logic]]
- [[_COMMUNITY_Decoder Checklist & ALU Opcodes|Decoder Checklist & ALU Opcodes]]
- [[_COMMUNITY_Verilator TB Entry Points|Verilator TB Entry Points]]
- [[_COMMUNITY_Cocotb Top Root Logic|Cocotb Top Root Logic]]
- [[_COMMUNITY_Decoder Testbench Root|Decoder Testbench Root]]
- [[_COMMUNITY_ALU Testbench Root|ALU Testbench Root]]
- [[_COMMUNITY_Fetch Testbench Root|Fetch Testbench Root]]
- [[_COMMUNITY_Fetch TB Trace Engine|Fetch TB Trace Engine]]
- [[_COMMUNITY_Decoder TB Trace Engine|Decoder TB Trace Engine]]
- [[_COMMUNITY_Top TB Trace Engine|Top TB Trace Engine]]
- [[_COMMUNITY_ALU TB Trace Engine|ALU TB Trace Engine]]
- [[_COMMUNITY_Verilator Symbol Tables|Verilator Symbol Tables]]
- [[_COMMUNITY_Assembler Encoders (gen_hex)|Assembler Encoders (gen_hex)]]
- [[_COMMUNITY_Assembler Encoders (gen_hex_2)|Assembler Encoders (gen_hex_2)]]
- [[_COMMUNITY_Full Core Cocotb Tests|Full Core Cocotb Tests]]
- [[_COMMUNITY_ALU Unit Tests|ALU Unit Tests]]
- [[_COMMUNITY_ALU VCD Trace|ALU VCD Trace]]
- [[_COMMUNITY_Top VCD Trace|Top VCD Trace]]
- [[_COMMUNITY_Fetch VCD Trace|Fetch VCD Trace]]
- [[_COMMUNITY_Decoder VCD Trace|Decoder VCD Trace]]
- [[_COMMUNITY_Cocotb Top VCD Trace|Cocotb Top VCD Trace]]
- [[_COMMUNITY_Top TB Symbols|Top TB Symbols]]
- [[_COMMUNITY_Fetch TB Symbols|Fetch TB Symbols]]
- [[_COMMUNITY_Decoder TB Symbols|Decoder TB Symbols]]
- [[_COMMUNITY_Fetch TB Root Header|Fetch TB Root Header]]
- [[_COMMUNITY_Decoder TB Root Header|Decoder TB Root Header]]
- [[_COMMUNITY_ALU TB Root Header|ALU TB Root Header]]
- [[_COMMUNITY_Top TB Root Header|Top TB Root Header]]
- [[_COMMUNITY_ALU TB Symbols|ALU TB Symbols]]
- [[_COMMUNITY_ALU TB Header|ALU TB Header]]
- [[_COMMUNITY_Cocotb Top Symbols|Cocotb Top Symbols]]
- [[_COMMUNITY_Cocotb Root Header|Cocotb Root Header]]
- [[_COMMUNITY_Cocotb Top Header|Cocotb Top Header]]
- [[_COMMUNITY_Instruction Decoder RTL|Instruction Decoder RTL]]
- [[_COMMUNITY_Instruction Memory RTL|Instruction Memory RTL]]
- [[_COMMUNITY_Fetch Stage RTL|Fetch Stage RTL]]
- [[_COMMUNITY_Top-Level Core RTL|Top-Level Core RTL]]
- [[_COMMUNITY_Data Memory RTL|Data Memory RTL]]
- [[_COMMUNITY_Register File RTL|Register File RTL]]
- [[_COMMUNITY_ALU RTL|ALU RTL]]
- [[_COMMUNITY_Fetch Verilog TB|Fetch Verilog TB]]
- [[_COMMUNITY_Top Verilog TB|Top Verilog TB]]
- [[_COMMUNITY_ALU Verilog TB|ALU Verilog TB]]
- [[_COMMUNITY_Decoder Verilog TB|Decoder Verilog TB]]
- [[_COMMUNITY_Top TB PCH Header|Top TB PCH Header]]
- [[_COMMUNITY_ALU TB PCH Header|ALU TB PCH Header]]
- [[_COMMUNITY_Decoder TB Header|Decoder TB Header]]
- [[_COMMUNITY_Top TB Compiled Unit|Top TB Compiled Unit]]
- [[_COMMUNITY_Fetch TB Compiled Unit|Fetch TB Compiled Unit]]
- [[_COMMUNITY_ALU TB Compiled Unit|ALU TB Compiled Unit]]
- [[_COMMUNITY_Decoder TB PCH Header|Decoder TB PCH Header]]
- [[_COMMUNITY_Top TB Main Header|Top TB Main Header]]
- [[_COMMUNITY_Fetch TB PCH Header|Fetch TB PCH Header]]
- [[_COMMUNITY_Decoder TB Compiled Unit|Decoder TB Compiled Unit]]
- [[_COMMUNITY_Fetch TB Main Header|Fetch TB Main Header]]
- [[_COMMUNITY_Cocotb Compiled Unit|Cocotb Compiled Unit]]
- [[_COMMUNITY_Cocotb DPI Bridge|Cocotb DPI Bridge]]
- [[_COMMUNITY_Cocotb Const Pool|Cocotb Const Pool]]
- [[_COMMUNITY_Cocotb DPI Header|Cocotb DPI Header]]
- [[_COMMUNITY_Cocotb PCH Header|Cocotb PCH Header]]

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
- `BoseRV RISC-V Course Overview (README)` --references--> `BoseRV Project`  [EXTRACTED]
  README.md → BoseRV_AI_Context.md
- `CLAUDE.md: graphify knowledge graph rule for BoseRV` --references--> `BoseRV Project`  [EXTRACTED]
  CLAUDE.md → BoseRV_AI_Context.md
- `Control Unit Decoder` --conceptually_related_to--> `Instruction Decoder (src/decoder.v)`  [EXTRACTED]
  BoseRV_Dashboard.md → BoseRV_AI_Context.md
- `Decoder OP_IMM Block (SLTI SLTIU XORI ORI ANDI SLLI SRLI SRAI)` --references--> `Instruction Decoder (src/decoder.v)`  [EXTRACTED]
  B4_Checklist.md → BoseRV_AI_Context.md
- `Decoder OP_REG Block (SLL SLT SLTU XOR SRL SRA OR AND)` --references--> `Instruction Decoder (src/decoder.v)`  [EXTRACTED]
  B4_Checklist.md → BoseRV_AI_Context.md

## Hyperedges (group relationships)
- **Single-Cycle Datapath: ALU + Decoder + Fetch + Regfile + Top wired together** — boserv_ai_context_alu, boserv_ai_context_decoder, boserv_ai_context_fetch, boserv_ai_context_regfile, boserv_ai_context_top [INFERRED]
- **Verification stack: Verilator + Cocotb + Pytest execute Python testbenches against Verilog** — implementation_plan_verilator, boserv_ai_context_cocotb_verification, dashboard_pytest, boserv_ai_context_test_top_py [INFERRED]
- **Linux boot chain: Privileged ISA + Peripherals + Supervisor Mode + OpenSBI required for Linux boot** — implementation_plan_privileged_isa, implementation_plan_peripherals, implementation_plan_supervisor_mode, implementation_plan_opensbi, implementation_plan_linux_boot [INFERRED]

## Communities

### Community 0 - "Top Testbench Root Logic"
Cohesion: 0.11
Nodes (32): Vtb_top___024root___ctor_var_reset(), Vtb_top___024root___dump_triggers__act(), Vtb_top___024root___dump_triggers__stl(), Vtb_top___024root___eval_initial__TOP(), Vtb_top___024root___eval_phase__stl(), Vtb_top___024root___eval_settle(), Vtb_top___024root___eval_static(), Vtb_top___024root___eval_static__TOP() (+24 more)

### Community 1 - "Decoder Checklist & ALU Opcodes"
Cohesion: 0.1
Nodes (36): ALU Opcode Reference Table, AUIPC Decoder Entry (opcode 0010111), Decoder OP_IMM Block (SLTI SLTIU XORI ORI ANDI SLLI SRLI SRAI), Decoder OP_REG Block (SLL SLT SLTU XOR SRL SRA OR AND), JAL Decoder Entry (opcode 1101111), ALU (src/alu.v), Rationale: AUIPC MUX wires PC to ALU input A instead of rs1, BoseRV Project (+28 more)

### Community 2 - "Verilator TB Entry Points"
Cohesion: 0.09
Nodes (23): main(), main(), main(), main(), Vtop___024root___eval_final(), eventsPending(), final(), hierName() (+15 more)

### Community 3 - "Cocotb Top Root Logic"
Cohesion: 0.13
Nodes (31): Vtop___024root___dump_triggers__act(), Vtop___024root___dump_triggers__ico(), Vtop___024root___dump_triggers__stl(), Vtop___024root___eval_initial(), Vtop___024root___eval_initial__TOP(), Vtop___024root___eval_phase__stl(), Vtop___024root___eval_settle(), Vtop___024root___eval_static() (+23 more)

### Community 4 - "Decoder Testbench Root"
Cohesion: 0.12
Nodes (28): Vtb_decoder___024root___ctor_var_reset(), Vtb_decoder___024root___dump_triggers__act(), Vtb_decoder___024root___dump_triggers__stl(), Vtb_decoder___024root___eval_phase__stl(), Vtb_decoder___024root___eval_settle(), Vtb_decoder___024root___eval_static(), Vtb_decoder___024root___eval_static__TOP(), Vtb_decoder___024root___eval_stl() (+20 more)

### Community 5 - "ALU Testbench Root"
Cohesion: 0.13
Nodes (27): Vtb_alu___024root___ctor_var_reset(), Vtb_alu___024root___dump_triggers__act(), Vtb_alu___024root___dump_triggers__stl(), Vtb_alu___024root___eval_phase__stl(), Vtb_alu___024root___eval_settle(), Vtb_alu___024root___eval_static(), Vtb_alu___024root___eval_static__TOP(), Vtb_alu___024root___eval_stl() (+19 more)

### Community 6 - "Fetch Testbench Root"
Cohesion: 0.13
Nodes (24): Vtb_fetch___024root___ctor_var_reset(), Vtb_fetch___024root___dump_triggers__act(), Vtb_fetch___024root___eval_initial__TOP(), Vtb_fetch___024root___eval_settle(), Vtb_fetch___024root___eval_static(), Vtb_fetch___024root___eval_static__TOP(), Vtb_fetch___024root____Vm_traceActivitySetAll(), Vtb_fetch___024root___eval() (+16 more)

### Community 7 - "Fetch TB Trace Engine"
Cohesion: 0.1
Nodes (16): Vtb_fetch___024root___eval_final(), final(), hierName(), name(), Vtb_fetch___024root__trace_const_0(), Vtb_fetch___024root__trace_const_0_sub_0(), Vtb_fetch___024root__trace_full_0(), Vtb_fetch___024root__trace_full_0_sub_0() (+8 more)

### Community 8 - "Decoder TB Trace Engine"
Cohesion: 0.1
Nodes (16): Vtb_decoder___024root___eval_final(), final(), hierName(), name(), Vtb_decoder___024root__trace_const_0(), Vtb_decoder___024root__trace_const_0_sub_0(), Vtb_decoder___024root__trace_full_0(), Vtb_decoder___024root__trace_full_0_sub_0() (+8 more)

### Community 9 - "Top TB Trace Engine"
Cohesion: 0.1
Nodes (16): Vtb_top___024root___eval_final(), final(), hierName(), name(), Vtb_top___024root__trace_const_0(), Vtb_top___024root__trace_const_0_sub_0(), Vtb_top___024root__trace_full_0(), Vtb_top___024root__trace_full_0_sub_0() (+8 more)

### Community 10 - "ALU TB Trace Engine"
Cohesion: 0.1
Nodes (14): Vtb_alu___024root___eval_final(), final(), hierName(), name(), Vtb_alu___024root__trace_full_0(), Vtb_alu___024root__trace_full_0_sub_0(), Vtb_alu___024root__trace_init_sub__TOP__0(), Vtb_alu___024root__trace_init_top() (+6 more)

### Community 11 - "Verilator Symbol Tables"
Cohesion: 0.09
Nodes (15): Vtb_alu__Syms(), eval_end_step(), _traceDumpClose(), Vtb_decoder__Syms(), eval_end_step(), _traceDumpClose(), Vtb_fetch__Syms(), eval_end_step() (+7 more)

### Community 12 - "Assembler Encoders (gen_hex)"
Cohesion: 0.44
Nodes (9): assemble_b(), assemble_i(), assemble_j(), assemble_l(), assemble_line(), assemble_r(), assemble_s(), assemble_u() (+1 more)

### Community 13 - "Assembler Encoders (gen_hex_2)"
Cohesion: 0.51
Nodes (9): assemble_b(), assemble_i(), assemble_j(), assemble_l(), assemble_line(), assemble_r(), assemble_s(), assemble_u() (+1 more)

### Community 14 - "Full Core Cocotb Tests"
Cohesion: 0.4
Nodes (4): Read register idx from DUT regfile, always returns unsigned 32-bit int., Run test_full.asm on BoseRV and verify the final architectural state.      Prima, read_reg(), test_full_rv32i()

### Community 15 - "ALU Unit Tests"
Cohesion: 0.4
Nodes (3): Test standard addition: 5 + 14 = 19, # TODO: Add more test cases here!, test_alu_addition()

### Community 16 - "ALU VCD Trace"
Cohesion: 0.67
Nodes (2): Vtb_alu___024root__trace_chg_0(), Vtb_alu___024root__trace_chg_0_sub_0()

### Community 17 - "Top VCD Trace"
Cohesion: 0.67
Nodes (2): Vtb_top___024root__trace_chg_0(), Vtb_top___024root__trace_chg_0_sub_0()

### Community 18 - "Fetch VCD Trace"
Cohesion: 0.67
Nodes (2): Vtb_fetch___024root__trace_chg_0(), Vtb_fetch___024root__trace_chg_0_sub_0()

### Community 19 - "Decoder VCD Trace"
Cohesion: 0.67
Nodes (2): Vtb_decoder___024root__trace_chg_0(), Vtb_decoder___024root__trace_chg_0_sub_0()

### Community 20 - "Cocotb Top VCD Trace"
Cohesion: 0.67
Nodes (2): Vtop___024root__trace_chg_0(), Vtop___024root__trace_chg_0_sub_0()

### Community 21 - "Top TB Symbols"
Cohesion: 1.0
Nodes (0): 

### Community 22 - "Fetch TB Symbols"
Cohesion: 1.0
Nodes (0): 

### Community 23 - "Decoder TB Symbols"
Cohesion: 1.0
Nodes (0): 

### Community 24 - "Fetch TB Root Header"
Cohesion: 1.0
Nodes (0): 

### Community 25 - "Decoder TB Root Header"
Cohesion: 1.0
Nodes (0): 

### Community 26 - "ALU TB Root Header"
Cohesion: 1.0
Nodes (0): 

### Community 27 - "Top TB Root Header"
Cohesion: 1.0
Nodes (0): 

### Community 28 - "ALU TB Symbols"
Cohesion: 1.0
Nodes (0): 

### Community 29 - "ALU TB Header"
Cohesion: 1.0
Nodes (0): 

### Community 30 - "Cocotb Top Symbols"
Cohesion: 1.0
Nodes (0): 

### Community 31 - "Cocotb Root Header"
Cohesion: 1.0
Nodes (0): 

### Community 32 - "Cocotb Top Header"
Cohesion: 1.0
Nodes (0): 

### Community 33 - "Instruction Decoder RTL"
Cohesion: 1.0
Nodes (0): 

### Community 34 - "Instruction Memory RTL"
Cohesion: 1.0
Nodes (0): 

### Community 35 - "Fetch Stage RTL"
Cohesion: 1.0
Nodes (0): 

### Community 36 - "Top-Level Core RTL"
Cohesion: 1.0
Nodes (0): 

### Community 37 - "Data Memory RTL"
Cohesion: 1.0
Nodes (0): 

### Community 38 - "Register File RTL"
Cohesion: 1.0
Nodes (0): 

### Community 39 - "ALU RTL"
Cohesion: 1.0
Nodes (0): 

### Community 40 - "Fetch Verilog TB"
Cohesion: 1.0
Nodes (0): 

### Community 41 - "Top Verilog TB"
Cohesion: 1.0
Nodes (0): 

### Community 42 - "ALU Verilog TB"
Cohesion: 1.0
Nodes (0): 

### Community 43 - "Decoder Verilog TB"
Cohesion: 1.0
Nodes (0): 

### Community 44 - "Top TB PCH Header"
Cohesion: 1.0
Nodes (0): 

### Community 45 - "ALU TB PCH Header"
Cohesion: 1.0
Nodes (0): 

### Community 46 - "Decoder TB Header"
Cohesion: 1.0
Nodes (0): 

### Community 47 - "Top TB Compiled Unit"
Cohesion: 1.0
Nodes (0): 

### Community 48 - "Fetch TB Compiled Unit"
Cohesion: 1.0
Nodes (0): 

### Community 49 - "ALU TB Compiled Unit"
Cohesion: 1.0
Nodes (0): 

### Community 50 - "Decoder TB PCH Header"
Cohesion: 1.0
Nodes (0): 

### Community 51 - "Top TB Main Header"
Cohesion: 1.0
Nodes (0): 

### Community 52 - "Fetch TB PCH Header"
Cohesion: 1.0
Nodes (0): 

### Community 53 - "Decoder TB Compiled Unit"
Cohesion: 1.0
Nodes (0): 

### Community 54 - "Fetch TB Main Header"
Cohesion: 1.0
Nodes (0): 

### Community 55 - "Cocotb Compiled Unit"
Cohesion: 1.0
Nodes (0): 

### Community 56 - "Cocotb DPI Bridge"
Cohesion: 1.0
Nodes (0): 

### Community 57 - "Cocotb Const Pool"
Cohesion: 1.0
Nodes (0): 

### Community 58 - "Cocotb DPI Header"
Cohesion: 1.0
Nodes (0): 

### Community 59 - "Cocotb PCH Header"
Cohesion: 1.0
Nodes (0): 

## Knowledge Gaps
- **10 isolated node(s):** `Test standard addition: 5 + 14 = 19`, `# TODO: Add more test cases here!`, `Read register idx from DUT regfile, always returns unsigned 32-bit int.`, `Run test_full.asm on BoseRV and verify the final architectural state.      Prima`, `Rationale: Tutor Mode — AI guides only, user writes all Verilog` (+5 more)
  These have ≤1 connection - possible missing edges or undocumented components.
- **Thin community `Top TB Symbols`** (2 nodes): `Vtb_top__Syms.h`, `name()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Fetch TB Symbols`** (2 nodes): `Vtb_fetch__Syms.h`, `name()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Decoder TB Symbols`** (2 nodes): `Vtb_decoder__Syms.h`, `name()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Fetch TB Root Header`** (2 nodes): `Vtb_fetch___024root.h`, `Vtb_fetch___024root()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Decoder TB Root Header`** (2 nodes): `Vtb_decoder___024root.h`, `Vtb_decoder___024root()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `ALU TB Root Header`** (2 nodes): `Vtb_alu___024root.h`, `Vtb_alu___024root()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Top TB Root Header`** (2 nodes): `Vtb_top___024root.h`, `Vtb_top___024root()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `ALU TB Symbols`** (2 nodes): `Vtb_alu__Syms.h`, `name()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `ALU TB Header`** (2 nodes): `Vtb_alu.h`, `eval_end_step()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Cocotb Top Symbols`** (2 nodes): `Vtop__Syms.h`, `name()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Cocotb Root Header`** (2 nodes): `Vtop___024root.h`, `Vtop___024root()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Cocotb Top Header`** (2 nodes): `Vtop.h`, `eval_end_step()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Instruction Decoder RTL`** (1 nodes): `decoder.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Instruction Memory RTL`** (1 nodes): `imem.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Fetch Stage RTL`** (1 nodes): `fetch.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Top-Level Core RTL`** (1 nodes): `top.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Data Memory RTL`** (1 nodes): `dmem.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Register File RTL`** (1 nodes): `regfile.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `ALU RTL`** (1 nodes): `alu.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Fetch Verilog TB`** (1 nodes): `tb_fetch.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Top Verilog TB`** (1 nodes): `tb_top.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `ALU Verilog TB`** (1 nodes): `tb_alu.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Decoder Verilog TB`** (1 nodes): `tb_decoder.v`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Top TB PCH Header`** (1 nodes): `Vtb_top__pch.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `ALU TB PCH Header`** (1 nodes): `Vtb_alu__pch.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Decoder TB Header`** (1 nodes): `Vtb_decoder.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Top TB Compiled Unit`** (1 nodes): `Vtb_top__ALL.cpp`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Fetch TB Compiled Unit`** (1 nodes): `Vtb_fetch__ALL.cpp`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `ALU TB Compiled Unit`** (1 nodes): `Vtb_alu__ALL.cpp`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Decoder TB PCH Header`** (1 nodes): `Vtb_decoder__pch.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Top TB Main Header`** (1 nodes): `Vtb_top.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Fetch TB PCH Header`** (1 nodes): `Vtb_fetch__pch.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Decoder TB Compiled Unit`** (1 nodes): `Vtb_decoder__ALL.cpp`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Fetch TB Main Header`** (1 nodes): `Vtb_fetch.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Cocotb Compiled Unit`** (1 nodes): `Vtop__ALL.cpp`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Cocotb DPI Bridge`** (1 nodes): `Vtop__Dpi.cpp`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Cocotb Const Pool`** (1 nodes): `Vtop__ConstPool__0__Slow.cpp`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Cocotb DPI Header`** (1 nodes): `Vtop__Dpi.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Cocotb PCH Header`** (1 nodes): `Vtop__pch.h`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **What connects `Test standard addition: 5 + 14 = 19`, `# TODO: Add more test cases here!`, `Read register idx from DUT regfile, always returns unsigned 32-bit int.` to the rest of the system?**
  _10 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `Top Testbench Root Logic` be split into smaller, more focused modules?**
  _Cohesion score 0.11 - nodes in this community are weakly interconnected._
- **Should `Decoder Checklist & ALU Opcodes` be split into smaller, more focused modules?**
  _Cohesion score 0.1 - nodes in this community are weakly interconnected._
- **Should `Verilator TB Entry Points` be split into smaller, more focused modules?**
  _Cohesion score 0.09 - nodes in this community are weakly interconnected._
- **Should `Cocotb Top Root Logic` be split into smaller, more focused modules?**
  _Cohesion score 0.13 - nodes in this community are weakly interconnected._
- **Should `Decoder Testbench Root` be split into smaller, more focused modules?**
  _Cohesion score 0.12 - nodes in this community are weakly interconnected._
- **Should `ALU Testbench Root` be split into smaller, more focused modules?**
  _Cohesion score 0.13 - nodes in this community are weakly interconnected._