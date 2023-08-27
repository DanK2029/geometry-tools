add_library(
	HalfEdgeMesh
	HalfEdgeMesh.h
	HalfEdgeMesh.cpp
)

target_include_directories(
	HalfEdgeMesh
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)