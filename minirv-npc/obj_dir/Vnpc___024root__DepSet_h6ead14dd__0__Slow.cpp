// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnpc.h for the primary calling header

#include "Vnpc__pch.h"
#include "Vnpc___024root.h"

VL_ATTR_COLD void Vnpc___024root___eval_static__TOP(Vnpc___024root* vlSelf);

VL_ATTR_COLD void Vnpc___024root___eval_static(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_static\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vnpc___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
}

VL_ATTR_COLD void Vnpc___024root___eval_static__TOP(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_static__TOP\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0 = 0U;
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0.fill(0U);
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
            VL_FATAL_MT("vsrc/npc.v", 5, "", "Settle region did not converge.");
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
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge reset)\n");
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
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge reset)\n");
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
    vlSelf->inst_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2881661861247159430ull);
    vlSelf->npc__DOT__nextpc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13448463068007023365ull);
    vlSelf->npc__DOT__ifu_state = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11982977368688405936ull);
    vlSelf->npc__DOT__ifu_next_state = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2364858635368160771ull);
    vlSelf->npc__DOT__ifu_raddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10384814231718738920ull);
    vlSelf->npc__DOT__inst_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 559965870459530219ull);
    vlSelf->npc__DOT__reg_cwen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7642231643570232800ull);
    vlSelf->npc__DOT__mem_ren = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15006860431274983569ull);
    vlSelf->npc__DOT__imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3403450650843488731ull);
    vlSelf->npc__DOT__is_add = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7113134690467923886ull);
    vlSelf->npc__DOT__is_jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16619542919619024910ull);
    vlSelf->npc__DOT__is_addi = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18095654288942725152ull);
    vlSelf->npc__DOT__is_lw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10815129200715278395ull);
    vlSelf->npc__DOT__is_lbu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3669384594204784412ull);
    vlSelf->npc__DOT__src2_is_imm = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6504361381926984660ull);
    vlSelf->npc__DOT__src1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9000192369759755854ull);
    vlSelf->npc__DOT__raddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7662766534979410799ull);
    vlSelf->npc__DOT____VdfgExtracted_hd008e9d4__0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16752461302980099478ull);
    vlSelf->npc__DOT____VdfgRegularize_h467b3cb3_0_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8604789670429405903ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->npc__DOT__u_regfile2__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7067308385293642866ull);
    }
    vlSelf->npc__DOT__u_csr__DOT__mcycle = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17786633203603633416ull);
    vlSelf->npc__DOT__u_csr__DOT__mcycleh = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16674371368503694857ull);
    vlSelf->__Vfunc_v_pmem_read__3__Vfuncout = 0;
    vlSelf->__Vfunc_v_pmem_read__4__Vfuncout = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1487628987237401141ull);
}
