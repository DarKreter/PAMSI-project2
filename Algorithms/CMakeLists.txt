set(HEADER_LIST inc/Algorithms.hpp fml/Algorithms.tpp)
set(SRC_LIST src/Algorithms.cpp)


add_library(algorithms ${SRC_LIST} ${HEADER_LIST})

target_include_directories(algorithms PUBLIC . inc fml src)