#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon&     _weapon;

        HumanA(const HumanA& other);
        HumanA& operator=(const HumanA& other);
    
    public:
        HumanA(const std::string& name, Weapon& weapon);
        ~HumanA();

        void    attack( void ) const;
};

#endif