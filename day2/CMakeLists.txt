cmake_minimum_required(VERSION 3.27)

project(day2)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

add_executable(main src/main.cpp include/engine.hpp include/io.hpp)

target_compile_features(main PRIVATE cxx_std_20)
target_compile_options(main PRIVATE -Werror -Wpedantic -Wall -Wextra)

target_include_directories(main PRIVATE
  ${PROJECT_SOURCE_DIR}/include
)
