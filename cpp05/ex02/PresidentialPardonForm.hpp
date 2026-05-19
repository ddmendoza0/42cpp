#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <cstdlib>
# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm  : public AForm
{
    private:
        std::string _target;
        PresidentialPardonForm & operator=(const PresidentialPardonForm & other);
    
    public:
        PresidentialPardonForm (const std::string& target);
        PresidentialPardonForm (const PresidentialPardonForm & other);
        ~PresidentialPardonForm (void);

        void execute(Bureaucrat const& executor) const;

};

#endif