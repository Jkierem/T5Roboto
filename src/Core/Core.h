#ifndef __CORE_H__
#define __CORE_H__

#include "../Types/Types.h"

namespace Core {
  template< typename Matrix , typename CoreTraits >
  bool isBorder( int row , int col , Matrix* m );
  template< typename Matrix , typename CoreTraits >
  void getBorders( Matrix* matrix );
  template< typename PolygonTraits , typename PointTraits , typename Matrix >
  typename PolygonTraits::Container getPolygons( typename PointTraits::Container borders );
} /* Core */

#include "Core.cxx"

#endif
