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
    vlSelf->npc__DOT__nextpc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13448463068007023365ull);
    vlSelf->npc__DOT__inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13484185947400506850ull);
    vlSelf->npc__DOT__mem_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6977832723820035533ull);
    vlSelf->npc__DOT__imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3403450650843488731ull);
    vlSelf->npc__DOT__is_add = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7113134690467923886ull);
    vlSelf->npc__DOT__is_xor = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16497246662640902904ull);
    vlSelf->npc__DOT__is_or = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14470214166798668838ull);
    vlSelf->npc__DOT__is_sltu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7105619691891532568ull);
    vlSelf->npc__DOT__is_sll = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17740457191497796115ull);
    vlSelf->npc__DOT__is_and = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14564807147912235218ull);
    vlSelf->npc__DOT__is_srl = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8581991778191014944ull);
    vlSelf->npc__DOT__is_srli = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1557024625016929814ull);
    vlSelf->npc__DOT__is_slt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9371827908278391710ull);
    vlSelf->npc__DOT__is_sra = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6832702589684493582ull);
    vlSelf->npc__DOT__is_jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16619542919619024910ull);
    vlSelf->npc__DOT__is_addi = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18095654288942725152ull);
    vlSelf->npc__DOT__is_lw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10815129200715278395ull);
    vlSelf->npc__DOT__is_lbu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3669384594204784412ull);
    vlSelf->npc__DOT__is_sltiu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1594603236580943049ull);
    vlSelf->npc__DOT__is_srai = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16084157117712975700ull);
    vlSelf->npc__DOT__is_xori = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17859615923300220298ull);
    vlSelf->npc__DOT__is_andi = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15447534817475441426ull);
    vlSelf->npc__DOT__is_slli = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15071584917759939222ull);
    vlSelf->npc__DOT__is_lh = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2073067310019782717ull);
    vlSelf->npc__DOT__is_lhu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7259090803116761004ull);
    vlSelf->npc__DOT__is_sh = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15395300221938876305ull);
    vlSelf->npc__DOT__is_sb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17239515840305236195ull);
    vlSelf->npc__DOT__is_bge = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7048329365100282259ull);
    vlSelf->npc__DOT__is_bgeu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2557408463039664384ull);
    vlSelf->npc__DOT__is_bltu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7086124738964239788ull);
    vlSelf->npc__DOT__is_blt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10031783266708861801ull);
    vlSelf->npc__DOT__src1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9000192369759755854ull);
    vlSelf->npc__DOT__alu_src1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2344565004898394841ull);
    vlSelf->npc__DOT__alu_src2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18328337154122140231ull);
    vlSelf->npc__DOT__raddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7662766534979410799ull);
    vlSelf->npc__DOT__pmem_read_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8288190997008375572ull);
    vlSelf->npc__DOT____VdfgRegularize_h467b3cb3_0_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8604789670429405903ull);
    vlSelf->npc__DOT____VdfgRegularize_h467b3cb3_0_8 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3873977110225484504ull);
    vlSelf->npc__DOT____VdfgRegularize_h467b3cb3_0_17 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 252982543673154213ull);
    vlSelf->npc__DOT____VdfgRegularize_h467b3cb3_0_19 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11968170070374015517ull);
    vlSelf->npc__DOT____VdfgRegularize_h467b3cb3_0_20 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14201283190348851629ull);
    vlSelf->npc__DOT____VdfgRegularize_h467b3cb3_0_21 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6276050114838745970ull);
    vlSelf->npc__DOT____VdfgRegularize_h467b3cb3_0_22 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8922911174211889837ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->npc__DOT__u_regfile2__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7067308385293642866ull);
    }
    vlSelf->npc__DOT__u_alu__DOT__sltu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17939194887316438677ull);
    vlSelf->npc__DOT__u_alu__DOT__bne = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6195531813428464050ull);
    vlSelf->npc__DOT__u_alu__DOT__sub = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12512278017900902968ull);
    vlSelf->npc__DOT__u_alu__DOT__slt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15681093017981471643ull);
    vlSelf->npc__DOT__u_alu__DOT__beq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7992696781295302392ull);
    vlSelf->npc__DOT__u_alu__DOT__add_sub_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18308337887036356919ull);
    vlSelf->npc__DOT__u_alu__DOT__adder_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6063479746036311668ull);
    vlSelf->npc__DOT__u_alu__DOT__adder_cin = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13922209588567249933ull);
    vlSelf->__Vfunc_v_pmem_read__0__Vfuncout = 0;
    vlSelf->__Vfunc_v_pmem_read__1__Vfuncout = 0;
    vlSelf->__Vfunc_v_pmem_read__2__Vfuncout = 0;
    vlSelf->__Vfunc_v_pmem_read__3__Vfuncout = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
}
