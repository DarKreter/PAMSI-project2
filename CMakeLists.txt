cmake_minimum_required(VERSION 3.10)

project(PAMSI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CPU_OPTIONS -Werror -Wall -Wextra -pedantic -ffunction-sections -fdata-sections -Os)
add_compile_options(${CPU_OPTIONS})

add_subdirectory(Algorithms)
add_subdirectory(Movie)
add_subdirectory(FilterData)
add_subdirectory(firmware)