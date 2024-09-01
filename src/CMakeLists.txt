set(DisSrc "disassembler/main.cpp" "disassembler/disassembler.cpp" "common/file_data_source.cpp")
add_executable(disassembler "${DisSrc}")
target_link_libraries(disassembler PRIVATE project_settings)
