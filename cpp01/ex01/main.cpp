#include "Zombie.hpp"

int main( void )
{
    Zombie  *horde;
    const int     nZombies = 10;

    horde = zombieHorde(nZombies, "ZombieDudes");
    for (int i = 0; nZombies > i; i++)
        horde[i].announce();
    delete[] horde;
    return (0);
}