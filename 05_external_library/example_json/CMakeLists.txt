cmake_minimum_required(VERSION 3.10)
project(example_json)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/json)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)