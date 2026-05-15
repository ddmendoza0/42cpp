#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name(name), _grade(grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException( );
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException( );
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat( void ) {}

const std::string& Bureaucrat::getName( void ) { return ( _name ); }

const std::string& Bureaucrat::getGrade( void ) { return ( _grade ); }

void Bureaucrat::incrementGrade( void )
{
    if ((_grade - 1) < 1)
        throw Bureaucrat::GradeTooHighException( );
    _grade--;
}

void Bureaucrat::decrementGrade( void )
{
    if ((grade + 1) > 150)
        throw Bureaucrat::GradeTooLowException( );
    grade++;
}