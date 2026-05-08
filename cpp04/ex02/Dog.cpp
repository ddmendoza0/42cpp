#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : AAnimal()
{
    std::cout << "Dog default constructor called\n";
    type  = "Dog";
    brain = new Brain();
}

Dog::Dog( const Dog& other ) : AAnimal(other)
{
    std::cout << "Dog copy constructor called\n";
    brain = new Brain(*other.brain);
};

Dog& Dog::operator=( const Dog& other )
{
    std::cout << "Dog assigment operator called\n";
    if (this != &other)
    {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Dog::~Dog( void )
{
    std::cout << "Dog destructor called\n";
    delete brain;
}

void Dog::makeSound( void ) const
{
    std::cout << "*wouf wouf*\n";
}