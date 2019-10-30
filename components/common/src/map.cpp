#include <worldbuilder/common/map.hpp>

using namespace WorldBuilder::Common;

Map::Map() {
  terrain_ = std::make_unique<Terrain>(1000, 1e3);
}

Map::~Map() {

}
