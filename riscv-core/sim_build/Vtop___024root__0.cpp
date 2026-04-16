// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.alu__DOT__op = vlSelfRef.op;
    vlSelfRef.alu__DOT__a = vlSelfRef.a;
    vlSelfRef.alu__DOT__b = vlSelfRef.b;
    vlSelfRef.alu__DOT__zero = (vlSelfRef.alu__DOT__a 
                                == vlSelfRef.alu__DOT__b);
    vlSelfRef.alu__DOT__result = ((8U & (IData)(vlSelfRef.alu__DOT__op))
                                   ? ((4U & (IData)(vlSelfRef.alu__DOT__op))
                                       ? 0U : ((2U 
                                                & (IData)(vlSelfRef.alu__DOT__op))
                                                ? 0U
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.alu__DOT__op))
                                                    ? 
                                                   ((vlSelfRef.alu__DOT__a 
                                                     < vlSelfRef.alu__DOT__b)
                                                     ? 1U
                                                     : 0U)
                                                    : 
                                                   (VL_LTS_III(32, vlSelfRef.alu__DOT__a, vlSelfRef.alu__DOT__b)
                                                     ? 1U
                                                     : 0U))))
                                   : ((4U & (IData)(vlSelfRef.alu__DOT__op))
                                       ? ((2U & (IData)(vlSelfRef.alu__DOT__op))
                                           ? ((1U & (IData)(vlSelfRef.alu__DOT__op))
                                               ? VL_SHIFTRS_III(32,32,5, vlSelfRef.alu__DOT__a, 
                                                                (0x0000001fU 
                                                                 & vlSelfRef.alu__DOT__b))
                                               : (vlSelfRef.alu__DOT__a 
                                                  >> 
                                                  (0x0000001fU 
                                                   & vlSelfRef.alu__DOT__b)))
                                           : ((1U & (IData)(vlSelfRef.alu__DOT__op))
                                               ? (vlSelfRef.alu__DOT__a 
                                                  << 
                                                  (0x0000001fU 
                                                   & vlSelfRef.alu__DOT__b))
                                               : (vlSelfRef.alu__DOT__a 
                                                  ^ vlSelfRef.alu__DOT__b)))
                                       : ((2U & (IData)(vlSelfRef.alu__DOT__op))
                                           ? ((1U & (IData)(vlSelfRef.alu__DOT__op))
                                               ? (vlSelfRef.alu__DOT__a 
                                                  | vlSelfRef.alu__DOT__b)
                                               : (vlSelfRef.alu__DOT__a 
                                                  & vlSelfRef.alu__DOT__b))
                                           : ((1U & (IData)(vlSelfRef.alu__DOT__op))
                                               ? (vlSelfRef.alu__DOT__a 
                                                  - vlSelfRef.alu__DOT__b)
                                               : (vlSelfRef.alu__DOT__a 
                                                  + vlSelfRef.alu__DOT__b)))));
    vlSelfRef.zero = vlSelfRef.alu__DOT__zero;
    vlSelfRef.result = vlSelfRef.alu__DOT__result;
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/ankur/workspace/BoseRV/riscv-core/src/alu.v", 12, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.op & 0xf0U)))) {
        Verilated::overWidthError("op");
    }
}
#endif  // VL_DEBUG
