#define CGAL_USE_BASIC_VIEWER

#include <iostream>
#include <vector>

#include "./Traits/Traits.h"
#include "./Bresenham/Bresenham.h"
#include "./FileReader/FileReader.h"
#include "./FileWriter/FileWriter.h"
#include "./BorderDetection/BorderDetection.h"
#include "./Voronoi/Voronoi.h"
#include "./ConnectedComponents/ConnectedComponents.h"

typedef Traits< int > TT;
typedef Core::FileReader< TT > FR;
typedef Core::FileWriter< TT > FW;
typedef Core::Voronoi< TT > VD;
typedef typename VD::Site_2 Site_2;
typedef typename VD::SiteVector SiteVector;

typedef Core::ConnectedComponents< TT > CC;

int main( int argc, char* argv[] )
{

  if( argc < 3 ) {
    std::cerr << "Usage: " << argv[ 0 ] << " [inFile] [outFile]" << std::endl;
    return( -1 );
  }

  FR::Response res = FR::readFile( argv[ 1 ] );

  if( res.state == TT::ERROR ){
    std::cerr << "Error reading file" << std::endl;
    return( -1 );
  }

  TT::Matrix m = res.value;
  TT::Matrix borders = Core::getBorders< TT >( m );

  SiteVector points = VD::getSitesFromMatrix( borders );
  VD::VoronoiDiagram v = VD::getVoronoiFromSites( points );
  TT::Matrix regions = CC::getConnectedRegions( borders );
  TT::PolygonContainer ps = CC::createPolygonsFromRegions( regions );
  FW::writeFile( argv[ 2 ] , regions );
  std::cout << "Ended excecution" << std::endl;

  return( 0 );
}
