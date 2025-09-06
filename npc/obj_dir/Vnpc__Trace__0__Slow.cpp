// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vnpc__Syms.h"


VL_ATTR_COLD void Vnpc___024root__trace_init_sub__TOP__0(Vnpc___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_init_sub__TOP__0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+132,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+134,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("npc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+132,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+134,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"nextpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"inst31_25",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+3,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+4,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+5,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+6,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+7,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+8,0,"reg_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"mem_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"mem_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"reg_from_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"reg_from_pc_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"reg_from_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"imm_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"imm_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"imm_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"imm_J",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"imm_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"imm_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+19,0,"is_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"is_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"is_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"is_J",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"is_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"is_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"is_lui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"is_auipc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"is_jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"is_add",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"is_xor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"is_or",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"is_sltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"is_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"is_sll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"is_and",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"is_srl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"is_srli",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"is_slt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"is_sra",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"is_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"is_addi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"is_lw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"is_lbu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"is_sltiu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"is_srai",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"is_xori",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"is_andi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"is_slli",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"is_lh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"is_lhu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"is_sw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"is_sh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"is_sb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+137,0,"is_correct_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"is_bne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"is_bge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"is_beq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"is_bgeu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"is_bltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"is_blt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"is_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+58,0,"opcode_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+62,0,"funct3_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+63,0,"inst31_25_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+138,0,"final_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+67,0,"alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+25,0,"src1_is_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"src2_is_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"src2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+71,0,"alu_src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"alu_src2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+73,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"wmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+77,0,"pmem_read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u1_decoder7_128", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+2,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declArray(c+63,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+71,0,"src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"src2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+67,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+134,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+78,0,"add",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"sltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"bne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"xor0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"or0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"sra",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"sll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"and0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"slt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"beq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"srl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+86,0,"add_sub_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"sltu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"bne_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+89,0,"xor_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"or_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"sra_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"sll_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"and_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"slt_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"beq_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,0,"srl_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+71,0,"adder_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"adder_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+98,0,"adder_cin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+86,0,"adder_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+99,0,"adder_cout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_decoder3_8", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+4,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+62,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_decoder7_128", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+3,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declArray(c+58,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_regfile2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+140,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+132,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+138,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+69,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+70,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+100+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vnpc___024root__trace_init_top(Vnpc___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_init_top\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vnpc___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vnpc___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vnpc___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vnpc___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vnpc___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vnpc___024root__trace_register(Vnpc___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_register\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vnpc___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vnpc___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vnpc___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vnpc___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vnpc___024root__trace_const_0_sub_0(Vnpc___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vnpc___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_const_0\n"); );
    // Init
    Vnpc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vnpc___024root*>(voidSelf);
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vnpc___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vnpc___024root__trace_const_0_sub_0(Vnpc___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_const_0_sub_0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+139,(vlSelfRef.npc__DOT__imm_R),32);
    bufp->fullIData(oldp+140,(5U),32);
    bufp->fullIData(oldp+141,(0x20U),32);
}

VL_ATTR_COLD void Vnpc___024root__trace_full_0_sub_0(Vnpc___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vnpc___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_full_0\n"); );
    // Init
    Vnpc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vnpc___024root*>(voidSelf);
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vnpc___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vnpc___024root__trace_full_0_sub_0(Vnpc___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_full_0_sub_0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelfRef.npc__DOT__inst),32);
    bufp->fullCData(oldp+2,((vlSelfRef.npc__DOT__inst 
                             >> 0x19U)),7);
    bufp->fullCData(oldp+3,((0x7fU & vlSelfRef.npc__DOT__inst)),7);
    bufp->fullCData(oldp+4,((7U & (vlSelfRef.npc__DOT__inst 
                                   >> 0xcU))),3);
    bufp->fullCData(oldp+5,((0x1fU & (vlSelfRef.npc__DOT__inst 
                                      >> 0xfU))),5);
    bufp->fullCData(oldp+6,((0x1fU & (vlSelfRef.npc__DOT__inst 
                                      >> 0x14U))),5);
    bufp->fullCData(oldp+7,((0x1fU & (vlSelfRef.npc__DOT__inst 
                                      >> 7U))),5);
    bufp->fullBit(oldp+8,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                           [0x17U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                      [0x37U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x6fU] 
                                                 | ((IData)(vlSelfRef.npc__DOT__is_jalr) 
                                                    | ((IData)(vlSelfRef.npc__DOT__is_addi) 
                                                       | ((IData)(vlSelfRef.npc__DOT__is_add) 
                                                          | ((IData)(vlSelfRef.npc__DOT__is_lw) 
                                                             | ((IData)(vlSelfRef.npc__DOT__is_lbu) 
                                                                | ((IData)(vlSelfRef.npc__DOT__is_sltiu) 
                                                                   | ((IData)(vlSelfRef.npc__DOT__is_xor) 
                                                                      | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__or0) 
                                                                         | ((IData)(vlSelfRef.npc__DOT__is_sltu) 
                                                                            | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sub) 
                                                                               | ((IData)(vlSelfRef.npc__DOT__is_srai) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_sll) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_and) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_xori) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_andi) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_srl) 
                                                                                | ((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_21) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_slt) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_lh) 
                                                                                | ((IData)(vlSelfRef.npc__DOT__is_lhu) 
                                                                                | (IData)(vlSelfRef.npc__DOT__is_sra))))))))))))))))))))))))));
    bufp->fullBit(oldp+9,(vlSelfRef.npc__DOT__mem_en));
    bufp->fullBit(oldp+10,(((IData)(((0x2000U == (0x7000U 
                                                  & vlSelfRef.npc__DOT__inst)) 
                                     & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                     [0x23U])) | ((IData)(vlSelfRef.npc__DOT__is_sb) 
                                                  | (IData)(vlSelfRef.npc__DOT__is_sh)))));
    bufp->fullBit(oldp+11,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                            [0x6fU] | (IData)(vlSelfRef.npc__DOT__is_jalr))));
    bufp->fullBit(oldp+12,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                           [0x37U]));
    bufp->fullIData(oldp+13,(vlSelfRef.npc__DOT__imm),32);
    bufp->fullIData(oldp+14,((((- (IData)((vlSelfRef.npc__DOT__inst 
                                           >> 0x1fU))) 
                               << 0xcU) | (vlSelfRef.npc__DOT__inst 
                                           >> 0x14U))),32);
    bufp->fullIData(oldp+15,((0xfffff000U & vlSelfRef.npc__DOT__inst)),32);
    bufp->fullIData(oldp+16,(((((- (IData)((vlSelfRef.npc__DOT__inst 
                                            >> 0x1fU))) 
                                << 0x15U) | (0x100000U 
                                             & (vlSelfRef.npc__DOT__inst 
                                                >> 0xbU))) 
                              | (((0xff000U & vlSelfRef.npc__DOT__inst) 
                                  | (0x800U & (vlSelfRef.npc__DOT__inst 
                                               >> 9U))) 
                                 | (0x7feU & (vlSelfRef.npc__DOT__inst 
                                              >> 0x14U))))),32);
    bufp->fullIData(oldp+17,((((- (IData)((vlSelfRef.npc__DOT__inst 
                                           >> 0x1fU))) 
                               << 0xcU) | ((0xfe0U 
                                            & (vlSelfRef.npc__DOT__inst 
                                               >> 0x14U)) 
                                           | (0x1fU 
                                              & (vlSelfRef.npc__DOT__inst 
                                                 >> 7U))))),32);
    bufp->fullIData(oldp+18,((((- (IData)((vlSelfRef.npc__DOT__inst 
                                           >> 0x1fU))) 
                               << 0xdU) | (((0x1000U 
                                             & (vlSelfRef.npc__DOT__inst 
                                                >> 0x13U)) 
                                            | (0x800U 
                                               & (vlSelfRef.npc__DOT__inst 
                                                  << 4U))) 
                                           | ((0x7e0U 
                                               & (vlSelfRef.npc__DOT__inst 
                                                  >> 0x14U)) 
                                              | (0x1eU 
                                                 & (vlSelfRef.npc__DOT__inst 
                                                    >> 7U)))))),32);
    bufp->fullBit(oldp+19,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                           [0x33U]));
    bufp->fullBit(oldp+20,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                            [0x13U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                       [3U] | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                       [0x67U]))));
    bufp->fullBit(oldp+21,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                            [0x37U] | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                            [0x17U])));
    bufp->fullBit(oldp+22,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                           [0x6fU]));
    bufp->fullBit(oldp+23,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                           [0x23U]));
    bufp->fullBit(oldp+24,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                           [0x63U]));
    bufp->fullBit(oldp+25,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                           [0x17U]));
    bufp->fullBit(oldp+26,(vlSelfRef.npc__DOT__is_add));
    bufp->fullBit(oldp+27,(vlSelfRef.npc__DOT__is_xor));
    bufp->fullBit(oldp+28,(vlSelfRef.npc__DOT__u_alu__DOT__or0));
    bufp->fullBit(oldp+29,(vlSelfRef.npc__DOT__is_sltu));
    bufp->fullBit(oldp+30,(vlSelfRef.npc__DOT__u_alu__DOT__sub));
    bufp->fullBit(oldp+31,(vlSelfRef.npc__DOT__is_sll));
    bufp->fullBit(oldp+32,(vlSelfRef.npc__DOT__is_and));
    bufp->fullBit(oldp+33,(vlSelfRef.npc__DOT__is_srl));
    bufp->fullBit(oldp+34,(vlSelfRef.npc__DOT__is_srli));
    bufp->fullBit(oldp+35,(vlSelfRef.npc__DOT__is_slt));
    bufp->fullBit(oldp+36,(vlSelfRef.npc__DOT__is_sra));
    bufp->fullBit(oldp+37,(vlSelfRef.npc__DOT__is_jalr));
    bufp->fullBit(oldp+38,(vlSelfRef.npc__DOT__is_addi));
    bufp->fullBit(oldp+39,(vlSelfRef.npc__DOT__is_lw));
    bufp->fullBit(oldp+40,(vlSelfRef.npc__DOT__is_lbu));
    bufp->fullBit(oldp+41,(vlSelfRef.npc__DOT__is_sltiu));
    bufp->fullBit(oldp+42,(vlSelfRef.npc__DOT__is_srai));
    bufp->fullBit(oldp+43,(vlSelfRef.npc__DOT__is_xori));
    bufp->fullBit(oldp+44,(vlSelfRef.npc__DOT__is_andi));
    bufp->fullBit(oldp+45,(vlSelfRef.npc__DOT__is_slli));
    bufp->fullBit(oldp+46,(vlSelfRef.npc__DOT__is_lh));
    bufp->fullBit(oldp+47,(vlSelfRef.npc__DOT__is_lhu));
    bufp->fullBit(oldp+48,((IData)(((0x2000U == (0x7000U 
                                                 & vlSelfRef.npc__DOT__inst)) 
                                    & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                    [0x23U]))));
    bufp->fullBit(oldp+49,(vlSelfRef.npc__DOT__is_sh));
    bufp->fullBit(oldp+50,(vlSelfRef.npc__DOT__is_sb));
    bufp->fullBit(oldp+51,(vlSelfRef.npc__DOT__u_alu__DOT__bne));
    bufp->fullBit(oldp+52,(vlSelfRef.npc__DOT__is_bge));
    bufp->fullBit(oldp+53,(vlSelfRef.npc__DOT__u_alu__DOT__beq));
    bufp->fullBit(oldp+54,(vlSelfRef.npc__DOT__is_bgeu));
    bufp->fullBit(oldp+55,(vlSelfRef.npc__DOT__is_bltu));
    bufp->fullBit(oldp+56,(vlSelfRef.npc__DOT__is_blt));
    bufp->fullBit(oldp+57,((0x100073U == vlSelfRef.npc__DOT__inst)));
    bufp->fullWData(oldp+58,(vlSelfRef.npc__DOT__opcode_d),128);
    bufp->fullCData(oldp+62,((((((7U == (7U & (vlSelfRef.npc__DOT__inst 
                                               >> 0xcU))) 
                                 << 7U) | ((6U == (7U 
                                                   & (vlSelfRef.npc__DOT__inst 
                                                      >> 0xcU))) 
                                           << 6U)) 
                               | (((5U == (7U & (vlSelfRef.npc__DOT__inst 
                                                 >> 0xcU))) 
                                   << 5U) | ((4U == 
                                              (7U & 
                                               (vlSelfRef.npc__DOT__inst 
                                                >> 0xcU))) 
                                             << 4U))) 
                              | ((((3U == (7U & (vlSelfRef.npc__DOT__inst 
                                                 >> 0xcU))) 
                                   << 3U) | ((2U == 
                                              (7U & 
                                               (vlSelfRef.npc__DOT__inst 
                                                >> 0xcU))) 
                                             << 2U)) 
                                 | (((1U == (7U & (vlSelfRef.npc__DOT__inst 
                                                   >> 0xcU))) 
                                     << 1U) | (0U == 
                                               (7U 
                                                & (vlSelfRef.npc__DOT__inst 
                                                   >> 0xcU))))))),8);
    bufp->fullWData(oldp+63,(vlSelfRef.npc__DOT__inst31_25_d),128);
    bufp->fullSData(oldp+67,(((((((IData)(vlSelfRef.npc__DOT__is_srl) 
                                  | (IData)(vlSelfRef.npc__DOT__is_srli)) 
                                 << 0xbU) | (((IData)(vlSelfRef.npc__DOT__u_alu__DOT__beq) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__slt) 
                                                << 9U))) 
                               | ((((IData)(vlSelfRef.npc__DOT__is_and) 
                                    | (IData)(vlSelfRef.npc__DOT__is_andi)) 
                                   << 8U) | ((((IData)(vlSelfRef.npc__DOT__is_sll) 
                                               | (IData)(vlSelfRef.npc__DOT__is_slli)) 
                                              << 7U) 
                                             | (((IData)(vlSelfRef.npc__DOT__is_srai) 
                                                 | (IData)(vlSelfRef.npc__DOT__is_sra)) 
                                                << 6U)))) 
                              | ((((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sub) 
                                   << 5U) | (((IData)(vlSelfRef.npc__DOT__u_alu__DOT__or0) 
                                              << 4U) 
                                             | (((IData)(vlSelfRef.npc__DOT__is_xor) 
                                                 | (IData)(vlSelfRef.npc__DOT__is_xori)) 
                                                << 3U))) 
                                 | (((IData)(vlSelfRef.npc__DOT__u_alu__DOT__bne) 
                                     << 2U) | (((IData)(vlSelfRef.npc__DOT__u_alu__DOT__sltu) 
                                                << 1U) 
                                               | ((IData)(vlSelfRef.npc__DOT__is_add) 
                                                  | (IData)(vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_20))))))),12);
    bufp->fullBit(oldp+68,(((IData)(vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_20) 
                            | ((IData)(vlSelfRef.npc__DOT__is_sltiu) 
                               | ((IData)(vlSelfRef.npc__DOT__is_srai) 
                                  | ((IData)(vlSelfRef.npc__DOT__is_xori) 
                                     | ((IData)(vlSelfRef.npc__DOT__is_andi) 
                                        | (IData)(vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_21))))))));
    bufp->fullIData(oldp+69,(vlSelfRef.npc__DOT__src1),32);
    bufp->fullIData(oldp+70,(((0U == (0x1fU & (vlSelfRef.npc__DOT__inst 
                                               >> 0x14U)))
                               ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                              [(0x1fU & (vlSelfRef.npc__DOT__inst 
                                         >> 0x14U))])),32);
    bufp->fullIData(oldp+71,(vlSelfRef.npc__DOT__u_alu__DOT__adder_a),32);
    bufp->fullIData(oldp+72,(vlSelfRef.npc__DOT__alu_src2),32);
    bufp->fullIData(oldp+73,(((IData)(vlSelfRef.npc__DOT__mem_en)
                               ? (((IData)(vlSelfRef.npc__DOT__is_lbu) 
                                   | (IData)(vlSelfRef.npc__DOT__is_lhu))
                                   ? vlSelfRef.npc__DOT__pmem_read_data
                                   : ((IData)(vlSelfRef.npc__DOT__is_lh)
                                       ? (((- (IData)(
                                                      (1U 
                                                       & (vlSelfRef.npc__DOT__pmem_read_data 
                                                          >> 0xfU)))) 
                                           << 0x10U) 
                                          | (0xffffU 
                                             & vlSelfRef.npc__DOT__pmem_read_data))
                                       : vlSelfRef.npc__DOT__pmem_read_data))
                               : 0U)),32);
    bufp->fullIData(oldp+74,(vlSelfRef.npc__DOT__raddr),32);
    bufp->fullIData(oldp+75,((((IData)(((0x2000U == 
                                         (0x7000U & vlSelfRef.npc__DOT__inst)) 
                                        & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                        [0x23U])) | 
                               ((IData)(vlSelfRef.npc__DOT__is_sb) 
                                | (IData)(vlSelfRef.npc__DOT__is_sh)))
                               ? vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0
                               : 0x80000000U)),32);
    bufp->fullCData(oldp+76,(((IData)(vlSelfRef.npc__DOT__is_sb)
                               ? 1U : ((IData)(vlSelfRef.npc__DOT__is_sh)
                                        ? 3U : 0xfU))),8);
    bufp->fullIData(oldp+77,(vlSelfRef.npc__DOT__pmem_read_data),32);
    bufp->fullBit(oldp+78,(((IData)(vlSelfRef.npc__DOT__is_add) 
                            | (IData)(vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_20))));
    bufp->fullBit(oldp+79,(vlSelfRef.npc__DOT__u_alu__DOT__sltu));
    bufp->fullBit(oldp+80,(((IData)(vlSelfRef.npc__DOT__is_xor) 
                            | (IData)(vlSelfRef.npc__DOT__is_xori))));
    bufp->fullBit(oldp+81,(((IData)(vlSelfRef.npc__DOT__is_srai) 
                            | (IData)(vlSelfRef.npc__DOT__is_sra))));
    bufp->fullBit(oldp+82,(((IData)(vlSelfRef.npc__DOT__is_sll) 
                            | (IData)(vlSelfRef.npc__DOT__is_slli))));
    bufp->fullBit(oldp+83,(((IData)(vlSelfRef.npc__DOT__is_and) 
                            | (IData)(vlSelfRef.npc__DOT__is_andi))));
    bufp->fullBit(oldp+84,(vlSelfRef.npc__DOT__u_alu__DOT__slt));
    bufp->fullBit(oldp+85,(((IData)(vlSelfRef.npc__DOT__is_srl) 
                            | (IData)(vlSelfRef.npc__DOT__is_srli))));
    bufp->fullIData(oldp+86,(vlSelfRef.npc__DOT__u_alu__DOT__add_sub_result),32);
    bufp->fullIData(oldp+87,((1U & (~ (IData)((1ULL 
                                               & (((QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_a)) 
                                                   + 
                                                   ((QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_b)) 
                                                    + (QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_cin)))) 
                                                  >> 0x20U)))))),32);
    bufp->fullIData(oldp+88,((0U != vlSelfRef.npc__DOT__u_alu__DOT__add_sub_result)),32);
    bufp->fullIData(oldp+89,((vlSelfRef.npc__DOT__u_alu__DOT__adder_a 
                              ^ vlSelfRef.npc__DOT__alu_src2)),32);
    bufp->fullIData(oldp+90,((vlSelfRef.npc__DOT__u_alu__DOT__adder_a 
                              | vlSelfRef.npc__DOT__alu_src2)),32);
    bufp->fullIData(oldp+91,(VL_SHIFTRS_III(32,32,5, vlSelfRef.npc__DOT__u_alu__DOT__adder_a, 
                                            (0x1fU 
                                             & vlSelfRef.npc__DOT__alu_src2))),32);
    bufp->fullIData(oldp+92,((vlSelfRef.npc__DOT__u_alu__DOT__adder_a 
                              << (0x1fU & vlSelfRef.npc__DOT__alu_src2))),32);
    bufp->fullIData(oldp+93,((vlSelfRef.npc__DOT__u_alu__DOT__adder_a 
                              & vlSelfRef.npc__DOT__alu_src2)),32);
    bufp->fullIData(oldp+94,((1U & (((vlSelfRef.npc__DOT__u_alu__DOT__adder_a 
                                      >> 0x1fU) == 
                                     (vlSelfRef.npc__DOT__alu_src2 
                                      >> 0x1fU)) ? 
                                    (vlSelfRef.npc__DOT__u_alu__DOT__add_sub_result 
                                     >> 0x1fU) : (vlSelfRef.npc__DOT__u_alu__DOT__adder_a 
                                                  >> 0x1fU)))),32);
    bufp->fullIData(oldp+95,((1U & (~ (0U != vlSelfRef.npc__DOT__u_alu__DOT__add_sub_result)))),32);
    bufp->fullIData(oldp+96,((vlSelfRef.npc__DOT__u_alu__DOT__adder_a 
                              >> (0x1fU & vlSelfRef.npc__DOT__alu_src2))),32);
    bufp->fullIData(oldp+97,(vlSelfRef.npc__DOT__u_alu__DOT__adder_b),32);
    bufp->fullBit(oldp+98,(vlSelfRef.npc__DOT__u_alu__DOT__adder_cin));
    bufp->fullBit(oldp+99,((1U & (IData)((1ULL & (((QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_a)) 
                                                   + 
                                                   ((QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_b)) 
                                                    + (QData)((IData)(vlSelfRef.npc__DOT__u_alu__DOT__adder_cin)))) 
                                                  >> 0x20U))))));
    bufp->fullIData(oldp+100,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[0]),32);
    bufp->fullIData(oldp+101,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[1]),32);
    bufp->fullIData(oldp+102,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[2]),32);
    bufp->fullIData(oldp+103,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[3]),32);
    bufp->fullIData(oldp+104,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[4]),32);
    bufp->fullIData(oldp+105,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[5]),32);
    bufp->fullIData(oldp+106,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[6]),32);
    bufp->fullIData(oldp+107,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[7]),32);
    bufp->fullIData(oldp+108,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[8]),32);
    bufp->fullIData(oldp+109,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[9]),32);
    bufp->fullIData(oldp+110,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[10]),32);
    bufp->fullIData(oldp+111,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[11]),32);
    bufp->fullIData(oldp+112,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[12]),32);
    bufp->fullIData(oldp+113,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[13]),32);
    bufp->fullIData(oldp+114,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[14]),32);
    bufp->fullIData(oldp+115,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[15]),32);
    bufp->fullIData(oldp+116,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[16]),32);
    bufp->fullIData(oldp+117,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[17]),32);
    bufp->fullIData(oldp+118,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[18]),32);
    bufp->fullIData(oldp+119,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[19]),32);
    bufp->fullIData(oldp+120,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[20]),32);
    bufp->fullIData(oldp+121,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[21]),32);
    bufp->fullIData(oldp+122,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[22]),32);
    bufp->fullIData(oldp+123,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[23]),32);
    bufp->fullIData(oldp+124,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[24]),32);
    bufp->fullIData(oldp+125,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[25]),32);
    bufp->fullIData(oldp+126,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[26]),32);
    bufp->fullIData(oldp+127,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[27]),32);
    bufp->fullIData(oldp+128,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[28]),32);
    bufp->fullIData(oldp+129,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[29]),32);
    bufp->fullIData(oldp+130,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[30]),32);
    bufp->fullIData(oldp+131,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[31]),32);
    bufp->fullBit(oldp+132,(vlSelfRef.clk));
    bufp->fullBit(oldp+133,(vlSelfRef.reset));
    bufp->fullIData(oldp+134,(vlSelfRef.alu_result),32);
    bufp->fullIData(oldp+135,(vlSelfRef.pc),32);
    bufp->fullIData(oldp+136,(((IData)(vlSelfRef.npc__DOT__is_jalr)
                                ? (0xfffffffeU & vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0)
                                : ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                    [0x6fU] | ((((IData)(vlSelfRef.npc__DOT__u_alu__DOT__bne) 
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
                                       + vlSelfRef.pc)))),32);
    bufp->fullBit(oldp+137,(((((IData)(vlSelfRef.npc__DOT__u_alu__DOT__bne) 
                               | ((IData)(vlSelfRef.npc__DOT__u_alu__DOT__beq) 
                                  | ((IData)(vlSelfRef.npc__DOT__is_bltu) 
                                     | (IData)(vlSelfRef.npc__DOT__is_blt)))) 
                              & (1U == vlSelfRef.alu_result)) 
                             | (((IData)(vlSelfRef.npc__DOT__is_bgeu) 
                                 | (IData)(vlSelfRef.npc__DOT__is_bge)) 
                                & (0U == vlSelfRef.alu_result)))));
    bufp->fullIData(oldp+138,(((IData)(vlSelfRef.npc__DOT__mem_en)
                                ? ((IData)(vlSelfRef.npc__DOT__mem_en)
                                    ? (((IData)(vlSelfRef.npc__DOT__is_lbu) 
                                        | (IData)(vlSelfRef.npc__DOT__is_lhu))
                                        ? vlSelfRef.npc__DOT__pmem_read_data
                                        : ((IData)(vlSelfRef.npc__DOT__is_lh)
                                            ? (((- (IData)(
                                                           (1U 
                                                            & (vlSelfRef.npc__DOT__pmem_read_data 
                                                               >> 0xfU)))) 
                                                << 0x10U) 
                                               | (0xffffU 
                                                  & vlSelfRef.npc__DOT__pmem_read_data))
                                            : vlSelfRef.npc__DOT__pmem_read_data))
                                    : 0U) : ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                              [0x6fU] 
                                              | (IData)(vlSelfRef.npc__DOT__is_jalr))
                                              ? ((IData)(4U) 
                                                 + vlSelfRef.pc)
                                              : (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                 [0x37U]
                                                  ? vlSelfRef.npc__DOT__imm
                                                  : vlSelfRef.alu_result)))),32);
}
