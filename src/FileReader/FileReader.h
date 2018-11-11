#ifndef __FILE_READER_H__
#define __FILE_READER_H__

namespace Core {

  template< typename T , typename S >
  struct Response {
    S state;
    T value;
  };

  template< typename Traits >
  class FileReader {
  public:
    typedef typename Traits::Matrix Matrix;
    typedef typename Traits::Element Element;
    typedef typename Core::Response< Matrix , Element > Response;
    static Response readFile( char* filename );
  };
} /* Core */

#include "./FileReader.cxx"

#endif
