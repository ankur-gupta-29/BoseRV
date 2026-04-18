// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__fetch_inst__DOT__clk__0 
        = vlSelfRef.top__DOT__fetch_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__fetch_inst__DOT__rst__0 
        = vlSelfRef.top__DOT__fetch_inst__DOT__rst;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__regfile_inst__DOT__clk__0 
        = vlSelfRef.top__DOT__regfile_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__dmem_inst__DOT__clk__0 
        = vlSelfRef.top__DOT__dmem_inst__DOT__clk;
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
                 ,  &(vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__mem)
                 , 0, ~0ULL);
    vlSelfRef.top__DOT__regfile_inst__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000020U, vlSelfRef.top__DOT__regfile_inst__DOT__i)) {
        vlSelfRef.top__DOT__regfile_inst__DOT__regs[(0x0000001fU 
                                                     & vlSelfRef.top__DOT__regfile_inst__DOT__i)] = 0U;
        vlSelfRef.top__DOT__regfile_inst__DOT__i = 
            ((IData)(1U) + vlSelfRef.top__DOT__regfile_inst__DOT__i);
    }
    vlSelfRef.top__DOT__decoder_inst__DOT__jalr = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__jump = 0U;
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
            VL_FATAL_MT("/home/ankur/workspace/BoseRV/riscv-core/src/top.v", 7, "", "Settle region did not converge after 100 tries");
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

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__jump = vlSelfRef.top__DOT__decoder_inst__DOT__jump;
    vlSelfRef.top__DOT__rst = vlSelfRef.rst;
    vlSelfRef.top__DOT__jalr = vlSelfRef.top__DOT__decoder_inst__DOT__jalr;
    vlSelfRef.top__DOT__clk = vlSelfRef.clk;
    vlSelfRef.top__DOT__fetch_inst__DOT__pc = vlSelfRef.top__DOT__fetch_inst__DOT__pc_reg;
    vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__addr 
        = vlSelfRef.top__DOT__fetch_inst__DOT__pc_reg;
    vlSelfRef.top__DOT__fetch_inst__DOT__jump = vlSelfRef.top__DOT__jump;
    vlSelfRef.top__DOT__fetch_inst__DOT__rst = vlSelfRef.top__DOT__rst;
    vlSelfRef.top__DOT__fetch_inst__DOT__clk = vlSelfRef.top__DOT__clk;
    vlSelfRef.top__DOT__regfile_inst__DOT__clk = vlSelfRef.top__DOT__clk;
    vlSelfRef.top__DOT__dmem_inst__DOT__clk = vlSelfRef.top__DOT__clk;
    vlSelfRef.top__DOT__pc = vlSelfRef.top__DOT__fetch_inst__DOT__pc;
    vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__instr 
        = vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__mem
        [(0x000000ffU & (vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__addr 
                         >> 2U))];
    vlSelfRef.top__DOT__fetch_inst__DOT__instr = vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__instr;
    vlSelfRef.top__DOT__instr = vlSelfRef.top__DOT__fetch_inst__DOT__instr;
    vlSelfRef.top__DOT__decoder_inst__DOT__instr = vlSelfRef.top__DOT__instr;
    vlSelfRef.top__DOT__decoder_inst__DOT__imm_j = 
        ((((0x00000ffeU & ((- (IData)((vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                                       >> 0x0000001fU))) 
                           << 1U)) | (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                                      >> 0x0000001fU)) 
          << 0x00000014U) | ((((0x000001feU & (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                                               >> 0x0000000bU)) 
                               | (1U & (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                                        >> 0x00000014U))) 
                              << 0x0000000bU) | (0x000007feU 
                                                 & (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                                                    >> 0x00000014U))));
    vlSelfRef.top__DOT__decoder_inst__DOT__rd = (0x0000001fU 
                                                 & (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                                                    >> 7U));
    vlSelfRef.top__DOT__decoder_inst__DOT__funct3 = 
        (7U & (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
               >> 0x0000000cU));
    vlSelfRef.top__DOT__decoder_inst__DOT__funct7 = 
        (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
         >> 0x00000019U);
    vlSelfRef.top__DOT__decoder_inst__DOT__rs2 = (0x0000001fU 
                                                  & (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                                                     >> 0x00000014U));
    vlSelfRef.top__DOT__decoder_inst__DOT__rs1 = (0x0000001fU 
                                                  & (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                                                     >> 0x0000000fU));
    vlSelfRef.top__DOT__decoder_inst__DOT__imm_b = 
        (((- (IData)((vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                      >> 0x0000001fU))) << 0x0000000dU) 
         | ((((2U & (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                     >> 0x0000001eU)) | (1U & (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                                               >> 7U))) 
             << 0x0000000bU) | ((0x000007e0U & (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                                                >> 0x00000014U)) 
                                | (0x0000001eU & (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                                                  >> 7U)))));
    vlSelfRef.top__DOT__decoder_inst__DOT__imm_i = 
        (((- (IData)((vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                      >> 0x0000001fU))) << 0x0000000cU) 
         | (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
            >> 0x00000014U));
    vlSelfRef.top__DOT__decoder_inst__DOT__imm_s = 
        (((- (IData)((vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                      >> 0x0000001fU))) << 0x0000000cU) 
         | ((0x00000fe0U & (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                            >> 0x00000014U)) | (0x0000001fU 
                                                & (vlSelfRef.top__DOT__decoder_inst__DOT__instr 
                                                   >> 7U))));
    vlSelfRef.top__DOT__decoder_inst__DOT__imm_u = 
        (0xfffff000U & vlSelfRef.top__DOT__decoder_inst__DOT__instr);
    vlSelfRef.top__DOT__decoder_inst__DOT__opcode = 
        (0x0000007fU & vlSelfRef.top__DOT__decoder_inst__DOT__instr);
    vlSelfRef.top__DOT__rd = vlSelfRef.top__DOT__decoder_inst__DOT__rd;
    vlSelfRef.top__DOT__rs2 = vlSelfRef.top__DOT__decoder_inst__DOT__rs2;
    vlSelfRef.top__DOT__rs1 = vlSelfRef.top__DOT__decoder_inst__DOT__rs1;
    vlSelfRef.top__DOT__decoder_inst__DOT__mem_read = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__mem_write = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__branch = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                  >> 6U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                      >> 5U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.top__DOT__decoder_inst__DOT__mem_read = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x00000020U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.top__DOT__decoder_inst__DOT__mem_write = 1U;
                            }
                        }
                    }
                }
            }
            if ((0x00000010U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
                            }
                        }
                    } else if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                                 >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
                        }
                    }
                }
            }
        } else if ((0x00000010U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                             >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 1U;
                    }
                }
            }
        }
    }
    vlSelfRef.top__DOT__decoder_inst__DOT__alu_op = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__imm = 0U;
    if ((0x00000040U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
        if ((0x00000020U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 0U;
                                vlSelfRef.top__DOT__decoder_inst__DOT__branch = 1U;
                                vlSelfRef.top__DOT__decoder_inst__DOT__alu_op = 1U;
                                vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 0U;
                                vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                                    = vlSelfRef.top__DOT__decoder_inst__DOT__imm_b;
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x00000020U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
        if ((0x00000010U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 1U;
                            vlSelfRef.top__DOT__decoder_inst__DOT__alu_op = 5U;
                            vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 1U;
                            vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                                = vlSelfRef.top__DOT__decoder_inst__DOT__imm_u;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 1U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__alu_op 
                            = ((0U == (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                ? ((0x00000020U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct7))
                                    ? 1U : 0U) : 0U);
                        vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 0U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__imm = 0U;
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                             >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 0U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__alu_op = 0U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 1U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                            = vlSelfRef.top__DOT__decoder_inst__DOT__imm_s;
                    }
                }
            }
        }
    } else if ((0x00000010U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 1U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__alu_op 
                            = ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                ? ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                    ? ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                        ? 2U : 3U) : 
                                   ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                     ? 0U : 4U)) : 
                               ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                 ? ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                     ? 9U : 8U) : 0U));
                        vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 1U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                            = vlSelfRef.top__DOT__decoder_inst__DOT__imm_i;
                    }
                }
            }
        }
    } else if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                         >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 1U;
                    vlSelfRef.top__DOT__decoder_inst__DOT__alu_op = 0U;
                    vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 1U;
                    vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                        = vlSelfRef.top__DOT__decoder_inst__DOT__imm_i;
                }
            }
        }
    }
    vlSelfRef.top__DOT__regfile_inst__DOT__rd = vlSelfRef.top__DOT__rd;
    vlSelfRef.top__DOT__regfile_inst__DOT__rs2 = vlSelfRef.top__DOT__rs2;
    vlSelfRef.top__DOT__regfile_inst__DOT__rs1 = vlSelfRef.top__DOT__rs1;
    vlSelfRef.top__DOT__mem_read = vlSelfRef.top__DOT__decoder_inst__DOT__mem_read;
    vlSelfRef.top__DOT__mem_write = vlSelfRef.top__DOT__decoder_inst__DOT__mem_write;
    vlSelfRef.top__DOT__reg_write = vlSelfRef.top__DOT__decoder_inst__DOT__reg_write;
    vlSelfRef.top__DOT__branch = vlSelfRef.top__DOT__decoder_inst__DOT__branch;
    vlSelfRef.top__DOT__wb_sel = vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel;
    vlSelfRef.top__DOT__alu_op = vlSelfRef.top__DOT__decoder_inst__DOT__alu_op;
    vlSelfRef.top__DOT__alu_src = vlSelfRef.top__DOT__decoder_inst__DOT__alu_src;
    vlSelfRef.top__DOT__imm = vlSelfRef.top__DOT__decoder_inst__DOT__imm;
    vlSelfRef.top__DOT__regfile_inst__DOT__rdata2 = 
        ((0U == (IData)(vlSelfRef.top__DOT__regfile_inst__DOT__rs2))
          ? 0U : vlSelfRef.top__DOT__regfile_inst__DOT__regs
         [vlSelfRef.top__DOT__regfile_inst__DOT__rs2]);
    vlSelfRef.top__DOT__regfile_inst__DOT__rdata1 = 
        ((0U == (IData)(vlSelfRef.top__DOT__regfile_inst__DOT__rs1))
          ? 0U : vlSelfRef.top__DOT__regfile_inst__DOT__regs
         [vlSelfRef.top__DOT__regfile_inst__DOT__rs1]);
    vlSelfRef.top__DOT__dmem_inst__DOT__we = vlSelfRef.top__DOT__mem_write;
    vlSelfRef.top__DOT__regfile_inst__DOT__we = vlSelfRef.top__DOT__reg_write;
    vlSelfRef.top__DOT__alu_inst__DOT__op = vlSelfRef.top__DOT__alu_op;
    vlSelfRef.top__DOT__branch_target = (vlSelfRef.top__DOT__imm 
                                         + vlSelfRef.top__DOT__pc);
    vlSelfRef.top__DOT__rs2_data = vlSelfRef.top__DOT__regfile_inst__DOT__rdata2;
    vlSelfRef.top__DOT__rs1_data = vlSelfRef.top__DOT__regfile_inst__DOT__rdata1;
    vlSelfRef.top__DOT__fetch_inst__DOT__branch_target 
        = vlSelfRef.top__DOT__branch_target;
    vlSelfRef.top__DOT__dmem_inst__DOT__wd = vlSelfRef.top__DOT__rs2_data;
    vlSelfRef.top__DOT__alu_b_in = ((IData)(vlSelfRef.top__DOT__alu_src)
                                     ? vlSelfRef.top__DOT__imm
                                     : vlSelfRef.top__DOT__rs2_data);
    vlSelfRef.top__DOT__jump_target = ((IData)(vlSelfRef.top__DOT__jalr)
                                        ? (vlSelfRef.top__DOT__imm 
                                           + vlSelfRef.top__DOT__rs1_data)
                                        : vlSelfRef.top__DOT__branch_target);
    vlSelfRef.top__DOT__alu_inst__DOT__a = vlSelfRef.top__DOT__rs1_data;
    vlSelfRef.top__DOT__alu_inst__DOT__b = vlSelfRef.top__DOT__alu_b_in;
    vlSelfRef.top__DOT__fetch_inst__DOT__jump_target 
        = vlSelfRef.top__DOT__jump_target;
    vlSelfRef.top__DOT__alu_inst__DOT__zero = (vlSelfRef.top__DOT__alu_inst__DOT__a 
                                               == vlSelfRef.top__DOT__alu_inst__DOT__b);
    vlSelfRef.top__DOT__alu_inst__DOT__result = ((8U 
                                                  & (IData)(vlSelfRef.top__DOT__alu_inst__DOT__op))
                                                  ? 
                                                 ((4U 
                                                   & (IData)(vlSelfRef.top__DOT__alu_inst__DOT__op))
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.top__DOT__alu_inst__DOT__op))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__alu_inst__DOT__op))
                                                     ? 
                                                    ((vlSelfRef.top__DOT__alu_inst__DOT__a 
                                                      < vlSelfRef.top__DOT__alu_inst__DOT__b)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    (VL_LTS_III(32, vlSelfRef.top__DOT__alu_inst__DOT__a, vlSelfRef.top__DOT__alu_inst__DOT__b)
                                                      ? 1U
                                                      : 0U))))
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlSelfRef.top__DOT__alu_inst__DOT__op))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.top__DOT__alu_inst__DOT__op))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__alu_inst__DOT__op))
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__alu_inst__DOT__a, 
                                                                   (0x0000001fU 
                                                                    & vlSelfRef.top__DOT__alu_inst__DOT__b))
                                                     : 
                                                    (vlSelfRef.top__DOT__alu_inst__DOT__a 
                                                     >> 
                                                     (0x0000001fU 
                                                      & vlSelfRef.top__DOT__alu_inst__DOT__b)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__alu_inst__DOT__op))
                                                     ? 
                                                    (vlSelfRef.top__DOT__alu_inst__DOT__a 
                                                     << 
                                                     (0x0000001fU 
                                                      & vlSelfRef.top__DOT__alu_inst__DOT__b))
                                                     : 
                                                    (vlSelfRef.top__DOT__alu_inst__DOT__a 
                                                     ^ vlSelfRef.top__DOT__alu_inst__DOT__b)))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.top__DOT__alu_inst__DOT__op))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__alu_inst__DOT__op))
                                                     ? 
                                                    (vlSelfRef.top__DOT__alu_inst__DOT__a 
                                                     | vlSelfRef.top__DOT__alu_inst__DOT__b)
                                                     : 
                                                    (vlSelfRef.top__DOT__alu_inst__DOT__a 
                                                     & vlSelfRef.top__DOT__alu_inst__DOT__b))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__alu_inst__DOT__op))
                                                     ? 
                                                    (vlSelfRef.top__DOT__alu_inst__DOT__a 
                                                     - vlSelfRef.top__DOT__alu_inst__DOT__b)
                                                     : 
                                                    (vlSelfRef.top__DOT__alu_inst__DOT__a 
                                                     + vlSelfRef.top__DOT__alu_inst__DOT__b)))));
    vlSelfRef.top__DOT__alu_zero = vlSelfRef.top__DOT__alu_inst__DOT__zero;
    vlSelfRef.top__DOT__alu_result = vlSelfRef.top__DOT__alu_inst__DOT__result;
    vlSelfRef.top__DOT__branch_taken = ((IData)(vlSelfRef.top__DOT__alu_zero) 
                                        & (IData)(vlSelfRef.top__DOT__branch));
    vlSelfRef.top__DOT__dmem_inst__DOT__addr = vlSelfRef.top__DOT__alu_result;
    vlSelfRef.top__DOT__fetch_inst__DOT__branch_taken 
        = vlSelfRef.top__DOT__branch_taken;
    vlSelfRef.top__DOT__dmem_inst__DOT__rd = vlSelfRef.top__DOT__dmem_inst__DOT__mem
        [(0x000000ffU & (vlSelfRef.top__DOT__dmem_inst__DOT__addr 
                         >> 2U))];
    vlSelfRef.top__DOT__mem_read_data = vlSelfRef.top__DOT__dmem_inst__DOT__rd;
    vlSelfRef.top__DOT__writeback_data = ((0U == (IData)(vlSelfRef.top__DOT__wb_sel))
                                           ? vlSelfRef.top__DOT__alu_result
                                           : ((1U == (IData)(vlSelfRef.top__DOT__wb_sel))
                                               ? vlSelfRef.top__DOT__mem_read_data
                                               : ((IData)(4U) 
                                                  + vlSelfRef.top__DOT__pc)));
    vlSelfRef.top__DOT__regfile_inst__DOT__wdata = vlSelfRef.top__DOT__writeback_data;
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge top.fetch_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge top.fetch_inst.rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge top.regfile_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge top.dmem_inst.clk)\n");
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
    vlSelf->top__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17741742976451700217ull);
    vlSelf->top__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9570330383657782965ull);
    vlSelf->top__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8764853023528993103ull);
    vlSelf->top__DOT__instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3126867797622976717ull);
    vlSelf->top__DOT__rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13712195198600804357ull);
    vlSelf->top__DOT__rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4635751753440128890ull);
    vlSelf->top__DOT__rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3328450216708286131ull);
    vlSelf->top__DOT__imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18445623346312568628ull);
    vlSelf->top__DOT__alu_op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2322472247495052196ull);
    vlSelf->top__DOT__alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 920486807967748938ull);
    vlSelf->top__DOT__mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7095475998987836616ull);
    vlSelf->top__DOT__mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16154316610771121487ull);
    vlSelf->top__DOT__reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6919762768922686668ull);
    vlSelf->top__DOT__branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9163301880374970101ull);
    vlSelf->top__DOT__jump = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17483046977668594442ull);
    vlSelf->top__DOT__jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6278530106186258012ull);
    vlSelf->top__DOT__wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2796855917807905036ull);
    vlSelf->top__DOT__rs1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 595039983895368829ull);
    vlSelf->top__DOT__rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12555395350430748387ull);
    vlSelf->top__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1414706314101411564ull);
    vlSelf->top__DOT__alu_zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9140342103571717515ull);
    vlSelf->top__DOT__mem_read_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15051047848365176992ull);
    vlSelf->top__DOT__alu_b_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9886311799662046688ull);
    vlSelf->top__DOT__writeback_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10042464747259415774ull);
    vlSelf->top__DOT__branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13525691122646395870ull);
    vlSelf->top__DOT__branch_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14505591511740879728ull);
    vlSelf->top__DOT__jump_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12303079154299553504ull);
    vlSelf->top__DOT__fetch_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3773510879838338583ull);
    vlSelf->top__DOT__fetch_inst__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17518742716669503812ull);
    vlSelf->top__DOT__fetch_inst__DOT__branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13118203494888417484ull);
    vlSelf->top__DOT__fetch_inst__DOT__jump = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17831118762830373163ull);
    vlSelf->top__DOT__fetch_inst__DOT__branch_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9264472380743015236ull);
    vlSelf->top__DOT__fetch_inst__DOT__jump_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6039084163081870074ull);
    vlSelf->top__DOT__fetch_inst__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10543177852063082828ull);
    vlSelf->top__DOT__fetch_inst__DOT__instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 172321751398767615ull);
    vlSelf->top__DOT__fetch_inst__DOT__pc_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2074575252472526253ull);
    vlSelf->top__DOT__fetch_inst__DOT__u_imem__DOT__addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16521763042711254119ull);
    vlSelf->top__DOT__fetch_inst__DOT__u_imem__DOT__instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17493964756293703549ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__fetch_inst__DOT__u_imem__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16606135449781499958ull);
    }
    vlSelf->top__DOT__decoder_inst__DOT__instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2682036965029910116ull);
    vlSelf->top__DOT__decoder_inst__DOT__rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11215177176817399757ull);
    vlSelf->top__DOT__decoder_inst__DOT__rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12425043554279891157ull);
    vlSelf->top__DOT__decoder_inst__DOT__rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 831629598981359547ull);
    vlSelf->top__DOT__decoder_inst__DOT__imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8465761249855628627ull);
    vlSelf->top__DOT__decoder_inst__DOT__alu_op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4807460218832618682ull);
    vlSelf->top__DOT__decoder_inst__DOT__alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6358984136917482604ull);
    vlSelf->top__DOT__decoder_inst__DOT__mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12110670100335788552ull);
    vlSelf->top__DOT__decoder_inst__DOT__mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1077766372843954964ull);
    vlSelf->top__DOT__decoder_inst__DOT__reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14881156642006915328ull);
    vlSelf->top__DOT__decoder_inst__DOT__wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8424617807433129ull);
    vlSelf->top__DOT__decoder_inst__DOT__branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9681169769944910408ull);
    vlSelf->top__DOT__decoder_inst__DOT__jump = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11618407731753084424ull);
    vlSelf->top__DOT__decoder_inst__DOT__jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6122482867727998351ull);
    vlSelf->top__DOT__decoder_inst__DOT__opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 5278871174110750403ull);
    vlSelf->top__DOT__decoder_inst__DOT__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15653698007575932710ull);
    vlSelf->top__DOT__decoder_inst__DOT__funct7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 3025944397351283816ull);
    vlSelf->top__DOT__decoder_inst__DOT__imm_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8479770808738772264ull);
    vlSelf->top__DOT__decoder_inst__DOT__imm_s = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10443916109826569940ull);
    vlSelf->top__DOT__decoder_inst__DOT__imm_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13754916753573560594ull);
    vlSelf->top__DOT__decoder_inst__DOT__imm_u = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10829323610996285597ull);
    vlSelf->top__DOT__decoder_inst__DOT__imm_j = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17057227121309099317ull);
    vlSelf->top__DOT__regfile_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 162555393775550975ull);
    vlSelf->top__DOT__regfile_inst__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15318123724366912717ull);
    vlSelf->top__DOT__regfile_inst__DOT__rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16130755345688209840ull);
    vlSelf->top__DOT__regfile_inst__DOT__rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 419873371825312845ull);
    vlSelf->top__DOT__regfile_inst__DOT__rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16933544311317376347ull);
    vlSelf->top__DOT__regfile_inst__DOT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11424748802552868404ull);
    vlSelf->top__DOT__regfile_inst__DOT__rdata1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1046134240354645343ull);
    vlSelf->top__DOT__regfile_inst__DOT__rdata2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1963615059428699184ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__regfile_inst__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8244382553938036793ull);
    }
    vlSelf->top__DOT__regfile_inst__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1026463913976432465ull);
    vlSelf->top__DOT__alu_inst__DOT__a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15257791579465142194ull);
    vlSelf->top__DOT__alu_inst__DOT__b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9489757871412241536ull);
    vlSelf->top__DOT__alu_inst__DOT__op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 149537438197528038ull);
    vlSelf->top__DOT__alu_inst__DOT__result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1768053166441957658ull);
    vlSelf->top__DOT__alu_inst__DOT__zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2833914088655146743ull);
    vlSelf->top__DOT__dmem_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14960251207774333673ull);
    vlSelf->top__DOT__dmem_inst__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12552956988604979624ull);
    vlSelf->top__DOT__dmem_inst__DOT__addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 153305109787213832ull);
    vlSelf->top__DOT__dmem_inst__DOT__wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5670428671551829942ull);
    vlSelf->top__DOT__dmem_inst__DOT__rd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13727104485436997236ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__dmem_inst__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4990546632610334596ull);
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__fetch_inst__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__fetch_inst__DOT__rst__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__regfile_inst__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__dmem_inst__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
