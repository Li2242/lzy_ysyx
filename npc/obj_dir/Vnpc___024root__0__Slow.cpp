// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnpc.h for the primary calling header

#include "Vnpc__pch.h"

VL_ATTR_COLD void Vnpc___024root___eval_static__TOP(Vnpc___024root* vlSelf);

VL_ATTR_COLD void Vnpc___024root___eval_static(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_static\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vnpc___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vnpc___024root___eval_static__TOP(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_static__TOP\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0 = 0U;
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0.fill(0U);
    vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0 = 0U;
    vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0.fill(0U);
}

VL_ATTR_COLD void Vnpc___024root___eval_initial(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_initial\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vnpc___024root___eval_final(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_final\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnpc___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vnpc___024root___eval_phase__stl(Vnpc___024root* vlSelf);

VL_ATTR_COLD void Vnpc___024root___eval_settle(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_settle\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vnpc___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("vsrc/npc.v", 5, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vnpc___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vnpc___024root___eval_triggers__stl(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_triggers__stl\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vnpc___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vnpc___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnpc___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vnpc___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vnpc___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(IData/*31:0*/ raddr, IData/*31:0*/ len, IData/*31:0*/ &v_pmem_read__Vfuncrtn);

VL_ATTR_COLD void Vnpc___024root___stl_sequent__TOP__0(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___stl_sequent__TOP__0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.pc, 4U, vlSelfRef.__Vfunc_v_pmem_read__0__Vfuncout);
    vlSelfRef.npc__DOT__inst = vlSelfRef.__Vfunc_v_pmem_read__0__Vfuncout;
    vlSelfRef.npc__DOT__csr_raddr = ((0x30200073U == vlSelfRef.npc__DOT__inst)
                                      ? 0x00000341U
                                      : ((0x00000073U 
                                          == vlSelfRef.npc__DOT__inst)
                                          ? 0x00000305U
                                          : (vlSelfRef.npc__DOT__inst 
                                             >> 0x00000014U)));
    vlSelfRef.npc__DOT__u_regfile2__DOT__rdata1 = (
                                                   (0U 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSelfRef.npc__DOT__inst 
                                                        >> 0x0000000fU)))
                                                    ? 0U
                                                    : 
                                                   vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                                   [
                                                   (0x0000001fU 
                                                    & (vlSelfRef.npc__DOT__inst 
                                                       >> 0x0000000fU))]);
    vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0[vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0] = 0U;
    vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0[(vlSelfRef.npc__DOT__inst 
                                                                                >> 0x00000019U)] = 1U;
    vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0 
        = (vlSelfRef.npc__DOT__inst >> 0x00000019U);
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0[vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0] = 0U;
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0[(0x0000007fU 
                                                                                & vlSelfRef.npc__DOT__inst)] = 1U;
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0 
        = (0x0000007fU & vlSelfRef.npc__DOT__inst);
    vlSelfRef.npc__DOT__u_csr__DOT__crdata = ((0x0300U 
                                               == (IData)(vlSelfRef.npc__DOT__csr_raddr))
                                               ? vlSelfRef.npc__DOT__u_csr__DOT__mstatus
                                               : ((0x0305U 
                                                   == (IData)(vlSelfRef.npc__DOT__csr_raddr))
                                                   ? vlSelfRef.npc__DOT__u_csr__DOT__mtvec
                                                   : 
                                                  ((0x0341U 
                                                    == (IData)(vlSelfRef.npc__DOT__csr_raddr))
                                                    ? vlSelfRef.npc__DOT__u_csr__DOT__mepc
                                                    : 
                                                   ((0x0342U 
                                                     == (IData)(vlSelfRef.npc__DOT__csr_raddr))
                                                     ? vlSelfRef.npc__DOT__u_csr__DOT__mcause
                                                     : 0U))));
    vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_8 
        = (IData)(((0x00001000U == (0x00007000U & vlSelfRef.npc__DOT__inst)) 
                   & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                   [0U]));
    vlSelfRef.npc__DOT__is_sb = (IData)(((0U == (0x00007000U 
                                                 & vlSelfRef.npc__DOT__inst)) 
                                         & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                         [0x23U]));
    vlSelfRef.npc__DOT__is_sh = (IData)(((0x00001000U 
                                          == (0x00007000U 
                                              & vlSelfRef.npc__DOT__inst)) 
                                         & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                         [0x23U]));
    vlSelfRef.npc__DOT__is_csrrw = (IData)(((0x00001000U 
                                             == (0x00007000U 
                                                 & vlSelfRef.npc__DOT__inst)) 
                                            & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x73U]));
    vlSelfRef.npc__DOT__is_csrrs = (IData)(((0x00002000U 
                                             == (0x00007000U 
                                                 & vlSelfRef.npc__DOT__inst)) 
                                            & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x73U]));
    vlSelfRef.npc__DOT__is_jalr = (IData)(((0U == (0x00007000U 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x67U]));
    vlSelfRef.npc__DOT__is_lh = (IData)(((0x00001000U 
                                          == (0x00007000U 
                                              & vlSelfRef.npc__DOT__inst)) 
                                         & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                         [3U]));
    vlSelfRef.npc__DOT__is_lhu = (IData)(((0x00005000U 
                                           == (0x00007000U 
                                               & vlSelfRef.npc__DOT__inst)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [3U]));
    vlSelfRef.npc__DOT__is_lbu = (IData)(((0x00004000U 
                                           == (0x00007000U 
                                               & vlSelfRef.npc__DOT__inst)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [3U]));
    vlSelfRef.npc__DOT__is_xor = (IData)(((0x00004000U 
                                           == (0x00007000U 
                                               & vlSelfRef.npc__DOT__inst)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [0x33U]));
    vlSelfRef.npc__DOT__is_or = (IData)(((0x00006000U 
                                          == (0x00007000U 
                                              & vlSelfRef.npc__DOT__inst)) 
                                         & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                         [0x33U]));
    vlSelfRef.npc__DOT__is_and = (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                  [0x33U] & (IData)(
                                                    ((0x00007000U 
                                                      == 
                                                      (0x00007000U 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0U])));
    vlSelfRef.npc__DOT__u_alu__DOT__src1 = (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x17U]
                                             ? vlSelfRef.pc
                                             : vlSelfRef.npc__DOT__u_regfile2__DOT__rdata1);
    vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_3 
        = (IData)(((0x00005000U == (0x00007000U & vlSelfRef.npc__DOT__inst)) 
                   & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                   [0x33U]));
    vlSelfRef.npc__DOT__is_xori = (IData)(((0x00004000U 
                                            == (0x00007000U 
                                                & vlSelfRef.npc__DOT__inst)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x13U]));
    vlSelfRef.npc__DOT__is_andi = (IData)(((0x00007000U 
                                            == (0x00007000U 
                                                & vlSelfRef.npc__DOT__inst)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x13U]));
    vlSelfRef.npc__DOT__is_ori = (IData)(((0x00006000U 
                                           == (0x00007000U 
                                               & vlSelfRef.npc__DOT__inst)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [0x13U]));
    vlSelfRef.npc__DOT__is_addi = (IData)(((0U == (0x00007000U 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x13U]));
    vlSelfRef.npc__DOT__imm = (((- (IData)((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x13U] 
                                            | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [3U] 
                                               | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                  [0x67U] 
                                                  | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                  [0x73U]))))) 
                                & (((- (IData)((vlSelfRef.npc__DOT__inst 
                                                >> 0x0000001fU))) 
                                    << 0x0000000cU) 
                                   | (vlSelfRef.npc__DOT__inst 
                                      >> 0x00000014U))) 
                               | ((0xfffff000U & ((- (IData)(
                                                             (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                              [0x37U] 
                                                              | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                              [0x17U]))) 
                                                  & vlSelfRef.npc__DOT__inst)) 
                                  | (((- (IData)(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x6fU])) 
                                      & ((((0x00000ffeU 
                                            & ((- (IData)(
                                                          (vlSelfRef.npc__DOT__inst 
                                                           >> 0x0000001fU))) 
                                               << 1U)) 
                                           | (vlSelfRef.npc__DOT__inst 
                                              >> 0x0000001fU)) 
                                          << 0x00000014U) 
                                         | ((((0x000001feU 
                                               & (vlSelfRef.npc__DOT__inst 
                                                  >> 0x0000000bU)) 
                                              | (1U 
                                                 & (vlSelfRef.npc__DOT__inst 
                                                    >> 0x00000014U))) 
                                             << 0x0000000bU) 
                                            | (0x000007feU 
                                               & (vlSelfRef.npc__DOT__inst 
                                                  >> 0x00000014U))))) 
                                     | (((- (IData)(
                                                    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                    [0x63U])) 
                                         & (((- (IData)(
                                                        (vlSelfRef.npc__DOT__inst 
                                                         >> 0x0000001fU))) 
                                             << 0x0000000dU) 
                                            | ((((2U 
                                                  & (vlSelfRef.npc__DOT__inst 
                                                     >> 0x0000001eU)) 
                                                 | (1U 
                                                    & (vlSelfRef.npc__DOT__inst 
                                                       >> 7U))) 
                                                << 0x0000000bU) 
                                               | ((0x000007e0U 
                                                   & (vlSelfRef.npc__DOT__inst 
                                                      >> 0x00000014U)) 
                                                  | (0x0000001eU 
                                                     & (vlSelfRef.npc__DOT__inst 
                                                        >> 7U)))))) 
                                        | ((- (IData)(
                                                      vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                      [0x23U])) 
                                           & (((- (IData)(
                                                          (vlSelfRef.npc__DOT__inst 
                                                           >> 0x0000001fU))) 
                                               << 0x0000000cU) 
                                              | ((0x00000fe0U 
                                                  & (vlSelfRef.npc__DOT__inst 
                                                     >> 0x00000014U)) 
                                                 | (0x0000001fU 
                                                    & (vlSelfRef.npc__DOT__inst 
                                                       >> 7U)))))))));
    vlSelfRef.npc__DOT__is_sltu = (IData)(((0x00003000U 
                                            == (0x00007000U 
                                                & vlSelfRef.npc__DOT__inst)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x33U]));
    vlSelfRef.npc__DOT__is_slt = (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                  [0x33U] & (IData)(
                                                    ((0x00002000U 
                                                      == 
                                                      (0x00007000U 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0U])));
    vlSelfRef.npc__DOT__u_alu__DOT__bne = (IData)((
                                                   (0x00001000U 
                                                    == 
                                                    (0x00007000U 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x63U]));
    vlSelfRef.npc__DOT__u_alu__DOT__beq = (IData)((
                                                   (0U 
                                                    == 
                                                    (0x00007000U 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x63U]));
    vlSelfRef.npc__DOT__is_blt = (IData)(((0x00004000U 
                                           == (0x00007000U 
                                               & vlSelfRef.npc__DOT__inst)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [0x63U]));
    vlSelfRef.npc__DOT__is_bge = (IData)(((0x00005000U 
                                           == (0x00007000U 
                                               & vlSelfRef.npc__DOT__inst)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [0x63U]));
    vlSelfRef.npc__DOT__is_bltu = (IData)(((0x00006000U 
                                            == (0x00007000U 
                                                & vlSelfRef.npc__DOT__inst)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x63U]));
    vlSelfRef.npc__DOT__is_bgeu = (IData)(((0x00007000U 
                                            == (0x00007000U 
                                                & vlSelfRef.npc__DOT__inst)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x63U]));
    vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_2 
        = (IData)(((0U == (0x00007000U & vlSelfRef.npc__DOT__inst)) 
                   & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                   [0x33U]));
    vlSelfRef.npc__DOT__is_sltiu = (IData)(((0x00003000U 
                                             == (0x00007000U 
                                                 & vlSelfRef.npc__DOT__inst)) 
                                            & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x13U]));
    vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_4 
        = (IData)(((0x00005000U == (0x00007000U & vlSelfRef.npc__DOT__inst)) 
                   & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                   [0x13U]));
    vlSelfRef.npc__DOT__is_sll = (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                  [0x33U] & (IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_8));
    vlSelfRef.npc__DOT__is_slli = (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                   [0x13U] & (IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_8));
    vlSelfRef.npc__DOT__reg_cwen = ((IData)(vlSelfRef.npc__DOT__is_csrrw) 
                                    | (IData)(vlSelfRef.npc__DOT__is_csrrs));
    vlSelfRef.npc__DOT__csr_wdata = ((IData)(vlSelfRef.npc__DOT__is_csrrw)
                                      ? vlSelfRef.npc__DOT__u_regfile2__DOT__rdata1
                                      : ((IData)(vlSelfRef.npc__DOT__is_csrrs)
                                          ? (vlSelfRef.npc__DOT__u_csr__DOT__crdata 
                                             | vlSelfRef.npc__DOT__u_regfile2__DOT__rdata1)
                                          : 0U));
    vlSelfRef.npc__DOT__reg_from_pc_4 = (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                         [0x6fU] | (IData)(vlSelfRef.npc__DOT__is_jalr));
    vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_5 
        = ((IData)(((0x00002000U == (0x00007000U & vlSelfRef.npc__DOT__inst)) 
                    & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                    [3U])) | (IData)(vlSelfRef.npc__DOT__is_lbu));
    vlSelfRef.npc__DOT__is_sra = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_3) 
                                  & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                  [0x20U]);
    vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_6 
        = ((IData)(vlSelfRef.npc__DOT__is_addi) | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
           [0x17U]);
    vlSelfRef.addr = (vlSelfRef.npc__DOT__u_regfile2__DOT__rdata1 
                      + vlSelfRef.npc__DOT__imm);
    vlSelfRef.npc__DOT__u_alu__DOT__slt = ((IData)(vlSelfRef.npc__DOT__is_slt) 
                                           | ((IData)(vlSelfRef.npc__DOT__is_bge) 
                                              | (IData)(vlSelfRef.npc__DOT__is_blt)));
    vlSelfRef.npc__DOT__is_add = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_2) 
                                  & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                  [0U]);
    vlSelfRef.npc__DOT__u_alu__DOT__sub = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_2) 
                                           & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x20U]);
    vlSelfRef.npc__DOT__u_alu__DOT__sltu = ((IData)(vlSelfRef.npc__DOT__is_sltiu) 
                                            | ((IData)(vlSelfRef.npc__DOT__is_sltu) 
                                               | ((IData)(vlSelfRef.npc__DOT__is_bgeu) 
                                                  | (IData)(vlSelfRef.npc__DOT__is_bltu))));
    vlSelfRef.npc__DOT__is_srai = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_4) 
                                   & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                   [0x20U]);
    vlSelfRef.npc__DOT__is_srli = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_4) 
                                   & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                   [0U]);
    vlSelfRef.npc__DOT__mem_en = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_5) 
                                  | ((IData)(vlSelfRef.npc__DOT__is_lh) 
                                     | (IData)(vlSelfRef.npc__DOT__is_lhu)));
    vlSelfRef.npc__DOT__u_alu__DOT__adder_cin = ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sltu) 
                                                 | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__bne) 
                                                    | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sub) 
                                                       | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__slt) 
                                                          | (IData)(vlSelfRef.npc__DOT__u_alu__DOT__beq)))));
    vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_7 
        = (((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_3) 
            & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
            [0U]) | (IData)(vlSelfRef.npc__DOT__is_srli));
    vlSelfRef.npc__DOT__u_alu__DOT__src2 = (((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_6) 
                                             | ((IData)(vlSelfRef.npc__DOT__is_sltiu) 
                                                | ((IData)(vlSelfRef.npc__DOT__is_srai) 
                                                   | ((IData)(vlSelfRef.npc__DOT__is_xori) 
                                                      | ((IData)(vlSelfRef.npc__DOT__is_andi) 
                                                         | ((IData)(vlSelfRef.npc__DOT__is_srli) 
                                                            | ((IData)(vlSelfRef.npc__DOT__is_slli) 
                                                               | (IData)(vlSelfRef.npc__DOT__is_ori))))))))
                                             ? vlSelfRef.npc__DOT__imm
                                             : ((0U 
                                                 == 
                                                 (0x0000001fU 
                                                  & (vlSelfRef.npc__DOT__inst 
                                                     >> 0x00000014U)))
                                                 ? 0U
                                                 : 
                                                vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                                [(0x0000001fU 
                                                  & (vlSelfRef.npc__DOT__inst 
                                                     >> 0x00000014U))]));
    vlSelfRef.npc__DOT__raddr = ((IData)(vlSelfRef.npc__DOT__mem_en)
                                  ? vlSelfRef.addr : 0x80000000U);
    vlSelfRef.npc__DOT__u_alu__DOT__adder_b = ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_cin)
                                                ? (~ vlSelfRef.npc__DOT__u_alu__DOT__src2)
                                                : vlSelfRef.npc__DOT__u_alu__DOT__src2);
    vlSelfRef.npc__DOT__pmem_read_data = ((IData)(vlSelfRef.npc__DOT__is_lbu)
                                           ? ([&]() {
                Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 1U, vlSelfRef.__Vfunc_v_pmem_read__1__Vfuncout);
            }(), vlSelfRef.__Vfunc_v_pmem_read__1__Vfuncout)
                                           : (((IData)(vlSelfRef.npc__DOT__is_lh) 
                                               | (IData)(vlSelfRef.npc__DOT__is_lhu))
                                               ? ([&]() {
                    Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 2U, vlSelfRef.__Vfunc_v_pmem_read__2__Vfuncout);
                }(), vlSelfRef.__Vfunc_v_pmem_read__2__Vfuncout)
                                               : ([&]() {
                    Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 4U, vlSelfRef.__Vfunc_v_pmem_read__3__Vfuncout);
                }(), vlSelfRef.__Vfunc_v_pmem_read__3__Vfuncout)));
    vlSelfRef.npc__DOT__u_alu__DOT__adder_result = 
        (vlSelfRef.npc__DOT__u_alu__DOT__src1 + (vlSelfRef.npc__DOT__u_alu__DOT__adder_b 
                                                 + (IData)((QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_cin)))));
    vlSelfRef.alu_result = (((- (IData)((((IData)(vlSelfRef.npc__DOT__is_add) 
                                          | (IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_6)) 
                                         | (IData)(vlSelfRef.npc__DOT__u_alu__DOT__sub)))) 
                             & vlSelfRef.npc__DOT__u_alu__DOT__adder_result) 
                            | ((1U & ((- (IData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sltu))) 
                                      & (~ (IData)(
                                                   (1ULL 
                                                    & (((QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__src1)) 
                                                        + 
                                                        ((QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_b)) 
                                                         + (QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_cin)))) 
                                                       >> 0x00000020U)))))) 
                               | (((- (IData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__bne))) 
                                   & (0U != vlSelfRef.npc__DOT__u_alu__DOT__adder_result)) 
                                  | (((- (IData)(((IData)(vlSelfRef.npc__DOT__is_xor) 
                                                  | (IData)(vlSelfRef.npc__DOT__is_xori)))) 
                                      & (vlSelfRef.npc__DOT__u_alu__DOT__src1 
                                         ^ vlSelfRef.npc__DOT__u_alu__DOT__src2)) 
                                     | (((- (IData)(
                                                    ((IData)(vlSelfRef.npc__DOT__is_or) 
                                                     | (IData)(vlSelfRef.npc__DOT__is_ori)))) 
                                         & (vlSelfRef.npc__DOT__u_alu__DOT__src1 
                                            | vlSelfRef.npc__DOT__u_alu__DOT__src2)) 
                                        | (((- (IData)(
                                                       ((IData)(vlSelfRef.npc__DOT__is_srai) 
                                                        | (IData)(vlSelfRef.npc__DOT__is_sra)))) 
                                            & VL_SHIFTRS_III(32,32,5, vlSelfRef.npc__DOT__u_alu__DOT__src1, 
                                                             (0x0000001fU 
                                                              & vlSelfRef.npc__DOT__u_alu__DOT__src2))) 
                                           | (((- (IData)(
                                                          ((IData)(vlSelfRef.npc__DOT__is_sll) 
                                                           | (IData)(vlSelfRef.npc__DOT__is_slli)))) 
                                               & (vlSelfRef.npc__DOT__u_alu__DOT__src1 
                                                  << 
                                                  (0x0000001fU 
                                                   & vlSelfRef.npc__DOT__u_alu__DOT__src2))) 
                                              | (((- (IData)(
                                                             ((IData)(vlSelfRef.npc__DOT__is_and) 
                                                              | (IData)(vlSelfRef.npc__DOT__is_andi)))) 
                                                  & (vlSelfRef.npc__DOT__u_alu__DOT__src1 
                                                     & vlSelfRef.npc__DOT__u_alu__DOT__src2)) 
                                                 | ((1U 
                                                     & ((- (IData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__slt))) 
                                                        & (((vlSelfRef.npc__DOT__u_alu__DOT__src1 
                                                             >> 0x0000001fU) 
                                                            == 
                                                            (vlSelfRef.npc__DOT__u_alu__DOT__src2 
                                                             >> 0x0000001fU))
                                                            ? 
                                                           (vlSelfRef.npc__DOT__u_alu__DOT__adder_result 
                                                            >> 0x0000001fU)
                                                            : 
                                                           (vlSelfRef.npc__DOT__u_alu__DOT__src1 
                                                            >> 0x0000001fU)))) 
                                                    | ((1U 
                                                        & ((- (IData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__beq))) 
                                                           & (~ 
                                                              (0U 
                                                               != vlSelfRef.npc__DOT__u_alu__DOT__adder_result)))) 
                                                       | ((- (IData)((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_7))) 
                                                          & (vlSelfRef.npc__DOT__u_alu__DOT__src1 
                                                             >> 
                                                             (0x0000001fU 
                                                              & vlSelfRef.npc__DOT__u_alu__DOT__src2)))))))))))));
    vlSelfRef.npc__DOT__nextpc = ((IData)(vlSelfRef.npc__DOT__is_jalr)
                                   ? (0xfffffffeU & vlSelfRef.addr)
                                   : (((0x30200073U 
                                        == vlSelfRef.npc__DOT__inst) 
                                       | (0x00000073U 
                                          == vlSelfRef.npc__DOT__inst))
                                       ? vlSelfRef.npc__DOT__u_csr__DOT__crdata
                                       : ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x6fU] 
                                           | ((((IData)(vlSelfRef.npc__DOT__u_alu__DOT__bne) 
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
                                           : ((IData)(4U) 
                                              + vlSelfRef.pc))));
}

VL_ATTR_COLD void Vnpc___024root___eval_stl(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_stl\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vnpc___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vnpc___024root___eval_phase__stl(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_phase__stl\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vnpc___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vnpc___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vnpc___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vnpc___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnpc___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vnpc___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vnpc___024root___ctor_var_reset(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___ctor_var_reset\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15326351562492354909ull);
    vlSelf->pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4211327832146562899ull);
    vlSelf->addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14934084843038794831ull);
    vlSelf->npc__DOT__nextpc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13448463068007023365ull);
    vlSelf->npc__DOT__inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13484185947400506850ull);
    vlSelf->npc__DOT__reg_cwen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7642231643570232800ull);
    vlSelf->npc__DOT__mem_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6977832723820035533ull);
    vlSelf->npc__DOT__reg_from_pc_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11601376165023514718ull);
    vlSelf->npc__DOT__imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3403450650843488731ull);
    vlSelf->npc__DOT__is_add = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7113134690467923886ull);
    vlSelf->npc__DOT__is_xor = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16497246662640902904ull);
    vlSelf->npc__DOT__is_or = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14470214166798668838ull);
    vlSelf->npc__DOT__is_sltu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7105619691891532568ull);
    vlSelf->npc__DOT__is_sll = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17740457191497796115ull);
    vlSelf->npc__DOT__is_and = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14564807147912235218ull);
    vlSelf->npc__DOT__is_srli = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1557024625016929814ull);
    vlSelf->npc__DOT__is_slt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9371827908278391710ull);
    vlSelf->npc__DOT__is_sra = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6832702589684493582ull);
    vlSelf->npc__DOT__is_jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16619542919619024910ull);
    vlSelf->npc__DOT__is_addi = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18095654288942725152ull);
    vlSelf->npc__DOT__is_lbu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3669384594204784412ull);
    vlSelf->npc__DOT__is_sltiu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1594603236580943049ull);
    vlSelf->npc__DOT__is_srai = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16084157117712975700ull);
    vlSelf->npc__DOT__is_xori = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17859615923300220298ull);
    vlSelf->npc__DOT__is_andi = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15447534817475441426ull);
    vlSelf->npc__DOT__is_slli = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15071584917759939222ull);
    vlSelf->npc__DOT__is_lh = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2073067310019782717ull);
    vlSelf->npc__DOT__is_lhu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7259090803116761004ull);
    vlSelf->npc__DOT__is_ori = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4354861069334576842ull);
    vlSelf->npc__DOT__is_csrrw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3750296343148065ull);
    vlSelf->npc__DOT__is_csrrs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3294389692030688566ull);
    vlSelf->npc__DOT__is_sh = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15395300221938876305ull);
    vlSelf->npc__DOT__is_sb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17239515840305236195ull);
    vlSelf->npc__DOT__is_bge = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7048329365100282259ull);
    vlSelf->npc__DOT__is_bgeu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2557408463039664384ull);
    vlSelf->npc__DOT__is_bltu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7086124738964239788ull);
    vlSelf->npc__DOT__is_blt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10031783266708861801ull);
    vlSelf->npc__DOT__csr_raddr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 10006122730569512850ull);
    vlSelf->npc__DOT__csr_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14994035147346098257ull);
    vlSelf->npc__DOT__raddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7662766534979410799ull);
    vlSelf->npc__DOT__pmem_read_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8288190997008375572ull);
    vlSelf->npc__DOT____VdfgRegularize_h06e98be2_0_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12676411809740312087ull);
    vlSelf->npc__DOT____VdfgRegularize_h06e98be2_0_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8878517751737777806ull);
    vlSelf->npc__DOT____VdfgRegularize_h06e98be2_0_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6728852299948576182ull);
    vlSelf->npc__DOT____VdfgRegularize_h06e98be2_0_5 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4470772341146574310ull);
    vlSelf->npc__DOT____VdfgRegularize_h06e98be2_0_6 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2476848395785516800ull);
    vlSelf->npc__DOT____VdfgRegularize_h06e98be2_0_7 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16525420930378171286ull);
    vlSelf->npc__DOT____VdfgRegularize_h06e98be2_0_8 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16379471940712112542ull);
    vlSelf->npc__DOT__u_regfile2__DOT__rdata1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1068761792014490981ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->npc__DOT__u_regfile2__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7067308385293642866ull);
    }
    vlSelf->npc__DOT__u_csr__DOT__crdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13918436264047761575ull);
    vlSelf->npc__DOT__u_csr__DOT__mepc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7882385580502595921ull);
    vlSelf->npc__DOT__u_csr__DOT__mcause = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16519444616851685064ull);
    vlSelf->npc__DOT__u_csr__DOT__mstatus = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14862025864194665906ull);
    vlSelf->npc__DOT__u_csr__DOT__mtvec = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11905907722351256196ull);
    vlSelf->npc__DOT__u_alu__DOT__src1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3194526296874634780ull);
    vlSelf->npc__DOT__u_alu__DOT__src2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13721060631079494823ull);
    vlSelf->npc__DOT__u_alu__DOT__sltu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17939194887316438677ull);
    vlSelf->npc__DOT__u_alu__DOT__bne = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6195531813428464050ull);
    vlSelf->npc__DOT__u_alu__DOT__sub = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12512278017900902968ull);
    vlSelf->npc__DOT__u_alu__DOT__slt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15681093017981471643ull);
    vlSelf->npc__DOT__u_alu__DOT__beq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7992696781295302392ull);
    vlSelf->npc__DOT__u_alu__DOT__adder_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6063479746036311668ull);
    vlSelf->npc__DOT__u_alu__DOT__adder_cin = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13922209588567249933ull);
    vlSelf->npc__DOT__u_alu__DOT__adder_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17099401982693055052ull);
    vlSelf->__Vfunc_v_pmem_read__0__Vfuncout = 0;
    vlSelf->__Vfunc_v_pmem_read__1__Vfuncout = 0;
    vlSelf->__Vfunc_v_pmem_read__2__Vfuncout = 0;
    vlSelf->__Vfunc_v_pmem_read__3__Vfuncout = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
