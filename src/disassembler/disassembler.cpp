#include <format>
#include <string>
#include <vector>

#include "common/addressing_mode.hpp"
#include "common/data_source.hpp"
#include "common/opcode.hpp"
#include "disassembler/disassembler.hpp"

using namespace ns;

auto &opcodes = Opcode::opcodes;

std::vector<std::string> Disassembler::Disassemble(IDataSource &source)
{
  std::vector<std::string> disassembly{};
  while (!source.ReachedEof()) {
    auto address = source.GetByteOffset();
    auto opcode = source.ReadNextByte();
    switch (opcodes[opcode].mode) {

    case AddressingMode::Implied: {
      auto instruction = std::format("{:0>4X}: {}", address, opcodes[opcode].name);
      disassembly.emplace_back(instruction);
    } break;

    case AddressingMode::Accumulator: {
      auto instruction = std::format("{:0>4X}: {} A", address, opcodes[opcode].name);
      disassembly.emplace_back(instruction);
    } break;

    case AddressingMode::Immediate: {
      auto op1 = source.ReadNextByte();
      auto instruction = std::format("{:0>4X}: {} #{:02X}", address, opcodes[opcode].name, op1);
      disassembly.emplace_back(instruction);
    } break;

    case AddressingMode::ZeroPage: {
      auto op1 = source.ReadNextByte();
      auto instruction = std::format("{:0>4X}: {} ${:02X}", address, opcodes[opcode].name, op1);
      disassembly.emplace_back(instruction);
    } break;

    case AddressingMode::ZeroPageX: {
      auto op1 = source.ReadNextByte();
      auto instruction = std::format("{:0>4X}: {} ${:02X}, X", address, opcodes[opcode].name, op1);
      disassembly.emplace_back(instruction);
    } break;

    case AddressingMode::ZeroPageY: {
      auto op1 = source.ReadNextByte();
      auto instruction = std::format("{:0>4X}: {} ${:02X}, Y", address, opcodes[opcode].name, op1);
      disassembly.emplace_back(instruction);
    } break;

    case AddressingMode::Relative: {
      auto op1 = source.ReadNextByte();
      auto instruction = std::format("{:0>4X}: {} ${:02X}", address, opcodes[opcode].name, op1);
      disassembly.emplace_back(instruction);
    } break;

    case AddressingMode::Absolute: {
      auto op2 = source.ReadNextByte();
      auto op1 = source.ReadNextByte();
      auto instruction = std::format("{:0>4x}: {} ${:02X}{:02X}", address, opcodes[opcode].name, op1, op2);
      disassembly.emplace_back(instruction);
    } break;

    case AddressingMode::AbsoluteX: {
      auto op2 = source.ReadNextByte();
      auto op1 = source.ReadNextByte();
      auto instruction = std::format("{:0>4x}: {} ${:02X}{:02X}, X", address, opcodes[opcode].name, op1, op2);
      disassembly.emplace_back(instruction);
    } break;

    case AddressingMode::AbsoluteY: {
      auto op2 = source.ReadNextByte();
      auto op1 = source.ReadNextByte();
      auto instruction = std::format("{:0>4X}: {} ${:02X}{:02X}, Y", address, opcodes[opcode].name, op1, op2);
      disassembly.emplace_back(instruction);
    } break;

    case AddressingMode::Indirect: {
      auto op2 = source.ReadNextByte();
      auto op1 = source.ReadNextByte();
      auto instruction = std::format("{:0>4X}: {} (${:02X}{:02X})", address, opcodes[opcode].name, op1, op2);
      disassembly.emplace_back(instruction);
    } break;

    case AddressingMode::IndexedIndirect: {
      auto op1 = source.ReadNextByte();
      auto instruction = std::format("{:0>4x}: {} (${:02X}, X)", address, opcodes[opcode].name, op1);
      disassembly.emplace_back(instruction);
    } break;

    case AddressingMode::IndirectIndexed: {
      auto op1 = source.ReadNextByte();
      auto instruction = std::format("{:0>4x}: {} (${:02X}), Y", address, opcodes[opcode].name, op1);
      disassembly.emplace_back(instruction);
    } break;

    default:
      disassembly.emplace_back(std::format("{}: unknown opcode", opcodes[opcode].name));
    }
  }
  return disassembly;
}
