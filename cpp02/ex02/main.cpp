#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

int main( void )
{
    Fixed       a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << std::left << std::setw(12) << "a" << a << std::endl;
    std::cout << std::setw(12) << "++a" << ++a << std::endl;
    std::cout << std::setw(12) << "a" << a << std::endl;
    std::cout << std::setw(12) << "a++" << a++ << std::endl;
    std::cout << std::setw(12) << "a" << a << std::endl;

    std::cout << std::setw(12) << "b" << b << std::endl;

    std::cout << std::setw(12) << "max(a , b)" << Fixed::max( a, b ) << std::endl;

    std::cout << std::setw(12) << "(a < b)" << (a < b) << std::endl;

    return ( 0 );
}