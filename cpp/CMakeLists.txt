CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

##################################################################
# BUILD FILES OUTPUT LOCATION
##################################################################
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/static_libs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/shared_libs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)

##################################################################
# OPERATIONAL SYSTEMS CONFIGURATION
##################################################################
if(UNIX)
    set(CMAKE_C_COMPILER gcc)
    set(CMAKE_CXX_COMPILER g++)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-m64 -std=c++17 -Wall -Wextra -Wnon-virtual-dtor -pedantic -Wno-parentheses" CACHE STRING "Default compiler flags")

    if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE "Release")
    endif()
    string(TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE)

    if(BUILD_SHARED_LIBS)
        set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fPIC" CACHE STRING "Necessary for shared libraries")
        set(LIBRARY_TYPE "shared")
    else()
        set(LIBRARY_TYPE "static")
    endif()

    set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG} "-g -DDEBUG" CACHE STRING "Debug compiler flags")
    set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE} "-O3 -DNDEBUG" CACHE STRING "Release compiler flags")
else()
    message(FATAL_ERROR "CMAKE HAS NOT BEEN CONFIGURED FOR THE CURRENT OPERATIONAL SYSTEM.\n")
endif()

add_definitions("-DTEST_INPUT_DIRECTORY=\"${CMAKE_SOURCE_DIR}/Zeta/Test/\"")
add_definitions("-DSCRIPT_DIRECTORY=\"${CMAKE_SOURCE_DIR}/Zeta/\"")

##################################################################
# ABOUT THE PROJECT
##################################################################
project(DTU_Test)
set(VERSION_MAJOR "0")
set(VERSION_MINOR "1")
set(VERSION_PATCH "0")
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

##################################################################
# EXTERNAL LIBRARIES
##################################################################
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

##############
# BOOST
##############
set(BOOST_VERSION "1.67.0")
set(BOOST_ROOT "/usr/include")
set(Components_Boost system filesystem unit_test_framework test_exec_monitor)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS ${Components_Boost} REQUIRED)
if(Boost_FOUND)
    include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
endif()

##################################################################
# MACROS
##################################################################
macro(add_executable _target)
    _add_executable(${_target} ${ARGN})
    target_link_libraries(${_target} ${Boost_LIBRARIES})
endmacro()

macro(add_library _target)
    _add_library(${_target} ${ARGN})
    target_link_libraries(${_target} ${Boost_LIBRARIES})
    set_target_properties(${_target}  PROPERTIES PREFIX "")
    set_target_properties(${_target}  PROPERTIES VERSION ${VERSION})
endmacro()

##################################################################
# COMPONENTS
##################################################################
add_subdirectory(problem1)
add_subdirectory(problem2)

##################################################################
# DISPLAY INFORMATION
##################################################################
message("\n")
message(STATUS "Project: ${PROJECT_NAME} ${VERSION}")
message(STATUS "Build type: ${BUILD_TYPE}")
message(STATUS "Library type: ${LIBRARY_TYPE}")

message("\n")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Compile flags: ${CMAKE_CXX_FLAGS}")
message(STATUS "Debug flags: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "Release flags: ${CMAKE_CXX_FLAGS_RELEASE}")

message("\n")
message(STATUS "Install prefix: ${CMAKE_INSTALL_PREFIX}")
