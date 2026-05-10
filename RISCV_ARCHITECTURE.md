# BoseRV — Complete RISC-V Architecture
> Harris & Harris style · Every wire matches the actual Verilog source

---

## 1. BoseRV Chip — Top-Level View

```mermaid
flowchart TD
    subgraph CHIP["BoseRV SoC"]
        direction TB

        subgraph CLKRST["Clock & Reset"]
            CLK(["clk"])
            RST(["rst"])
        end

        subgraph CORE["pipe_top.v — Pipelined RV32I Core"]
            direction LR

            subgraph IFB["IF"]
                FETCH["fetch.v\n+ imem.v\n+ bht.v"]
            end
            subgraph PIPELINE["Pipeline Registers"]
                IFID_B["if_id.v"]
                IDEX_B["id_ex.v"]
                EXMEM_B["ex_mem.v"]
                MEMWB_B["mem_wb.v"]
            end
            subgraph IDB["ID"]
                DEC2["decoder.v"]
                RF2["regfile.v"]
            end
            subgraph EXB["EX"]
                ALU2["alu.v"]
                MUL["multiplier.v\n(M-ext, TODO)"]
                DIV["divider.v\n(M-ext, TODO)"]
                FWD2["forwarding.v"]
            end
            subgraph MEMB["MEM"]
                DMEM2["dmem.v"]
            end
            subgraph WBB["WB"]
                WBMUX2["wb_sel MUX"]
            end
            subgraph CTRL["Control"]
                HAZ2["hazard.v"]
            end
        end

        subgraph REF["top.v — Single-Cycle Reference Core"]
            direction LR
            SC_F["fetch"] --> SC_D["decode"] --> SC_E["execute"] --> SC_M["memory"] --> SC_W["writeback"]
        end
    end

    CLK --> CORE
    RST --> CORE
    CLK --> REF
    RST --> REF
```

---

## 2. Full Pipelined Datapath — pipe_top.v

> One diagram — every stage, every MUX, every pipeline register, every control wire.

```mermaid
flowchart LR

    %% ══════════════ IF STAGE ══════════════
    subgraph IF["━━━━━━━  IF  ━━━━━━━"]
        direction TB
        PC(["pc_reg\n32-bit"])
        IMEM_B["imem\n256×32 ROM\n(instr_mem.hex)"]
        BHT_B["bht\n64×2-bit\ncounters"]
        PCMUX["Next-PC\nMUX"]

        PCMUX -->|next_pc| PC
        PC -->|addr| IMEM_B
        PC -->|pc_in| BHT_B
        BHT_B -->|prediction| PCMUX
        PC -->|+4| PCMUX
    end

    %% ══════════════ IF/ID ══════════════
    subgraph IFID["━━  IF/ID  ━━\nif_id.v"]
        direction TB
        IPC(["pc\n[31:0]"])
        IIN(["instr\n[31:0]"])
    end

    %% ══════════════ ID STAGE ══════════════
    subgraph ID["━━━━━━━  ID  ━━━━━━━"]
        direction TB
        DEC3["decoder.v\n(combinational)"]
        RF3["regfile.v\n32 × 32-bit\nx0 hardwired = 0"]
        DEC3 -->|"rs1[4:0]\nrs2[4:0]"| RF3
    end

    %% ══════════════ ID/EX ══════════════
    subgraph IDEX["━━  ID/EX  ━━\nid_ex.v"]
        direction TB
        EPC(["pc_EX"])
        ERD1(["rs1_data_EX"])
        ERD2(["rs2_data_EX"])
        EIMM(["imm_EX"])
        ERS1(["rs1_EX [4:0]"])
        ERS2(["rs2_EX [4:0]"])
        ERD(["rd_EX [4:0]"])
        ECTL(["alu_op · alu_src\nmem_r · mem_w\nreg_w · wb_sel\nbranch · jump\njalr · auipc · lui\nfunct3"])
    end

    %% ══════════════ EX STAGE ══════════════
    subgraph EX["━━━━━━━  EX  ━━━━━━━"]
        direction TB
        FWDA(["Fwd MUX A\n00=RF\n10=EX/MEM\n01=MEM/WB"])
        FWDB(["Fwd MUX B\n00=RF\n10=EX/MEM\n01=MEM/WB"])
        AMUX(["ALU-src MUX\n0=rs2\n1=imm"])
        AMUX_A(["A-operand MUX\nnormal=rs1\nauipc=PC\nlui=0"])
        ALU3["alu.v\nADD/SUB/AND/OR\nXOR/SLL/SRL/SRA\nSLT/SLTU"]
        BTADD["pc_EX + imm\nbranch_target"]
        JTADD["(rs1+imm)&~1\njump_target"]
        BRLOGIC["Branch\nCondition\nfunct3 decode"]

        AMUX_A --> ALU3
        FWDB --> AMUX --> ALU3
        ALU3 -->|zero| BRLOGIC
        ALU3 -->|"result[0]"| BRLOGIC
    end

    %% ══════════════ EX/MEM ══════════════
    subgraph EXMEM["━━  EX/MEM  ━━\nex_mem.v"]
        direction TB
        MALUR(["alu_result_MEM"])
        MRSD2(["rs2_data_MEM"])
        MPC4(["pc_plus4_MEM"])
        MBTAR(["branch_target_MEM"])
        MJTAR(["jump_target_MEM"])
        MBTK(["branch_taken_MEM"])
        MRD(["rd_MEM [4:0]"])
        MCTL(["mem_r · mem_w\nreg_w · wb_sel\njump"])
    end

    %% ══════════════ MEM STAGE ══════════════
    subgraph MEM["━━━━━━━  MEM  ━━━━━━━"]
        direction TB
        DMEM3["dmem.v\n256×32 RAM\nSW sync write\nLW async read"]
    end

    %% ══════════════ MEM/WB ══════════════
    subgraph MEMWB["━━  MEM/WB  ━━\nmem_wb.v"]
        direction TB
        WALUR(["alu_result_WB"])
        WMDAT(["mem_data_WB"])
        WPC4(["pc_plus4_WB"])
        WRD(["rd_WB [4:0]"])
        WCTL(["reg_w · wb_sel"])
    end

    %% ══════════════ WB STAGE ══════════════
    subgraph WB["━━━━━━━  WB  ━━━━━━━"]
        direction TB
        WBMUX3["wb_sel MUX\n00 = alu_result\n01 = mem_data\n10 = pc_plus4"]
    end

    %% ══════════════ DATAPATH CONNECTIONS ══════════════
    IMEM_B -->|instr| IIN
    PC     -->|pc| IPC

    IPC --> EPC
    IIN -->|"[31:0]"| DEC3
    IIN -->|"[19:15]rs1\n[24:20]rs2\n[11:7] rd"| RF3

    DEC3 -->|imm| EIMM
    DEC3 -->|rs1| ERS1
    DEC3 -->|rs2| ERS2
    DEC3 -->|rd| ERD
    DEC3 -->|controls| ECTL
    RF3  -->|rdata1| ERD1
    RF3  -->|rdata2| ERD2

    ERD1 --> FWDA --> AMUX_A
    ERD2 --> FWDB --> AMUX
    EIMM --> AMUX
    EPC  --> BTADD
    EIMM --> BTADD
    ERD1 --> JTADD
    EIMM --> JTADD

    ALU3 -->|alu_result| MALUR
    ERD2 -->|rs2_data| MRSD2
    EPC  -->|"+4"| MPC4
    BTADD --> MBTAR
    JTADD --> MJTAR
    BRLOGIC -->|branch_taken| MBTK
    ERD  -->|rd| MRD
    ECTL -->|controls| MCTL

    MALUR -->|addr| DMEM3
    MRSD2 -->|write data| DMEM3
    MALUR --> WALUR
    DMEM3 -->|read data| WMDAT
    MPC4  --> WPC4
    MRD   --> WRD
    MCTL  -->|reg_w wb_sel| WCTL

    WALUR --> WBMUX3
    WMDAT --> WBMUX3
    WPC4  --> WBMUX3
    WBMUX3 -->|wdata| RF3

    %% ══════════════ BRANCH/JUMP FEEDBACK ══════════════
    MBTK  -->|branch_taken| PCMUX
    MBTAR -->|branch_target| PCMUX
    MJTAR -->|jump_target| PCMUX
```

---

## 3. Hazard & Forwarding Unit Connections

```mermaid
flowchart TD
    subgraph HAZ_BOX["hazard.v"]
        HC1["mem_read_EX = 1\nAND rd_EX ≠ 0\nAND rd_EX = rs1_ID\n   OR rs2_ID\n────────────────\n→ stall = 1"]
    end

    subgraph FWD_BOX["forwarding.v"]
        FC1["EX-EX:  rd_MEM=rs1_EX → forward_A=2'b10\nEX-EX:  rd_MEM=rs2_EX → forward_B=2'b10\nMEM-EX: rd_WB =rs1_EX → forward_A=2'b01\nMEM-EX: rd_WB =rs2_EX → forward_B=2'b01\nNo match             → forward_X=2'b00"]
    end

    IDEX_OUT(["ID/EX outputs\nrs1_EX rs2_EX\nmem_read_EX rd_EX"])
    EXMEM_OUT(["EX/MEM outputs\nrd_MEM reg_write_MEM\nalu_result_MEM"])
    MEMWB_OUT(["MEM/WB outputs\nrd_WB reg_write_WB\nwriteback_data"])
    IFID_OUT(["IF/ID outputs\nrs1_ID rs2_ID"])

    IDEX_OUT -->|"rs1_EX rs2_EX"| FWD_BOX
    EXMEM_OUT -->|"rd_MEM reg_write_MEM"| FWD_BOX
    MEMWB_OUT -->|"rd_WB reg_write_WB"| FWD_BOX

    IDEX_OUT -->|"mem_read_EX\nrd_EX"| HAZ_BOX
    IFID_OUT -->|"rs1_ID rs2_ID"| HAZ_BOX

    FWD_BOX -->|"forward_A [1:0]"| MUXA_BOX(["ALU Fwd MUX A"])
    FWD_BOX -->|"forward_B [1:0]"| MUXB_BOX(["ALU Fwd MUX B"])
    EXMEM_OUT -->|"alu_result_MEM"| MUXA_BOX & MUXB_BOX
    MEMWB_OUT -->|"writeback_data"| MUXA_BOX & MUXB_BOX

    HAZ_BOX -->|"stall → hold PC\n        hold IF/ID"| PC_BOX(["fetch.v\nPC register"])
    HAZ_BOX -->|"flush → zero\nall control"| IDEX_BOX(["id_ex.v\n(NOP bubble)"])
```

---

## 4. Branch Condition Decoder — Inside EX Stage

```mermaid
flowchart LR
    ALU_Z(["alu_zero\n(result==0)"])
    ALU_R0(["alu_result[0]\n(SLT/SLTU bit)"])
    F3(["funct3\n[2:0]"])
    BR(["branch\n(B-type flag)"])

    subgraph COND["Branch Condition Logic"]
        C0["000 BEQ  →  alu_zero"]
        C1["001 BNE  → !alu_zero"]
        C2["100 BLT  →  result[0]"]
        C3["101 BGE  → !result[0]"]
        C4["110 BLTU →  result[0]"]
        C5["111 BGEU → !result[0]"]
    end

    ALU_Z  --> COND
    ALU_R0 --> COND
    F3     --> COND
    BR     -->|"branch & condition"| TAKEN(["branch_taken"])
    COND   --> TAKEN
```

---

## 5. ALU Operand Routing — Full MUX Chain

```mermaid
flowchart LR
    subgraph SRC_A["Operand A source"]
        RF_RD1(["rs1_data\n(from RF or forward)"])
        PC_EX(["pc_EX"])
        ZERO_A(["32'h0"])
        RF_RD1 -->|"default"| AMUX_F["A-opnd MUX\n(auipc/lui)"]
        PC_EX  -->|"auipc=1"| AMUX_F
        ZERO_A -->|"lui=1"| AMUX_F
    end

    subgraph SRC_B["Operand B source"]
        FWD_RS2(["fwd_rs2\n(from RF or forward)"])
        IMM_EX(["imm_EX\n32-bit"])
        FWD_RS2 -->|"alu_src=0"| BMUX_F["B-opnd MUX\n(alu_src)"]
        IMM_EX  -->|"alu_src=1"| BMUX_F
    end

    AMUX_F -->|"alu_a"| ALU_FINAL["alu.v"]
    BMUX_F -->|"alu_b"| ALU_FINAL
    ALU_FINAL -->|"result [31:0]"| RESULT(["alu_result"])
    ALU_FINAL -->|"zero"| ZERO_OUT(["zero flag"])
```

---

## 6. Writeback MUX

```mermaid
flowchart LR
    AR(["alu_result_WB"]) -->|"wb_sel = 2'b00"| WB3["wb_sel\nMUX"]
    MD(["mem_data_WB"])   -->|"wb_sel = 2'b01"| WB3
    P4(["pc_plus4_WB"])   -->|"wb_sel = 2'b10"| WB3
    WB3 -->|"writeback_data"| REG_W["regfile.v\nwrite port\n(rd, we=reg_write)"]
    REG_W -.->|"also forwarded\nto EX MUXes"| FWD_PATH(["MEM-EX\nforward path"])

    NOTE_WB["wb_sel=00 → R-type · I-ALU · LUI · AUIPC
wb_sel=01 → LW
wb_sel=10 → JAL · JALR  (return address)"]
```

---

## 7. BHT — Branch History Table

```mermaid
flowchart LR
    subgraph BHT_INT["bht.v — 64 × 2-bit saturating counters"]
        direction TB
        PSIDE["PREDICT (combinational)\npc_in[7:2] → index\ncounter[1] → prediction"]
        UTABLE["counter_table[0:63]"]
        USIDE["UPDATE (registered)\nupdate_pc[7:2] → index\nactual_taken → 2'b11\nrst → all = 2'b01"]
        PSIDE --- UTABLE --- USIDE
    end

    PC_B(["pc_in [31:0]"]) -->|"[7:2]"| BHT_INT
    BHT_INT -->|"prediction"| PCMUX_B(["Next-PC MUX"])
    UEN(["update_en"]) --> BHT_INT
    UPC(["update_pc"]) --> BHT_INT
    ATAKEN(["actual_taken"]) --> BHT_INT
```

**2-bit counter state machine:**

```mermaid
stateDiagram-v2
    direction LR
    s1 : 00 Strongly Not-Taken
    s2 : 01 Weakly Not-Taken
    s3 : 10 Weakly Taken
    s4 : 11 Strongly Taken

    s1 --> s2 : taken
    s1 --> s1 : not taken
    s2 --> s3 : taken
    s2 --> s1 : not taken
    s3 --> s4 : taken
    s3 --> s2 : not taken
    s4 --> s4 : taken
    s4 --> s3 : not taken
```

---

## 8. Single-Cycle Reference Core — top.v

> `top.v` is the original single-cycle version. `pipe_top.v` is the pipelined upgrade.
> Both use the same leaf modules: `fetch`, `decoder`, `regfile`, `alu`, `dmem`.

```mermaid
flowchart LR
    subgraph SC["top.v — Single-Cycle (no pipeline registers)"]
        direction LR
        SC_PC(["PC"]) -->|addr| SC_IM["imem"]
        SC_IM -->|instr| SC_DEC["decoder"]
        SC_DEC -->|rs1 rs2| SC_RF["regfile"]
        SC_DEC -->|rd| SC_RF
        SC_RF -->|rdata1 rdata2| SC_ALU["ALU"]
        SC_DEC -->|imm alu_op alu_src| SC_ALU
        SC_ALU -->|result| SC_DM["dmem"]
        SC_RF -->|rdata2| SC_DM
        SC_DM -->|read data| SC_WBMUX["WB MUX\nwb_sel"]
        SC_ALU -->|result| SC_WBMUX
        SC_PC  -->|"+4"| SC_WBMUX
        SC_WBMUX -->|wdata| SC_RF
        SC_ALU -->|branch_taken| SC_PCMUX["PC MUX"]
        SC_PCMUX -->|next_pc| SC_PC
    end
```

**Key difference from pipelined:**

| | `top.v` single-cycle | `pipe_top.v` pipelined |
|---|---|---|
| Pipeline registers | None | IF/ID · ID/EX · EX/MEM · MEM/WB |
| Hazard handling | Not needed | `hazard.v` — load-use stall |
| Forwarding | Not needed | `forwarding.v` — EX-EX & MEM-EX |
| Branch predictor | Not present | `bht.v` — 2-bit saturating |
| CPI (ideal) | 1 (but slow clock) | ~1 (fast clock, stalls on hazard) |

---

## 9. Future: M-Extension (multiplier.v · divider.v)

```mermaid
flowchart LR
    subgraph M_EXT["M-Extension — EX Stage (TODO)"]
        direction TB
        MUL_B["multiplier.v\nMUL MULH MULHSU MULHU\n(Assignment E1)"]
        DIV_B["divider.v\nDIV DIVU REM REMU\nState machine\n(Assignment E2)"]
        MUX_EX["EX result MUX\nalu_result\nor mul_result\nor div_result"]
        MUL_B -->|"mul_result"| MUX_EX
        DIV_B -->|"div_result"| MUX_EX
    end

    RS1_M(["rs1_data_EX"]) --> MUL_B & DIV_B
    RS2_M(["rs2_data_EX"]) --> MUL_B & DIV_B
    ALU_M(["alu_result"])   --> MUX_EX
    FUNCT3_M(["funct3\nfunct7"]) -->|"select"| MUX_EX
    MUX_EX -->|"to EX/MEM reg"| EXMEM_M(["EX/MEM register"])
```

---

## 10. Complete Module Hierarchy

```mermaid
flowchart TD
    TOP_V["top.v\n(single-cycle reference)"]
    PIPE_V["pipe_top.v\n(pipelined core)"]

    TOP_V --> FETCH_V["fetch.v"]
    TOP_V --> DEC_V["decoder.v"]
    TOP_V --> RF_V["regfile.v"]
    TOP_V --> ALU_V["alu.v"]
    TOP_V --> DMEM_V["dmem.v"]

    FETCH_V --> IMEM_V["imem.v"]

    PIPE_V --> FETCH_V
    PIPE_V --> IFID_V["if_id.v"]
    PIPE_V --> DEC_V
    PIPE_V --> RF_V
    PIPE_V --> IDEX_V["id_ex.v"]
    PIPE_V --> ALU_V
    PIPE_V --> MUL_V["multiplier.v\n(M-ext, TODO)"]
    PIPE_V --> DIV_V["divider.v\n(M-ext, TODO)"]
    PIPE_V --> FWD_V["forwarding.v"]
    PIPE_V --> HAZ_V["hazard.v"]
    PIPE_V --> EXMEM_V["ex_mem.v"]
    PIPE_V --> DMEM_V
    PIPE_V --> MEMWB_V["mem_wb.v"]
    PIPE_V --> BHT_V["bht.v"]
```

---

## 11. Signal Name Reference — Exact Wire Names from pipe_top.v

| Signal | Stage suffix | Example | Meaning |
|---|---|---|---|
| `pc` | `_IF _ID _EX` | `pc_EX` | Program counter at that stage |
| `instr` | — | `instr_IF` | Raw 32-bit instruction |
| `rs1_data` | `_ID _EX` | `rs1_data_EX` | Register file read 1 |
| `rs2_data` | `_ID _EX _MEM` | `rs2_data_MEM` | Register file read 2 / store data |
| `alu_result` | `_EX _MEM _WB` | `alu_result_MEM` | ALU output |
| `mem_read_data` | `_MEM _WB` | `mem_read_data_WB` | dmem read output |
| `pc_plus4` | `_MEM _WB` | `pc_plus4_WB` | Return address |
| `branch_target` | `_MEM` | `branch_target_MEM` | PC + imm_b |
| `jump_target` | `_MEM` | `jump_target_MEM` | (rs1+imm)&~1 |
| `branch_taken` | `_EX _MEM` | `branch_taken_MEM` | Branch condition result |
| `writeback_data` | — | `writeback_data` | Final WB MUX output |
| `fwd_rs1` | — | `fwd_rs1` | rs1 after forwarding MUX |
| `fwd_rs2` | — | `fwd_rs2` | rs2 after forwarding MUX |
| `forward_A/B` | — | `forward_A` | 2-bit MUX select from forwarding unit |
| `stall` | — | `stall` | 1 = freeze PC + IF/ID |
| `flush` | — | `flush` | 1 = zero ID/EX controls (NOP bubble) |
| `prediction` | — | `prediction` | BHT branch prediction |
