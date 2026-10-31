cmake_minimum_required(VERSION 4.3)

project(main)

set(SRC "src")

include_directories(include)
include_directories(${PROJECT_SOURCE_DIR})

add_library(stack_static STATIC ${SRC}/stack.c)
add_library(stack STATIC IMPORTED)

set_target_properties(stack PROPERTIES IMPORTED_LOCATION 
    "${CMAKE_CURRENT_SOURCE_DIR}/build/libstack_static.a")

target_include_directories(stack_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(stack_static PROPERTIES POSITION_INDEPENDENT_CODE ON)

# #
# Static Library, an archive file with a .a extension
# Create an Archive File, and use it.
# 10.26.26
# #
