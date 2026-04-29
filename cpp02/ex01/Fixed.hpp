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
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif