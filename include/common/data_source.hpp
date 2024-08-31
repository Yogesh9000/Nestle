#pragma once

#include <cstdint>
namespace ns {

class DataSource
{
public:
  virtual ~DataSource() = default;

  // Returns true if reached end of DataSource
  virtual bool ReachedEof() = 0;

  // Reads the next byte from DataSource
  virtual uint8_t ReadNextByte() = 0;

  // Returns the offset of next byte which will be read.
  virtual int GetByteOffset() = 0;
};

}// namespace ns
