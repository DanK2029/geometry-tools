add_library(
	Meshes
	HalfEdgeMesh.h
	HalfEdgeMesh.cpp
)

target_include_directories(
	Meshes
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)