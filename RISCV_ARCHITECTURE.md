# BoseRV — RISC-V Pipelined Datapath
> Style: David Harris & Sarah Harris, *Digital Design and Computer Architecture*

---

## Complete Pipelined Datapath

```mermaid
flowchart LR
    %% ─────────── IF ───────────
    subgraph IF["  IF  "]
        direction TB
        PC(["PC"])
        IMEM["Instr\nMem"]
        PC -->|"PC"| IMEM
    end

    %% ─────────── IF/ID ───────────
    subgraph IFID["IF / ID"]
        direction TB
        R_PC1(["PC"])
        R_IN(["Instr"])
    end

    %% ─────────── ID ───────────
    subgraph ID["  ID  "]
        direction TB
        DEC["Decode\n+\nControl"]
        RF["Register\nFile\n32×32"]
        DEC -->|"rs1 rs2"| RF
    end

    %% ─────────── ID/EX ───────────
    subgraph IDEX["ID / EX"]
        direction TB
        R_PC2(["PC"])
        R_RD1(["RD1"])
        R_RD2(["RD2"])
        R_IMM(["Imm"])
        R_RS1(["rs1"])
        R_RS2(["rs2"])
        R_RD(["rd"])
        R_CTL(["alu_op\nalu_src\nmem_r\nmem_w\nreg_w\nwb_sel\nbranch\njump\njalr\nauipc\nlui"])
    end

    %% ─────────── EX ───────────
    subgraph EX["  EX  "]
        direction TB
        MUXA(["M\nU\nX\nA"])
        MUXB(["M\nU\nX\nB"])
        MUXSRC(["M\nU\nX\nsrc"])
        ALU["ALU"]
        BRANCH_ADD["PC+Imm\n(branch\ntarget)"]
        JUMP_ADD["rs1+Imm\n& ~1\n(JALR\ntarget)"]
        MUXA --> ALU
        MUXB --> MUXSRC --> ALU
        R_PC2 --> BRANCH_ADD
        R_IMM --> BRANCH_ADD
        R_RD1 --> JUMP_ADD
        R_IMM --> JUMP_ADD
    end

    %% ─────────── EX/MEM ───────────
    subgraph EXMEM["EX / MEM"]
        direction TB
        R_ALU(["ALU\nResult"])
        R_RD2B(["RD2"])
        R_PC4(["PC+4"])
        R_BTAR(["Branch\nTarget"])
        R_JTAR(["Jump\nTarget"])
        R_BTAKEN(["branch\ntaken"])
        R_RD2(["rd"])
        R_CTL2(["mem_r\nmem_w\nreg_w\nwb_sel\njump"])
    end

    %% ─────────── MEM ───────────
    subgraph MEM["  MEM  "]
        direction TB
        DMEM["Data\nMem"]
    end

    %% ─────────── MEM/WB ───────────
    subgraph MEMWB["MEM / WB"]
        direction TB
        R_ALU2(["ALU\nResult"])
        R_MDAT(["Mem\nData"])
        R_PC4B(["PC+4"])
        R_RD3(["rd"])
        R_CTL3(["reg_w\nwb_sel"])
    end

    %% ─────────── WB ───────────
    subgraph WB["  WB  "]
        direction TB
        MUXWB(["M\nU\nX\nwb"])
    end

    %% ─────────── Main pipeline flow ───────────
    IMEM -->|"Instr"| R_IN
    PC   -->|"PC"| R_PC1
    R_PC1 --> R_PC2
    R_IN --> DEC
    R_IN -->|"[19:15]\n[24:20]\n[11:7]"| RF
    DEC -->|"Imm\nalu_op\nalu_src\nmem_r/w\nreg_w\nwb_sel\nbranch\njump\njalr\nauipc\nlui"| R_CTL
    RF -->|"RD1"| R_RD1
    RF -->|"RD2"| R_RD2
    DEC -->|"Imm"| R_IMM
    DEC -->|"rs1"| R_RS1
    DEC -->|"rs2"| R_RS2
    DEC -->|"rd"| R_RD

    R_RD1 --> MUXA
    R_RD2 --> MUXB
    R_IMM --> MUXSRC
    ALU -->|"alu_result"| R_ALU
    ALU -->|"zero"| R_BTAKEN
    BRANCH_ADD -->|"branch_target"| R_BTAR
    JUMP_ADD -->|"jump_target"| R_JTAR
    R_PC2 -->|"PC+4"| R_PC4
    R_RD2 -->|"store data"| R_RD2B
    R_RD -->|"rd"| R_RD2
    R_CTL -->|"controls"| R_CTL2

    R_ALU -->|"addr / result"| DMEM
    R_RD2B -->|"write data"| DMEM
    R_ALU --> R_ALU2
    DMEM -->|"read data"| R_MDAT
    R_PC4 --> R_PC4B
    R_RD2 --> R_RD3
    R_CTL2 -->|"controls"| R_CTL3

    R_ALU2 --> MUXWB
    R_MDAT --> MUXWB
    R_PC4B --> MUXWB
    MUXWB -->|"WB data"| RF
```

---

## Hazard Unit + Forwarding Unit Overlay

```mermaid
flowchart LR
    subgraph PIPE["Pipeline (abbreviated)"]
        direction LR

        subgraph IF2["IF"]
            PC2(["PC"])
        end
        subgraph IFID2["IF/ID"]
            RS1ID(["rs1_ID"])
            RS2ID(["rs2_ID"])
        end
        subgraph EX2["EX"]
            MUXA2(["MUX A"])
            MUXB2(["MUX B"])
            ALU2["ALU"]
            MUXA2 --> ALU2
            MUXB2 --> ALU2
        end
        subgraph EXMEM2["EX/MEM"]
            RDMEM(["rd_MEM"])
            RGWMEM(["reg_write\n_MEM"])
            ALRMEM(["alu_result\n_MEM"])
        end
        subgraph MEMWB2["MEM/WB"]
            RDWB(["rd_WB"])
            RGWWB(["reg_write\n_WB"])
            WBDAT(["wb_data"])
        end

        IF2 --> IFID2 --> EX2 --> EXMEM2 --> MEMWB2
    end

    HAZ["Hazard\nDetection\nUnit\n\nmem_read_EX=1\nrd_EX=rs1_ID\nOR rs2_ID\n→ stall"]
    FWD["Forwarding\nUnit\n\nforward_A\nforward_B"]

    RDMEM -->|"rd_MEM\nreg_write_MEM"| FWD
    RDWB  -->|"rd_WB\nreg_write_WB"| FWD
    FWD -->|"2'b10 → EX/MEM\n2'b01 → MEM/WB\n2'b00 → RegFile"| MUXA2
    FWD -->|"same select"| MUXB2
    ALRMEM -->|"forward path"| MUXA2
    ALRMEM -->|"forward path"| MUXB2
    WBDAT  -->|"forward path"| MUXA2
    WBDAT  -->|"forward path"| MUXB2

    HAZ -->|"stall\n(freeze PC\n+ IF/ID)"| PC2
    HAZ -->|"flush\n(→ NOP bubble\nin ID/EX)"| EX2
```

---

## PC Next MUX — Full Priority Chain

```mermaid
flowchart LR
    PC4["pc_reg + 4\n(sequential)"]
    BT["branch_target\n= PC_EX + imm_b"]
    JT["jump_target\n= (rs1+imm) & ~1\n(JALR only)"]
    HOLD["pc_reg\n(stall hold)"]
    ZERO["0x00000000\n(reset)"]

    subgraph MUX["Next-PC MUX — Priority (high → low)"]
        direction TB
        P1["① rst  → 0x0"]
        P2["② branch_taken → branch_target"]
        P3["③ jump  → jump_target"]
        P4["④ stall → hold"]
        P5["⑤ default → PC+4"]
    end

    ZERO --> P1
    BT   --> P2
    JT   --> P3
    HOLD --> P4
    PC4  --> P5
    MUX  -->|"next_pc"| PCREG(["pc_reg"])
```

---

## Writeback MUX

```mermaid
flowchart LR
    ALU_R(["alu_result_WB"]) -->|"wb_sel = 00"| MUXWB2["WB\nMUX"]
    MEM_R(["mem_read_data_WB"]) -->|"wb_sel = 01"| MUXWB2
    PC4_R(["pc_plus4_WB"]) -->|"wb_sel = 10"| MUXWB2
    MUXWB2 -->|"wdata"| RF2["Register\nFile\n(write port)"]

    NOTE1["wb_sel=00 → R-type, I-ALU,\n         LUI, AUIPC"]
    NOTE2["wb_sel=01 → LW"]
    NOTE3["wb_sel=10 → JAL, JALR\n         (return addr)"]
```

---

## ALU Operand A MUX — LUI / AUIPC Special Routing

```mermaid
flowchart LR
    RS1_DATA(["rs1_data\n(from RegFile\nor forward)"]) -->|"normal"| MUXA3["ALU\nOperand A\nMUX"]
    PC_EX(["pc_EX"]) -->|"auipc = 1"| MUXA3
    ZERO2(["32'h0"]) -->|"lui = 1"| MUXA3
    MUXA3 -->|"alu_a"| ALU3["ALU"]

    NOTE_A["auipc: rd = PC + imm_u\nlui:   rd = 0  + imm_u"]
```

---

## Decoder — Immediate Formats

```mermaid
flowchart TD
    INSTR(["instr[31:0]"])

    subgraph I["I-type (ADDI, LW, JALR)"]
        I1["[31:20] sign-extended to 32 bits"]
    end
    subgraph S["S-type (SW)"]
        S1["[31:25] ++ [11:7] sign-extended"]
    end
    subgraph B["B-type (BEQ, BNE, BLT, BGE…)"]
        B1["[31][7][30:25][11:8] ++ 1'b0\nsign-extended — bit 0 always 0"]
    end
    subgraph U["U-type (LUI, AUIPC)"]
        U1["[31:12] ++ 12'b0"]
    end
    subgraph J["J-type (JAL)"]
        J1["[31][19:12][20][30:21] ++ 1'b0\nsign-extended — bit 0 always 0"]
    end

    INSTR --> I & S & B & U & J
```

---

## Control Signal Truth Table

| Instruction | `alu_src` | `mem_r` | `mem_w` | `reg_w` | `wb_sel` | `branch` | `jump` | `jalr` | `auipc` | `lui` |
|---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **R-type** (ADD, SUB…) | 0 | 0 | 0 | 1 | 00 | 0 | 0 | 0 | 0 | 0 |
| **I-ALU** (ADDI, ANDI…)| 1 | 0 | 0 | 1 | 00 | 0 | 0 | 0 | 0 | 0 |
| **LW** | 1 | 1 | 0 | 1 | 01 | 0 | 0 | 0 | 0 | 0 |
| **SW** | 1 | 0 | 1 | 0 | — | 0 | 0 | 0 | 0 | 0 |
| **BEQ/BNE/BLT…** | 0 | 0 | 0 | 0 | — | 1 | 0 | 0 | 0 | 0 |
| **LUI** | 1 | 0 | 0 | 1 | 00 | 0 | 0 | 0 | 0 | 1 |
| **AUIPC** | 1 | 0 | 0 | 1 | 00 | 0 | 0 | 0 | 1 | 0 |
| **JAL** | — | 0 | 0 | 1 | 10 | 0 | 1 | 0 | 0 | 0 |
| **JALR** | 0 | 0 | 0 | 1 | 10 | 0 | 1 | 1 | 0 | 0 |

---

## ALU Operations

| `alu_op` | Operation | Used by |
|---|---|---|
| `0000` | A + B | ADD, ADDI, LW/SW addr, AUIPC, LUI |
| `0001` | A − B | SUB, BEQ/BNE compare |
| `0010` | A & B | AND, ANDI |
| `0011` | A \| B | OR, ORI |
| `0100` | A ^ B | XOR, XORI |
| `0101` | A << B[4:0] | SLL, SLLI |
| `0110` | A >> B[4:0] | SRL, SRLI (logical) |
| `0111` | A >>> B[4:0] | SRA, SRAI (arithmetic) |
| `1000` | signed(A) < signed(B) | SLT, SLTI, BLT, BGE |
| `1001` | A < B (unsigned) | SLTU, SLTIU, BLTU, BGEU |

---

## Branch History Table — 2-Bit Saturating Counter

```mermaid
stateDiagram-v2
    direction LR
    SN : 00  Strongly\nNot-Taken
    WN : 01  Weakly\nNot-Taken
    WT : 10  Weakly\nTaken
    ST : 11  Strongly\nTaken

    SN --> WN : taken
    SN --> SN : not taken
    WN --> WT : taken
    WN --> SN : not taken
    WT --> ST : taken
    WT --> WN : not taken
    ST --> ST : taken
    ST --> WT : not taken
```

> **Index:** `pc_in[7:2]` → 6-bit → selects 1 of 64 counters.  
> **Predict:** `counter[1]` (MSB) — 1 = predict taken.  
> **Reset:** all counters → `2'b01` (Weakly Not-Taken).

---

## Pipeline Register Summary

| Register | Holds | On `rst` / `flush` | On `stall` |
|---|---|---|---|
| **IF/ID** | PC, Instr | → `0` (NOP) | freeze (hold) |
| **ID/EX** | All decode outputs + data | → `0` (all control=0) | → `0` (bubble) |
| **EX/MEM** | ALU result, store data, targets, control | → `0` | — |
| **MEM/WB** | ALU result, mem data, PC+4, control | → `0` | — |

---

## Load-Use Hazard — Why Forwarding Is Not Enough

```
Cycle      :   3         4         5         6
           ──────────────────────────────────────
lw  x1,0(x0): IF  →  ID  →  EX  →  MEM  →  WB
add x4,x1,x2:          IF  →  ID  → [stall] →  EX  →  MEM  → WB
                                 ↑
                           x1 needed here (start of EX)
                           but lw only produces it at end of MEM
                           → impossible without 1-cycle stall
```

Forwarding only helps after `lw` reaches **MEM** — by then `add` already needs `x1` at **EX** input.

---

## Forwarding Paths

```
Situation             forward_A/B   Source
──────────────────────────────────────────────
No hazard             2'b00         Register file (rdata1/rdata2)
EX-EX hazard          2'b10         alu_result_MEM  (1 cycle old)
MEM-EX hazard         2'b01         writeback_data  (2 cycles old)

EX-EX takes priority over MEM-EX when both match.
```
