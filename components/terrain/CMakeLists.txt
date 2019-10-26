target_sources( terrain
  PRIVATE
  src/terrain.cpp
  )

target_sources_public( core
  include/worldbuilder/core/worldbuilderengine.hpp
  )

target_include_directories(core
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
	)

target_link_libraries( core
  PUBLIC
  GeometricTools::Mathematics
  )

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
