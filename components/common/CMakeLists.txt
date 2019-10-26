target_sources( common
  PRIVATE
  src/terrain.cpp
  src/map.cpp
  )

target_sources_public( common
  include/worldbuilder/common/map.hpp
  include/worldbuilder/common/terrain.hpp
  )

target_include_directories(common
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
	)

target_link_libraries( common
  PUBLIC
  GeometricTools::Mathematics
  )

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
