#include <fstream>
#include <sstream>

template< typename T >
typename Core::FileReader<T>::Response Core::FileReader<T>::readFile( char* filename ){

  std::ifstream inFile;
  inFile.open( filename );
  Response res;

  if( !inFile ) {
    res.state = T::ERROR;
    return res;
  }

  std::stringstream ss;
  std::string inputLine = "";

  std::getline( inFile, inputLine );
  if( inputLine.compare( "P2" ) != 0 ) {
    res.state = T::ERROR;
    return res;
  }

  std::getline( inFile, inputLine );

  int numRows = 0, numColumns = 0, maxValue = 0;
  ss << inFile.rdbuf( );
  ss >> numColumns >> numRows >> maxValue;

  Matrix m( numRows , numColumns );
  for( unsigned int i = 0; i < m.row_dimension( ) ; i++ ) {
    for( unsigned int j = 0; j < m.column_dimension( ) ; j++ ) {
      unsigned int value = 0;
      Element e;
      ss >> value;
      if( value == 0 ){
        e = T::FREE ;
      }else{
        e = T::BLOCKED ;
      }
      m( i , j ) = e;
    }
  }

  inFile.close( );

  res.state = T::SUCCESS;
  res.value = m;
  return res;
}
