#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat( void ) : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called\n";
};

WrongCat& WrongCat::operator=( const WrongCat& other )
{
    std::cout << "WrongCat assigment operator called\n";
    if (this != &other)
        WrongAnimal::operator=(other);
    return (*this);
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound( void ) const
{
    std::cout << "*meow...sound strange right?*\n";
}