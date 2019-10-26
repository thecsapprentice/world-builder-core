#ifndef WORLDBUILDER_COMMON_MAP_HPP
#define WORLDBUILDER_COMMON_MAP_HPP

#include <worldbuilder/common/terrain.hpp>

#include <memory>

namespace WorldBuilder {
  namespace Common {

    class Map {
    public:
      Map();
      ~Map();

      Terrain& GetTerrain() {
	return *terrain_;
      }

      const Terrain& GetTerrain() const {
	return *terrain_;
      }
      
    private:
      std::unique_ptr<Terrain> terrain_;
    };

    
  }
}

#endif
