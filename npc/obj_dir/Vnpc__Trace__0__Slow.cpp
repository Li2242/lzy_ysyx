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
    tracep->declBit(c+69,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+71,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+73,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("npc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+69,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+71,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+73,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"src2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+76,0,"reg_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("pc_4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+82,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"RESET_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+69,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+77,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+73,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+84,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+74,0,"imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"src2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_decoder", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+69,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+71,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"src1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"src2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+74,0,"imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+76,0,"reg_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"r1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+79,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+80,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+76,0,"is_addi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_RegisterFile1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+85,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+82,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+69,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+86,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+87,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+35,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+36,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+33,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_regfile", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+85,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+82,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+69,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+75,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+72,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+35,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+81,0,"raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+36,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+37+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+34,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
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
    bufp->fullIData(oldp+82,(0x20U),32);
    bufp->fullIData(oldp+83,(0x80000000U),32);
    bufp->fullBit(oldp+84,(1U));
    bufp->fullIData(oldp+85,(5U),32);
    bufp->fullCData(oldp+86,(0U),5);
    bufp->fullIData(oldp+87,(0U),32);
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
    bufp->fullIData(oldp+1,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0]),32);
    bufp->fullIData(oldp+2,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[1]),32);
    bufp->fullIData(oldp+3,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[2]),32);
    bufp->fullIData(oldp+4,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[3]),32);
    bufp->fullIData(oldp+5,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[4]),32);
    bufp->fullIData(oldp+6,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[5]),32);
    bufp->fullIData(oldp+7,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[6]),32);
    bufp->fullIData(oldp+8,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[7]),32);
    bufp->fullIData(oldp+9,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[8]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[9]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[10]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[11]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[12]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[13]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[14]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[15]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[16]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[17]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[18]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[19]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[20]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[21]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[22]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[23]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[24]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[25]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[26]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[27]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[28]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[29]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[30]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[31]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+34,(vlSelfRef.npc__DOT__u_regfile__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+35,(vlSelfRef.npc__DOT__src1),32);
    bufp->fullIData(oldp+36,(vlSelfRef.npc__DOT__src2),32);
    bufp->fullIData(oldp+37,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+38,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+39,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+40,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+41,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+42,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+43,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+44,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+45,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+46,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+47,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+48,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+49,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+50,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+51,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+52,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+53,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+54,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+55,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+56,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+57,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+58,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+59,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+60,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+61,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+62,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+63,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+64,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+65,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+66,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+67,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+68,(vlSelfRef.npc__DOT__u_regfile__DOT__rf[31]),32);
    bufp->fullBit(oldp+69,(vlSelfRef.clk));
    bufp->fullBit(oldp+70,(vlSelfRef.rst));
    bufp->fullIData(oldp+71,(vlSelfRef.inst),32);
    bufp->fullIData(oldp+72,(vlSelfRef.alu_result),32);
    bufp->fullIData(oldp+73,(vlSelfRef.pc),32);
    bufp->fullIData(oldp+74,((((- (IData)((vlSelfRef.inst 
                                           >> 0x1fU))) 
                               << 0xcU) | (vlSelfRef.inst 
                                           >> 0x14U))),32);
    bufp->fullCData(oldp+75,((0x1fU & (vlSelfRef.inst 
                                       >> 7U))),5);
    bufp->fullBit(oldp+76,((IData)((0x13U == (0x707fU 
                                              & vlSelfRef.inst)))));
    bufp->fullIData(oldp+77,(((IData)(4U) + vlSelfRef.pc)),32);
    bufp->fullCData(oldp+78,((0x1fU & (vlSelfRef.inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+79,((0x7fU & vlSelfRef.inst)),7);
    bufp->fullCData(oldp+80,((7U & (vlSelfRef.inst 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+81,((0x1fU & (vlSelfRef.inst 
                                       >> 0x14U))),5);
}
