cmake_minimum_required(VERSION 3.10)

project(PAMSI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CPU_OPTIONS -Werror -Wall -Wextra -pedantic -ffunction-sections -fdata-sections -Os)

set(LIBS movie)


add_compile_options(${CPU_OPTIONS})

add_library(movie src/Movie.cpp inc/Movie.hpp)
# add_library(pair src/Pair.cpp inc/Pair.hpp fml/Pair.tpp)

target_include_directories(movie PUBLIC src inc)
# target_include_directories(pair PUBLIC . src inc fml)


add_executable(firmware main.cpp src/CallArgsParser.cpp)

target_include_directories(firmware PUBLIC inc)
target_link_libraries(firmware ${LIBS})
target_compile_options(firmware PUBLIC ${CPU_OPTIONS})