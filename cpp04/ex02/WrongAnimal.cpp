#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal( void ) : type("WrongAnimal") 
{
    std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) : type(other.type) 
{
    std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other )
{
    std::cout << "WrongAnimal assigment operator called\n";
    if (this != &other)
        type = other.type;
    return (*this);
}

WrongAnimal::~WrongAnimal( void ) 
{
    std::cout << "WrongAnimal destructor called\n";
}

std::string WrongAnimal::getType( void ) const { return ( type ); }

void WrongAnimal::makeSound( void ) const
{
    std::cout << "*muffled sound...but kinda wrong??*\n";
}