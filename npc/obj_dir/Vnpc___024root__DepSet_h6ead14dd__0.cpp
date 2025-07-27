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
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vnpc___024root___ico_sequent__TOP__0(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___ico_sequent__TOP__0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.npc__DOT__hot_opcode[0U] = (((((((0x1fU 
                                                == 
                                                (0x7fU 
                                                 & vlSelfRef.inst)) 
                                               << 0x1fU) 
                                              | ((0x1eU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x1eU)) 
                                             | (((0x1dU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x1dU) 
                                                | ((0x1cU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x1cU))) 
                                            | ((((0x1bU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x1bU) 
                                                | ((0x1aU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x1aU)) 
                                               | (((0x19U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x19U) 
                                                  | ((0x18U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x18U)))) 
                                           | (((((0x17U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x17U) 
                                                | ((0x16U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x16U)) 
                                               | (((0x15U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x15U) 
                                                  | ((0x14U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x14U))) 
                                              | ((((0x13U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x13U) 
                                                  | ((0x12U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x12U)) 
                                                 | (((0x11U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x11U) 
                                                    | ((0x10U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 0x10U))))) 
                                          | ((((((0xfU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0xfU) 
                                                | ((0xeU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0xeU)) 
                                               | (((0xdU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0xdU) 
                                                  | ((0xcU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0xcU))) 
                                              | ((((0xbU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0xbU) 
                                                  | ((0xaU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0xaU)) 
                                                 | (((9U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 9U) 
                                                    | ((8U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 8U)))) 
                                             | (((((7U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 7U) 
                                                  | ((6U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 6U)) 
                                                 | (((5U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 5U) 
                                                    | ((4U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 4U))) 
                                                | ((((3U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 3U) 
                                                    | ((2U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 2U)) 
                                                   | (((1U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 1U) 
                                                      | (0U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelfRef.inst)))))));
    vlSelfRef.npc__DOT__hot_opcode[1U] = (((((((0x3fU 
                                                == 
                                                (0x7fU 
                                                 & vlSelfRef.inst)) 
                                               << 0x1fU) 
                                              | ((0x3eU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x1eU)) 
                                             | (((0x3dU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x1dU) 
                                                | ((0x3cU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x1cU))) 
                                            | ((((0x3bU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x1bU) 
                                                | ((0x3aU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x1aU)) 
                                               | (((0x39U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x19U) 
                                                  | ((0x38U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x18U)))) 
                                           | (((((0x37U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x17U) 
                                                | ((0x36U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x16U)) 
                                               | (((0x35U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x15U) 
                                                  | ((0x34U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x14U))) 
                                              | ((((0x33U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x13U) 
                                                  | ((0x32U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x12U)) 
                                                 | (((0x31U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x11U) 
                                                    | ((0x30U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 0x10U))))) 
                                          | ((((((0x2fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0xfU) 
                                                | ((0x2eU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0xeU)) 
                                               | (((0x2dU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0xdU) 
                                                  | ((0x2cU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0xcU))) 
                                              | ((((0x2bU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0xbU) 
                                                  | ((0x2aU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0xaU)) 
                                                 | (((0x29U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 9U) 
                                                    | ((0x28U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 8U)))) 
                                             | (((((0x27U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 7U) 
                                                  | ((0x26U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 6U)) 
                                                 | (((0x25U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 5U) 
                                                    | ((0x24U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 4U))) 
                                                | ((((0x23U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 3U) 
                                                    | ((0x22U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 2U)) 
                                                   | (((0x21U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 1U) 
                                                      | (0x20U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelfRef.inst)))))));
    vlSelfRef.npc__DOT__hot_opcode[2U] = (((((((0x5fU 
                                                == 
                                                (0x7fU 
                                                 & vlSelfRef.inst)) 
                                               << 0x1fU) 
                                              | ((0x5eU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x1eU)) 
                                             | (((0x5dU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x1dU) 
                                                | ((0x5cU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x1cU))) 
                                            | ((((0x5bU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x1bU) 
                                                | ((0x5aU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x1aU)) 
                                               | (((0x59U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x19U) 
                                                  | ((0x58U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x18U)))) 
                                           | (((((0x57U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x17U) 
                                                | ((0x56U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x16U)) 
                                               | (((0x55U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x15U) 
                                                  | ((0x54U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x14U))) 
                                              | ((((0x53U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x13U) 
                                                  | ((0x52U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x12U)) 
                                                 | (((0x51U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x11U) 
                                                    | ((0x50U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 0x10U))))) 
                                          | ((((((0x4fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0xfU) 
                                                | ((0x4eU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0xeU)) 
                                               | (((0x4dU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0xdU) 
                                                  | ((0x4cU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0xcU))) 
                                              | ((((0x4bU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0xbU) 
                                                  | ((0x4aU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0xaU)) 
                                                 | (((0x49U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 9U) 
                                                    | ((0x48U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 8U)))) 
                                             | (((((0x47U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 7U) 
                                                  | ((0x46U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 6U)) 
                                                 | (((0x45U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 5U) 
                                                    | ((0x44U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 4U))) 
                                                | ((((0x43U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 3U) 
                                                    | ((0x42U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 2U)) 
                                                   | (((0x41U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 1U) 
                                                      | (0x40U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelfRef.inst)))))));
    vlSelfRef.npc__DOT__hot_opcode[3U] = (((((((0x7fU 
                                                == 
                                                (0x7fU 
                                                 & vlSelfRef.inst)) 
                                               << 0x1fU) 
                                              | ((0x7eU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x1eU)) 
                                             | (((0x7dU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x1dU) 
                                                | ((0x7cU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x1cU))) 
                                            | ((((0x7bU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x1bU) 
                                                | ((0x7aU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x1aU)) 
                                               | (((0x79U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x19U) 
                                                  | ((0x78U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x18U)))) 
                                           | (((((0x77U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0x17U) 
                                                | ((0x76U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x16U)) 
                                               | (((0x75U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x15U) 
                                                  | ((0x74U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x14U))) 
                                              | ((((0x73U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0x13U) 
                                                  | ((0x72U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x12U)) 
                                                 | (((0x71U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0x11U) 
                                                    | ((0x70U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 0x10U))))) 
                                          | ((((((0x6fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.inst)) 
                                                 << 0xfU) 
                                                | ((0x6eU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0xeU)) 
                                               | (((0x6dU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0xdU) 
                                                  | ((0x6cU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0xcU))) 
                                              | ((((0x6bU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 0xbU) 
                                                  | ((0x6aU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 0xaU)) 
                                                 | (((0x69U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 9U) 
                                                    | ((0x68U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 8U)))) 
                                             | (((((0x67U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   << 7U) 
                                                  | ((0x66U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 6U)) 
                                                 | (((0x65U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 5U) 
                                                    | ((0x64U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 4U))) 
                                                | ((((0x63U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.inst)) 
                                                     << 3U) 
                                                    | ((0x62U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 2U)) 
                                                   | (((0x61U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.inst)) 
                                                       << 1U) 
                                                      | (0x60U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelfRef.inst)))))));
    vlSelfRef.npc__DOT__src1 = ((0U == (0x1fU & (vlSelfRef.inst 
                                                 >> 0xfU)))
                                 ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                [(0x1fU & (vlSelfRef.inst 
                                           >> 0xfU))]);
    vlSelfRef.npc__DOT__is_U = ((0x37U == (0x7fU & vlSelfRef.inst)) 
                                | (0x17U == (0x7fU 
                                             & vlSelfRef.inst)));
    vlSelfRef.npc__DOT__is_I = ((0x13U == (0x7fU & vlSelfRef.inst)) 
                                | ((3U == (0x7fU & vlSelfRef.inst)) 
                                   | (0x67U == (0x7fU 
                                                & vlSelfRef.inst))));
    vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_5 
        = ((IData)(vlSelfRef.npc__DOT__is_I) & (0U 
                                                == 
                                                (0x7000U 
                                                 & vlSelfRef.inst)));
    vlSelfRef.npc__DOT__imm = (((- (IData)((IData)(vlSelfRef.npc__DOT__is_I))) 
                                & (((- (IData)((vlSelfRef.inst 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSelfRef.inst 
                                                >> 0x14U))) 
                               | ((0xfffff000U & ((- (IData)((IData)(vlSelfRef.npc__DOT__is_U))) 
                                                  & vlSelfRef.inst)) 
                                  | ((- (IData)((0x6fU 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelfRef.inst)))) 
                                     & ((((- (IData)(
                                                     (vlSelfRef.inst 
                                                      >> 0x1fU))) 
                                          << 0x15U) 
                                         | (0x100000U 
                                            & (vlSelfRef.inst 
                                               >> 0xbU))) 
                                        | (((0xff000U 
                                             & vlSelfRef.inst) 
                                            | (0x800U 
                                               & (vlSelfRef.inst 
                                                  >> 9U))) 
                                           | (0x7feU 
                                              & (vlSelfRef.inst 
                                                 >> 0x14U)))))));
    vlSelfRef.npc__DOT__is_jalr = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_5) 
                                   & (0x67U == (0x7fU 
                                                & vlSelfRef.inst)));
    vlSelfRef.npc__DOT__u_alu__DOT__result_auipc = 
        (vlSelfRef.npc__DOT__imm + vlSelfRef.pc);
    vlSelfRef.npc__DOT__next_pc = ((0x6fU == (0x7fU 
                                              & vlSelfRef.inst))
                                    ? vlSelfRef.npc__DOT__u_alu__DOT__result_auipc
                                    : ((IData)(vlSelfRef.npc__DOT__is_jalr)
                                        ? (0xfffffffeU 
                                           & (vlSelfRef.npc__DOT__imm 
                                              + vlSelfRef.npc__DOT__src1))
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
                                        & (vlSelfRef.npc__DOT__src1 
                                           - vlSelfRef.npc__DOT__imm))))));
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
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
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
            VL_FATAL_MT("vsrc/npc.v", 3, "", "Input combinational region did not converge.");
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
            VL_FATAL_MT("vsrc/npc.v", 3, "", "NBA region did not converge.");
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
                VL_FATAL_MT("vsrc/npc.v", 3, "", "Active region did not converge.");
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
