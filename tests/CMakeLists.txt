enable_testing()

set(PROJECT_TESTS GEOMETRY_TOOLS_TESTS)

include_directories(${gtest_SOURCE_DIR}/include)

add_executable(${PROJECT_TESTS} UtilsTests.cpp)

target_link_libraries(${PROJECT_TESTS} gtest_main Utils HalfEdgeMesh)

add_test(NAME ${PROJECT_TESTS} COMMAND ${PROJECT_TESTS})