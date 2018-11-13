template< typename Traits >
std::vector< typename Core::Voronoi< Traits >::Site_2 > Core::Voronoi< Traits >::getSitesFromMatrix( typename Traits::Matrix& m ){
  std::vector< typename Core::Voronoi< Traits >::Site_2 > res;
  int nRows = m.row_dimension( );
  int nCols = m.column_dimension( );
  for (int i = 0; i < nRows ; i++) {
    for( int j = 0 ; j < nCols ; j++ ){
      typename Traits::Element value = m( i , j );
      if( value == Traits::BLOCKED ){
        Point_2 p( i , j );
        res.push_back( Site_2( p ) );
      }
    }
  }
  res.push_back( Site_2( Point_2( 0 , 0 ) ) );
  res.push_back( Site_2( Point_2( nRows - 1 , 0 ) ) );
  res.push_back( Site_2( Point_2( 0 , nCols - 1 ) ) );
  res.push_back( Site_2( Point_2( nRows - 1 , nCols - 1 ) ) );
  return res;
}

template< typename Traits >
typename Core::Voronoi< Traits >::VoronoiDiagram Core::Voronoi< Traits >::getVoronoiFromSites( const typename Core::Voronoi< Traits >::SiteVector& sites ){
  typename Core::Voronoi< Traits >::VoronoiDiagram vd;
  SiteVector::const_iterator sIt = sites.begin( );
  for( ; sIt != sites.end( ) ; sIt++ ){
    vd.insert( *sIt );
  }
  return vd;
}
