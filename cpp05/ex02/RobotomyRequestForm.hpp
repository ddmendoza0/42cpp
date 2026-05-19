#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <cstdlib>
# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm  : public AForm
{
    private:
        std::string _target;
        RobotomyRequestForm & operator=(const RobotomyRequestForm & other);
    
    public:
        RobotomyRequestForm (const std::string& target);
        RobotomyRequestForm (const RobotomyRequestForm & other);
        ~RobotomyRequestForm (void);

        void execute(Bureaucrat const& executor) const;

};

#endif