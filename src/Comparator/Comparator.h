#ifndef __COMPARATOR_H__
#define __COMPARATOR_H__ value

template< typename Point >
struct Comparator {
  bool operator() (const Point& a, const Point& b) const {
    if(a.y() == b.y()){
      return a.x() > b.x();
    }else{
      return b.y() > a.y();
    }
  }
};

#endif
