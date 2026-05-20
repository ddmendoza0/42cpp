#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(const Intern&);
        Intern& operator=(const Intern&);
        ~Intern(void);
        AForm*  makeForm(const std::string& fname, const std::string& target);

};

#endif