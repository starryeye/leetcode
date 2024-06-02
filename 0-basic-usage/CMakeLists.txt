cmake_minimum_required(VERSION 3.28)
project(0-basic-usage)

set(CMAKE_CXX_STANDARD 17)

add_executable(main src/main.cpp)
add_executable(vector_example src/vector_example.cpp)
add_executable(unordered_map_example src/unordered_map_example.cpp)
add_executable(unordered_set_example src/unordered_set_example.cpp)
