#ifndef __CORE_H__
#define __CORE_H__

namespace Core {
  template< typename Traits >
  bool isBorder( int i , int j , const typename Traits::Matrix& m );
  template< typename Traits >
  typename Traits::Matrix getBorders( typename Traits::Matrix& matrix );
} /* Core */

#include "Core.cxx"

#endif
