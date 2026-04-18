// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(274);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_top = new VerilatedScope{this, "top", "top", "top", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_top__alu_inst = new VerilatedScope{this, "top.alu_inst", "alu_inst", "alu", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_top__decoder_inst = new VerilatedScope{this, "top.decoder_inst", "decoder_inst", "decoder", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_top__dmem_inst = new VerilatedScope{this, "top.dmem_inst", "dmem_inst", "dmem", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_top__fetch_inst = new VerilatedScope{this, "top.fetch_inst", "fetch_inst", "fetch", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_top__fetch_inst__u_imem = new VerilatedScope{this, "top.fetch_inst.u_imem", "u_imem", "imem", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_top__regfile_inst = new VerilatedScope{this, "top.regfile_inst", "regfile_inst", "regfile", -12, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_top);
    __Vhier.add(__Vscopep_top, __Vscopep_top__alu_inst);
    __Vhier.add(__Vscopep_top, __Vscopep_top__decoder_inst);
    __Vhier.add(__Vscopep_top, __Vscopep_top__dmem_inst);
    __Vhier.add(__Vscopep_top, __Vscopep_top__fetch_inst);
    __Vhier.add(__Vscopep_top, __Vscopep_top__regfile_inst);
    __Vhier.add(__Vscopep_top__fetch_inst, __Vscopep_top__fetch_inst__u_imem);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rst", &(TOP.rst), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_top->varInsert("alu_b_in", &(TOP.top__DOT__alu_b_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top->varInsert("alu_op", &(TOP.top__DOT__alu_op), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_top->varInsert("alu_result", &(TOP.top__DOT__alu_result), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top->varInsert("alu_src", &(TOP.top__DOT__alu_src), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top->varInsert("alu_zero", &(TOP.top__DOT__alu_zero), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top->varInsert("auipc", &(TOP.top__DOT__auipc), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top->varInsert("branch", &(TOP.top__DOT__branch), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top->varInsert("branch_taken", &(TOP.top__DOT__branch_taken), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top->varInsert("branch_target", &(TOP.top__DOT__branch_target), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top->varInsert("clk", &(TOP.top__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top->varInsert("funct3", &(TOP.top__DOT__funct3), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_top->varInsert("imm", &(TOP.top__DOT__imm), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top->varInsert("instr", &(TOP.top__DOT__instr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top->varInsert("jalr", &(TOP.top__DOT__jalr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top->varInsert("jump", &(TOP.top__DOT__jump), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top->varInsert("jump_target", &(TOP.top__DOT__jump_target), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top->varInsert("lui", &(TOP.top__DOT__lui), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top->varInsert("mem_read", &(TOP.top__DOT__mem_read), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top->varInsert("mem_read_data", &(TOP.top__DOT__mem_read_data), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top->varInsert("mem_write", &(TOP.top__DOT__mem_write), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top->varInsert("pc", &(TOP.top__DOT__pc), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top->varInsert("rd", &(TOP.top__DOT__rd), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_top->varInsert("reg_write", &(TOP.top__DOT__reg_write), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top->varInsert("rs1", &(TOP.top__DOT__rs1), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_top->varInsert("rs1_data", &(TOP.top__DOT__rs1_data), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top->varInsert("rs2", &(TOP.top__DOT__rs2), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_top->varInsert("rs2_data", &(TOP.top__DOT__rs2_data), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top->varInsert("rst", &(TOP.top__DOT__rst), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top->varInsert("wb_sel", &(TOP.top__DOT__wb_sel), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_top->varInsert("writeback_data", &(TOP.top__DOT__writeback_data), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__alu_inst->varInsert("a", &(TOP.top__DOT__alu_inst__DOT__a), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__alu_inst->varInsert("b", &(TOP.top__DOT__alu_inst__DOT__b), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__alu_inst->varInsert("op", &(TOP.top__DOT__alu_inst__DOT__op), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_top__alu_inst->varInsert("result", &(TOP.top__DOT__alu_inst__DOT__result), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__alu_inst->varInsert("zero", &(TOP.top__DOT__alu_inst__DOT__zero), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__decoder_inst->varInsert("OP_AUIPC", const_cast<void*>(static_cast<const void*>(&(TOP.top__DOT__decoder_inst__DOT__OP_AUIPC))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_top__decoder_inst->varInsert("OP_BRANCH", const_cast<void*>(static_cast<const void*>(&(TOP.top__DOT__decoder_inst__DOT__OP_BRANCH))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_top__decoder_inst->varInsert("OP_IMM", const_cast<void*>(static_cast<const void*>(&(TOP.top__DOT__decoder_inst__DOT__OP_IMM))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_top__decoder_inst->varInsert("OP_JAL", const_cast<void*>(static_cast<const void*>(&(TOP.top__DOT__decoder_inst__DOT__OP_JAL))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_top__decoder_inst->varInsert("OP_JALR", const_cast<void*>(static_cast<const void*>(&(TOP.top__DOT__decoder_inst__DOT__OP_JALR))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_top__decoder_inst->varInsert("OP_LOAD", const_cast<void*>(static_cast<const void*>(&(TOP.top__DOT__decoder_inst__DOT__OP_LOAD))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_top__decoder_inst->varInsert("OP_LUI", const_cast<void*>(static_cast<const void*>(&(TOP.top__DOT__decoder_inst__DOT__OP_LUI))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_top__decoder_inst->varInsert("OP_REG", const_cast<void*>(static_cast<const void*>(&(TOP.top__DOT__decoder_inst__DOT__OP_REG))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_top__decoder_inst->varInsert("OP_STORE", const_cast<void*>(static_cast<const void*>(&(TOP.top__DOT__decoder_inst__DOT__OP_STORE))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_top__decoder_inst->varInsert("alu_op", &(TOP.top__DOT__decoder_inst__DOT__alu_op), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_top__decoder_inst->varInsert("alu_src", &(TOP.top__DOT__decoder_inst__DOT__alu_src), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__decoder_inst->varInsert("auipc", &(TOP.top__DOT__decoder_inst__DOT__auipc), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__decoder_inst->varInsert("branch", &(TOP.top__DOT__decoder_inst__DOT__branch), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__decoder_inst->varInsert("funct3", &(TOP.top__DOT__decoder_inst__DOT__funct3), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_top__decoder_inst->varInsert("funct7", &(TOP.top__DOT__decoder_inst__DOT__funct7), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_top__decoder_inst->varInsert("imm", &(TOP.top__DOT__decoder_inst__DOT__imm), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__decoder_inst->varInsert("imm_b", &(TOP.top__DOT__decoder_inst__DOT__imm_b), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__decoder_inst->varInsert("imm_i", &(TOP.top__DOT__decoder_inst__DOT__imm_i), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__decoder_inst->varInsert("imm_j", &(TOP.top__DOT__decoder_inst__DOT__imm_j), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__decoder_inst->varInsert("imm_s", &(TOP.top__DOT__decoder_inst__DOT__imm_s), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__decoder_inst->varInsert("imm_u", &(TOP.top__DOT__decoder_inst__DOT__imm_u), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__decoder_inst->varInsert("instr", &(TOP.top__DOT__decoder_inst__DOT__instr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__decoder_inst->varInsert("jalr", &(TOP.top__DOT__decoder_inst__DOT__jalr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__decoder_inst->varInsert("jump", &(TOP.top__DOT__decoder_inst__DOT__jump), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__decoder_inst->varInsert("lui", &(TOP.top__DOT__decoder_inst__DOT__lui), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__decoder_inst->varInsert("mem_read", &(TOP.top__DOT__decoder_inst__DOT__mem_read), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__decoder_inst->varInsert("mem_write", &(TOP.top__DOT__decoder_inst__DOT__mem_write), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__decoder_inst->varInsert("opcode", &(TOP.top__DOT__decoder_inst__DOT__opcode), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_top__decoder_inst->varInsert("rd", &(TOP.top__DOT__decoder_inst__DOT__rd), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_top__decoder_inst->varInsert("reg_write", &(TOP.top__DOT__decoder_inst__DOT__reg_write), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__decoder_inst->varInsert("rs1", &(TOP.top__DOT__decoder_inst__DOT__rs1), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_top__decoder_inst->varInsert("rs2", &(TOP.top__DOT__decoder_inst__DOT__rs2), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_top__decoder_inst->varInsert("wb_sel", &(TOP.top__DOT__decoder_inst__DOT__wb_sel), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_top__dmem_inst->varInsert("addr", &(TOP.top__DOT__dmem_inst__DOT__addr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__dmem_inst->varInsert("clk", &(TOP.top__DOT__dmem_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__dmem_inst->varInsert("mem", &(TOP.top__DOT__dmem_inst__DOT__mem), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,255 ,31,0);
    __Vscopep_top__dmem_inst->varInsert("rd", &(TOP.top__DOT__dmem_inst__DOT__rd), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__dmem_inst->varInsert("wd", &(TOP.top__DOT__dmem_inst__DOT__wd), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__dmem_inst->varInsert("we", &(TOP.top__DOT__dmem_inst__DOT__we), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__fetch_inst->varInsert("branch_taken", &(TOP.top__DOT__fetch_inst__DOT__branch_taken), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__fetch_inst->varInsert("branch_target", &(TOP.top__DOT__fetch_inst__DOT__branch_target), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__fetch_inst->varInsert("clk", &(TOP.top__DOT__fetch_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__fetch_inst->varInsert("instr", &(TOP.top__DOT__fetch_inst__DOT__instr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__fetch_inst->varInsert("jump", &(TOP.top__DOT__fetch_inst__DOT__jump), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__fetch_inst->varInsert("jump_target", &(TOP.top__DOT__fetch_inst__DOT__jump_target), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__fetch_inst->varInsert("pc", &(TOP.top__DOT__fetch_inst__DOT__pc), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__fetch_inst->varInsert("pc_reg", &(TOP.top__DOT__fetch_inst__DOT__pc_reg), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__fetch_inst->varInsert("rst", &(TOP.top__DOT__fetch_inst__DOT__rst), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__fetch_inst__u_imem->varInsert("addr", &(TOP.top__DOT__fetch_inst__DOT__u_imem__DOT__addr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__fetch_inst__u_imem->varInsert("instr", &(TOP.top__DOT__fetch_inst__DOT__u_imem__DOT__instr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__fetch_inst__u_imem->varInsert("mem", &(TOP.top__DOT__fetch_inst__DOT__u_imem__DOT__mem), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,255 ,31,0);
    __Vscopep_top__regfile_inst->varInsert("clk", &(TOP.top__DOT__regfile_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_top__regfile_inst->varInsert("i", &(TOP.top__DOT__regfile_inst__DOT__i), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_top__regfile_inst->varInsert("rd", &(TOP.top__DOT__regfile_inst__DOT__rd), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_top__regfile_inst->varInsert("rdata1", &(TOP.top__DOT__regfile_inst__DOT__rdata1), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__regfile_inst->varInsert("rdata2", &(TOP.top__DOT__regfile_inst__DOT__rdata2), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__regfile_inst->varInsert("regs", &(TOP.top__DOT__regfile_inst__DOT__regs), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,31 ,31,0);
    __Vscopep_top__regfile_inst->varInsert("rs1", &(TOP.top__DOT__regfile_inst__DOT__rs1), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_top__regfile_inst->varInsert("rs2", &(TOP.top__DOT__regfile_inst__DOT__rs2), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_top__regfile_inst->varInsert("wdata", &(TOP.top__DOT__regfile_inst__DOT__wdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top__regfile_inst->varInsert("we", &(TOP.top__DOT__regfile_inst__DOT__we), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_top);
    __Vhier.remove(__Vscopep_top, __Vscopep_top__alu_inst);
    __Vhier.remove(__Vscopep_top, __Vscopep_top__decoder_inst);
    __Vhier.remove(__Vscopep_top, __Vscopep_top__dmem_inst);
    __Vhier.remove(__Vscopep_top, __Vscopep_top__fetch_inst);
    __Vhier.remove(__Vscopep_top, __Vscopep_top__regfile_inst);
    __Vhier.remove(__Vscopep_top__fetch_inst, __Vscopep_top__fetch_inst__u_imem);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_top, __Vscopep_top = nullptr);
    VL_DO_CLEAR(delete __Vscopep_top__alu_inst, __Vscopep_top__alu_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_top__decoder_inst, __Vscopep_top__decoder_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_top__dmem_inst, __Vscopep_top__dmem_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_top__fetch_inst, __Vscopep_top__fetch_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_top__fetch_inst__u_imem, __Vscopep_top__fetch_inst__u_imem = nullptr);
    VL_DO_CLEAR(delete __Vscopep_top__regfile_inst, __Vscopep_top__regfile_inst = nullptr);
    // Tear down sub module instances
}
