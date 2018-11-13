#ifndef __VORONOI_H__
#define __VORONOI_H__

#include <vector>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Voronoi_diagram_2.h>
#include <CGAL/Delaunay_triangulation_adaptation_traits_2.h>
#include <CGAL/Delaunay_triangulation_adaptation_policies_2.h>

namespace Core {
  template< typename Traits >
  class Voronoi{
  public:

    /*
    * CGAL Voronoi Definitions
    */

    typedef CGAL::Exact_predicates_inexact_constructions_kernel                  K;
    typedef CGAL::Delaunay_triangulation_2<K>                                    DT;
    typedef CGAL::Delaunay_triangulation_adaptation_traits_2<DT>                 AT;
    typedef CGAL::Delaunay_triangulation_caching_degeneracy_removal_policy_2<DT> AP;
    typedef CGAL::Voronoi_diagram_2<DT,AT,AP>                                    VoronoiDiagram;

    /*
    * Voronoi Data Structures
    */

    typedef AT::Point_2 Point_2;
    typedef AT::Site_2 Site_2;
    typedef std::vector< Site_2 > SiteVector;
    typedef typename Traits::Matrix Matrix;
    static SiteVector getSitesFromMatrix( Matrix& m );
    static VoronoiDiagram getVoronoiFromSites( const SiteVector& sites );
  };
} /* Core */

#include "Voronoi.cxx"

#endif
