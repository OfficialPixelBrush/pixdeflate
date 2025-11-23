cmake_minimum_required(VERSION 3.16.0)
cmake_policy(SET CMP0072 NEW)

project(PixDeflate VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(
    PixDeflate
    helper.cpp
    deflate.cpp
    main.cpp
)

target_compile_definitions(PixDeflate PRIVATE -D_LIBCPP_ENABLE_EXPERIMENTAL=1)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(PixDeflate PRIVATE -ggdb)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
    set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address")
endif ()

set(CMAKE_SYSTEM_NAME Linux)

# If we're being extra pedantic
target_compile_options(PixDeflate PRIVATE
    # Make code more secure
    -Wall
    -Wextra
    -Wpedantic           # Enforce strict ISO compliance
    -Wconversion          # Implicit conversions (int → float, etc.)
    -Wsign-conversion     # Sign mismatches
    -Wshadow              # Variable shadowing
    -Wunused              # Unused variables, params, etc.
    -Wuninitialized
    -Werror               # Treat warnings as errors
    -Wnon-virtual-dtor    # Common OOP pitfall
    -Wold-style-cast
    -Woverloaded-virtual
    -Wnull-dereference
    -Wdouble-promotion
    -Wformat=2
)

target_link_libraries(
    PixDeflate
)