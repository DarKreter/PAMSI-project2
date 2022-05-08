set(HEADER_LIST inc/Movie.hpp)
set(SRC_LIST src/Movie.cpp)


add_library(movie ${SRC_LIST} ${HEADER_LIST})

target_include_directories(movie PUBLIC . inc fml src)

target_link_libraries(movie PUBLIC algorithms)
add_dependencies(movie algorithms)