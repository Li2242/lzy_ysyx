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
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("npc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"nextpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"mem_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+6,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+8,0,"src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"src2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+11,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+12,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+13,0,"alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+14,0,"reg_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"is_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"is_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"is_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"is_J",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+73,0,"imm_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"imm_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+20,0,"imm_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+21,0,"imm_J",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+22,0,"is_auipc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"is_lui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"is_jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"is_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"is_addi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"is_add",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"is_lw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+27,0,"hot_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+31,0,"hot_funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("u_alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+6,0,"imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"src2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+2,0,"rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+71,0,"result_auipc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"result_lui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"result_jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"result_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"result_addi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+33,0,"result_add",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"result_lw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_decoder3_8", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+7,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+31,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_decoder7_128", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+5,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declArray(c+27,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_regfile2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+74,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+68,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+8,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+9,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+34+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
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
    bufp->fullIData(oldp+73,(vlSelfRef.npc__DOT__imm_R),32);
    bufp->fullIData(oldp+74,(5U),32);
    bufp->fullIData(oldp+75,(0x20U),32);
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
    bufp->fullIData(oldp+1,(vlSelfRef.npc__DOT__inst),32);
    bufp->fullIData(oldp+2,(vlSelfRef.npc__DOT__rdata),32);
    bufp->fullIData(oldp+3,(((- (IData)((IData)(vlSelfRef.npc__DOT__mem_en))) 
                             & (vlSelfRef.npc__DOT__src1 
                                + vlSelfRef.npc__DOT__imm_I))),32);
    bufp->fullBit(oldp+4,(vlSelfRef.npc__DOT__mem_en));
    bufp->fullCData(oldp+5,((0x7fU & vlSelfRef.npc__DOT__inst)),7);
    bufp->fullIData(oldp+6,(vlSelfRef.npc__DOT__imm),32);
    bufp->fullCData(oldp+7,((7U & (vlSelfRef.npc__DOT__inst 
                                   >> 0xcU))),3);
    bufp->fullIData(oldp+8,(vlSelfRef.npc__DOT__src1),32);
    bufp->fullIData(oldp+9,(((0U == (0x1fU & (vlSelfRef.npc__DOT__inst 
                                              >> 0x14U)))
                              ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                             [(0x1fU & (vlSelfRef.npc__DOT__inst 
                                        >> 0x14U))])),32);
    bufp->fullCData(oldp+10,((0x1fU & (vlSelfRef.npc__DOT__inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+11,((0x1fU & (vlSelfRef.npc__DOT__inst 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+12,((0x1fU & (vlSelfRef.npc__DOT__inst 
                                       >> 7U))),5);
    bufp->fullCData(oldp+13,((((((IData)(vlSelfRef.npc__DOT__mem_en) 
                                 << 6U) | ((IData)(vlSelfRef.npc__DOT__is_add) 
                                           << 5U)) 
                               | (((IData)(vlSelfRef.npc__DOT__is_addi) 
                                   << 4U) | ((IData)(vlSelfRef.npc__DOT__is_jalr) 
                                             << 3U))) 
                              | (((0x6fU == (0x7fU 
                                             & vlSelfRef.npc__DOT__inst)) 
                                  << 2U) | (((IData)(vlSelfRef.npc__DOT__is_lui) 
                                             << 1U) 
                                            | (IData)(vlSelfRef.npc__DOT__is_auipc))))),7);
    bufp->fullBit(oldp+14,(((IData)(vlSelfRef.npc__DOT__is_auipc) 
                            | ((IData)(vlSelfRef.npc__DOT__is_lui) 
                               | ((0x6fU == (0x7fU 
                                             & vlSelfRef.npc__DOT__inst)) 
                                  | ((IData)(vlSelfRef.npc__DOT__is_jalr) 
                                     | ((IData)(vlSelfRef.npc__DOT__is_addi) 
                                        | ((IData)(vlSelfRef.npc__DOT__is_add) 
                                           | (IData)(vlSelfRef.npc__DOT__mem_en)))))))));
    bufp->fullBit(oldp+15,((0x33U == (0x7fU & vlSelfRef.npc__DOT__inst))));
    bufp->fullBit(oldp+16,(vlSelfRef.npc__DOT__is_I));
    bufp->fullBit(oldp+17,(vlSelfRef.npc__DOT__is_U));
    bufp->fullBit(oldp+18,((0x6fU == (0x7fU & vlSelfRef.npc__DOT__inst))));
    bufp->fullIData(oldp+19,(vlSelfRef.npc__DOT__imm_I),32);
    bufp->fullIData(oldp+20,((0xfffff000U & vlSelfRef.npc__DOT__inst)),32);
    bufp->fullIData(oldp+21,(((((- (IData)((vlSelfRef.npc__DOT__inst 
                                            >> 0x1fU))) 
                                << 0x15U) | (0x100000U 
                                             & (vlSelfRef.npc__DOT__inst 
                                                >> 0xbU))) 
                              | (((0xff000U & vlSelfRef.npc__DOT__inst) 
                                  | (0x800U & (vlSelfRef.npc__DOT__inst 
                                               >> 9U))) 
                                 | (0x7feU & (vlSelfRef.npc__DOT__inst 
                                              >> 0x14U))))),32);
    bufp->fullBit(oldp+22,(vlSelfRef.npc__DOT__is_auipc));
    bufp->fullBit(oldp+23,(vlSelfRef.npc__DOT__is_lui));
    bufp->fullBit(oldp+24,(vlSelfRef.npc__DOT__is_jalr));
    bufp->fullBit(oldp+25,(vlSelfRef.npc__DOT__is_addi));
    bufp->fullBit(oldp+26,(vlSelfRef.npc__DOT__is_add));
    bufp->fullWData(oldp+27,(vlSelfRef.npc__DOT__hot_opcode),128);
    bufp->fullCData(oldp+31,((((((7U == (7U & (vlSelfRef.npc__DOT__inst 
                                               >> 0xcU))) 
                                 << 7U) | ((6U == (7U 
                                                   & (vlSelfRef.npc__DOT__inst 
                                                      >> 0xcU))) 
                                           << 6U)) 
                               | (((5U == (7U & (vlSelfRef.npc__DOT__inst 
                                                 >> 0xcU))) 
                                   << 5U) | ((4U == 
                                              (7U & 
                                               (vlSelfRef.npc__DOT__inst 
                                                >> 0xcU))) 
                                             << 4U))) 
                              | ((((3U == (7U & (vlSelfRef.npc__DOT__inst 
                                                 >> 0xcU))) 
                                   << 3U) | ((2U == 
                                              (7U & 
                                               (vlSelfRef.npc__DOT__inst 
                                                >> 0xcU))) 
                                             << 2U)) 
                                 | (((1U == (7U & (vlSelfRef.npc__DOT__inst 
                                                   >> 0xcU))) 
                                     << 1U) | (0U == 
                                               (7U 
                                                & (vlSelfRef.npc__DOT__inst 
                                                   >> 0xcU))))))),8);
    bufp->fullIData(oldp+32,((vlSelfRef.npc__DOT__imm 
                              + vlSelfRef.npc__DOT__src1)),32);
    bufp->fullIData(oldp+33,((vlSelfRef.npc__DOT__src1 
                              + ((0U == (0x1fU & (vlSelfRef.npc__DOT__inst 
                                                  >> 0x14U)))
                                  ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                 [(0x1fU & (vlSelfRef.npc__DOT__inst 
                                            >> 0x14U))]))),32);
    bufp->fullIData(oldp+34,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[0]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[1]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[2]),32);
    bufp->fullIData(oldp+37,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[3]),32);
    bufp->fullIData(oldp+38,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[4]),32);
    bufp->fullIData(oldp+39,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[5]),32);
    bufp->fullIData(oldp+40,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[6]),32);
    bufp->fullIData(oldp+41,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[7]),32);
    bufp->fullIData(oldp+42,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[8]),32);
    bufp->fullIData(oldp+43,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[9]),32);
    bufp->fullIData(oldp+44,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[10]),32);
    bufp->fullIData(oldp+45,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[11]),32);
    bufp->fullIData(oldp+46,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[12]),32);
    bufp->fullIData(oldp+47,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[13]),32);
    bufp->fullIData(oldp+48,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[14]),32);
    bufp->fullIData(oldp+49,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[15]),32);
    bufp->fullIData(oldp+50,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[16]),32);
    bufp->fullIData(oldp+51,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[17]),32);
    bufp->fullIData(oldp+52,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[18]),32);
    bufp->fullIData(oldp+53,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[19]),32);
    bufp->fullIData(oldp+54,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[20]),32);
    bufp->fullIData(oldp+55,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[21]),32);
    bufp->fullIData(oldp+56,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[22]),32);
    bufp->fullIData(oldp+57,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[23]),32);
    bufp->fullIData(oldp+58,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[24]),32);
    bufp->fullIData(oldp+59,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[25]),32);
    bufp->fullIData(oldp+60,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[26]),32);
    bufp->fullIData(oldp+61,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[27]),32);
    bufp->fullIData(oldp+62,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[28]),32);
    bufp->fullIData(oldp+63,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[29]),32);
    bufp->fullIData(oldp+64,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[30]),32);
    bufp->fullIData(oldp+65,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[31]),32);
    bufp->fullBit(oldp+66,(vlSelfRef.clk));
    bufp->fullBit(oldp+67,(vlSelfRef.reset));
    bufp->fullIData(oldp+68,(vlSelfRef.alu_result),32);
    bufp->fullIData(oldp+69,(vlSelfRef.pc),32);
    bufp->fullIData(oldp+70,(((0x6fU == (0x7fU & vlSelfRef.npc__DOT__inst))
                               ? (vlSelfRef.pc + vlSelfRef.npc__DOT__imm)
                               : ((IData)(vlSelfRef.npc__DOT__is_jalr)
                                   ? (0xfffffffeU & 
                                      (vlSelfRef.npc__DOT__src1 
                                       + vlSelfRef.npc__DOT__imm))
                                   : ((IData)(4U) + vlSelfRef.pc)))),32);
    bufp->fullIData(oldp+71,((vlSelfRef.npc__DOT__imm 
                              + vlSelfRef.pc)),32);
    bufp->fullIData(oldp+72,(((IData)(4U) + vlSelfRef.pc)),32);
}
