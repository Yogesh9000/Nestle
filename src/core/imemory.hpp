#pragma once

#include "common/common.hpp"

class IMemory
{
public:
  virtual ~IMemory() = default;

  virtual u8 ReadByte(u16 address) = 0;
  virtual u16 ReadWord(u16 address) = 0;
  virtual void WriteByte(u16 address, u8 data) = 0;
  virtual void WriteWord(u16 address, u16 data) = 0;
};
