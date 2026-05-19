
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( const std::string& name, int gradeToSign, int gradeToExecute ) : _name(name), _signed(false), _gradeToSign(gradeToSign) ,_gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form( const Form& other ) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign) ,_gradeToExecute(other._gradeToExecute) {}

Form::~Form( void ) {}

const std::string&  Form::getName( void ) const { return ( _name ); }
bool                Form::getSigned( void ) const { return ( _signed ); }
int                 Form::getGradeToSign( void ) const { return ( _gradeToSign ); }
int                 Form::getGradeToExecute( void ) const { return ( _gradeToExecute ); }

void    Form::beSigned( const Bureaucrat& b ) 
{
    if ( b.getGrade() > _gradeToSign )
        throw Form::GradeTooLowException();
    _signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ( "Grade is too high" );
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ( "Grade is too low" );
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
    out << "Form: " << f.getName() << "\nSigned: " << f.getSigned() << "\nRequired Grade to Sign: " << f.getGradeToSign() << "\nRequired Grade to Execute: " << f.getGradeToExecute();
    return ( out );
}