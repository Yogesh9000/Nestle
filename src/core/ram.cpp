#include "core/ram.hpp"

Ram::Ram() : m_ram(RAM_SIZE, 0x0) {}

const Ram::MemoryType &Ram::Raw() const
{
  return m_ram;
}

u8 Ram::ReadByte(u16 address)
{
  return m_ram[address % RAM_SIZE];
}

u16 Ram::ReadWord(u16 address)
{
  auto lo = m_ram[address % RAM_SIZE];
  auto hi = m_ram[(address + 1) % RAM_SIZE];
  return (hi << 8) | lo;
}

void Ram::WriteByte(u16 address, u8 data)
{
  m_ram[address % RAM_SIZE] = data;
}

void Ram::WriteWord(u16 address, u16 data)
{
  u8 lo = data & 0xFF;
  u8 hi = (data & 0xFF00) >> 8;
  m_ram[address % RAM_SIZE] = lo;
  m_ram[(address + 1) % RAM_SIZE] = hi;
}
