set(TARGET Hedra)

add_library(${TARGET})

set_target_properties(
	${TARGET}
	PROPERTIES
		CXX_STANDARD 23)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cc" "*.hh")

target_sources(${TARGET} PRIVATE ${SOURCES})

target_link_libraries(${TARGET} PRIVATE DirectXMath)

target_include_directories(${TARGET} PRIVATE ${PROJECT_SOURCE_DIR}/lib/simde)
target_include_directories(${TARGET} PUBLIC .)

target_compile_definitions(${TARGET} PRIVATE LIBHEDRA)