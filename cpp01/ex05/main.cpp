#include "Harl.hpp"
#include <iostream>

int main( void )
{
    Harl    harl;
    std::string level_name[5] = { "DEBUG", "INFO", "WARNING", "ERROR", "THIS SHOULD FAIL" };

    for (int i = 0; i < 5; i++)
    {
        std::cout << level_name[i] << " :\n";
        harl.complain( level_name[i] );
    }
    return (0);
}