#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : _name("") {}

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::Zombie(const Zombie& other) : _name(other._name) {}

Zombie& Zombie::operator=(const Zombie& other)
{
    if (this != &other)
        _name = other._name;
    return *this;
}

Zombie::~Zombie() {
    std::cout << _name << " is destroyed\n";
}

void    Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
