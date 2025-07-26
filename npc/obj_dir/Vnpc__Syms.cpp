// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vnpc__pch.h"
#include "Vnpc.h"
#include "Vnpc___024root.h"
#include "Vnpc___024unit.h"

void Vnpc___024root____Vdpiexp_npc__DOT__u_regfile2__DOT__get_reg_TOP(Vnpc__Syms* __restrict vlSymsp, IData/*31:0*/ index, IData/*31:0*/ &get_reg__Vfuncrtn);

// FUNCTIONS
Vnpc__Syms::~Vnpc__Syms()
{
}

Vnpc__Syms::Vnpc__Syms(VerilatedContext* contextp, const char* namep, Vnpc* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP____024unit{this, Verilated::catName(namep, "$unit")}
{
        // Check resources
        Verilated::stackCheck(73);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT____024unit = &TOP____024unit;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP____024unit.__Vconfigure(true);
    // Setup scopes
    __Vscope_npc__u_regfile2.configure(this, name(), "npc.u_regfile2", "u_regfile2", "<null>", -12, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_npc__u_regfile2.exportInsert(__Vfinal, "get_reg", (void*)(&Vnpc___024root____Vdpiexp_npc__DOT__u_regfile2__DOT__get_reg_TOP));
    }
}
