#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal()
{
    type = "Cat";
    std::cout << "Cat default constructor called\n";
}

Cat::Cat( const Cat& other ) : Animal(other)
{
    std::cout << "Cat copy constructor called\n";
};

Cat& Cat::operator=( const Cat& other )
{
    std::cout << "Cat assigment operator called\n";
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

Cat::~Cat( void )
{
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound( void ) const
{
    std::cout << "*meow*\n";
}