#include "disassembler/disassembler.hpp"
#include "disassembler/file_data_source.hpp"
#include <iostream>
#include <stdexcept>

using std::runtime_error;

using namespace ns;

int main(int argc, char **argv)
{
  if (argc != 2) {
    std::cout << "Usage: <file_path>\n";
    return -1;
  }
  FileDataSource fileSource;
  try {
    fileSource.Open(argv[1]);
  } catch (runtime_error &err) {
    std::cout << err.what() << "\n";
    return -1;
  }
  auto disassembly = Disassembler::Disassemble(fileSource);
  for (auto &str : disassembly) { std::cout << str << "\n"; }
  return 0;
}
