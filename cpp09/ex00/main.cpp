#include "BitcoinExchange.hpp"
#include <iostream>

int main( int argc, char *argv[] )
{
    if ( argc < 2 )
    {
        std::cerr << "Error: An input file is required." << std::endl;
    }
    else if ( argc > 2 )
    {
        std::cerr << "Error: Too many arguments." << std::endl;
    }

    BitcoinExchange btc;
    btc.process(argv[1]);

    return ( 0 );
}