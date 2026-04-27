#include "Harl.hpp"
#include <iostream>

int main( int argc, char **argv )
{
    if (argc > 2 || !argv[1])
        return (0);

    Harl    harl;
    std::string level_name = argv[1];
    harl.complain( level_name );

    return (1);
}