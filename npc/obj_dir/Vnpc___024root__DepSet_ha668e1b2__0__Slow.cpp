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
    vlSelfRef.__VstlTriggered.setBit(1U, ((IData)(vlSelfRef.npc__DOT__mem_en) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__npc__DOT__mem_en__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__npc__DOT__mem_en__0 
        = vlSelfRef.npc__DOT__mem_en;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VstlDidInit)))))) {
        vlSelfRef.__VstlDidInit = 1U;
        vlSelfRef.__VstlTriggered.setBit(1U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vnpc___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
