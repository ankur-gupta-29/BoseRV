// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__fetch_inst__DOT__clk__0 
        = vlSelfRef.pipe_top__DOT__fetch_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__fetch_inst__DOT__rst__0 
        = vlSelfRef.pipe_top__DOT__fetch_inst__DOT__rst;
    vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__if_id_inst__DOT__clk__0 
        = vlSelfRef.pipe_top__DOT__if_id_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__if_id_inst__DOT__rst__0 
        = vlSelfRef.pipe_top__DOT__if_id_inst__DOT__rst;
    vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__regfile_inst__DOT__clk__0 
        = vlSelfRef.pipe_top__DOT__regfile_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__id_ex_inst__DOT__clk__0 
        = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__id_ex_inst__DOT__rst__0 
        = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rst;
    vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__ex_mem_inst__DOT__clk__0 
        = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__ex_mem_inst__DOT__rst__0 
        = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rst;
    vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__dmem_inst__DOT__clk__0 
        = vlSelfRef.pipe_top__DOT__dmem_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__mem_wb_inst__DOT__clk__0 
        = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__mem_wb_inst__DOT__rst__0 
        = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__rst;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_READMEM_N(true, 32, 256, 0, "tests/instr_mem.hex"s
                 ,  &(vlSelfRef.pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__mem)
                 , 0, ~0ULL);
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000020U, vlSelfRef.pipe_top__DOT__regfile_inst__DOT__i)) {
        vlSelfRef.pipe_top__DOT__regfile_inst__DOT__regs[(0x0000001fU 
                                                          & vlSelfRef.pipe_top__DOT__regfile_inst__DOT__i)] = 0U;
        vlSelfRef.pipe_top__DOT__regfile_inst__DOT__i 
            = ((IData)(1U) + vlSelfRef.pipe_top__DOT__regfile_inst__DOT__i);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/home/ankur/workspace/BoseRV/riscv-core/src/pipe_top.v", 1, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtop___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge pipe_top.fetch_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge pipe_top.fetch_inst.rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge pipe_top.if_id_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge pipe_top.if_id_inst.rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge pipe_top.regfile_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(posedge pipe_top.id_ex_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @(posedge pipe_top.id_ex_inst.rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @(posedge pipe_top.ex_mem_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 8 is active: @(posedge pipe_top.ex_mem_inst.rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 9 is active: @(posedge pipe_top.dmem_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 10 is active: @(posedge pipe_top.mem_wb_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 11 is active: @(posedge pipe_top.mem_wb_inst.rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->pipe_top__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 529410581898060912ull);
    vlSelf->pipe_top__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8579708979881094436ull);
    vlSelf->pipe_top__DOT__pc_IF = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1034277157316485899ull);
    vlSelf->pipe_top__DOT__pc_ID = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10599663468685104498ull);
    vlSelf->pipe_top__DOT__pc_EX = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4380470185694372889ull);
    vlSelf->pipe_top__DOT__pc_plus4_MEM = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11723061960070491036ull);
    vlSelf->pipe_top__DOT__pc_plus4_WB = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15411906528667106095ull);
    vlSelf->pipe_top__DOT__instr_IF = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10672059338625765225ull);
    vlSelf->pipe_top__DOT__instr_ID = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3068338129791460861ull);
    vlSelf->pipe_top__DOT__rs1_ID = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4041798638689773532ull);
    vlSelf->pipe_top__DOT__rs2_ID = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9981332861424149228ull);
    vlSelf->pipe_top__DOT__rd_ID = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17495988583151528637ull);
    vlSelf->pipe_top__DOT__rs1_EX = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6136845709051705125ull);
    vlSelf->pipe_top__DOT__rs2_EX = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5344091925694754989ull);
    vlSelf->pipe_top__DOT__rd_EX = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8027678175892457532ull);
    vlSelf->pipe_top__DOT__rd_MEM = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7094565385237506372ull);
    vlSelf->pipe_top__DOT__rd_WB = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8975397809488473201ull);
    vlSelf->pipe_top__DOT__imm_ID = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7949011365696899253ull);
    vlSelf->pipe_top__DOT__imm_EX = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2096019639528922117ull);
    vlSelf->pipe_top__DOT__alu_op_ID = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1720511099935082785ull);
    vlSelf->pipe_top__DOT__alu_op_EX = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14481095018536231289ull);
    vlSelf->pipe_top__DOT__alu_src_ID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6394319192739443228ull);
    vlSelf->pipe_top__DOT__alu_src_EX = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3278549044248792138ull);
    vlSelf->pipe_top__DOT__mem_read_ID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8620048021620293836ull);
    vlSelf->pipe_top__DOT__mem_read_EX = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7478809373378977388ull);
    vlSelf->pipe_top__DOT__mem_read_MEM = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13977373651836255035ull);
    vlSelf->pipe_top__DOT__mem_write_ID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7535329028906649321ull);
    vlSelf->pipe_top__DOT__mem_write_EX = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5191342816303993372ull);
    vlSelf->pipe_top__DOT__mem_write_MEM = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5420627486873639858ull);
    vlSelf->pipe_top__DOT__reg_write_ID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6648219836258771123ull);
    vlSelf->pipe_top__DOT__reg_write_EX = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18068570318147552183ull);
    vlSelf->pipe_top__DOT__reg_write_MEM = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3334778210766393665ull);
    vlSelf->pipe_top__DOT__reg_write_WB = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16739808865959710677ull);
    vlSelf->pipe_top__DOT__wb_sel_ID = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2491729819128434801ull);
    vlSelf->pipe_top__DOT__wb_sel_EX = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14409150865587659057ull);
    vlSelf->pipe_top__DOT__wb_sel_MEM = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4520937666612421971ull);
    vlSelf->pipe_top__DOT__wb_sel_WB = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1997604649701719372ull);
    vlSelf->pipe_top__DOT__branch_ID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2523240854733117576ull);
    vlSelf->pipe_top__DOT__branch_EX = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12744467231276989133ull);
    vlSelf->pipe_top__DOT__jump_ID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6434905195525704702ull);
    vlSelf->pipe_top__DOT__jump_EX = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6317010922764043710ull);
    vlSelf->pipe_top__DOT__jump_MEM = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1653384171755533199ull);
    vlSelf->pipe_top__DOT__jalr_ID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12215015592884793442ull);
    vlSelf->pipe_top__DOT__jalr_EX = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15529851164599783040ull);
    vlSelf->pipe_top__DOT__auipc_ID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4331665550607441587ull);
    vlSelf->pipe_top__DOT__auipc_EX = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12899966629876262153ull);
    vlSelf->pipe_top__DOT__lui_ID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11907351283741131014ull);
    vlSelf->pipe_top__DOT__lui_EX = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17102806757350372429ull);
    vlSelf->pipe_top__DOT__rs1_data_ID = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18335558206014268687ull);
    vlSelf->pipe_top__DOT__rs1_data_EX = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10898294751846898668ull);
    vlSelf->pipe_top__DOT__rs2_data_ID = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10680300304423317680ull);
    vlSelf->pipe_top__DOT__rs2_data_EX = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9638812512271100902ull);
    vlSelf->pipe_top__DOT__rs2_data_MEM = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1615349430265196638ull);
    vlSelf->pipe_top__DOT__alu_b_EX = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16133686926705810347ull);
    vlSelf->pipe_top__DOT__alu_result_EX = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11890998561687746535ull);
    vlSelf->pipe_top__DOT__alu_result_MEM = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12579961310990027236ull);
    vlSelf->pipe_top__DOT__alu_result_WB = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17458728837980464320ull);
    vlSelf->pipe_top__DOT__alu_zero_EX = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12445257609135769011ull);
    vlSelf->pipe_top__DOT__alu_zero_MEM = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15953323764273932969ull);
    vlSelf->pipe_top__DOT__mem_read_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12826605548436465770ull);
    vlSelf->pipe_top__DOT__mem_read_data_WB = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5057745780985344305ull);
    vlSelf->pipe_top__DOT__writeback_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12898872819089144139ull);
    vlSelf->pipe_top__DOT__branch_taken_EX = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14027227949784217249ull);
    vlSelf->pipe_top__DOT__branch_taken_MEM = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10436290620146424350ull);
    vlSelf->pipe_top__DOT__branch_target_EX = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15713315796457166564ull);
    vlSelf->pipe_top__DOT__branch_target_MEM = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 111390992571421070ull);
    vlSelf->pipe_top__DOT__jump_target_EX = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2286227437140730488ull);
    vlSelf->pipe_top__DOT__jump_target_MEM = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1461801464333627204ull);
    vlSelf->pipe_top__DOT__funct3_EX = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15681055627711579387ull);
    vlSelf->pipe_top__DOT__fetch_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7155303325188249863ull);
    vlSelf->pipe_top__DOT__fetch_inst__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7712374594945359208ull);
    vlSelf->pipe_top__DOT__fetch_inst__DOT__branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6925993229625994356ull);
    vlSelf->pipe_top__DOT__fetch_inst__DOT__jump = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14726533150943267290ull);
    vlSelf->pipe_top__DOT__fetch_inst__DOT__branch_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5017124034381819993ull);
    vlSelf->pipe_top__DOT__fetch_inst__DOT__jump_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6754570971529792521ull);
    vlSelf->pipe_top__DOT__fetch_inst__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4744010983807512764ull);
    vlSelf->pipe_top__DOT__fetch_inst__DOT__instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10549878079208745147ull);
    vlSelf->pipe_top__DOT__fetch_inst__DOT__pc_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3458108654912933090ull);
    vlSelf->pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18193069698023319052ull);
    vlSelf->pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5056213482438939903ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16973569878748914192ull);
    }
    vlSelf->pipe_top__DOT__if_id_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13259973137487203214ull);
    vlSelf->pipe_top__DOT__if_id_inst__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6202656340590388628ull);
    vlSelf->pipe_top__DOT__if_id_inst__DOT__pc_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7900051652827989289ull);
    vlSelf->pipe_top__DOT__if_id_inst__DOT__instr_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11331736610820440184ull);
    vlSelf->pipe_top__DOT__if_id_inst__DOT__pc_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2083365225644469695ull);
    vlSelf->pipe_top__DOT__if_id_inst__DOT__instr_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11356251167771338453ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7995202881108654519ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10126000877243896607ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14733845719902610431ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12486935001705090195ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11842919976960854012ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__alu_op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12309644788889533629ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13863878400976170534ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15598235315300191164ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15502221870998509491ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8032616873994609058ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10000973685689961232ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10995630996131219980ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__jump = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3750116137049508566ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12225703681770394315ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__auipc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13673366793540455681ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__lui = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17559318710974419694ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 16133571294444561205ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8343094650788010581ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__funct7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 4138044636665792596ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__imm_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4005435326017322305ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__imm_s = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12590105215277120734ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__imm_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11572065542181808610ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__imm_u = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1571519265068769578ull);
    vlSelf->pipe_top__DOT__decoder_inst__DOT__imm_j = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16432466234918830684ull);
    vlSelf->pipe_top__DOT__regfile_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2705207319134732538ull);
    vlSelf->pipe_top__DOT__regfile_inst__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 439631284644795642ull);
    vlSelf->pipe_top__DOT__regfile_inst__DOT__rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15170212978522157148ull);
    vlSelf->pipe_top__DOT__regfile_inst__DOT__rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16426217722948663937ull);
    vlSelf->pipe_top__DOT__regfile_inst__DOT__rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1100208267438976608ull);
    vlSelf->pipe_top__DOT__regfile_inst__DOT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15396177722382344883ull);
    vlSelf->pipe_top__DOT__regfile_inst__DOT__rdata1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1724312466313183111ull);
    vlSelf->pipe_top__DOT__regfile_inst__DOT__rdata2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6199162623589219504ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->pipe_top__DOT__regfile_inst__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2332993153541439735ull);
    }
    vlSelf->pipe_top__DOT__regfile_inst__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 575083327079803206ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8012609025109948384ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12763829140970909866ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__pc_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16212835771435371583ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__rs1_data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11204006425332800316ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__rs2_data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14188448125908287106ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__imm_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8109027051695849091ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__rs1_in = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16282172161787862606ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__rs2_in = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14860156548690442825ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__rd_in = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10653907317678011407ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__alu_op_in = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5431683739068118257ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__alu_src_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17619603775713875513ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__mem_read_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8402386589378959894ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__mem_write_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4882787708514753627ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__reg_write_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10194953333253876029ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__wb_sel_in = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17983568435896250687ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__branch_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16409102800646573767ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__jump_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6681098995093527358ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__jalr_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10675347519313231005ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__auipc_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9901706329698543255ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__lui_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10756572531400966251ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__funct3_in = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10013687389426676277ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__pc_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17891741439417122965ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__rs1_data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2986264166115030602ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__rs2_data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8321701678210958274ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__imm_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6032505965050575344ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__rs1_out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12972119697166436632ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__rs2_out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 880298135565389319ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__rd_out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7139729322034484238ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__alu_op_out = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17233807813639914197ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__alu_src_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1888331528421702475ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__mem_read_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10091483040989133845ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__mem_write_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14822095559948712692ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__reg_write_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5230206356650962854ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__wb_sel_out = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10482715129031022070ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__branch_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3985599120018875595ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__jump_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8360444110574720953ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__jalr_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4325184202912550343ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__auipc_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2617403667320919402ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__funct3_out = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5895443149631042380ull);
    vlSelf->pipe_top__DOT__id_ex_inst__DOT__lui_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4409343050446296811ull);
    vlSelf->pipe_top__DOT__alu_inst__DOT__a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3533465227299174110ull);
    vlSelf->pipe_top__DOT__alu_inst__DOT__b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3091473972393087219ull);
    vlSelf->pipe_top__DOT__alu_inst__DOT__op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11927866965131588942ull);
    vlSelf->pipe_top__DOT__alu_inst__DOT__result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5227603788946804319ull);
    vlSelf->pipe_top__DOT__alu_inst__DOT__zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 412365632646042670ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 303499125808783897ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2295019758369102331ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__alu_result_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5948516866153911707ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__rs2_data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12465968788809533811ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__pc_plus4_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7073799909002127850ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__branch_target_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2395786766184727307ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__jump_target_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13820520760839643873ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__branch_taken_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17886650281528230676ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__alu_zero_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12231584302754045807ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__rd_in = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3067479938090185840ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__mem_read_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9674017583570081889ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__mem_write_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3466369153369258623ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__reg_write_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14503277331843600403ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__wb_sel_in = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17697510304262671512ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__jump_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16392892547288984797ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__alu_result_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10091699754273049879ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__rs2_data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18148658503257349617ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__pc_plus4_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18092255693999448177ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__branch_target_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16236195260159198430ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__jump_target_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13686797118090233714ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__branch_taken_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7388536742619952151ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__alu_zero_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2960876074124171875ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__rd_out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7656570362860542706ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__mem_read_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18300575484910411839ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__mem_write_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2084584452947279756ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__reg_write_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9788281893544643511ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__wb_sel_out = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10637824942824725889ull);
    vlSelf->pipe_top__DOT__ex_mem_inst__DOT__jump_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1965240044624267954ull);
    vlSelf->pipe_top__DOT__dmem_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13570478596381941801ull);
    vlSelf->pipe_top__DOT__dmem_inst__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5177603181202085256ull);
    vlSelf->pipe_top__DOT__dmem_inst__DOT__addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3212641867964382291ull);
    vlSelf->pipe_top__DOT__dmem_inst__DOT__wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8432766698546889735ull);
    vlSelf->pipe_top__DOT__dmem_inst__DOT__rd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14975936355479955836ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pipe_top__DOT__dmem_inst__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7630915477635861322ull);
    }
    vlSelf->pipe_top__DOT__mem_wb_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8007985482484251729ull);
    vlSelf->pipe_top__DOT__mem_wb_inst__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18148861083503023916ull);
    vlSelf->pipe_top__DOT__mem_wb_inst__DOT__alu_result_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6815463607205818929ull);
    vlSelf->pipe_top__DOT__mem_wb_inst__DOT__mem_read_data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13365426895942177854ull);
    vlSelf->pipe_top__DOT__mem_wb_inst__DOT__pc_plus4_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7528320589119121887ull);
    vlSelf->pipe_top__DOT__mem_wb_inst__DOT__rd_in = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17784310516006139719ull);
    vlSelf->pipe_top__DOT__mem_wb_inst__DOT__reg_write_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16993404746364816602ull);
    vlSelf->pipe_top__DOT__mem_wb_inst__DOT__wb_sel_in = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13735424860828061764ull);
    vlSelf->pipe_top__DOT__mem_wb_inst__DOT__alu_result_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7845079164367822119ull);
    vlSelf->pipe_top__DOT__mem_wb_inst__DOT__mem_read_data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11824542979366738654ull);
    vlSelf->pipe_top__DOT__mem_wb_inst__DOT__pc_plus4_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17534853024277403981ull);
    vlSelf->pipe_top__DOT__mem_wb_inst__DOT__rd_out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11772776352815177290ull);
    vlSelf->pipe_top__DOT__mem_wb_inst__DOT__reg_write_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2876976946518754338ull);
    vlSelf->pipe_top__DOT__mem_wb_inst__DOT__wb_sel_out = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8170187617947495625ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__pipe_top__DOT__fetch_inst__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipe_top__DOT__fetch_inst__DOT__rst__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipe_top__DOT__if_id_inst__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipe_top__DOT__if_id_inst__DOT__rst__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipe_top__DOT__regfile_inst__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipe_top__DOT__id_ex_inst__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipe_top__DOT__id_ex_inst__DOT__rst__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipe_top__DOT__ex_mem_inst__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipe_top__DOT__ex_mem_inst__DOT__rst__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipe_top__DOT__dmem_inst__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipe_top__DOT__mem_wb_inst__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipe_top__DOT__mem_wb_inst__DOT__rst__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
