#pragma once

#include <vector>
#include <cstdlib>
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
        void            addRange(void);

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