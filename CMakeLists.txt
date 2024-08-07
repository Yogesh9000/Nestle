cmake_minimum_required(VERSION 3.28.2)
project(nestle
  VERSION 0.1.0
  DESCRIPTION "Nintendo Entairtenment System (NES) emulator"
  LANGUAGES CXX
)

add_library(project_settings INTERFACE)
target_compile_features(project_settings INTERFACE cxx_std_23)

add_subdirectory("src")

enable_testing()
add_subdirectory("test")
