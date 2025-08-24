// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vnpc.h for the primary calling header

#ifndef VERILATED_VNPC___024ROOT_H_
#define VERILATED_VNPC___024ROOT_H_  // guard

#include "verilated.h"
class Vnpc___024unit;


class Vnpc__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vnpc___024root final : public VerilatedModule {
  public:
    // CELLS
    Vnpc___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset,0,0);
        CData/*0:0*/ npc__DOT__mem_en;
        CData/*0:0*/ npc__DOT__is_add;
        CData/*0:0*/ npc__DOT__is_xor;
        CData/*0:0*/ npc__DOT__is_or;
        CData/*0:0*/ npc__DOT__is_sltu;
        CData/*0:0*/ npc__DOT__is_sll;
        CData/*0:0*/ npc__DOT__is_and;
        CData/*0:0*/ npc__DOT__is_srl;
        CData/*0:0*/ npc__DOT__is_srli;
        CData/*0:0*/ npc__DOT__is_slt;
        CData/*0:0*/ npc__DOT__is_sra;
        CData/*0:0*/ npc__DOT__is_jalr;
        CData/*0:0*/ npc__DOT__is_addi;
        CData/*0:0*/ npc__DOT__is_lw;
        CData/*0:0*/ npc__DOT__is_lbu;
        CData/*0:0*/ npc__DOT__is_sltiu;
        CData/*0:0*/ npc__DOT__is_srai;
        CData/*0:0*/ npc__DOT__is_xori;
        CData/*0:0*/ npc__DOT__is_andi;
        CData/*0:0*/ npc__DOT__is_slli;
        CData/*0:0*/ npc__DOT__is_lh;
        CData/*0:0*/ npc__DOT__is_lhu;
        CData/*0:0*/ npc__DOT__is_sh;
        CData/*0:0*/ npc__DOT__is_sb;
        CData/*0:0*/ npc__DOT__is_bge;
        CData/*0:0*/ npc__DOT__is_bgeu;
        CData/*0:0*/ npc__DOT__is_bltu;
        CData/*0:0*/ npc__DOT__is_blt;
        CData/*0:0*/ npc__DOT____VdfgRegularize_h467b3cb3_0_8;
        CData/*0:0*/ npc__DOT____VdfgRegularize_h467b3cb3_0_17;
        CData/*0:0*/ npc__DOT____VdfgRegularize_h467b3cb3_0_19;
        CData/*0:0*/ npc__DOT____VdfgRegularize_h467b3cb3_0_20;
        CData/*0:0*/ npc__DOT____VdfgRegularize_h467b3cb3_0_21;
        CData/*0:0*/ npc__DOT____VdfgRegularize_h467b3cb3_0_22;
        CData/*6:0*/ npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0;
        CData/*6:0*/ npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Pre_hbc128af0_0_0;
        CData/*0:0*/ npc__DOT__u_alu__DOT__sltu;
        CData/*0:0*/ npc__DOT__u_alu__DOT__bne;
        CData/*0:0*/ npc__DOT__u_alu__DOT__sub;
        CData/*0:0*/ npc__DOT__u_alu__DOT__slt;
        CData/*0:0*/ npc__DOT__u_alu__DOT__beq;
        CData/*0:0*/ npc__DOT__u_alu__DOT__adder_cin;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __VactContinue;
        VL_OUT(alu_result,31,0);
        VL_OUT(pc,31,0);
        IData/*31:0*/ npc__DOT__nextpc;
        IData/*31:0*/ npc__DOT__inst;
        IData/*31:0*/ npc__DOT__imm;
        IData/*31:0*/ npc__DOT__src1;
        IData/*31:0*/ npc__DOT__alu_src1;
        IData/*31:0*/ npc__DOT__alu_src2;
        IData/*31:0*/ npc__DOT__raddr;
        IData/*31:0*/ npc__DOT__pmem_read_data;
        IData/*31:0*/ npc__DOT____VdfgRegularize_h467b3cb3_0_0;
        IData/*31:0*/ npc__DOT__u_alu__DOT__add_sub_result;
        IData/*31:0*/ npc__DOT__u_alu__DOT__adder_b;
        IData/*31:0*/ __Vfunc_v_pmem_read__0__Vfuncout;
        IData/*31:0*/ __Vfunc_v_pmem_read__1__Vfuncout;
        IData/*31:0*/ __Vfunc_v_pmem_read__2__Vfuncout;
        IData/*31:0*/ __Vfunc_v_pmem_read__3__Vfuncout;
    };
    struct {
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*0:0*/, 128> npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0;
        VlUnpacked<CData/*0:0*/, 128> npc__DOT__u1_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0;
        VlUnpacked<IData/*31:0*/, 32> npc__DOT__u_regfile2__DOT__rf;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vnpc__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vnpc___024root(Vnpc__Syms* symsp, const char* v__name);
    ~Vnpc___024root();
    VL_UNCOPYABLE(Vnpc___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
