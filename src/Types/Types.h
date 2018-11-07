#ifndef __TYPES_H__
#define __TYPES_H__

#include <map>

template< typename TElement >
class Types {
public:
  typedef std::map< int , TElement > Column;
  typedef std::map< int , Column > Matrix;
}; /* MatrixType */

#endif
