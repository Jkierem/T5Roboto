template< typename Traits >
bool Core::isBorder( int row , int col , const typename Traits::Matrix& m ){
  int nRows = m.row_dimension( );
  int nCols = m.column_dimension( );
  bool is = false;
  if( row+1 < nRows && m( row+1 , col ) == Traits::FREE ){ is = true; }
  if( col+1 < nCols && m( row , col+1 ) == Traits::FREE ){ is = true; }
  if( row-1 >= 0    && m( row-1 , col ) == Traits::FREE ){ is = true; }
  if( col-1 >= 0    && m( row , col-1 ) == Traits::FREE ){ is = true; }
  return is;
}

template< typename Traits >
typename Traits::Matrix Core::getBorders( typename Traits::Matrix& matrix ){
  int nRows = matrix.row_dimension( );
  int nCols = matrix.column_dimension( );
  typename Traits::Matrix res( nRows , nCols );
  for ( int row = 0; row < nRows ; row++ ) {
    for ( int col = 0 ; col < nCols ; col++ ) {
      int value = matrix( row , col );
      if( value == Traits::BLOCKED && Core::isBorder< Traits >( row , col , matrix ) ){
        res( row , col ) = Traits::BLOCKED;
      }else{
        res( row , col ) = Traits::FREE;
      }
    }
  }
  return res;
}
