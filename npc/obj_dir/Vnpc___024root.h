// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vnpc.h for the primary calling header

#ifndef VERILATED_VNPC___024ROOT_H_
#define VERILATED_VNPC___024ROOT_H_  // guard

#include "verilated.h"


class Vnpc__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vnpc___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(inst,31,0);
    VL_OUT(alu_result,31,0);
    VL_OUT(pc,31,0);
    IData/*31:0*/ npc__DOT____Vcellinp__pc_4__din;
    IData/*31:0*/ npc__DOT__src1;
    IData/*31:0*/ npc__DOT__src2;
    IData/*31:0*/ npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ npc__DOT__u_regfile__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> npc__DOT__u_decoder__DOT__u_RegisterFile1__DOT__rf;
    VlUnpacked<IData/*31:0*/, 32> npc__DOT__u_regfile__DOT__rf;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
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
