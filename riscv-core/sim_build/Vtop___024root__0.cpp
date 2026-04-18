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
    vlSelfRef.top__DOT__rst = vlSelfRef.rst;
    vlSelfRef.top__DOT__clk = vlSelfRef.clk;
    vlSelfRef.top__DOT__fetch_inst__DOT__pc = vlSelfRef.top__DOT__fetch_inst__DOT__pc_reg;
    vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__addr 
        = vlSelfRef.top__DOT__fetch_inst__DOT__pc_reg;
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
    vlSelfRef.top__DOT__decoder_inst__DOT__auipc = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__mem_read = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__mem_write = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                  >> 6U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                      >> 5U)))) {
            if ((0x00000010U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.top__DOT__decoder_inst__DOT__auipc = 1U;
                            }
                        }
                    }
                }
            }
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
        }
    }
    vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__jump = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__branch = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__jalr = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__alu_op = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__imm = 0U;
    if ((0x00000040U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
        if ((0x00000020U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                          >> 4U)))) {
                if ((8U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    if ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 1U;
                                vlSelfRef.top__DOT__decoder_inst__DOT__jump = 1U;
                                vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 2U;
                                vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                                    = vlSelfRef.top__DOT__decoder_inst__DOT__imm_j;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 1U;
                            vlSelfRef.top__DOT__decoder_inst__DOT__jump = 0U;
                            vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 2U;
                            vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                                = vlSelfRef.top__DOT__decoder_inst__DOT__imm_i;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 0U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                            = vlSelfRef.top__DOT__decoder_inst__DOT__imm_b;
                    }
                }
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.top__DOT__decoder_inst__DOT__branch = 1U;
                                vlSelfRef.top__DOT__decoder_inst__DOT__alu_op 
                                    = ((0U == (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                        ? 1U : ((1U 
                                                 == (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                                 ? 1U
                                                 : 
                                                ((4U 
                                                  == (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                                  ? 9U
                                                  : 1U)));
                            }
                        }
                    }
                    if ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.top__DOT__decoder_inst__DOT__jalr = 1U;
                                vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 0U;
                            }
                        }
                    } else if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 0U;
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
                            vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
                            vlSelfRef.top__DOT__decoder_inst__DOT__alu_op = 0U;
                            vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 1U;
                            vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                                = vlSelfRef.top__DOT__decoder_inst__DOT__imm_u;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 1U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__alu_op 
                            = ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                ? ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                    ? ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                        ? 2U : 3U) : 
                                   ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                     ? ((0x00000020U 
                                         & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct7))
                                         ? 7U : 6U)
                                     : 4U)) : ((2U 
                                                & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                                    ? 9U
                                                    : 8U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                                    ? 5U
                                                    : 
                                                   ((0x00000020U 
                                                     & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct7))
                                                     ? 1U
                                                     : 0U))));
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
                        vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
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
            if ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 1U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__alu_op = 0U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 1U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                            = vlSelfRef.top__DOT__decoder_inst__DOT__imm_u;
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 1U;
                    vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
                    vlSelfRef.top__DOT__decoder_inst__DOT__alu_op 
                        = ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                            ? ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                ? ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                    ? 2U : 3U) : ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                                   ? 
                                                  ((0x00000020U 
                                                    & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct7))
                                                    ? 7U
                                                    : 6U)
                                                   : 4U))
                            : ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                ? ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                    ? 9U : 8U) : ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                                   ? 5U
                                                   : 0U)));
                    vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 1U;
                    vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                        = vlSelfRef.top__DOT__decoder_inst__DOT__imm_i;
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
                    vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 1U;
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
    vlSelfRef.top__DOT__jump = vlSelfRef.top__DOT__decoder_inst__DOT__jump;
    vlSelfRef.top__DOT__branch = vlSelfRef.top__DOT__decoder_inst__DOT__branch;
    vlSelfRef.top__DOT__wb_sel = vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel;
    vlSelfRef.top__DOT__jalr = vlSelfRef.top__DOT__decoder_inst__DOT__jalr;
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
    vlSelfRef.top__DOT__fetch_inst__DOT__jump = vlSelfRef.top__DOT__jump;
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
    vlSelfRef.top__DOT__alu_inst__DOT__a = ((IData)(vlSelfRef.top__DOT__auipc)
                                             ? vlSelfRef.top__DOT__pc
                                             : vlSelfRef.top__DOT__rs1_data);
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

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((((IData)(vlSelfRef.top__DOT__dmem_inst__DOT__clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__dmem_inst__DOT__clk__0))) 
                                                       << 3U) 
                                                      | (((IData)(vlSelfRef.top__DOT__regfile_inst__DOT__clk) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__regfile_inst__DOT__clk__0))) 
                                                         << 2U)) 
                                                     | ((((IData)(vlSelfRef.top__DOT__fetch_inst__DOT__rst) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__fetch_inst__DOT__rst__0))) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.top__DOT__fetch_inst__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__fetch_inst__DOT__clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__fetch_inst__DOT__clk__0 
        = vlSelfRef.top__DOT__fetch_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__fetch_inst__DOT__rst__0 
        = vlSelfRef.top__DOT__fetch_inst__DOT__rst;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__regfile_inst__DOT__clk__0 
        = vlSelfRef.top__DOT__regfile_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__dmem_inst__DOT__clk__0 
        = vlSelfRef.top__DOT__dmem_inst__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
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

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdlyVal__top__DOT__dmem_inst__DOT__mem__v0;
    __VdlyVal__top__DOT__dmem_inst__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__dmem_inst__DOT__mem__v0;
    __VdlyDim0__top__DOT__dmem_inst__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__dmem_inst__DOT__mem__v0;
    __VdlySet__top__DOT__dmem_inst__DOT__mem__v0 = 0;
    // Body
    __VdlySet__top__DOT__dmem_inst__DOT__mem__v0 = 0U;
    if (vlSelfRef.top__DOT__dmem_inst__DOT__we) {
        __VdlyVal__top__DOT__dmem_inst__DOT__mem__v0 
            = vlSelfRef.top__DOT__dmem_inst__DOT__wd;
        __VdlyDim0__top__DOT__dmem_inst__DOT__mem__v0 
            = (0x000000ffU & (vlSelfRef.top__DOT__dmem_inst__DOT__addr 
                              >> 2U));
        __VdlySet__top__DOT__dmem_inst__DOT__mem__v0 = 1U;
    }
    if (__VdlySet__top__DOT__dmem_inst__DOT__mem__v0) {
        vlSelfRef.top__DOT__dmem_inst__DOT__mem[__VdlyDim0__top__DOT__dmem_inst__DOT__mem__v0] 
            = __VdlyVal__top__DOT__dmem_inst__DOT__mem__v0;
    }
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdlyVal__top__DOT__regfile_inst__DOT__regs__v0;
    __VdlyVal__top__DOT__regfile_inst__DOT__regs__v0 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regfile_inst__DOT__regs__v0;
    __VdlyDim0__top__DOT__regfile_inst__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regfile_inst__DOT__regs__v0;
    __VdlySet__top__DOT__regfile_inst__DOT__regs__v0 = 0;
    // Body
    __VdlySet__top__DOT__regfile_inst__DOT__regs__v0 = 0U;
    if (((IData)(vlSelfRef.top__DOT__regfile_inst__DOT__we) 
         & (0U != (IData)(vlSelfRef.top__DOT__regfile_inst__DOT__rd)))) {
        __VdlyVal__top__DOT__regfile_inst__DOT__regs__v0 
            = vlSelfRef.top__DOT__regfile_inst__DOT__wdata;
        __VdlyDim0__top__DOT__regfile_inst__DOT__regs__v0 
            = vlSelfRef.top__DOT__regfile_inst__DOT__rd;
        __VdlySet__top__DOT__regfile_inst__DOT__regs__v0 = 1U;
    }
    if (__VdlySet__top__DOT__regfile_inst__DOT__regs__v0) {
        vlSelfRef.top__DOT__regfile_inst__DOT__regs[__VdlyDim0__top__DOT__regfile_inst__DOT__regs__v0] 
            = __VdlyVal__top__DOT__regfile_inst__DOT__regs__v0;
    }
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__fetch_inst__DOT__pc_reg = ((IData)(vlSelfRef.top__DOT__fetch_inst__DOT__rst)
                                                    ? 0U
                                                    : 
                                                   ((IData)(vlSelfRef.top__DOT__fetch_inst__DOT__branch_taken)
                                                     ? vlSelfRef.top__DOT__fetch_inst__DOT__branch_target
                                                     : 
                                                    ((IData)(vlSelfRef.top__DOT__fetch_inst__DOT__jump)
                                                      ? vlSelfRef.top__DOT__fetch_inst__DOT__jump_target
                                                      : 
                                                     ((IData)(4U) 
                                                      + vlSelfRef.top__DOT__fetch_inst__DOT__pc_reg))));
    vlSelfRef.top__DOT__fetch_inst__DOT__pc = vlSelfRef.top__DOT__fetch_inst__DOT__pc_reg;
    vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__addr 
        = vlSelfRef.top__DOT__fetch_inst__DOT__pc_reg;
    vlSelfRef.top__DOT__pc = vlSelfRef.top__DOT__fetch_inst__DOT__pc;
    vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__instr 
        = vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__mem
        [(0x000000ffU & (vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__addr 
                         >> 2U))];
    vlSelfRef.top__DOT__fetch_inst__DOT__instr = vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__instr;
    vlSelfRef.top__DOT__instr = vlSelfRef.top__DOT__fetch_inst__DOT__instr;
    vlSelfRef.top__DOT__decoder_inst__DOT__instr = vlSelfRef.top__DOT__instr;
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
    vlSelfRef.top__DOT__decoder_inst__DOT__auipc = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__mem_read = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__mem_write = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                  >> 6U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                      >> 5U)))) {
            if ((0x00000010U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.top__DOT__decoder_inst__DOT__auipc = 1U;
                            }
                        }
                    }
                }
            }
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
        }
    }
    vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__jump = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__branch = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__jalr = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__alu_op = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 0U;
    vlSelfRef.top__DOT__decoder_inst__DOT__imm = 0U;
    if ((0x00000040U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
        if ((0x00000020U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                          >> 4U)))) {
                if ((8U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    if ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 1U;
                                vlSelfRef.top__DOT__decoder_inst__DOT__jump = 1U;
                                vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 2U;
                                vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                                    = vlSelfRef.top__DOT__decoder_inst__DOT__imm_j;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 1U;
                            vlSelfRef.top__DOT__decoder_inst__DOT__jump = 0U;
                            vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 2U;
                            vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                                = vlSelfRef.top__DOT__decoder_inst__DOT__imm_i;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 0U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                            = vlSelfRef.top__DOT__decoder_inst__DOT__imm_b;
                    }
                }
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.top__DOT__decoder_inst__DOT__branch = 1U;
                                vlSelfRef.top__DOT__decoder_inst__DOT__alu_op 
                                    = ((0U == (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                        ? 1U : ((1U 
                                                 == (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                                 ? 1U
                                                 : 
                                                ((4U 
                                                  == (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                                  ? 9U
                                                  : 1U)));
                            }
                        }
                    }
                    if ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.top__DOT__decoder_inst__DOT__jalr = 1U;
                                vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 0U;
                            }
                        }
                    } else if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 0U;
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
                            vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
                            vlSelfRef.top__DOT__decoder_inst__DOT__alu_op = 0U;
                            vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 1U;
                            vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                                = vlSelfRef.top__DOT__decoder_inst__DOT__imm_u;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 1U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__alu_op 
                            = ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                ? ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                    ? ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                        ? 2U : 3U) : 
                                   ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                     ? ((0x00000020U 
                                         & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct7))
                                         ? 7U : 6U)
                                     : 4U)) : ((2U 
                                                & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                                    ? 9U
                                                    : 8U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                                    ? 5U
                                                    : 
                                                   ((0x00000020U 
                                                     & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct7))
                                                     ? 1U
                                                     : 0U))));
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
                        vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
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
            if ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 1U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__alu_op = 0U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 1U;
                        vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                            = vlSelfRef.top__DOT__decoder_inst__DOT__imm_u;
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__opcode))) {
                    vlSelfRef.top__DOT__decoder_inst__DOT__reg_write = 1U;
                    vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 0U;
                    vlSelfRef.top__DOT__decoder_inst__DOT__alu_op 
                        = ((4U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                            ? ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                ? ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                    ? 2U : 3U) : ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                                   ? 
                                                  ((0x00000020U 
                                                    & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct7))
                                                    ? 7U
                                                    : 6U)
                                                   : 4U))
                            : ((2U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                ? ((1U & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                    ? 9U : 8U) : ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__decoder_inst__DOT__funct3))
                                                   ? 5U
                                                   : 0U)));
                    vlSelfRef.top__DOT__decoder_inst__DOT__alu_src = 1U;
                    vlSelfRef.top__DOT__decoder_inst__DOT__imm 
                        = vlSelfRef.top__DOT__decoder_inst__DOT__imm_i;
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
                    vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel = 1U;
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
    vlSelfRef.top__DOT__jump = vlSelfRef.top__DOT__decoder_inst__DOT__jump;
    vlSelfRef.top__DOT__branch = vlSelfRef.top__DOT__decoder_inst__DOT__branch;
    vlSelfRef.top__DOT__wb_sel = vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel;
    vlSelfRef.top__DOT__jalr = vlSelfRef.top__DOT__decoder_inst__DOT__jalr;
    vlSelfRef.top__DOT__alu_op = vlSelfRef.top__DOT__decoder_inst__DOT__alu_op;
    vlSelfRef.top__DOT__alu_src = vlSelfRef.top__DOT__decoder_inst__DOT__alu_src;
    vlSelfRef.top__DOT__imm = vlSelfRef.top__DOT__decoder_inst__DOT__imm;
    vlSelfRef.top__DOT__dmem_inst__DOT__we = vlSelfRef.top__DOT__mem_write;
    vlSelfRef.top__DOT__regfile_inst__DOT__we = vlSelfRef.top__DOT__reg_write;
    vlSelfRef.top__DOT__fetch_inst__DOT__jump = vlSelfRef.top__DOT__jump;
    vlSelfRef.top__DOT__alu_inst__DOT__op = vlSelfRef.top__DOT__alu_op;
    vlSelfRef.top__DOT__branch_target = (vlSelfRef.top__DOT__imm 
                                         + vlSelfRef.top__DOT__pc);
    vlSelfRef.top__DOT__fetch_inst__DOT__branch_target 
        = vlSelfRef.top__DOT__branch_target;
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__regfile_inst__DOT__rdata2 = 
        ((0U == (IData)(vlSelfRef.top__DOT__regfile_inst__DOT__rs2))
          ? 0U : vlSelfRef.top__DOT__regfile_inst__DOT__regs
         [vlSelfRef.top__DOT__regfile_inst__DOT__rs2]);
    vlSelfRef.top__DOT__regfile_inst__DOT__rdata1 = 
        ((0U == (IData)(vlSelfRef.top__DOT__regfile_inst__DOT__rs1))
          ? 0U : vlSelfRef.top__DOT__regfile_inst__DOT__regs
         [vlSelfRef.top__DOT__regfile_inst__DOT__rs1]);
    vlSelfRef.top__DOT__rs2_data = vlSelfRef.top__DOT__regfile_inst__DOT__rdata2;
    vlSelfRef.top__DOT__rs1_data = vlSelfRef.top__DOT__regfile_inst__DOT__rdata1;
    vlSelfRef.top__DOT__dmem_inst__DOT__wd = vlSelfRef.top__DOT__rs2_data;
    vlSelfRef.top__DOT__alu_b_in = ((IData)(vlSelfRef.top__DOT__alu_src)
                                     ? vlSelfRef.top__DOT__imm
                                     : vlSelfRef.top__DOT__rs2_data);
    vlSelfRef.top__DOT__jump_target = ((IData)(vlSelfRef.top__DOT__jalr)
                                        ? (vlSelfRef.top__DOT__imm 
                                           + vlSelfRef.top__DOT__rs1_data)
                                        : vlSelfRef.top__DOT__branch_target);
    vlSelfRef.top__DOT__alu_inst__DOT__a = ((IData)(vlSelfRef.top__DOT__auipc)
                                             ? vlSelfRef.top__DOT__pc
                                             : vlSelfRef.top__DOT__rs1_data);
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
}

void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((7ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x000000000000000fULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
    }
}

void Vtop___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    Vtop___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/ankur/workspace/BoseRV/riscv-core/src/top.v", 7, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/ankur/workspace/BoseRV/riscv-core/src/top.v", 7, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/ankur/workspace/BoseRV/riscv-core/src/top.v", 7, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtop___024root___eval_phase__act(vlSelf));
    } while (Vtop___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
}
#endif  // VL_DEBUG
