#ifndef __FILE_READER_H__
#define __FILE_READER_H__

template< typename Traits >
class FileReader {
public:
  typedef typename Traits::Container Container;
  static Container* readFile( char* filename );
};

#include "./FileReader.cxx"

#endif
