#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name) : _name(name), _hp(10), _ep(10), _dmg(0)
{
    std::cout << "ClapTrap " << _name << " is alive";
}

ClapTrap::ClapTrap( const ClapTrap& other ) : _name(other._name), _hp(other._hp), _ep(other._ep), _dmg(other._dmg) {}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        _name   = other._name;
        _hp     = other._hp;
        _ep     = other._ep;
        _dmg    = other._dmg;
    }
    return (*this);
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap " << _name << " is destroyed";
}

void    ClapTrap::attack( const std::string& target )
{
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _dmg << " points of damage!";
}

void   ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!";
}

void   ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points";
}