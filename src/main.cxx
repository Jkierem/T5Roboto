#define CGAL_USE_BASIC_VIEWER

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Simple_cartesian.h>
#include <iostream>

#include "./FileReader/FileReader.h"
#include "./MatrixInserter/MatrixInserter.h"
#include "./Traits/ReaderTraits.h"
#include "./Comparator/Comparator.h"
#include "./Types/Types.h"

typedef CGAL::Exact_predicates_inexact_constructions_kernel Epick;
typedef CGAL::Simple_cartesian< int > Kernel;
typedef Kernel::Point_3 TPoint;

typedef Types< int > TT;
typedef TT::Matrix TMatrix;
typedef MatrixInserter< int > TMatrixInserter;
typedef ReaderTraits< TMatrix , TMatrixInserter , int > RT;
typedef FileReader< RT > FR;

int main( int argc, char* argv[] )
{

  if( argc < 2 ) {
    std::cerr << "Usage: " << argv[ 0 ] << " [file]" << std::endl;
    return( -1 );
  }

  RT::Container* pixels = FR::readFile( argv[ 1 ] );
  

  if( pixels == NULL ){
    std::cerr << "Error reading file. Please check input file" << std::endl;
    return( -1 );
  }else{
    std::cout << "Loaded file..." << std::endl;
  }

  return( 0 );
}
