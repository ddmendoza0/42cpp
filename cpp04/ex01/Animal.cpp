#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) : type("Animal") 
{
    std::cout << "Animal default constructor called\n";
}

Animal::Animal( const Animal& other ) : type(other.type) 
{
    std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=( const Animal& other )
{
    std::cout << "Animal assigment operator called\n";
    if (this != &other)
        type = other.type;
    return (*this);
}

Animal::~Animal( void ) 
{
    std::cout << "Animal destructor called\n";
}

std::string Animal::getType( void ) const { return ( type ); }

void Animal::makeSound( void ) const
{
    std::cout << "*muffled sound...*\n";
}