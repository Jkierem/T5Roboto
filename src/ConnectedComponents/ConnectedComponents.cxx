template< typename Traits >
int Core::ConnectedComponents< Traits >::validateValue( int x , int dx , int limit ){
  int value = x + dx;
  if( value >= limit || value < 0 ){
    return 0;
  }
  return dx;
}

template< typename Traits >
int Core::ConnectedComponents< Traits >::getRegion( int x , int y , int newRegion , const typename Traits::Matrix& m ){
  int maxValue = m.row_dimension( ) + m.column_dimension( ) + 1;
  int region = maxValue;
  int neighbors[16] = {
     1,  0,  0,  1,
    -1,  0,  0, -1,
     1,  1,  1, -1,
    -1,  1, -1, -1
  };
  for( int i = 0 ; i < 8 ; i++ ){
    int j = 2*i;
    int xi = neighbors[  j  ];
    int yi = neighbors[ j+1 ];
    int cx = x + validateValue( x , xi , m.row_dimension( ) );
    int cy = y + validateValue( y , yi , m.column_dimension( ) );
    typename Traits::Element value = m( cx , cy );
    if( value > 0 && value < region ){
      region = value;
    }
  }
  if( region == maxValue ){
    region = newRegion;
  }
  return region;
}

template< typename Traits >
typename Traits::Matrix Core::ConnectedComponents< Traits >::getConnectedRegions( const typename Traits::Matrix& m ){
  typedef Core::ConnectedComponents< Traits > CC;
  typedef typename Traits::Element Element;

  int currentRegion = 0;
  int nRows = m.row_dimension( );
  int nCols = m.column_dimension( );
  typename Traits::Matrix regions( nRows , nCols );

  for ( int row = 0; row < nRows ; row++ ) {
    for ( int col = 0; col < nCols ; col++ ) {
      if( m( row , col ) == Traits::BLOCKED ){
        Element region = CC::getRegion( row , col , currentRegion + 1 , regions );
        if( region == currentRegion + 1 ){
          currentRegion++;
        }
        regions( row , col ) = region;
      }
    }
  }

  int markers[ currentRegion ];
  for ( int i = 0; i < currentRegion ; i++ ) {
    markers[ i ] = i;
  }

  for ( int row = 0; row < nRows ; row++ ) {
    for ( int col = 0; col < nCols ; col++ ) {
      Element value = regions( row , col );
      if( value != Traits::FREE ){
        Element expectedRegion = getRegion( row , col , 0 , regions );
        if( expectedRegion != value ){
          markers[ value - 1 ] = expectedRegion - 1;
        }
      }
    }
  }

  for ( int row = 0; row < nRows ; row++ ) {
    for ( int col = 0; col < nCols ; col++ ) {
      Element value = regions( row , col );
      if( value != Traits::FREE ){
        if( markers[ value - 1 ] != value - 1 ){
          int regionValue = value - 1;
          while( markers[ regionValue ] != regionValue ){
            regionValue = markers[ regionValue ];
          }
          regions( row , col ) = regionValue + 1;
        }
      }
    }
  }

  return regions;
}

template< typename Traits >
typename Traits::PolygonContainer Core::ConnectedComponents< Traits >::createPolygonsFromRegions( const typename Traits::Matrix& m ){
  typedef typename Traits::Point Point;
  typedef typename Traits::Polygon Polygon;
  typename Traits::PolygonContainer ps;
  int nRows = m.row_dimension( );
  int nCols = m.column_dimension( );

  std::set< int > checkedRegions;
  int neighbors[ 16 ] = {
    0,1,
    1,1,
    1,0,
    1,-1,
    0,-1,
    -1,-1,
    -1,0,
    -1,1
  };

  typename Traits::Matrix marks( nRows , nCols );
  for( int row = 0 ; row < nRows ; row++ ){
    for( int col = 0 ; col < nCols ; col++ ){
      int region = m( row , col );
      if( region != Traits::FREE && checkedRegions.find( region ) == checkedRegions.end( ) ){
        checkedRegions.insert( region );
        Polygon p;
        bool hasNext = true;
        int curRow = row;
        int curCol = col;
        marks( curRow , curCol ) = Traits::MARKED;
        p.push_back( Point( curRow , curCol ) );
        while( hasNext ){
          hasNext = false;
          for( int n = 0 ; n < 8 ; n++ ){
            int curN = 2*n;
            int xi = neighbors[  curN  ];
            int yi = neighbors[ curN+1 ];
            int cx = curRow + xi;
            int cy = curCol + yi;
            bool validPos = true;
            if( cx >= nRows || cx < 0 || cy >= nCols || cy < 0 ){
              validPos = false;
            }
            if( validPos && !hasNext && m( cx , cy ) == region && marks( cx , cy ) != Traits::MARKED ){
              hasNext = true;
              p.push_back( Point( cx , cy ) );
              marks( cx , cy ) = Traits::MARKED;
              curRow = cx;
              curCol = cy;
            }
          }
        }
        ps.push_back( p );
      }
    }
  }

  return ps;
}
