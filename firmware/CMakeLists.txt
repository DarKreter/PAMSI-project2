add_executable(firmware src/main.cpp src/CallArgsParser.cpp)

target_include_directories(firmware PUBLIC . inc src)

target_link_libraries(firmware PUBLIC algorithms)
target_link_libraries(firmware PUBLIC movie)

add_dependencies(firmware algorithms)
add_dependencies(firmware movie)
