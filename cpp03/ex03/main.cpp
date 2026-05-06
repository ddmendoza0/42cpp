#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
    DiamondTrap dt("dt");
    dt.attack("enemy");
    dt.takeDamage(10);
    dt.beRepaired(10);
    dt.guardGate();
    dt.highFivesGuys();
    dt.whoAmI();

    DiamondTrap dt2(dt);
    DiamondTrap dt3("dt3");
    dt3 = dt;
}