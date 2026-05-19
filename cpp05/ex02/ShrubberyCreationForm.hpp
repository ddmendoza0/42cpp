
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    
    public:
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm(void);

        void execute(Bureaucrat const& executor) const;

        class CannotOpenFileException : public std::exception
        {
            public:
                const char* what() const throw();
        };

};

#endif