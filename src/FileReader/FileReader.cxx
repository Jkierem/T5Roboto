#include <fstream>
#include <sstream>

template< typename T >
typename T::Container* FileReader<T>::readFile( char* filename ){

  typedef typename T::Container Container;
  typedef typename T::Element Element;
  typedef typename T::Inserter Inserter;
  Container* pixels;

  std::ifstream inFile;
  inFile.open( filename );

  if( !inFile ) {
    return pixels;
  }

  std::stringstream ss;
  std::string inputLine = "";

  std::getline( inFile, inputLine );
  if( inputLine.compare( "P2" ) != 0 ) {
    return pixels;
  }

  pixels = new Container( );
  Inserter inserter( pixels );

  std::getline( inFile, inputLine );

  int numRows = 0, numColumns = 0, maxValue = 0;
  ss << inFile.rdbuf( );
  ss >> numColumns >> numRows >> maxValue;

  for( unsigned int i = 0; i < numRows; i++ ) {
    for( unsigned int j = 0; j < numColumns; j++ ) {
      unsigned int value = 0;
      Element e;
      ss >> value;
      if( value == 0 ){
        e = T::FREE ;
      }else{
        e = T::BLOCKED ;
      }
      inserter.insert( i , j , e );
    }
  }

  inFile.close( );

  return pixels;
}
