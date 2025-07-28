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
            VL_FATAL_MT("vsrc/npc.v", 4, "", "Settle region did not converge.");
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
VL_ATTR_COLD void Vnpc___024root____Vm_traceActivitySetAll(Vnpc___024root* vlSelf);

VL_ATTR_COLD void Vnpc___024root___eval_stl(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_stl\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vnpc___024root___stl_sequent__TOP__0(vlSelf);
        Vnpc___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vnpc___024root___stl_sequent__TOP__0(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___stl_sequent__TOP__0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.npc__DOT__hot_opcode[0U] = (((((((0x1fU 
                                                == 
                                                (0x7fU 
                                                 & vlSelfRef.npc__DOT__inst)) 
                                               << 0x1fU) 
                                              | ((0x1eU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x1eU)) 
                                             | (((0x1dU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x1dU) 
                                                | ((0x1cU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x1cU))) 
                                            | ((((0x1bU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x1bU) 
                                                | ((0x1aU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x1aU)) 
                                               | (((0x19U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x19U) 
                                                  | ((0x18U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x18U)))) 
                                           | (((((0x17U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x17U) 
                                                | ((0x16U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x16U)) 
                                               | (((0x15U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x15U) 
                                                  | ((0x14U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x14U))) 
                                              | ((((0x13U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x13U) 
                                                  | ((0x12U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x12U)) 
                                                 | (((0x11U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x11U) 
                                                    | ((0x10U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 0x10U))))) 
                                          | ((((((0xfU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0xfU) 
                                                | ((0xeU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0xeU)) 
                                               | (((0xdU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0xdU) 
                                                  | ((0xcU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0xcU))) 
                                              | ((((0xbU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0xbU) 
                                                  | ((0xaU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0xaU)) 
                                                 | (((9U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 9U) 
                                                    | ((8U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 8U)))) 
                                             | (((((7U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 7U) 
                                                  | ((6U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 6U)) 
                                                 | (((5U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 5U) 
                                                    | ((4U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 4U))) 
                                                | ((((3U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 3U) 
                                                    | ((2U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 2U)) 
                                                   | (((1U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 1U) 
                                                      | (0U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelfRef.npc__DOT__inst)))))));
    vlSelfRef.npc__DOT__hot_opcode[1U] = (((((((0x3fU 
                                                == 
                                                (0x7fU 
                                                 & vlSelfRef.npc__DOT__inst)) 
                                               << 0x1fU) 
                                              | ((0x3eU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x1eU)) 
                                             | (((0x3dU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x1dU) 
                                                | ((0x3cU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x1cU))) 
                                            | ((((0x3bU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x1bU) 
                                                | ((0x3aU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x1aU)) 
                                               | (((0x39U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x19U) 
                                                  | ((0x38U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x18U)))) 
                                           | (((((0x37U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x17U) 
                                                | ((0x36U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x16U)) 
                                               | (((0x35U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x15U) 
                                                  | ((0x34U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x14U))) 
                                              | ((((0x33U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x13U) 
                                                  | ((0x32U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x12U)) 
                                                 | (((0x31U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x11U) 
                                                    | ((0x30U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 0x10U))))) 
                                          | ((((((0x2fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0xfU) 
                                                | ((0x2eU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0xeU)) 
                                               | (((0x2dU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0xdU) 
                                                  | ((0x2cU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0xcU))) 
                                              | ((((0x2bU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0xbU) 
                                                  | ((0x2aU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0xaU)) 
                                                 | (((0x29U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 9U) 
                                                    | ((0x28U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 8U)))) 
                                             | (((((0x27U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 7U) 
                                                  | ((0x26U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 6U)) 
                                                 | (((0x25U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 5U) 
                                                    | ((0x24U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 4U))) 
                                                | ((((0x23U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 3U) 
                                                    | ((0x22U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 2U)) 
                                                   | (((0x21U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 1U) 
                                                      | (0x20U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelfRef.npc__DOT__inst)))))));
    vlSelfRef.npc__DOT__hot_opcode[2U] = (((((((0x5fU 
                                                == 
                                                (0x7fU 
                                                 & vlSelfRef.npc__DOT__inst)) 
                                               << 0x1fU) 
                                              | ((0x5eU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x1eU)) 
                                             | (((0x5dU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x1dU) 
                                                | ((0x5cU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x1cU))) 
                                            | ((((0x5bU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x1bU) 
                                                | ((0x5aU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x1aU)) 
                                               | (((0x59U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x19U) 
                                                  | ((0x58U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x18U)))) 
                                           | (((((0x57U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x17U) 
                                                | ((0x56U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x16U)) 
                                               | (((0x55U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x15U) 
                                                  | ((0x54U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x14U))) 
                                              | ((((0x53U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x13U) 
                                                  | ((0x52U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x12U)) 
                                                 | (((0x51U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x11U) 
                                                    | ((0x50U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 0x10U))))) 
                                          | ((((((0x4fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0xfU) 
                                                | ((0x4eU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0xeU)) 
                                               | (((0x4dU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0xdU) 
                                                  | ((0x4cU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0xcU))) 
                                              | ((((0x4bU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0xbU) 
                                                  | ((0x4aU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0xaU)) 
                                                 | (((0x49U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 9U) 
                                                    | ((0x48U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 8U)))) 
                                             | (((((0x47U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 7U) 
                                                  | ((0x46U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 6U)) 
                                                 | (((0x45U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 5U) 
                                                    | ((0x44U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 4U))) 
                                                | ((((0x43U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 3U) 
                                                    | ((0x42U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 2U)) 
                                                   | (((0x41U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 1U) 
                                                      | (0x40U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelfRef.npc__DOT__inst)))))));
    vlSelfRef.npc__DOT__hot_opcode[3U] = (((((((0x7fU 
                                                == 
                                                (0x7fU 
                                                 & vlSelfRef.npc__DOT__inst)) 
                                               << 0x1fU) 
                                              | ((0x7eU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x1eU)) 
                                             | (((0x7dU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x1dU) 
                                                | ((0x7cU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x1cU))) 
                                            | ((((0x7bU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x1bU) 
                                                | ((0x7aU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x1aU)) 
                                               | (((0x79U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x19U) 
                                                  | ((0x78U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x18U)))) 
                                           | (((((0x77U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0x17U) 
                                                | ((0x76U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x16U)) 
                                               | (((0x75U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x15U) 
                                                  | ((0x74U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x14U))) 
                                              | ((((0x73U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0x13U) 
                                                  | ((0x72U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x12U)) 
                                                 | (((0x71U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0x11U) 
                                                    | ((0x70U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 0x10U))))) 
                                          | ((((((0x6fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                                 << 0xfU) 
                                                | ((0x6eU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0xeU)) 
                                               | (((0x6dU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0xdU) 
                                                  | ((0x6cU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0xcU))) 
                                              | ((((0x6bU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 0xbU) 
                                                  | ((0x6aU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 0xaU)) 
                                                 | (((0x69U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 9U) 
                                                    | ((0x68U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 8U)))) 
                                             | (((((0x67U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   << 7U) 
                                                  | ((0x66U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 6U)) 
                                                 | (((0x65U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 5U) 
                                                    | ((0x64U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 4U))) 
                                                | ((((0x63U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     << 3U) 
                                                    | ((0x62U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 2U)) 
                                                   | (((0x61U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst)) 
                                                       << 1U) 
                                                      | (0x60U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelfRef.npc__DOT__inst)))))));
    vlSelfRef.npc__DOT__src1 = ((0U == (0x1fU & (vlSelfRef.npc__DOT__inst 
                                                 >> 0xfU)))
                                 ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                [(0x1fU & (vlSelfRef.npc__DOT__inst 
                                           >> 0xfU))]);
    vlSelfRef.npc__DOT__is_U = ((0x37U == (0x7fU & vlSelfRef.npc__DOT__inst)) 
                                | (0x17U == (0x7fU 
                                             & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__is_I = ((0x13U == (0x7fU & vlSelfRef.npc__DOT__inst)) 
                                | ((3U == (0x7fU & vlSelfRef.npc__DOT__inst)) 
                                   | (0x67U == (0x7fU 
                                                & vlSelfRef.npc__DOT__inst))));
    vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_5 
        = ((IData)(vlSelfRef.npc__DOT__is_I) & (0U 
                                                == 
                                                (0x7000U 
                                                 & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__imm = (((- (IData)((IData)(vlSelfRef.npc__DOT__is_I))) 
                                & (((- (IData)((vlSelfRef.npc__DOT__inst 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSelfRef.npc__DOT__inst 
                                                >> 0x14U))) 
                               | ((0xfffff000U & ((- (IData)((IData)(vlSelfRef.npc__DOT__is_U))) 
                                                  & vlSelfRef.npc__DOT__inst)) 
                                  | ((- (IData)((0x6fU 
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
                                                 >> 0x14U)))))));
    vlSelfRef.npc__DOT__is_jalr = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_5) 
                                   & (0x67U == (0x7fU 
                                                & vlSelfRef.npc__DOT__inst)));
    vlSelfRef.npc__DOT__u_alu__DOT__result_auipc = 
        (vlSelfRef.npc__DOT__imm + vlSelfRef.pc);
    vlSelfRef.npc__DOT__u_alu__DOT__result_addi = (vlSelfRef.npc__DOT__imm 
                                                   + vlSelfRef.npc__DOT__src1);
    vlSelfRef.npc__DOT__next_pc = ((0x6fU == (0x7fU 
                                              & vlSelfRef.npc__DOT__inst))
                                    ? vlSelfRef.npc__DOT__u_alu__DOT__result_auipc
                                    : ((IData)(vlSelfRef.npc__DOT__is_jalr)
                                        ? (0xfffffffeU 
                                           & vlSelfRef.npc__DOT__u_alu__DOT__result_addi)
                                        : ((IData)(4U) 
                                           + vlSelfRef.pc)));
    vlSelfRef.alu_result = (((- (IData)(((IData)(vlSelfRef.npc__DOT__is_U) 
                                         & (0x17U == 
                                            (0x7fU 
                                             & vlSelfRef.npc__DOT__inst))))) 
                             & vlSelfRef.npc__DOT__u_alu__DOT__result_auipc) 
                            | (((- (IData)(((IData)(vlSelfRef.npc__DOT__is_U) 
                                            & (0x37U 
                                               == (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst))))) 
                                & vlSelfRef.npc__DOT__imm) 
                               | (((- (IData)((0x6fU 
                                               == (0x7fU 
                                                   & vlSelfRef.npc__DOT__inst)))) 
                                   & ((IData)(4U) + vlSelfRef.pc)) 
                                  | (((- (IData)((IData)(vlSelfRef.npc__DOT__is_jalr))) 
                                      & ((IData)(4U) 
                                         + vlSelfRef.pc)) 
                                     | (((- (IData)(
                                                    ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_5) 
                                                     & (0x13U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.npc__DOT__inst))))) 
                                         & vlSelfRef.npc__DOT__u_alu__DOT__result_addi) 
                                        | ((- (IData)((IData)(vlSelfRef.npc__DOT__is_add))) 
                                           & (vlSelfRef.npc__DOT__src1 
                                              + ((0U 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelfRef.npc__DOT__inst 
                                                      >> 0x14U)))
                                                  ? 0U
                                                  : 
                                                 vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                                 [(0x1fU 
                                                   & (vlSelfRef.npc__DOT__inst 
                                                      >> 0x14U))]))))))));
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
VL_ATTR_COLD void Vnpc___024root___dump_triggers__act(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___dump_triggers__act\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @( clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
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
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @( clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
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
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
}

VL_ATTR_COLD void Vnpc___024root___ctor_var_reset(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___ctor_var_reset\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->alu_result = VL_RAND_RESET_I(32);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->npc__DOT__inst = VL_RAND_RESET_I(32);
    vlSelf->npc__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->npc__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->npc__DOT__src1 = VL_RAND_RESET_I(32);
    vlSelf->npc__DOT__is_I = VL_RAND_RESET_I(1);
    vlSelf->npc__DOT__is_U = VL_RAND_RESET_I(1);
    vlSelf->npc__DOT__imm_R = VL_RAND_RESET_I(32);
    vlSelf->npc__DOT__is_jalr = VL_RAND_RESET_I(1);
    vlSelf->npc__DOT__is_add = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->npc__DOT__hot_opcode);
    vlSelf->npc__DOT____VdfgRegularize_h9a2a8a06_0_5 = VL_RAND_RESET_I(1);
    vlSelf->npc__DOT__u_alu__DOT__result_auipc = VL_RAND_RESET_I(32);
    vlSelf->npc__DOT__u_alu__DOT__result_addi = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->npc__DOT__u_regfile2__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
