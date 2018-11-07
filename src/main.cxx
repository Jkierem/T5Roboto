#define CGAL_USE_BASIC_VIEWER

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Simple_cartesian.h>
#include <iostream>

#include "./FileReader/FileReader.h"
#include "./FileWriter/FileWriter.h"
#include "./MatrixInserter/MatrixInserter.h"
#include "./Traits/ReaderTraits.h"
#include "./Traits/LogicTraits.h"
#include "./Comparator/Comparator.h"
#include "./Types/Types.h"
#include "./Core/Core.h"

typedef CGAL::Exact_predicates_inexact_constructions_kernel Epick;
typedef CGAL::Simple_cartesian< int > Kernel;
typedef Kernel::Point_3 TPoint;

typedef Types< int > TT;
typedef LogicTraits LT;
typedef TT::Matrix TMatrix;
typedef MatrixInserter< int > TMatrixInserter;
typedef ReaderTraits< TMatrix , TMatrixInserter , int > RT;
typedef FileReader< RT > FR;
typedef FileWriter< TMatrix , TT , LT > FW;

int main( int argc, char* argv[] )
{

  if( argc < 3 ) {
    std::cerr << "Usage: " << argv[ 0 ] << " [inFile]" << "[outFile]" << std::endl;
    return( -1 );
  }

  RT::Container* pixels = FR::readFile( argv[ 1 ] );
  Core::getBorders( pixels );
  FW::writeFile( argv[2] , pixels );

  if( pixels == NULL ){
    std::cerr << "Error reading file. Please check input file" << std::endl;
    return( -1 );
  }else{
    std::cout << "Loaded file..." << std::endl;
  }

  return( 0 );
}
