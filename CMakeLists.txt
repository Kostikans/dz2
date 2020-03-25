cmake_minimum_required(VERSION 3.1)
project(dz2 C)
enable_language(C CXX)
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -std=c11 -Werror -Wall -Wpedantic -fPIC " )


set(lib_hdrs
        ${PROJECT_SOURCE_DIR}/include/utils.h
        ${PROJECT_SOURCE_DIR}/include/libCrawlSequintally.h
        )

set(lib_srcs
        ${PROJECT_SOURCE_DIR}/src/utils.c
        ${PROJECT_SOURCE_DIR}/src/libCrawlSequintally.c
        )

set( lib_target "MyStaticLib" )

add_library( ${lib_target} STATIC ${lib_srcs} ${lib_hdrs} )

set(lib_hdrs
        ${PROJECT_SOURCE_DIR}/include/utils.h
        ${PROJECT_SOURCE_DIR}/include/libCrawlParallel.h
        )
set(lib_srcs
        ${PROJECT_SOURCE_DIR}/src/utils.c
        ${PROJECT_SOURCE_DIR}/src/libCrawlParallel.c
        )

set( lib_target "MySharedLib" )
add_library( ${lib_target} SHARED ${lib_srcs} ${lib_hdrs} )


add_executable(dz2 src/main.c)
find_package(Threads REQUIRED)
target_link_libraries(dz2 Threads::Threads MyStaticLib MySharedLib)


