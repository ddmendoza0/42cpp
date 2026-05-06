#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name) : ClapTrap(name)
{
    _hp     = 100;
    _ep     = 50;
    _dmg    = 20;
    std::cout << "ScavTrap " << _name << " is created\n";
}

ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap(other)
{
    std::cout << "ScavTrap " << _name << " is copied\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap " << _name << " is assigned\n";
    }
    return (*this);
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap " << _name << " is destroyed\n";
}

void    ScavTrap::attack( const std::string& target )
{
    if (_ep <= 0)
        std::cout << "ScavTrap " << _name << " is tired and couldn't attack\n";
    else if (_hp <= 0)
        std::cout << "ScavTrap " << _name << " is K.O. and couldn't attack\n";
    else
    {
        _ep--;
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _dmg << " points of damage!\n";
    }
}

void    ScavTrap::guardGate()
{
    if (_ep <= 0)
        std::cout << "ScavTrap " << _name << " is tired and couldn't enter Gate keeper mode\n";
    else if (_hp <= 0)
        std::cout << "ScavTrap " << _name << " is K.O. and couldn't enter Gate keeper mode\n";
    else
    {
        _ep--;
        std::cout << "ScavTrap " << _name << " is now in Gate keeper mode\n";
    }
}