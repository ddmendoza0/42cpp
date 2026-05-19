#include <ctime>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
    Bureaucrat  ba("Hermes", 26);
    Bureaucrat  bb("DIRECTOR", 1);
    Bureaucrat  bc("Paperweight", 150);

    // ShrubberyCreationForm   f0("test00");
    // ba.signForm(f0);
    // f0.execute(ba);

    // std::srand(std::time(NULL));
    // RobotomyRequestForm f1("test01");
    // ba.signForm(f1);
    // f1.execute(ba);

    PresidentialPardonForm  f2("test02");
    bb.signForm(f2);
    f2.execute(bb);
    
    return ( 0 );
}