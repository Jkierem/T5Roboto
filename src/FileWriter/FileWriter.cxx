#include <ofstream>

template< typename Matrix , typename MT , typename LT >
int FileWriter< Matrix >::writeFile( char* filename , Matrix* info ){
  ofstream outFile;
  outFile.open( filename );
  if( !outFile ){
    return typename LT::ERROR;
  }

  int height = info->size( );
  int width = (*info)[0].size( );
  int maxValue = typename LT::BLOCKED;

  outFile << "P2" << "\n"
  << "# Author Juan Gomez" << "\n"
  << width << " " << height << "\n"
  << maxValue << "\n";

  for( int row = 0 ; row < height ; row++ ){
    for( int col = 0 ; col < width ; col++ ){
      typename MT::Element value = (*info)[row][col];
      outFile << value << " ";
    }
    outFile << "\n";
  }

  return typename LT::SUCCESS;
}
