// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnpc.h for the primary calling header

#include "Vnpc__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnpc___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vnpc___024root___eval_triggers__act(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_triggers__act\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((IData)(vlSelfRef.clk) 
                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vnpc___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vnpc___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vnpc___024unit____Vdpiimwrap_v_pmem_write_TOP____024unit(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);
void Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit(IData/*31:0*/ pc);
void Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(IData/*31:0*/ raddr, IData/*31:0*/ len, IData/*31:0*/ &v_pmem_read__Vfuncrtn);

void Vnpc___024root___nba_sequent__TOP__0(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___nba_sequent__TOP__0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0;
    __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0 = 0;
    CData/*4:0*/ __VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0;
    __VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0 = 0;
    CData/*0:0*/ __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0;
    __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 0;
    // Body
    if (((IData)(((0x00002000U == (0x00007000U & vlSelfRef.npc__DOT__inst)) 
                  & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                  [0x23U])) | ((IData)(vlSelfRef.npc__DOT__is_sb) 
                               | (IData)(vlSelfRef.npc__DOT__is_sh)))) {
        Vnpc___024unit____Vdpiimwrap_v_pmem_write_TOP____024unit(
                                                                 (((IData)(
                                                                           ((0x00002000U 
                                                                             == 
                                                                             (0x00007000U 
                                                                              & vlSelfRef.npc__DOT__inst)) 
                                                                            & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                                            [0x23U])) 
                                                                   | ((IData)(vlSelfRef.npc__DOT__is_sb) 
                                                                      | (IData)(vlSelfRef.npc__DOT__is_sh)))
                                                                   ? vlSelfRef.addr
                                                                   : 0x80000000U), 
                                                                 ((0U 
                                                                   == 
                                                                   (0x0000001fU 
                                                                    & (vlSelfRef.npc__DOT__inst 
                                                                       >> 0x00000014U)))
                                                                   ? 0U
                                                                   : 
                                                                  vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                                                  [
                                                                  (0x0000001fU 
                                                                   & (vlSelfRef.npc__DOT__inst 
                                                                      >> 0x00000014U))]), 
                                                                 ((IData)(vlSelfRef.npc__DOT__is_sb)
                                                                   ? 1U
                                                                   : 
                                                                  ((IData)(vlSelfRef.npc__DOT__is_sh)
                                                                    ? 3U
                                                                    : 0x0fU)));
    }
    if ((0x00100073U == vlSelfRef.npc__DOT__inst)) {
        Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit(vlSelfRef.pc);
    }
    __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 0U;
    if (((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
          [0x17U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                     [0x37U] | ((IData)(vlSelfRef.npc__DOT__reg_from_pc_4) 
                                | ((IData)(vlSelfRef.npc__DOT__is_addi) 
                                   | ((IData)(vlSelfRef.npc__DOT__is_add) 
                                      | ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_5) 
                                         | ((IData)(vlSelfRef.npc__DOT__is_sltiu) 
                                            | ((IData)(vlSelfRef.npc__DOT__is_xor) 
                                               | ((IData)(vlSelfRef.npc__DOT__is_or) 
                                                  | ((IData)(vlSelfRef.npc__DOT__is_sltu) 
                                                     | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sub) 
                                                        | ((IData)(vlSelfRef.npc__DOT__is_srai) 
                                                           | ((IData)(vlSelfRef.npc__DOT__is_sll) 
                                                              | ((IData)(vlSelfRef.npc__DOT__is_and) 
                                                                 | ((IData)(vlSelfRef.npc__DOT__is_xori) 
                                                                    | ((IData)(vlSelfRef.npc__DOT__is_andi) 
                                                                       | ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_7) 
                                                                          | ((IData)(vlSelfRef.npc__DOT__is_slli) 
                                                                             | ((IData)(vlSelfRef.npc__DOT__is_slt) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_lh) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_lhu) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_sra) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_csrrw) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_csrrs) 
                                                                                | (IData)(vlSelfRef.npc__DOT__is_ori))))))))))))))))))))))))) 
         & (0U != (0x0000001fU & (vlSelfRef.npc__DOT__inst 
                                  >> 7U))))) {
        __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0 
            = ((IData)(vlSelfRef.npc__DOT__mem_en) ? 
               (((IData)(vlSelfRef.npc__DOT__is_lbu) 
                 | (IData)(vlSelfRef.npc__DOT__is_lhu))
                 ? vlSelfRef.npc__DOT__pmem_read_data
                 : ((IData)(vlSelfRef.npc__DOT__is_lh)
                     ? (((- (IData)((1U & (vlSelfRef.npc__DOT__pmem_read_data 
                                           >> 0x0000000fU)))) 
                         << 0x00000010U) | (0x0000ffffU 
                                            & vlSelfRef.npc__DOT__pmem_read_data))
                     : vlSelfRef.npc__DOT__pmem_read_data))
                : ((IData)(vlSelfRef.npc__DOT__reg_from_pc_4)
                    ? ((IData)(4U) + vlSelfRef.pc) : 
                   (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                    [0x37U] ? vlSelfRef.npc__DOT__imm
                     : ((IData)(vlSelfRef.npc__DOT__reg_cwen)
                         ? vlSelfRef.npc__DOT__u_csr__DOT__crdata
                         : vlSelfRef.alu_result))));
        __VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0 
            = (0x0000001fU & (vlSelfRef.npc__DOT__inst 
                              >> 7U));
        __VdlySet__npc__DOT__u_regfile2__DOT__rf__v0 = 1U;
    }
    if (vlSelfRef.npc__DOT__reg_cwen) {
        if ((0x0300U == (IData)(vlSelfRef.npc__DOT__csr_raddr))) {
            vlSelfRef.npc__DOT__u_csr__DOT__mstatus 
                = vlSelfRef.npc__DOT__csr_wdata;
        }
        if ((0x0300U != (IData)(vlSelfRef.npc__DOT__csr_raddr))) {
            if ((0x0305U == (IData)(vlSelfRef.npc__DOT__csr_raddr))) {
                vlSelfRef.npc__DOT__u_csr__DOT__mtvec 
                    = vlSelfRef.npc__DOT__csr_wdata;
            }
            if ((0x0305U != (IData)(vlSelfRef.npc__DOT__csr_raddr))) {
                if ((0x0341U != (IData)(vlSelfRef.npc__DOT__csr_raddr))) {
                    if ((0x0342U == (IData)(vlSelfRef.npc__DOT__csr_raddr))) {
                        vlSelfRef.npc__DOT__u_csr__DOT__mcause 
                            = vlSelfRef.npc__DOT__csr_wdata;
                    }
                }
                if ((0x0341U == (IData)(vlSelfRef.npc__DOT__csr_raddr))) {
                    vlSelfRef.npc__DOT__u_csr__DOT__mepc 
                        = vlSelfRef.npc__DOT__csr_wdata;
                }
            }
        }
    }
    if ((0x00000073U == vlSelfRef.npc__DOT__inst)) {
        vlSelfRef.npc__DOT__u_csr__DOT__mcause = 0x0000000bU;
        vlSelfRef.npc__DOT__u_csr__DOT__mepc = vlSelfRef.pc;
    }
    if (__VdlySet__npc__DOT__u_regfile2__DOT__rf__v0) {
        vlSelfRef.npc__DOT__u_regfile2__DOT__rf[__VdlyDim0__npc__DOT__u_regfile2__DOT__rf__v0] 
            = __VdlyVal__npc__DOT__u_regfile2__DOT__rf__v0;
    }
    vlSelfRef.pc = ((IData)(vlSelfRef.reset) ? 0x80000000U
                     : vlSelfRef.npc__DOT__nextpc);
    Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.pc, 4U, vlSelfRef.__Vfunc_v_pmem_read__0__Vfuncout);
    vlSelfRef.npc__DOT__inst = vlSelfRef.__Vfunc_v_pmem_read__0__Vfuncout;
    vlSelfRef.npc__DOT__csr_raddr = ((0x30200073U == vlSelfRef.npc__DOT__inst)
                                      ? 0x00000341U
                                      : ((0x00000073U 
                                          == vlSelfRef.npc__DOT__inst)
                                          ? 0x00000305U
                                          : (vlSelfRef.npc__DOT__inst 
                                             >> 0x00000014U)));
    vlSelfRef.npc__DOT__u_regfile2__DOT__rdata1 = (
                                                   (0U 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSelfRef.npc__DOT__inst 
                                                        >> 0x0000000fU)))
                                                    ? 0U
                                                    : 
                                                   vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                                   [
                                                   (0x0000001fU 
                                                    & (vlSelfRef.npc__DOT__inst 
                                                       >> 0x0000000fU))]);
    vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0[vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0] = 0U;
    vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0[(vlSelfRef.npc__DOT__inst 
                                                                                >> 0x00000019U)] = 1U;
    vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0 
        = (vlSelfRef.npc__DOT__inst >> 0x00000019U);
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0[vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0] = 0U;
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0[(0x0000007fU 
                                                                                & vlSelfRef.npc__DOT__inst)] = 1U;
    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0 
        = (0x0000007fU & vlSelfRef.npc__DOT__inst);
    vlSelfRef.npc__DOT__u_csr__DOT__crdata = ((0x0300U 
                                               == (IData)(vlSelfRef.npc__DOT__csr_raddr))
                                               ? vlSelfRef.npc__DOT__u_csr__DOT__mstatus
                                               : ((0x0305U 
                                                   == (IData)(vlSelfRef.npc__DOT__csr_raddr))
                                                   ? vlSelfRef.npc__DOT__u_csr__DOT__mtvec
                                                   : 
                                                  ((0x0341U 
                                                    == (IData)(vlSelfRef.npc__DOT__csr_raddr))
                                                    ? vlSelfRef.npc__DOT__u_csr__DOT__mepc
                                                    : 
                                                   ((0x0342U 
                                                     == (IData)(vlSelfRef.npc__DOT__csr_raddr))
                                                     ? vlSelfRef.npc__DOT__u_csr__DOT__mcause
                                                     : 0U))));
    vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_8 
        = (IData)(((0x00001000U == (0x00007000U & vlSelfRef.npc__DOT__inst)) 
                   & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                   [0U]));
    vlSelfRef.npc__DOT__is_sb = (IData)(((0U == (0x00007000U 
                                                 & vlSelfRef.npc__DOT__inst)) 
                                         & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                         [0x23U]));
    vlSelfRef.npc__DOT__is_sh = (IData)(((0x00001000U 
                                          == (0x00007000U 
                                              & vlSelfRef.npc__DOT__inst)) 
                                         & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                         [0x23U]));
    vlSelfRef.npc__DOT__is_csrrw = (IData)(((0x00001000U 
                                             == (0x00007000U 
                                                 & vlSelfRef.npc__DOT__inst)) 
                                            & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x73U]));
    vlSelfRef.npc__DOT__is_csrrs = (IData)(((0x00002000U 
                                             == (0x00007000U 
                                                 & vlSelfRef.npc__DOT__inst)) 
                                            & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x73U]));
    vlSelfRef.npc__DOT__is_jalr = (IData)(((0U == (0x00007000U 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x67U]));
    vlSelfRef.npc__DOT__is_lh = (IData)(((0x00001000U 
                                          == (0x00007000U 
                                              & vlSelfRef.npc__DOT__inst)) 
                                         & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                         [3U]));
    vlSelfRef.npc__DOT__is_lhu = (IData)(((0x00005000U 
                                           == (0x00007000U 
                                               & vlSelfRef.npc__DOT__inst)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [3U]));
    vlSelfRef.npc__DOT__is_lbu = (IData)(((0x00004000U 
                                           == (0x00007000U 
                                               & vlSelfRef.npc__DOT__inst)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [3U]));
    vlSelfRef.npc__DOT__is_xor = (IData)(((0x00004000U 
                                           == (0x00007000U 
                                               & vlSelfRef.npc__DOT__inst)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [0x33U]));
    vlSelfRef.npc__DOT__is_or = (IData)(((0x00006000U 
                                          == (0x00007000U 
                                              & vlSelfRef.npc__DOT__inst)) 
                                         & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                         [0x33U]));
    vlSelfRef.npc__DOT__is_and = (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                  [0x33U] & (IData)(
                                                    ((0x00007000U 
                                                      == 
                                                      (0x00007000U 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0U])));
    vlSelfRef.npc__DOT__u_alu__DOT__src1 = (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x17U]
                                             ? vlSelfRef.pc
                                             : vlSelfRef.npc__DOT__u_regfile2__DOT__rdata1);
    vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_3 
        = (IData)(((0x00005000U == (0x00007000U & vlSelfRef.npc__DOT__inst)) 
                   & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                   [0x33U]));
    vlSelfRef.npc__DOT__is_xori = (IData)(((0x00004000U 
                                            == (0x00007000U 
                                                & vlSelfRef.npc__DOT__inst)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x13U]));
    vlSelfRef.npc__DOT__is_andi = (IData)(((0x00007000U 
                                            == (0x00007000U 
                                                & vlSelfRef.npc__DOT__inst)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x13U]));
    vlSelfRef.npc__DOT__is_ori = (IData)(((0x00006000U 
                                           == (0x00007000U 
                                               & vlSelfRef.npc__DOT__inst)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [0x13U]));
    vlSelfRef.npc__DOT__is_addi = (IData)(((0U == (0x00007000U 
                                                   & vlSelfRef.npc__DOT__inst)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x13U]));
    vlSelfRef.npc__DOT__imm = (((- (IData)((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x13U] 
                                            | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [3U] 
                                               | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                  [0x67U] 
                                                  | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                  [0x73U]))))) 
                                & (((- (IData)((vlSelfRef.npc__DOT__inst 
                                                >> 0x0000001fU))) 
                                    << 0x0000000cU) 
                                   | (vlSelfRef.npc__DOT__inst 
                                      >> 0x00000014U))) 
                               | ((0xfffff000U & ((- (IData)(
                                                             (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                              [0x37U] 
                                                              | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                              [0x17U]))) 
                                                  & vlSelfRef.npc__DOT__inst)) 
                                  | (((- (IData)(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x6fU])) 
                                      & ((((0x00000ffeU 
                                            & ((- (IData)(
                                                          (vlSelfRef.npc__DOT__inst 
                                                           >> 0x0000001fU))) 
                                               << 1U)) 
                                           | (vlSelfRef.npc__DOT__inst 
                                              >> 0x0000001fU)) 
                                          << 0x00000014U) 
                                         | ((((0x000001feU 
                                               & (vlSelfRef.npc__DOT__inst 
                                                  >> 0x0000000bU)) 
                                              | (1U 
                                                 & (vlSelfRef.npc__DOT__inst 
                                                    >> 0x00000014U))) 
                                             << 0x0000000bU) 
                                            | (0x000007feU 
                                               & (vlSelfRef.npc__DOT__inst 
                                                  >> 0x00000014U))))) 
                                     | (((- (IData)(
                                                    vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                    [0x63U])) 
                                         & (((- (IData)(
                                                        (vlSelfRef.npc__DOT__inst 
                                                         >> 0x0000001fU))) 
                                             << 0x0000000dU) 
                                            | ((((2U 
                                                  & (vlSelfRef.npc__DOT__inst 
                                                     >> 0x0000001eU)) 
                                                 | (1U 
                                                    & (vlSelfRef.npc__DOT__inst 
                                                       >> 7U))) 
                                                << 0x0000000bU) 
                                               | ((0x000007e0U 
                                                   & (vlSelfRef.npc__DOT__inst 
                                                      >> 0x00000014U)) 
                                                  | (0x0000001eU 
                                                     & (vlSelfRef.npc__DOT__inst 
                                                        >> 7U)))))) 
                                        | ((- (IData)(
                                                      vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                      [0x23U])) 
                                           & (((- (IData)(
                                                          (vlSelfRef.npc__DOT__inst 
                                                           >> 0x0000001fU))) 
                                               << 0x0000000cU) 
                                              | ((0x00000fe0U 
                                                  & (vlSelfRef.npc__DOT__inst 
                                                     >> 0x00000014U)) 
                                                 | (0x0000001fU 
                                                    & (vlSelfRef.npc__DOT__inst 
                                                       >> 7U)))))))));
    vlSelfRef.npc__DOT__is_sltu = (IData)(((0x00003000U 
                                            == (0x00007000U 
                                                & vlSelfRef.npc__DOT__inst)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x33U]));
    vlSelfRef.npc__DOT__is_slt = (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                  [0x33U] & (IData)(
                                                    ((0x00002000U 
                                                      == 
                                                      (0x00007000U 
                                                       & vlSelfRef.npc__DOT__inst)) 
                                                     & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                     [0U])));
    vlSelfRef.npc__DOT__u_alu__DOT__bne = (IData)((
                                                   (0x00001000U 
                                                    == 
                                                    (0x00007000U 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x63U]));
    vlSelfRef.npc__DOT__u_alu__DOT__beq = (IData)((
                                                   (0U 
                                                    == 
                                                    (0x00007000U 
                                                     & vlSelfRef.npc__DOT__inst)) 
                                                   & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x63U]));
    vlSelfRef.npc__DOT__is_blt = (IData)(((0x00004000U 
                                           == (0x00007000U 
                                               & vlSelfRef.npc__DOT__inst)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [0x63U]));
    vlSelfRef.npc__DOT__is_bge = (IData)(((0x00005000U 
                                           == (0x00007000U 
                                               & vlSelfRef.npc__DOT__inst)) 
                                          & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                          [0x63U]));
    vlSelfRef.npc__DOT__is_bltu = (IData)(((0x00006000U 
                                            == (0x00007000U 
                                                & vlSelfRef.npc__DOT__inst)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x63U]));
    vlSelfRef.npc__DOT__is_bgeu = (IData)(((0x00007000U 
                                            == (0x00007000U 
                                                & vlSelfRef.npc__DOT__inst)) 
                                           & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x63U]));
    vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_2 
        = (IData)(((0U == (0x00007000U & vlSelfRef.npc__DOT__inst)) 
                   & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                   [0x33U]));
    vlSelfRef.npc__DOT__is_sltiu = (IData)(((0x00003000U 
                                             == (0x00007000U 
                                                 & vlSelfRef.npc__DOT__inst)) 
                                            & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                            [0x13U]));
    vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_4 
        = (IData)(((0x00005000U == (0x00007000U & vlSelfRef.npc__DOT__inst)) 
                   & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                   [0x13U]));
    vlSelfRef.npc__DOT__is_sll = (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                  [0x33U] & (IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_8));
    vlSelfRef.npc__DOT__is_slli = (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                   [0x13U] & (IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_8));
    vlSelfRef.npc__DOT__reg_cwen = ((IData)(vlSelfRef.npc__DOT__is_csrrw) 
                                    | (IData)(vlSelfRef.npc__DOT__is_csrrs));
    vlSelfRef.npc__DOT__csr_wdata = ((IData)(vlSelfRef.npc__DOT__is_csrrw)
                                      ? vlSelfRef.npc__DOT__u_regfile2__DOT__rdata1
                                      : ((IData)(vlSelfRef.npc__DOT__is_csrrs)
                                          ? (vlSelfRef.npc__DOT__u_csr__DOT__crdata 
                                             | vlSelfRef.npc__DOT__u_regfile2__DOT__rdata1)
                                          : 0U));
    vlSelfRef.npc__DOT__reg_from_pc_4 = (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                         [0x6fU] | (IData)(vlSelfRef.npc__DOT__is_jalr));
    vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_5 
        = ((IData)(((0x00002000U == (0x00007000U & vlSelfRef.npc__DOT__inst)) 
                    & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                    [3U])) | (IData)(vlSelfRef.npc__DOT__is_lbu));
    vlSelfRef.npc__DOT__is_sra = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_3) 
                                  & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                  [0x20U]);
    vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_6 
        = ((IData)(vlSelfRef.npc__DOT__is_addi) | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
           [0x17U]);
    vlSelfRef.addr = (vlSelfRef.npc__DOT__u_regfile2__DOT__rdata1 
                      + vlSelfRef.npc__DOT__imm);
    vlSelfRef.npc__DOT__u_alu__DOT__slt = ((IData)(vlSelfRef.npc__DOT__is_slt) 
                                           | ((IData)(vlSelfRef.npc__DOT__is_bge) 
                                              | (IData)(vlSelfRef.npc__DOT__is_blt)));
    vlSelfRef.npc__DOT__is_add = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_2) 
                                  & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                  [0U]);
    vlSelfRef.npc__DOT__u_alu__DOT__sub = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_2) 
                                           & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x20U]);
    vlSelfRef.npc__DOT__u_alu__DOT__sltu = ((IData)(vlSelfRef.npc__DOT__is_sltiu) 
                                            | ((IData)(vlSelfRef.npc__DOT__is_sltu) 
                                               | ((IData)(vlSelfRef.npc__DOT__is_bgeu) 
                                                  | (IData)(vlSelfRef.npc__DOT__is_bltu))));
    vlSelfRef.npc__DOT__is_srai = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_4) 
                                   & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                   [0x20U]);
    vlSelfRef.npc__DOT__is_srli = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_4) 
                                   & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                   [0U]);
    vlSelfRef.npc__DOT__mem_en = ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_5) 
                                  | ((IData)(vlSelfRef.npc__DOT__is_lh) 
                                     | (IData)(vlSelfRef.npc__DOT__is_lhu)));
    vlSelfRef.npc__DOT__u_alu__DOT__adder_cin = ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sltu) 
                                                 | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__bne) 
                                                    | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sub) 
                                                       | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__slt) 
                                                          | (IData)(vlSelfRef.npc__DOT__u_alu__DOT__beq)))));
    vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_7 
        = (((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_3) 
            & vlSelfRef.npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
            [0U]) | (IData)(vlSelfRef.npc__DOT__is_srli));
    vlSelfRef.npc__DOT__u_alu__DOT__src2 = (((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_6) 
                                             | ((IData)(vlSelfRef.npc__DOT__is_sltiu) 
                                                | ((IData)(vlSelfRef.npc__DOT__is_srai) 
                                                   | ((IData)(vlSelfRef.npc__DOT__is_xori) 
                                                      | ((IData)(vlSelfRef.npc__DOT__is_andi) 
                                                         | ((IData)(vlSelfRef.npc__DOT__is_srli) 
                                                            | ((IData)(vlSelfRef.npc__DOT__is_slli) 
                                                               | (IData)(vlSelfRef.npc__DOT__is_ori))))))))
                                             ? vlSelfRef.npc__DOT__imm
                                             : ((0U 
                                                 == 
                                                 (0x0000001fU 
                                                  & (vlSelfRef.npc__DOT__inst 
                                                     >> 0x00000014U)))
                                                 ? 0U
                                                 : 
                                                vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                                [(0x0000001fU 
                                                  & (vlSelfRef.npc__DOT__inst 
                                                     >> 0x00000014U))]));
    vlSelfRef.npc__DOT__raddr = ((IData)(vlSelfRef.npc__DOT__mem_en)
                                  ? vlSelfRef.addr : 0x80000000U);
    vlSelfRef.npc__DOT__u_alu__DOT__adder_b = ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_cin)
                                                ? (~ vlSelfRef.npc__DOT__u_alu__DOT__src2)
                                                : vlSelfRef.npc__DOT__u_alu__DOT__src2);
    vlSelfRef.npc__DOT__pmem_read_data = ((IData)(vlSelfRef.npc__DOT__is_lbu)
                                           ? ([&]() {
                Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 1U, vlSelfRef.__Vfunc_v_pmem_read__1__Vfuncout);
            }(), vlSelfRef.__Vfunc_v_pmem_read__1__Vfuncout)
                                           : (((IData)(vlSelfRef.npc__DOT__is_lh) 
                                               | (IData)(vlSelfRef.npc__DOT__is_lhu))
                                               ? ([&]() {
                    Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 2U, vlSelfRef.__Vfunc_v_pmem_read__2__Vfuncout);
                }(), vlSelfRef.__Vfunc_v_pmem_read__2__Vfuncout)
                                               : ([&]() {
                    Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(vlSelfRef.npc__DOT__raddr, 4U, vlSelfRef.__Vfunc_v_pmem_read__3__Vfuncout);
                }(), vlSelfRef.__Vfunc_v_pmem_read__3__Vfuncout)));
    vlSelfRef.npc__DOT__u_alu__DOT__adder_result = 
        (vlSelfRef.npc__DOT__u_alu__DOT__src1 + (vlSelfRef.npc__DOT__u_alu__DOT__adder_b 
                                                 + (IData)((QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_cin)))));
    vlSelfRef.alu_result = (((- (IData)((((IData)(vlSelfRef.npc__DOT__is_add) 
                                          | (IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_6)) 
                                         | (IData)(vlSelfRef.npc__DOT__u_alu__DOT__sub)))) 
                             & vlSelfRef.npc__DOT__u_alu__DOT__adder_result) 
                            | ((1U & ((- (IData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sltu))) 
                                      & (~ (IData)(
                                                   (1ULL 
                                                    & (((QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__src1)) 
                                                        + 
                                                        ((QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_b)) 
                                                         + (QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_cin)))) 
                                                       >> 0x00000020U)))))) 
                               | (((- (IData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__bne))) 
                                   & (0U != vlSelfRef.npc__DOT__u_alu__DOT__adder_result)) 
                                  | (((- (IData)(((IData)(vlSelfRef.npc__DOT__is_xor) 
                                                  | (IData)(vlSelfRef.npc__DOT__is_xori)))) 
                                      & (vlSelfRef.npc__DOT__u_alu__DOT__src1 
                                         ^ vlSelfRef.npc__DOT__u_alu__DOT__src2)) 
                                     | (((- (IData)(
                                                    ((IData)(vlSelfRef.npc__DOT__is_or) 
                                                     | (IData)(vlSelfRef.npc__DOT__is_ori)))) 
                                         & (vlSelfRef.npc__DOT__u_alu__DOT__src1 
                                            | vlSelfRef.npc__DOT__u_alu__DOT__src2)) 
                                        | (((- (IData)(
                                                       ((IData)(vlSelfRef.npc__DOT__is_srai) 
                                                        | (IData)(vlSelfRef.npc__DOT__is_sra)))) 
                                            & VL_SHIFTRS_III(32,32,5, vlSelfRef.npc__DOT__u_alu__DOT__src1, 
                                                             (0x0000001fU 
                                                              & vlSelfRef.npc__DOT__u_alu__DOT__src2))) 
                                           | (((- (IData)(
                                                          ((IData)(vlSelfRef.npc__DOT__is_sll) 
                                                           | (IData)(vlSelfRef.npc__DOT__is_slli)))) 
                                               & (vlSelfRef.npc__DOT__u_alu__DOT__src1 
                                                  << 
                                                  (0x0000001fU 
                                                   & vlSelfRef.npc__DOT__u_alu__DOT__src2))) 
                                              | (((- (IData)(
                                                             ((IData)(vlSelfRef.npc__DOT__is_and) 
                                                              | (IData)(vlSelfRef.npc__DOT__is_andi)))) 
                                                  & (vlSelfRef.npc__DOT__u_alu__DOT__src1 
                                                     & vlSelfRef.npc__DOT__u_alu__DOT__src2)) 
                                                 | ((1U 
                                                     & ((- (IData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__slt))) 
                                                        & (((vlSelfRef.npc__DOT__u_alu__DOT__src1 
                                                             >> 0x0000001fU) 
                                                            == 
                                                            (vlSelfRef.npc__DOT__u_alu__DOT__src2 
                                                             >> 0x0000001fU))
                                                            ? 
                                                           (vlSelfRef.npc__DOT__u_alu__DOT__adder_result 
                                                            >> 0x0000001fU)
                                                            : 
                                                           (vlSelfRef.npc__DOT__u_alu__DOT__src1 
                                                            >> 0x0000001fU)))) 
                                                    | ((1U 
                                                        & ((- (IData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__beq))) 
                                                           & (~ 
                                                              (0U 
                                                               != vlSelfRef.npc__DOT__u_alu__DOT__adder_result)))) 
                                                       | ((- (IData)((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h06e98be2_0_7))) 
                                                          & (vlSelfRef.npc__DOT__u_alu__DOT__src1 
                                                             >> 
                                                             (0x0000001fU 
                                                              & vlSelfRef.npc__DOT__u_alu__DOT__src2)))))))))))));
    vlSelfRef.npc__DOT__nextpc = ((IData)(vlSelfRef.npc__DOT__is_jalr)
                                   ? (0xfffffffeU & vlSelfRef.addr)
                                   : (((0x30200073U 
                                        == vlSelfRef.npc__DOT__inst) 
                                       | (0x00000073U 
                                          == vlSelfRef.npc__DOT__inst))
                                       ? vlSelfRef.npc__DOT__u_csr__DOT__crdata
                                       : ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                           [0x6fU] 
                                           | ((((IData)(vlSelfRef.npc__DOT__u_alu__DOT__bne) 
                                                | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__beq) 
                                                   | ((IData)(vlSelfRef.npc__DOT__is_bltu) 
                                                      | (IData)(vlSelfRef.npc__DOT__is_blt)))) 
                                               & (1U 
                                                  == vlSelfRef.alu_result)) 
                                              | (((IData)(vlSelfRef.npc__DOT__is_bgeu) 
                                                  | (IData)(vlSelfRef.npc__DOT__is_bge)) 
                                                 & (0U 
                                                    == vlSelfRef.alu_result))))
                                           ? (vlSelfRef.pc 
                                              + vlSelfRef.npc__DOT__imm)
                                           : ((IData)(4U) 
                                              + vlSelfRef.pc))));
}

void Vnpc___024root___eval_nba(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_nba\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vnpc___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vnpc___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vnpc___024root___eval_phase__act(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_phase__act\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vnpc___024root___eval_triggers__act(vlSelf);
    Vnpc___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vnpc___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vnpc___024root___eval_phase__nba(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_phase__nba\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vnpc___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vnpc___024root___eval_nba(vlSelf);
        Vnpc___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vnpc___024root___eval(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vnpc___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("vsrc/npc.v", 5, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vnpc___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("vsrc/npc.v", 5, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vnpc___024root___eval_phase__act(vlSelf));
    } while (Vnpc___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vnpc___024root___eval_debug_assertions(Vnpc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root___eval_debug_assertions\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
}
#endif  // VL_DEBUG
