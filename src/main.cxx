#define CGAL_USE_BASIC_VIEWER

#include <iostream>

#include "./Traits/Traits.h"
#include "./Bresenham/Bresenham.h"
#include "./FileReader/FileReader.h"
#include "./FileWriter/FileWriter.h"
#include "./BorderDetection/BorderDetection.h"


typedef Traits< int > TT;
typedef Core::FileReader< TT > FR;
typedef Core::FileWriter< TT > FW;

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
  Core::getBorders< TT >( m );

  Core::Line line = Core::calculateLine( 0 , 0 , 100 , 5);
  Core::plotOverMatrix< TT >( m , line );
  FW::writeFile( argv[ 2 ] , m );

  std::cout << "Ended excecution" << std::endl;

  return( 0 );
}
