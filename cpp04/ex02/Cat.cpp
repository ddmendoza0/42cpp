#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : AAnimal()
{
    std::cout << "Cat default constructor called\n";
    type  = "Cat";
    brain = new Brain();
}

Cat::Cat( const Cat& other ) : AAnimal(other)
{
    std::cout << "Cat copy constructor called\n";
    brain = new Brain(*other.brain);
};

Cat& Cat::operator=( const Cat& other )
{
    std::cout << "Cat assigment operator called\n";
    if (this != &other)
    {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Cat::~Cat( void )
{
    std::cout << "Cat destructor called\n";
    delete brain;
}

void Cat::makeSound( void ) const
{
    std::cout << "*meow*\n";
}