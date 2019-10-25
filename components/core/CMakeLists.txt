target_sources( core
  PRIVATE
  src/worldbuilderengine.cpp
  )

target_sources_public( core
  worldbuilder/core/worldbuilderengine.hpp
  )

target_include_directories(core
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
