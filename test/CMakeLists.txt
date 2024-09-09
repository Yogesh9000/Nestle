find_package(GTest REQUIRED)

add_executable(disassembler_test "disassembler/disassembler.test.cpp" "${PROJECT_SOURCE_DIR}/src/disassembler/disassembler.cpp")
target_link_libraries(disassembler_test project_settings GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(disassembler_test)
