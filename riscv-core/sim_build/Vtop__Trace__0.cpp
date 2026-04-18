// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst));
    bufp->chgBit(oldp+2,(vlSelfRef.top__DOT__clk));
    bufp->chgBit(oldp+3,(vlSelfRef.top__DOT__rst));
    bufp->chgIData(oldp+4,(vlSelfRef.top__DOT__pc),32);
    bufp->chgIData(oldp+5,(vlSelfRef.top__DOT__instr),32);
    bufp->chgCData(oldp+6,(vlSelfRef.top__DOT__rs1),5);
    bufp->chgCData(oldp+7,(vlSelfRef.top__DOT__rs2),5);
    bufp->chgCData(oldp+8,(vlSelfRef.top__DOT__rd),5);
    bufp->chgIData(oldp+9,(vlSelfRef.top__DOT__imm),32);
    bufp->chgCData(oldp+10,(vlSelfRef.top__DOT__alu_op),4);
    bufp->chgBit(oldp+11,(vlSelfRef.top__DOT__alu_src));
    bufp->chgBit(oldp+12,(vlSelfRef.top__DOT__mem_read));
    bufp->chgBit(oldp+13,(vlSelfRef.top__DOT__mem_write));
    bufp->chgBit(oldp+14,(vlSelfRef.top__DOT__reg_write));
    bufp->chgBit(oldp+15,(vlSelfRef.top__DOT__branch));
    bufp->chgBit(oldp+16,(vlSelfRef.top__DOT__jump));
    bufp->chgBit(oldp+17,(vlSelfRef.top__DOT__jalr));
    bufp->chgCData(oldp+18,(vlSelfRef.top__DOT__wb_sel),2);
    bufp->chgIData(oldp+19,(vlSelfRef.top__DOT__rs1_data),32);
    bufp->chgIData(oldp+20,(vlSelfRef.top__DOT__rs2_data),32);
    bufp->chgIData(oldp+21,(vlSelfRef.top__DOT__alu_result),32);
    bufp->chgBit(oldp+22,(vlSelfRef.top__DOT__alu_zero));
    bufp->chgIData(oldp+23,(vlSelfRef.top__DOT__mem_read_data),32);
    bufp->chgIData(oldp+24,(vlSelfRef.top__DOT__alu_b_in),32);
    bufp->chgIData(oldp+25,(vlSelfRef.top__DOT__writeback_data),32);
    bufp->chgBit(oldp+26,(vlSelfRef.top__DOT__branch_taken));
    bufp->chgIData(oldp+27,(vlSelfRef.top__DOT__branch_target),32);
    bufp->chgIData(oldp+28,(vlSelfRef.top__DOT__jump_target),32);
    bufp->chgBit(oldp+29,(vlSelfRef.top__DOT__auipc));
    bufp->chgBit(oldp+30,(vlSelfRef.top__DOT__lui));
    bufp->chgCData(oldp+31,(vlSelfRef.top__DOT__funct3),3);
    bufp->chgIData(oldp+32,(vlSelfRef.top__DOT__alu_inst__DOT__a),32);
    bufp->chgIData(oldp+33,(vlSelfRef.top__DOT__alu_inst__DOT__b),32);
    bufp->chgCData(oldp+34,(vlSelfRef.top__DOT__alu_inst__DOT__op),4);
    bufp->chgIData(oldp+35,(vlSelfRef.top__DOT__alu_inst__DOT__result),32);
    bufp->chgBit(oldp+36,(vlSelfRef.top__DOT__alu_inst__DOT__zero));
    bufp->chgIData(oldp+37,(vlSelfRef.top__DOT__decoder_inst__DOT__instr),32);
    bufp->chgCData(oldp+38,(vlSelfRef.top__DOT__decoder_inst__DOT__rs1),5);
    bufp->chgCData(oldp+39,(vlSelfRef.top__DOT__decoder_inst__DOT__rs2),5);
    bufp->chgCData(oldp+40,(vlSelfRef.top__DOT__decoder_inst__DOT__rd),5);
    bufp->chgIData(oldp+41,(vlSelfRef.top__DOT__decoder_inst__DOT__imm),32);
    bufp->chgCData(oldp+42,(vlSelfRef.top__DOT__decoder_inst__DOT__alu_op),4);
    bufp->chgBit(oldp+43,(vlSelfRef.top__DOT__decoder_inst__DOT__alu_src));
    bufp->chgBit(oldp+44,(vlSelfRef.top__DOT__decoder_inst__DOT__mem_read));
    bufp->chgBit(oldp+45,(vlSelfRef.top__DOT__decoder_inst__DOT__mem_write));
    bufp->chgBit(oldp+46,(vlSelfRef.top__DOT__decoder_inst__DOT__reg_write));
    bufp->chgCData(oldp+47,(vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel),2);
    bufp->chgBit(oldp+48,(vlSelfRef.top__DOT__decoder_inst__DOT__branch));
    bufp->chgBit(oldp+49,(vlSelfRef.top__DOT__decoder_inst__DOT__jump));
    bufp->chgBit(oldp+50,(vlSelfRef.top__DOT__decoder_inst__DOT__jalr));
    bufp->chgBit(oldp+51,(vlSelfRef.top__DOT__decoder_inst__DOT__auipc));
    bufp->chgBit(oldp+52,(vlSelfRef.top__DOT__decoder_inst__DOT__lui));
    bufp->chgCData(oldp+53,(vlSelfRef.top__DOT__decoder_inst__DOT__opcode),7);
    bufp->chgCData(oldp+54,(vlSelfRef.top__DOT__decoder_inst__DOT__funct3),3);
    bufp->chgCData(oldp+55,(vlSelfRef.top__DOT__decoder_inst__DOT__funct7),7);
    bufp->chgIData(oldp+56,(vlSelfRef.top__DOT__decoder_inst__DOT__imm_i),32);
    bufp->chgIData(oldp+57,(vlSelfRef.top__DOT__decoder_inst__DOT__imm_s),32);
    bufp->chgIData(oldp+58,(vlSelfRef.top__DOT__decoder_inst__DOT__imm_b),32);
    bufp->chgIData(oldp+59,(vlSelfRef.top__DOT__decoder_inst__DOT__imm_u),32);
    bufp->chgIData(oldp+60,(vlSelfRef.top__DOT__decoder_inst__DOT__imm_j),32);
    bufp->chgBit(oldp+61,(vlSelfRef.top__DOT__dmem_inst__DOT__clk));
    bufp->chgBit(oldp+62,(vlSelfRef.top__DOT__dmem_inst__DOT__we));
    bufp->chgIData(oldp+63,(vlSelfRef.top__DOT__dmem_inst__DOT__addr),32);
    bufp->chgIData(oldp+64,(vlSelfRef.top__DOT__dmem_inst__DOT__wd),32);
    bufp->chgIData(oldp+65,(vlSelfRef.top__DOT__dmem_inst__DOT__rd),32);
    bufp->chgBit(oldp+66,(vlSelfRef.top__DOT__fetch_inst__DOT__clk));
    bufp->chgBit(oldp+67,(vlSelfRef.top__DOT__fetch_inst__DOT__rst));
    bufp->chgBit(oldp+68,(vlSelfRef.top__DOT__fetch_inst__DOT__branch_taken));
    bufp->chgBit(oldp+69,(vlSelfRef.top__DOT__fetch_inst__DOT__jump));
    bufp->chgIData(oldp+70,(vlSelfRef.top__DOT__fetch_inst__DOT__branch_target),32);
    bufp->chgIData(oldp+71,(vlSelfRef.top__DOT__fetch_inst__DOT__jump_target),32);
    bufp->chgIData(oldp+72,(vlSelfRef.top__DOT__fetch_inst__DOT__pc),32);
    bufp->chgIData(oldp+73,(vlSelfRef.top__DOT__fetch_inst__DOT__instr),32);
    bufp->chgIData(oldp+74,(vlSelfRef.top__DOT__fetch_inst__DOT__pc_reg),32);
    bufp->chgIData(oldp+75,(vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__addr),32);
    bufp->chgIData(oldp+76,(vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__instr),32);
    bufp->chgBit(oldp+77,(vlSelfRef.top__DOT__regfile_inst__DOT__clk));
    bufp->chgBit(oldp+78,(vlSelfRef.top__DOT__regfile_inst__DOT__we));
    bufp->chgCData(oldp+79,(vlSelfRef.top__DOT__regfile_inst__DOT__rs1),5);
    bufp->chgCData(oldp+80,(vlSelfRef.top__DOT__regfile_inst__DOT__rs2),5);
    bufp->chgCData(oldp+81,(vlSelfRef.top__DOT__regfile_inst__DOT__rd),5);
    bufp->chgIData(oldp+82,(vlSelfRef.top__DOT__regfile_inst__DOT__wdata),32);
    bufp->chgIData(oldp+83,(vlSelfRef.top__DOT__regfile_inst__DOT__rdata1),32);
    bufp->chgIData(oldp+84,(vlSelfRef.top__DOT__regfile_inst__DOT__rdata2),32);
    bufp->chgIData(oldp+85,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[0]),32);
    bufp->chgIData(oldp+86,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[1]),32);
    bufp->chgIData(oldp+87,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[2]),32);
    bufp->chgIData(oldp+88,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[3]),32);
    bufp->chgIData(oldp+89,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[4]),32);
    bufp->chgIData(oldp+90,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[5]),32);
    bufp->chgIData(oldp+91,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[6]),32);
    bufp->chgIData(oldp+92,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[7]),32);
    bufp->chgIData(oldp+93,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[8]),32);
    bufp->chgIData(oldp+94,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[9]),32);
    bufp->chgIData(oldp+95,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[10]),32);
    bufp->chgIData(oldp+96,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[11]),32);
    bufp->chgIData(oldp+97,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[12]),32);
    bufp->chgIData(oldp+98,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[13]),32);
    bufp->chgIData(oldp+99,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[14]),32);
    bufp->chgIData(oldp+100,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[15]),32);
    bufp->chgIData(oldp+101,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[16]),32);
    bufp->chgIData(oldp+102,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[17]),32);
    bufp->chgIData(oldp+103,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[18]),32);
    bufp->chgIData(oldp+104,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[19]),32);
    bufp->chgIData(oldp+105,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[20]),32);
    bufp->chgIData(oldp+106,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[21]),32);
    bufp->chgIData(oldp+107,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[22]),32);
    bufp->chgIData(oldp+108,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[23]),32);
    bufp->chgIData(oldp+109,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[24]),32);
    bufp->chgIData(oldp+110,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[25]),32);
    bufp->chgIData(oldp+111,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[26]),32);
    bufp->chgIData(oldp+112,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[27]),32);
    bufp->chgIData(oldp+113,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[28]),32);
    bufp->chgIData(oldp+114,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[29]),32);
    bufp->chgIData(oldp+115,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[30]),32);
    bufp->chgIData(oldp+116,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[31]),32);
    bufp->chgIData(oldp+117,(vlSelfRef.top__DOT__regfile_inst__DOT__i),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
