// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnpc.h for the primary calling header

#include "Vnpc__pch.h"
#include "Vnpc___024root.h"

void Vnpc___024root___ico_sequent__TOP__0(Vnpc___024root* vlSelf);

void Vnpc___024root___eval_ico(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_ico\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vnpc___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vnpc___024root____Vdpiimwrap_npc__DOT__ebreak_TOP(IData/*31:0*/ addr);

VL_INLINE_OPT void Vnpc___024root___ico_sequent__TOP__0(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___ico_sequent__TOP__0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x100073U == vlSelfRef.inst)) {
        Vnpc___024root____Vdpiimwrap_npc__DOT__ebreak_TOP(vlSelfRef.pc);
    }
    vlSelfRef.alu_result = ((((- (IData)((vlSelfRef.inst 
                                          >> 0x1fU))) 
                              << 0xcU) | (vlSelfRef.inst 
                                          >> 0x14U)) 
                            + ((0U == (0x1fU & (vlSelfRef.inst 
                                                >> 0xfU)))
                                ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                               [(0x1fU & (vlSelfRef.inst 
                                          >> 0xfU))]));
}

void Vnpc___024root___eval_triggers__ico(Vnpc___024root* vlSelf);

bool Vnpc___024root___eval_phase__ico(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_phase__ico\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vnpc___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vnpc___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vnpc___024root___eval_act(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_act\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vnpc___024root___nba_sequent__TOP__0(Vnpc___024root* vlSelf);

void Vnpc___024root___eval_nba(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_nba\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vnpc___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

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
    __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 0U;
    if (((IData)((0x13U == (0x707fU & vlSelfRef.inst))) 
         & (0U != (0x1fU & (vlSelfRef.inst >> 7U))))) {
        __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0 
            = vlSelfRef.alu_result;
        __VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0 
            = (0x1fU & (vlSelfRef.inst >> 7U));
        __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 1U;
    }
    vlSelfRef.pc = ((IData)(vlSelfRef.rst) ? 0x80000000U
                     : vlSelfRef.npc__DOT____Vcellinp__pc_4__din);
    if (__VdlySet__npc__DOT__u_regfile2__DOT__rf__v0) {
        vlSelfRef.npc__DOT__u_regfile2__DOT__rf[__VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0] 
            = __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0;
    }
    vlSelfRef.alu_result = ((((- (IData)((vlSelfRef.inst 
                                          >> 0x1fU))) 
                              << 0xcU) | (vlSelfRef.inst 
                                          >> 0x14U)) 
                            + ((0U == (0x1fU & (vlSelfRef.inst 
                                                >> 0xfU)))
                                ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                               [(0x1fU & (vlSelfRef.inst 
                                          >> 0xfU))]));
    if ((0x100073U == vlSelfRef.inst)) {
        Vnpc___024root____Vdpiimwrap_npc__DOT__ebreak_TOP(vlSelfRef.pc);
    }
    vlSelfRef.npc__DOT____Vcellinp__pc_4__din = ((IData)(4U) 
                                                 + vlSelfRef.pc);
}

void Vnpc___024root___eval_triggers__act(Vnpc___024root* vlSelf);

bool Vnpc___024root___eval_phase__act(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_phase__act\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vnpc___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vnpc___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vnpc___024root___eval_phase__nba(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_phase__nba\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vnpc___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnpc___024root___dump_triggers__ico(Vnpc___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vnpc___024root___dump_triggers__nba(Vnpc___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vnpc___024root___dump_triggers__act(Vnpc___024root* vlSelf);
#endif  // VL_DEBUG

void Vnpc___024root___eval(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vnpc___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("vsrc/npc.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vnpc___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vnpc___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("vsrc/npc.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vnpc___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("vsrc/npc.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vnpc___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vnpc___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vnpc___024root___eval_debug_assertions(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_debug_assertions\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
