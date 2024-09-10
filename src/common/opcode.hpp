#pragma once

#include <array>
#include <string_view>

#include "addressing_mode.hpp"

struct Opcode
{
  std::string_view name;
  int length{};
  int cycle{};
  bool extraCycle{};
  AddressingMode mode;
  bool isIllegal{};

  constexpr static int NUM_OPCODES{ 0x100 };
  const static std::array<Opcode, NUM_OPCODES> opcodes;
};

constexpr std::array<Opcode, Opcode::NUM_OPCODES> Opcode::opcodes{ {
  { "BRK", 1, 7, false, AddressingMode::Implied, false },
  { "ORA", 2, 6, false, AddressingMode::IndexedIndirect, false },
  { "JAM", 1, -1, false, AddressingMode::Implied, true },
  { "SLO", 2, 8, false, AddressingMode::IndexedIndirect, true },
  { "NOP", 2, 3, false, AddressingMode::ZeroPage, true },
  { "ORA", 2, 3, false, AddressingMode::ZeroPage, false },
  { "ASL", 2, 5, false, AddressingMode::ZeroPage, false },
  { "SLO", 2, 5, false, AddressingMode::ZeroPage, true },
  { "PHP", 1, 3, false, AddressingMode::Implied, false },
  { "ORA", 2, 2, false, AddressingMode::Immediate, false },
  { "ASL", 1, 2, false, AddressingMode::Accumulator, false },
  { "ANC", 2, 2, false, AddressingMode::Immediate, true },
  { "NOP", 3, 4, false, AddressingMode::Absolute, true },
  { "ORA", 3, 4, false, AddressingMode::Absolute, false },
  { "ASL", 3, 6, false, AddressingMode::Absolute, false },
  { "SLO", 3, 6, false, AddressingMode::Absolute, true },
  { "BPL", 2, 2, true, AddressingMode::Relative, false },
  { "ORA", 2, 5, true, AddressingMode::IndirectIndexed, false },
  { "JAM", 1, -1, false, AddressingMode::Implied, true },
  { "SLO", 2, 8, false, AddressingMode::IndirectIndexed, true },
  { "NOP", 2, 4, false, AddressingMode::ZeroPageX, true },
  { "ORA", 2, 4, false, AddressingMode::ZeroPageX, false },
  { "ASL", 2, 6, false, AddressingMode::ZeroPageX, false },
  { "SLO", 2, 6, false, AddressingMode::ZeroPageX, true },
  { "CLC", 1, 2, false, AddressingMode::Implied, false },
  { "ORA", 3, 4, true, AddressingMode::AbsoluteY, false },
  { "NOP", 1, 2, false, AddressingMode::Implied, true },
  { "SLO", 3, 7, false, AddressingMode::AbsoluteY, true },
  { "NOP", 3, 4, true, AddressingMode::AbsoluteX, true },
  { "ORA", 3, 4, true, AddressingMode::AbsoluteX, false },
  { "ASL", 3, 7, false, AddressingMode::AbsoluteX, false },
  { "SLO", 3, 7, false, AddressingMode::AbsoluteX, true },
  { "JSR", 3, 6, false, AddressingMode::Absolute, false },
  { "AND", 2, 6, false, AddressingMode::IndexedIndirect, false },
  { "JAM", 1, -1, false, AddressingMode::Implied, true },
  { "RLA", 2, 8, false, AddressingMode::IndexedIndirect, true },
  { "BIT", 2, 3, false, AddressingMode::ZeroPage, false },
  { "AND", 2, 3, false, AddressingMode::ZeroPage, false },
  { "ROL", 2, 5, false, AddressingMode::ZeroPage, false },
  { "RLA", 2, 5, false, AddressingMode::ZeroPage, true },
  { "PLP", 1, 4, false, AddressingMode::Implied, false },
  { "AND", 2, 2, false, AddressingMode::Immediate, false },
  { "ROL", 1, 2, false, AddressingMode::Accumulator, false },
  { "ANC", 2, 2, false, AddressingMode::Immediate, true },
  { "BIT", 3, 4, false, AddressingMode::Absolute, false },
  { "AND", 3, 4, false, AddressingMode::Absolute, false },
  { "ROL", 3, 6, false, AddressingMode::Absolute, false },
  { "RLA", 3, 6, false, AddressingMode::Absolute, true },
  { "BMI", 2, 2, true, AddressingMode::Relative, false },
  { "AND", 2, 5, true, AddressingMode::IndirectIndexed, false },
  { "JAM", 1, -1, false, AddressingMode::Implied, true },
  { "RLA", 2, 8, false, AddressingMode::IndirectIndexed, true },
  { "NOP", 2, 4, false, AddressingMode::ZeroPageX, true },
  { "AND", 2, 4, false, AddressingMode::ZeroPageX, false },
  { "ROL", 2, 6, false, AddressingMode::ZeroPageX, false },
  { "RLA", 2, 6, false, AddressingMode::ZeroPageX, true },
  { "SEC", 1, 2, false, AddressingMode::Implied, false },
  { "AND", 3, 4, true, AddressingMode::AbsoluteY, false },
  { "NOP", 1, 2, false, AddressingMode::Implied, true },
  { "RLA", 3, 7, false, AddressingMode::AbsoluteY, true },
  { "NOP", 3, 4, true, AddressingMode::AbsoluteX, true },
  { "AND", 3, 4, true, AddressingMode::AbsoluteX, false },
  { "ROL", 3, 7, false, AddressingMode::AbsoluteX, false },
  { "RLA", 3, 7, false, AddressingMode::AbsoluteX, true },
  { "RTI", 1, 6, false, AddressingMode::Implied, false },
  { "EOR", 2, 6, false, AddressingMode::IndexedIndirect, false },
  { "JAM", 1, -1, false, AddressingMode::Implied, true },
  { "SRE", 2, 8, false, AddressingMode::IndexedIndirect, true },
  { "NOP", 2, 3, false, AddressingMode::ZeroPage, true },
  { "EOR", 2, 3, false, AddressingMode::ZeroPage, false },
  { "LSR", 2, 5, false, AddressingMode::ZeroPage, false },
  { "SRE", 2, 5, false, AddressingMode::ZeroPage, true },
  { "PHA", 1, 3, false, AddressingMode::Implied, false },
  { "EOR", 2, 2, false, AddressingMode::Immediate, false },
  { "LSR", 1, 2, false, AddressingMode::Accumulator, false },
  { "ASR", 2, 2, false, AddressingMode::Immediate, true },
  { "JMP", 3, 3, false, AddressingMode::Absolute, false },
  { "EOR", 3, 4, false, AddressingMode::Absolute, false },
  { "LSR", 3, 6, false, AddressingMode::Absolute, false },
  { "SRE", 3, 6, false, AddressingMode::Absolute, true },
  { "BVC", 2, 2, true, AddressingMode::Relative, false },
  { "EOR", 2, 5, true, AddressingMode::IndirectIndexed, false },
  { "JAM", 1, -1, false, AddressingMode::Implied, true },
  { "SRE", 2, 8, false, AddressingMode::IndirectIndexed, true },
  { "NOP", 2, 4, false, AddressingMode::ZeroPageX, true },
  { "EOR", 2, 4, false, AddressingMode::ZeroPageX, false },
  { "LSR", 2, 6, false, AddressingMode::ZeroPageX, false },
  { "SRE", 2, 6, false, AddressingMode::ZeroPageX, true },
  { "CLI", 1, 2, false, AddressingMode::Implied, false },
  { "EOR", 3, 4, true, AddressingMode::AbsoluteY, false },
  { "NOP", 1, 2, false, AddressingMode::Implied, true },
  { "SRE", 3, 7, false, AddressingMode::AbsoluteY, true },
  { "NOP", 3, 4, true, AddressingMode::AbsoluteX, true },
  { "EOR", 3, 4, true, AddressingMode::AbsoluteX, false },
  { "LSR", 3, 7, false, AddressingMode::AbsoluteX, false },
  { "SRE", 3, 7, false, AddressingMode::AbsoluteX, true },
  { "RTS", 1, 6, false, AddressingMode::Implied, false },
  { "ADC", 2, 6, false, AddressingMode::IndexedIndirect, false },
  { "JAM", 1, -1, false, AddressingMode::Implied, true },
  { "RRA", 2, 8, false, AddressingMode::IndexedIndirect, true },
  { "NOP", 2, 3, false, AddressingMode::ZeroPage, true },
  { "ADC", 2, 3, false, AddressingMode::ZeroPage, false },
  { "ROR", 2, 5, false, AddressingMode::ZeroPage, false },
  { "RRA", 2, 5, false, AddressingMode::ZeroPage, true },
  { "PLA", 1, 4, false, AddressingMode::Implied, false },
  { "ADC", 2, 2, false, AddressingMode::Immediate, false },
  { "ROR", 1, 2, false, AddressingMode::Accumulator, false },
  { "ARR", 2, 2, false, AddressingMode::Immediate, true },
  { "JMP", 3, 5, false, AddressingMode::Indirect, false },
  { "ADC", 3, 4, false, AddressingMode::Absolute, false },
  { "ROR", 3, 6, false, AddressingMode::Absolute, false },
  { "RRA", 3, 6, false, AddressingMode::Absolute, true },
  { "BVS", 2, 2, true, AddressingMode::Relative, false },
  { "ADC", 2, 5, true, AddressingMode::IndirectIndexed, false },
  { "JAM", 1, -1, false, AddressingMode::Implied, true },
  { "RRA", 2, 8, false, AddressingMode::IndirectIndexed, true },
  { "NOP", 2, 4, false, AddressingMode::ZeroPageX, true },
  { "ADC", 2, 4, false, AddressingMode::ZeroPageX, false },
  { "ROR", 2, 6, false, AddressingMode::ZeroPageX, false },
  { "RRA", 2, 6, false, AddressingMode::ZeroPageX, true },
  { "SEI", 1, 2, false, AddressingMode::Implied, false },
  { "ADC", 3, 4, true, AddressingMode::AbsoluteY, false },
  { "NOP", 1, 2, false, AddressingMode::Implied, true },
  { "RRA", 3, 7, false, AddressingMode::AbsoluteY, true },
  { "NOP", 3, 4, true, AddressingMode::AbsoluteX, true },
  { "ADC", 3, 4, true, AddressingMode::AbsoluteX, false },
  { "ROR", 3, 7, false, AddressingMode::AbsoluteX, false },
  { "RRA", 3, 7, false, AddressingMode::AbsoluteX, true },
  { "NOP", 2, 2, false, AddressingMode::Immediate, true },
  { "STA", 2, 6, false, AddressingMode::IndexedIndirect, false },
  { "NOP", 2, 2, false, AddressingMode::Immediate, true },
  { "SAX", 2, 6, false, AddressingMode::IndexedIndirect, true },
  { "STY", 2, 3, false, AddressingMode::ZeroPage, false },
  { "STA", 2, 3, false, AddressingMode::ZeroPage, false },
  { "STX", 2, 3, false, AddressingMode::ZeroPage, false },
  { "SAX", 2, 3, false, AddressingMode::ZeroPage, true },
  { "DEY", 1, 2, false, AddressingMode::Implied, false },
  { "NOP", 2, 2, false, AddressingMode::Immediate, true },
  { "TXA", 1, 2, false, AddressingMode::Implied, false },
  { "XAA", 2, 2, false, AddressingMode::Immediate, true },
  { "STY", 3, 4, false, AddressingMode::Absolute, false },
  { "STA", 3, 4, false, AddressingMode::Absolute, false },
  { "STX", 3, 4, false, AddressingMode::Absolute, false },
  { "SAX", 3, 4, false, AddressingMode::Absolute, true },
  { "BCC", 2, 2, true, AddressingMode::Relative, false },
  { "STA", 2, 6, false, AddressingMode::IndirectIndexed, false },
  { "JAM", 1, -1, false, AddressingMode::Implied, true },
  { "SHA", 2, 6, false, AddressingMode::IndirectIndexed, true },
  { "STY", 2, 4, false, AddressingMode::ZeroPageX, false },
  { "STA", 2, 4, false, AddressingMode::ZeroPageX, false },
  { "STX", 2, 4, false, AddressingMode::ZeroPageY, false },
  { "SAX", 2, 4, false, AddressingMode::ZeroPageY, true },
  { "TYA", 1, 2, false, AddressingMode::Implied, false },
  { "STA", 3, 5, false, AddressingMode::AbsoluteY, false },
  { "TXS", 1, 2, false, AddressingMode::Implied, false },
  { "SHS", 3, 5, false, AddressingMode::AbsoluteY, true },
  { "SHY", 3, 5, false, AddressingMode::AbsoluteX, true },
  { "STA", 3, 5, false, AddressingMode::AbsoluteX, false },
  { "SHX", 3, 5, false, AddressingMode::AbsoluteY, true },
  { "SHA", 3, 5, false, AddressingMode::AbsoluteY, true },
  { "LDY", 2, 2, false, AddressingMode::Immediate, false },
  { "LDA", 2, 6, false, AddressingMode::IndexedIndirect, false },
  { "LDX", 2, 2, false, AddressingMode::Immediate, false },
  { "LAX", 2, 6, false, AddressingMode::IndexedIndirect, true },
  { "LDY", 2, 3, false, AddressingMode::ZeroPage, false },
  { "LDA", 2, 3, false, AddressingMode::ZeroPage, false },
  { "LDX", 2, 3, false, AddressingMode::ZeroPage, false },
  { "LAX", 2, 3, false, AddressingMode::ZeroPage, true },
  { "TAY", 1, 2, false, AddressingMode::Implied, false },
  { "LDA", 2, 2, false, AddressingMode::Immediate, false },
  { "TAX", 1, 2, false, AddressingMode::Implied, false },
  { "LAX", 2, 2, false, AddressingMode::Immediate, true },
  { "LDY", 3, 4, false, AddressingMode::Absolute, false },
  { "LDA", 3, 4, false, AddressingMode::Absolute, false },
  { "LDX", 3, 4, false, AddressingMode::Absolute, false },
  { "LAX", 3, 4, false, AddressingMode::Absolute, true },
  { "BCS", 2, 2, true, AddressingMode::Relative, false },
  { "LDA", 2, 5, true, AddressingMode::IndirectIndexed, false },
  { "JAM", 1, -1, false, AddressingMode::Implied, true },
  { "LAX", 2, 5, true, AddressingMode::IndirectIndexed, false },
  { "LDY", 2, 4, false, AddressingMode::ZeroPageX, false },
  { "LDA", 2, 4, false, AddressingMode::ZeroPageX, false },
  { "LDX", 2, 4, false, AddressingMode::ZeroPageY, false },
  { "LAX", 2, 4, false, AddressingMode::ZeroPageY, true },
  { "CLV", 1, 2, false, AddressingMode::Implied, false },
  { "LDA", 3, 4, true, AddressingMode::AbsoluteY, false },
  { "TSX", 1, 2, false, AddressingMode::Implied, false },
  { "LAS", 3, 4, true, AddressingMode::AbsoluteY, true },
  { "LDY", 3, 4, true, AddressingMode::AbsoluteX, false },
  { "LDA", 3, 4, true, AddressingMode::AbsoluteX, false },
  { "LDX", 3, 4, true, AddressingMode::AbsoluteY, false },
  { "LAX", 3, 4, true, AddressingMode::AbsoluteY, true },
  { "CPY", 2, 2, false, AddressingMode::Immediate, false },
  { "CMP", 2, 6, false, AddressingMode::IndexedIndirect, false },
  { "NOP", 2, 2, false, AddressingMode::Immediate, true },
  { "DCP", 2, 8, false, AddressingMode::IndexedIndirect, true },
  { "CPY", 2, 3, false, AddressingMode::ZeroPage, false },
  { "CMP", 2, 3, false, AddressingMode::ZeroPage, false },
  { "DEC", 2, 5, false, AddressingMode::ZeroPage, false },
  { "DCP", 2, 5, false, AddressingMode::ZeroPage, true },
  { "INY", 1, 2, false, AddressingMode::Implied, false },
  { "CMP", 2, 2, false, AddressingMode::Immediate, false },
  { "DEX", 1, 2, false, AddressingMode::Implied, false },
  { "SBX", 2, 2, false, AddressingMode::Immediate, true },
  { "CPY", 3, 4, false, AddressingMode::Absolute, false },
  { "CMP", 3, 4, false, AddressingMode::Absolute, false },
  { "DEC", 3, 6, false, AddressingMode::Absolute, false },
  { "DCP", 3, 6, false, AddressingMode::Absolute, true },
  { "BNE", 2, 2, true, AddressingMode::Relative, false },
  { "CMP", 2, 5, true, AddressingMode::IndirectIndexed, false },
  { "JAM", 1, -1, false, AddressingMode::Implied, true },
  { "DCP", 2, 8, false, AddressingMode::IndirectIndexed, true },
  { "NOP", 2, 4, false, AddressingMode::ZeroPageX, true },
  { "CMP", 2, 4, false, AddressingMode::ZeroPageX, false },
  { "DEC", 2, 6, false, AddressingMode::ZeroPageX, false },
  { "DCP", 2, 6, false, AddressingMode::ZeroPageX, true },
  { "CLD", 1, 2, false, AddressingMode::Implied, false },
  { "CMP", 3, 4, true, AddressingMode::AbsoluteY, false },
  { "NOP", 1, 2, false, AddressingMode::Implied, true },
  { "DCP", 3, 7, false, AddressingMode::AbsoluteY, true },
  { "NOP", 3, 4, true, AddressingMode::AbsoluteX, true },
  { "CMP", 3, 4, true, AddressingMode::AbsoluteX, false },
  { "DEC", 3, 7, false, AddressingMode::AbsoluteX, false },
  { "DCP", 3, 7, false, AddressingMode::AbsoluteX, true },
  { "CPX", 2, 2, false, AddressingMode::Immediate, false },
  { "SBC", 2, 6, false, AddressingMode::IndexedIndirect, false },
  { "NOP", 2, 2, false, AddressingMode::Immediate, true },
  { "ISC", 2, 8, false, AddressingMode::IndexedIndirect, true },
  { "CPX", 2, 3, false, AddressingMode::ZeroPage, false },
  { "SBC", 2, 3, false, AddressingMode::ZeroPage, false },
  { "INC", 2, 5, false, AddressingMode::ZeroPage, false },
  { "ISC", 2, 5, false, AddressingMode::ZeroPage, true },
  { "INX", 1, 2, false, AddressingMode::Implied, false },
  { "SBC", 2, 2, false, AddressingMode::Immediate, false },
  { "NOP", 1, 2, false, AddressingMode::Implied, false },
  { "SBC", 2, 2, false, AddressingMode::Immediate, true },
  { "CPX", 3, 4, false, AddressingMode::Absolute, false },
  { "SBC", 3, 4, false, AddressingMode::Absolute, false },
  { "INC", 3, 6, false, AddressingMode::Absolute, false },
  { "ISC", 3, 6, false, AddressingMode::Absolute, true },
  { "BEQ", 2, 2, true, AddressingMode::Relative, false },
  { "SBC", 2, 5, true, AddressingMode::IndirectIndexed, false },
  { "JAM", 1, -1, false, AddressingMode::Implied, true },
  { "ISC", 2, 8, false, AddressingMode::IndirectIndexed, true },
  { "NOP", 2, 4, false, AddressingMode::ZeroPageX, true },
  { "SBC", 2, 4, false, AddressingMode::ZeroPageX, false },
  { "INC", 2, 6, false, AddressingMode::ZeroPageX, false },
  { "ISC", 2, 6, false, AddressingMode::ZeroPageX, true },
  { "SED", 1, 2, false, AddressingMode::Implied, false },
  { "SBC", 3, 4, true, AddressingMode::AbsoluteY, false },
  { "NOP", 1, 2, false, AddressingMode::Implied, true },
  { "ISC", 3, 7, false, AddressingMode::AbsoluteY, true },
  { "NOP", 3, 4, true, AddressingMode::AbsoluteX, true },
  { "SBC", 3, 4, true, AddressingMode::AbsoluteX, false },
  { "INC", 3, 7, false, AddressingMode::AbsoluteX, false },
  { "ISC", 3, 7, false, AddressingMode::AbsoluteX, true },
} };
