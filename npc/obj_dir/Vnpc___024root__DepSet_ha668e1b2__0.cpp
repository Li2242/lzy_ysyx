// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnpc.h for the primary calling header

#include "Vnpc__pch.h"
#include "Vnpc__Syms.h"
#include "Vnpc___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnpc___024root___dump_triggers__ico(Vnpc___024root* vlSelf);
#endif  // VL_DEBUG

void Vnpc___024root___eval_triggers__ico(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_triggers__ico\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vnpc___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

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

void Vnpc___024unit____Vdpiimwrap_info_reg__Vdpioc2_TOP____024unit(const VlUnpacked<IData/*31:0*/, 32> &rf_data);
void Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit(IData/*31:0*/ pc);

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
    if (vlSelfRef.info_r) {
        Vnpc___024unit____Vdpiimwrap_info_reg__Vdpioc2_TOP____024unit(vlSelfRef.npc__DOT__u_regfile2__DOT__rf);
    }
    __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 0U;
    if ((0x100073U == vlSelfRef.inst)) {
        Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit(
                                                           ((IData)(4U) 
                                                            + vlSelfRef.pc));
    }
    if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
        __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0 
            = vlSelfRef.alu_result;
        __VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0 
            = (0x1fU & (vlSelfRef.inst >> 7U));
        __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 1U;
    }
    if (__VdlySet__npc__DOT__u_regfile2__DOT__rf__v0) {
        vlSelfRef.npc__DOT__u_regfile2__DOT__rf[__VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0] 
            = __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0;
    }
    vlSelfRef.pc = ((IData)(vlSelfRef.rst) ? 0x80000000U
                     : vlSelfRef.npc__DOT__next_pc);
    vlSelfRef.npc__DOT__u_alu__DOT__result_addi = (vlSelfRef.npc__DOT__imm 
                                                   + 
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelfRef.inst 
                                                         >> 0xfU)))
                                                     ? 0U
                                                     : 
                                                    vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                                    [
                                                    (0x1fU 
                                                     & (vlSelfRef.inst 
                                                        >> 0xfU))]));
    vlSelfRef.npc__DOT__u_alu__DOT__result_auipc = 
        (vlSelfRef.npc__DOT__imm + vlSelfRef.pc);
    vlSelfRef.npc__DOT__next_pc = ((0x6fU == (0x7fU 
                                              & vlSelfRef.inst))
                                    ? vlSelfRef.npc__DOT__u_alu__DOT__result_auipc
                                    : ((IData)(vlSelfRef.npc__DOT__is_jalr)
                                        ? (0xfffffffeU 
                                           & vlSelfRef.npc__DOT__u_alu__DOT__result_addi)
                                        : ((IData)(4U) 
                                           + vlSelfRef.pc)));
    vlSelfRef.alu_result = (((- (IData)(((IData)(vlSelfRef.npc__DOT__is_U) 
                                         & (0x17U == 
                                            (0x7fU 
                                             & vlSelfRef.inst))))) 
                             & vlSelfRef.npc__DOT__u_alu__DOT__result_auipc) 
                            | (((- (IData)(((IData)(vlSelfRef.npc__DOT__is_U) 
                                            & (0x37U 
                                               == (0x7fU 
                                                   & vlSelfRef.inst))))) 
                                & vlSelfRef.npc__DOT__imm) 
                               | (((- (IData)((0x6fU 
                                               == (0x7fU 
                                                   & vlSelfRef.inst)))) 
                                   & ((IData)(4U) + vlSelfRef.pc)) 
                                  | (((- (IData)((IData)(vlSelfRef.npc__DOT__is_jalr))) 
                                      & ((IData)(4U) 
                                         + vlSelfRef.pc)) 
                                     | ((- (IData)(
                                                   ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_5) 
                                                    & (0x13U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelfRef.inst))))) 
                                        & vlSelfRef.npc__DOT__u_alu__DOT__result_addi)))));
}
