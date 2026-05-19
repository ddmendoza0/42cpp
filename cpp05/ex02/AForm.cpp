
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( const std::string& name, int gradeToSign, int gradeToExecute ) : _name(name), _signed(false), _gradeToSign(gradeToSign) ,_gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm( const AForm& other ) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign) ,_gradeToExecute(other._gradeToExecute) {}

AForm::~AForm( void ) {}

const std::string&  AForm::getName( void ) const { return ( _name ); }
bool                AForm::getSigned( void ) const { return ( _signed ); }
int                 AForm::getGradeToSign( void ) const { return ( _gradeToSign ); }
int                 AForm::getGradeToExecute( void ) const { return ( _gradeToExecute ); }

void    AForm::beSigned( const Bureaucrat& b ) 
{
    if ( b.getGrade() > _gradeToSign )
        throw AForm::GradeTooLowException();
    _signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ( "Grade is too high" );
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ( "Grade is too low" );
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << "AForm: " << f.getName() << "\nSigned: " << f.getSigned() << "\nRequired Grade to Sign: " << f.getGradeToSign() << "\nRequired Grade to Execute: " << f.getGradeToExecute();
    return ( out );
}