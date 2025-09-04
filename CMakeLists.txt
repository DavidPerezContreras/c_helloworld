cmake_minimum_required(VERSION 3.10)
project(hello_world VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(hello_world main.c)

# Enable AddressSanitizer only if supported
if(CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(hello_world PRIVATE -fsanitize=address -g)
    target_link_options(hello_world PRIVATE -fsanitize=address)
elseif(MSVC)
    message(STATUS "MSVC detected — enabling runtime checks")
    target_compile_options(hello_world PRIVATE /Zi /Od /RTC1)
    target_link_options(hello_world PRIVATE /DEBUG)
endif()

