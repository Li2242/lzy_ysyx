// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnpc.h for the primary calling header

#include "Vnpc__pch.h"
#include "Vnpc__Syms.h"
#include "Vnpc___024root.h"

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
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.reset)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__reset__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
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
    IData/*31:0*/ __Vdly__npc__DOT__u_csr__DOT__mcycleh;
    __Vdly__npc__DOT__u_csr__DOT__mcycleh = 0;
    IData/*31:0*/ __Vdly__npc__DOT__u_csr__DOT__mcycle;
    __Vdly__npc__DOT__u_csr__DOT__mcycle = 0;
    IData/*31:0*/ __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0;
    __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0 = 0;
    CData/*4:0*/ __VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0;
    __VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0 = 0;
    CData/*0:0*/ __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0;
    __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 0;
    // Body
    __Vdly__npc__DOT__u_csr__DOT__mcycleh = vlSelfRef.npc__DOT__u_csr__DOT__mcycleh;
    __Vdly__npc__DOT__u_csr__DOT__mcycle = vlSelfRef.npc__DOT__u_csr__DOT__mcycle;
    if (vlSelfRef.npc__DOT__mem_wen) {
        Vnpc___024unit____Vdpiimwrap_v_pmem_write_TOP____024unit(
                                                                 ((IData)(vlSelfRef.npc__DOT__mem_wen)
                                                                   ? vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0
                                                                   : 0x80000000U), 
                                                                 ((0U 
                                                                   == 
                                                                   (0x1fU 
                                                                    & (vlSelfRef.npc__DOT__inst_reg 
                                                                       >> 0x14U)))
                                                                   ? 0U
                                                                   : 
                                                                  vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                                                  [
                                                                  (0x1fU 
                                                                   & (vlSelfRef.npc__DOT__inst_reg 
                                                                      >> 0x14U))]), 
                                                                 ((IData)(
                                                                          ((0U 
                                                                            == 
                                                                            (0x7000U 
                                                                             & vlSelfRef.npc__DOT__inst_reg)) 
                                                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                                           [0x23U]))
                                                                   ? 1U
                                                                   : 0xfU));
    }
    if (((0x100073U == vlSelfRef.npc__DOT__inst_reg) 
         & (IData)(vlSelfRef.inst_valid))) {
        Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit(vlSelfRef.pc);
    }
    __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 0U;
    if (vlSelfRef.npc__DOT__reg_cwen) {
        if ((0xb00U != (0xfffU & vlSelfRef.npc__DOT__imm))) {
            if ((0xb02U == (0xfffU & vlSelfRef.npc__DOT__imm))) {
                __Vdly__npc__DOT__u_csr__DOT__mcycleh 
                    = vlSelfRef.npc__DOT__src1;
            }
        }
    }
    __Vdly__npc__DOT__u_csr__DOT__mcycleh = (IData)(
                                                    ((1ULL 
                                                      + 
                                                      (((QData)((IData)(vlSelfRef.npc__DOT__u_csr__DOT__mcycleh)) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(vlSelfRef.npc__DOT__u_csr__DOT__mcycle)))) 
                                                     >> 0x20U));
    __Vdly__npc__DOT__u_csr__DOT__mcycle = ((IData)(1U) 
                                            + vlSelfRef.npc__DOT__u_csr__DOT__mcycle);
    if (vlSelfRef.npc__DOT__reg_cwen) {
        if ((0xb00U == (0xfffU & vlSelfRef.npc__DOT__imm))) {
            __Vdly__npc__DOT__u_csr__DOT__mcycle = vlSelfRef.npc__DOT__src1;
        }
    }
    if ((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
           [0x17U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                      [0x37U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                 [0x6fU] | ((IData)(vlSelfRef.npc__DOT__is_jalr) 
                                            | ((IData)(vlSelfRef.npc__DOT__is_addi) 
                                               | ((IData)(vlSelfRef.npc__DOT__is_add) 
                                                  | ((IData)(vlSelfRef.npc__DOT__is_lw) 
                                                     | ((IData)(vlSelfRef.npc__DOT__is_lbu) 
                                                        | (IData)(vlSelfRef.npc__DOT__reg_cwen))))))))) 
          & (IData)(vlSelfRef.inst_valid)) & (0U != 
                                              (0x1fU 
                                               & (vlSelfRef.npc__DOT__inst_reg 
                                                  >> 7U))))) {
        __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0 
            = ((IData)(vlSelfRef.npc__DOT__mem_ren)
                ? ((IData)(vlSelfRef.npc__DOT__mem_ren)
                    ? vlSelfRef.npc__DOT____VdfgExtracted_hd008e9d4__0
                    : 0U) : ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x6fU] | (IData)(vlSelfRef.npc__DOT__is_jalr))
                              ? ((IData)(4U) + vlSelfRef.pc)
                              : (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                 [0x37U] ? vlSelfRef.npc__DOT__imm
                                  : ((IData)(vlSelfRef.npc__DOT__reg_cwen)
                                      ? ((0xb00U == 
                                          (0xfffU & vlSelfRef.npc__DOT__imm))
                                          ? vlSelfRef.npc__DOT__u_csr__DOT__mcycle
                                          : ((0xb02U 
                                              == (0xfffU 
                                                  & vlSelfRef.npc__DOT__imm))
                                              ? vlSelfRef.npc__DOT__u_csr__DOT__mcycleh
                                              : ((0xf11U 
                                                  == 
                                                  (0xfffU 
                                                   & vlSelfRef.npc__DOT__imm))
                                                  ? 0x79737978U
                                                  : 
                                                 ((0xf12U 
                                                   == 
                                                   (0xfffU 
                                                    & vlSelfRef.npc__DOT__imm))
                                                   ? 0x17e634bU
                                                   : 0U))))
                                      : vlSelfRef.alu_result))));
        __VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0 
            = (0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                        >> 7U));
        __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 1U;
    }
    vlSelfRef.npc__DOT__u_csr__DOT__mcycle = __Vdly__npc__DOT__u_csr__DOT__mcycle;
    vlSelfRef.npc__DOT__u_csr__DOT__mcycleh = __Vdly__npc__DOT__u_csr__DOT__mcycleh;
    if (__VdlySet__npc__DOT__u_regfile2__DOT__rf__v0) {
        vlSelfRef.npc__DOT__u_regfile2__DOT__rf[__VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0] 
            = __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0;
    }
}

void Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(IData/*31:0*/ raddr, IData/*31:0*/ len, IData/*31:0*/ &v_pmem_read__Vfuncrtn);

VL_INLINE_OPT void Vnpc___024root___nba_sequent__TOP__1(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___nba_sequent__TOP__1\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vfunc_v_pmem_read__0__Vfuncout;
    __Vfunc_v_pmem_read__0__Vfuncout = 0;
    IData/*31:0*/ __Vdly__pc;
    __Vdly__pc = 0;
    CData/*0:0*/ __Vdly__npc__DOT__pc_valid;
    __Vdly__npc__DOT__pc_valid = 0;
    // Body
    __Vdly__npc__DOT__pc_valid = vlSelfRef.npc__DOT__pc_valid;
    __Vdly__pc = vlSelfRef.pc;
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        __Vdly__pc = 0x80000000U;
    }
    if (vlSelfRef.npc__DOT__ifu_state) {
        if (vlSelfRef.npc__DOT__ifu_state) {
            Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__ifu_raddr, 4U, __Vfunc_v_pmem_read__0__Vfuncout);
            vlSelfRef.inst_valid = 1U;
            vlSelfRef.npc__DOT__inst_reg = __Vfunc_v_pmem_read__0__Vfuncout;
            __Vdly__npc__DOT__pc_valid = 1U;
        }
    } else {
        vlSelfRef.npc__DOT__ifu_raddr = vlSelfRef.pc;
        vlSelfRef.inst_valid = 0U;
        if (vlSelfRef.npc__DOT__pc_valid) {
            __Vdly__pc = vlSelfRef.npc__DOT__nextpc;
            __Vdly__npc__DOT__pc_valid = 0U;
        }
    }
    vlSelfRef.npc__DOT__pc_valid = __Vdly__npc__DOT__pc_valid;
    vlSelfRef.pc = __Vdly__pc;
    vlSelfRef.npc__DOT__ifu_state = ((IData)(vlSelfRef.reset) 
                                     && (IData)(vlSelfRef.npc__DOT__ifu_next_state));
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0[vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0] = 0U;
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0[(0x7fU 
                                                                                & vlSelfRef.npc__DOT__inst_reg)] = 1U;
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0 
        = (0x7fU & vlSelfRef.npc__DOT__inst_reg);
    vlSelfRef.npc__DOT__opcode_d[0U] = ((((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                             [0x1fU] 
                                             << 0x1fU) 
                                            | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x1eU] 
                                               << 0x1eU)) 
                                           | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x1dU] 
                                               << 0x1dU) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x1cU] 
                                                 << 0x1cU))) 
                                          | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x1bU] 
                                               << 0x1bU) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x1aU] 
                                                 << 0x1aU)) 
                                             | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x19U] 
                                                 << 0x19U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x18U] 
                                                   << 0x18U)))) 
                                         | ((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x17U] 
                                               << 0x17U) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x16U] 
                                                 << 0x16U)) 
                                             | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x15U] 
                                                 << 0x15U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x14U] 
                                                   << 0x14U))) 
                                            | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x13U] 
                                                 << 0x13U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x12U] 
                                                   << 0x12U)) 
                                               | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x11U] 
                                                   << 0x11U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x10U] 
                                                     << 0x10U))))) 
                                        | (((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0xfU] 
                                               << 0xfU) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0xeU] 
                                                 << 0xeU)) 
                                             | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0xdU] 
                                                 << 0xdU) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0xcU] 
                                                   << 0xcU))) 
                                            | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0xbU] 
                                                 << 0xbU) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0xaU] 
                                                   << 0xaU)) 
                                               | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [9U] 
                                                   << 9U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [8U] 
                                                     << 8U)))) 
                                           | ((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [7U] 
                                                 << 7U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [6U] 
                                                   << 6U)) 
                                               | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [5U] 
                                                   << 5U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [4U] 
                                                     << 4U))) 
                                              | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [3U] 
                                                   << 3U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [2U] 
                                                     << 2U)) 
                                                 | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [1U] 
                                                     << 1U) 
                                                    | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                    [0U])))));
    vlSelfRef.npc__DOT__opcode_d[1U] = ((((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                             [0x3fU] 
                                             << 0x1fU) 
                                            | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x3eU] 
                                               << 0x1eU)) 
                                           | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x3dU] 
                                               << 0x1dU) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x3cU] 
                                                 << 0x1cU))) 
                                          | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x3bU] 
                                               << 0x1bU) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x3aU] 
                                                 << 0x1aU)) 
                                             | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x39U] 
                                                 << 0x19U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x38U] 
                                                   << 0x18U)))) 
                                         | ((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x37U] 
                                               << 0x17U) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x36U] 
                                                 << 0x16U)) 
                                             | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x35U] 
                                                 << 0x15U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x34U] 
                                                   << 0x14U))) 
                                            | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x33U] 
                                                 << 0x13U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x32U] 
                                                   << 0x12U)) 
                                               | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x31U] 
                                                   << 0x11U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x30U] 
                                                     << 0x10U))))) 
                                        | (((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x2fU] 
                                               << 0xfU) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x2eU] 
                                                 << 0xeU)) 
                                             | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x2dU] 
                                                 << 0xdU) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x2cU] 
                                                   << 0xcU))) 
                                            | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x2bU] 
                                                 << 0xbU) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x2aU] 
                                                   << 0xaU)) 
                                               | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x29U] 
                                                   << 9U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x28U] 
                                                     << 8U)))) 
                                           | ((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x27U] 
                                                 << 7U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x26U] 
                                                   << 6U)) 
                                               | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x25U] 
                                                   << 5U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x24U] 
                                                     << 4U))) 
                                              | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x23U] 
                                                   << 3U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x22U] 
                                                     << 2U)) 
                                                 | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x21U] 
                                                     << 1U) 
                                                    | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                    [0x20U])))));
    vlSelfRef.npc__DOT__opcode_d[2U] = ((((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                             [0x5fU] 
                                             << 0x1fU) 
                                            | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x5eU] 
                                               << 0x1eU)) 
                                           | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x5dU] 
                                               << 0x1dU) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x5cU] 
                                                 << 0x1cU))) 
                                          | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x5bU] 
                                               << 0x1bU) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x5aU] 
                                                 << 0x1aU)) 
                                             | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x59U] 
                                                 << 0x19U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x58U] 
                                                   << 0x18U)))) 
                                         | ((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x57U] 
                                               << 0x17U) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x56U] 
                                                 << 0x16U)) 
                                             | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x55U] 
                                                 << 0x15U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x54U] 
                                                   << 0x14U))) 
                                            | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x53U] 
                                                 << 0x13U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x52U] 
                                                   << 0x12U)) 
                                               | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x51U] 
                                                   << 0x11U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x50U] 
                                                     << 0x10U))))) 
                                        | (((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x4fU] 
                                               << 0xfU) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x4eU] 
                                                 << 0xeU)) 
                                             | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x4dU] 
                                                 << 0xdU) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x4cU] 
                                                   << 0xcU))) 
                                            | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x4bU] 
                                                 << 0xbU) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x4aU] 
                                                   << 0xaU)) 
                                               | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x49U] 
                                                   << 9U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x48U] 
                                                     << 8U)))) 
                                           | ((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x47U] 
                                                 << 7U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x46U] 
                                                   << 6U)) 
                                               | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x45U] 
                                                   << 5U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x44U] 
                                                     << 4U))) 
                                              | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x43U] 
                                                   << 3U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x42U] 
                                                     << 2U)) 
                                                 | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x41U] 
                                                     << 1U) 
                                                    | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                    [0x40U])))));
    vlSelfRef.npc__DOT__opcode_d[3U] = ((((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                             [0x7fU] 
                                             << 0x1fU) 
                                            | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x7eU] 
                                               << 0x1eU)) 
                                           | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x7dU] 
                                               << 0x1dU) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x7cU] 
                                                 << 0x1cU))) 
                                          | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x7bU] 
                                               << 0x1bU) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x7aU] 
                                                 << 0x1aU)) 
                                             | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x79U] 
                                                 << 0x19U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x78U] 
                                                   << 0x18U)))) 
                                         | ((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x77U] 
                                               << 0x17U) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x76U] 
                                                 << 0x16U)) 
                                             | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x75U] 
                                                 << 0x15U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x74U] 
                                                   << 0x14U))) 
                                            | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x73U] 
                                                 << 0x13U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x72U] 
                                                   << 0x12U)) 
                                               | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x71U] 
                                                   << 0x11U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x70U] 
                                                     << 0x10U))))) 
                                        | (((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x6fU] 
                                               << 0xfU) 
                                              | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x6eU] 
                                                 << 0xeU)) 
                                             | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x6dU] 
                                                 << 0xdU) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x6cU] 
                                                   << 0xcU))) 
                                            | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x6bU] 
                                                 << 0xbU) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x6aU] 
                                                   << 0xaU)) 
                                               | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x69U] 
                                                   << 9U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x68U] 
                                                     << 8U)))) 
                                           | ((((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x67U] 
                                                 << 7U) 
                                                | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x66U] 
                                                   << 6U)) 
                                               | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x65U] 
                                                   << 5U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x64U] 
                                                     << 4U))) 
                                              | (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x63U] 
                                                   << 3U) 
                                                  | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x62U] 
                                                     << 2U)) 
                                                 | ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0x61U] 
                                                     << 1U) 
                                                    | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                    [0x60U])))));
    vlSelfRef.npc__DOT__reg_cwen = (IData)(((0x1000U 
                                             == (0x7000U 
                                                 & vlSelfRef.npc__DOT__inst_reg)) 
                                            & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x73U]));
    vlSelfRef.npc__DOT__mem_wen = ((IData)(((0x2000U 
                                             == (0x7000U 
                                                 & vlSelfRef.npc__DOT__inst_reg)) 
                                            & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x23U])) 
                                   | (IData)(((0U == 
                                               (0x7000U 
                                                & vlSelfRef.npc__DOT__inst_reg)) 
                                              & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                              [0x23U])));
    vlSelfRef.npc__DOT__is_add = (IData)(((0U == (0x7000U 
                                                  & vlSelfRef.npc__DOT__inst_reg)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [0x33U]));
    vlSelfRef.npc__DOT__is_jalr = (IData)(((0U == (0x7000U 
                                                   & vlSelfRef.npc__DOT__inst_reg)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x67U]));
    vlSelfRef.npc__DOT__is_addi = (IData)(((0U == (0x7000U 
                                                   & vlSelfRef.npc__DOT__inst_reg)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x13U]));
    vlSelfRef.npc__DOT__is_lw = (IData)(((0x2000U == 
                                          (0x7000U 
                                           & vlSelfRef.npc__DOT__inst_reg)) 
                                         & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                         [3U]));
    vlSelfRef.npc__DOT__is_lbu = (IData)(((0x4000U 
                                           == (0x7000U 
                                               & vlSelfRef.npc__DOT__inst_reg)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [3U]));
    vlSelfRef.npc__DOT__imm = (((- (IData)((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x13U] 
                                            | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [3U] 
                                               | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                  [0x67U] 
                                                  | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                  [0x73U]))))) 
                                & (((- (IData)((vlSelfRef.npc__DOT__inst_reg 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSelfRef.npc__DOT__inst_reg 
                                                >> 0x14U))) 
                               | ((0xfffff000U & ((- (IData)(
                                                             (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                              [0x37U] 
                                                              | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                              [0x17U]))) 
                                                  & vlSelfRef.npc__DOT__inst_reg)) 
                                  | (((- (IData)(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x6fU])) 
                                      & ((((- (IData)(
                                                      (vlSelfRef.npc__DOT__inst_reg 
                                                       >> 0x1fU))) 
                                           << 0x15U) 
                                          | (0x100000U 
                                             & (vlSelfRef.npc__DOT__inst_reg 
                                                >> 0xbU))) 
                                         | (((0xff000U 
                                              & vlSelfRef.npc__DOT__inst_reg) 
                                             | (0x800U 
                                                & (vlSelfRef.npc__DOT__inst_reg 
                                                   >> 9U))) 
                                            | (0x7feU 
                                               & (vlSelfRef.npc__DOT__inst_reg 
                                                  >> 0x14U))))) 
                                     | ((- (IData)(
                                                   vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x23U])) 
                                        & (((- (IData)(
                                                       (vlSelfRef.npc__DOT__inst_reg 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0xfe0U 
                                               & (vlSelfRef.npc__DOT__inst_reg 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelfRef.npc__DOT__inst_reg 
                                                    >> 7U))))))));
    vlSelfRef.npc__DOT__ifu_next_state = (1U & (~ (IData)(vlSelfRef.npc__DOT__ifu_state)));
    vlSelfRef.npc__DOT__src2_is_imm = ((IData)(vlSelfRef.npc__DOT__is_addi) 
                                       | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                       [0x17U]);
    vlSelfRef.npc__DOT__mem_ren = ((IData)(vlSelfRef.npc__DOT__is_lw) 
                                   | (IData)(vlSelfRef.npc__DOT__is_lbu));
}

VL_INLINE_OPT void Vnpc___024root___nba_comb__TOP__0(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___nba_comb__TOP__0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.npc__DOT__src1 = ((0U == (0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                                 >> 0xfU)))
                                 ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                [(0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                           >> 0xfU))]);
    vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0 
        = (vlSelfRef.npc__DOT__src1 + vlSelfRef.npc__DOT__imm);
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
    vlSelfRef.npc__DOT__raddr = ((IData)(vlSelfRef.npc__DOT__mem_ren)
                                  ? vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0
                                  : 0x80000000U);
    vlSelfRef.npc__DOT____VdfgExtracted_hd008e9d4__0 
        = ((IData)(vlSelfRef.npc__DOT__is_lbu) ? (0xffU 
                                                  & ([&]() {
                    Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 1U, vlSelfRef.__Vfunc_v_pmem_read__3__Vfuncout);
                }(), vlSelfRef.__Vfunc_v_pmem_read__3__Vfuncout))
            : ([&]() {
                Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 4U, vlSelfRef.__Vfunc_v_pmem_read__4__Vfuncout);
            }(), vlSelfRef.__Vfunc_v_pmem_read__4__Vfuncout));
}
