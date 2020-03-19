cmake_minimum_required(VERSION 3.1)
project(dz2 C)
enable_language(C CXX)
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -std=c11 -Werror -Wall -Wpedantic -fPIC" )

enable_testing()

include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(MyStaticLib STATIC ${PROJECT_SOURCE_DIR}/src/libCrawlSequintally.c)
add_library(MySharedLib SHARED ${PROJECT_SOURCE_DIR}/src/libCrawlParallel.c)

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.c")

add_executable(dz2 ${sources})
find_package(Threads REQUIRED)
target_link_libraries(dz2 Threads::Threads MyStaticLib MySharedLib)


