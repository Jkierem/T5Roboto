
Core::IntPair::IntPair( int x , int y ){
  this->m_x = x;
  this->m_y = y;
}

Core::IntPair::~IntPair(){}

int Core::IntPair::x(){
  return this->m_x;
}

int Core::IntPair::y(){
  return this->m_y;
}

Core::Line Core::calculateLine( int x0 , int y0 , int x1 , int y1 ){
  int dy = y1 - y0;
  int dx = x1 - x0;
  if( dy < 0 ){ dy *= -1; }
  if( dx < 0 ){ dx *= -1; }

  if( dy < dx ){
    if( x0 > x1 ){
      return calculateOverX(x1, y1, x0, y0);
    }else{
      return calculateOverX(x0, y0, x1, y1);
    }
  }else{
    if( y0 > y1 ){
      return calculateOverY(x1, y1, x0, y0);
    }else{
      return calculateOverY(x0, y0, x1, y1);
    }
  }
}

Core::Line Core::calculateOverX( int x0 , int y0 , int x1 , int y1 ){
  Core::Line res;

  int dx = x1 - x0;
  int dy = y1 - y0;
  int yi = 1;
  if( dy < 0 ){
    yi = -1;
    dy = -dy;
  }
  int D = ( 2 * dy ) - dx;
  int y = y0;

  for( int x = x0 ; x < x1 ; x++ ){
    res.push_back( Core::IntPair( x , y ) );
    if( D > 0 ){
      y = y + yi;
      D = D - ( 2 * dx );
    }
    D = D + ( 2 * dy );
  }

  return res;
}

Core::Line Core::calculateOverY( int x0 , int y0 , int x1 , int y1 ){
  Core::Line res;
  int dx = x1 - x0;
  int dy = y1 - y0;
  int xi = 1;
  if( dx < 0 ){
    xi = -1;
    dx = -dx;
  }
  int D = ( 2 * dx ) - dy;
  int x = x0;

  for( int y = y0 ; y < y1 ; y++ ){
    res.push_back( Core::IntPair( x , y ) );
    if( D > 0 ){
      x = x + xi;
      D = D - ( 2 * dy );
    }
    D = D - ( 2 * dx );
  }

  return res;
}

template< typename Traits >
void Core::plotOverMatrix( typename Traits::Matrix& m , Core::Line line ){
  for (size_t i = 0; i < line.size( ) ; i++) {
    Core::IntPair p = line[i];
    m( p.y( ) , p.x( ) ) = Traits::PATH;
  }
}
