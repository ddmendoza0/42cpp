#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap    cltp("cltp");

    cltp.attack("enemy of Sactuary");
    cltp.takeDamage(5);
    cltp.beRepaired(5);
}