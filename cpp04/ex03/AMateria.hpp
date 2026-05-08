#ifndef AAMATERIA_HPP
# define AAMATERIA_HPP

class   AMateria
{
    protected:

    public:
        AMateria(std::string const & type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        ~AMateria(void);

        std::string const & getType() const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

}

#enfif