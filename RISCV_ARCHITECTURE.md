# RISC-V 5-Stage Pipeline Architecture

This document visualizes the full architecture of this RISC-V core, matching the modules in `riscv-core/src/`.

---

## 1. Top-Level Overview

```mermaid
graph TD
    CLK([clk]) --> PIPE[pipe_top]
    RST([rst]) --> PIPE
    PIPE --> IMEM[imem\nInstruction Memory]
    PIPE --> DMEM[dmem\nData Memory]
    PIPE --> RF[regfile\nRegister File]
    PIPE --> ALU[alu\nArithmetic Logic Unit]
    PIPE --> DEC[decoder\nInstruction Decoder]
    PIPE --> FWD[forwarding\nForwarding Unit]
    PIPE --> HAZ[hazard\nHazard Detection]
    PIPE --> BHT[bht\nBranch History Table]
```

---

## 2. Full 5-Stage Pipeline Datapath

```mermaid
flowchart LR
    subgraph IF["① IF — Instruction Fetch"]
        PC["PC\n(Program Counter)"]
        IMEM["imem\nInstr Memory"]
        BHT_BOX["bht\nBranch Predictor"]
        PC -->|pc| IMEM
        PC -->|pc_in| BHT_BOX
    end

    subgraph IFID["IF/ID\nPipeline Reg"]
        R1["• pc\n• instr"]
    end

    subgraph ID["② ID — Instruction Decode"]
        DEC2["decoder\nDecode + Control"]
        RF2["regfile\nRead rs1, rs2"]
        DEC2 -->|rs1,rs2| RF2
    end

    subgraph IDEX["ID/EX\nPipeline Reg"]
        R2["• rs1_data\n• rs2_data\n• imm\n• rd\n• control"]
    end

    subgraph EX["③ EX — Execute"]
        MUX_A["MUX\nForward A"]
        MUX_B["MUX\nForward B"]
        ALU2["alu\nALU"]
        BRANCH["Branch Target\nCompute"]
        MUX_A --> ALU2
        MUX_B --> ALU2
    end

    subgraph EXMEM["EX/MEM\nPipeline Reg"]
        R3["• alu_result\n• rs2_data\n• rd\n• control"]
    end

    subgraph MEM["④ MEM — Memory"]
        DMEM2["dmem\nData Memory"]
    end

    subgraph MEMWB["MEM/WB\nPipeline Reg"]
        R4["• alu_result\n• mem_data\n• rd\n• control"]
    end

    subgraph WB["⑤ WB — Write Back"]
        MUXWB["MUX\nALU or Mem?"]
        RFWRITE["regfile\nWrite rd"]
        MUXWB --> RFWRITE
    end

    IF --> IFID --> ID --> IDEX --> EX --> EXMEM --> MEM --> MEMWB --> WB

    WB -->|"wb_data (forwarded)"| RF2
```

---

## 3. Hazard & Forwarding Control

```mermaid
flowchart TD
    subgraph HAZ["hazard.v — Hazard Detection Unit"]
        H1["Detects load-use hazards\n(MEM read followed by use)"]
        H2["Outputs: stall (PC + IF/ID hold)\nflush (IF/ID + ID/EX → NOP)"]
    end

    subgraph FWD["forwarding.v — Forwarding Unit"]
        F1["Detects EX-EX hazard\n→ forward from EX/MEM"]
        F2["Detects MEM-EX hazard\n→ forward from MEM/WB"]
        F3["Outputs: ForwardA, ForwardB\n(2-bit MUX select)"]
    end

    subgraph BHT["bht.v — Branch History Table"]
        B1["2-bit saturating counter\nper PC entry"]
        B2["Outputs prediction (taken/not)"]
        B3["Updated after branch resolves"]
    end

    EX_STAGE["EX Stage\n(ALU)"] -->|rs1/rs2 source| FWD
    FWD -->|ForwardA ForwardB| MUX["Forwarding MUXes\nin EX stage"]
    ID_STAGE["ID Stage\n(after decode)"] -->|rd EX, load signal| HAZ
    HAZ -->|stall| PC_IFIDreg["PC + IF/ID Reg"]
    HAZ -->|flush| IFIDIDEXreg["IF/ID + ID/EX Reg"]
    IF_STAGE["IF Stage\n(fetch)"] -->|pc| BHT
    BHT -->|prediction| PC_NEXT["Next PC MUX"]
```

---

## 4. Branch & Jump Logic

```mermaid
flowchart LR
    PC -->|current pc| ADDER1["PC + 4"]
    PC -->|current pc| BHT_PRED["bht\nprediction"]
    BHT_PRED -->|taken?| MUX_PC["Next PC MUX"]
    ADDER1 --> MUX_PC

    EX["EX Stage"] -->|branch_target\n= pc + imm| MUX_PC
    EX -->|branch_taken\n(ALU zero / compare)| CORRECT["Correction Logic"]
    CORRECT -->|misprediction flush| MUX_PC

    MUX_PC -->|next_pc| PC
```

---

## 5. Module Inventory

| Module | Stage | Role |
|---|---|---|
| `fetch.v` | IF | Drives PC, reads `imem` |
| `imem.v` | IF | Instruction ROM |
| `bht.v` | IF | 2-bit branch predictor |
| `if_id.v` | IF→ID | Pipeline register |
| `decoder.v` | ID | Decodes opcode, generates control signals |
| `regfile.v` | ID/WB | 32 × 32-bit register file |
| `id_ex.v` | ID→EX | Pipeline register |
| `alu.v` | EX | ADD/SUB/AND/OR/SLT/shifts |
| `multiplier.v` | EX | MUL/MULH (M-ext) |
| `divider.v` | EX | DIV/REM (M-ext) |
| `forwarding.v` | EX | Data hazard forwarding MUX select |
| `hazard.v` | ID/EX | Load-use stall + flush |
| `ex_mem.v` | EX→MEM | Pipeline register |
| `dmem.v` | MEM | Data memory (load/store) |
| `mem_wb.v` | MEM→WB | Pipeline register |
| `pipe_top.v` | ALL | Wires all stages together |
| `top.v` | SoC | Top-level chip wrapper |

---

## 6. Pipeline Register Data Flow (Signal Names)

```mermaid
flowchart LR
    subgraph IF_wires["IF wires"]
        pc_IF["pc_IF"]
        instr_IF["instr_IF"]
    end

    subgraph ID_wires["ID wires (after IF/ID)"]
        pc_ID["pc_ID"]
        rs1_data_ID["rs1_data_ID"]
        rs2_data_ID["rs2_data_ID"]
        imm_ID["imm_ID"]
        rd_ID["rd_ID"]
    end

    subgraph EX_wires["EX wires (after ID/EX)"]
        alu_result_EX["alu_result_EX"]
        rs2_data_EX["rs2_data_EX"]
        rd_EX["rd_EX"]
    end

    subgraph MEM_wires["MEM wires (after EX/MEM)"]
        alu_result_MEM["alu_result_MEM"]
        mem_read_data["mem_read_data"]
        rd_MEM["rd_MEM"]
    end

    subgraph WB_wires["WB wires (after MEM/WB)"]
        alu_result_WB["alu_result_WB"]
        mem_read_data_WB["mem_read_data_WB"]
        rd_WB["rd_WB"]
    end

    IF_wires --> ID_wires --> EX_wires --> MEM_wires --> WB_wires
```
