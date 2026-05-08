#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>

class   AAnimal
{
    protected:
        std::string type;

    public:
        AAnimal(void);
        AAnimal(const AAnimal& other);
        AAnimal& operator=(const AAnimal& other);
        virtual ~AAnimal(void);

        std::string getType(void) const;

        virtual void    makeSound(void) const = 0;

};

#endif