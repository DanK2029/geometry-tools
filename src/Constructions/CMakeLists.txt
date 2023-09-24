set(HEADERS Point.h Vector.h Plane.h Line.h LineSegment.h)
set(SOURCES Point.cpp Vector.cpp Plane.cpp Line.h LineSegment.h)

add_library(
	Constructions
	${HEADERS}
	${SOURCES}
)

set_target_properties(Constructions PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(
	Constructions
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)
