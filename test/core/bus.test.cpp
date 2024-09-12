#include "core/main_bus.hpp"
#include "core/ram.hpp"

#include "gtest/gtest.h"

class BusTests : public testing::Test
{
protected:
  // Arrange

  void SetUp() override
  {
    bus.RegisterRam(&ram);
  }

  MainBus bus;
  Ram ram;
};

TEST_F(BusTests, BusTestReadWriteByteRam)
{
  // Act
  bus.WriteByte(0x200, 0xF);
  auto data = bus.ReadByte(0x200);

  // Assert
  ASSERT_EQ(data, 0xF);
}

TEST_F(BusTests, BusTestReadWriteWordRam)
{
  // Act
  bus.WriteWord(0x600, 0xFABC);
  auto data = bus.ReadWord(0x600);

  // Assert
  ASSERT_EQ(data, 0xFABC);
}
