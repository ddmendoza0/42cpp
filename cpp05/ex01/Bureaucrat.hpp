#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <ostream>
class Form;

class   Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;

        Bureaucrat& operator=(const Bureaucrat& other);

    public:
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat(void);

        const std::string& getName(void) const;
        int     getGrade(void) const;

        void    incrementGrade(void);
        void    decrementGrade(void);

        void    signForm(Form& f);

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


std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);


#endif