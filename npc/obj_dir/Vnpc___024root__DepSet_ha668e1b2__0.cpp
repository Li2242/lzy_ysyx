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

void Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(IData/*31:0*/ raddr, IData/*31:0*/ len, IData/*31:0*/ &v_pmem_read__Vfuncrtn);

VL_INLINE_OPT void Vnpc___024root___ico_sequent__TOP__0(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___ico_sequent__TOP__0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.reset) {
        Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(0x80000000U, 4U, vlSelfRef.__Vfunc_v_pmem_read__0__Vfuncout);
        vlSelfRef.npc__DOT__inst = vlSelfRef.__Vfunc_v_pmem_read__0__Vfuncout;
    } else {
        Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.pc, 4U, vlSelfRef.__Vfunc_v_pmem_read__1__Vfuncout);
        vlSelfRef.npc__DOT__inst = vlSelfRef.__Vfunc_v_pmem_read__1__Vfuncout;
    }
    vlSelfRef.npc__DOT__opcode_d[0U] = (((((((0x1fU 
                                              == (0x7fU 
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
    vlSelfRef.npc__DOT__opcode_d[1U] = (((((((0x3fU 
                                              == (0x7fU 
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
    vlSelfRef.npc__DOT__opcode_d[2U] = (((((((0x5fU 
                                              == (0x7fU 
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
    vlSelfRef.npc__DOT__opcode_d[3U] = (((((((0x7fU 
                                              == (0x7fU 
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
                    Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 1U, vlSelfRef.__Vfunc_v_pmem_read__4__Vfuncout);
                }(), vlSelfRef.__Vfunc_v_pmem_read__4__Vfuncout))
            : ([&]() {
                Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 4U, vlSelfRef.__Vfunc_v_pmem_read__5__Vfuncout);
            }(), vlSelfRef.__Vfunc_v_pmem_read__5__Vfuncout));
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

void Vnpc___024unit____Vdpiimwrap_v_pmem_write_TOP____024unit(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);
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
    if (VL_UNLIKELY((((IData)((0x2023U == (0x707fU 
                                           & vlSelfRef.npc__DOT__inst))) 
                      | (IData)((0x23U == (0x707fU 
                                           & vlSelfRef.npc__DOT__inst))))))) {
        VL_WRITEF_NX("MemWrite: waddr=0x%08x,  wdata=0x%08x, mem_wen=%b, wmask=0x%08x\n",0,
                     32,(((IData)((0x2023U == (0x707fU 
                                               & vlSelfRef.npc__DOT__inst))) 
                          | (IData)((0x23U == (0x707fU 
                                               & vlSelfRef.npc__DOT__inst))))
                          ? vlSelfRef.npc__DOT____VdfgRegularize_h9a2a8a06_0_0
                          : 0x80000000U),32,((0U == 
                                              (0x1fU 
                                               & (vlSelfRef.npc__DOT__inst 
                                                  >> 0x14U)))
                                              ? 0U : 
                                             vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                             [(0x1fU 
                                               & (vlSelfRef.npc__DOT__inst 
                                                  >> 0x14U))]),
                     1,((IData)((0x2023U == (0x707fU 
                                             & vlSelfRef.npc__DOT__inst))) 
                        | (IData)((0x23U == (0x707fU 
                                             & vlSelfRef.npc__DOT__inst)))),
                     8,((IData)((0x23U == (0x707fU 
                                           & vlSelfRef.npc__DOT__inst)))
                         ? 1U : 0xfU));
    }
    if ((0x100073U == vlSelfRef.npc__DOT__inst)) {
        Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit(vlSelfRef.pc);
    }
    if (VL_UNLIKELY((((0x17U == (0x7fU & vlSelfRef.npc__DOT__inst)) 
                      | ((0x37U == (0x7fU & vlSelfRef.npc__DOT__inst)) 
                         | ((IData)(vlSelfRef.npc__DOT__reg_from_pc_4) 
                            | ((IData)(vlSelfRef.npc__DOT__is_addi) 
                               | ((IData)(vlSelfRef.npc__DOT__is_add) 
                                  | (IData)(vlSelfRef.npc__DOT__mem_en))))))))) {
        VL_WRITEF_NX("RegWrite: rd=%2#,  final_result=0x%08x, mem_en=%b, rdata=0x%08x\n",0,
                     5,(0x1fU & (vlSelfRef.npc__DOT__inst 
                                 >> 7U)),32,((IData)(vlSelfRef.npc__DOT__mem_en)
                                              ? ((IData)(vlSelfRef.npc__DOT__mem_en)
                                                  ? vlSelfRef.npc__DOT____VdfgExtracted_hfee1d2e3__0
                                                  : 0U)
                                              : ((IData)(vlSelfRef.npc__DOT__reg_from_pc_4)
                                                  ? 
                                                 ((IData)(4U) 
                                                  + vlSelfRef.pc)
                                                  : 
                                                 ((0x37U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelfRef.npc__DOT__inst))
                                                   ? vlSelfRef.npc__DOT__imm
                                                   : vlSelfRef.alu_result))),
                     1,(IData)(vlSelfRef.npc__DOT__mem_en),
                     32,((IData)(vlSelfRef.npc__DOT__mem_en)
                          ? vlSelfRef.npc__DOT____VdfgExtracted_hfee1d2e3__0
                          : 0U));
    }
    __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 0U;
    if ((((0x17U == (0x7fU & vlSelfRef.npc__DOT__inst)) 
          | ((0x37U == (0x7fU & vlSelfRef.npc__DOT__inst)) 
             | ((IData)(vlSelfRef.npc__DOT__reg_from_pc_4) 
                | ((IData)(vlSelfRef.npc__DOT__is_addi) 
                   | ((IData)(vlSelfRef.npc__DOT__is_add) 
                      | (IData)(vlSelfRef.npc__DOT__mem_en)))))) 
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
    if (vlSelfRef.reset) {
        Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(0x80000000U, 4U, vlSelfRef.__Vfunc_v_pmem_read__0__Vfuncout);
        vlSelfRef.npc__DOT__inst = vlSelfRef.__Vfunc_v_pmem_read__0__Vfuncout;
    } else {
        Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.pc, 4U, vlSelfRef.__Vfunc_v_pmem_read__1__Vfuncout);
        vlSelfRef.npc__DOT__inst = vlSelfRef.__Vfunc_v_pmem_read__1__Vfuncout;
    }
    vlSelfRef.npc__DOT__opcode_d[0U] = (((((((0x1fU 
                                              == (0x7fU 
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
    vlSelfRef.npc__DOT__opcode_d[1U] = (((((((0x3fU 
                                              == (0x7fU 
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
    vlSelfRef.npc__DOT__opcode_d[2U] = (((((((0x5fU 
                                              == (0x7fU 
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
    vlSelfRef.npc__DOT__opcode_d[3U] = (((((((0x7fU 
                                              == (0x7fU 
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
                    Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 1U, vlSelfRef.__Vfunc_v_pmem_read__4__Vfuncout);
                }(), vlSelfRef.__Vfunc_v_pmem_read__4__Vfuncout))
            : ([&]() {
                Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 4U, vlSelfRef.__Vfunc_v_pmem_read__5__Vfuncout);
            }(), vlSelfRef.__Vfunc_v_pmem_read__5__Vfuncout));
}
