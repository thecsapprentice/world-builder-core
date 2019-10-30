#ifndef WORLDBUILDER_COMMON_TERRAIN_HPP
#define WORLDBUILDER_COMMON_TERRAIN_HPP

#include <Mathematics/Vector3.h>
#include <Mathematics/ETManifoldMesh.h>
#include <vector>

namespace WorldBuilder {
  namespace Common {

    struct TerrainParameters {
      enum CrustType { Oceanic=0, Continental=1 };
      enum OrogenyType { Andean=0, Himalayan=1 };
      CrustType crust_type;
      float crust_thickness;
      float relief_elevation;
      float crust_age;
      gte::Vector3<float> local_ridge_direction;
      float orogeny_age;
      OrogenyType orogeny_type;
      gte::Vector3<float> local_fold_direction;
    };

      
    struct TerrainPoint {
      gte::Vector3<float> x;
      TerrainParameters params;
    };
    
    struct Plate{
      gte::Vector3<float> centroid;
      gte::Vector3<float> rotation_axis;
      float rotation_speed;
      gte::ETManifoldMesh mesh;
    };
    
    class Terrain {
    public:
      Terrain();
      Terrain(float radius, int resolution);
      ~Terrain();

      void Generate();

      std::size_t NumPlates() const { return plates.size(); }
      std::size_t NumPoints() const { return points.size(); }

      Plate& GetPlate(const std::size_t& idx) { return plates[idx]; }
      const Plate& GetPlate(const std::size_t& idx) const { return plates[idx]; }

      TerrainPoint& GetPoint(const std::size_t& idx) { return points[idx]; }
      const TerrainPoint& GetPoint(const std::size_t& idx) const { return points[idx]; }

      
    private:

      gte::Vector3<float> GetSamplePoint(int i, int n);

      float radius;
      int resolution;
      std::vector<TerrainPoint> points;
      std::vector<Plate> plates;
	
    };
  }
}


#endif
