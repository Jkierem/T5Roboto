#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

template< typename Traits >
int Core::FileWriter< Traits >::writeFile( char* filename , const typename Traits::Matrix& info ){
  std::stringstream ss;
  std::ofstream outFile(  filename , std::ios::out);

  if ( !outFile.is_open() ) {
    return Traits::ERROR;
  }

  int width = info.column_dimension( );
  int height = info.row_dimension( );
  int maxValue = Traits::MAX_VALUE;

  outFile << "P2" << "\n"
  << "# Author Juan Gomez" << "\n"
  << width << " " << height << "\n"
  << maxValue << "\n";

  for (size_t row = 0; row < info.row_dimension( ) ; row++) {
    for (size_t col = 0; col < info.column_dimension( ) ; col++) {
      typename Traits::Element value = info( row , col );
      outFile << value << " ";
    }
    outFile << "\n";
  }

  outFile.flush( );
  outFile.close( );

  return Traits::SUCCESS;
}
