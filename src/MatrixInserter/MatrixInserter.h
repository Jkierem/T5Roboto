#ifndef __MatrixInserter_H__
#define __MatrixInserter_H__

#include "../Types/Types.h"

template< typename TElement >
class MatrixInserter {
protected:
  typename Types< TElement >::Matrix* m_Matrix;
public:
  MatrixInserter( typename Types< TElement >::Matrix* m );
  ~MatrixInserter( );
  void insert( int x , int y , TElement element );
};


template< class TElement >
MatrixInserter< TElement >::MatrixInserter( typename Types< TElement >::Matrix* m ){
  this->m_Matrix = m;
}

template< class TElement >
MatrixInserter< TElement >::~MatrixInserter( ){
  delete this->m_Matrix;
}

template< class TElement >
void MatrixInserter< TElement >::insert( int x , int y , TElement element ){
  if( this->m_Matrix->find( x ) == this->m_Matrix->end( ) ){
    (*(this->m_Matrix))[x] = typename Types< TElement >::Column( );
  }
  (*(this->m_Matrix))[x][y] = element;
}

#endif
