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
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
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
    IData/*31:0*/ __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0;
    __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0 = 0;
    CData/*4:0*/ __VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0;
    __VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0 = 0;
    CData/*0:0*/ __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0;
    __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 0;
    // Body
    if (((IData)((0x2023U == (0x707fU & vlSelfRef.npc__DOT__inst))) 
         | (IData)((0x23U == (0x707fU & vlSelfRef.npc__DOT__inst))))) {
        Vnpc___024unit____Vdpiimwrap_v_pmem_write_TOP____024unit(
                                                                 (((IData)(
                                                                           (0x2023U 
                                                                            == 
                                                                            (0x707fU 
                                                                             & vlSelfRef.npc__DOT__inst))) 
                                                                   | (IData)(
                                                                             (0x23U 
                                                                              == 
                                                                              (0x707fU 
                                                                               & vlSelfRef.npc__DOT__inst))))
                                                                   ? vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_0
                                                                   : 0x80000000U), 
                                                                 ((0U 
                                                                   == 
                                                                   (0x1fU 
                                                                    & (vlSelfRef.npc__DOT__inst 
                                                                       >> 0x14U)))
                                                                   ? 0U
                                                                   : 
                                                                  vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                                                  [
                                                                  (0x1fU 
                                                                   & (vlSelfRef.npc__DOT__inst 
                                                                      >> 0x14U))]), 
                                                                 ((IData)(
                                                                          (0x23U 
                                                                           == 
                                                                           (0x707fU 
                                                                            & vlSelfRef.npc__DOT__inst)))
                                                                   ? 1U
                                                                   : 0xfU));
    }
    if ((0x100073U == vlSelfRef.npc__DOT__inst)) {
        Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit(vlSelfRef.pc);
    }
    __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 0U;
    if ((((0x17U == (0x7fU & vlSelfRef.npc__DOT__inst)) 
          | ((0x37U == (0x7fU & vlSelfRef.npc__DOT__inst)) 
             | ((IData)(vlSelfRef.npc__DOT__reg_from_pc_4) 
                | ((IData)(vlSelfRef.npc__DOT__is_addi) 
                   | ((IData)(vlSelfRef.npc__DOT__is_add) 
                      | ((IData)(vlSelfRef.npc__DOT__mem_en) 
                         | ((IData)(vlSelfRef.npc__DOT__is_sltiu) 
                            | ((IData)(vlSelfRef.npc__DOT__is_xor) 
                               | ((IData)(vlSelfRef.npc__DOT__is_or) 
                                  | ((IData)(vlSelfRef.npc__DOT__is_sltu) 
                                     | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sub) 
                                        | (IData)(vlSelfRef.npc__DOT__is_srai)))))))))))) 
         & (0U != (0x1fU & (vlSelfRef.npc__DOT__inst 
                            >> 7U))))) {
        __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0 
            = ((IData)(vlSelfRef.npc__DOT__mem_en) ? 
               ((IData)(vlSelfRef.npc__DOT__mem_en)
                 ? vlSelfRef.npc__DOT____VdfgExtracted_hfee1d2e3__0
                 : 0U) : ((IData)(vlSelfRef.npc__DOT__reg_from_pc_4)
                           ? ((IData)(4U) + vlSelfRef.pc)
                           : ((0x37U == (0x7fU & vlSelfRef.npc__DOT__inst))
                               ? vlSelfRef.npc__DOT__imm
                               : vlSelfRef.alu_result)));
        __VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0 
            = (0x1fU & (vlSelfRef.npc__DOT__inst >> 7U));
        __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 1U;
    }
    if (__VdlySet__npc__DOT__u_regfile2__DOT__rf__v0) {
        vlSelfRef.npc__DOT__u_regfile2__DOT__rf[__VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0] 
            = __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0;
    }
    vlSelfRef.pc = ((IData)(vlSelfRef.reset) ? 0x80000000U
                     : vlSelfRef.npc__DOT__nextpc);
    Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.pc, 4U, vlSelfRef.__Vfunc_v_pmem_read__0__Vfuncout);
    vlSelfRef.npc__DOT__inst = vlSelfRef.__Vfunc_v_pmem_read__0__Vfuncout;
    vlSelfRef.npc__DOT__is_jalr = (IData)((0x67U == 
                                           (0x707fU 
                                            & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__is_lbu = (IData)((0x4003U == 
                                          (0x707fU 
                                           & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__is_xor = (IData)((0x4033U == 
                                          (0x707fU 
                                           & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__is_or = (IData)((0x6033U == 
                                         (0x707fU & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__src1 = ((0U == (0x1fU & (vlSelfRef.npc__DOT__inst 
                                                 >> 0xfU)))
                                 ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                [(0x1fU & (vlSelfRef.npc__DOT__inst 
                                           >> 0xfU))]);
    vlSelfRef.npc__DOT__is_srai = (IData)((0x40005013U 
                                           == (0xfe00707fU 
                                               & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__is_sltu = (IData)((0x3033U 
                                           == (0x707fU 
                                               & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__is_addi = (IData)((0x13U == 
                                           (0x707fU 
                                            & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__u_alu__DOT__bne = (IData)((0x1063U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__imm = (((- (IData)(((0x13U 
                                             == (0x7fU 
                                                 & vlSelfRef.npc__DOT__inst)) 
                                            | ((3U 
                                                == 
                                                (0x7fU 
                                                 & vlSelfRef.npc__DOT__inst)) 
                                               | (0x67U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)))))) 
                                & (((- (IData)((vlSelfRef.npc__DOT__inst 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSelfRef.npc__DOT__inst 
                                                >> 0x14U))) 
                               | ((0xfffff000U & ((- (IData)(
                                                             ((0x37U 
                                                               == 
                                                               (0x7fU 
                                                                & vlSelfRef.npc__DOT__inst)) 
                                                              | (0x17U 
                                                                 == 
                                                                 (0x7fU 
                                                                  & vlSelfRef.npc__DOT__inst))))) 
                                                  & vlSelfRef.npc__DOT__inst)) 
                                  | (((- (IData)((0x6fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)))) 
                                      & ((((- (IData)(
                                                      (vlSelfRef.npc__DOT__inst 
                                                       >> 0x1fU))) 
                                           << 0x15U) 
                                          | (0x100000U 
                                             & (vlSelfRef.npc__DOT__inst 
                                                >> 0xbU))) 
                                         | (((0xff000U 
                                              & vlSelfRef.npc__DOT__inst) 
                                             | (0x800U 
                                                & (vlSelfRef.npc__DOT__inst 
                                                   >> 9U))) 
                                            | (0x7feU 
                                               & (vlSelfRef.npc__DOT__inst 
                                                  >> 0x14U))))) 
                                     | (((- (IData)(
                                                    (0x63U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelfRef.npc__DOT__inst)))) 
                                         & (((- (IData)(
                                                        (vlSelfRef.npc__DOT__inst 
                                                         >> 0x1fU))) 
                                             << 0xdU) 
                                            | (((0x1000U 
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
                                                        >> 7U)))))) 
                                        | ((- (IData)(
                                                      (0x23U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelfRef.npc__DOT__inst)))) 
                                           & (((- (IData)(
                                                          (vlSelfRef.npc__DOT__inst 
                                                           >> 0x1fU))) 
                                               << 0xcU) 
                                              | ((0xfe0U 
                                                  & (vlSelfRef.npc__DOT__inst 
                                                     >> 0x14U)) 
                                                 | (0x1fU 
                                                    & (vlSelfRef.npc__DOT__inst 
                                                       >> 7U)))))))));
    vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_8 
        = (IData)((0x33U == (0x707fU & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__is_sltiu = (IData)((0x3013U 
                                            == (0x707fU 
                                                & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__reg_from_pc_4 = ((0x6fU == 
                                          (0x7fU & vlSelfRef.npc__DOT__inst)) 
                                         | (IData)(vlSelfRef.npc__DOT__is_jalr));
    vlSelfRef.npc__DOT__mem_en = ((IData)((0x2003U 
                                           == (0x707fU 
                                               & vlSelfRef.npc__DOT__inst))) 
                                  | (IData)(vlSelfRef.npc__DOT__is_lbu));
    vlSelfRef.npc__DOT__alu_src1 = ((0x17U == (0x7fU 
                                               & vlSelfRef.npc__DOT__inst))
                                     ? vlSelfRef.pc
                                     : vlSelfRef.npc__DOT__src1);
    vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_13 
        = ((IData)(vlSelfRef.npc__DOT__is_addi) | (0x17U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_0 
        = (vlSelfRef.npc__DOT__src1 + vlSelfRef.npc__DOT__imm);
    vlSelfRef.npc__DOT__is_add = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_8) 
                                  & (0U == (vlSelfRef.npc__DOT__inst 
                                            >> 0x19U)));
    vlSelfRef.npc__DOT__u_alu__DOT__sub = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_8) 
                                           & (0x20U 
                                              == (vlSelfRef.npc__DOT__inst 
                                                  >> 0x19U)));
    vlSelfRef.npc__DOT__u_alu__DOT__sltu = ((IData)(vlSelfRef.npc__DOT__is_sltiu) 
                                            | (IData)(vlSelfRef.npc__DOT__is_sltu));
    vlSelfRef.npc__DOT__alu_src2 = (((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_13) 
                                     | ((IData)(vlSelfRef.npc__DOT__is_sltiu) 
                                        | (IData)(vlSelfRef.npc__DOT__is_srai)))
                                     ? vlSelfRef.npc__DOT__imm
                                     : ((0U == (0x1fU 
                                                & (vlSelfRef.npc__DOT__inst 
                                                   >> 0x14U)))
                                         ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                        [(0x1fU & (vlSelfRef.npc__DOT__inst 
                                                   >> 0x14U))]));
    vlSelfRef.npc__DOT__raddr = ((IData)(vlSelfRef.npc__DOT__mem_en)
                                  ? vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_0
                                  : 0x80000000U);
    vlSelfRef.npc__DOT__u_alu__DOT__adder_cin = ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sltu) 
                                                 | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__bne) 
                                                    | (IData)(vlSelfRef.npc__DOT__u_alu__DOT__sub)));
    vlSelfRef.npc__DOT__u_alu__DOT__xor_result = (vlSelfRef.npc__DOT__alu_src1 
                                                  ^ vlSelfRef.npc__DOT__alu_src2);
    vlSelfRef.npc__DOT____VdfgExtracted_hfee1d2e3__0 
        = ((IData)(vlSelfRef.npc__DOT__is_lbu) ? (0xffU 
                                                  & ([&]() {
                    Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 1U, vlSelfRef.__Vfunc_v_pmem_read__3__Vfuncout);
                }(), vlSelfRef.__Vfunc_v_pmem_read__3__Vfuncout))
            : ([&]() {
                Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 4U, vlSelfRef.__Vfunc_v_pmem_read__4__Vfuncout);
            }(), vlSelfRef.__Vfunc_v_pmem_read__4__Vfuncout));
    vlSelfRef.npc__DOT__u_alu__DOT__adder_b = ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_cin)
                                                ? (~ vlSelfRef.npc__DOT__alu_src2)
                                                : vlSelfRef.npc__DOT__alu_src2);
    vlSelfRef.npc__DOT__u_alu__DOT__add_sub_result 
        = (vlSelfRef.npc__DOT__alu_src1 + (vlSelfRef.npc__DOT__u_alu__DOT__adder_b 
                                           + (IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_cin)));
    vlSelfRef.alu_result = (((- (IData)((((IData)(vlSelfRef.npc__DOT__is_add) 
                                          | (IData)(vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_13)) 
                                         | (IData)(vlSelfRef.npc__DOT__u_alu__DOT__sub)))) 
                             & vlSelfRef.npc__DOT__u_alu__DOT__add_sub_result) 
                            | ((1U & ((- (IData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sltu))) 
                                      & (~ (IData)(
                                                   (1ULL 
                                                    & (((QData)((IData)(vlSelfRef.npc__DOT__alu_src1)) 
                                                        + 
                                                        ((QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_b)) 
                                                         + (QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_cin)))) 
                                                       >> 0x20U)))))) 
                               | (((- (IData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__bne))) 
                                   & (0U != vlSelfRef.npc__DOT__u_alu__DOT__add_sub_result)) 
                                  | (((- (IData)((IData)(vlSelfRef.npc__DOT__is_xor))) 
                                      & vlSelfRef.npc__DOT__u_alu__DOT__xor_result) 
                                     | (((- (IData)((IData)(vlSelfRef.npc__DOT__is_or))) 
                                         & (vlSelfRef.npc__DOT__alu_src1 
                                            | vlSelfRef.npc__DOT__alu_src2)) 
                                        | ((- (IData)((IData)(vlSelfRef.npc__DOT__is_srai))) 
                                           & vlSelfRef.npc__DOT__u_alu__DOT__xor_result))))));
    vlSelfRef.npc__DOT__nextpc = ((IData)(vlSelfRef.npc__DOT__is_jalr)
                                   ? (0xfffffffeU & vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_0)
                                   : (((0x6fU == (0x7fU 
                                                  & vlSelfRef.npc__DOT__inst)) 
                                       | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__bne) 
                                          & (1U == vlSelfRef.alu_result)))
                                       ? (vlSelfRef.pc 
                                          + vlSelfRef.npc__DOT__imm)
                                       : ((IData)(4U) 
                                          + vlSelfRef.pc)));
}
