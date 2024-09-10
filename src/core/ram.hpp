#pragma once

#include "core/imemory.hpp"
#include <vector>

constexpr int RAM_SIZE{ 0x800 };// 2KB

class Ram : public IMemory
{
public:
  using MemoryType = std::vector<u8>;

  Ram();
  [[nodiscard]] const MemoryType &Raw() const;

  u8 ReadByte(u16 address) override;
  u16 ReadWord(u16 address) override;
  void WriteByte(u16 address, u8 data) override;
  void WriteWord(u16 address, u16 data) override;

private:
  MemoryType m_ram;
};
