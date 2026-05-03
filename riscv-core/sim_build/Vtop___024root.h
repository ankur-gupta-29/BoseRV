// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        CData/*0:0*/ pipe_top__DOT__clk;
        CData/*0:0*/ pipe_top__DOT__rst;
        CData/*4:0*/ pipe_top__DOT__rs1_ID;
        CData/*4:0*/ pipe_top__DOT__rs2_ID;
        CData/*4:0*/ pipe_top__DOT__rd_ID;
        CData/*4:0*/ pipe_top__DOT__rs1_EX;
        CData/*4:0*/ pipe_top__DOT__rs2_EX;
        CData/*4:0*/ pipe_top__DOT__rd_EX;
        CData/*4:0*/ pipe_top__DOT__rd_MEM;
        CData/*4:0*/ pipe_top__DOT__rd_WB;
        CData/*3:0*/ pipe_top__DOT__alu_op_ID;
        CData/*3:0*/ pipe_top__DOT__alu_op_EX;
        CData/*0:0*/ pipe_top__DOT__alu_src_ID;
        CData/*0:0*/ pipe_top__DOT__alu_src_EX;
        CData/*0:0*/ pipe_top__DOT__mem_read_ID;
        CData/*0:0*/ pipe_top__DOT__mem_read_EX;
        CData/*0:0*/ pipe_top__DOT__mem_read_MEM;
        CData/*0:0*/ pipe_top__DOT__mem_write_ID;
        CData/*0:0*/ pipe_top__DOT__mem_write_EX;
        CData/*0:0*/ pipe_top__DOT__mem_write_MEM;
        CData/*0:0*/ pipe_top__DOT__reg_write_ID;
        CData/*0:0*/ pipe_top__DOT__reg_write_EX;
        CData/*0:0*/ pipe_top__DOT__reg_write_MEM;
        CData/*0:0*/ pipe_top__DOT__reg_write_WB;
        CData/*1:0*/ pipe_top__DOT__wb_sel_ID;
        CData/*1:0*/ pipe_top__DOT__wb_sel_EX;
        CData/*1:0*/ pipe_top__DOT__wb_sel_MEM;
        CData/*1:0*/ pipe_top__DOT__wb_sel_WB;
        CData/*0:0*/ pipe_top__DOT__branch_ID;
        CData/*0:0*/ pipe_top__DOT__branch_EX;
        CData/*0:0*/ pipe_top__DOT__jump_ID;
        CData/*0:0*/ pipe_top__DOT__jump_EX;
        CData/*0:0*/ pipe_top__DOT__jump_MEM;
        CData/*0:0*/ pipe_top__DOT__jalr_ID;
        CData/*0:0*/ pipe_top__DOT__jalr_EX;
        CData/*0:0*/ pipe_top__DOT__auipc_ID;
        CData/*0:0*/ pipe_top__DOT__auipc_EX;
        CData/*0:0*/ pipe_top__DOT__lui_ID;
        CData/*0:0*/ pipe_top__DOT__lui_EX;
        CData/*0:0*/ pipe_top__DOT__alu_zero_EX;
        CData/*0:0*/ pipe_top__DOT__alu_zero_MEM;
        CData/*0:0*/ pipe_top__DOT__branch_taken_EX;
        CData/*0:0*/ pipe_top__DOT__branch_taken_MEM;
        CData/*2:0*/ pipe_top__DOT__funct3_EX;
        CData/*1:0*/ pipe_top__DOT__forward_A;
        CData/*1:0*/ pipe_top__DOT__forward_B;
        CData/*0:0*/ pipe_top__DOT__fetch_inst__DOT__clk;
        CData/*0:0*/ pipe_top__DOT__fetch_inst__DOT__rst;
        CData/*0:0*/ pipe_top__DOT__fetch_inst__DOT__branch_taken;
        CData/*0:0*/ pipe_top__DOT__fetch_inst__DOT__jump;
        CData/*0:0*/ pipe_top__DOT__if_id_inst__DOT__clk;
        CData/*0:0*/ pipe_top__DOT__if_id_inst__DOT__rst;
        CData/*4:0*/ pipe_top__DOT__decoder_inst__DOT__rs1;
        CData/*4:0*/ pipe_top__DOT__decoder_inst__DOT__rs2;
        CData/*4:0*/ pipe_top__DOT__decoder_inst__DOT__rd;
        CData/*3:0*/ pipe_top__DOT__decoder_inst__DOT__alu_op;
        CData/*0:0*/ pipe_top__DOT__decoder_inst__DOT__alu_src;
        CData/*0:0*/ pipe_top__DOT__decoder_inst__DOT__mem_read;
        CData/*0:0*/ pipe_top__DOT__decoder_inst__DOT__mem_write;
        CData/*0:0*/ pipe_top__DOT__decoder_inst__DOT__reg_write;
        CData/*1:0*/ pipe_top__DOT__decoder_inst__DOT__wb_sel;
        CData/*0:0*/ pipe_top__DOT__decoder_inst__DOT__branch;
    };
    struct {
        CData/*0:0*/ pipe_top__DOT__decoder_inst__DOT__jump;
        CData/*0:0*/ pipe_top__DOT__decoder_inst__DOT__jalr;
        CData/*0:0*/ pipe_top__DOT__decoder_inst__DOT__auipc;
        CData/*0:0*/ pipe_top__DOT__decoder_inst__DOT__lui;
        CData/*6:0*/ pipe_top__DOT__decoder_inst__DOT__opcode;
        CData/*2:0*/ pipe_top__DOT__decoder_inst__DOT__funct3;
        CData/*6:0*/ pipe_top__DOT__decoder_inst__DOT__funct7;
        CData/*0:0*/ pipe_top__DOT__regfile_inst__DOT__clk;
        CData/*0:0*/ pipe_top__DOT__regfile_inst__DOT__we;
        CData/*4:0*/ pipe_top__DOT__regfile_inst__DOT__rs1;
        CData/*4:0*/ pipe_top__DOT__regfile_inst__DOT__rs2;
        CData/*4:0*/ pipe_top__DOT__regfile_inst__DOT__rd;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__clk;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__rst;
        CData/*4:0*/ pipe_top__DOT__id_ex_inst__DOT__rs1_in;
        CData/*4:0*/ pipe_top__DOT__id_ex_inst__DOT__rs2_in;
        CData/*4:0*/ pipe_top__DOT__id_ex_inst__DOT__rd_in;
        CData/*3:0*/ pipe_top__DOT__id_ex_inst__DOT__alu_op_in;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__alu_src_in;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__mem_read_in;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__mem_write_in;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__reg_write_in;
        CData/*1:0*/ pipe_top__DOT__id_ex_inst__DOT__wb_sel_in;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__branch_in;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__jump_in;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__jalr_in;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__auipc_in;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__lui_in;
        CData/*2:0*/ pipe_top__DOT__id_ex_inst__DOT__funct3_in;
        CData/*4:0*/ pipe_top__DOT__id_ex_inst__DOT__rs1_out;
        CData/*4:0*/ pipe_top__DOT__id_ex_inst__DOT__rs2_out;
        CData/*4:0*/ pipe_top__DOT__id_ex_inst__DOT__rd_out;
        CData/*3:0*/ pipe_top__DOT__id_ex_inst__DOT__alu_op_out;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__alu_src_out;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__mem_read_out;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__mem_write_out;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__reg_write_out;
        CData/*1:0*/ pipe_top__DOT__id_ex_inst__DOT__wb_sel_out;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__branch_out;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__jump_out;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__jalr_out;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__auipc_out;
        CData/*2:0*/ pipe_top__DOT__id_ex_inst__DOT__funct3_out;
        CData/*0:0*/ pipe_top__DOT__id_ex_inst__DOT__lui_out;
        CData/*3:0*/ pipe_top__DOT__alu_inst__DOT__op;
        CData/*0:0*/ pipe_top__DOT__alu_inst__DOT__zero;
        CData/*0:0*/ pipe_top__DOT__ex_mem_inst__DOT__clk;
        CData/*0:0*/ pipe_top__DOT__ex_mem_inst__DOT__rst;
        CData/*0:0*/ pipe_top__DOT__ex_mem_inst__DOT__branch_taken_in;
        CData/*0:0*/ pipe_top__DOT__ex_mem_inst__DOT__alu_zero_in;
        CData/*4:0*/ pipe_top__DOT__ex_mem_inst__DOT__rd_in;
        CData/*0:0*/ pipe_top__DOT__ex_mem_inst__DOT__mem_read_in;
        CData/*0:0*/ pipe_top__DOT__ex_mem_inst__DOT__mem_write_in;
        CData/*0:0*/ pipe_top__DOT__ex_mem_inst__DOT__reg_write_in;
        CData/*1:0*/ pipe_top__DOT__ex_mem_inst__DOT__wb_sel_in;
        CData/*0:0*/ pipe_top__DOT__ex_mem_inst__DOT__jump_in;
        CData/*0:0*/ pipe_top__DOT__ex_mem_inst__DOT__branch_taken_out;
        CData/*0:0*/ pipe_top__DOT__ex_mem_inst__DOT__alu_zero_out;
        CData/*4:0*/ pipe_top__DOT__ex_mem_inst__DOT__rd_out;
        CData/*0:0*/ pipe_top__DOT__ex_mem_inst__DOT__mem_read_out;
        CData/*0:0*/ pipe_top__DOT__ex_mem_inst__DOT__mem_write_out;
        CData/*0:0*/ pipe_top__DOT__ex_mem_inst__DOT__reg_write_out;
        CData/*1:0*/ pipe_top__DOT__ex_mem_inst__DOT__wb_sel_out;
        CData/*0:0*/ pipe_top__DOT__ex_mem_inst__DOT__jump_out;
    };
    struct {
        CData/*0:0*/ pipe_top__DOT__dmem_inst__DOT__clk;
        CData/*0:0*/ pipe_top__DOT__dmem_inst__DOT__we;
        CData/*0:0*/ pipe_top__DOT__mem_wb_inst__DOT__clk;
        CData/*0:0*/ pipe_top__DOT__mem_wb_inst__DOT__rst;
        CData/*4:0*/ pipe_top__DOT__mem_wb_inst__DOT__rd_in;
        CData/*0:0*/ pipe_top__DOT__mem_wb_inst__DOT__reg_write_in;
        CData/*1:0*/ pipe_top__DOT__mem_wb_inst__DOT__wb_sel_in;
        CData/*4:0*/ pipe_top__DOT__mem_wb_inst__DOT__rd_out;
        CData/*0:0*/ pipe_top__DOT__mem_wb_inst__DOT__reg_write_out;
        CData/*1:0*/ pipe_top__DOT__mem_wb_inst__DOT__wb_sel_out;
        CData/*4:0*/ pipe_top__DOT__forwarding_inst__DOT__rs1_EX;
        CData/*4:0*/ pipe_top__DOT__forwarding_inst__DOT__rs2_EX;
        CData/*4:0*/ pipe_top__DOT__forwarding_inst__DOT__rd_MEM;
        CData/*0:0*/ pipe_top__DOT__forwarding_inst__DOT__reg_write_MEM;
        CData/*4:0*/ pipe_top__DOT__forwarding_inst__DOT__rd_WB;
        CData/*0:0*/ pipe_top__DOT__forwarding_inst__DOT__reg_write_WB;
        CData/*1:0*/ pipe_top__DOT__forwarding_inst__DOT__forward_A;
        CData/*1:0*/ pipe_top__DOT__forwarding_inst__DOT__forward_B;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__pipe_top__DOT__fetch_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__pipe_top__DOT__fetch_inst__DOT__rst__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__pipe_top__DOT__if_id_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__pipe_top__DOT__if_id_inst__DOT__rst__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__pipe_top__DOT__regfile_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__pipe_top__DOT__id_ex_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__pipe_top__DOT__id_ex_inst__DOT__rst__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__pipe_top__DOT__ex_mem_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__pipe_top__DOT__ex_mem_inst__DOT__rst__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__pipe_top__DOT__dmem_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__pipe_top__DOT__mem_wb_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__pipe_top__DOT__mem_wb_inst__DOT__rst__0;
        IData/*31:0*/ pipe_top__DOT__pc_IF;
        IData/*31:0*/ pipe_top__DOT__pc_ID;
        IData/*31:0*/ pipe_top__DOT__pc_EX;
        IData/*31:0*/ pipe_top__DOT__pc_plus4_MEM;
        IData/*31:0*/ pipe_top__DOT__pc_plus4_WB;
        IData/*31:0*/ pipe_top__DOT__instr_IF;
        IData/*31:0*/ pipe_top__DOT__instr_ID;
        IData/*31:0*/ pipe_top__DOT__imm_ID;
        IData/*31:0*/ pipe_top__DOT__imm_EX;
        IData/*31:0*/ pipe_top__DOT__rs1_data_ID;
        IData/*31:0*/ pipe_top__DOT__rs1_data_EX;
        IData/*31:0*/ pipe_top__DOT__rs2_data_ID;
        IData/*31:0*/ pipe_top__DOT__rs2_data_EX;
        IData/*31:0*/ pipe_top__DOT__rs2_data_MEM;
        IData/*31:0*/ pipe_top__DOT__alu_b_EX;
        IData/*31:0*/ pipe_top__DOT__alu_result_EX;
        IData/*31:0*/ pipe_top__DOT__alu_result_MEM;
        IData/*31:0*/ pipe_top__DOT__alu_result_WB;
        IData/*31:0*/ pipe_top__DOT__mem_read_data;
        IData/*31:0*/ pipe_top__DOT__mem_read_data_WB;
        IData/*31:0*/ pipe_top__DOT__writeback_data;
        IData/*31:0*/ pipe_top__DOT__branch_target_EX;
        IData/*31:0*/ pipe_top__DOT__branch_target_MEM;
        IData/*31:0*/ pipe_top__DOT__jump_target_EX;
        IData/*31:0*/ pipe_top__DOT__jump_target_MEM;
        IData/*31:0*/ pipe_top__DOT__fwd_rs1;
        IData/*31:0*/ pipe_top__DOT__fwd_rs2;
        IData/*31:0*/ pipe_top__DOT__fetch_inst__DOT__branch_target;
        IData/*31:0*/ pipe_top__DOT__fetch_inst__DOT__jump_target;
        IData/*31:0*/ pipe_top__DOT__fetch_inst__DOT__pc;
        IData/*31:0*/ pipe_top__DOT__fetch_inst__DOT__instr;
        IData/*31:0*/ pipe_top__DOT__fetch_inst__DOT__pc_reg;
    };
    struct {
        IData/*31:0*/ pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__addr;
        IData/*31:0*/ pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__instr;
        IData/*31:0*/ pipe_top__DOT__if_id_inst__DOT__pc_in;
        IData/*31:0*/ pipe_top__DOT__if_id_inst__DOT__instr_in;
        IData/*31:0*/ pipe_top__DOT__if_id_inst__DOT__pc_out;
        IData/*31:0*/ pipe_top__DOT__if_id_inst__DOT__instr_out;
        IData/*31:0*/ pipe_top__DOT__decoder_inst__DOT__instr;
        IData/*31:0*/ pipe_top__DOT__decoder_inst__DOT__imm;
        IData/*31:0*/ pipe_top__DOT__decoder_inst__DOT__imm_i;
        IData/*31:0*/ pipe_top__DOT__decoder_inst__DOT__imm_s;
        IData/*31:0*/ pipe_top__DOT__decoder_inst__DOT__imm_b;
        IData/*31:0*/ pipe_top__DOT__decoder_inst__DOT__imm_u;
        IData/*31:0*/ pipe_top__DOT__decoder_inst__DOT__imm_j;
        IData/*31:0*/ pipe_top__DOT__regfile_inst__DOT__wdata;
        IData/*31:0*/ pipe_top__DOT__regfile_inst__DOT__rdata1;
        IData/*31:0*/ pipe_top__DOT__regfile_inst__DOT__rdata2;
        IData/*31:0*/ pipe_top__DOT__regfile_inst__DOT__i;
        IData/*31:0*/ pipe_top__DOT__id_ex_inst__DOT__pc_in;
        IData/*31:0*/ pipe_top__DOT__id_ex_inst__DOT__rs1_data_in;
        IData/*31:0*/ pipe_top__DOT__id_ex_inst__DOT__rs2_data_in;
        IData/*31:0*/ pipe_top__DOT__id_ex_inst__DOT__imm_in;
        IData/*31:0*/ pipe_top__DOT__id_ex_inst__DOT__pc_out;
        IData/*31:0*/ pipe_top__DOT__id_ex_inst__DOT__rs1_data_out;
        IData/*31:0*/ pipe_top__DOT__id_ex_inst__DOT__rs2_data_out;
        IData/*31:0*/ pipe_top__DOT__id_ex_inst__DOT__imm_out;
        IData/*31:0*/ pipe_top__DOT__alu_inst__DOT__a;
        IData/*31:0*/ pipe_top__DOT__alu_inst__DOT__b;
        IData/*31:0*/ pipe_top__DOT__alu_inst__DOT__result;
        IData/*31:0*/ pipe_top__DOT__ex_mem_inst__DOT__alu_result_in;
        IData/*31:0*/ pipe_top__DOT__ex_mem_inst__DOT__rs2_data_in;
        IData/*31:0*/ pipe_top__DOT__ex_mem_inst__DOT__pc_plus4_in;
        IData/*31:0*/ pipe_top__DOT__ex_mem_inst__DOT__branch_target_in;
        IData/*31:0*/ pipe_top__DOT__ex_mem_inst__DOT__jump_target_in;
        IData/*31:0*/ pipe_top__DOT__ex_mem_inst__DOT__alu_result_out;
        IData/*31:0*/ pipe_top__DOT__ex_mem_inst__DOT__rs2_data_out;
        IData/*31:0*/ pipe_top__DOT__ex_mem_inst__DOT__pc_plus4_out;
        IData/*31:0*/ pipe_top__DOT__ex_mem_inst__DOT__branch_target_out;
        IData/*31:0*/ pipe_top__DOT__ex_mem_inst__DOT__jump_target_out;
        IData/*31:0*/ pipe_top__DOT__dmem_inst__DOT__addr;
        IData/*31:0*/ pipe_top__DOT__dmem_inst__DOT__wd;
        IData/*31:0*/ pipe_top__DOT__dmem_inst__DOT__rd;
        IData/*31:0*/ pipe_top__DOT__mem_wb_inst__DOT__alu_result_in;
        IData/*31:0*/ pipe_top__DOT__mem_wb_inst__DOT__mem_read_data_in;
        IData/*31:0*/ pipe_top__DOT__mem_wb_inst__DOT__pc_plus4_in;
        IData/*31:0*/ pipe_top__DOT__mem_wb_inst__DOT__alu_result_out;
        IData/*31:0*/ pipe_top__DOT__mem_wb_inst__DOT__mem_read_data_out;
        IData/*31:0*/ pipe_top__DOT__mem_wb_inst__DOT__pc_plus4_out;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 256> pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__mem;
        VlUnpacked<IData/*31:0*/, 32> pipe_top__DOT__regfile_inst__DOT__regs;
        VlUnpacked<IData/*31:0*/, 256> pipe_top__DOT__dmem_inst__DOT__mem;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*6:0*/ pipe_top__DOT__decoder_inst__DOT__OP_LOAD = 3U;
    static constexpr CData/*6:0*/ pipe_top__DOT__decoder_inst__DOT__OP_STORE = 0x23U;
    static constexpr CData/*6:0*/ pipe_top__DOT__decoder_inst__DOT__OP_IMM = 0x13U;
    static constexpr CData/*6:0*/ pipe_top__DOT__decoder_inst__DOT__OP_REG = 0x33U;
    static constexpr CData/*6:0*/ pipe_top__DOT__decoder_inst__DOT__OP_BRANCH = 0x63U;
    static constexpr CData/*6:0*/ pipe_top__DOT__decoder_inst__DOT__OP_LUI = 0x37U;
    static constexpr CData/*6:0*/ pipe_top__DOT__decoder_inst__DOT__OP_AUIPC = 0x17U;
    static constexpr CData/*6:0*/ pipe_top__DOT__decoder_inst__DOT__OP_JAL = 0x6fU;
    static constexpr CData/*6:0*/ pipe_top__DOT__decoder_inst__DOT__OP_JALR = 0x67U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
