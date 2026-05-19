#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include <ostream>
class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;

        Form& operator=(const Form& other);

    public:
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        ~Form();

        const std::string& getName(void) const;
        bool    getSigned(void) const;
        int     getGradeToSign(void) const;
        int     getGradeToExecute(void) const;

        void    beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Form& b);

#endif