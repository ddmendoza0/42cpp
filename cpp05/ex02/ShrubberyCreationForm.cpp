
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) : AForm("Shrubbery Creation Form", 145, 137), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::execute( Bureaucrat const& executor ) const
{
    this->checkExecution( executor );

    std::string     outputfile_n = _target + "_shrubbery";
    std::ofstream   f0(outputfile_n.c_str());
    if (!f0.is_open())
        throw ShrubberyCreationForm::CannotOpenFileException();
    f0 << "     *\n    ***\n   *****\n  *******\n *********\n     |";
    f0.close();
}

const char* ShrubberyCreationForm::CannotOpenFileException::what() const throw()
{
    return ( "Could not open file" );
}