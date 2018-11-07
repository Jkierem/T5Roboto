#ifndef __FILE_WRITER_H__
#define __FILE_WRITER_H__

#include "../Types/Types.h"
#include "../Traits/LogicTraits.h"

template<
  typename MatrixContainer ,
  typename MT ,
  typename LT
>
class FileWriter {
public:
  static int writeFile( char* filename , MatrixContainer* info );
};

#include "FileWriter.cxx"

#endif
