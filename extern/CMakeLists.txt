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

