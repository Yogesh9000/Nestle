#pragma once

#include "core/imemory.hpp"
class MainBus : public IMemory
{
public:
  u8 ReadByte(u16 address) override;
  u16 ReadWord(u16 address) override;
  void WriteByte(u16 address, u8 data) override;
  void WriteWord(u16 address, u16 data) override;

  void RegisterRam(IMemory *ram);
  void RegisterMapper(IMemory *mapper);
  void RegisterPpu(IMemory *ppu);

private:
  IMemory *GetDevice(u16 address);

  IMemory *m_ram{ nullptr };
  IMemory *m_mapper{ nullptr };
  IMemory *m_ppu{ nullptr };
};
