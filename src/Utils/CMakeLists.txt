add_library(
	Utils
	StringUtils.h
	StringUtils.cpp
)

set_target_properties(Utils PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(
	Utils
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)
