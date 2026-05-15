#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal( void ) : type("Animal") 
{
    std::cout << "Animal default constructor called\n";
}

AAnimal::AAnimal( const AAnimal& other ) : type(other.type) 
{
    std::cout << "Animal copy constructor called\n";
}

AAnimal& AAnimal::operator=( const AAnimal& other )
{
    std::cout << "Animal assigment operator called\n";
    if (this != &other)
        type = other.type;
    return (*this);
}

AAnimal::~AAnimal( void ) 
{
    std::cout << "Animal destructor called\n";
}

std::string AAnimal::getType( void ) const { return ( type ); }
