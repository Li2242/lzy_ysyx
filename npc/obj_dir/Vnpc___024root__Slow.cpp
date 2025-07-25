// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnpc.h for the primary calling header

#include "Vnpc__pch.h"
#include "Vnpc__Syms.h"
#include "Vnpc___024root.h"

void Vnpc___024root___ctor_var_reset(Vnpc___024root* vlSelf);

Vnpc___024root::Vnpc___024root(Vnpc__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vnpc___024root___ctor_var_reset(this);
}

void Vnpc___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vnpc___024root::~Vnpc___024root() {
}
