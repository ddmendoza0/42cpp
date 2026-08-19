#pragma once

#include <vector>
#include <algorithm>
#include <exception>

class Span
{
    private:
        std::vector<int>    _v;
        unsigned int        _n;

    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span(void);

        void            addNumber(int n);
        unsigned int    shortestSpan(void);
        unsigned int    longestSpan(void);
        template <typename Iterator>
        void            addRange(Iterator begin, Iterator end);

        class FullContainer : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class CalculationNotPossible : public std::exception
        {
            public:
                const char* what() const throw();
        };

};

template <typename Iterator>
void Span::addRange( Iterator begin, Iterator end )
{
    if ( std::distance(begin, end) + _v.size() > _n )
        throw Span::FullContainer();
    _v.insert( _v.end(), begin, end );
}