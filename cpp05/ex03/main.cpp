#include <ctime>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
    Intern  intern;
    AForm*  form;

    std::cout << "*_Valid forms_*" << std::endl;
    form = intern.makeForm("robotomy request", "Bender");
    delete form;

    form = intern.makeForm("presidential pardon", "Bender");
    delete form;

    form = intern.makeForm("shrubbery creation", "home");
    delete form;

    std::cout << "\n*_Invalid form_*" << std::endl;
    form = intern.makeForm("coffee request", "Bender");
    if (form)
        delete form;

    std::cout << "\n*_Sign and execute_*" << std::endl;
    Bureaucrat bb("DIRECTOR", 1);
    form = intern.makeForm("presidential pardon", "Zaphod");
    bb.signForm(*form);
    bb.executeForm(*form);
    delete form;

    return ( 0 );
}