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
        bufp->chgCData(oldp+1,((vlSelfRef.npc__DOT__inst 
                                >> 0x19U)),7);
        bufp->chgCData(oldp+2,((0x7fU & vlSelfRef.npc__DOT__inst)),7);
        bufp->chgCData(oldp+3,((7U & (vlSelfRef.npc__DOT__inst 
                                      >> 0xcU))),3);
        bufp->chgCData(oldp+4,((0x1fU & (vlSelfRef.npc__DOT__inst 
                                         >> 0xfU))),5);
        bufp->chgCData(oldp+5,((0x1fU & (vlSelfRef.npc__DOT__inst 
                                         >> 0x14U))),5);
        bufp->chgCData(oldp+6,((0x1fU & (vlSelfRef.npc__DOT__inst 
                                         >> 7U))),5);
        bufp->chgBit(oldp+7,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x17U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                         [0x37U] | 
                                         (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [0x6fU] | 
                                          ((IData)(vlSelfRef.npc__DOT__is_jalr) 
                                           | ((IData)(vlSelfRef.npc__DOT__is_addi) 
                                              | ((IData)(vlSelfRef.npc__DOT__is_add) 
                                                 | ((IData)(vlSelfRef.npc__DOT__is_lw) 
                                                    | ((IData)(vlSelfRef.npc__DOT__is_lbu) 
                                                       | ((IData)(vlSelfRef.npc__DOT__is_sltiu) 
                                                          | ((IData)(vlSelfRef.npc__DOT__is_xor) 
                                                             | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__or0) 
                                                                | ((IData)(vlSelfRef.npc__DOT__is_sltu) 
                                                                   | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sub) 
                                                                      | ((IData)(vlSelfRef.npc__DOT__is_srai) 
                                                                         | ((IData)(vlSelfRef.npc__DOT__is_sll) 
                                                                            | ((IData)(vlSelfRef.npc__DOT__is_and) 
                                                                               | ((IData)(vlSelfRef.npc__DOT__is_xori) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_andi) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_srl) 
                                                                                | ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_21) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_slt) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_lh) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_lhu) 
                                                                                | (IData)(vlSelfRef.npc__DOT__is_sra))))))))))))))))))))))))));
        bufp->chgBit(oldp+8,(vlSelfRef.npc__DOT__mem_en));
        bufp->chgBit(oldp+9,(((IData)(((0x2000U == 
                                        (0x7000U & vlSelfRef.npc__DOT__inst)) 
                                       & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                       [0x23U])) | 
                              ((IData)(vlSelfRef.npc__DOT__is_sb) 
                               | (IData)(vlSelfRef.npc__DOT__is_sh)))));
        bufp->chgBit(oldp+10,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                               [0x6fU] | (IData)(vlSelfRef.npc__DOT__is_jalr))));
        bufp->chgBit(oldp+11,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x37U]));
        bufp->chgIData(oldp+12,(vlSelfRef.npc__DOT__imm),32);
        bufp->chgIData(oldp+13,((((- (IData)((vlSelfRef.npc__DOT__inst 
                                              >> 0x1fU))) 
                                  << 0xcU) | (vlSelfRef.npc__DOT__inst 
                                              >> 0x14U))),32);
        bufp->chgIData(oldp+14,((0xfffff000U & vlSelfRef.npc__DOT__inst)),32);
        bufp->chgIData(oldp+15,(((((- (IData)((vlSelfRef.npc__DOT__inst 
                                               >> 0x1fU))) 
                                   << 0x15U) | (0x100000U 
                                                & (vlSelfRef.npc__DOT__inst 
                                                   >> 0xbU))) 
                                 | (((0xff000U & vlSelfRef.npc__DOT__inst) 
                                     | (0x800U & (vlSelfRef.npc__DOT__inst 
                                                  >> 9U))) 
                                    | (0x7feU & (vlSelfRef.npc__DOT__inst 
                                                 >> 0x14U))))),32);
        bufp->chgIData(oldp+16,((((- (IData)((vlSelfRef.npc__DOT__inst 
                                              >> 0x1fU))) 
                                  << 0xcU) | ((0xfe0U 
                                               & (vlSelfRef.npc__DOT__inst 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelfRef.npc__DOT__inst 
                                                    >> 7U))))),32);
        bufp->chgIData(oldp+17,((((- (IData)((vlSelfRef.npc__DOT__inst 
                                              >> 0x1fU))) 
                                  << 0xdU) | (((0x1000U 
                                                & (vlSelfRef.npc__DOT__inst 
                                                   >> 0x13U)) 
                                               | (0x800U 
                                                  & (vlSelfRef.npc__DOT__inst 
                                                     << 4U))) 
                                              | ((0x7e0U 
                                                  & (vlSelfRef.npc__DOT__inst 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlSelfRef.npc__DOT__inst 
                                                       >> 7U)))))),32);
        bufp->chgBit(oldp+18,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x33U]));
        bufp->chgBit(oldp+19,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                               [0x13U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [3U] | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [0x67U]))));
        bufp->chgBit(oldp+20,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                               [0x37U] | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                               [0x17U])));
        bufp->chgBit(oldp+21,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x6fU]));
        bufp->chgBit(oldp+22,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x23U]));
        bufp->chgBit(oldp+23,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x63U]));
        bufp->chgBit(oldp+24,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x17U]));
        bufp->chgBit(oldp+25,(vlSelfRef.npc__DOT__is_add));
        bufp->chgBit(oldp+26,(vlSelfRef.npc__DOT__is_xor));
        bufp->chgBit(oldp+27,(vlSelfRef.npc__DOT__u_alu__DOT__or0));
        bufp->chgBit(oldp+28,(vlSelfRef.npc__DOT__is_sltu));
        bufp->chgBit(oldp+29,(vlSelfRef.npc__DOT__u_alu__DOT__sub));
        bufp->chgBit(oldp+30,(vlSelfRef.npc__DOT__is_sll));
        bufp->chgBit(oldp+31,(vlSelfRef.npc__DOT__is_and));
        bufp->chgBit(oldp+32,(vlSelfRef.npc__DOT__is_srl));
        bufp->chgBit(oldp+33,(vlSelfRef.npc__DOT__is_srli));
        bufp->chgBit(oldp+34,(vlSelfRef.npc__DOT__is_slt));
        bufp->chgBit(oldp+35,(vlSelfRef.npc__DOT__is_sra));
        bufp->chgBit(oldp+36,(vlSelfRef.npc__DOT__is_jalr));
        bufp->chgBit(oldp+37,(vlSelfRef.npc__DOT__is_addi));
        bufp->chgBit(oldp+38,(vlSelfRef.npc__DOT__is_lw));
        bufp->chgBit(oldp+39,(vlSelfRef.npc__DOT__is_lbu));
        bufp->chgBit(oldp+40,(vlSelfRef.npc__DOT__is_sltiu));
        bufp->chgBit(oldp+41,(vlSelfRef.npc__DOT__is_srai));
        bufp->chgBit(oldp+42,(vlSelfRef.npc__DOT__is_xori));
        bufp->chgBit(oldp+43,(vlSelfRef.npc__DOT__is_andi));
        bufp->chgBit(oldp+44,(vlSelfRef.npc__DOT__is_slli));
        bufp->chgBit(oldp+45,(vlSelfRef.npc__DOT__is_lh));
        bufp->chgBit(oldp+46,(vlSelfRef.npc__DOT__is_lhu));
        bufp->chgBit(oldp+47,((IData)(((0x2000U == 
                                        (0x7000U & vlSelfRef.npc__DOT__inst)) 
                                       & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                       [0x23U]))));
        bufp->chgBit(oldp+48,(vlSelfRef.npc__DOT__is_sh));
        bufp->chgBit(oldp+49,(vlSelfRef.npc__DOT__is_sb));
        bufp->chgBit(oldp+50,(vlSelfRef.npc__DOT__u_alu__DOT__bne));
        bufp->chgBit(oldp+51,(vlSelfRef.npc__DOT__is_bge));
        bufp->chgBit(oldp+52,(vlSelfRef.npc__DOT__u_alu__DOT__beq));
        bufp->chgBit(oldp+53,(vlSelfRef.npc__DOT__is_bgeu));
        bufp->chgBit(oldp+54,(vlSelfRef.npc__DOT__is_bltu));
        bufp->chgBit(oldp+55,(vlSelfRef.npc__DOT__is_blt));
        bufp->chgBit(oldp+56,((0x100073U == vlSelfRef.npc__DOT__inst)));
        bufp->chgWData(oldp+57,(vlSelfRef.npc__DOT__opcode_d),128);
        bufp->chgCData(oldp+61,((((((7U == (7U & (vlSelfRef.npc__DOT__inst 
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
        bufp->chgWData(oldp+62,(vlSelfRef.npc__DOT__inst31_25_d),128);
        bufp->chgSData(oldp+66,(((((((IData)(vlSelfRef.npc__DOT__is_srl) 
                                     | (IData)(vlSelfRef.npc__DOT__is_srli)) 
                                    << 0xbU) | (((IData)(vlSelfRef.npc__DOT__u_alu__DOT__beq) 
                                                 << 0xaU) 
                                                | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__slt) 
                                                   << 9U))) 
                                  | ((((IData)(vlSelfRef.npc__DOT__is_and) 
                                       | (IData)(vlSelfRef.npc__DOT__is_andi)) 
                                      << 8U) | ((((IData)(vlSelfRef.npc__DOT__is_sll) 
                                                  | (IData)(vlSelfRef.npc__DOT__is_slli)) 
                                                 << 7U) 
                                                | (((IData)(vlSelfRef.npc__DOT__is_srai) 
                                                    | (IData)(vlSelfRef.npc__DOT__is_sra)) 
                                                   << 6U)))) 
                                 | ((((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sub) 
                                      << 5U) | (((IData)(vlSelfRef.npc__DOT__u_alu__DOT__or0) 
                                                 << 4U) 
                                                | (((IData)(vlSelfRef.npc__DOT__is_xor) 
                                                    | (IData)(vlSelfRef.npc__DOT__is_xori)) 
                                                   << 3U))) 
                                    | (((IData)(vlSelfRef.npc__DOT__u_alu__DOT__bne) 
                                        << 2U) | (((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sltu) 
                                                   << 1U) 
                                                  | ((IData)(vlSelfRef.npc__DOT__is_add) 
                                                     | (IData)(vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_20))))))),12);
        bufp->chgBit(oldp+67,(((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_20) 
                               | ((IData)(vlSelfRef.npc__DOT__is_sltiu) 
                                  | ((IData)(vlSelfRef.npc__DOT__is_srai) 
                                     | ((IData)(vlSelfRef.npc__DOT__is_xori) 
                                        | ((IData)(vlSelfRef.npc__DOT__is_andi) 
                                           | (IData)(vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_21))))))));
        bufp->chgIData(oldp+68,(vlSelfRef.npc__DOT__src1),32);
        bufp->chgIData(oldp+69,(((0U == (0x1fU & (vlSelfRef.npc__DOT__inst 
                                                  >> 0x14U)))
                                  ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                 [(0x1fU & (vlSelfRef.npc__DOT__inst 
                                            >> 0x14U))])),32);
        bufp->chgIData(oldp+70,(vlSelfRef.npc__DOT__u_alu__DOT__adder_a),32);
        bufp->chgIData(oldp+71,(vlSelfRef.npc__DOT__alu_src2),32);
        bufp->chgIData(oldp+72,(((IData)(vlSelfRef.npc__DOT__mem_en)
                                  ? (((IData)(vlSelfRef.npc__DOT__is_lbu) 
                                      | (IData)(vlSelfRef.npc__DOT__is_lhu))
                                      ? vlSelfRef.npc__DOT__pmem_read_data
                                      : ((IData)(vlSelfRef.npc__DOT__is_lh)
                                          ? (((- (IData)(
                                                         (1U 
                                                          & (vlSelfRef.npc__DOT__pmem_read_data 
                                                             >> 0xfU)))) 
                                              << 0x10U) 
                                             | (0xffffU 
                                                & vlSelfRef.npc__DOT__pmem_read_data))
                                          : vlSelfRef.npc__DOT__pmem_read_data))
                                  : 0U)),32);
        bufp->chgIData(oldp+73,(vlSelfRef.npc__DOT__raddr),32);
        bufp->chgIData(oldp+74,((((IData)(((0x2000U 
                                            == (0x7000U 
                                                & vlSelfRef.npc__DOT__inst)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x23U])) 
                                  | ((IData)(vlSelfRef.npc__DOT__is_sb) 
                                     | (IData)(vlSelfRef.npc__DOT__is_sh)))
                                  ? vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0
                                  : 0x80000000U)),32);
        bufp->chgCData(oldp+75,(((IData)(vlSelfRef.npc__DOT__is_sb)
                                  ? 1U : ((IData)(vlSelfRef.npc__DOT__is_sh)
                                           ? 3U : 0xfU))),8);
        bufp->chgIData(oldp+76,(vlSelfRef.npc__DOT__pmem_read_data),32);
        bufp->chgBit(oldp+77,(((IData)(vlSelfRef.npc__DOT__is_add) 
                               | (IData)(vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_20))));
        bufp->chgBit(oldp+78,(vlSelfRef.npc__DOT__u_alu__DOT__sltu));
        bufp->chgBit(oldp+79,(((IData)(vlSelfRef.npc__DOT__is_xor) 
                               | (IData)(vlSelfRef.npc__DOT__is_xori))));
        bufp->chgBit(oldp+80,(((IData)(vlSelfRef.npc__DOT__is_srai) 
                               | (IData)(vlSelfRef.npc__DOT__is_sra))));
        bufp->chgBit(oldp+81,(((IData)(vlSelfRef.npc__DOT__is_sll) 
                               | (IData)(vlSelfRef.npc__DOT__is_slli))));
        bufp->chgBit(oldp+82,(((IData)(vlSelfRef.npc__DOT__is_and) 
                               | (IData)(vlSelfRef.npc__DOT__is_andi))));
        bufp->chgBit(oldp+83,(vlSelfRef.npc__DOT__u_alu__DOT__slt));
        bufp->chgBit(oldp+84,(((IData)(vlSelfRef.npc__DOT__is_srl) 
                               | (IData)(vlSelfRef.npc__DOT__is_srli))));
        bufp->chgIData(oldp+85,(vlSelfRef.npc__DOT__u_alu__DOT__add_sub_result),32);
        bufp->chgIData(oldp+86,((1U & (~ (IData)((1ULL 
                                                  & (((QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_a)) 
                                                      + 
                                                      ((QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_b)) 
                                                       + (QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_cin)))) 
                                                     >> 0x20U)))))),32);
        bufp->chgIData(oldp+87,((0U != vlSelfRef.npc__DOT__u_alu__DOT__add_sub_result)),32);
        bufp->chgIData(oldp+88,((vlSelfRef.npc__DOT__u_alu__DOT__adder_a 
                                 ^ vlSelfRef.npc__DOT__alu_src2)),32);
        bufp->chgIData(oldp+89,((vlSelfRef.npc__DOT__u_alu__DOT__adder_a 
                                 | vlSelfRef.npc__DOT__alu_src2)),32);
        bufp->chgIData(oldp+90,(VL_SHIFTRS_III(32,32,5, vlSelfRef.npc__DOT__u_alu__DOT__adder_a, 
                                               (0x1fU 
                                                & vlSelfRef.npc__DOT__alu_src2))),32);
        bufp->chgIData(oldp+91,((vlSelfRef.npc__DOT__u_alu__DOT__adder_a 
                                 << (0x1fU & vlSelfRef.npc__DOT__alu_src2))),32);
        bufp->chgIData(oldp+92,((vlSelfRef.npc__DOT__u_alu__DOT__adder_a 
                                 & vlSelfRef.npc__DOT__alu_src2)),32);
        bufp->chgIData(oldp+93,((1U & (((vlSelfRef.npc__DOT__u_alu__DOT__adder_a 
                                         >> 0x1fU) 
                                        == (vlSelfRef.npc__DOT__alu_src2 
                                            >> 0x1fU))
                                        ? (vlSelfRef.npc__DOT__u_alu__DOT__add_sub_result 
                                           >> 0x1fU)
                                        : (vlSelfRef.npc__DOT__u_alu__DOT__adder_a 
                                           >> 0x1fU)))),32);
        bufp->chgIData(oldp+94,((1U & (~ (0U != vlSelfRef.npc__DOT__u_alu__DOT__add_sub_result)))),32);
        bufp->chgIData(oldp+95,((vlSelfRef.npc__DOT__u_alu__DOT__adder_a 
                                 >> (0x1fU & vlSelfRef.npc__DOT__alu_src2))),32);
        bufp->chgIData(oldp+96,(vlSelfRef.npc__DOT__u_alu__DOT__adder_b),32);
        bufp->chgBit(oldp+97,(vlSelfRef.npc__DOT__u_alu__DOT__adder_cin));
        bufp->chgBit(oldp+98,((1U & (IData)((1ULL & 
                                             (((QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_a)) 
                                               + ((QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_b)) 
                                                  + (QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_cin)))) 
                                              >> 0x20U))))));
        bufp->chgIData(oldp+99,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[0]),32);
        bufp->chgIData(oldp+100,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[1]),32);
        bufp->chgIData(oldp+101,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[2]),32);
        bufp->chgIData(oldp+102,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[3]),32);
        bufp->chgIData(oldp+103,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[4]),32);
        bufp->chgIData(oldp+104,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[5]),32);
        bufp->chgIData(oldp+105,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[6]),32);
        bufp->chgIData(oldp+106,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[7]),32);
        bufp->chgIData(oldp+107,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[8]),32);
        bufp->chgIData(oldp+108,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[9]),32);
        bufp->chgIData(oldp+109,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[10]),32);
        bufp->chgIData(oldp+110,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[11]),32);
        bufp->chgIData(oldp+111,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[12]),32);
        bufp->chgIData(oldp+112,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[13]),32);
        bufp->chgIData(oldp+113,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[14]),32);
        bufp->chgIData(oldp+114,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[15]),32);
        bufp->chgIData(oldp+115,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[16]),32);
        bufp->chgIData(oldp+116,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[17]),32);
        bufp->chgIData(oldp+117,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[18]),32);
        bufp->chgIData(oldp+118,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[19]),32);
        bufp->chgIData(oldp+119,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[20]),32);
        bufp->chgIData(oldp+120,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[21]),32);
        bufp->chgIData(oldp+121,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[22]),32);
        bufp->chgIData(oldp+122,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[23]),32);
        bufp->chgIData(oldp+123,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[24]),32);
        bufp->chgIData(oldp+124,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[25]),32);
        bufp->chgIData(oldp+125,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[26]),32);
        bufp->chgIData(oldp+126,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[27]),32);
        bufp->chgIData(oldp+127,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[28]),32);
        bufp->chgIData(oldp+128,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[29]),32);
        bufp->chgIData(oldp+129,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[30]),32);
        bufp->chgIData(oldp+130,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+131,(vlSelfRef.clk));
    bufp->chgBit(oldp+132,(vlSelfRef.reset));
    bufp->chgIData(oldp+133,(vlSelfRef.alu_result),32);
    bufp->chgIData(oldp+134,(vlSelfRef.pc),32);
    bufp->chgIData(oldp+135,(((IData)(vlSelfRef.npc__DOT__is_jalr)
                               ? (0xfffffffeU & vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0)
                               : ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                   [0x6fU] | ((((IData)(vlSelfRef.npc__DOT__u_alu__DOT__bne) 
                                                | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__beq) 
                                                   | ((IData)(vlSelfRef.npc__DOT__is_bltu) 
                                                      | (IData)(vlSelfRef.npc__DOT__is_blt)))) 
                                               & (1U 
                                                  == vlSelfRef.alu_result)) 
                                              | (((IData)(vlSelfRef.npc__DOT__is_bgeu) 
                                                  | (IData)(vlSelfRef.npc__DOT__is_bge)) 
                                                 & (0U 
                                                    == vlSelfRef.alu_result))))
                                   ? (vlSelfRef.pc 
                                      + vlSelfRef.npc__DOT__imm)
                                   : ((IData)(4U) + vlSelfRef.pc)))),32);
    bufp->chgBit(oldp+136,(((((IData)(vlSelfRef.npc__DOT__u_alu__DOT__bne) 
                              | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__beq) 
                                 | ((IData)(vlSelfRef.npc__DOT__is_bltu) 
                                    | (IData)(vlSelfRef.npc__DOT__is_blt)))) 
                             & (1U == vlSelfRef.alu_result)) 
                            | (((IData)(vlSelfRef.npc__DOT__is_bgeu) 
                                | (IData)(vlSelfRef.npc__DOT__is_bge)) 
                               & (0U == vlSelfRef.alu_result)))));
    bufp->chgIData(oldp+137,(((IData)(vlSelfRef.npc__DOT__mem_en)
                               ? ((IData)(vlSelfRef.npc__DOT__mem_en)
                                   ? (((IData)(vlSelfRef.npc__DOT__is_lbu) 
                                       | (IData)(vlSelfRef.npc__DOT__is_lhu))
                                       ? vlSelfRef.npc__DOT__pmem_read_data
                                       : ((IData)(vlSelfRef.npc__DOT__is_lh)
                                           ? (((- (IData)(
                                                          (1U 
                                                           & (vlSelfRef.npc__DOT__pmem_read_data 
                                                              >> 0xfU)))) 
                                               << 0x10U) 
                                              | (0xffffU 
                                                 & vlSelfRef.npc__DOT__pmem_read_data))
                                           : vlSelfRef.npc__DOT__pmem_read_data))
                                   : 0U) : ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                             [0x6fU] 
                                             | (IData)(vlSelfRef.npc__DOT__is_jalr))
                                             ? ((IData)(4U) 
                                                + vlSelfRef.pc)
                                             : (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                [0x37U]
                                                 ? vlSelfRef.npc__DOT__imm
                                                 : vlSelfRef.alu_result)))),32);
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
