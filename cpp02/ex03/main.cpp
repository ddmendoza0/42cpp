#include <iostream>
#include "Point.hpp"

int main( void )
{
    Point   a(1,1);
    Point   b(1,10);
    Point   c(10,1);
    Point   p(5,5);

    std::cout << bsp(a, b, c, p);
    return ( 0 );
}
