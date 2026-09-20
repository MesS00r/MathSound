cmake_minimum_required(VERSION 3.10.0)
project(math_sound VERSION 0.1.0 LANGUAGES C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES
    "src/main.c"
    "lib/*.c"
)

add_executable(math_sound ${SOURCES})

target_include_directories(math_sound PRIVATE lib)

target_compile_options(math_sound PRIVATE
    -g
    -O1
    -Wall
    -Wextra
    -Wformat
    -Wshadow
    -Wconversion
    -Wsign-conversion
    -fstack-protector-strong
)