#include "ScalarConverter.hpp"

int main( int argc, char **argv )
{
    std::string input;

    if (argc != 2 || !argv[1])
        return (1);

    input = argv[1];
    
    ScalarConverter::convert( input );

    return (0);
};