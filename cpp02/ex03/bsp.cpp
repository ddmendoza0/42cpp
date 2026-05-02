#include "Point.hpp"

Fixed   crossPoint( Point const& a, Point const& b, Point const& p )
{
    return ( (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX()) );
}


bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
    Fixed   cross_ab = crossPoint(a, b, point);
    Fixed   cross_bc = crossPoint(b, c, point);
    Fixed   cross_ca = crossPoint(c, a, point);

    bool allPositive = cross_ab > Fixed(0) && cross_bc > Fixed(0) && cross_ca > Fixed(0);
    bool allNegative = cross_ab < Fixed(0) && cross_bc < Fixed(0) && cross_ca < Fixed(0);
    
    return ( allPositive || allNegative );
}
