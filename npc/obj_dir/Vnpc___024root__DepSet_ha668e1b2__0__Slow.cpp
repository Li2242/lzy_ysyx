// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnpc.h for the primary calling header

#include "Vnpc__pch.h"
#include "Vnpc__Syms.h"
#include "Vnpc___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnpc___024root___dump_triggers__stl(Vnpc___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vnpc___024root___eval_triggers__stl(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_triggers__stl\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vnpc___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

void Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(IData/*31:0*/ raddr, IData/*31:0*/ len, IData/*31:0*/ &v_pmem_read__Vfuncrtn);

VL_ATTR_COLD void Vnpc___024root___stl_sequent__TOP__0(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___stl_sequent__TOP__0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.pc, 4U, vlSelfRef.__Vfunc_v_pmem_read__0__Vfuncout);
    vlSelfRef.npc__DOT__inst = vlSelfRef.__Vfunc_v_pmem_read__0__Vfuncout;
    vlSelfRef.npc__DOT__is_add = (IData)((0x33U == 
                                          (0x707fU 
                                           & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__is_jalr = (IData)((0x67U == 
                                           (0x707fU 
                                            & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__is_addi = (IData)((0x13U == 
                                           (0x707fU 
                                            & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__is_lbu = (IData)((0x4003U == 
                                          (0x707fU 
                                           & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__src1 = ((0U == (0x1fU & (vlSelfRef.npc__DOT__inst 
                                                 >> 0xfU)))
                                 ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                [(0x1fU & (vlSelfRef.npc__DOT__inst 
                                           >> 0xfU))]);
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
                                                    >> 7U))))))));
    vlSelfRef.npc__DOT__reg_from_pc_4 = ((0x6fU == 
                                          (0x7fU & vlSelfRef.npc__DOT__inst)) 
                                         | (IData)(vlSelfRef.npc__DOT__is_jalr));
    vlSelfRef.npc__DOT__src2_is_imm = ((IData)(vlSelfRef.npc__DOT__is_addi) 
                                       | (0x17U == 
                                          (0x7fU & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__mem_en = ((IData)((0x2003U 
                                           == (0x707fU 
                                               & vlSelfRef.npc__DOT__inst))) 
                                  | (IData)(vlSelfRef.npc__DOT__is_lbu));
    vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_0 
        = (vlSelfRef.npc__DOT__src1 + vlSelfRef.npc__DOT__imm);
    vlSelfRef.alu_result = ((- (IData)(((IData)(vlSelfRef.npc__DOT__is_add) 
                                        | (IData)(vlSelfRef.npc__DOT__src2_is_imm)))) 
                            & (((0x17U == (0x7fU & vlSelfRef.npc__DOT__inst))
                                 ? vlSelfRef.pc : vlSelfRef.npc__DOT__src1) 
                               + ((IData)(vlSelfRef.npc__DOT__src2_is_imm)
                                   ? vlSelfRef.npc__DOT__imm
                                   : ((0U == (0x1fU 
                                              & (vlSelfRef.npc__DOT__inst 
                                                 >> 0x14U)))
                                       ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                      [(0x1fU & (vlSelfRef.npc__DOT__inst 
                                                 >> 0x14U))]))));
    vlSelfRef.npc__DOT__nextpc = ((IData)(vlSelfRef.npc__DOT__is_jalr)
                                   ? (0xfffffffeU & vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_0)
                                   : ((0x6fU == (0x7fU 
                                                 & vlSelfRef.npc__DOT__inst))
                                       ? (vlSelfRef.pc 
                                          + vlSelfRef.npc__DOT__imm)
                                       : ((IData)(4U) 
                                          + vlSelfRef.pc)));
    vlSelfRef.npc__DOT__raddr = ((IData)(vlSelfRef.npc__DOT__mem_en)
                                  ? vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_0
                                  : 0x80000000U);
    vlSelfRef.npc__DOT____VdfgExtracted_hfee1d2e3__0 
        = ((IData)(vlSelfRef.npc__DOT__is_lbu) ? (0xffU 
                                                  & ([&]() {
                    Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 1U, vlSelfRef.__Vfunc_v_pmem_read__3__Vfuncout);
                }(), vlSelfRef.__Vfunc_v_pmem_read__3__Vfuncout))
            : ([&]() {
                Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 4U, vlSelfRef.__Vfunc_v_pmem_read__4__Vfuncout);
            }(), vlSelfRef.__Vfunc_v_pmem_read__4__Vfuncout));
}
