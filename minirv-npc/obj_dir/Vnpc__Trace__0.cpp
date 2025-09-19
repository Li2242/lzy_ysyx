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
        bufp->chgIData(oldp+0,(vlSelfRef.npc__DOT__u_csr__DOT__mcycle),32);
        bufp->chgIData(oldp+1,(vlSelfRef.npc__DOT__u_csr__DOT__mcycleh),32);
        bufp->chgIData(oldp+2,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[0]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[1]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[2]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[3]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[4]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[5]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[6]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[7]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[8]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[9]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[10]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[11]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[12]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[13]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[14]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[15]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[16]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[17]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[18]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[19]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[20]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[21]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[22]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[23]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[24]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[25]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[26]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[27]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[28]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[29]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[30]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[31]),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+34,(vlSelfRef.npc__DOT__ifu_state));
        bufp->chgBit(oldp+35,((1U & (~ (IData)(vlSelfRef.npc__DOT__ifu_state)))));
        bufp->chgIData(oldp+36,(vlSelfRef.npc__DOT__ifu_raddr),32);
        bufp->chgBit(oldp+37,(vlSelfRef.npc__DOT__pc_valid));
        bufp->chgIData(oldp+38,(vlSelfRef.npc__DOT__inst_reg),32);
        bufp->chgCData(oldp+39,((0x7fU & vlSelfRef.npc__DOT__inst_reg)),7);
        bufp->chgCData(oldp+40,((7U & (vlSelfRef.npc__DOT__inst_reg 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+41,((0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+42,((0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+43,((0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                          >> 7U))),5);
        bufp->chgBit(oldp+44,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                               [0x17U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [0x37U] | 
                                          (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x6fU] 
                                           | ((IData)(vlSelfRef.npc__DOT__is_jalr) 
                                              | ((IData)(vlSelfRef.npc__DOT__is_addi) 
                                                 | ((IData)(vlSelfRef.npc__DOT__is_add) 
                                                    | ((IData)(vlSelfRef.npc__DOT__is_lw) 
                                                       | ((IData)(vlSelfRef.npc__DOT__is_lbu) 
                                                          | (IData)(vlSelfRef.npc__DOT__reg_cwen)))))))))));
        bufp->chgBit(oldp+45,(vlSelfRef.npc__DOT__reg_cwen));
        bufp->chgBit(oldp+46,(vlSelfRef.npc__DOT__mem_ren));
        bufp->chgBit(oldp+47,(vlSelfRef.npc__DOT__mem_wen));
        bufp->chgBit(oldp+48,(((IData)(vlSelfRef.npc__DOT__mem_ren) 
                               | (IData)(vlSelfRef.npc__DOT__mem_wen))));
        bufp->chgBit(oldp+49,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                               [0x6fU] | (IData)(vlSelfRef.npc__DOT__is_jalr))));
        bufp->chgBit(oldp+50,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x37U]));
        bufp->chgIData(oldp+51,(vlSelfRef.npc__DOT__imm),32);
        bufp->chgIData(oldp+52,((((- (IData)((vlSelfRef.npc__DOT__inst_reg 
                                              >> 0x1fU))) 
                                  << 0xcU) | (vlSelfRef.npc__DOT__inst_reg 
                                              >> 0x14U))),32);
        bufp->chgIData(oldp+53,((0xfffff000U & vlSelfRef.npc__DOT__inst_reg)),32);
        bufp->chgIData(oldp+54,(((((- (IData)((vlSelfRef.npc__DOT__inst_reg 
                                               >> 0x1fU))) 
                                   << 0x15U) | (0x100000U 
                                                & (vlSelfRef.npc__DOT__inst_reg 
                                                   >> 0xbU))) 
                                 | (((0xff000U & vlSelfRef.npc__DOT__inst_reg) 
                                     | (0x800U & (vlSelfRef.npc__DOT__inst_reg 
                                                  >> 9U))) 
                                    | (0x7feU & (vlSelfRef.npc__DOT__inst_reg 
                                                 >> 0x14U))))),32);
        bufp->chgIData(oldp+55,((((- (IData)((vlSelfRef.npc__DOT__inst_reg 
                                              >> 0x1fU))) 
                                  << 0xcU) | ((0xfe0U 
                                               & (vlSelfRef.npc__DOT__inst_reg 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelfRef.npc__DOT__inst_reg 
                                                    >> 7U))))),32);
        bufp->chgBit(oldp+56,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x33U]));
        bufp->chgBit(oldp+57,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                               [0x13U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [3U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                  [0x67U] 
                                                  | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                  [0x73U])))));
        bufp->chgBit(oldp+58,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                               [0x37U] | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                               [0x17U])));
        bufp->chgBit(oldp+59,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x6fU]));
        bufp->chgBit(oldp+60,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x23U]));
        bufp->chgBit(oldp+61,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x17U]));
        bufp->chgBit(oldp+62,(vlSelfRef.npc__DOT__is_add));
        bufp->chgBit(oldp+63,(vlSelfRef.npc__DOT__is_jalr));
        bufp->chgBit(oldp+64,(vlSelfRef.npc__DOT__is_addi));
        bufp->chgBit(oldp+65,(vlSelfRef.npc__DOT__is_lw));
        bufp->chgBit(oldp+66,(vlSelfRef.npc__DOT__is_lbu));
        bufp->chgBit(oldp+67,((IData)(((0x2000U == 
                                        (0x7000U & vlSelfRef.npc__DOT__inst_reg)) 
                                       & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                       [0x23U]))));
        bufp->chgBit(oldp+68,((IData)(((0U == (0x7000U 
                                               & vlSelfRef.npc__DOT__inst_reg)) 
                                       & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                       [0x23U]))));
        bufp->chgBit(oldp+69,((0x100073U == vlSelfRef.npc__DOT__inst_reg)));
        bufp->chgWData(oldp+70,(vlSelfRef.npc__DOT__opcode_d),128);
        bufp->chgCData(oldp+74,((((((7U == (7U & (vlSelfRef.npc__DOT__inst_reg 
                                                  >> 0xcU))) 
                                    << 7U) | ((6U == 
                                               (7U 
                                                & (vlSelfRef.npc__DOT__inst_reg 
                                                   >> 0xcU))) 
                                              << 6U)) 
                                  | (((5U == (7U & 
                                              (vlSelfRef.npc__DOT__inst_reg 
                                               >> 0xcU))) 
                                      << 5U) | ((4U 
                                                 == 
                                                 (7U 
                                                  & (vlSelfRef.npc__DOT__inst_reg 
                                                     >> 0xcU))) 
                                                << 4U))) 
                                 | ((((3U == (7U & 
                                              (vlSelfRef.npc__DOT__inst_reg 
                                               >> 0xcU))) 
                                      << 3U) | ((2U 
                                                 == 
                                                 (7U 
                                                  & (vlSelfRef.npc__DOT__inst_reg 
                                                     >> 0xcU))) 
                                                << 2U)) 
                                    | (((1U == (7U 
                                                & (vlSelfRef.npc__DOT__inst_reg 
                                                   >> 0xcU))) 
                                        << 1U) | (0U 
                                                  == 
                                                  (7U 
                                                   & (vlSelfRef.npc__DOT__inst_reg 
                                                      >> 0xcU))))))),8);
        bufp->chgBit(oldp+75,(((IData)(vlSelfRef.npc__DOT__is_add) 
                               | (IData)(vlSelfRef.npc__DOT__src2_is_imm))));
        bufp->chgBit(oldp+76,(vlSelfRef.npc__DOT__src2_is_imm));
        bufp->chgIData(oldp+77,(vlSelfRef.npc__DOT__src1),32);
        bufp->chgIData(oldp+78,(((IData)(vlSelfRef.npc__DOT__mem_ren)
                                  ? vlSelfRef.npc__DOT____VdfgExtracted_hd008e9d4__0
                                  : 0U)),32);
        bufp->chgIData(oldp+79,(vlSelfRef.npc__DOT__raddr),32);
        bufp->chgIData(oldp+80,(((IData)(vlSelfRef.npc__DOT__mem_wen)
                                  ? vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0
                                  : 0x80000000U)),32);
        bufp->chgCData(oldp+81,(((IData)(((0U == (0x7000U 
                                                  & vlSelfRef.npc__DOT__inst_reg)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [0x23U]))
                                  ? 1U : 0xfU)),8);
        bufp->chgSData(oldp+82,((0xfffU & vlSelfRef.npc__DOT__imm)),12);
    }
    bufp->chgBit(oldp+83,(vlSelfRef.clk));
    bufp->chgBit(oldp+84,(vlSelfRef.reset));
    bufp->chgIData(oldp+85,(vlSelfRef.alu_result),32);
    bufp->chgIData(oldp+86,(vlSelfRef.pc),32);
    bufp->chgBit(oldp+87,(vlSelfRef.inst_valid));
    bufp->chgIData(oldp+88,(((IData)(vlSelfRef.npc__DOT__is_jalr)
                              ? (0xfffffffeU & vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0)
                              : (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                 [0x6fU] ? (vlSelfRef.pc 
                                            + vlSelfRef.npc__DOT__imm)
                                  : ((IData)(4U) + vlSelfRef.pc)))),32);
    bufp->chgIData(oldp+89,(((IData)(vlSelfRef.npc__DOT__mem_ren)
                              ? ((IData)(vlSelfRef.npc__DOT__mem_ren)
                                  ? vlSelfRef.npc__DOT____VdfgExtracted_hd008e9d4__0
                                  : 0U) : ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x6fU] 
                                            | (IData)(vlSelfRef.npc__DOT__is_jalr))
                                            ? ((IData)(4U) 
                                               + vlSelfRef.pc)
                                            : (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x37U]
                                                ? vlSelfRef.npc__DOT__imm
                                                : ((IData)(vlSelfRef.npc__DOT__reg_cwen)
                                                    ? 
                                                   ((0xb00U 
                                                     == 
                                                     (0xfffU 
                                                      & vlSelfRef.npc__DOT__imm))
                                                     ? vlSelfRef.npc__DOT__u_csr__DOT__mcycle
                                                     : 
                                                    ((0xb02U 
                                                      == 
                                                      (0xfffU 
                                                       & vlSelfRef.npc__DOT__imm))
                                                      ? vlSelfRef.npc__DOT__u_csr__DOT__mcycleh
                                                      : 
                                                     ((0xf11U 
                                                       == 
                                                       (0xfffU 
                                                        & vlSelfRef.npc__DOT__imm))
                                                       ? 0x79737978U
                                                       : 
                                                      ((0xf12U 
                                                        == 
                                                        (0xfffU 
                                                         & vlSelfRef.npc__DOT__imm))
                                                        ? 0x17e634bU
                                                        : 0U))))
                                                    : vlSelfRef.alu_result))))),32);
    bufp->chgIData(oldp+90,(((0xb00U == (0xfffU & vlSelfRef.npc__DOT__imm))
                              ? vlSelfRef.npc__DOT__u_csr__DOT__mcycle
                              : ((0xb02U == (0xfffU 
                                             & vlSelfRef.npc__DOT__imm))
                                  ? vlSelfRef.npc__DOT__u_csr__DOT__mcycleh
                                  : ((0xf11U == (0xfffU 
                                                 & vlSelfRef.npc__DOT__imm))
                                      ? 0x79737978U
                                      : ((0xf12U == 
                                          (0xfffU & vlSelfRef.npc__DOT__imm))
                                          ? 0x17e634bU
                                          : 0U))))),32);
    bufp->chgIData(oldp+91,(((0U == (0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                              >> 0x14U)))
                              ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                             [(0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                        >> 0x14U))])),32);
    bufp->chgIData(oldp+92,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                             [0x17U] ? vlSelfRef.pc
                              : vlSelfRef.npc__DOT__src1)),32);
    bufp->chgIData(oldp+93,(((IData)(vlSelfRef.npc__DOT__src2_is_imm)
                              ? vlSelfRef.npc__DOT__imm
                              : ((0U == (0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                                  >> 0x14U)))
                                  ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                 [(0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                            >> 0x14U))]))),32);
    bufp->chgIData(oldp+94,(((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x17U] ? vlSelfRef.pc
                               : vlSelfRef.npc__DOT__src1) 
                             + ((IData)(vlSelfRef.npc__DOT__src2_is_imm)
                                 ? vlSelfRef.npc__DOT__imm
                                 : ((0U == (0x1fU & 
                                            (vlSelfRef.npc__DOT__inst_reg 
                                             >> 0x14U)))
                                     ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                    [(0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                               >> 0x14U))])))),32);
    bufp->chgBit(oldp+95,(((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                            [0x17U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                       [0x37U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                  [0x6fU] 
                                                  | ((IData)(vlSelfRef.npc__DOT__is_jalr) 
                                                     | ((IData)(vlSelfRef.npc__DOT__is_addi) 
                                                        | ((IData)(vlSelfRef.npc__DOT__is_add) 
                                                           | ((IData)(vlSelfRef.npc__DOT__is_lw) 
                                                              | ((IData)(vlSelfRef.npc__DOT__is_lbu) 
                                                                 | (IData)(vlSelfRef.npc__DOT__reg_cwen))))))))) 
                           & (IData)(vlSelfRef.inst_valid))));
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
