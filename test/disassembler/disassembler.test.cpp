#include "disassembler/disassembler.hpp"
#include "common/data_source.hpp"
#include <cstdint>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ns;
using namespace testing;

class MockDataSource : public DataSource
{
public:
  MOCK_METHOD(bool, ReachedEof, (), (override));
  MOCK_METHOD(uint8_t, ReadNextByte, (), (override));
  MOCK_METHOD(int, GetByteOffset, (), (override));
};

TEST(AddressingModeTests, AddressingModeImpliedTest)
{
  // Arrange
  MockDataSource dataSource;
  EXPECT_CALL(dataSource, ReachedEof).WillOnce(Return(false)).WillOnce(Return(true));
  EXPECT_CALL(dataSource, ReadNextByte).WillOnce(Return(0x00));
  EXPECT_CALL(dataSource, GetByteOffset).WillOnce(Return(0x00));

  // Act
  auto disassembly = Disassembler::Disassemble(dataSource);

  // Assert
  ASSERT_EQ(disassembly.size(), 1);
  EXPECT_EQ(disassembly[0], "0000: BRK");
}

TEST(AddressingModeTests, AddressingModeAccumulatorTest)
{
  // Arrange
  MockDataSource dataSource;
  EXPECT_CALL(dataSource, ReachedEof).WillOnce(Return(false)).WillOnce(Return(true));
  EXPECT_CALL(dataSource, ReadNextByte).WillOnce(Return(0x0A));
  EXPECT_CALL(dataSource, GetByteOffset).WillOnce(Return(0x01));

  // Act
  auto disassembly = Disassembler::Disassemble(dataSource);

  // Assert
  ASSERT_EQ(disassembly.size(), 1);
  EXPECT_EQ(disassembly[0], "0001: ASL A");
}

TEST(AddressingModeTests, AddressingModeImmediateTest)
{
  // Arrange
  MockDataSource dataSource;
  EXPECT_CALL(dataSource, ReachedEof).WillOnce(Return(false)).WillOnce(Return(true));
  EXPECT_CALL(dataSource, ReadNextByte).WillOnce(Return(0x69)).WillOnce(Return(0xA5));
  EXPECT_CALL(dataSource, GetByteOffset).WillOnce(Return(0x00));

  // Act
  auto disassembly = Disassembler::Disassemble(dataSource);

  // Assert
  ASSERT_EQ(disassembly.size(), 1);
  EXPECT_EQ(disassembly[0], "0000: ADC #A5");
}

TEST(AddressingModeTests, AddressingModeZeroPageTest)
{
  // Arrange
  MockDataSource dataSource;
  EXPECT_CALL(dataSource, ReachedEof).WillOnce(Return(false)).WillOnce(Return(true));
  EXPECT_CALL(dataSource, ReadNextByte).WillOnce(Return(0x24)).WillOnce(Return(0xA5));
  EXPECT_CALL(dataSource, GetByteOffset).WillOnce(Return(0x03));

  // Act
  auto disassembly = Disassembler::Disassemble(dataSource);

  // Assert
  ASSERT_EQ(disassembly.size(), 1);
  EXPECT_EQ(disassembly[0], "0003: BIT $A5");
}

TEST(AddressingModeTests, AddressingModeZeroPageXTest)
{
  // Arrange
  MockDataSource dataSource;
  EXPECT_CALL(dataSource, ReachedEof).WillOnce(Return(false)).WillOnce(Return(true));
  EXPECT_CALL(dataSource, ReadNextByte).WillOnce(Return(0x75)).WillOnce(Return(0xA5));
  EXPECT_CALL(dataSource, GetByteOffset).WillOnce(Return(0x03));

  // Act
  auto disassembly = Disassembler::Disassemble(dataSource);

  // Assert
  ASSERT_EQ(disassembly.size(), 1);
  EXPECT_EQ(disassembly[0], "0003: ADC $A5, X");
}

TEST(AddressingModeTests, AddressingModeZeroPageYTest)
{
  // Arrange
  MockDataSource dataSource;
  EXPECT_CALL(dataSource, ReachedEof).WillOnce(Return(false)).WillOnce(Return(true));
  EXPECT_CALL(dataSource, ReadNextByte).WillOnce(Return(0xB6)).WillOnce(Return(0xB5));
  EXPECT_CALL(dataSource, GetByteOffset).WillOnce(Return(0x03));

  // Act
  auto disassembly = Disassembler::Disassemble(dataSource);

  // Assert
  ASSERT_EQ(disassembly.size(), 1);
  EXPECT_EQ(disassembly[0], "0003: LDX $B5, Y");
}

TEST(AddressingModeTests, AddressingModeRelativeTest)
{
  // Arrange
  MockDataSource dataSource;
  EXPECT_CALL(dataSource, ReachedEof).WillOnce(Return(false)).WillOnce(Return(true));
  EXPECT_CALL(dataSource, ReadNextByte).WillOnce(Return(0x90)).WillOnce(Return(0xA5));
  EXPECT_CALL(dataSource, GetByteOffset).WillOnce(Return(0x02));

  // Act
  auto disassembly = Disassembler::Disassemble(dataSource);

  // Assert
  ASSERT_EQ(disassembly.size(), 1);
  EXPECT_EQ(disassembly[0], "0002: BCC $A5");
}

TEST(AddressingModeTests, AddressingModeAbsoluteTest)
{
  // Arrange
  MockDataSource dataSource;
  EXPECT_CALL(dataSource, ReachedEof).WillOnce(Return(false)).WillOnce(Return(true));
  EXPECT_CALL(dataSource, ReadNextByte).WillOnce(Return(0x4C)).WillOnce(Return(0xB6)).WillOnce(Return(0xA5));
  EXPECT_CALL(dataSource, GetByteOffset).WillOnce(Return(0x02));

  // Act
  auto disassembly = Disassembler::Disassemble(dataSource);

  // Assert
  ASSERT_EQ(disassembly.size(), 1);
  EXPECT_EQ(disassembly[0], "0002: JMP $A5B6");
}

TEST(AddressingModeTests, AddressingModeAbsoluteXTest)
{
  // Arrange
  MockDataSource dataSource;
  EXPECT_CALL(dataSource, ReachedEof).WillOnce(Return(false)).WillOnce(Return(true));
  EXPECT_CALL(dataSource, ReadNextByte).WillOnce(Return(0xBD)).WillOnce(Return(0xB6)).WillOnce(Return(0xA5));
  EXPECT_CALL(dataSource, GetByteOffset).WillOnce(Return(0x02));

  // Act
  auto disassembly = Disassembler::Disassemble(dataSource);

  // Assert
  ASSERT_EQ(disassembly.size(), 1);
  EXPECT_EQ(disassembly[0], "0002: LDA $A5B6, X");
}

TEST(AddressingModeTests, AddressingModeAbsoluteYTest)
{
  // Arrange
  MockDataSource dataSource;
  EXPECT_CALL(dataSource, ReachedEof).WillOnce(Return(false)).WillOnce(Return(true));
  EXPECT_CALL(dataSource, ReadNextByte).WillOnce(Return(0xB9)).WillOnce(Return(0xB6)).WillOnce(Return(0xA5));
  EXPECT_CALL(dataSource, GetByteOffset).WillOnce(Return(0x0F));

  // Act
  auto disassembly = Disassembler::Disassemble(dataSource);

  // Assert
  ASSERT_EQ(disassembly.size(), 1);
  EXPECT_EQ(disassembly[0], "000F: LDA $A5B6, Y");
}

TEST(AddressingModeTests, AddressingModeIndirectTest)
{
  // Arrange
  MockDataSource dataSource;
  EXPECT_CALL(dataSource, ReachedEof).WillOnce(Return(false)).WillOnce(Return(true));
  EXPECT_CALL(dataSource, ReadNextByte).WillOnce(Return(0x6C)).WillOnce(Return(0xB6)).WillOnce(Return(0xA5));
  EXPECT_CALL(dataSource, GetByteOffset).WillOnce(Return(0x0F));

  // Act
  auto disassembly = Disassembler::Disassemble(dataSource);

  // Assert
  ASSERT_EQ(disassembly.size(), 1);
  EXPECT_EQ(disassembly[0], "000F: JMP ($A5B6)");
}

TEST(AddressingModeTests, AddressingModeIndexedIndirectTest)
{
  // Arrange
  MockDataSource dataSource;
  EXPECT_CALL(dataSource, ReachedEof).WillOnce(Return(false)).WillOnce(Return(true));
  EXPECT_CALL(dataSource, ReadNextByte).WillOnce(Return(0x21)).WillOnce(Return(0xA5));
  EXPECT_CALL(dataSource, GetByteOffset).WillOnce(Return(0x00));

  // Act
  auto disassembly = Disassembler::Disassemble(dataSource);

  // Assert
  ASSERT_EQ(disassembly.size(), 1);
  EXPECT_EQ(disassembly[0], "0000: AND ($A5, X)");
}

TEST(AddressingModeTests, AddressingModeIndirectIndexedTest)
{
  // Arrange
  MockDataSource dataSource;
  EXPECT_CALL(dataSource, ReachedEof).WillOnce(Return(false)).WillOnce(Return(true));
  EXPECT_CALL(dataSource, ReadNextByte).WillOnce(Return(0x31)).WillOnce(Return(0xA5));
  EXPECT_CALL(dataSource, GetByteOffset).WillOnce(Return(0x00));

  // Act
  auto disassembly = Disassembler::Disassemble(dataSource);

  // Assert
  ASSERT_EQ(disassembly.size(), 1);
  EXPECT_EQ(disassembly[0], "0000: AND ($A5), Y");
}

TEST(DisassemblerTests, MultipleInstructionTest)
{
  // Arrange
  MockDataSource dataSource;
  EXPECT_CALL(dataSource, ReachedEof).WillOnce(Return(false)).WillOnce(Return(false)).WillOnce(Return(true));
  EXPECT_CALL(dataSource, ReadNextByte)
    .WillOnce(Return(0x31))
    .WillOnce(Return(0xA5))
    .WillOnce(Return(0x21))
    .WillOnce(Return(0xA5));
  EXPECT_CALL(dataSource, GetByteOffset).WillOnce(Return(0x00)).WillOnce(Return(0x02));

  // Act
  auto disassembly = Disassembler::Disassemble(dataSource);

  // Assert
  ASSERT_EQ(disassembly.size(), 2);
  EXPECT_EQ(disassembly[0], "0000: AND ($A5), Y");
  EXPECT_EQ(disassembly[1], "0002: AND ($A5, X)");
}
