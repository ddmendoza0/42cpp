#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fractional_bits = 8;

Fixed::Fixed() { fixed_point = 0; }

Fixed::Fixed( const int p_int ) { fixed_point = p_int << fractional_bits; }

Fixed::Fixed( const float p_float ) { fixed_point = roundf(p_float * (1 << fractional_bits)); }

Fixed::Fixed( const Fixed& other) : fixed_point(other.fixed_point) {}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        fixed_point = other.fixed_point;
    return (*this);
}

Fixed::~Fixed() {}

void Fixed::setRawBits( int const raw ) { fixed_point = raw; }

int Fixed::getRawBits( void ) const { return fixed_point; }

float   Fixed::toFloat( void ) const { return ( (float)fixed_point / (1 << fractional_bits) ); }

int     Fixed::toInt( void ) const { return ( fixed_point >> fractional_bits ); }

// COMPARISON OPERATORS OVERLOAD
bool    Fixed::operator>( const Fixed& other) const
{
    return ( this->fixed_point > other.fixed_point );
}

bool    Fixed::operator<( const Fixed& other) const
{
    return ( this->fixed_point < other.fixed_point );
}

bool    Fixed::operator>=( const Fixed& other) const
{
    return ( this->fixed_point >= other.fixed_point );
}

bool    Fixed::operator<=( const Fixed& other) const
{
    return ( this->fixed_point <= other.fixed_point );
}

bool    Fixed::operator==( const Fixed& other) const
{
    return ( this->fixed_point == other.fixed_point );
}

bool    Fixed::operator!=( const Fixed& other) const
{
    return ( this->fixed_point != other.fixed_point );
}

// ARITHMETIC OPERATORS OVERLOAD
Fixed   Fixed::operator+( const Fixed& other) const
{
    Fixed   result;
    result.setRawBits(this->fixed_point + other.fixed_point);
    return ( result );
}

Fixed   Fixed::operator-( const Fixed& other) const
{
    Fixed   result;
    result.setRawBits(this->fixed_point - other.fixed_point);
    return ( result );
}

Fixed   Fixed::operator*( const Fixed& other) const
{
    Fixed   result;
    result.setRawBits((this->fixed_point * other.fixed_point) >> fractional_bits);
    return ( result );
}

Fixed   Fixed::operator/( const Fixed& other) const
{
    Fixed   result;
    result.setRawBits((this->fixed_point << fractional_bits) / other.fixed_point);
    return ( result );
}

// INC/DEC OPERATORS OVERLOAD
Fixed&  Fixed::operator++()
{
    fixed_point += 1;
    return ( *this );
}

Fixed   Fixed::operator++( int )
{
    Fixed result(*this);
    fixed_point += 1;
    return ( result );
}

Fixed&  Fixed::operator--()
{
    fixed_point -= 1;
    return ( *this );
}

Fixed   Fixed::operator--( int )
{
    Fixed result(*this);
    fixed_point -= 1;
    return ( result );
}

// MIN/MAX OVERLOAD
const Fixed&    Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

Fixed&          Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed&    Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

Fixed&          Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

// STD::COUT OVERLOAD
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}