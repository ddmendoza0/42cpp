#ifndef FIXED_HPP
# define FIXED_HPP
#include <ostream>

class   Fixed
{
    private:
        int                 fixed_point;
        static const int    fractional_bits;

    public:
        Fixed();
        Fixed(const int p_int);
        Fixed(const float p_float);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int     getRawBits( void ) const;
        void    setRawBits(int const raw);

        float   toFloat( void ) const;
        int     toInt( void ) const;

        // COMPARISON OPERATORS OVERLOAD
        bool    operator>( const Fixed& other) const;
        bool    operator<( const Fixed& other) const;
        bool    operator>=( const Fixed& other) const;
        bool    operator<=( const Fixed& other) const;
        bool    operator==( const Fixed& other) const;
        bool    operator!=( const Fixed& other) const;

        // ARITHMETIC OPERATORS OVERLOAD
        Fixed   operator+( const Fixed& other) const;
        Fixed   operator-( const Fixed& other) const;
        Fixed   operator*( const Fixed& other) const;
        Fixed   operator/( const Fixed& other) const;

        // INC/DEC OPERATORS OVERLOAD
        Fixed&  operator++();
        Fixed   operator++( int );
        Fixed&  operator--();
        Fixed   operator--( int );

        // MIN/MAX OVERLOAD
        static const Fixed&    min(const Fixed& a, const Fixed& b);
        static Fixed&          min(Fixed& a, Fixed& b);
        static const Fixed&    max(const Fixed& a, const Fixed& b);
        static Fixed&          max(Fixed& a, Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif