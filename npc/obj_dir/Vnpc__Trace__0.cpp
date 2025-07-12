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
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.npc__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+1,(vlSelfRef.clk));
    bufp->chgBit(oldp+2,(vlSelfRef.rst));
    bufp->chgBit(oldp+3,(vlSelfRef.wen));
    bufp->chgIData(oldp+4,(vlSelfRef.rf[0]),32);
    bufp->chgIData(oldp+5,(vlSelfRef.rf[1]),32);
    bufp->chgIData(oldp+6,(vlSelfRef.rf[2]),32);
    bufp->chgIData(oldp+7,(vlSelfRef.rf[3]),32);
    bufp->chgIData(oldp+8,(vlSelfRef.rf[4]),32);
    bufp->chgIData(oldp+9,(vlSelfRef.rf[5]),32);
    bufp->chgIData(oldp+10,(vlSelfRef.rf[6]),32);
    bufp->chgIData(oldp+11,(vlSelfRef.rf[7]),32);
    bufp->chgIData(oldp+12,(vlSelfRef.rf[8]),32);
    bufp->chgIData(oldp+13,(vlSelfRef.rf[9]),32);
    bufp->chgIData(oldp+14,(vlSelfRef.rf[10]),32);
    bufp->chgIData(oldp+15,(vlSelfRef.rf[11]),32);
    bufp->chgIData(oldp+16,(vlSelfRef.rf[12]),32);
    bufp->chgIData(oldp+17,(vlSelfRef.rf[13]),32);
    bufp->chgIData(oldp+18,(vlSelfRef.rf[14]),32);
    bufp->chgIData(oldp+19,(vlSelfRef.rf[15]),32);
    bufp->chgIData(oldp+20,(vlSelfRef.rf[16]),32);
    bufp->chgIData(oldp+21,(vlSelfRef.rf[17]),32);
    bufp->chgIData(oldp+22,(vlSelfRef.rf[18]),32);
    bufp->chgIData(oldp+23,(vlSelfRef.rf[19]),32);
    bufp->chgIData(oldp+24,(vlSelfRef.rf[20]),32);
    bufp->chgIData(oldp+25,(vlSelfRef.rf[21]),32);
    bufp->chgIData(oldp+26,(vlSelfRef.rf[22]),32);
    bufp->chgIData(oldp+27,(vlSelfRef.rf[23]),32);
    bufp->chgIData(oldp+28,(vlSelfRef.rf[24]),32);
    bufp->chgIData(oldp+29,(vlSelfRef.rf[25]),32);
    bufp->chgIData(oldp+30,(vlSelfRef.rf[26]),32);
    bufp->chgIData(oldp+31,(vlSelfRef.rf[27]),32);
    bufp->chgIData(oldp+32,(vlSelfRef.rf[28]),32);
    bufp->chgIData(oldp+33,(vlSelfRef.rf[29]),32);
    bufp->chgIData(oldp+34,(vlSelfRef.rf[30]),32);
    bufp->chgIData(oldp+35,(vlSelfRef.rf[31]),32);
    bufp->chgIData(oldp+36,(vlSelfRef.pc),32);
    bufp->chgIData(oldp+37,(vlSelfRef.inst),32);
    bufp->chgIData(oldp+38,(vlSelfRef.src1),32);
    bufp->chgCData(oldp+39,(vlSelfRef.rd),5);
    bufp->chgIData(oldp+40,(vlSelfRef.imm),32);
    bufp->chgIData(oldp+41,(vlSelfRef.npc__DOT____Vcellout__u_idu__srd),32);
}

void Vnpc___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_cleanup\n"); );
    // Init
    Vnpc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vnpc___024root*>(voidSelf);
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
}
