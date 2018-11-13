#ifndef __TYPES_H__
#define __TYPES_H__

#include <CGAL/Polygon_2.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Linear_algebraCd.h>

template< typename FT >
class Traits {
public:

  /*
  * Possible PGM values
  */

  static const FT FREE;
  static const FT PATH;
  static const FT BLOCKED;
  static const FT MARKED;
  static const FT MAX_VALUE;

  /*
  * Return values
  */

  static const FT ERROR;
  static const FT SUCCESS;

  /*
  * CGAL Algebraic Types
  */

  typedef FT Element;
  typedef CGAL::Linear_algebraCd< FT > AlgebraicKernel;
  typedef typename AlgebraicKernel::Vector Vector;
  typedef typename AlgebraicKernel::Matrix Matrix;
  typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
  typedef CGAL::Polygon_2< K > Polygon;
  typedef CGAL::Point_2< K > Point;
  typedef std::vector< Polygon > PolygonContainer;

}; /* Traits */

template< typename FT >
const FT Traits< FT >::FREE = 0;
template< typename FT >
const FT Traits< FT >::PATH = 1;
template< typename FT >
const FT Traits< FT >::BLOCKED = 2;
template< typename FT >
const FT Traits< FT >::MARKED = 3;
template< typename FT >
const FT Traits< FT >::MAX_VALUE = 2;
template< typename FT >
const FT Traits< FT >::ERROR = 4;
template< typename FT >
const FT Traits< FT >::SUCCESS = 5;

#endif
