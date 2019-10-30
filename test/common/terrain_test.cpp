// This is a blank test...

#include <worldbuilder/common/terrain.hpp>
#include "gtest/gtest.h"

using namespace WorldBuilder::Common;

namespace {
  class TerrainTest : public testing::Test {
  protected:
    void SetUp() override {
    }
    
    void TearDown() override {
    }
    
  };
  
  TEST_F(TerrainTest, DefaultConstructor) {
    Terrain terrain;
  }

  TEST_F(TerrainTest, ParameterizedConstructor) {
    Terrain terrain(1000, 1e3);
  }

  TEST_F(TerrainTest, Generate) {
    Terrain terrain(100, 1e3);
    terrain.Generate();
    EXPECT_EQ( terrain.NumPoints() , 1e3 );
  }

  

}  // namespace
