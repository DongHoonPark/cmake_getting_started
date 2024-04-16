cmake_minimum_required(VERSION 3.10)
project(example_json)

include(FetchContent)

set(JSON_BuildTests OFF CACHE INTERNAL "")
FetchContent_Declare(
        json
        GIT_REPOSITORY "https://github.com/nlohmann/json"
        GIT_TAG "8c391e04fe4195d8be862c97f38cfe10e2a3472e"
)
FetchContent_MakeAvailable(json)


add_executable(main main.cpp)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)