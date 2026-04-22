#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon*     _weapon;

        HumanB(const HumanB& other);
        HumanB& operator=(const HumanB& other);
    
    public:
        HumanB(const std::string& name);
        ~HumanB();

        void    setWeapon( Weapon& weapon);

        void    attack( void ) const;
};

#endif