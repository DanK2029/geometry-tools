enable_testing()

set(PROJECT_TESTS geometry_tools_tests)

include_directories(${gtest_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

set(TEST_FILES UtilsTests.cpp HalfEdgeMeshTests.cpp PointTests.cpp VectorTests.cpp PlaneTests.cpp)
set(LIBRARIES gtest_main Utils Meshes Constructions)

add_executable(${PROJECT_TESTS} ${TEST_FILES})

target_link_libraries(${PROJECT_TESTS} ${LIBRARIES})

add_test(NAME ${PROJECT_TESTS} COMMAND ${PROJECT_TESTS})