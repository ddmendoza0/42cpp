#include "PmergeMe.hpp"

int main( int argc, char *argv[] )
{
    if ( argc < 2 )
    {
        std::cerr << "Error" << std::endl;
        return ( 1 );
    }

    try
    {
        PmergeMe pm(argc, argv);
        pm.sort();
    }
    catch ( std::exception& e )
    {
        std::cerr << e.what() << std::endl;
        return ( 1 );
    }

}