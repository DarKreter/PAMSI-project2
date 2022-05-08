add_executable(FilterData filterData.cpp)

target_link_libraries(FilterData algorithms movie)

add_dependencies(FilterData algorithms)
add_dependencies(FilterData movie)