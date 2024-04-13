cmake_minimum_required(VERSION 3.10)
project(EXAMPLE_COOST)

set(sources main.cpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/coost)

add_executable(main ${sources})

target_include_directories(main PUBLIC coost/include)
target_link_libraries(main co)