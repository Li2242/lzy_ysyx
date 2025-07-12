// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vnpc__Syms.h"


void Vnpc___024root__trace_chg_0_sub_0(Vnpc___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vnpc___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_chg_0\n"); );
    // Init
    Vnpc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vnpc___024root*>(voidSelf);
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vnpc___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vnpc___024root__trace_chg_0_sub_0(Vnpc___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_chg_0_sub_0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[0]),32);
        bufp->chgIData(oldp+1,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[1]),32);
        bufp->chgIData(oldp+2,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[2]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[3]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[4]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[5]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[6]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[7]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[8]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[9]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[10]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[11]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[12]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[13]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[14]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[15]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[16]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[17]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[18]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[19]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[20]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[21]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[22]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[23]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[24]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[25]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[26]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[27]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[28]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[29]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[30]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.npc__DOT__u_alu__DOT__u_RegisterFile2__DOT__rf[31]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[1]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[2]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[3]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[4]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[5]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[6]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[7]),32);
        bufp->chgIData(oldp+40,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[8]),32);
        bufp->chgIData(oldp+41,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[9]),32);
        bufp->chgIData(oldp+42,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[10]),32);
        bufp->chgIData(oldp+43,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[11]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[12]),32);
        bufp->chgIData(oldp+45,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[13]),32);
        bufp->chgIData(oldp+46,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[14]),32);
        bufp->chgIData(oldp+47,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[15]),32);
        bufp->chgIData(oldp+48,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[16]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[17]),32);
        bufp->chgIData(oldp+50,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[18]),32);
        bufp->chgIData(oldp+51,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[19]),32);
        bufp->chgIData(oldp+52,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[20]),32);
        bufp->chgIData(oldp+53,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[21]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[22]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[23]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[24]),32);
        bufp->chgIData(oldp+57,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[25]),32);
        bufp->chgIData(oldp+58,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[26]),32);
        bufp->chgIData(oldp+59,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[27]),32);
        bufp->chgIData(oldp+60,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[28]),32);
        bufp->chgIData(oldp+61,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[29]),32);
        bufp->chgIData(oldp+62,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[30]),32);
        bufp->chgIData(oldp+63,(vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+64,(vlSelfRef.clk));
    bufp->chgIData(oldp+65,(vlSelfRef.pc),32);
    bufp->chgIData(oldp+66,(vlSelfRef.inst),32);
    bufp->chgIData(oldp+67,(vlSelfRef.src1),32);
    bufp->chgIData(oldp+68,(vlSelfRef.src2),32);
    bufp->chgCData(oldp+69,(vlSelfRef.rd),5);
    bufp->chgIData(oldp+70,(vlSelfRef.imm),32);
    bufp->chgIData(oldp+71,(vlSelfRef.sum),32);
    bufp->chgCData(oldp+72,((0x1fU & (vlSelfRef.inst 
                                      >> 0xfU))),5);
    bufp->chgBit(oldp+73,((IData)(((0x13U == (0x107fU 
                                              & vlSelfRef.inst)) 
                                   & (~ (IData)((0U 
                                                 != 
                                                 (0x6000U 
                                                  & vlSelfRef.inst))))))));
}

void Vnpc___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_cleanup\n"); );
    // Init
    Vnpc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vnpc___024root*>(voidSelf);
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
