#ifndef __READER_TRAITS_H__
#define __READER_TRAITS_H__

template< class TContainer , class TInserter , typename TElement >
class ReaderTraits {
public:

  static const int FREE;
  static const int BLOCKED;
  static const int PATH;

  typedef TElement Element;
  typedef TContainer Container;
  typedef TInserter Inserter;

};

template< class TContainer , class TInserter , class TElement >
const int ReaderTraits< TContainer , TInserter , TElement >::FREE = 0;

template< class TContainer , class TInserter , class TElement >
const int ReaderTraits< TContainer , TInserter , TElement >::BLOCKED = 1;

template< class TContainer , class TInserter , class TElement >
const int ReaderTraits< TContainer , TInserter , TElement >::PATH = 2;

#endif
