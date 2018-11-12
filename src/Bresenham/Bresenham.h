#ifndef __BRESENHAM_H__
#define __BRESENHAM_H__

#include <vector>

namespace Core {

  class IntPair {
    protected:
      int m_x;
      int m_y;
    public:
      IntPair( int x , int y );
      virtual ~IntPair();
      int x();
      int y();
  };
  
  typedef std::vector< IntPair > Line;

  Line calculateLine( int x0 , int y0 , int x1 , int y1 );
  Line calculateOverX( int x0 , int y0 , int x1 , int y1 );
  Line calculateOverY( int x0 , int y0 , int x1 , int y1 );

  template< typename Traits >
  void plotOverMatrix( typename Traits::Matrix& m , Line line );
} /* Core */

#include "Bresenham.cxx"

#endif
