#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fractional_bits = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    fixed_point = 0;
}

Fixed::Fixed( const int p_int ) //shift or multiply by 256
{
    std::cout << "Int constructor called\n";
    fixed_point = p_int << fractional_bits;
}

Fixed::Fixed( const float p_float ) //floats cannot be shifted
{
    std::cout << "Float constructor called\n";
    fixed_point = roundf(p_float * (1 << fractional_bits));
}

Fixed::Fixed( const Fixed& other) : fixed_point(other.fixed_point)
{
    std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        fixed_point = other.fixed_point;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called\n";
    fixed_point = raw;
}

int Fixed::getRawBits( void ) const 
{
    std::cout << "getRawBits member function called\n";
    return fixed_point;
}

float   Fixed::toFloat( void ) const
{
    return ( (float)fixed_point / (1 << fractional_bits) );
}

int     Fixed::toInt( void ) const
{
    return ( fixed_point >> fractional_bits );
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}