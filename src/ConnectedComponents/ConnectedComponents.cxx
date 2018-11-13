template< typename Traits >
int Core::ConnectedComponents< Traits >::validateValue( int value , int limit ){
  if( value >= limit || value < 0 ){
    return 0;
  }
  return value;
}

template< typename Traits >
typename Traits::Element Core::ConnectedComponents< Traits >::getRegion( int x , int y , int newRegion , const typename Traits::Matrix& m ){
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
    int cx = validateValue( x + xi , m.row_dimension( ) );
    int cy = validateValue( y + yi , m.column_dimension( ) );
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
