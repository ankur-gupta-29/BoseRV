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
    vlSelfRef.pipe_top__DOT__rs1_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs1_out;
    vlSelfRef.pipe_top__DOT__rs2_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs2_out;
    vlSelfRef.pipe_top__DOT__branch_target_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__branch_target_out;
    vlSelfRef.pipe_top__DOT__jump_target_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__jump_target_out;
    vlSelfRef.pipe_top__DOT__branch_taken_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__branch_taken_out;
    vlSelfRef.pipe_top__DOT__alu_zero_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__alu_zero_out;
    vlSelfRef.pipe_top__DOT__mem_read_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__mem_read_out;
    vlSelfRef.pipe_top__DOT__jump_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__jump_out;
    vlSelfRef.pipe_top__DOT__pc_ID = vlSelfRef.pipe_top__DOT__if_id_inst__DOT__pc_out;
    vlSelfRef.pipe_top__DOT__reg_write_WB = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__reg_write_out;
    vlSelfRef.pipe_top__DOT__rd_WB = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__rd_out;
    vlSelfRef.pipe_top__DOT__rd_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rd_out;
    vlSelfRef.pipe_top__DOT__mem_read_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__mem_read_out;
    vlSelfRef.pipe_top__DOT__mem_write_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__mem_write_out;
    vlSelfRef.pipe_top__DOT__reg_write_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__reg_write_out;
    vlSelfRef.pipe_top__DOT__wb_sel_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__wb_sel_out;
    vlSelfRef.pipe_top__DOT__rs2_data_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rs2_data_out;
    vlSelfRef.pipe_top__DOT__pc_plus4_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__pc_plus4_out;
    vlSelfRef.pipe_top__DOT__rd_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rd_out;
    vlSelfRef.pipe_top__DOT__mem_write_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__mem_write_out;
    vlSelfRef.pipe_top__DOT__reg_write_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__reg_write_out;
    vlSelfRef.pipe_top__DOT__wb_sel_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__wb_sel_out;
    vlSelfRef.pipe_top__DOT__jump_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__jump_out;
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__pc = vlSelfRef.pipe_top__DOT__fetch_inst__DOT__pc_reg;
    vlSelfRef.pipe_top__DOT__wb_sel_WB = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__wb_sel_out;
    vlSelfRef.pipe_top__DOT__alu_result_WB = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__alu_result_out;
    vlSelfRef.pipe_top__DOT__mem_read_data_WB = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__mem_read_data_out;
    vlSelfRef.pipe_top__DOT__pc_plus4_WB = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__pc_plus4_out;
    vlSelfRef.pipe_top__DOT__jalr_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__jalr_out;
    vlSelfRef.pipe_top__DOT__branch_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__branch_out;
    vlSelfRef.pipe_top__DOT__funct3_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__funct3_out;
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__addr 
        = vlSelfRef.pipe_top__DOT__fetch_inst__DOT__pc_reg;
    vlSelfRef.pipe_top__DOT__rst = vlSelfRef.rst;
    vlSelfRef.pipe_top__DOT__alu_result_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__alu_result_out;
    vlSelfRef.pipe_top__DOT__clk = vlSelfRef.clk;
    vlSelfRef.pipe_top__DOT__alu_op_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__alu_op_out;
    vlSelfRef.pipe_top__DOT__auipc_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__auipc_out;
    vlSelfRef.pipe_top__DOT__lui_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__lui_out;
    vlSelfRef.pipe_top__DOT__alu_src_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__alu_src_out;
    vlSelfRef.pipe_top__DOT__rs2_data_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs2_data_out;
    vlSelfRef.pipe_top__DOT__rs1_data_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs1_data_out;
    vlSelfRef.pipe_top__DOT__pc_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__pc_out;
    vlSelfRef.pipe_top__DOT__imm_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__imm_out;
    vlSelfRef.pipe_top__DOT__instr_ID = vlSelfRef.pipe_top__DOT__if_id_inst__DOT__instr_out;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__pc_in 
        = vlSelfRef.pipe_top__DOT__pc_ID;
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__we 
        = vlSelfRef.pipe_top__DOT__reg_write_WB;
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rd 
        = vlSelfRef.pipe_top__DOT__rd_WB;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rd_in 
        = vlSelfRef.pipe_top__DOT__rd_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__mem_read_in 
        = vlSelfRef.pipe_top__DOT__mem_read_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__mem_write_in 
        = vlSelfRef.pipe_top__DOT__mem_write_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__reg_write_in 
        = vlSelfRef.pipe_top__DOT__reg_write_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__wb_sel_in 
        = vlSelfRef.pipe_top__DOT__wb_sel_EX;
    vlSelfRef.pipe_top__DOT__dmem_inst__DOT__wd = vlSelfRef.pipe_top__DOT__rs2_data_MEM;
    vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__pc_plus4_in 
        = vlSelfRef.pipe_top__DOT__pc_plus4_MEM;
    vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__rd_in 
        = vlSelfRef.pipe_top__DOT__rd_MEM;
    vlSelfRef.pipe_top__DOT__dmem_inst__DOT__we = vlSelfRef.pipe_top__DOT__mem_write_MEM;
    vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__reg_write_in 
        = vlSelfRef.pipe_top__DOT__reg_write_MEM;
    vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__wb_sel_in 
        = vlSelfRef.pipe_top__DOT__wb_sel_MEM;
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__jump 
        = vlSelfRef.pipe_top__DOT__jump_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__jump_in 
        = vlSelfRef.pipe_top__DOT__jump_EX;
    vlSelfRef.pipe_top__DOT__pc_IF = vlSelfRef.pipe_top__DOT__fetch_inst__DOT__pc;
    vlSelfRef.pipe_top__DOT__writeback_data = ((0U 
                                                == (IData)(vlSelfRef.pipe_top__DOT__wb_sel_WB))
                                                ? vlSelfRef.pipe_top__DOT__alu_result_WB
                                                : (
                                                   (1U 
                                                    == (IData)(vlSelfRef.pipe_top__DOT__wb_sel_WB))
                                                    ? vlSelfRef.pipe_top__DOT__mem_read_data_WB
                                                    : vlSelfRef.pipe_top__DOT__pc_plus4_WB));
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__instr 
        = vlSelfRef.pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__mem
        [(0x000000ffU & (vlSelfRef.pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__addr 
                         >> 2U))];
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__rst = vlSelfRef.pipe_top__DOT__rst;
    vlSelfRef.pipe_top__DOT__if_id_inst__DOT__rst = vlSelfRef.pipe_top__DOT__rst;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rst = vlSelfRef.pipe_top__DOT__rst;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rst 
        = vlSelfRef.pipe_top__DOT__rst;
    vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__rst 
        = vlSelfRef.pipe_top__DOT__rst;
    vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__alu_result_in 
        = vlSelfRef.pipe_top__DOT__alu_result_MEM;
    vlSelfRef.pipe_top__DOT__dmem_inst__DOT__addr = vlSelfRef.pipe_top__DOT__alu_result_MEM;
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__clk = vlSelfRef.pipe_top__DOT__clk;
    vlSelfRef.pipe_top__DOT__if_id_inst__DOT__clk = vlSelfRef.pipe_top__DOT__clk;
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__clk 
        = vlSelfRef.pipe_top__DOT__clk;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__clk = vlSelfRef.pipe_top__DOT__clk;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__clk 
        = vlSelfRef.pipe_top__DOT__clk;
    vlSelfRef.pipe_top__DOT__dmem_inst__DOT__clk = vlSelfRef.pipe_top__DOT__clk;
    vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__clk 
        = vlSelfRef.pipe_top__DOT__clk;
    vlSelfRef.pipe_top__DOT__alu_inst__DOT__op = vlSelfRef.pipe_top__DOT__alu_op_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rs2_data_in 
        = vlSelfRef.pipe_top__DOT__rs2_data_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__pc_plus4_in 
        = ((IData)(4U) + vlSelfRef.pipe_top__DOT__pc_EX);
    vlSelfRef.pipe_top__DOT__alu_inst__DOT__a = ((IData)(vlSelfRef.pipe_top__DOT__auipc_EX)
                                                  ? vlSelfRef.pipe_top__DOT__pc_EX
                                                  : 
                                                 ((IData)(vlSelfRef.pipe_top__DOT__lui_EX)
                                                   ? 0U
                                                   : vlSelfRef.pipe_top__DOT__rs1_data_EX));
    vlSelfRef.pipe_top__DOT__branch_target_EX = (vlSelfRef.pipe_top__DOT__imm_EX 
                                                 + vlSelfRef.pipe_top__DOT__pc_EX);
    vlSelfRef.pipe_top__DOT__alu_b_EX = ((IData)(vlSelfRef.pipe_top__DOT__alu_src_EX)
                                          ? vlSelfRef.pipe_top__DOT__imm_EX
                                          : vlSelfRef.pipe_top__DOT__rs2_data_EX);
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__funct3_in 
        = (7U & (vlSelfRef.pipe_top__DOT__instr_ID 
                 >> 0x0000000cU));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
        = vlSelfRef.pipe_top__DOT__instr_ID;
    vlSelfRef.pipe_top__DOT__if_id_inst__DOT__pc_in 
        = vlSelfRef.pipe_top__DOT__pc_IF;
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__wdata 
        = vlSelfRef.pipe_top__DOT__writeback_data;
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__instr 
        = vlSelfRef.pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__instr;
    vlSelfRef.pipe_top__DOT__dmem_inst__DOT__rd = vlSelfRef.pipe_top__DOT__dmem_inst__DOT__mem
        [(0x000000ffU & (vlSelfRef.pipe_top__DOT__dmem_inst__DOT__addr 
                         >> 2U))];
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__branch_target 
        = vlSelfRef.pipe_top__DOT__branch_target_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__branch_target_in 
        = vlSelfRef.pipe_top__DOT__branch_target_EX;
    vlSelfRef.pipe_top__DOT__jump_target_EX = ((IData)(vlSelfRef.pipe_top__DOT__jalr_EX)
                                                ? (0xfffffffeU 
                                                   & (vlSelfRef.pipe_top__DOT__imm_EX 
                                                      + vlSelfRef.pipe_top__DOT__rs1_data_EX))
                                                : vlSelfRef.pipe_top__DOT__branch_target_EX);
    vlSelfRef.pipe_top__DOT__alu_inst__DOT__b = vlSelfRef.pipe_top__DOT__alu_b_EX;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__rd 
        = (0x0000001fU & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                          >> 7U));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3 
        = (7U & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                 >> 0x0000000cU));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct7 
        = (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
           >> 0x00000019U);
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_b 
        = (((- (IData)((vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                        >> 0x0000001fU))) << 0x0000000dU) 
           | ((((2U & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                       >> 0x0000001eU)) | (1U & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                                 >> 7U))) 
               << 0x0000000bU) | ((0x000007e0U & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                                  >> 0x00000014U)) 
                                  | (0x0000001eU & 
                                     (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                      >> 7U)))));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_i 
        = (((- (IData)((vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                        >> 0x0000001fU))) << 0x0000000cU) 
           | (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
              >> 0x00000014U));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_j 
        = ((((0x00000ffeU & ((- (IData)((vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                         >> 0x0000001fU))) 
                             << 1U)) | (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                        >> 0x0000001fU)) 
            << 0x00000014U) | ((((0x000001feU & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                                 >> 0x0000000bU)) 
                                 | (1U & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                          >> 0x00000014U))) 
                                << 0x0000000bU) | (0x000007feU 
                                                   & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                                      >> 0x00000014U))));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_s 
        = (((- (IData)((vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                        >> 0x0000001fU))) << 0x0000000cU) 
           | ((0x00000fe0U & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                              >> 0x00000014U)) | (0x0000001fU 
                                                  & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                                     >> 7U))));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_u 
        = (0xfffff000U & vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr);
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__rs1 
        = (0x0000001fU & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                          >> 0x0000000fU));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__rs2 
        = (0x0000001fU & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                          >> 0x00000014U));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode 
        = (0x0000007fU & vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr);
    vlSelfRef.pipe_top__DOT__instr_IF = vlSelfRef.pipe_top__DOT__fetch_inst__DOT__instr;
    vlSelfRef.pipe_top__DOT__mem_read_data = vlSelfRef.pipe_top__DOT__dmem_inst__DOT__rd;
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__jump_target 
        = vlSelfRef.pipe_top__DOT__jump_target_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__jump_target_in 
        = vlSelfRef.pipe_top__DOT__jump_target_EX;
    vlSelfRef.pipe_top__DOT__alu_inst__DOT__result 
        = ((8U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
            ? ((4U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                ? 0U : ((2U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                         ? 0U : ((1U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                                  ? ((vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                                      < vlSelfRef.pipe_top__DOT__alu_inst__DOT__b)
                                      ? 1U : 0U) : 
                                 (VL_LTS_III(32, vlSelfRef.pipe_top__DOT__alu_inst__DOT__a, vlSelfRef.pipe_top__DOT__alu_inst__DOT__b)
                                   ? 1U : 0U)))) : 
           ((4U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
             ? ((2U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                 ? ((1U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                     ? VL_SHIFTRS_III(32,32,5, vlSelfRef.pipe_top__DOT__alu_inst__DOT__a, 
                                      (0x0000001fU 
                                       & vlSelfRef.pipe_top__DOT__alu_inst__DOT__b))
                     : (vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                        >> (0x0000001fU & vlSelfRef.pipe_top__DOT__alu_inst__DOT__b)))
                 : ((1U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                     ? (vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                        << (0x0000001fU & vlSelfRef.pipe_top__DOT__alu_inst__DOT__b))
                     : (vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                        ^ vlSelfRef.pipe_top__DOT__alu_inst__DOT__b)))
             : ((2U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                 ? ((1U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                     ? (vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                        | vlSelfRef.pipe_top__DOT__alu_inst__DOT__b)
                     : (vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                        & vlSelfRef.pipe_top__DOT__alu_inst__DOT__b))
                 : ((1U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                     ? (vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                        - vlSelfRef.pipe_top__DOT__alu_inst__DOT__b)
                     : (vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                        + vlSelfRef.pipe_top__DOT__alu_inst__DOT__b)))));
    vlSelfRef.pipe_top__DOT__rd_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__rd;
    vlSelfRef.pipe_top__DOT__rs1_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__rs1;
    vlSelfRef.pipe_top__DOT__rs2_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__rs2;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__mem_read = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__mem_write = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__branch = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__jump = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__jalr = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__auipc = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__lui = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                  >> 6U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                      >> 5U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__mem_read = 1U;
                            }
                        }
                    }
                }
            }
            if ((0x00000010U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__auipc = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x00000020U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__mem_write = 1U;
                            }
                        }
                    }
                }
            }
            if ((0x00000010U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__lui = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm = 0U;
    if ((0x00000040U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
        if ((0x00000020U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 0U;
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__jalr = 1U;
                            }
                        }
                    } else if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 0U;
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__branch = 1U;
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op 
                                    = ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                        ? ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                            ? 9U : 8U)
                                        : 1U);
                            }
                        }
                    }
                }
                if ((8U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    if ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 1U;
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 2U;
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__jump = 1U;
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                                    = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_j;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 1U;
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 2U;
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__jump = 1U;
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                                = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_i;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 0U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                            = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_b;
                    }
                }
            }
        }
    } else if ((0x00000020U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
        if ((0x00000010U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 1U;
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 1U;
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 0U;
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op = 0U;
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                                = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_u;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 0U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 1U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 0U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op 
                            = ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                ? ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                    ? ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                        ? 2U : 3U) : 
                                   ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                     ? ((0x00000020U 
                                         & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct7))
                                         ? 7U : 6U)
                                     : 4U)) : ((2U 
                                                & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                                    ? 9U
                                                    : 8U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                                    ? 5U
                                                    : 
                                                   ((0x00000020U 
                                                     & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct7))
                                                     ? 1U
                                                     : 0U))));
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                             >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 1U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 0U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op = 0U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                            = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_s;
                    }
                }
            }
        }
    } else if ((0x00000010U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
        if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                      >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 1U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 1U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 0U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op = 0U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                            = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_u;
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 1U;
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 1U;
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 0U;
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op 
                        = ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                            ? ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                ? ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                    ? 2U : 3U) : ((1U 
                                                   & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                                   ? 
                                                  ((0x00000020U 
                                                    & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct7))
                                                    ? 7U
                                                    : 6U)
                                                   : 4U))
                            : ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                ? ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                    ? 9U : 8U) : ((1U 
                                                   & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                                   ? 5U
                                                   : 0U)));
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                        = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_i;
                }
            }
        }
    } else if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                         >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 1U;
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 1U;
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 1U;
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op = 0U;
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                        = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_i;
                }
            }
        }
    }
    vlSelfRef.pipe_top__DOT__if_id_inst__DOT__instr_in 
        = vlSelfRef.pipe_top__DOT__instr_IF;
    vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__mem_read_data_in 
        = vlSelfRef.pipe_top__DOT__mem_read_data;
    vlSelfRef.pipe_top__DOT__alu_result_EX = vlSelfRef.pipe_top__DOT__alu_inst__DOT__result;
    vlSelfRef.pipe_top__DOT__alu_inst__DOT__zero = 
        (0U == vlSelfRef.pipe_top__DOT__alu_inst__DOT__result);
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rd_in 
        = vlSelfRef.pipe_top__DOT__rd_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs1_in 
        = vlSelfRef.pipe_top__DOT__rs1_ID;
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rs1 
        = vlSelfRef.pipe_top__DOT__rs1_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs2_in 
        = vlSelfRef.pipe_top__DOT__rs2_ID;
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rs2 
        = vlSelfRef.pipe_top__DOT__rs2_ID;
    vlSelfRef.pipe_top__DOT__alu_src_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src;
    vlSelfRef.pipe_top__DOT__mem_read_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__mem_read;
    vlSelfRef.pipe_top__DOT__mem_write_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__mem_write;
    vlSelfRef.pipe_top__DOT__reg_write_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write;
    vlSelfRef.pipe_top__DOT__wb_sel_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel;
    vlSelfRef.pipe_top__DOT__branch_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__branch;
    vlSelfRef.pipe_top__DOT__jump_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__jump;
    vlSelfRef.pipe_top__DOT__jalr_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__jalr;
    vlSelfRef.pipe_top__DOT__auipc_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__auipc;
    vlSelfRef.pipe_top__DOT__lui_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__lui;
    vlSelfRef.pipe_top__DOT__alu_op_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op;
    vlSelfRef.pipe_top__DOT__imm_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__alu_result_in 
        = vlSelfRef.pipe_top__DOT__alu_result_EX;
    vlSelfRef.pipe_top__DOT__alu_zero_EX = vlSelfRef.pipe_top__DOT__alu_inst__DOT__zero;
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rdata1 
        = ((0U == (IData)(vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rs1))
            ? 0U : vlSelfRef.pipe_top__DOT__regfile_inst__DOT__regs
           [vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rs1]);
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rdata2 
        = ((0U == (IData)(vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rs2))
            ? 0U : vlSelfRef.pipe_top__DOT__regfile_inst__DOT__regs
           [vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rs2]);
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__alu_src_in 
        = vlSelfRef.pipe_top__DOT__alu_src_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__mem_read_in 
        = vlSelfRef.pipe_top__DOT__mem_read_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__mem_write_in 
        = vlSelfRef.pipe_top__DOT__mem_write_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__reg_write_in 
        = vlSelfRef.pipe_top__DOT__reg_write_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__wb_sel_in 
        = vlSelfRef.pipe_top__DOT__wb_sel_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__branch_in 
        = vlSelfRef.pipe_top__DOT__branch_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__jump_in 
        = vlSelfRef.pipe_top__DOT__jump_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__jalr_in 
        = vlSelfRef.pipe_top__DOT__jalr_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__auipc_in 
        = vlSelfRef.pipe_top__DOT__auipc_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__lui_in 
        = vlSelfRef.pipe_top__DOT__lui_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__alu_op_in 
        = vlSelfRef.pipe_top__DOT__alu_op_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__imm_in 
        = vlSelfRef.pipe_top__DOT__imm_ID;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__alu_zero_in 
        = vlSelfRef.pipe_top__DOT__alu_zero_EX;
    vlSelfRef.pipe_top__DOT__branch_taken_EX = ((IData)(vlSelfRef.pipe_top__DOT__branch_EX) 
                                                & ((0U 
                                                    == (IData)(vlSelfRef.pipe_top__DOT__funct3_EX))
                                                    ? (IData)(vlSelfRef.pipe_top__DOT__alu_zero_EX)
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelfRef.pipe_top__DOT__funct3_EX))
                                                     ? 
                                                    (~ (IData)(vlSelfRef.pipe_top__DOT__alu_zero_EX))
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlSelfRef.pipe_top__DOT__funct3_EX))
                                                      ? vlSelfRef.pipe_top__DOT__alu_result_EX
                                                      : 
                                                     ((5U 
                                                       == (IData)(vlSelfRef.pipe_top__DOT__funct3_EX))
                                                       ? 
                                                      (~ vlSelfRef.pipe_top__DOT__alu_result_EX)
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlSelfRef.pipe_top__DOT__funct3_EX))
                                                        ? vlSelfRef.pipe_top__DOT__alu_result_EX
                                                        : 
                                                       (~ vlSelfRef.pipe_top__DOT__alu_result_EX)))))));
    vlSelfRef.pipe_top__DOT__rs1_data_ID = vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rdata1;
    vlSelfRef.pipe_top__DOT__rs2_data_ID = vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rdata2;
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__branch_taken 
        = vlSelfRef.pipe_top__DOT__branch_taken_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__branch_taken_in 
        = vlSelfRef.pipe_top__DOT__branch_taken_EX;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs1_data_in 
        = vlSelfRef.pipe_top__DOT__rs1_data_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs2_data_in 
        = vlSelfRef.pipe_top__DOT__rs2_data_ID;
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
                                                    (((((((IData)(vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__rst) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__mem_wb_inst__DOT__rst__0))) 
                                                         << 3U) 
                                                        | (((IData)(vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__mem_wb_inst__DOT__clk__0))) 
                                                           << 2U)) 
                                                       | ((((IData)(vlSelfRef.pipe_top__DOT__dmem_inst__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__dmem_inst__DOT__clk__0))) 
                                                           << 1U) 
                                                          | ((IData)(vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rst) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__ex_mem_inst__DOT__rst__0))))) 
                                                      << 8U) 
                                                     | (((((((IData)(vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__ex_mem_inst__DOT__clk__0))) 
                                                            << 3U) 
                                                           | (((IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rst) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__id_ex_inst__DOT__rst__0))) 
                                                              << 2U)) 
                                                          | ((((IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__id_ex_inst__DOT__clk__0))) 
                                                              << 1U) 
                                                             | ((IData)(vlSelfRef.pipe_top__DOT__regfile_inst__DOT__clk) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__regfile_inst__DOT__clk__0))))) 
                                                         << 4U) 
                                                        | (((((IData)(vlSelfRef.pipe_top__DOT__if_id_inst__DOT__rst) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__if_id_inst__DOT__rst__0))) 
                                                             << 3U) 
                                                            | (((IData)(vlSelfRef.pipe_top__DOT__if_id_inst__DOT__clk) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__if_id_inst__DOT__clk__0))) 
                                                               << 2U)) 
                                                           | ((((IData)(vlSelfRef.pipe_top__DOT__fetch_inst__DOT__rst) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__fetch_inst__DOT__rst__0))) 
                                                               << 1U) 
                                                              | ((IData)(vlSelfRef.pipe_top__DOT__fetch_inst__DOT__clk) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipe_top__DOT__fetch_inst__DOT__clk__0)))))))));
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
    IData/*31:0*/ __VdlyVal__pipe_top__DOT__dmem_inst__DOT__mem__v0;
    __VdlyVal__pipe_top__DOT__dmem_inst__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyDim0__pipe_top__DOT__dmem_inst__DOT__mem__v0;
    __VdlyDim0__pipe_top__DOT__dmem_inst__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__pipe_top__DOT__dmem_inst__DOT__mem__v0;
    __VdlySet__pipe_top__DOT__dmem_inst__DOT__mem__v0 = 0;
    // Body
    __VdlySet__pipe_top__DOT__dmem_inst__DOT__mem__v0 = 0U;
    if (vlSelfRef.pipe_top__DOT__dmem_inst__DOT__we) {
        __VdlyVal__pipe_top__DOT__dmem_inst__DOT__mem__v0 
            = vlSelfRef.pipe_top__DOT__dmem_inst__DOT__wd;
        __VdlyDim0__pipe_top__DOT__dmem_inst__DOT__mem__v0 
            = (0x000000ffU & (vlSelfRef.pipe_top__DOT__dmem_inst__DOT__addr 
                              >> 2U));
        __VdlySet__pipe_top__DOT__dmem_inst__DOT__mem__v0 = 1U;
    }
    if (__VdlySet__pipe_top__DOT__dmem_inst__DOT__mem__v0) {
        vlSelfRef.pipe_top__DOT__dmem_inst__DOT__mem[__VdlyDim0__pipe_top__DOT__dmem_inst__DOT__mem__v0] 
            = __VdlyVal__pipe_top__DOT__dmem_inst__DOT__mem__v0;
    }
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__pc_reg 
        = ((IData)(vlSelfRef.pipe_top__DOT__fetch_inst__DOT__rst)
            ? 0U : ((IData)(vlSelfRef.pipe_top__DOT__fetch_inst__DOT__branch_taken)
                     ? vlSelfRef.pipe_top__DOT__fetch_inst__DOT__branch_target
                     : ((IData)(vlSelfRef.pipe_top__DOT__fetch_inst__DOT__jump)
                         ? vlSelfRef.pipe_top__DOT__fetch_inst__DOT__jump_target
                         : ((IData)(4U) + vlSelfRef.pipe_top__DOT__fetch_inst__DOT__pc_reg))));
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__pc = vlSelfRef.pipe_top__DOT__fetch_inst__DOT__pc_reg;
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__addr 
        = vlSelfRef.pipe_top__DOT__fetch_inst__DOT__pc_reg;
    vlSelfRef.pipe_top__DOT__pc_IF = vlSelfRef.pipe_top__DOT__fetch_inst__DOT__pc;
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__instr 
        = vlSelfRef.pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__mem
        [(0x000000ffU & (vlSelfRef.pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__addr 
                         >> 2U))];
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__instr 
        = vlSelfRef.pipe_top__DOT__fetch_inst__DOT__u_imem__DOT__instr;
    vlSelfRef.pipe_top__DOT__instr_IF = vlSelfRef.pipe_top__DOT__fetch_inst__DOT__instr;
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdlyVal__pipe_top__DOT__regfile_inst__DOT__regs__v0;
    __VdlyVal__pipe_top__DOT__regfile_inst__DOT__regs__v0 = 0;
    CData/*4:0*/ __VdlyDim0__pipe_top__DOT__regfile_inst__DOT__regs__v0;
    __VdlyDim0__pipe_top__DOT__regfile_inst__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__pipe_top__DOT__regfile_inst__DOT__regs__v0;
    __VdlySet__pipe_top__DOT__regfile_inst__DOT__regs__v0 = 0;
    // Body
    __VdlySet__pipe_top__DOT__regfile_inst__DOT__regs__v0 = 0U;
    if (((IData)(vlSelfRef.pipe_top__DOT__regfile_inst__DOT__we) 
         & (0U != (IData)(vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rd)))) {
        __VdlyVal__pipe_top__DOT__regfile_inst__DOT__regs__v0 
            = vlSelfRef.pipe_top__DOT__regfile_inst__DOT__wdata;
        __VdlyDim0__pipe_top__DOT__regfile_inst__DOT__regs__v0 
            = vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rd;
        __VdlySet__pipe_top__DOT__regfile_inst__DOT__regs__v0 = 1U;
    }
    if (__VdlySet__pipe_top__DOT__regfile_inst__DOT__regs__v0) {
        vlSelfRef.pipe_top__DOT__regfile_inst__DOT__regs[__VdlyDim0__pipe_top__DOT__regfile_inst__DOT__regs__v0] 
            = __VdlyVal__pipe_top__DOT__regfile_inst__DOT__regs__v0;
    }
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.pipe_top__DOT__if_id_inst__DOT__rst) {
        vlSelfRef.pipe_top__DOT__if_id_inst__DOT__pc_out = 0U;
        vlSelfRef.pipe_top__DOT__if_id_inst__DOT__instr_out = 0U;
    } else {
        vlSelfRef.pipe_top__DOT__if_id_inst__DOT__pc_out 
            = vlSelfRef.pipe_top__DOT__if_id_inst__DOT__pc_in;
        vlSelfRef.pipe_top__DOT__if_id_inst__DOT__instr_out 
            = vlSelfRef.pipe_top__DOT__if_id_inst__DOT__instr_in;
    }
    vlSelfRef.pipe_top__DOT__pc_ID = vlSelfRef.pipe_top__DOT__if_id_inst__DOT__pc_out;
    vlSelfRef.pipe_top__DOT__instr_ID = vlSelfRef.pipe_top__DOT__if_id_inst__DOT__instr_out;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
        = vlSelfRef.pipe_top__DOT__instr_ID;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__rd 
        = (0x0000001fU & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                          >> 7U));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3 
        = (7U & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                 >> 0x0000000cU));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct7 
        = (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
           >> 0x00000019U);
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_b 
        = (((- (IData)((vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                        >> 0x0000001fU))) << 0x0000000dU) 
           | ((((2U & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                       >> 0x0000001eU)) | (1U & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                                 >> 7U))) 
               << 0x0000000bU) | ((0x000007e0U & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                                  >> 0x00000014U)) 
                                  | (0x0000001eU & 
                                     (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                      >> 7U)))));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_i 
        = (((- (IData)((vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                        >> 0x0000001fU))) << 0x0000000cU) 
           | (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
              >> 0x00000014U));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_j 
        = ((((0x00000ffeU & ((- (IData)((vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                         >> 0x0000001fU))) 
                             << 1U)) | (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                        >> 0x0000001fU)) 
            << 0x00000014U) | ((((0x000001feU & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                                 >> 0x0000000bU)) 
                                 | (1U & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                          >> 0x00000014U))) 
                                << 0x0000000bU) | (0x000007feU 
                                                   & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                                      >> 0x00000014U))));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_s 
        = (((- (IData)((vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                        >> 0x0000001fU))) << 0x0000000cU) 
           | ((0x00000fe0U & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                              >> 0x00000014U)) | (0x0000001fU 
                                                  & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                                                     >> 7U))));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_u 
        = (0xfffff000U & vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr);
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__rs1 
        = (0x0000001fU & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                          >> 0x0000000fU));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__rs2 
        = (0x0000001fU & (vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr 
                          >> 0x00000014U));
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode 
        = (0x0000007fU & vlSelfRef.pipe_top__DOT__decoder_inst__DOT__instr);
    vlSelfRef.pipe_top__DOT__rd_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__rd;
    vlSelfRef.pipe_top__DOT__rs1_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__rs1;
    vlSelfRef.pipe_top__DOT__rs2_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__rs2;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__mem_read = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__mem_write = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__branch = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__jump = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__jalr = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__auipc = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__lui = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                  >> 6U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                      >> 5U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__mem_read = 1U;
                            }
                        }
                    }
                }
            }
            if ((0x00000010U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__auipc = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x00000020U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__mem_write = 1U;
                            }
                        }
                    }
                }
            }
            if ((0x00000010U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__lui = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op = 0U;
    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm = 0U;
    if ((0x00000040U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
        if ((0x00000020U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 0U;
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__jalr = 1U;
                            }
                        }
                    } else if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 0U;
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__branch = 1U;
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op 
                                    = ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                        ? ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                            ? 9U : 8U)
                                        : 1U);
                            }
                        }
                    }
                }
                if ((8U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    if ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 1U;
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 2U;
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__jump = 1U;
                                vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                                    = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_j;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 1U;
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 2U;
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__jump = 1U;
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                                = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_i;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 0U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                            = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_b;
                    }
                }
            }
        }
    } else if ((0x00000020U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
        if ((0x00000010U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 1U;
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 1U;
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 0U;
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op = 0U;
                            vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                                = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_u;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 0U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 1U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 0U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op 
                            = ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                ? ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                    ? ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                        ? 2U : 3U) : 
                                   ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                     ? ((0x00000020U 
                                         & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct7))
                                         ? 7U : 6U)
                                     : 4U)) : ((2U 
                                                & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                                    ? 9U
                                                    : 8U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                                    ? 5U
                                                    : 
                                                   ((0x00000020U 
                                                     & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct7))
                                                     ? 1U
                                                     : 0U))));
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                             >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 1U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 0U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op = 0U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                            = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_s;
                    }
                }
            }
        }
    } else if ((0x00000010U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
        if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                      >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 1U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 1U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 0U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op = 0U;
                        vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                            = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_u;
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 1U;
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 1U;
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 0U;
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op 
                        = ((4U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                            ? ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                ? ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                    ? 2U : 3U) : ((1U 
                                                   & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                                   ? 
                                                  ((0x00000020U 
                                                    & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct7))
                                                    ? 7U
                                                    : 6U)
                                                   : 4U))
                            : ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                ? ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                    ? 9U : 8U) : ((1U 
                                                   & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__funct3))
                                                   ? 5U
                                                   : 0U)));
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                        = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_i;
                }
            }
        }
    } else if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                         >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.pipe_top__DOT__decoder_inst__DOT__opcode))) {
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src = 1U;
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write = 1U;
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel = 1U;
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op = 0U;
                    vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm 
                        = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm_i;
                }
            }
        }
    }
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rs1 
        = vlSelfRef.pipe_top__DOT__rs1_ID;
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rs2 
        = vlSelfRef.pipe_top__DOT__rs2_ID;
    vlSelfRef.pipe_top__DOT__alu_src_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_src;
    vlSelfRef.pipe_top__DOT__mem_read_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__mem_read;
    vlSelfRef.pipe_top__DOT__mem_write_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__mem_write;
    vlSelfRef.pipe_top__DOT__reg_write_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__reg_write;
    vlSelfRef.pipe_top__DOT__wb_sel_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__wb_sel;
    vlSelfRef.pipe_top__DOT__branch_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__branch;
    vlSelfRef.pipe_top__DOT__jump_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__jump;
    vlSelfRef.pipe_top__DOT__jalr_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__jalr;
    vlSelfRef.pipe_top__DOT__auipc_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__auipc;
    vlSelfRef.pipe_top__DOT__lui_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__lui;
    vlSelfRef.pipe_top__DOT__alu_op_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__alu_op;
    vlSelfRef.pipe_top__DOT__imm_ID = vlSelfRef.pipe_top__DOT__decoder_inst__DOT__imm;
}

void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__rst) {
        vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__rd_out = 0U;
        vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__alu_result_out = 0U;
        vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__mem_read_data_out = 0U;
        vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__pc_plus4_out = 0U;
        vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__wb_sel_out = 0U;
    } else {
        vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__rd_out 
            = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__rd_in;
        vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__alu_result_out 
            = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__alu_result_in;
        vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__mem_read_data_out 
            = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__mem_read_data_in;
        vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__pc_plus4_out 
            = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__pc_plus4_in;
        vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__wb_sel_out 
            = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__wb_sel_in;
    }
    vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__reg_write_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__reg_write_in));
    vlSelfRef.pipe_top__DOT__rd_WB = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__rd_out;
    vlSelfRef.pipe_top__DOT__reg_write_WB = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__reg_write_out;
    vlSelfRef.pipe_top__DOT__alu_result_WB = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__alu_result_out;
    vlSelfRef.pipe_top__DOT__mem_read_data_WB = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__mem_read_data_out;
    vlSelfRef.pipe_top__DOT__pc_plus4_WB = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__pc_plus4_out;
    vlSelfRef.pipe_top__DOT__wb_sel_WB = vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__wb_sel_out;
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rd 
        = vlSelfRef.pipe_top__DOT__rd_WB;
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__we 
        = vlSelfRef.pipe_top__DOT__reg_write_WB;
    vlSelfRef.pipe_top__DOT__writeback_data = ((0U 
                                                == (IData)(vlSelfRef.pipe_top__DOT__wb_sel_WB))
                                                ? vlSelfRef.pipe_top__DOT__alu_result_WB
                                                : (
                                                   (1U 
                                                    == (IData)(vlSelfRef.pipe_top__DOT__wb_sel_WB))
                                                    ? vlSelfRef.pipe_top__DOT__mem_read_data_WB
                                                    : vlSelfRef.pipe_top__DOT__pc_plus4_WB));
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__wdata 
        = vlSelfRef.pipe_top__DOT__writeback_data;
}

void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__alu_zero_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__alu_zero_in));
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__branch_taken_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__branch_taken_in));
    if (vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rst) {
        vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__jump_target_out = 0U;
        vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__branch_target_out = 0U;
        vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__wb_sel_out = 0U;
        vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rd_out = 0U;
        vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__pc_plus4_out = 0U;
        vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rs2_data_out = 0U;
        vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__alu_result_out = 0U;
    } else {
        vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__jump_target_out 
            = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__jump_target_in;
        vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__branch_target_out 
            = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__branch_target_in;
        vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__wb_sel_out 
            = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__wb_sel_in;
        vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rd_out 
            = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rd_in;
        vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__pc_plus4_out 
            = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__pc_plus4_in;
        vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rs2_data_out 
            = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rs2_data_in;
        vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__alu_result_out 
            = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__alu_result_in;
    }
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__mem_read_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__mem_read_in));
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__jump_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__jump_in));
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__reg_write_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__reg_write_in));
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__mem_write_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__mem_write_in));
    vlSelfRef.pipe_top__DOT__alu_zero_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__alu_zero_out;
    vlSelfRef.pipe_top__DOT__branch_taken_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__branch_taken_out;
    vlSelfRef.pipe_top__DOT__jump_target_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__jump_target_out;
    vlSelfRef.pipe_top__DOT__branch_target_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__branch_target_out;
    vlSelfRef.pipe_top__DOT__mem_read_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__mem_read_out;
    vlSelfRef.pipe_top__DOT__jump_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__jump_out;
    vlSelfRef.pipe_top__DOT__wb_sel_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__wb_sel_out;
    vlSelfRef.pipe_top__DOT__reg_write_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__reg_write_out;
    vlSelfRef.pipe_top__DOT__mem_write_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__mem_write_out;
    vlSelfRef.pipe_top__DOT__rd_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rd_out;
    vlSelfRef.pipe_top__DOT__pc_plus4_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__pc_plus4_out;
    vlSelfRef.pipe_top__DOT__rs2_data_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rs2_data_out;
    vlSelfRef.pipe_top__DOT__alu_result_MEM = vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__alu_result_out;
    vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__wb_sel_in 
        = vlSelfRef.pipe_top__DOT__wb_sel_MEM;
    vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__reg_write_in 
        = vlSelfRef.pipe_top__DOT__reg_write_MEM;
    vlSelfRef.pipe_top__DOT__dmem_inst__DOT__we = vlSelfRef.pipe_top__DOT__mem_write_MEM;
    vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__rd_in 
        = vlSelfRef.pipe_top__DOT__rd_MEM;
    vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__pc_plus4_in 
        = vlSelfRef.pipe_top__DOT__pc_plus4_MEM;
    vlSelfRef.pipe_top__DOT__dmem_inst__DOT__wd = vlSelfRef.pipe_top__DOT__rs2_data_MEM;
    vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__alu_result_in 
        = vlSelfRef.pipe_top__DOT__alu_result_MEM;
    vlSelfRef.pipe_top__DOT__dmem_inst__DOT__addr = vlSelfRef.pipe_top__DOT__alu_result_MEM;
}

void Vtop___024root___nba_sequent__TOP__6(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__6\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rst) {
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs2_out = 0U;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs1_out = 0U;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rd_out = 0U;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__wb_sel_out = 0U;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__funct3_out = 0U;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__alu_op_out = 0U;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs2_data_out = 0U;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs1_data_out = 0U;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__pc_out = 0U;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__imm_out = 0U;
    } else {
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs2_out 
            = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs2_in;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs1_out 
            = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs1_in;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rd_out 
            = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rd_in;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__wb_sel_out 
            = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__wb_sel_in;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__funct3_out 
            = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__funct3_in;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__alu_op_out 
            = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__alu_op_in;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs2_data_out 
            = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs2_data_in;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs1_data_out 
            = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs1_data_in;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__pc_out 
            = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__pc_in;
        vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__imm_out 
            = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__imm_in;
    }
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__reg_write_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__reg_write_in));
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__mem_write_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__mem_write_in));
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__mem_read_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__mem_read_in));
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__jump_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__jump_in));
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__branch_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__branch_in));
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__jalr_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__jalr_in));
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__auipc_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__auipc_in));
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__lui_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__lui_in));
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__alu_src_out 
        = ((1U & (~ (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rst))) 
           && (IData)(vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__alu_src_in));
    vlSelfRef.pipe_top__DOT__rs2_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs2_out;
    vlSelfRef.pipe_top__DOT__rs1_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs1_out;
    vlSelfRef.pipe_top__DOT__reg_write_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__reg_write_out;
    vlSelfRef.pipe_top__DOT__mem_write_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__mem_write_out;
    vlSelfRef.pipe_top__DOT__mem_read_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__mem_read_out;
    vlSelfRef.pipe_top__DOT__rd_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rd_out;
    vlSelfRef.pipe_top__DOT__wb_sel_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__wb_sel_out;
    vlSelfRef.pipe_top__DOT__jump_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__jump_out;
    vlSelfRef.pipe_top__DOT__branch_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__branch_out;
    vlSelfRef.pipe_top__DOT__jalr_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__jalr_out;
    vlSelfRef.pipe_top__DOT__funct3_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__funct3_out;
    vlSelfRef.pipe_top__DOT__alu_op_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__alu_op_out;
    vlSelfRef.pipe_top__DOT__auipc_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__auipc_out;
    vlSelfRef.pipe_top__DOT__lui_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__lui_out;
    vlSelfRef.pipe_top__DOT__alu_src_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__alu_src_out;
    vlSelfRef.pipe_top__DOT__rs2_data_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs2_data_out;
    vlSelfRef.pipe_top__DOT__rs1_data_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs1_data_out;
    vlSelfRef.pipe_top__DOT__pc_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__pc_out;
    vlSelfRef.pipe_top__DOT__imm_EX = vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__imm_out;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__reg_write_in 
        = vlSelfRef.pipe_top__DOT__reg_write_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__mem_write_in 
        = vlSelfRef.pipe_top__DOT__mem_write_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__mem_read_in 
        = vlSelfRef.pipe_top__DOT__mem_read_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rd_in 
        = vlSelfRef.pipe_top__DOT__rd_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__wb_sel_in 
        = vlSelfRef.pipe_top__DOT__wb_sel_EX;
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__jump 
        = vlSelfRef.pipe_top__DOT__jump_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__jump_in 
        = vlSelfRef.pipe_top__DOT__jump_EX;
    vlSelfRef.pipe_top__DOT__alu_inst__DOT__op = vlSelfRef.pipe_top__DOT__alu_op_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__rs2_data_in 
        = vlSelfRef.pipe_top__DOT__rs2_data_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__pc_plus4_in 
        = ((IData)(4U) + vlSelfRef.pipe_top__DOT__pc_EX);
    vlSelfRef.pipe_top__DOT__alu_inst__DOT__a = ((IData)(vlSelfRef.pipe_top__DOT__auipc_EX)
                                                  ? vlSelfRef.pipe_top__DOT__pc_EX
                                                  : 
                                                 ((IData)(vlSelfRef.pipe_top__DOT__lui_EX)
                                                   ? 0U
                                                   : vlSelfRef.pipe_top__DOT__rs1_data_EX));
    vlSelfRef.pipe_top__DOT__branch_target_EX = (vlSelfRef.pipe_top__DOT__imm_EX 
                                                 + vlSelfRef.pipe_top__DOT__pc_EX);
    vlSelfRef.pipe_top__DOT__alu_b_EX = ((IData)(vlSelfRef.pipe_top__DOT__alu_src_EX)
                                          ? vlSelfRef.pipe_top__DOT__imm_EX
                                          : vlSelfRef.pipe_top__DOT__rs2_data_EX);
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__branch_target 
        = vlSelfRef.pipe_top__DOT__branch_target_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__branch_target_in 
        = vlSelfRef.pipe_top__DOT__branch_target_EX;
    vlSelfRef.pipe_top__DOT__jump_target_EX = ((IData)(vlSelfRef.pipe_top__DOT__jalr_EX)
                                                ? (0xfffffffeU 
                                                   & (vlSelfRef.pipe_top__DOT__imm_EX 
                                                      + vlSelfRef.pipe_top__DOT__rs1_data_EX))
                                                : vlSelfRef.pipe_top__DOT__branch_target_EX);
    vlSelfRef.pipe_top__DOT__alu_inst__DOT__b = vlSelfRef.pipe_top__DOT__alu_b_EX;
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__jump_target 
        = vlSelfRef.pipe_top__DOT__jump_target_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__jump_target_in 
        = vlSelfRef.pipe_top__DOT__jump_target_EX;
    vlSelfRef.pipe_top__DOT__alu_inst__DOT__result 
        = ((8U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
            ? ((4U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                ? 0U : ((2U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                         ? 0U : ((1U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                                  ? ((vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                                      < vlSelfRef.pipe_top__DOT__alu_inst__DOT__b)
                                      ? 1U : 0U) : 
                                 (VL_LTS_III(32, vlSelfRef.pipe_top__DOT__alu_inst__DOT__a, vlSelfRef.pipe_top__DOT__alu_inst__DOT__b)
                                   ? 1U : 0U)))) : 
           ((4U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
             ? ((2U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                 ? ((1U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                     ? VL_SHIFTRS_III(32,32,5, vlSelfRef.pipe_top__DOT__alu_inst__DOT__a, 
                                      (0x0000001fU 
                                       & vlSelfRef.pipe_top__DOT__alu_inst__DOT__b))
                     : (vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                        >> (0x0000001fU & vlSelfRef.pipe_top__DOT__alu_inst__DOT__b)))
                 : ((1U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                     ? (vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                        << (0x0000001fU & vlSelfRef.pipe_top__DOT__alu_inst__DOT__b))
                     : (vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                        ^ vlSelfRef.pipe_top__DOT__alu_inst__DOT__b)))
             : ((2U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                 ? ((1U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                     ? (vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                        | vlSelfRef.pipe_top__DOT__alu_inst__DOT__b)
                     : (vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                        & vlSelfRef.pipe_top__DOT__alu_inst__DOT__b))
                 : ((1U & (IData)(vlSelfRef.pipe_top__DOT__alu_inst__DOT__op))
                     ? (vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                        - vlSelfRef.pipe_top__DOT__alu_inst__DOT__b)
                     : (vlSelfRef.pipe_top__DOT__alu_inst__DOT__a 
                        + vlSelfRef.pipe_top__DOT__alu_inst__DOT__b)))));
    vlSelfRef.pipe_top__DOT__alu_result_EX = vlSelfRef.pipe_top__DOT__alu_inst__DOT__result;
    vlSelfRef.pipe_top__DOT__alu_inst__DOT__zero = 
        (0U == vlSelfRef.pipe_top__DOT__alu_inst__DOT__result);
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__alu_result_in 
        = vlSelfRef.pipe_top__DOT__alu_result_EX;
    vlSelfRef.pipe_top__DOT__alu_zero_EX = vlSelfRef.pipe_top__DOT__alu_inst__DOT__zero;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__alu_zero_in 
        = vlSelfRef.pipe_top__DOT__alu_zero_EX;
    vlSelfRef.pipe_top__DOT__branch_taken_EX = ((IData)(vlSelfRef.pipe_top__DOT__branch_EX) 
                                                & ((0U 
                                                    == (IData)(vlSelfRef.pipe_top__DOT__funct3_EX))
                                                    ? (IData)(vlSelfRef.pipe_top__DOT__alu_zero_EX)
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelfRef.pipe_top__DOT__funct3_EX))
                                                     ? 
                                                    (~ (IData)(vlSelfRef.pipe_top__DOT__alu_zero_EX))
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlSelfRef.pipe_top__DOT__funct3_EX))
                                                      ? vlSelfRef.pipe_top__DOT__alu_result_EX
                                                      : 
                                                     ((5U 
                                                       == (IData)(vlSelfRef.pipe_top__DOT__funct3_EX))
                                                       ? 
                                                      (~ vlSelfRef.pipe_top__DOT__alu_result_EX)
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlSelfRef.pipe_top__DOT__funct3_EX))
                                                        ? vlSelfRef.pipe_top__DOT__alu_result_EX
                                                        : 
                                                       (~ vlSelfRef.pipe_top__DOT__alu_result_EX)))))));
    vlSelfRef.pipe_top__DOT__fetch_inst__DOT__branch_taken 
        = vlSelfRef.pipe_top__DOT__branch_taken_EX;
    vlSelfRef.pipe_top__DOT__ex_mem_inst__DOT__branch_taken_in 
        = vlSelfRef.pipe_top__DOT__branch_taken_EX;
}

void Vtop___024root___nba_sequent__TOP__7(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__7\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pipe_top__DOT__if_id_inst__DOT__pc_in 
        = vlSelfRef.pipe_top__DOT__pc_IF;
    vlSelfRef.pipe_top__DOT__if_id_inst__DOT__instr_in 
        = vlSelfRef.pipe_top__DOT__instr_IF;
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rdata1 
        = ((0U == (IData)(vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rs1))
            ? 0U : vlSelfRef.pipe_top__DOT__regfile_inst__DOT__regs
           [vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rs1]);
    vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rdata2 
        = ((0U == (IData)(vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rs2))
            ? 0U : vlSelfRef.pipe_top__DOT__regfile_inst__DOT__regs
           [vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rs2]);
    vlSelfRef.pipe_top__DOT__rs1_data_ID = vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rdata1;
    vlSelfRef.pipe_top__DOT__rs2_data_ID = vlSelfRef.pipe_top__DOT__regfile_inst__DOT__rdata2;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs1_data_in 
        = vlSelfRef.pipe_top__DOT__rs1_data_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs2_data_in 
        = vlSelfRef.pipe_top__DOT__rs2_data_ID;
}

void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pipe_top__DOT__dmem_inst__DOT__rd = vlSelfRef.pipe_top__DOT__dmem_inst__DOT__mem
        [(0x000000ffU & (vlSelfRef.pipe_top__DOT__dmem_inst__DOT__addr 
                         >> 2U))];
    vlSelfRef.pipe_top__DOT__mem_read_data = vlSelfRef.pipe_top__DOT__dmem_inst__DOT__rd;
    vlSelfRef.pipe_top__DOT__mem_wb_inst__DOT__mem_read_data_in 
        = vlSelfRef.pipe_top__DOT__mem_read_data;
}

void Vtop___024root___nba_sequent__TOP__8(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs2_in 
        = vlSelfRef.pipe_top__DOT__rs2_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rs1_in 
        = vlSelfRef.pipe_top__DOT__rs1_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__reg_write_in 
        = vlSelfRef.pipe_top__DOT__reg_write_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__mem_write_in 
        = vlSelfRef.pipe_top__DOT__mem_write_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__mem_read_in 
        = vlSelfRef.pipe_top__DOT__mem_read_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__rd_in 
        = vlSelfRef.pipe_top__DOT__rd_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__wb_sel_in 
        = vlSelfRef.pipe_top__DOT__wb_sel_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__jump_in 
        = vlSelfRef.pipe_top__DOT__jump_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__branch_in 
        = vlSelfRef.pipe_top__DOT__branch_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__jalr_in 
        = vlSelfRef.pipe_top__DOT__jalr_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__funct3_in 
        = (7U & (vlSelfRef.pipe_top__DOT__instr_ID 
                 >> 0x0000000cU));
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__alu_op_in 
        = vlSelfRef.pipe_top__DOT__alu_op_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__auipc_in 
        = vlSelfRef.pipe_top__DOT__auipc_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__lui_in 
        = vlSelfRef.pipe_top__DOT__lui_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__alu_src_in 
        = vlSelfRef.pipe_top__DOT__alu_src_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__pc_in 
        = vlSelfRef.pipe_top__DOT__pc_ID;
    vlSelfRef.pipe_top__DOT__id_ex_inst__DOT__imm_in 
        = vlSelfRef.pipe_top__DOT__imm_ID;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x0000000000000200ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x0000000000000c00ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((0x0000000000000180ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((0x0000000000000060ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__6(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__7(vlSelf);
    }
    if ((0x000000000000001cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x0000000000000380ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__8(vlSelf);
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
            VL_FATAL_MT("/home/ankur/workspace/BoseRV/riscv-core/src/pipe_top.v", 1, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/ankur/workspace/BoseRV/riscv-core/src/pipe_top.v", 1, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/ankur/workspace/BoseRV/riscv-core/src/pipe_top.v", 1, "", "Active region did not converge after 100 tries");
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
