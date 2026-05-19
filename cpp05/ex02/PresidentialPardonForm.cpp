#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ) : AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm("Presidential Pardon Form", 25, 5), _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void PresidentialPardonForm::execute( Bureaucrat const& executor ) const
{
    this->checkExecution( executor );

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
