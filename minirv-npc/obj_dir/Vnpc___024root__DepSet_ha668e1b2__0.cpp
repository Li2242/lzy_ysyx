// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnpc.h for the primary calling header

#include "Vnpc__pch.h"
#include "Vnpc__Syms.h"
#include "Vnpc___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnpc___024root___dump_triggers__act(Vnpc___024root* vlSelf);
#endif  // VL_DEBUG

void Vnpc___024root___eval_triggers__act(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_triggers__act\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.reset)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__reset__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vnpc___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vnpc___024unit____Vdpiimwrap_v_pmem_write_TOP____024unit(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);
void Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit(IData/*31:0*/ pc);
void Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(IData/*31:0*/ raddr, IData/*31:0*/ len, IData/*31:0*/ &v_pmem_read__Vfuncrtn);

VL_INLINE_OPT void Vnpc___024root___nba_sequent__TOP__0(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___nba_sequent__TOP__0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vfunc_v_pmem_read__0__Vfuncout;
    __Vfunc_v_pmem_read__0__Vfuncout = 0;
    IData/*31:0*/ __Vdly__npc__DOT__u_csr__DOT__mcycleh;
    __Vdly__npc__DOT__u_csr__DOT__mcycleh = 0;
    IData/*31:0*/ __Vdly__npc__DOT__u_csr__DOT__mcycle;
    __Vdly__npc__DOT__u_csr__DOT__mcycle = 0;
    IData/*31:0*/ __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0;
    __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0 = 0;
    CData/*4:0*/ __VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0;
    __VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0 = 0;
    CData/*0:0*/ __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0;
    __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 0;
    // Body
    __Vdly__npc__DOT__u_csr__DOT__mcycleh = vlSelfRef.npc__DOT__u_csr__DOT__mcycleh;
    __Vdly__npc__DOT__u_csr__DOT__mcycle = vlSelfRef.npc__DOT__u_csr__DOT__mcycle;
    if (((IData)(((0x2000U == (0x7000U & vlSelfRef.npc__DOT__inst_reg)) 
                  & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                  [0x23U])) | (IData)(((0U == (0x7000U 
                                               & vlSelfRef.npc__DOT__inst_reg)) 
                                       & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                       [0x23U])))) {
        Vnpc___024unit____Vdpiimwrap_v_pmem_write_TOP____024unit(
                                                                 (((IData)(
                                                                           ((0x2000U 
                                                                             == 
                                                                             (0x7000U 
                                                                              & vlSelfRef.npc__DOT__inst_reg)) 
                                                                            & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                                            [0x23U])) 
                                                                   | (IData)(
                                                                             ((0U 
                                                                               == 
                                                                               (0x7000U 
                                                                                & vlSelfRef.npc__DOT__inst_reg)) 
                                                                              & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                                              [0x23U])))
                                                                   ? vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0
                                                                   : 0x80000000U), 
                                                                 ((0U 
                                                                   == 
                                                                   (0x1fU 
                                                                    & (vlSelfRef.npc__DOT__inst_reg 
                                                                       >> 0x14U)))
                                                                   ? 0U
                                                                   : 
                                                                  vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                                                  [
                                                                  (0x1fU 
                                                                   & (vlSelfRef.npc__DOT__inst_reg 
                                                                      >> 0x14U))]), 
                                                                 ((IData)(
                                                                          ((0U 
                                                                            == 
                                                                            (0x7000U 
                                                                             & vlSelfRef.npc__DOT__inst_reg)) 
                                                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                                           [0x23U]))
                                                                   ? 1U
                                                                   : 0xfU));
    }
    if (((0x100073U == vlSelfRef.npc__DOT__inst_reg) 
         & (IData)(vlSelfRef.inst_valid))) {
        Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit(vlSelfRef.pc);
    }
    __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 0U;
    if (vlSelfRef.npc__DOT__reg_cwen) {
        if ((0xb00U != (0xfffU & vlSelfRef.npc__DOT__imm))) {
            if ((0xb02U == (0xfffU & vlSelfRef.npc__DOT__imm))) {
                __Vdly__npc__DOT__u_csr__DOT__mcycleh 
                    = vlSelfRef.npc__DOT__src1;
            }
        }
    }
    __Vdly__npc__DOT__u_csr__DOT__mcycleh = (IData)(
                                                    ((1ULL 
                                                      + 
                                                      (((QData)((IData)(vlSelfRef.npc__DOT__u_csr__DOT__mcycleh)) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(vlSelfRef.npc__DOT__u_csr__DOT__mcycle)))) 
                                                     >> 0x20U));
    __Vdly__npc__DOT__u_csr__DOT__mcycle = ((IData)(1U) 
                                            + vlSelfRef.npc__DOT__u_csr__DOT__mcycle);
    if (vlSelfRef.npc__DOT__reg_cwen) {
        if ((0xb00U == (0xfffU & vlSelfRef.npc__DOT__imm))) {
            __Vdly__npc__DOT__u_csr__DOT__mcycle = vlSelfRef.npc__DOT__src1;
        }
    }
    if ((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
           [0x17U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                      [0x37U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                 [0x6fU] | ((IData)(vlSelfRef.npc__DOT__is_jalr) 
                                            | ((IData)(vlSelfRef.npc__DOT__is_addi) 
                                               | ((IData)(vlSelfRef.npc__DOT__is_add) 
                                                  | ((IData)(vlSelfRef.npc__DOT__is_lw) 
                                                     | ((IData)(vlSelfRef.npc__DOT__is_lbu) 
                                                        | (IData)(vlSelfRef.npc__DOT__reg_cwen))))))))) 
          & (IData)(vlSelfRef.inst_valid)) & (0U != 
                                              (0x1fU 
                                               & (vlSelfRef.npc__DOT__inst_reg 
                                                  >> 7U))))) {
        __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0 
            = ((IData)(vlSelfRef.npc__DOT__mem_ren)
                ? ((IData)(vlSelfRef.npc__DOT__mem_ren)
                    ? vlSelfRef.npc__DOT____VdfgExtracted_hd008e9d4__0
                    : 0U) : ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x6fU] | (IData)(vlSelfRef.npc__DOT__is_jalr))
                              ? ((IData)(4U) + vlSelfRef.pc)
                              : (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                 [0x37U] ? vlSelfRef.npc__DOT__imm
                                  : ((IData)(vlSelfRef.npc__DOT__reg_cwen)
                                      ? ((0xb00U == 
                                          (0xfffU & vlSelfRef.npc__DOT__imm))
                                          ? vlSelfRef.npc__DOT__u_csr__DOT__mcycle
                                          : ((0xb02U 
                                              == (0xfffU 
                                                  & vlSelfRef.npc__DOT__imm))
                                              ? vlSelfRef.npc__DOT__u_csr__DOT__mcycleh
                                              : ((0xf11U 
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
                                      : vlSelfRef.alu_result))));
        __VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0 
            = (0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                        >> 7U));
        __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 1U;
    }
    vlSelfRef.npc__DOT__u_csr__DOT__mcycle = __Vdly__npc__DOT__u_csr__DOT__mcycle;
    vlSelfRef.npc__DOT__u_csr__DOT__mcycleh = __Vdly__npc__DOT__u_csr__DOT__mcycleh;
    if (__VdlySet__npc__DOT__u_regfile2__DOT__rf__v0) {
        vlSelfRef.npc__DOT__u_regfile2__DOT__rf[__VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0] 
            = __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0;
    }
    if (vlSelfRef.npc__DOT__ifu_state) {
        if (vlSelfRef.npc__DOT__ifu_state) {
            Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__ifu_raddr, 4U, __Vfunc_v_pmem_read__0__Vfuncout);
            vlSelfRef.inst_valid = 1U;
            vlSelfRef.npc__DOT__inst_reg = __Vfunc_v_pmem_read__0__Vfuncout;
        }
    } else {
        vlSelfRef.npc__DOT__ifu_raddr = vlSelfRef.pc;
        vlSelfRef.inst_valid = 0U;
    }
    vlSelfRef.npc__DOT__src1 = ((0U == (0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                                 >> 0xfU)))
                                 ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                [(0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                           >> 0xfU))]);
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0[vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0] = 0U;
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0[(0x7fU 
                                                                                & vlSelfRef.npc__DOT__inst_reg)] = 1U;
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0 
        = (0x7fU & vlSelfRef.npc__DOT__inst_reg);
    vlSelfRef.npc__DOT__reg_cwen = (IData)(((0x1000U 
                                             == (0x7000U 
                                                 & vlSelfRef.npc__DOT__inst_reg)) 
                                            & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x73U]));
    vlSelfRef.npc__DOT__is_add = (IData)(((0U == (0x7000U 
                                                  & vlSelfRef.npc__DOT__inst_reg)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [0x33U]));
    vlSelfRef.npc__DOT__is_jalr = (IData)(((0U == (0x7000U 
                                                   & vlSelfRef.npc__DOT__inst_reg)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x67U]));
    vlSelfRef.npc__DOT__is_addi = (IData)(((0U == (0x7000U 
                                                   & vlSelfRef.npc__DOT__inst_reg)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x13U]));
    vlSelfRef.npc__DOT__is_lw = (IData)(((0x2000U == 
                                          (0x7000U 
                                           & vlSelfRef.npc__DOT__inst_reg)) 
                                         & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                         [3U]));
    vlSelfRef.npc__DOT__is_lbu = (IData)(((0x4000U 
                                           == (0x7000U 
                                               & vlSelfRef.npc__DOT__inst_reg)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [3U]));
    vlSelfRef.npc__DOT__imm = (((- (IData)((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x13U] 
                                            | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [3U] 
                                               | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                  [0x67U] 
                                                  | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                  [0x73U]))))) 
                                & (((- (IData)((vlSelfRef.npc__DOT__inst_reg 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSelfRef.npc__DOT__inst_reg 
                                                >> 0x14U))) 
                               | ((0xfffff000U & ((- (IData)(
                                                             (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                              [0x37U] 
                                                              | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                              [0x17U]))) 
                                                  & vlSelfRef.npc__DOT__inst_reg)) 
                                  | (((- (IData)(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x6fU])) 
                                      & ((((- (IData)(
                                                      (vlSelfRef.npc__DOT__inst_reg 
                                                       >> 0x1fU))) 
                                           << 0x15U) 
                                          | (0x100000U 
                                             & (vlSelfRef.npc__DOT__inst_reg 
                                                >> 0xbU))) 
                                         | (((0xff000U 
                                              & vlSelfRef.npc__DOT__inst_reg) 
                                             | (0x800U 
                                                & (vlSelfRef.npc__DOT__inst_reg 
                                                   >> 9U))) 
                                            | (0x7feU 
                                               & (vlSelfRef.npc__DOT__inst_reg 
                                                  >> 0x14U))))) 
                                     | ((- (IData)(
                                                   vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x23U])) 
                                        & (((- (IData)(
                                                       (vlSelfRef.npc__DOT__inst_reg 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0xfe0U 
                                               & (vlSelfRef.npc__DOT__inst_reg 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelfRef.npc__DOT__inst_reg 
                                                    >> 7U))))))));
    vlSelfRef.npc__DOT__src2_is_imm = ((IData)(vlSelfRef.npc__DOT__is_addi) 
                                       | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                       [0x17U]);
    vlSelfRef.npc__DOT__mem_ren = ((IData)(vlSelfRef.npc__DOT__is_lw) 
                                   | (IData)(vlSelfRef.npc__DOT__is_lbu));
    vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0 
        = (vlSelfRef.npc__DOT__src1 + vlSelfRef.npc__DOT__imm);
    vlSelfRef.npc__DOT__raddr = ((IData)(vlSelfRef.npc__DOT__mem_ren)
                                  ? vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0
                                  : 0x80000000U);
    vlSelfRef.npc__DOT____VdfgExtracted_hd008e9d4__0 
        = ((IData)(vlSelfRef.npc__DOT__is_lbu) ? (0xffU 
                                                  & ([&]() {
                    Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 1U, vlSelfRef.__Vfunc_v_pmem_read__3__Vfuncout);
                }(), vlSelfRef.__Vfunc_v_pmem_read__3__Vfuncout))
            : ([&]() {
                Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 4U, vlSelfRef.__Vfunc_v_pmem_read__4__Vfuncout);
            }(), vlSelfRef.__Vfunc_v_pmem_read__4__Vfuncout));
}
