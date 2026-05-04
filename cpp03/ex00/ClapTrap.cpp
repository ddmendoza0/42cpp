#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name) : _name(name), _hp(10), _ep(10), _dmg(0)
{
    std::cout << "ClapTrap " << _name << " is alive\n";
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
    std::cout << "ClapTrap " << _name << " is destroyed\n";
}

void    ClapTrap::attack( const std::string& target )
{
    if (_ep <= 0)
        std::cout << "ClapTrap " << _name << " is tired and couldn't attack\n";
    else if (_hp <= 0)
        std::cout << "ClapTrap " << _name << " is K.O. and couldn't attack\n";
    else
    {
        _ep--;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _dmg << " points of damage!\n";
    }
}

void   ClapTrap::beRepaired(unsigned int amount)
{
    if (_ep <= 0)
        std::cout << "ClapTrap " << _name << " is tired and couldn't repair itself\n";
    else if (_hp <= 0)
        std::cout << "ClapTrap " << _name << " is K.O. and couldn't repair itself\n";
    else
    {
        _ep--;
        _hp += amount;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points\n";
    }
}

void   ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > _hp)
        _hp = 0;
    else
        _hp -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!\n";
}