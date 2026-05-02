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

    if (cross_ab <= 0 || cross_bc <= 0 || cross_ca <= 0)
        return ( false );
    return ( true );
}
