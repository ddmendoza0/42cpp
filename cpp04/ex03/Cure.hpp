#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class   Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure& other);
        Cure& operator=(const Cure& other);
        ~Cure(void);

        virtual Cure* clone() const;
        virtual void use(ICharacter& target);

};

#endif