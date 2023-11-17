set(TARGET HedraTriangle)

add_executable(${TARGET})

target_link_libraries(${TARGET} Hedra)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "HedraTriangle/*.cc")

target_sources(${TARGET} PRIVATE ${SOURCES})