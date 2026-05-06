#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string p_name) : ClapTrap(p_name + "_clap_name"), FragTrap(p_name), ScavTrap(p_name), name(p_name)
{
    _hp  = 100;
    _ep  = 50;
    _dmg = 30;
    std::cout << "DiamondTrap " << name << " is created\n";
}

DiamondTrap::DiamondTrap( const DiamondTrap& other ) : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name) 
{
    std::cout << "DiamondTrap " << name << " is copied\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        name = other.name;
        std::cout << "DiamondTrap " << name << " is assigned\n";
    }
    return (*this);
}

DiamondTrap::~DiamondTrap() 
{
    std::cout << "DiamondTrap " << name << " is destroyed\n";
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::_name << "\n";
}