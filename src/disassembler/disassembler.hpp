#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "disassembler/data_source.hpp"
namespace ns {

class Disassembler
{
public:
  static std::vector<std::string> Disassemble(IDataSource &);
};

}// namespace ns
