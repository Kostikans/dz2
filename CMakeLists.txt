cmake_minimum_required(VERSION 3.1)
project(dz2 C)
enable_language(C CXX)
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -std=c11 -Werror -Wall -Wpedantic -fPIC " )


set(lib_static_hdrs
        ${PROJECT_SOURCE_DIR}/include/utils.h
        ${PROJECT_SOURCE_DIR}/include/libCrawlSequintally.h
        )

set(lib_static_srcs
        ${PROJECT_SOURCE_DIR}/src/utils.c
        ${PROJECT_SOURCE_DIR}/src/libCrawlSequintally.c
        )


add_library( MyStaticLib STATIC ${lib_static_srcs} ${lib_static_hdrs} )
find_package(Threads REQUIRED)
target_link_libraries(MyStaticLib Threads::Threads)

set(lib_shared_hdrs
        ${PROJECT_SOURCE_DIR}/include/utils.h
        ${PROJECT_SOURCE_DIR}/include/libCrawlParallel.h
        )
set(lib_shared_srcs
        ${PROJECT_SOURCE_DIR}/src/utils.c
        ${PROJECT_SOURCE_DIR}/src/libCrawlParallel.c
        )

add_library( MySharedLib SHARED ${lib_shared_srcs} ${lib_shared_hdrs} )
target_link_libraries(MySharedLib Threads::Threads)


add_executable(dz2 src/main.c)
target_link_libraries(dz2  MyStaticLib MySharedLib)


