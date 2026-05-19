#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm("Shrubbery Creation Form", 145, 137), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::execute( Bureaucrat const& executor ) const
{
    this->checkExecution( executor );

    std::cout << "** [DRILLING NOISES] **" << std::endl;
    if ( rand() % 2 )
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << _target << " robotomy failed!" << std::endl;       
}
