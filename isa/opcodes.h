#ifndef EVM_ISA_OPCODES_ISA_OPCODES_H
#define EVM_ISA_OPCODES_ISA_OPCODES_H

#include "common/constants.h"
#include "isa/macros.h"

namespace evm {

// clang-format off

#define DEFINE_INSTR(instr, opcode, imm_len, interpret) instr = opcode,

enum Opcode {
    #include "isa/isa.def"
};

#undef DEFINE_INSTR

// clang-format on
