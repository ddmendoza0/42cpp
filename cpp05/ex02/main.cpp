#include <ctime>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
    std::srand(std::time(NULL));

    Bureaucrat  ba("Hermes", 26);
    Bureaucrat  bb("DIRECTOR", 1);
    Bureaucrat  bc("Paperweight", 150);

    std::cout << "*_Execute Shrubbery with signature_*" << std::endl;
    ShrubberyCreationForm   f0("test00");
    ba.signForm(f0);
    ba.executeForm(f0);    

    std::cout << "\n*_Execute Shrubbery without signature_*" << std::endl;
    ShrubberyCreationForm f3("unsigned");
    ba.executeForm(f3);

    std::cout << "\n*_Execute Robotomy with signature_*" << std::endl;
    RobotomyRequestForm f1("test01");
    ba.signForm(f1);
    ba.executeForm(f1);

    std::cout << "\n*_Execute Presidential Pardon with signature_*" << std::endl;
    PresidentialPardonForm  f2("test02");
    bb.signForm(f2);
    bb.executeForm(f2);

    std::cout << "\n*_Sign with insuficient Grade_*" << std::endl;
    bc.signForm(f2);

    std::cout << "\n*_Execute with insuficient Grade_*" << std::endl;
    RobotomyRequestForm f4("robot");
    bb.signForm(f4);
    bc.executeForm(f4);

    std::cout << "\n*_Execute Form direct call_*" << std::endl;
    f2.execute(bb);
    
    return ( 0 );
}