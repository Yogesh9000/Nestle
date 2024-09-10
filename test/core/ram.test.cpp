#include "core/ram.hpp"
#include <gtest/gtest.h>

class RamTests : public testing::Test
{
protected:
  // Arrange
  Ram ram;
};

TEST_F(RamTests, ReadAndWriteByte)
{
  // Act
  ram.WriteByte(0x200, 0xF);
  auto data = ram.ReadByte(0x200);

  // Assert
  ASSERT_EQ(data, 0xF);
}

TEST_F(RamTests, ReadAndWriteWord)
{
  // Act
  ram.WriteWord(0x600, 0xFABC);
  auto data = ram.ReadWord(0x600);

  // Assert
  ASSERT_EQ(data, 0xFABC);
}

TEST_F(RamTests, Mirroring)
{
  // Act
  ram.WriteByte(0x801, 0xFA);
  auto data1 = ram.ReadByte(0x1);

  ram.WriteWord(0x1FCC, 0xFABC);
  auto data2 = ram.ReadWord(0x7CC);

  // Assert
  ASSERT_EQ(data1, 0xFA);
  ASSERT_EQ(data2, 0xFABC);
}
