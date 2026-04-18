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
        CData/*0:0*/ top__DOT__clk;
        CData/*0:0*/ top__DOT__rst;
        CData/*4:0*/ top__DOT__rs1;
        CData/*4:0*/ top__DOT__rs2;
        CData/*4:0*/ top__DOT__rd;
        CData/*3:0*/ top__DOT__alu_op;
        CData/*0:0*/ top__DOT__alu_src;
        CData/*0:0*/ top__DOT__mem_read;
        CData/*0:0*/ top__DOT__mem_write;
        CData/*0:0*/ top__DOT__reg_write;
        CData/*0:0*/ top__DOT__branch;
        CData/*0:0*/ top__DOT__jump;
        CData/*0:0*/ top__DOT__jalr;
        CData/*1:0*/ top__DOT__wb_sel;
        CData/*0:0*/ top__DOT__alu_zero;
        CData/*0:0*/ top__DOT__branch_taken;
        CData/*0:0*/ top__DOT__fetch_inst__DOT__clk;
        CData/*0:0*/ top__DOT__fetch_inst__DOT__rst;
        CData/*0:0*/ top__DOT__fetch_inst__DOT__branch_taken;
        CData/*0:0*/ top__DOT__fetch_inst__DOT__jump;
        CData/*4:0*/ top__DOT__decoder_inst__DOT__rs1;
        CData/*4:0*/ top__DOT__decoder_inst__DOT__rs2;
        CData/*4:0*/ top__DOT__decoder_inst__DOT__rd;
        CData/*3:0*/ top__DOT__decoder_inst__DOT__alu_op;
        CData/*0:0*/ top__DOT__decoder_inst__DOT__alu_src;
        CData/*0:0*/ top__DOT__decoder_inst__DOT__mem_read;
        CData/*0:0*/ top__DOT__decoder_inst__DOT__mem_write;
        CData/*0:0*/ top__DOT__decoder_inst__DOT__reg_write;
        CData/*1:0*/ top__DOT__decoder_inst__DOT__wb_sel;
        CData/*0:0*/ top__DOT__decoder_inst__DOT__branch;
        CData/*0:0*/ top__DOT__decoder_inst__DOT__jump;
        CData/*0:0*/ top__DOT__decoder_inst__DOT__jalr;
        CData/*6:0*/ top__DOT__decoder_inst__DOT__opcode;
        CData/*2:0*/ top__DOT__decoder_inst__DOT__funct3;
        CData/*6:0*/ top__DOT__decoder_inst__DOT__funct7;
        CData/*0:0*/ top__DOT__regfile_inst__DOT__clk;
        CData/*0:0*/ top__DOT__regfile_inst__DOT__we;
        CData/*4:0*/ top__DOT__regfile_inst__DOT__rs1;
        CData/*4:0*/ top__DOT__regfile_inst__DOT__rs2;
        CData/*4:0*/ top__DOT__regfile_inst__DOT__rd;
        CData/*3:0*/ top__DOT__alu_inst__DOT__op;
        CData/*0:0*/ top__DOT__alu_inst__DOT__zero;
        CData/*0:0*/ top__DOT__dmem_inst__DOT__clk;
        CData/*0:0*/ top__DOT__dmem_inst__DOT__we;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__fetch_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__fetch_inst__DOT__rst__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__regfile_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__dmem_inst__DOT__clk__0;
        IData/*31:0*/ top__DOT__pc;
        IData/*31:0*/ top__DOT__instr;
        IData/*31:0*/ top__DOT__imm;
        IData/*31:0*/ top__DOT__rs1_data;
        IData/*31:0*/ top__DOT__rs2_data;
        IData/*31:0*/ top__DOT__alu_result;
        IData/*31:0*/ top__DOT__mem_read_data;
        IData/*31:0*/ top__DOT__alu_b_in;
        IData/*31:0*/ top__DOT__writeback_data;
        IData/*31:0*/ top__DOT__branch_target;
        IData/*31:0*/ top__DOT__jump_target;
        IData/*31:0*/ top__DOT__fetch_inst__DOT__branch_target;
    };
    struct {
        IData/*31:0*/ top__DOT__fetch_inst__DOT__jump_target;
        IData/*31:0*/ top__DOT__fetch_inst__DOT__pc;
        IData/*31:0*/ top__DOT__fetch_inst__DOT__instr;
        IData/*31:0*/ top__DOT__fetch_inst__DOT__pc_reg;
        IData/*31:0*/ top__DOT__fetch_inst__DOT__u_imem__DOT__addr;
        IData/*31:0*/ top__DOT__fetch_inst__DOT__u_imem__DOT__instr;
        IData/*31:0*/ top__DOT__decoder_inst__DOT__instr;
        IData/*31:0*/ top__DOT__decoder_inst__DOT__imm;
        IData/*31:0*/ top__DOT__decoder_inst__DOT__imm_i;
        IData/*31:0*/ top__DOT__decoder_inst__DOT__imm_s;
        IData/*31:0*/ top__DOT__decoder_inst__DOT__imm_b;
        IData/*31:0*/ top__DOT__decoder_inst__DOT__imm_u;
        IData/*31:0*/ top__DOT__decoder_inst__DOT__imm_j;
        IData/*31:0*/ top__DOT__regfile_inst__DOT__wdata;
        IData/*31:0*/ top__DOT__regfile_inst__DOT__rdata1;
        IData/*31:0*/ top__DOT__regfile_inst__DOT__rdata2;
        IData/*31:0*/ top__DOT__regfile_inst__DOT__i;
        IData/*31:0*/ top__DOT__alu_inst__DOT__a;
        IData/*31:0*/ top__DOT__alu_inst__DOT__b;
        IData/*31:0*/ top__DOT__alu_inst__DOT__result;
        IData/*31:0*/ top__DOT__dmem_inst__DOT__addr;
        IData/*31:0*/ top__DOT__dmem_inst__DOT__wd;
        IData/*31:0*/ top__DOT__dmem_inst__DOT__rd;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 256> top__DOT__fetch_inst__DOT__u_imem__DOT__mem;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__regfile_inst__DOT__regs;
        VlUnpacked<IData/*31:0*/, 256> top__DOT__dmem_inst__DOT__mem;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*6:0*/ top__DOT__decoder_inst__DOT__OP_LOAD = 3U;
    static constexpr CData/*6:0*/ top__DOT__decoder_inst__DOT__OP_STORE = 0x23U;
    static constexpr CData/*6:0*/ top__DOT__decoder_inst__DOT__OP_IMM = 0x13U;
    static constexpr CData/*6:0*/ top__DOT__decoder_inst__DOT__OP_REG = 0x33U;
    static constexpr CData/*6:0*/ top__DOT__decoder_inst__DOT__OP_BRANCH = 0x63U;
    static constexpr CData/*6:0*/ top__DOT__decoder_inst__DOT__OP_LUI = 0x37U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
