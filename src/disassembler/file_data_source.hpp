#pragma once

#include "disassembler/data_source.hpp"
#include <cstdint>
#include <fstream>

namespace ns {

class FileDataSource : public IDataSource
{
public:
  // Opens a file for reading, may throw a exception if failed to open the file.
  void Open(const std::string &fileName);

  bool ReachedEof() override;
  uint8_t ReadNextByte() override;
  int GetByteOffset() override;

private:
  std::ifstream file;
};

}// namespace ns
