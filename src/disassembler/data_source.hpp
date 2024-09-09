#pragma once

#include "common/typedefs.hpp"
#include <cstdint>

namespace ns {

class IDataSource
{
public:
  virtual ~IDataSource() = default;

  // Returns true if reached end of DataSource
  virtual bool ReachedEof() = 0;

  // Reads the next byte from DataSource
  virtual u8 ReadNextByte() = 0;

  // Returns the offset of next byte which will be read.
  virtual int GetByteOffset() = 0;
};

}// namespace ns
