#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
    ScavTrap    sctp("sctp");
    sctp.attack("enemy of Sanctuary");
    sctp.takeDamage(5);
    sctp.beRepaired(5);
    sctp.guardGate();
    ScavTrap sctp2(sctp);
    ScavTrap sctp3("sctp3");
    sctp3 = sctp;

    FragTrap    frtp("frtp");
    frtp.attack("enemy of Sanctuary");
    frtp.takeDamage(10);
    frtp.beRepaired(10);
    frtp.highFivesGuys();
    FragTrap frtp2(frtp);
    FragTrap frtp3("frtp3");
    frtp3 = frtp;
}