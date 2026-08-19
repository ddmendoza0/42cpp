#include "Span.hpp"

Span::Span( unsigned int n ) : _n(n) {}

Span::Span( const Span& other ) : _v(other._v), _n(other._n) {}

Span& Span::operator=( const Span& other )
{
    if ( this != &other )
    {
        _n = other._n;
        _v = other._v;
    }
    return ( *this );
}

Span::~Span( void ) {}

void Span::addNumber( int n )
{
    if ( _v.size() >= _n )
        throw Span::FullContainer();
    _v.push_back(n);
}

unsigned int Span::shortestSpan( void )
{
    if ( _v.size() < 2 )
        throw Span::CalculationNotPossible();

    std::vector<int> sorted = _v;
    std::sort( sorted.begin(), sorted.end() );

    int min = sorted[1] - sorted[0];
    for ( unsigned int i = 0; i < ( sorted.size() - 1 ); i++ )
    {
        if ( ( sorted[i + 1] - sorted[i] ) < min )
            min = sorted[i + 1] - sorted[i];
    }
    
    return ( min );
}

unsigned int Span::longestSpan( void )
{
    if ( _v.size() < 2 )
        throw Span::CalculationNotPossible();

    int min = *std::min_element( _v.begin(), _v.end() );
    int max = *std::max_element( _v.begin(), _v.end() );

    return ( max - min );
}

const char*  Span::FullContainer::what() const throw()
{
    return ( "Container is full" );
}

const char* Span::CalculationNotPossible::what() const throw()
{
    return ( "Not enough elements" );
}