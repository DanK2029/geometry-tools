cmake_minimum_required(VERSION 3.1.0)

project(GEOMETRY_TOOLS)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_subdirectory(src)
add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} HalfEdgeMesh)