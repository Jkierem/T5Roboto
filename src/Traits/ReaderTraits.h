#ifndef __READER_TRAITS_H__
#define __READER_TRAITS_H__

#include "LogicTraits.h"

template< class TContainer , class TInserter , typename TElement , typename LT=LogicTraits >
class ReaderTraits {
public:
  static const int FREE;
  static const int BLOCKED;

  typedef TElement Element;
  typedef TContainer Container;
  typedef TInserter Inserter;

};

template< class TContainer , class TInserter , typename TElement , typename LT >
const int ReaderTraits< TContainer , TInserter , TElement , LT >::FREE = LT::FREE;

template< class TContainer , class TInserter , typename TElement , typename LT >
const int ReaderTraits< TContainer , TInserter , TElement , LT >::BLOCKED = LT::BLOCKED;


#endif
