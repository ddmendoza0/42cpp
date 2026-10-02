#include "BitcoinExchange.hpp"
#include <iostream>

int main( int argc, char *argv[] )
{
    if ( argc < 2 )
    {
        std::cerr << "Error: An input file is required." << std::endl;
        return ( 1 );
    }
    else if ( argc > 2 )
    {
        std::cerr << "Error: Too many arguments." << std::endl;
        return ( 1 );
    }

    BitcoinExchange btc;
    btc.process(argv[1]);

    return ( 0 );
}