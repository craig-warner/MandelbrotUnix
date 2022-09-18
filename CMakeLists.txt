cmake_minimum_required(VERSION 3.1...3.16)

# set the project name and version
project(MandelbrotUnix VERSION 1.0)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS "-lm")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

# The compiled library code is here
add_subdirectory(src)

add_executable(MandelbrotUnix
	${PROJECT_SOURCE_DIR}/include/mandel_txt.h
	${PROJECT_SOURCE_DIR}/src/mandel_txt_hrv.c
	${PROJECT_SOURCE_DIR}/src/mandel_txt.c
)

set_source_files_properties(
	${PROJECT_SOURCE_DIR}/src/mandel_txt_hrv.c
	${PROJECT_SOURCE_DIR}/src/mandel_txt.c
	PROPERTIES LANGUAGE "C")

target_include_directories(MandelbrotUnix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
    add_subdirectory(tests)
endif()
