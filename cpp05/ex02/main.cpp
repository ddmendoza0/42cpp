
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
    Bureaucrat  ba("Hermes", 26);
    Bureaucrat  bb("DIRECTOR", 1);
    Bureaucrat  bc("Paperweight", 150);

    ShrubberyCreationForm   f0("test01");
    ba.signForm(f0);
    f0.execute(ba);
    
    return ( 0 );
}