#include <string>
#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(const std::string& name) : _name(name),  _weapon(NULL) {}

HumanB::~HumanB() {}

void    HumanB::setWeapon( Weapon& weapon)
{
    _weapon = &weapon;
}

void    HumanB::attack( void ) const
{
    if (!_weapon)
    {
        std::cout << _name << " has no weapon to attack with" << std::endl;
        return;
    }
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}