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
        bufp->chgIData(oldp+0,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[0]),32);
        bufp->chgIData(oldp+1,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[1]),32);
        bufp->chgIData(oldp+2,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[2]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[3]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[4]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[5]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[6]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[7]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[8]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[9]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[10]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[11]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[12]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[13]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[14]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[15]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[16]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[17]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[18]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[19]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[20]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[21]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[22]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[23]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[24]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[25]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[26]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[27]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[28]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[29]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[30]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[31]),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+32,(vlSelfRef.npc__DOT__inst),32);
        bufp->chgCData(oldp+33,((0x7fU & vlSelfRef.npc__DOT__inst)),7);
        bufp->chgIData(oldp+34,(vlSelfRef.npc__DOT__imm),32);
        bufp->chgCData(oldp+35,((7U & (vlSelfRef.npc__DOT__inst 
                                       >> 0xcU))),3);
        bufp->chgIData(oldp+36,(vlSelfRef.npc__DOT__src1),32);
        bufp->chgCData(oldp+37,((0x1fU & (vlSelfRef.npc__DOT__inst 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+38,((0x1fU & (vlSelfRef.npc__DOT__inst 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+39,((0x1fU & (vlSelfRef.npc__DOT__inst 
                                          >> 7U))),5);
        bufp->chgCData(oldp+40,(((((IData)(vlSelfRef.npc__DOT__is_add) 
                                   << 5U) | ((((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_5) 
                                               & (0x13U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst))) 
                                              << 4U) 
                                             | ((IData)(vlSelfRef.npc__DOT__is_jalr) 
                                                << 3U))) 
                                 | (((0x6fU == (0x7fU 
                                                & vlSelfRef.npc__DOT__inst)) 
                                     << 2U) | ((((IData)(vlSelfRef.npc__DOT__is_U) 
                                                 & (0x37U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst))) 
                                                << 1U) 
                                               | ((IData)(vlSelfRef.npc__DOT__is_U) 
                                                  & (0x17U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelfRef.npc__DOT__inst))))))),6);
        bufp->chgBit(oldp+41,((0x33U == (0x7fU & vlSelfRef.npc__DOT__inst))));
        bufp->chgBit(oldp+42,(vlSelfRef.npc__DOT__is_I));
        bufp->chgBit(oldp+43,(vlSelfRef.npc__DOT__is_U));
        bufp->chgBit(oldp+44,((0x6fU == (0x7fU & vlSelfRef.npc__DOT__inst))));
        bufp->chgIData(oldp+45,((((- (IData)((vlSelfRef.npc__DOT__inst 
                                              >> 0x1fU))) 
                                  << 0xcU) | (vlSelfRef.npc__DOT__inst 
                                              >> 0x14U))),32);
        bufp->chgIData(oldp+46,((0xfffff000U & vlSelfRef.npc__DOT__inst)),32);
        bufp->chgIData(oldp+47,(((((- (IData)((vlSelfRef.npc__DOT__inst 
                                               >> 0x1fU))) 
                                   << 0x15U) | (0x100000U 
                                                & (vlSelfRef.npc__DOT__inst 
                                                   >> 0xbU))) 
                                 | (((0xff000U & vlSelfRef.npc__DOT__inst) 
                                     | (0x800U & (vlSelfRef.npc__DOT__inst 
                                                  >> 9U))) 
                                    | (0x7feU & (vlSelfRef.npc__DOT__inst 
                                                 >> 0x14U))))),32);
        bufp->chgBit(oldp+48,(((IData)(vlSelfRef.npc__DOT__is_U) 
                               & (0x17U == (0x7fU & vlSelfRef.npc__DOT__inst)))));
        bufp->chgBit(oldp+49,(((IData)(vlSelfRef.npc__DOT__is_U) 
                               & (0x37U == (0x7fU & vlSelfRef.npc__DOT__inst)))));
        bufp->chgBit(oldp+50,(vlSelfRef.npc__DOT__is_jalr));
        bufp->chgBit(oldp+51,(((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_5) 
                               & (0x13U == (0x7fU & vlSelfRef.npc__DOT__inst)))));
        bufp->chgWData(oldp+52,(vlSelfRef.npc__DOT__hot_opcode),128);
        bufp->chgCData(oldp+56,((((((7U == (7U & (vlSelfRef.npc__DOT__inst 
                                                  >> 0xcU))) 
                                    << 7U) | ((6U == 
                                               (7U 
                                                & (vlSelfRef.npc__DOT__inst 
                                                   >> 0xcU))) 
                                              << 6U)) 
                                  | (((5U == (7U & 
                                              (vlSelfRef.npc__DOT__inst 
                                               >> 0xcU))) 
                                      << 5U) | ((4U 
                                                 == 
                                                 (7U 
                                                  & (vlSelfRef.npc__DOT__inst 
                                                     >> 0xcU))) 
                                                << 4U))) 
                                 | ((((3U == (7U & 
                                              (vlSelfRef.npc__DOT__inst 
                                               >> 0xcU))) 
                                      << 3U) | ((2U 
                                                 == 
                                                 (7U 
                                                  & (vlSelfRef.npc__DOT__inst 
                                                     >> 0xcU))) 
                                                << 2U)) 
                                    | (((1U == (7U 
                                                & (vlSelfRef.npc__DOT__inst 
                                                   >> 0xcU))) 
                                        << 1U) | (0U 
                                                  == 
                                                  (7U 
                                                   & (vlSelfRef.npc__DOT__inst 
                                                      >> 0xcU))))))),8);
        bufp->chgIData(oldp+57,(vlSelfRef.npc__DOT__u_alu__DOT__result_auipc),32);
        bufp->chgIData(oldp+58,(vlSelfRef.npc__DOT__u_alu__DOT__result_addi),32);
    }
    bufp->chgBit(oldp+59,(vlSelfRef.clk));
    bufp->chgBit(oldp+60,(vlSelfRef.rst));
    bufp->chgIData(oldp+61,(vlSelfRef.alu_result),32);
    bufp->chgIData(oldp+62,(vlSelfRef.pc),32);
    bufp->chgIData(oldp+63,(((0x6fU == (0x7fU & vlSelfRef.npc__DOT__inst))
                              ? vlSelfRef.npc__DOT__u_alu__DOT__result_auipc
                              : ((IData)(vlSelfRef.npc__DOT__is_jalr)
                                  ? (0xfffffffeU & vlSelfRef.npc__DOT__u_alu__DOT__result_addi)
                                  : ((IData)(4U) + vlSelfRef.pc)))),32);
    bufp->chgIData(oldp+64,(((0U == (0x1fU & (vlSelfRef.npc__DOT__inst 
                                              >> 0x14U)))
                              ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                             [(0x1fU & (vlSelfRef.npc__DOT__inst 
                                        >> 0x14U))])),32);
    bufp->chgIData(oldp+65,(((IData)(4U) + vlSelfRef.pc)),32);
    bufp->chgIData(oldp+66,((vlSelfRef.npc__DOT__src1 
                             + ((0U == (0x1fU & (vlSelfRef.npc__DOT__inst 
                                                 >> 0x14U)))
                                 ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                [(0x1fU & (vlSelfRef.npc__DOT__inst 
                                           >> 0x14U))]))),32);
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
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
