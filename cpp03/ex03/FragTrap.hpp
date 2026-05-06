#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class   FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();

        void    highFivesGuys(void);

};

#endif