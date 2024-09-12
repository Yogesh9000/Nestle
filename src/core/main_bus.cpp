#include "core/main_bus.hpp"
#include "common/common.hpp"
#include "core/imemory.hpp"
#include <cassert>
#include <format>

// Returns the memory device mapped to address location
IMemory *MainBus::GetDevice(u16 address)
{
  if (address >= 0x0000 && address < 0x2000) {
    return m_ram;
  } else if (address >= 0x2000 && address < 0x4000) {
    return m_ppu;
  } else if (address >= 0x4000 && address < 0x4020) {
    // TODO:
    // APU and IO Registers
    return nullptr;
  } else if (address >= 0x4020 && address <= 0xFFFF) {
    return m_mapper;
  } else {
    WARNING(std::format("Attempt to read from out of range memory location: {:0>4X}", address))
    return nullptr;
  }
}

u8 MainBus::ReadByte(u16 address)
{
  auto *device = GetDevice(address);
  assert(device != nullptr && "Attempt to read from location with no connected device");
  return device->ReadByte(address);
}

u16 MainBus::ReadWord(u16 address)
{
  auto *device = GetDevice(address);
  assert(device != nullptr && "Attempt to read from location with no connected device");
  return device->ReadWord(address);
}

void MainBus::WriteByte(u16 address, u8 data)
{
  auto *device = GetDevice(address);
  assert(device != nullptr && "Attempt to read from location with no connected device");
  device->WriteByte(address, data);
}

void MainBus::WriteWord(u16 address, u16 data)
{
  auto *device = GetDevice(address);
  assert(device != nullptr && "Attempt to read from location with no connected device");
  device->WriteWord(address, data);
}


void MainBus::RegisterRam(IMemory *ram)
{
  if (ram) {
    m_ram = ram;
  } else {
    WARNING("Failed to register RAM.")
  }
}

void MainBus::RegisterMapper(IMemory *mapper)
{
  if (mapper) {
    m_mapper = mapper;
  } else {
    WARNING("Failed to register Mapper.")
  }
}

void MainBus::RegisterPpu(IMemory *ppu)
{
  if (ppu) {
    m_ppu = ppu;
  } else {
    WARNING("Failed to register PPU.")
  }
}
