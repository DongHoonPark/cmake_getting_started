cmake_minimum_required(VERSION 3.10)
project(LIBRARY_LINKING)

set(sources main.cpp)

add_library(lib library/foo.cpp)
target_include_directories(lib PUBLIC library)

add_executable(main ${sources})
target_include_directories(main PUBLIC library)
target_link_libraries(main lib)