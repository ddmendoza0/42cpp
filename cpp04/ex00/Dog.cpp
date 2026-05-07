#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal()
{
    type = "Dog";
    std::cout << "Dog default constructor called\n";
}

Dog::Dog( const Dog& other ) : Animal(other)
{
    std::cout << "Dog copy constructor called\n";
};

Dog& Dog::operator=( const Dog& other )
{
    std::cout << "Dog assigment operator called\n";
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

Dog::~Dog( void )
{
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound( void ) const
{
    std::cout << "*wouf wouf*\n";
}