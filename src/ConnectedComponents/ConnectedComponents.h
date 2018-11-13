#ifndef __CONNECTED_COMPONENTS_H__
#define __CONNECTED_COMPONENTS_H__

#include <set>

namespace Core {
  template< typename Traits >
  class ConnectedComponents {
  public:
    typedef typename Traits::Polygon Polygon;
    typedef typename Traits::PolygonContainer PolygonContainer;
    typedef typename Traits::Matrix Matrix;
    typedef typename Traits::Element Element;
    static int getRegion( int x , int y , int newRegion , const Matrix& m );
    static Matrix getConnectedRegions( const Matrix& m );
    static PolygonContainer createPolygonsFromRegions( const Matrix& m );
  protected:
    static int validateValue( int x , int dx , int limit );
  };
} /* Core */

#include "ConnectedComponents.cxx"

#endif
