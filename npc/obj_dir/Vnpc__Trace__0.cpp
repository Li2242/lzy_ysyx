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
        bufp->chgIData(oldp+0,(vlSelfRef.npc__DOT__inst),32);
        bufp->chgCData(oldp+1,((0x7fU & vlSelfRef.npc__DOT__inst)),7);
        bufp->chgCData(oldp+2,((7U & (vlSelfRef.npc__DOT__inst 
                                      >> 0xcU))),3);
        bufp->chgCData(oldp+3,((0x1fU & (vlSelfRef.npc__DOT__inst 
                                         >> 0xfU))),5);
        bufp->chgCData(oldp+4,((0x1fU & (vlSelfRef.npc__DOT__inst 
                                         >> 0x14U))),5);
        bufp->chgCData(oldp+5,((0x1fU & (vlSelfRef.npc__DOT__inst 
                                         >> 7U))),5);
        bufp->chgBit(oldp+6,(((0x17U == (0x7fU & vlSelfRef.npc__DOT__inst)) 
                              | ((0x37U == (0x7fU & vlSelfRef.npc__DOT__inst)) 
                                 | ((IData)(vlSelfRef.npc__DOT__reg_from_pc_4) 
                                    | ((IData)(vlSelfRef.npc__DOT__is_addi) 
                                       | ((IData)(vlSelfRef.npc__DOT__is_add) 
                                          | (IData)(vlSelfRef.npc__DOT__mem_en))))))));
        bufp->chgBit(oldp+7,(vlSelfRef.npc__DOT__mem_en));
        bufp->chgBit(oldp+8,(((IData)((0x2023U == (0x707fU 
                                                   & vlSelfRef.npc__DOT__inst))) 
                              | (IData)(vlSelfRef.npc__DOT__is_sb))));
        bufp->chgBit(oldp+9,(vlSelfRef.npc__DOT__reg_from_pc_4));
        bufp->chgBit(oldp+10,((0x37U == (0x7fU & vlSelfRef.npc__DOT__inst))));
        bufp->chgIData(oldp+11,(vlSelfRef.npc__DOT__imm),32);
        bufp->chgIData(oldp+12,((((- (IData)((vlSelfRef.npc__DOT__inst 
                                              >> 0x1fU))) 
                                  << 0xcU) | (vlSelfRef.npc__DOT__inst 
                                              >> 0x14U))),32);
        bufp->chgIData(oldp+13,((0xfffff000U & vlSelfRef.npc__DOT__inst)),32);
        bufp->chgIData(oldp+14,(((((- (IData)((vlSelfRef.npc__DOT__inst 
                                               >> 0x1fU))) 
                                   << 0x15U) | (0x100000U 
                                                & (vlSelfRef.npc__DOT__inst 
                                                   >> 0xbU))) 
                                 | (((0xff000U & vlSelfRef.npc__DOT__inst) 
                                     | (0x800U & (vlSelfRef.npc__DOT__inst 
                                                  >> 9U))) 
                                    | (0x7feU & (vlSelfRef.npc__DOT__inst 
                                                 >> 0x14U))))),32);
        bufp->chgIData(oldp+15,((((- (IData)((vlSelfRef.npc__DOT__inst 
                                              >> 0x1fU))) 
                                  << 0xcU) | ((0xfe0U 
                                               & (vlSelfRef.npc__DOT__inst 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelfRef.npc__DOT__inst 
                                                    >> 7U))))),32);
        bufp->chgBit(oldp+16,((0x33U == (0x7fU & vlSelfRef.npc__DOT__inst))));
        bufp->chgBit(oldp+17,(((0x13U == (0x7fU & vlSelfRef.npc__DOT__inst)) 
                               | ((3U == (0x7fU & vlSelfRef.npc__DOT__inst)) 
                                  | (0x67U == (0x7fU 
                                               & vlSelfRef.npc__DOT__inst))))));
        bufp->chgBit(oldp+18,(((0x37U == (0x7fU & vlSelfRef.npc__DOT__inst)) 
                               | (0x17U == (0x7fU & vlSelfRef.npc__DOT__inst)))));
        bufp->chgBit(oldp+19,((0x6fU == (0x7fU & vlSelfRef.npc__DOT__inst))));
        bufp->chgBit(oldp+20,((0x23U == (0x7fU & vlSelfRef.npc__DOT__inst))));
        bufp->chgBit(oldp+21,((0x17U == (0x7fU & vlSelfRef.npc__DOT__inst))));
        bufp->chgBit(oldp+22,(vlSelfRef.npc__DOT__is_add));
        bufp->chgBit(oldp+23,(vlSelfRef.npc__DOT__is_jalr));
        bufp->chgBit(oldp+24,(vlSelfRef.npc__DOT__is_addi));
        bufp->chgBit(oldp+25,((IData)((0x2003U == (0x707fU 
                                                   & vlSelfRef.npc__DOT__inst)))));
        bufp->chgBit(oldp+26,(vlSelfRef.npc__DOT__is_lbu));
        bufp->chgBit(oldp+27,((IData)((0x2023U == (0x707fU 
                                                   & vlSelfRef.npc__DOT__inst)))));
        bufp->chgBit(oldp+28,(vlSelfRef.npc__DOT__is_sb));
        bufp->chgBit(oldp+29,((0x100073U == vlSelfRef.npc__DOT__inst)));
        bufp->chgWData(oldp+30,(vlSelfRef.npc__DOT__opcode_d),128);
        bufp->chgCData(oldp+34,((((((7U == (7U & (vlSelfRef.npc__DOT__inst 
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
        bufp->chgBit(oldp+35,(((IData)(vlSelfRef.npc__DOT__is_add) 
                               | (IData)(vlSelfRef.npc__DOT__src2_is_imm))));
        bufp->chgBit(oldp+36,(vlSelfRef.npc__DOT__src2_is_imm));
        bufp->chgIData(oldp+37,(vlSelfRef.npc__DOT__src1),32);
        bufp->chgIData(oldp+38,(vlSelfRef.npc__DOT__src2),32);
        bufp->chgIData(oldp+39,(((IData)(vlSelfRef.npc__DOT__src2_is_imm)
                                  ? vlSelfRef.npc__DOT__imm
                                  : vlSelfRef.npc__DOT__src2)),32);
        bufp->chgIData(oldp+40,(vlSelfRef.npc__DOT__rdata),32);
        bufp->chgIData(oldp+41,(vlSelfRef.npc__DOT__raddr),32);
        bufp->chgCData(oldp+42,(((IData)(vlSelfRef.npc__DOT__is_sb)
                                  ? 1U : 0xfU)),8);
        bufp->chgIData(oldp+43,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[0]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[1]),32);
        bufp->chgIData(oldp+45,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[2]),32);
        bufp->chgIData(oldp+46,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[3]),32);
        bufp->chgIData(oldp+47,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[4]),32);
        bufp->chgIData(oldp+48,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[5]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[6]),32);
        bufp->chgIData(oldp+50,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[7]),32);
        bufp->chgIData(oldp+51,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[8]),32);
        bufp->chgIData(oldp+52,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[9]),32);
        bufp->chgIData(oldp+53,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[10]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[11]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[12]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[13]),32);
        bufp->chgIData(oldp+57,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[14]),32);
        bufp->chgIData(oldp+58,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[15]),32);
        bufp->chgIData(oldp+59,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[16]),32);
        bufp->chgIData(oldp+60,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[17]),32);
        bufp->chgIData(oldp+61,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[18]),32);
        bufp->chgIData(oldp+62,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[19]),32);
        bufp->chgIData(oldp+63,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[20]),32);
        bufp->chgIData(oldp+64,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[21]),32);
        bufp->chgIData(oldp+65,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[22]),32);
        bufp->chgIData(oldp+66,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[23]),32);
        bufp->chgIData(oldp+67,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[24]),32);
        bufp->chgIData(oldp+68,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[25]),32);
        bufp->chgIData(oldp+69,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[26]),32);
        bufp->chgIData(oldp+70,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[27]),32);
        bufp->chgIData(oldp+71,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[28]),32);
        bufp->chgIData(oldp+72,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[29]),32);
        bufp->chgIData(oldp+73,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[30]),32);
        bufp->chgIData(oldp+74,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+75,(vlSelfRef.clk));
    bufp->chgBit(oldp+76,(vlSelfRef.reset));
    bufp->chgIData(oldp+77,(vlSelfRef.alu_result),32);
    bufp->chgIData(oldp+78,(vlSelfRef.pc),32);
    bufp->chgIData(oldp+79,(((IData)(vlSelfRef.npc__DOT__is_jalr)
                              ? (0xfffffffeU & vlSelfRef.npc__DOT__raddr)
                              : ((0x6fU == (0x7fU & vlSelfRef.npc__DOT__inst))
                                  ? (vlSelfRef.pc + vlSelfRef.npc__DOT__imm)
                                  : ((IData)(4U) + vlSelfRef.pc)))),32);
    bufp->chgIData(oldp+80,(((0x17U == (0x7fU & vlSelfRef.npc__DOT__inst))
                              ? vlSelfRef.pc : vlSelfRef.npc__DOT__src1)),32);
    bufp->chgIData(oldp+81,(((IData)(vlSelfRef.npc__DOT__mem_en)
                              ? vlSelfRef.npc__DOT__rdata
                              : ((IData)(vlSelfRef.npc__DOT__reg_from_pc_4)
                                  ? ((IData)(4U) + vlSelfRef.pc)
                                  : ((0x37U == (0x7fU 
                                                & vlSelfRef.npc__DOT__inst))
                                      ? vlSelfRef.npc__DOT__imm
                                      : vlSelfRef.alu_result)))),32);
    bufp->chgIData(oldp+82,((((0x17U == (0x7fU & vlSelfRef.npc__DOT__inst))
                               ? vlSelfRef.pc : vlSelfRef.npc__DOT__src1) 
                             + ((IData)(vlSelfRef.npc__DOT__src2_is_imm)
                                 ? vlSelfRef.npc__DOT__imm
                                 : vlSelfRef.npc__DOT__src2))),32);
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
