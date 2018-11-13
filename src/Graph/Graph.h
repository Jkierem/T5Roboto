#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include "../Traits/Traits.h"

namespace Core {

  template< typename Node , typename Weight=int >
  class Graph {
  protected:
    std::vector< Node > m_nodes;
    Traits< Weight >::Matrix m_adj;
  public:
    Graph( );
    virtual ~Graph( );
    void insertNode( Node node );
    void insertDirectedEdge( Node src , Node dst , Weight w );
    void insertBidirectedEdge( Node src , Node dst , Weight w );
    int findNodeIndex( Node node );
    Node getNodeByIndex( int index );
    // Algorithm to build
    /*
    * 1 - Find highest leftmost point
    * 2 - Connect towards the first unmarked point found in the following order
    *
    *     7 8 1
    *     6 X 2
    *     5 4 3
    */
  };
} /* Core */

#include "Graph.cxx"

#endif
