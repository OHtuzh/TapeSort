cmake_minimum_required(VERSION 3.23)
project(TapeSort)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(lib)
add_subdirectory(OMFL-parser/lib)

add_executable(TapeSort main.cpp)

target_link_libraries(
        TapeSort
        PRIVATE
        tape-sort
        ITMLparse
)
