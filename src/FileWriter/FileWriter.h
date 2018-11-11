#ifndef __FILE_WRITER_H__
#define __FILE_WRITER_H__

namespace Core {
  template< typename Traits >
  class FileWriter {
  public:
    static int writeFile( char* filename , const typename Traits::Matrix& info );
  };
} /* Core */

#include "FileWriter.cxx"

#endif
