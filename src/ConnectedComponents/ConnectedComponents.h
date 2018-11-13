#ifndef __CONNECTED_COMPONENTS_H__
#define __CONNECTED_COMPONENTS_H__

namespace Core {
  template< typename Traits >
  class ConnectedComponents {
  public:
    typedef typename Traits::Matrix Matrix;
    typedef typename Traits::Element Element;
    static Element getRegion( int x , int y , int newRegion , const Matrix& m );
    static Matrix getConnectedRegions( const Matrix& m );
  protected:
    static int validateValue( int value , int limit );
  };
} /* Core */

#include "ConnectedComponents.cxx"

#endif
