cmake_minimum_required(VERSION 4.3)

project(main)

set(SRC "src")

include_directories(include)
include_directories(${PROJECT_SOURCE_DIR})

add_library(ds_static STATIC 
    ${SRC}/set.c 
    ${SRC}/stack.c 
    ${SRC}/linkedlist.c)

add_library(set STATIC IMPORTED)
add_library(stack STATIC IMPORTED)
add_library(linkedlist STATIC IMPORTED)

set_target_properties(stack PROPERTIES IMPORTED_LOCATION 
    "${CMAKE_CURRENT_SOURCE_DIR}/build/libds_static.a")

target_include_directories(ds_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(ds_static PROPERTIES POSITION_INDEPENDENT_CODE ON)

install(TARGETS ds_static ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX})

# #
# Static Library, an archive file with a .a extension
# Create an Archive File, and use it.
# 10.26.26
# #
