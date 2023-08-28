cmake_minimum_required(VERSION 3.1.0)

project(GEOMETRY_TOOLS)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(third_party/googletest)
add_subdirectory(src)
add_subdirectory(tests)

include_directories(${gtest_SOURCE_DIR}/incldue)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} HalfEdgeMesh Utils)