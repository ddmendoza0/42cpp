
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
    Bureaucrat  ba("Hermes", 26);
    Bureaucrat  bb("DIRECTOR", 1);
    Bureaucrat  bc("Paperweight", 150);

    std::cout << ba << std::endl;
    std::cout << bb << std::endl;
    std::cout << bc << std::endl;

    Form    fa("Simple Form", 150, 150);
    Form    fb("Interesting Form", 70, 60);
    Form    fc("Bureaucrats Nightmare", 1, 2);
    try
    {
        Form invalid("bad form", 0, 50);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    ba.signForm(fa);
    bc.signForm(fb);
    bb.signForm(fc);
    
    return ( 0 );
}