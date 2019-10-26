cmake_minimum_required(VERSION 3.15)
project(world-builder-core VERSION 1.0.0 LANGUAGES CXX)
include(GNUInstallDirs)

function(target_sources_public target)
  # Must be using CMake 3.12 or earlier, so simulate the new behavior
  unset(_srcList)
  foreach(src ${ARGN})
    list(APPEND _srcList "$<BUILD_INTERFACE:include/${src}>")
    list(APPEND _srcList "$<INSTALL_INTERFACE:include/${src}>")
  endforeach()
  target_sources(${target} PUBLIC ${_srcList})
endfunction()

add_subdirectory(extern)

add_library(core "")
add_library(WorldBuilderCore::Core ALIAS core)
add_subdirectory(components/core)

install(TARGETS core
    EXPORT core-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
  
install(EXPORT core-targets
  FILE
    coreTargets.cmake
  NAMESPACE
    WorldBuilderCore::
  DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/WorldBuilderCore
    )


add_library(common "")
add_library(WorldBuilderCore::Common ALIAS common)
add_subdirectory(components/common)

install(TARGETS common
    EXPORT common-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
  
install(EXPORT common-targets
  FILE
    commonTargets.cmake
  NAMESPACE
    WorldBuilderCore::
  DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/WorldBuilderCore
    )
