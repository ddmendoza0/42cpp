#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap    sctp("sctp");

    sctp.attack("enemy of Sactuary");
    sctp.takeDamage(5);
    sctp.beRepaired(5);
    sctp.guardGate();

    ScavTrap sctp2(sctp);
    ScavTrap sctp3("sctp3");
    sctp3 = sctp;
}