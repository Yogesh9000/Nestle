cmake_minimum_required(VERSION 3.28.2)
project(nestle
  VERSION 0.1.0
  DESCRIPTION "Nintendo Entairtenment System (NES) emulator"
  LANGUAGES CXX
)

add_library(project_settings INTERFACE)
target_compile_features(project_settings INTERFACE cxx_std_20)

include_directories("${PROJECT_SOURCE_DIR}/src")

add_subdirectory("src")

list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")
enable_testing()
add_subdirectory("test")
