// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnpc.h for the primary calling header

#include "Vnpc__pch.h"
#include "Vnpc___024root.h"

void Vnpc___024root___eval_act(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_act\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vnpc___024root___nba_sequent__TOP__0(Vnpc___024root* vlSelf);
void Vnpc___024root___nba_sequent__TOP__1(Vnpc___024root* vlSelf);
void Vnpc___024root___nba_comb__TOP__0(Vnpc___024root* vlSelf);

void Vnpc___024root___eval_nba(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_nba\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vnpc___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vnpc___024root___nba_sequent__TOP__1(vlSelf);
        Vnpc___024root___nba_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vnpc___024root___nba_sequent__TOP__1(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___nba_sequent__TOP__1\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.npc__DOT__ifu_state = ((IData)(vlSelfRef.reset) 
                                     && (IData)(vlSelfRef.npc__DOT__ifu_next_state));
    vlSelfRef.pc = ((IData)(vlSelfRef.reset) ? vlSelfRef.npc__DOT__nextpc
                     : 0x80000000U);
    vlSelfRef.npc__DOT__ifu_next_state = (1U & (~ (IData)(vlSelfRef.npc__DOT__ifu_state)));
}

VL_INLINE_OPT void Vnpc___024root___nba_comb__TOP__0(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___nba_comb__TOP__0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.inst_valid) {
        VL_WRITEF_NX("EXEC PC=0x%08x inst=0x%08x nextPC=0x%08x\n",0,
                     32,vlSelfRef.pc,32,vlSelfRef.npc__DOT__inst_reg,
                     32,((IData)(vlSelfRef.npc__DOT__is_jalr)
                          ? (0xfffffffeU & vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0)
                          : (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                             [0x6fU] ? (vlSelfRef.pc 
                                        + vlSelfRef.npc__DOT__imm)
                              : ((IData)(4U) + vlSelfRef.pc))));
    } else {
        VL_WRITEF_NX("WAIT PC=0x%08x inst=0x%08x\n",0,
                     32,vlSelfRef.pc,32,vlSelfRef.npc__DOT__inst_reg);
    }
    vlSelfRef.npc__DOT__nextpc = ((IData)(vlSelfRef.npc__DOT__is_jalr)
                                   ? (0xfffffffeU & vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0)
                                   : (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                      [0x6fU] ? (vlSelfRef.pc 
                                                 + vlSelfRef.npc__DOT__imm)
                                       : ((IData)(4U) 
                                          + vlSelfRef.pc)));
    vlSelfRef.alu_result = ((- (IData)(((IData)(vlSelfRef.npc__DOT__is_add) 
                                        | (IData)(vlSelfRef.npc__DOT__src2_is_imm)))) 
                            & ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                [0x17U] ? vlSelfRef.pc
                                 : vlSelfRef.npc__DOT__src1) 
                               + ((IData)(vlSelfRef.npc__DOT__src2_is_imm)
                                   ? vlSelfRef.npc__DOT__imm
                                   : ((0U == (0x1fU 
                                              & (vlSelfRef.npc__DOT__inst_reg 
                                                 >> 0x14U)))
                                       ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                      [(0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                                 >> 0x14U))]))));
}

void Vnpc___024root___eval_triggers__act(Vnpc___024root* vlSelf);

bool Vnpc___024root___eval_phase__act(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_phase__act\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
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
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vnpc___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("vsrc/npc.v", 5, "", "NBA region did not converge.");
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
                VL_FATAL_MT("vsrc/npc.v", 5, "", "Active region did not converge.");
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
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
