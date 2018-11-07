#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

template< typename Matrix , typename MT , typename LT >
int FileWriter< Matrix , MT , LT >::writeFile( char* filename , Matrix* info ){
  std::stringstream ss;
  std::ofstream outFile;
  outFile.open( filename );

  int height = info->size( );
  int width = (*info)[0].size( );
  int maxValue = LT::BLOCKED;

  ss << "P2" << "\n"
  << "# Author Juan Gomez" << "\n"
  << width << " " << height << "\n"
  << maxValue << "\n";
  
  
  typedef typename MT::Row_Iterator RowIt;
  typedef typename MT::Column_Iterator ColIt;
  RowIt rowIt = info->begin( );
  for( ; rowIt != info->end( ) ; rowIt++ ){
    ColIt colIt = rowIt->second.begin( );
    for( ; colIt != rowIt->second.end( ) ; colIt++ ){
      ss << std::to_string( colIt->second ) << " " ;
    }
    ss << "\n";
  }
  
  outFile << ss.rdbuf( );
  
  outFile.close( );

  return LT::SUCCESS;
}
