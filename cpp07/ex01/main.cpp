#include "iter.hpp"
#include <iostream>

void add_one( int& n )
{
    n++;
    std::cout << n <<std::endl;
}

void greet( std::string& name)
{
    std::cout << "Greetings " << name << std::endl;
}

int main( void )
{
    std::cout << "Calling Iter with function \"add_one\" and numbers: ";
    int nums[] = {0,10,20,30};
    for ( int i = 0; i < 4; i++ )
    {
        std::cout << nums[i];
        if ( i == 3 )
            std::cout  << std::endl;
        else
            std::cout << ", ";
    }
    ::iter(nums, 4, add_one);

    std::cout << "Calling Iter with function \"greet\" and names: ";
    std::string names[] = {"John", "Shreck", "Gustavo"};
    for ( int i = 0; i < 3; i++ )
    {
        std::cout << names[i];
        if ( i == 2 )
            std::cout  << std::endl;
        else
            std::cout << ", ";
    }
    ::iter(names, 3, greet);

    return ( 1 );
}