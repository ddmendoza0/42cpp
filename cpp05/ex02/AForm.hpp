#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>
# include <iostream>
class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;

        AForm& operator=(const AForm& other);

    protected:
        void checkExecution(Bureaucrat const& executor) const;

    public:
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        ~AForm();

        const std::string& getName(void) const;
        bool    getSigned(void) const;
        int     getGradeToSign(void) const;
        int     getGradeToExecute(void) const;

        void    beSigned(const Bureaucrat& b);

        virtual void    execute(Bureaucrat const& executor) const = 0;

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

        class AlreadySignedException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class NotSignedException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif