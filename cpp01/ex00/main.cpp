#include "Zombie.hpp"

int main( void )
{
    Zombie  *zombie;

    zombie = newZombie("Cheesus");
    zombie->announce();
    randomChump("Believer");
    delete zombie;
    return (0);
}