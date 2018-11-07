#ifndef __FILE_WRITER_H__
#define __FILE_WRITER_H__

#include "../Types/Types.h"
#include "../Traits/LogicTraits.h"

typedef typename Types< int > DefaultTraits;
typedef typename DefaultTraits::Matrix DefaultType;

template<
  typename MatrixContainer=DefaultType ,
  typename MT=DefaultTraits ,
  typename LT=LogicTraits
>
class FileWriter {
public:
  static int writeFile( char* filename , MatrixContainer* info );
};

#include "FileWriter.cxx"

#endif
