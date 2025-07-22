// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vnpc__Syms.h"


VL_ATTR_COLD void Vnpc___024root__trace_init_sub__TOP__0(Vnpc___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_init_sub__TOP__0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+41,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+43,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("npc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+41,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+43,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+47,0,"next_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+49,0,"src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+51,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+64,0,"reg_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+3,0,"is_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"is_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"is_J",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+53,0,"imm_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"imm_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+55,0,"imm_J",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+56,0,"is_auipc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"is_lui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"is_jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"is_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"is_addi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+5,0,"hot_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+60,0,"hot_funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("pc_4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+65,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+66,0,"RESET_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+41,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+47,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+64,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+49,0,"src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"next_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"result_auipc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"result_lui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+62,0,"result_jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+62,0,"result_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"result_addi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_decoder3_8", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+48,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+60,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_decoder7_128", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+46,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declArray(c+5,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_regfile2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+67,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+65,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+41,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+64,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+44,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+49,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+9+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vnpc___024root__trace_init_top(Vnpc___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_init_top\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vnpc___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vnpc___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vnpc___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vnpc___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vnpc___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vnpc___024root__trace_register(Vnpc___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_register\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vnpc___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vnpc___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vnpc___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vnpc___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vnpc___024root__trace_const_0_sub_0(Vnpc___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vnpc___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_const_0\n"); );
    // Init
    Vnpc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vnpc___024root*>(voidSelf);
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vnpc___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vnpc___024root__trace_const_0_sub_0(Vnpc___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_const_0_sub_0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+64,(1U));
    bufp->fullIData(oldp+65,(0x20U),32);
    bufp->fullIData(oldp+66,(0x80000000U),32);
    bufp->fullIData(oldp+67,(5U),32);
}

VL_ATTR_COLD void Vnpc___024root__trace_full_0_sub_0(Vnpc___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vnpc___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_full_0\n"); );
    // Init
    Vnpc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vnpc___024root*>(voidSelf);
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vnpc___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vnpc___024root__trace_full_0_sub_0(Vnpc___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_full_0_sub_0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelfRef.npc__DOT__imm),32);
    bufp->fullIData(oldp+2,(vlSelfRef.npc__DOT__alu_op),32);
    bufp->fullBit(oldp+3,(vlSelfRef.npc__DOT__is_I));
    bufp->fullBit(oldp+4,(vlSelfRef.npc__DOT__is_U));
    bufp->fullWData(oldp+5,(vlSelfRef.npc__DOT__hot_opcode),128);
    bufp->fullIData(oldp+9,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[0]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[1]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[2]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[3]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[4]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[5]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[6]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[7]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[8]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[9]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[10]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[11]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[12]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[13]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[14]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[15]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[16]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[17]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[18]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[19]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[20]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[21]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[22]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[23]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[24]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[25]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[26]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[27]),32);
    bufp->fullIData(oldp+37,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[28]),32);
    bufp->fullIData(oldp+38,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[29]),32);
    bufp->fullIData(oldp+39,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[30]),32);
    bufp->fullIData(oldp+40,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[31]),32);
    bufp->fullBit(oldp+41,(vlSelfRef.clk));
    bufp->fullBit(oldp+42,(vlSelfRef.rst));
    bufp->fullIData(oldp+43,(vlSelfRef.inst),32);
    bufp->fullIData(oldp+44,(vlSelfRef.alu_result),32);
    bufp->fullIData(oldp+45,(vlSelfRef.pc),32);
    bufp->fullCData(oldp+46,((0x7fU & vlSelfRef.inst)),7);
    bufp->fullIData(oldp+47,(((4U & vlSelfRef.npc__DOT__alu_op)
                               ? vlSelfRef.npc__DOT__u_alu__DOT__result_auipc
                               : ((8U & vlSelfRef.npc__DOT__alu_op)
                                   ? (0xfffffffeU & vlSelfRef.npc__DOT__u_alu__DOT__result_addi)
                                   : ((IData)(4U) + vlSelfRef.pc)))),32);
    bufp->fullCData(oldp+48,((7U & (vlSelfRef.inst 
                                    >> 0xcU))),3);
    bufp->fullIData(oldp+49,(((0U == (0x1fU & (vlSelfRef.inst 
                                               >> 0xfU)))
                               ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                              [(0x1fU & (vlSelfRef.inst 
                                         >> 0xfU))])),32);
    bufp->fullCData(oldp+50,((0x1fU & (vlSelfRef.inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+51,((0x1fU & (vlSelfRef.inst 
                                       >> 7U))),5);
    bufp->fullBit(oldp+52,((0x6fU == (0x7fU & vlSelfRef.inst))));
    bufp->fullIData(oldp+53,((((- (IData)((vlSelfRef.inst 
                                           >> 0x1fU))) 
                               << 0xcU) | (vlSelfRef.inst 
                                           >> 0x14U))),32);
    bufp->fullIData(oldp+54,((0xfffff000U & vlSelfRef.inst)),32);
    bufp->fullIData(oldp+55,(((((- (IData)((vlSelfRef.inst 
                                            >> 0x1fU))) 
                                << 0x15U) | (0x100000U 
                                             & (vlSelfRef.inst 
                                                >> 0xbU))) 
                              | (((0xff000U & vlSelfRef.inst) 
                                  | (0x800U & (vlSelfRef.inst 
                                               >> 9U))) 
                                 | (0x7feU & (vlSelfRef.inst 
                                              >> 0x14U))))),32);
    bufp->fullBit(oldp+56,(((IData)(vlSelfRef.npc__DOT__is_U) 
                            & (0x17U == (0x7fU & vlSelfRef.inst)))));
    bufp->fullBit(oldp+57,(((IData)(vlSelfRef.npc__DOT__is_U) 
                            & (0x37U == (0x7fU & vlSelfRef.inst)))));
    bufp->fullBit(oldp+58,(((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_5) 
                            & (0x67U == (0x7fU & vlSelfRef.inst)))));
    bufp->fullBit(oldp+59,(((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_5) 
                            & (0x13U == (0x7fU & vlSelfRef.inst)))));
    bufp->fullCData(oldp+60,((((((7U == (7U & (vlSelfRef.inst 
                                               >> 0xcU))) 
                                 << 7U) | ((6U == (7U 
                                                   & (vlSelfRef.inst 
                                                      >> 0xcU))) 
                                           << 6U)) 
                               | (((5U == (7U & (vlSelfRef.inst 
                                                 >> 0xcU))) 
                                   << 5U) | ((4U == 
                                              (7U & 
                                               (vlSelfRef.inst 
                                                >> 0xcU))) 
                                             << 4U))) 
                              | ((((3U == (7U & (vlSelfRef.inst 
                                                 >> 0xcU))) 
                                   << 3U) | ((2U == 
                                              (7U & 
                                               (vlSelfRef.inst 
                                                >> 0xcU))) 
                                             << 2U)) 
                                 | (((1U == (7U & (vlSelfRef.inst 
                                                   >> 0xcU))) 
                                     << 1U) | (0U == 
                                               (7U 
                                                & (vlSelfRef.inst 
                                                   >> 0xcU))))))),8);
    bufp->fullIData(oldp+61,(vlSelfRef.npc__DOT__u_alu__DOT__result_auipc),32);
    bufp->fullIData(oldp+62,(((IData)(4U) + vlSelfRef.pc)),32);
    bufp->fullIData(oldp+63,(vlSelfRef.npc__DOT__u_alu__DOT__result_addi),32);
}
