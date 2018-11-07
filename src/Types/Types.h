#ifndef __TYPES_H__
#define __TYPES_H__

#include <map>

template< typename TElement >
class Types {
public:
  typedef TElement Element;
  typedef std::map< int , TElement > Column;
  typedef std::map< int , Column > Matrix;
  typedef typename Column::iterator Column_Iterator;
  typedef typename Matrix::iterator Row_Iterator;
}; /* MatrixType */

#endif
