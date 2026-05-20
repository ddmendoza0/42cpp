#include "Intern.hpp"

Intern::Intern( void ) {}

Intern::Intern( const Intern& ) {}

Intern& Intern::operator=( const Intern& ) { return ( *this ); }

Intern::~Intern( void ) {}

// MAKE FORM & HELPERS
typedef AForm* (*FormCreator)(const std::string&);

AForm* createRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }
AForm* createPardon(const std::string& target) { return new PresidentialPardonForm(target); }
AForm* createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }

AForm*  Intern::makeForm( const std::string& fname, const std::string& target )
{
    std::string     names[3] = { "robotomy request", "presidential pardon", "shrubbery creation" };
    FormCreator     creators[3] = { createRobotomy, createPardon, createShrubbery };

    for ( int i = 0; i < 3; i++ )
    {
        if ( fname == names[i] )
        {
            AForm* form = creators[i](target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return ( form );
        }
    }

    std::cout << "Form with name " << fname << "does not exists" <<std::endl;
    return ( NULL );
}