#define CGAL_USE_BASIC_VIEWER
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::Point TPoint;

std::vector< TPoint >* readFile( char* filename , bool debug ){

  std::vector< TPoint >* pixels;

  std::ifstream inFile;
  inFile.open( filename );

  if( !inFile ) {
    return pixels;
  }

  std::stringstream ss;
  std::string inputLine = "";

  std::getline( inFile, inputLine );
  if( inputLine.compare( "P2" ) != 0 ) {
    std::cerr << "Error de version" << std::endl;
    return pixels;
  }

  std::getline( inFile, inputLine );

  int numRows = 0, numColumns = 0;
  ss << inFile.rdbuf( );
  ss >> numColumns >> numRows;

  int FREE = 0;
  int BLOCKED = 1;

  pixels = new std::vector< TPoint >();

  for( unsigned int i = 0; i < numRows; i++ ) {
    for( unsigned int j = 0; j < numColumns; j++ ) {
      unsigned int value = 0;
      ss >> value;
      pixels->push_back( TPoint( i , j , value ) );
    }
  }

  inFile.close( );
  return pixels;
}

int main( int argc, char* argv[] )
{

  if( argc < 2 ) {
    std::cerr << "Usage: " << argv[ 0 ] << " [file]" << std::endl;
    return( -1 );
  }

  std::vector< TPoint >* pixels = readFile( argv[ 1 ] , true );

  if( pixels == NULL ){
    std::cerr << "Error reading file. Please check input file" << std::endl;
    return( -1 );
  }else{
    std::cout << "Loaded file..." << std::endl;
  }

  return( 0 );
}
