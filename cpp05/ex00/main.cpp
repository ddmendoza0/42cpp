
#include <iostream>
#include "Bureaucrat.hpp"

int main( void )
{
    Bureaucrat  a("Hermes", 26);
    Bureaucrat  b("DIRECTOR", 1);
    Bureaucrat  c("paperweight", 150);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    a.incrementGrade();
    std::cout << a << std::endl;

    try
    {
        //all of these throw exceptions
        Bureaucrat invalid("too high", 0);
        Bureaucrat invalid("too low", 151);
        b.incrementGrade();
        c.decrementGrade();    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return ( 0 );
}