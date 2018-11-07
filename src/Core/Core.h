#ifndef __CORE_H__
#define __CORE_H__

#include "../Traits/LogicTraits.h"

namespace Core {
  template< typename Matrix , typename CoreTraits=LogicTraits >
  bool isBorder( int row , int col , Matrix* m );
  template< typename Matrix , typename CoreTraits=LogicTraits >
  void getBorders( Matrix* matrix );
  template< typename PolygonTraits , typename PointTraits , typename Matrix >
  typename PolygonTraits::Container getPolygons( typename PointTraits::Container borders );
} /* Core */

#include "Core.cxx"

#endif
