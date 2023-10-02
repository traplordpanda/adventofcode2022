cmake_minimum_required(VERSION 3.27)

project(day5)

set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
add_compile_options(-Wall -Wextra -Werror -pedantic)

# FetchContent for the fmt library
include(FetchContent)
FetchContent_Declare(
    fmtlib
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
)
FetchContent_MakeAvailable(fmtlib)
# Specify the include directories for the compiler.
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_executable(main ${CMAKE_CURRENT_LIST_DIR}/source/main.cpp ${CMAKE_CURRENT_LIST_DIR}/source/crates.cpp )
target_compile_features(main PRIVATE cxx_std_20)
target_compile_options(main PRIVATE -Werror -Wpedantic -Wall -Wextra)

target_link_libraries(main fmt::fmt)