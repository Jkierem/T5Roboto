template< typename Matrix , typename CoreTraits >
bool Core::isBorder( int row , int col , Matrix* m ){
  int nRows = m->size( );
  int nCols = (*m)[0].size( );
  bool is = false;
  if( row+1 < nRows && (*matrix)[row+1][col] == CoreTraits::FREE ){ is = true; }
  if( col+1 < nCols && (*matrix)[row][col+1] == CoreTraits::FREE ){ is = true; }
  if( row-1 >= 0    && (*matrix)[row-1][col] == CoreTraits::FREE ){ is = true; }
  if( col-1 >= 0    && (*matrix)[row][col-1] == CoreTraits::FREE ){ is = true; }
  if( row+1 < nRows && col+1 < nCols && (*matrix)[row+1][col+1] == CoreTraits::FREE ){ is = true; }
  if( row-1 >= 0    && col+1 < nCols && (*matrix)[row-1][col+1] == CoreTraits::FREE ){ is = true; }
  if( row+1 < nRows && col-1 >= 0    && (*matrix)[row+1][col-1] == CoreTraits::FREE ){ is = true; }
  if( row-1 >= 0    && col-1 >= 0    && (*matrix)[row-1][col-1] == CoreTraits::FREE ){ is = true; }
  return is;
}

template< typename Matrix , typename CoreTraits >
void Core::getBorders( Matrix* matrix ){
  int nRows = matrix->size( );
  int nCols = (*matrix)[0].size( );
  for ( int row = 0; row < nRows ; row++ ) {
    for ( int col = 0 ; col < nCols ; col++ ) {
      int value = (*matrix)[row][col];
      if( value == CoreTraits::BLOCKED && !Core::isBorder< Matrix , CoreTraits >( row , col , matrix) ){
        (*matrix)[row][col] = CoreTraits::FREE;
      }
    }
  }
}

template< typename PolygonTraits , typename PointTraits , typename Matrix >
typename PolygonTraits::Container Core::getPolygons( Matrix* borders ){

}
