// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnpc.h for the primary calling header

#include "Vnpc__pch.h"
#include "Vnpc___024root.h"

VL_ATTR_COLD void Vnpc___024root___eval_static(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_static\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vnpc___024root___eval_initial__TOP(Vnpc___024root* vlSelf);
VL_ATTR_COLD void Vnpc___024root____Vm_traceActivitySetAll(Vnpc___024root* vlSelf);

VL_ATTR_COLD void Vnpc___024root___eval_initial(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_initial\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vnpc___024root___eval_initial__TOP(vlSelf);
    Vnpc___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void Vnpc___024root___eval_initial__TOP(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_initial__TOP\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pc = 0x80000000U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[1U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[2U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[3U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[4U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[5U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[6U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[7U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[8U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[9U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0xaU] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0xbU] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0xcU] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0xdU] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0xeU] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0xfU] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x10U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x11U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x12U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x13U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x14U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x15U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x16U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x17U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x18U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x19U] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x1aU] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x1bU] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x1cU] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x1dU] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x1eU] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[0x1fU] = 0U;
    vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__unnamedblk1__DOT__i = 0x20U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[1U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[2U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[3U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[4U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[5U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[6U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[7U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[8U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[9U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0xaU] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0xbU] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0xcU] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0xdU] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0xeU] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0xfU] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x10U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x11U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x12U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x13U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x14U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x15U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x16U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x17U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x18U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x19U] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x1aU] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x1bU] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x1cU] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x1dU] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x1eU] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__rf[0x1fU] = 0U;
    vlSelfRef.npc__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x20U;
}

VL_ATTR_COLD void Vnpc___024root___eval_final(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_final\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnpc___024root___dump_triggers__stl(Vnpc___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vnpc___024root___eval_phase__stl(Vnpc___024root* vlSelf);

VL_ATTR_COLD void Vnpc___024root___eval_settle(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_settle\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vnpc___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("vsrc/npc.v", 2, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vnpc___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnpc___024root___dump_triggers__stl(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___dump_triggers__stl\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vnpc___024root___stl_sequent__TOP__0(Vnpc___024root* vlSelf);

VL_ATTR_COLD void Vnpc___024root___eval_stl(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_stl\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vnpc___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vnpc___024root___stl_sequent__TOP__0(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___stl_sequent__TOP__0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.npc__DOT____Vcellinp__pc_4__din = ((IData)(4U) 
                                                 + vlSelfRef.pc);
    vlSelfRef.alu_result = (((0U == (0x1fU & (vlSelfRef.inst 
                                              >> 0xfU)))
                              ? 0U : vlSelfRef.npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf
                             [(0x1fU & (vlSelfRef.inst 
                                        >> 0xfU))]) 
                            + (((- (IData)((vlSelfRef.inst 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelfRef.inst 
                                            >> 0x14U)));
}

VL_ATTR_COLD void Vnpc___024root___eval_triggers__stl(Vnpc___024root* vlSelf);

VL_ATTR_COLD bool Vnpc___024root___eval_phase__stl(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_phase__stl\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vnpc___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vnpc___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnpc___024root___dump_triggers__ico(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___dump_triggers__ico\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnpc___024root___dump_triggers__act(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___dump_triggers__act\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnpc___024root___dump_triggers__nba(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___dump_triggers__nba\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vnpc___024root____Vm_traceActivitySetAll(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root____Vm_traceActivitySetAll\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void Vnpc___024root___ctor_var_reset(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___ctor_var_reset\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->inst = VL_RAND_RESET_I(32);
    vlSelf->alu_result = VL_RAND_RESET_I(32);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->npc__DOT____Vcellinp__pc_4__din = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__unnamedblk1__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->npc__DOT__u_regfile__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->npc__DOT__u_regfile__DOT__unnamedblk1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
