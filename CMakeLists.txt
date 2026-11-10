cmake_minimum_required(VERSION 4.3)

project(main)

set(SRC "src")
set(LIB, "library")

include_directories(include)
include_directories(${PROJECT_SOURCE_DIR})

add_library(ds_static STATIC 
    ${SRC}/set.c 
    ${SRC}/stack.c 
    ${SRC}/linkedlist.c
    ${SRC}/linkedlist.c
    ${SRC}/library/compression.c)

# keep files in order.
add_library(compression STATIC IMPORTED)
add_library(set STATIC IMPORTED)
add_library(stack STATIC IMPORTED)
add_library(linkedlist STATIC IMPORTED)

set_target_properties(stack PROPERTIES IMPORTED_LOCATION 
    "${CMAKE_CURRENT_BINARY_DIR}/libds_static.a")

target_include_directories(ds_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(ds_static PROPERTIES POSITION_INDEPENDENT_CODE ON)

install(TARGETS ds_static ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX})

# 11.04.26
# create a new directory inside of the build directory to house the lib file 
add_custom_command(
    TARGET ds_static POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_CURRENT_BINARY_DIR}/lib" 
    COMMAND ${CMAKE_COMMAND} -E copy 
    "${CMAKE_CURRENT_BINARY_DIR}/libds_static.a"
    "${CMAKE_CURRENT_BINARY_DIR}/lib/libds_static.a"
    COMMENT "Copying static libds_static.a file to build directory.")

# Copy archive file 
# #
add_custom_command (
    TARGET ds_static POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/lib/libds_static.a" "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/home/patrick/Dev/GitProjects/StaticTest/libs/libds_static.a"
    COMMENT "Moving file to archive file..."
)

# Copy the *.h files
# # 
add_custom_command (
    TARGET ds_static POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/include/compression.h" "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/home/patrick/Dev/GitProjects/StaticTest/include/"
    COMMENT "Moving include files...")

# #
# Static Library, an archive file with a .a extension
# Create an Archive File, and use it.
# 10.26.26
# #

# this program create a library or "static library" of datastructures that
# is compiled into build/library the file is libds_static.a and is used in StaticTest program, one level above. StaticTest uses the library and makes 
# function calls using the library's functions: stack, linkedlist, queue...
# Sharedlibrary is in github, but StaticTest isn't. 
# To add the library to another program, add the header files: stack.h,
# linkedlist.h etc. into main's include declaration.
# 
# StaticTest/src/main.c
# #include "stack.h"
# 
# initialize the datastructure and you're in business. 
# example:
# stack_t stack = create_stack();
# stack.data ...
