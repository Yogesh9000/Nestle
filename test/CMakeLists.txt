find_package(GTest REQUIRED)

add_executable(disassembler_test "disassembler/disassembler.test.cpp" "${PROJECT_SOURCE_DIR}/src/disassembler/disassembler.cpp")
target_link_libraries(disassembler_test project_settings GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_executable(ram_test "core/ram.test.cpp" "${PROJECT_SOURCE_DIR}/src/core/ram.cpp")
target_link_libraries(ram_test project_settings GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_executable(bus_test "core/bus.test.cpp" "${PROJECT_SOURCE_DIR}/src/core/ram.cpp" "${PROJECT_SOURCE_DIR}/src/core/main_bus.cpp")
target_link_libraries(bus_test project_settings GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(disassembler_test)
gtest_discover_tests(bus_test)
