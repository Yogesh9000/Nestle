set(DisSrc "disassembler/main.cpp" "disassembler/disassembler.cpp")
add_executable(disassembler "${DisSrc}")
target_link_libraries(disassembler PRIVATE project_settings)
