#include "Span.hpp"
#include <iostream>
#include <ctime>

void fill_vector( std::vector<int>& v, unsigned int n )
{
    for ( unsigned int i = 0; i < n; i++ )
        v.push_back( std::rand() );
}


int main( void )
{
    std::srand(std::time(NULL));

    /*SUBJECT PROVIDED*/
    std::cout << "Subject provided test: " << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    /*EXCEPTION*/
    std::cout << "Exceptions tests" << std::endl;
    Span ex_sp(3);
    ex_sp.addNumber(6);

    std::cout << "  - shortestSpan call: ";
    try 
    {
        std::cout << ex_sp.shortestSpan() << std::endl;
    }
    catch ( std::exception& e )
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "  - longestSpan  call: ";
    try 
    {
        std::cout << ex_sp.longestSpan() << std::endl;
    }
    catch ( std::exception& e )
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "  - Adding a number when full: ";
    ex_sp.addNumber(6);
    ex_sp.addNumber(6);
    try 
    {
        ex_sp.addNumber(6);
    }
    catch ( std::exception& e )
    {
        std::cerr << e.what() << std::endl;
    }

    /*ADD RANGE*/
    std::cout << "Add range method: ";
    Span range_sp = Span(20);
    std::vector<int> source;
    for (int i = 1; i <= 10; i++)
        source.push_back(i);
    range_sp.addRange(source.begin(), source.end());
    std::cout << range_sp.shortestSpan() << ", " << range_sp.longestSpan() << std::endl;

    /*STRESS TEST*/
    std::cout << "20.000 numbers: ";
    Span big_sp = Span(20000);
    source.clear();
    fill_vector(source, 20000);
    big_sp.addRange(source.begin(), source.end());
    std::cout << big_sp.shortestSpan() << ", " << big_sp.longestSpan() << std::endl;

    return ( 0 );
}