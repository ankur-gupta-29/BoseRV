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
    __Vscopep_pipe_top = new VerilatedScope{this, "pipe_top", "pipe_top", "pipe_top", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_pipe_top__alu_inst = new VerilatedScope{this, "pipe_top.alu_inst", "alu_inst", "alu", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_pipe_top__decoder_inst = new VerilatedScope{this, "pipe_top.decoder_inst", "decoder_inst", "decoder", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_pipe_top__dmem_inst = new VerilatedScope{this, "pipe_top.dmem_inst", "dmem_inst", "dmem", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_pipe_top__ex_mem_inst = new VerilatedScope{this, "pipe_top.ex_mem_inst", "ex_mem_inst", "ex_mem", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_pipe_top__fetch_inst = new VerilatedScope{this, "pipe_top.fetch_inst", "fetch_inst", "fetch", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_pipe_top__fetch_inst__u_imem = new VerilatedScope{this, "pipe_top.fetch_inst.u_imem", "u_imem", "imem", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_pipe_top__id_ex_inst = new VerilatedScope{this, "pipe_top.id_ex_inst", "id_ex_inst", "id_ex", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_pipe_top__if_id_inst = new VerilatedScope{this, "pipe_top.if_id_inst", "if_id_inst", "if_id", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_pipe_top__mem_wb_inst = new VerilatedScope{this, "pipe_top.mem_wb_inst", "mem_wb_inst", "mem_wb", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_pipe_top__regfile_inst = new VerilatedScope{this, "pipe_top.regfile_inst", "regfile_inst", "regfile", -12, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_pipe_top);
    __Vhier.add(__Vscopep_pipe_top, __Vscopep_pipe_top__alu_inst);
    __Vhier.add(__Vscopep_pipe_top, __Vscopep_pipe_top__decoder_inst);
    __Vhier.add(__Vscopep_pipe_top, __Vscopep_pipe_top__dmem_inst);
    __Vhier.add(__Vscopep_pipe_top, __Vscopep_pipe_top__ex_mem_inst);
    __Vhier.add(__Vscopep_pipe_top, __Vscopep_pipe_top__fetch_inst);
    __Vhier.add(__Vscopep_pipe_top, __Vscopep_pipe_top__id_ex_inst);
    __Vhier.add(__Vscopep_pipe_top, __Vscopep_pipe_top__if_id_inst);
    __Vhier.add(__Vscopep_pipe_top, __Vscopep_pipe_top__mem_wb_inst);
    __Vhier.add(__Vscopep_pipe_top, __Vscopep_pipe_top__regfile_inst);
    __Vhier.add(__Vscopep_pipe_top__fetch_inst, __Vscopep_pipe_top__fetch_inst__u_imem);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rst", &(TOP.rst), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("alu_b_EX", &(TOP.pipe_top__DOT__alu_b_EX), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("alu_op_EX", &(TOP.pipe_top__DOT__alu_op_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_pipe_top->varInsert("alu_op_ID", &(TOP.pipe_top__DOT__alu_op_ID), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_pipe_top->varInsert("alu_result_EX", &(TOP.pipe_top__DOT__alu_result_EX), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("alu_result_MEM", &(TOP.pipe_top__DOT__alu_result_MEM), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("alu_result_WB", &(TOP.pipe_top__DOT__alu_result_WB), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("alu_src_EX", &(TOP.pipe_top__DOT__alu_src_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("alu_src_ID", &(TOP.pipe_top__DOT__alu_src_ID), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("alu_zero_EX", &(TOP.pipe_top__DOT__alu_zero_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("alu_zero_MEM", &(TOP.pipe_top__DOT__alu_zero_MEM), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("auipc_EX", &(TOP.pipe_top__DOT__auipc_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("auipc_ID", &(TOP.pipe_top__DOT__auipc_ID), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("branch_EX", &(TOP.pipe_top__DOT__branch_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("branch_ID", &(TOP.pipe_top__DOT__branch_ID), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("branch_taken_EX", &(TOP.pipe_top__DOT__branch_taken_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("branch_taken_MEM", &(TOP.pipe_top__DOT__branch_taken_MEM), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("branch_target_EX", &(TOP.pipe_top__DOT__branch_target_EX), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("branch_target_MEM", &(TOP.pipe_top__DOT__branch_target_MEM), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("clk", &(TOP.pipe_top__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("funct3_EX", &(TOP.pipe_top__DOT__funct3_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_pipe_top->varInsert("imm_EX", &(TOP.pipe_top__DOT__imm_EX), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("imm_ID", &(TOP.pipe_top__DOT__imm_ID), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("instr_ID", &(TOP.pipe_top__DOT__instr_ID), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("instr_IF", &(TOP.pipe_top__DOT__instr_IF), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("jalr_EX", &(TOP.pipe_top__DOT__jalr_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("jalr_ID", &(TOP.pipe_top__DOT__jalr_ID), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("jump_EX", &(TOP.pipe_top__DOT__jump_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("jump_ID", &(TOP.pipe_top__DOT__jump_ID), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("jump_MEM", &(TOP.pipe_top__DOT__jump_MEM), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("jump_target_EX", &(TOP.pipe_top__DOT__jump_target_EX), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("jump_target_MEM", &(TOP.pipe_top__DOT__jump_target_MEM), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("lui_EX", &(TOP.pipe_top__DOT__lui_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("lui_ID", &(TOP.pipe_top__DOT__lui_ID), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("mem_read_EX", &(TOP.pipe_top__DOT__mem_read_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("mem_read_ID", &(TOP.pipe_top__DOT__mem_read_ID), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("mem_read_MEM", &(TOP.pipe_top__DOT__mem_read_MEM), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("mem_read_data", &(TOP.pipe_top__DOT__mem_read_data), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("mem_read_data_WB", &(TOP.pipe_top__DOT__mem_read_data_WB), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("mem_write_EX", &(TOP.pipe_top__DOT__mem_write_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("mem_write_ID", &(TOP.pipe_top__DOT__mem_write_ID), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("mem_write_MEM", &(TOP.pipe_top__DOT__mem_write_MEM), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("pc_EX", &(TOP.pipe_top__DOT__pc_EX), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("pc_ID", &(TOP.pipe_top__DOT__pc_ID), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("pc_IF", &(TOP.pipe_top__DOT__pc_IF), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("pc_plus4_MEM", &(TOP.pipe_top__DOT__pc_plus4_MEM), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("pc_plus4_WB", &(TOP.pipe_top__DOT__pc_plus4_WB), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("rd_EX", &(TOP.pipe_top__DOT__rd_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top->varInsert("rd_ID", &(TOP.pipe_top__DOT__rd_ID), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top->varInsert("rd_MEM", &(TOP.pipe_top__DOT__rd_MEM), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top->varInsert("rd_WB", &(TOP.pipe_top__DOT__rd_WB), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top->varInsert("reg_write_EX", &(TOP.pipe_top__DOT__reg_write_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("reg_write_ID", &(TOP.pipe_top__DOT__reg_write_ID), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("reg_write_MEM", &(TOP.pipe_top__DOT__reg_write_MEM), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("reg_write_WB", &(TOP.pipe_top__DOT__reg_write_WB), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("rs1_EX", &(TOP.pipe_top__DOT__rs1_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top->varInsert("rs1_ID", &(TOP.pipe_top__DOT__rs1_ID), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top->varInsert("rs1_data_EX", &(TOP.pipe_top__DOT__rs1_data_EX), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("rs1_data_ID", &(TOP.pipe_top__DOT__rs1_data_ID), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("rs2_EX", &(TOP.pipe_top__DOT__rs2_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top->varInsert("rs2_ID", &(TOP.pipe_top__DOT__rs2_ID), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top->varInsert("rs2_data_EX", &(TOP.pipe_top__DOT__rs2_data_EX), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("rs2_data_ID", &(TOP.pipe_top__DOT__rs2_data_ID), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("rs2_data_MEM", &(TOP.pipe_top__DOT__rs2_data_MEM), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top->varInsert("rst", &(TOP.pipe_top__DOT__rst), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top->varInsert("wb_sel_EX", &(TOP.pipe_top__DOT__wb_sel_EX), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_pipe_top->varInsert("wb_sel_ID", &(TOP.pipe_top__DOT__wb_sel_ID), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_pipe_top->varInsert("wb_sel_MEM", &(TOP.pipe_top__DOT__wb_sel_MEM), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_pipe_top->varInsert("wb_sel_WB", &(TOP.pipe_top__DOT__wb_sel_WB), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_pipe_top->varInsert("writeback_data", &(TOP.pipe_top__DOT__writeback_data), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__alu_inst->varInsert("a", &(TOP.pipe_top__DOT__alu_inst__DOT__a), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__alu_inst->varInsert("b", &(TOP.pipe_top__DOT__alu_inst__DOT__b), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__alu_inst->varInsert("op", &(TOP.pipe_top__DOT__alu_inst__DOT__op), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_pipe_top__alu_inst->varInsert("result", &(TOP.pipe_top__DOT__alu_inst__DOT__result), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__alu_inst->varInsert("zero", &(TOP.pipe_top__DOT__alu_inst__DOT__zero), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__decoder_inst->varInsert("OP_AUIPC", const_cast<void*>(static_cast<const void*>(&(TOP.pipe_top__DOT__decoder_inst__DOT__OP_AUIPC))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("OP_BRANCH", const_cast<void*>(static_cast<const void*>(&(TOP.pipe_top__DOT__decoder_inst__DOT__OP_BRANCH))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("OP_IMM", const_cast<void*>(static_cast<const void*>(&(TOP.pipe_top__DOT__decoder_inst__DOT__OP_IMM))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("OP_JAL", const_cast<void*>(static_cast<const void*>(&(TOP.pipe_top__DOT__decoder_inst__DOT__OP_JAL))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("OP_JALR", const_cast<void*>(static_cast<const void*>(&(TOP.pipe_top__DOT__decoder_inst__DOT__OP_JALR))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("OP_LOAD", const_cast<void*>(static_cast<const void*>(&(TOP.pipe_top__DOT__decoder_inst__DOT__OP_LOAD))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("OP_LUI", const_cast<void*>(static_cast<const void*>(&(TOP.pipe_top__DOT__decoder_inst__DOT__OP_LUI))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("OP_REG", const_cast<void*>(static_cast<const void*>(&(TOP.pipe_top__DOT__decoder_inst__DOT__OP_REG))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("OP_STORE", const_cast<void*>(static_cast<const void*>(&(TOP.pipe_top__DOT__decoder_inst__DOT__OP_STORE))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("alu_op", &(TOP.pipe_top__DOT__decoder_inst__DOT__alu_op), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("alu_src", &(TOP.pipe_top__DOT__decoder_inst__DOT__alu_src), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__decoder_inst->varInsert("auipc", &(TOP.pipe_top__DOT__decoder_inst__DOT__auipc), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__decoder_inst->varInsert("branch", &(TOP.pipe_top__DOT__decoder_inst__DOT__branch), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__decoder_inst->varInsert("funct3", &(TOP.pipe_top__DOT__decoder_inst__DOT__funct3), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("funct7", &(TOP.pipe_top__DOT__decoder_inst__DOT__funct7), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("imm", &(TOP.pipe_top__DOT__decoder_inst__DOT__imm), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("imm_b", &(TOP.pipe_top__DOT__decoder_inst__DOT__imm_b), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("imm_i", &(TOP.pipe_top__DOT__decoder_inst__DOT__imm_i), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("imm_j", &(TOP.pipe_top__DOT__decoder_inst__DOT__imm_j), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("imm_s", &(TOP.pipe_top__DOT__decoder_inst__DOT__imm_s), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("imm_u", &(TOP.pipe_top__DOT__decoder_inst__DOT__imm_u), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("instr", &(TOP.pipe_top__DOT__decoder_inst__DOT__instr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("jalr", &(TOP.pipe_top__DOT__decoder_inst__DOT__jalr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__decoder_inst->varInsert("jump", &(TOP.pipe_top__DOT__decoder_inst__DOT__jump), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__decoder_inst->varInsert("lui", &(TOP.pipe_top__DOT__decoder_inst__DOT__lui), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__decoder_inst->varInsert("mem_read", &(TOP.pipe_top__DOT__decoder_inst__DOT__mem_read), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__decoder_inst->varInsert("mem_write", &(TOP.pipe_top__DOT__decoder_inst__DOT__mem_write), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__decoder_inst->varInsert("opcode", &(TOP.pipe_top__DOT__decoder_inst__DOT__opcode), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,6,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("rd", &(TOP.pipe_top__DOT__decoder_inst__DOT__rd), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("reg_write", &(TOP.pipe_top__DOT__decoder_inst__DOT__reg_write), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__decoder_inst->varInsert("rs1", &(TOP.pipe_top__DOT__decoder_inst__DOT__rs1), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("rs2", &(TOP.pipe_top__DOT__decoder_inst__DOT__rs2), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__decoder_inst->varInsert("wb_sel", &(TOP.pipe_top__DOT__decoder_inst__DOT__wb_sel), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_pipe_top__dmem_inst->varInsert("addr", &(TOP.pipe_top__DOT__dmem_inst__DOT__addr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__dmem_inst->varInsert("clk", &(TOP.pipe_top__DOT__dmem_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__dmem_inst->varInsert("mem", &(TOP.pipe_top__DOT__dmem_inst__DOT__mem), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,255 ,31,0);
    __Vscopep_pipe_top__dmem_inst->varInsert("rd", &(TOP.pipe_top__DOT__dmem_inst__DOT__rd), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__dmem_inst->varInsert("wd", &(TOP.pipe_top__DOT__dmem_inst__DOT__wd), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__dmem_inst->varInsert("we", &(TOP.pipe_top__DOT__dmem_inst__DOT__we), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("alu_result_in", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__alu_result_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("alu_result_out", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__alu_result_out), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("alu_zero_in", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__alu_zero_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("alu_zero_out", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__alu_zero_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("branch_taken_in", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__branch_taken_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("branch_taken_out", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__branch_taken_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("branch_target_in", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__branch_target_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("branch_target_out", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__branch_target_out), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("clk", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("jump_in", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__jump_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("jump_out", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__jump_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("jump_target_in", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__jump_target_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("jump_target_out", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__jump_target_out), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("mem_read_in", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__mem_read_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("mem_read_out", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__mem_read_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("mem_write_in", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__mem_write_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("mem_write_out", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__mem_write_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("pc_plus4_in", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__pc_plus4_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("pc_plus4_out", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__pc_plus4_out), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("rd_in", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__rd_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("rd_out", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__rd_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("reg_write_in", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__reg_write_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("reg_write_out", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__reg_write_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("rs2_data_in", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__rs2_data_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("rs2_data_out", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__rs2_data_out), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("rst", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__rst), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("wb_sel_in", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__wb_sel_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_pipe_top__ex_mem_inst->varInsert("wb_sel_out", &(TOP.pipe_top__DOT__ex_mem_inst__DOT__wb_sel_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_pipe_top__fetch_inst->varInsert("branch_taken", &(TOP.pipe_top__DOT__fetch_inst__DOT__branch_taken), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__fetch_inst->varInsert("branch_target", &(TOP.pipe_top__DOT__fetch_inst__DOT__branch_target), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__fetch_inst->varInsert("clk", &(TOP.pipe_top__DOT__fetch_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__fetch_inst->varInsert("instr", &(TOP.pipe_top__DOT__fetch_inst__DOT__instr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__fetch_inst->varInsert("jump", &(TOP.pipe_top__DOT__fetch_inst__DOT__jump), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__fetch_inst->varInsert("jump_target", &(TOP.pipe_top__DOT__fetch_inst__DOT__jump_target), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__fetch_inst->varInsert("pc", &(TOP.pipe_top__DOT__fetch_inst__DOT__pc), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__fetch_inst->varInsert("pc_reg", &(TOP.pipe_top__DOT__fetch_inst__DOT__pc_reg), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__fetch_inst->varInsert("rst", &(TOP.pipe_top__DOT__fetch_inst__DOT__rst), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__fetch_inst__u_imem->varInsert("addr", &(TOP.pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__addr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__fetch_inst__u_imem->varInsert("instr", &(TOP.pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__instr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__fetch_inst__u_imem->varInsert("mem", &(TOP.pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__mem), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,255 ,31,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("alu_op_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__alu_op_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("alu_op_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__alu_op_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("alu_src_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__alu_src_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("alu_src_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__alu_src_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("auipc_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__auipc_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("auipc_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__auipc_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("branch_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__branch_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("branch_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__branch_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("clk", &(TOP.pipe_top__DOT__id_ex_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("funct3_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__funct3_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("funct3_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__funct3_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("imm_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__imm_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("imm_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__imm_out), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("jalr_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__jalr_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("jalr_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__jalr_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("jump_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__jump_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("jump_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__jump_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("lui_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__lui_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("lui_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__lui_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("mem_read_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__mem_read_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("mem_read_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__mem_read_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("mem_write_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__mem_write_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("mem_write_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__mem_write_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("pc_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__pc_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("pc_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__pc_out), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("rd_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__rd_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("rd_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__rd_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("reg_write_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__reg_write_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("reg_write_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__reg_write_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("rs1_data_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__rs1_data_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("rs1_data_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__rs1_data_out), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("rs1_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__rs1_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("rs1_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__rs1_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("rs2_data_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__rs2_data_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("rs2_data_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__rs2_data_out), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("rs2_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__rs2_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("rs2_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__rs2_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("rst", &(TOP.pipe_top__DOT__id_ex_inst__DOT__rst), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("wb_sel_in", &(TOP.pipe_top__DOT__id_ex_inst__DOT__wb_sel_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_pipe_top__id_ex_inst->varInsert("wb_sel_out", &(TOP.pipe_top__DOT__id_ex_inst__DOT__wb_sel_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_pipe_top__if_id_inst->varInsert("clk", &(TOP.pipe_top__DOT__if_id_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__if_id_inst->varInsert("instr_in", &(TOP.pipe_top__DOT__if_id_inst__DOT__instr_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__if_id_inst->varInsert("instr_out", &(TOP.pipe_top__DOT__if_id_inst__DOT__instr_out), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__if_id_inst->varInsert("pc_in", &(TOP.pipe_top__DOT__if_id_inst__DOT__pc_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__if_id_inst->varInsert("pc_out", &(TOP.pipe_top__DOT__if_id_inst__DOT__pc_out), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__if_id_inst->varInsert("rst", &(TOP.pipe_top__DOT__if_id_inst__DOT__rst), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__mem_wb_inst->varInsert("alu_result_in", &(TOP.pipe_top__DOT__mem_wb_inst__DOT__alu_result_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__mem_wb_inst->varInsert("alu_result_out", &(TOP.pipe_top__DOT__mem_wb_inst__DOT__alu_result_out), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__mem_wb_inst->varInsert("clk", &(TOP.pipe_top__DOT__mem_wb_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__mem_wb_inst->varInsert("mem_read_data_in", &(TOP.pipe_top__DOT__mem_wb_inst__DOT__mem_read_data_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__mem_wb_inst->varInsert("mem_read_data_out", &(TOP.pipe_top__DOT__mem_wb_inst__DOT__mem_read_data_out), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__mem_wb_inst->varInsert("pc_plus4_in", &(TOP.pipe_top__DOT__mem_wb_inst__DOT__pc_plus4_in), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__mem_wb_inst->varInsert("pc_plus4_out", &(TOP.pipe_top__DOT__mem_wb_inst__DOT__pc_plus4_out), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__mem_wb_inst->varInsert("rd_in", &(TOP.pipe_top__DOT__mem_wb_inst__DOT__rd_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__mem_wb_inst->varInsert("rd_out", &(TOP.pipe_top__DOT__mem_wb_inst__DOT__rd_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__mem_wb_inst->varInsert("reg_write_in", &(TOP.pipe_top__DOT__mem_wb_inst__DOT__reg_write_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__mem_wb_inst->varInsert("reg_write_out", &(TOP.pipe_top__DOT__mem_wb_inst__DOT__reg_write_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__mem_wb_inst->varInsert("rst", &(TOP.pipe_top__DOT__mem_wb_inst__DOT__rst), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__mem_wb_inst->varInsert("wb_sel_in", &(TOP.pipe_top__DOT__mem_wb_inst__DOT__wb_sel_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_pipe_top__mem_wb_inst->varInsert("wb_sel_out", &(TOP.pipe_top__DOT__mem_wb_inst__DOT__wb_sel_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_pipe_top__regfile_inst->varInsert("clk", &(TOP.pipe_top__DOT__regfile_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_pipe_top__regfile_inst->varInsert("i", &(TOP.pipe_top__DOT__regfile_inst__DOT__i), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_pipe_top__regfile_inst->varInsert("rd", &(TOP.pipe_top__DOT__regfile_inst__DOT__rd), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__regfile_inst->varInsert("rdata1", &(TOP.pipe_top__DOT__regfile_inst__DOT__rdata1), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__regfile_inst->varInsert("rdata2", &(TOP.pipe_top__DOT__regfile_inst__DOT__rdata2), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__regfile_inst->varInsert("regs", &(TOP.pipe_top__DOT__regfile_inst__DOT__regs), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,31 ,31,0);
    __Vscopep_pipe_top__regfile_inst->varInsert("rs1", &(TOP.pipe_top__DOT__regfile_inst__DOT__rs1), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__regfile_inst->varInsert("rs2", &(TOP.pipe_top__DOT__regfile_inst__DOT__rs2), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_pipe_top__regfile_inst->varInsert("wdata", &(TOP.pipe_top__DOT__regfile_inst__DOT__wdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_pipe_top__regfile_inst->varInsert("we", &(TOP.pipe_top__DOT__regfile_inst__DOT__we), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_pipe_top);
    __Vhier.remove(__Vscopep_pipe_top, __Vscopep_pipe_top__alu_inst);
    __Vhier.remove(__Vscopep_pipe_top, __Vscopep_pipe_top__decoder_inst);
    __Vhier.remove(__Vscopep_pipe_top, __Vscopep_pipe_top__dmem_inst);
    __Vhier.remove(__Vscopep_pipe_top, __Vscopep_pipe_top__ex_mem_inst);
    __Vhier.remove(__Vscopep_pipe_top, __Vscopep_pipe_top__fetch_inst);
    __Vhier.remove(__Vscopep_pipe_top, __Vscopep_pipe_top__id_ex_inst);
    __Vhier.remove(__Vscopep_pipe_top, __Vscopep_pipe_top__if_id_inst);
    __Vhier.remove(__Vscopep_pipe_top, __Vscopep_pipe_top__mem_wb_inst);
    __Vhier.remove(__Vscopep_pipe_top, __Vscopep_pipe_top__regfile_inst);
    __Vhier.remove(__Vscopep_pipe_top__fetch_inst, __Vscopep_pipe_top__fetch_inst__u_imem);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_pipe_top, __Vscopep_pipe_top = nullptr);
    VL_DO_CLEAR(delete __Vscopep_pipe_top__alu_inst, __Vscopep_pipe_top__alu_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_pipe_top__decoder_inst, __Vscopep_pipe_top__decoder_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_pipe_top__dmem_inst, __Vscopep_pipe_top__dmem_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_pipe_top__ex_mem_inst, __Vscopep_pipe_top__ex_mem_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_pipe_top__fetch_inst, __Vscopep_pipe_top__fetch_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_pipe_top__fetch_inst__u_imem, __Vscopep_pipe_top__fetch_inst__u_imem = nullptr);
    VL_DO_CLEAR(delete __Vscopep_pipe_top__id_ex_inst, __Vscopep_pipe_top__id_ex_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_pipe_top__if_id_inst, __Vscopep_pipe_top__if_id_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_pipe_top__mem_wb_inst, __Vscopep_pipe_top__mem_wb_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_pipe_top__regfile_inst, __Vscopep_pipe_top__regfile_inst = nullptr);
    // Tear down sub module instances
}
