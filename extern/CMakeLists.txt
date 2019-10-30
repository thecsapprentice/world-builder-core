cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

include(FetchContent)

#---------------------------------------
# External repository holding dependencies for this library
FetchContent_Declare(
  extern_world-builder-dependencies

  GIT_REPOSITORY https://github.com/thecsapprentice/world-builder-dependencies
  GIT_TAG        origin/master
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
  )

FetchContent_MakeAvailable( extern_world-builder-dependencies )

#---------------------------------------
# Testing framework

FetchContent_Declare(
  extern-googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.8.0
)

FetchContent_GetProperties(extern-googletest)
if(NOT extern-googletest_POPULATED)
  FetchContent_Populate(extern-googletest)
  add_subdirectory(${extern-googletest_SOURCE_DIR} ${extern-googletest_BINARY_DIR})
endif()
