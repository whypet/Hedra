cmake_minimum_required(VERSION 3.26)
project(Hedra LANGUAGES CXX)

option(BUILD_SAMPLES "Builds Hedra samples" ON)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

if(MSVC)
	set(CMAKE_CXX_FLAGS "/EHsc /W4")
	set(CMAKE_CXX_FLAGS_DEBUG "/Zi /DEBUG")
	set(CMAKE_CXX_FLAGS_RELEASE "/O2")
else()
	set(CMAKE_CXX_FLAGS "-Wall -Wextra")
	set(CMAKE_CXX_FLAGS_DEBUG "-g")
	set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()

include(lib/cmake/OptimizeForArchitecture.cmake)

OptimizeForArchitecture()

foreach(flag ${Vc_ARCHITECTURE_FLAGS})
	if(NOT ${flag} IN_LIST COMPILE_OPTIONS)
		add_compile_options(${flag})
	endif()
endforeach()

# Third party
add_subdirectory(lib/DirectXMath)

add_subdirectory(src "Hedra")