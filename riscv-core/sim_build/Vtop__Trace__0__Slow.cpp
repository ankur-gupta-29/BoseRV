// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+3,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"instr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+8,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+9,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+10,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+12,0,"alu_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"mem_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"mem_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"reg_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+16,0,"wb_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+17,0,"branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"auipc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"lui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+22,0,"rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,0,"rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"alu_b_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+26,0,"alu_zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"mem_read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"writeback_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+29,0,"branch_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"branch_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"jump_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->pushPrefix("alu_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+33,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+34,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+36,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+37,0,"zero",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("decoder_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+38,0,"instr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+40,0,"rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+41,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+42,0,"imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"alu_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+44,0,"alu_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"mem_read",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"mem_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"reg_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"wb_sel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+49,0,"branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"jump",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"jalr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"auipc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"lui",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+54,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+55,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+56,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+57,0,"imm_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+58,0,"imm_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"imm_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+60,0,"imm_u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"imm_j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+119,0,"OP_LOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+120,0,"OP_STORE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+121,0,"OP_IMM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+122,0,"OP_REG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+123,0,"OP_BRANCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+124,0,"OP_LUI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+125,0,"OP_AUIPC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+126,0,"OP_JAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+127,0,"OP_JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->pushPrefix("dmem_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+62,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+65,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+66,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("fetch_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+67,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"branch_taken",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"jump",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+71,0,"branch_target",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"jump_target",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+73,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"pc_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_imem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+76,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("regfile_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+78,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+80,0,"rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+81,0,"rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+82,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+83,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+86+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+118,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullCData(oldp+119,(3U),7);
    bufp->fullCData(oldp+120,(0x23U),7);
    bufp->fullCData(oldp+121,(0x13U),7);
    bufp->fullCData(oldp+122,(0x33U),7);
    bufp->fullCData(oldp+123,(0x63U),7);
    bufp->fullCData(oldp+124,(0x37U),7);
    bufp->fullCData(oldp+125,(0x17U),7);
    bufp->fullCData(oldp+126,(0x6fU),7);
    bufp->fullCData(oldp+127,(0x67U),7);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+1,(vlSelfRef.clk));
    bufp->fullBit(oldp+2,(vlSelfRef.rst));
    bufp->fullBit(oldp+3,(vlSelfRef.top__DOT__clk));
    bufp->fullBit(oldp+4,(vlSelfRef.top__DOT__rst));
    bufp->fullIData(oldp+5,(vlSelfRef.top__DOT__pc),32);
    bufp->fullIData(oldp+6,(vlSelfRef.top__DOT__instr),32);
    bufp->fullCData(oldp+7,(vlSelfRef.top__DOT__rs1),5);
    bufp->fullCData(oldp+8,(vlSelfRef.top__DOT__rs2),5);
    bufp->fullCData(oldp+9,(vlSelfRef.top__DOT__rd),5);
    bufp->fullIData(oldp+10,(vlSelfRef.top__DOT__imm),32);
    bufp->fullCData(oldp+11,(vlSelfRef.top__DOT__alu_op),4);
    bufp->fullBit(oldp+12,(vlSelfRef.top__DOT__alu_src));
    bufp->fullBit(oldp+13,(vlSelfRef.top__DOT__mem_read));
    bufp->fullBit(oldp+14,(vlSelfRef.top__DOT__mem_write));
    bufp->fullBit(oldp+15,(vlSelfRef.top__DOT__reg_write));
    bufp->fullCData(oldp+16,(vlSelfRef.top__DOT__wb_sel),2);
    bufp->fullBit(oldp+17,(vlSelfRef.top__DOT__branch));
    bufp->fullBit(oldp+18,(vlSelfRef.top__DOT__jump));
    bufp->fullBit(oldp+19,(vlSelfRef.top__DOT__jalr));
    bufp->fullBit(oldp+20,(vlSelfRef.top__DOT__auipc));
    bufp->fullBit(oldp+21,(vlSelfRef.top__DOT__lui));
    bufp->fullIData(oldp+22,(vlSelfRef.top__DOT__rs1_data),32);
    bufp->fullIData(oldp+23,(vlSelfRef.top__DOT__rs2_data),32);
    bufp->fullIData(oldp+24,(vlSelfRef.top__DOT__alu_b_in),32);
    bufp->fullIData(oldp+25,(vlSelfRef.top__DOT__alu_result),32);
    bufp->fullBit(oldp+26,(vlSelfRef.top__DOT__alu_zero));
    bufp->fullIData(oldp+27,(vlSelfRef.top__DOT__mem_read_data),32);
    bufp->fullIData(oldp+28,(vlSelfRef.top__DOT__writeback_data),32);
    bufp->fullBit(oldp+29,(vlSelfRef.top__DOT__branch_taken));
    bufp->fullIData(oldp+30,(vlSelfRef.top__DOT__branch_target),32);
    bufp->fullIData(oldp+31,(vlSelfRef.top__DOT__jump_target),32);
    bufp->fullCData(oldp+32,(vlSelfRef.top__DOT__funct3),3);
    bufp->fullIData(oldp+33,(vlSelfRef.top__DOT__alu_inst__DOT__a),32);
    bufp->fullIData(oldp+34,(vlSelfRef.top__DOT__alu_inst__DOT__b),32);
    bufp->fullCData(oldp+35,(vlSelfRef.top__DOT__alu_inst__DOT__op),4);
    bufp->fullIData(oldp+36,(vlSelfRef.top__DOT__alu_inst__DOT__result),32);
    bufp->fullBit(oldp+37,(vlSelfRef.top__DOT__alu_inst__DOT__zero));
    bufp->fullIData(oldp+38,(vlSelfRef.top__DOT__decoder_inst__DOT__instr),32);
    bufp->fullCData(oldp+39,(vlSelfRef.top__DOT__decoder_inst__DOT__rs1),5);
    bufp->fullCData(oldp+40,(vlSelfRef.top__DOT__decoder_inst__DOT__rs2),5);
    bufp->fullCData(oldp+41,(vlSelfRef.top__DOT__decoder_inst__DOT__rd),5);
    bufp->fullIData(oldp+42,(vlSelfRef.top__DOT__decoder_inst__DOT__imm),32);
    bufp->fullCData(oldp+43,(vlSelfRef.top__DOT__decoder_inst__DOT__alu_op),4);
    bufp->fullBit(oldp+44,(vlSelfRef.top__DOT__decoder_inst__DOT__alu_src));
    bufp->fullBit(oldp+45,(vlSelfRef.top__DOT__decoder_inst__DOT__mem_read));
    bufp->fullBit(oldp+46,(vlSelfRef.top__DOT__decoder_inst__DOT__mem_write));
    bufp->fullBit(oldp+47,(vlSelfRef.top__DOT__decoder_inst__DOT__reg_write));
    bufp->fullCData(oldp+48,(vlSelfRef.top__DOT__decoder_inst__DOT__wb_sel),2);
    bufp->fullBit(oldp+49,(vlSelfRef.top__DOT__decoder_inst__DOT__branch));
    bufp->fullBit(oldp+50,(vlSelfRef.top__DOT__decoder_inst__DOT__jump));
    bufp->fullBit(oldp+51,(vlSelfRef.top__DOT__decoder_inst__DOT__jalr));
    bufp->fullBit(oldp+52,(vlSelfRef.top__DOT__decoder_inst__DOT__auipc));
    bufp->fullBit(oldp+53,(vlSelfRef.top__DOT__decoder_inst__DOT__lui));
    bufp->fullCData(oldp+54,(vlSelfRef.top__DOT__decoder_inst__DOT__opcode),7);
    bufp->fullCData(oldp+55,(vlSelfRef.top__DOT__decoder_inst__DOT__funct3),3);
    bufp->fullCData(oldp+56,(vlSelfRef.top__DOT__decoder_inst__DOT__funct7),7);
    bufp->fullIData(oldp+57,(vlSelfRef.top__DOT__decoder_inst__DOT__imm_i),32);
    bufp->fullIData(oldp+58,(vlSelfRef.top__DOT__decoder_inst__DOT__imm_s),32);
    bufp->fullIData(oldp+59,(vlSelfRef.top__DOT__decoder_inst__DOT__imm_b),32);
    bufp->fullIData(oldp+60,(vlSelfRef.top__DOT__decoder_inst__DOT__imm_u),32);
    bufp->fullIData(oldp+61,(vlSelfRef.top__DOT__decoder_inst__DOT__imm_j),32);
    bufp->fullBit(oldp+62,(vlSelfRef.top__DOT__dmem_inst__DOT__clk));
    bufp->fullBit(oldp+63,(vlSelfRef.top__DOT__dmem_inst__DOT__we));
    bufp->fullIData(oldp+64,(vlSelfRef.top__DOT__dmem_inst__DOT__addr),32);
    bufp->fullIData(oldp+65,(vlSelfRef.top__DOT__dmem_inst__DOT__wd),32);
    bufp->fullIData(oldp+66,(vlSelfRef.top__DOT__dmem_inst__DOT__rd),32);
    bufp->fullBit(oldp+67,(vlSelfRef.top__DOT__fetch_inst__DOT__clk));
    bufp->fullBit(oldp+68,(vlSelfRef.top__DOT__fetch_inst__DOT__rst));
    bufp->fullBit(oldp+69,(vlSelfRef.top__DOT__fetch_inst__DOT__branch_taken));
    bufp->fullBit(oldp+70,(vlSelfRef.top__DOT__fetch_inst__DOT__jump));
    bufp->fullIData(oldp+71,(vlSelfRef.top__DOT__fetch_inst__DOT__branch_target),32);
    bufp->fullIData(oldp+72,(vlSelfRef.top__DOT__fetch_inst__DOT__jump_target),32);
    bufp->fullIData(oldp+73,(vlSelfRef.top__DOT__fetch_inst__DOT__pc),32);
    bufp->fullIData(oldp+74,(vlSelfRef.top__DOT__fetch_inst__DOT__instr),32);
    bufp->fullIData(oldp+75,(vlSelfRef.top__DOT__fetch_inst__DOT__pc_reg),32);
    bufp->fullIData(oldp+76,(vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__addr),32);
    bufp->fullIData(oldp+77,(vlSelfRef.top__DOT__fetch_inst__DOT__u_imem__DOT__instr),32);
    bufp->fullBit(oldp+78,(vlSelfRef.top__DOT__regfile_inst__DOT__clk));
    bufp->fullBit(oldp+79,(vlSelfRef.top__DOT__regfile_inst__DOT__we));
    bufp->fullCData(oldp+80,(vlSelfRef.top__DOT__regfile_inst__DOT__rs1),5);
    bufp->fullCData(oldp+81,(vlSelfRef.top__DOT__regfile_inst__DOT__rs2),5);
    bufp->fullCData(oldp+82,(vlSelfRef.top__DOT__regfile_inst__DOT__rd),5);
    bufp->fullIData(oldp+83,(vlSelfRef.top__DOT__regfile_inst__DOT__wdata),32);
    bufp->fullIData(oldp+84,(vlSelfRef.top__DOT__regfile_inst__DOT__rdata1),32);
    bufp->fullIData(oldp+85,(vlSelfRef.top__DOT__regfile_inst__DOT__rdata2),32);
    bufp->fullIData(oldp+86,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[0]),32);
    bufp->fullIData(oldp+87,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[1]),32);
    bufp->fullIData(oldp+88,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[2]),32);
    bufp->fullIData(oldp+89,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[3]),32);
    bufp->fullIData(oldp+90,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[4]),32);
    bufp->fullIData(oldp+91,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[5]),32);
    bufp->fullIData(oldp+92,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[6]),32);
    bufp->fullIData(oldp+93,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[7]),32);
    bufp->fullIData(oldp+94,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[8]),32);
    bufp->fullIData(oldp+95,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[9]),32);
    bufp->fullIData(oldp+96,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[10]),32);
    bufp->fullIData(oldp+97,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[11]),32);
    bufp->fullIData(oldp+98,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[12]),32);
    bufp->fullIData(oldp+99,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[13]),32);
    bufp->fullIData(oldp+100,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[14]),32);
    bufp->fullIData(oldp+101,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[15]),32);
    bufp->fullIData(oldp+102,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[16]),32);
    bufp->fullIData(oldp+103,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[17]),32);
    bufp->fullIData(oldp+104,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[18]),32);
    bufp->fullIData(oldp+105,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[19]),32);
    bufp->fullIData(oldp+106,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[20]),32);
    bufp->fullIData(oldp+107,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[21]),32);
    bufp->fullIData(oldp+108,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[22]),32);
    bufp->fullIData(oldp+109,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[23]),32);
    bufp->fullIData(oldp+110,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[24]),32);
    bufp->fullIData(oldp+111,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[25]),32);
    bufp->fullIData(oldp+112,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[26]),32);
    bufp->fullIData(oldp+113,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[27]),32);
    bufp->fullIData(oldp+114,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[28]),32);
    bufp->fullIData(oldp+115,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[29]),32);
    bufp->fullIData(oldp+116,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[30]),32);
    bufp->fullIData(oldp+117,(vlSelfRef.top__DOT__regfile_inst__DOT__regs[31]),32);
    bufp->fullIData(oldp+118,(vlSelfRef.top__DOT__regfile_inst__DOT__i),32);
}
