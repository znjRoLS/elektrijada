cmake_minimum_required(VERSION 3.3)
project(test_build)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


file( GLOB_RECURSE APP_SOURCES *.cpp )
foreach( testsourcefile ${APP_SOURCES} )
    # I used a simple string replace, to cut off .cpp.
    string( REPLACE ".cpp" "" testname ${testsourcefile} )
    get_filename_component( testname_dir_strip ${testname} DIRECTORY)
    get_filename_component( testname_lastdir_strip ${testname_dir_strip} NAME)
    get_filename_component( testname_strip ${testname} NAME )
    get_filename_component( testsourcefile_strip ${testsourcefile} NAME )
    add_executable( ${BIN_PREFIX}oop-${testname_lastdir_strip}-${testname_strip} ${testname_dir_strip}/${testsourcefile_strip} )
    # Make sure YourLib is linked to each app
    # target_link_libraries( ${testname} YourLib )
endforeach( testsourcefile ${APP_SOURCES} )

file( GLOB_RECURSE APP_SOURCES *.c )
foreach( testsourcefile ${APP_SOURCES} )
    # I used a simple string replace, to cut off .cpp.
    string( REPLACE ".c" "" testname ${testsourcefile} )
    get_filename_component( testname_dir_strip ${testname} DIRECTORY)
    get_filename_component( testname_lastdir_strip ${testname_dir_strip} NAME)
    get_filename_component( testname_strip ${testname} NAME )
    get_filename_component( testsourcefile_strip ${testsourcefile} NAME )
    add_executable( ${BIN_PREFIX}inf-${testname_lastdir_strip}-${testname_strip} ${testname_dir_strip}/${testsourcefile_strip} )
    # Make sure YourLib is linked to each app
    # target_link_libraries( ${testname} YourLib )
endforeach( testsourcefile ${APP_SOURCES} )

#set(BUILD_1 inf_2016_1)
#set(SOURCE_FILES_1 inf/2016/1.c)
#add_executable(${BUILD_1} ${SOURCE_FILES_1})
#
#set(BUILD_2 inf_2012)
#file(GLOB SOURCE_FILES_2 inf/2012/*.c)
#add_executable(${BUILD_2} ${SOURCE_FILES_2})