#include <worldbuilder/common/terrain.hpp>
#include <iostream>
#include <istream>
#include <Mathematics/Math.h>
#include <Mathematics/BSNumber.h>
#include <Mathematics/UIntegerFP32.h>
#include <Mathematics/ConvexHull3.h>
#include <cmath> 

using namespace WorldBuilder::Common;

Terrain::Terrain(float raduis, int resolution) :
  radius( radius ), resolution(resolution)
{
}

Terrain::~Terrain() {

}

void Terrain::Generate() {

  std::vector<gte::Vector3<float> > pvec;
  
  for( std::size_t i = 0; i < resolution; ++i ){
    pvec.push_back( GetSamplePoint(i, resolution) );
  }

  gte::ConvexHull3<float,gte::BSNumber<gte::UIntegerFP32<27> > > hull_gen;
  bool success = hull_gen(pvec.size(), pvec.data(), 1e-6);

  gte::ETManifoldMesh hull =  hull_gen.GetHullMesh();

  for( std::size_t i = 0; i < resolution; ++i ){
    TerrainPoint tp;
    tp.x = pvec[i];
    points.push_back( tp );
  }

  Plate plate;
  plate.centroid = gte::Vector3<float>();
  plate.rotation_axis = gte::Vector3<float>({1,0,0});
  plate.rotation_speed = 1e-4;
  plate.mesh = hull;
}

constexpr double GoldenRatio() {
  return (std::sqrt(5.0)+1)/2.0;
}

constexpr double GoldenRatioInv() {
  return GoldenRatio() - 1.0;
}

constexpr float FibTheta( int i, int n ){
  double throwaway=0;
  return GTE_C_TWO_PI  * std::modf((double)i * GoldenRatioInv(), &throwaway);
}

constexpr float FibZetta( int i, int n ){
  return 1.0 - (2.0*(double)(i) - 1.0)/(double)(n);
}

gte::Vector3<float> PointFromAngles( float theta, float zetta ) {
  return gte::Vector3<float>(
    {
      std::cos(theta)*std::sin(std::acos(zetta)),
      std::sin(theta)*std::sin(std::acos(zetta)),
      std::cos(std::acos(zetta))
    });
}

gte::Vector3<float>
Terrain::GetSamplePoint(int i, int n){
  return PointFromAngles( FibTheta(i,n), FibZetta(i, n) );
}
