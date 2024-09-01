#include <cstdint>
#include <format>
#include <stdexcept>

#include "common/file_data_source.hpp"

using namespace ns;

void FileDataSource::Open(const std::string &fileName)
{
  file.open(fileName);
  if (!file.is_open()) { throw std::runtime_error(std::format("failed to open file: {}", fileName)); }
}


bool FileDataSource::ReachedEof() { return file.eof(); }

uint8_t FileDataSource::ReadNextByte()
{
  char byte{};
  file.read(&byte, 1);
  return static_cast<uint8_t>(byte);
}

int FileDataSource::GetByteOffset() { return file.tellg(); }
