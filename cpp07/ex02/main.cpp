#include "Array.hpp"
#include <iostream>

int main( void )
{
    /*EMPTY ARRAY*/
    std::cout << "Empty array: ";
    Array<int> empty;
    for ( unsigned int i = 0; i < empty.size(); i++ )
    {
        std::cout << empty[i];
        if ( i == empty.size() - 1)
            std::cout << std::endl;
        else
            std::cout << ", ";
    }
    std::cout << std::endl;

    /*STRING ARRAY*/
    std::cout << "String array: ";
    Array<std::string> strs(3);
    std::string tmp[] = {"this", "are", "strings"};
    for ( unsigned int i = 0; i < strs.size(); i++ )
        strs[i] = tmp[i];
    for ( unsigned int i = 0; i < strs.size(); i++ )
    {
        std::cout << strs[i];
        if ( i == strs.size() - 1)
            std::cout << std::endl;
        else
            std::cout << ", ";
    }

    /*INT ARRAY*/
    std::cout << "Int array: ";
    Array<int> ints(5);
    for ( unsigned int i = 0; i < ints.size(); i++ )
        ints[i] = i;
    for ( unsigned int i = 0; i < ints.size(); i++ )
    {
        std::cout << ints[i];
        if ( i == ints.size() - 1)
            std::cout << std::endl;
        else
            std::cout << ", ";
    }

    /*ASSINGMENT*/
    std::cout << "Copy constructor from Int to Empty: ";
    empty = ints;
    for ( unsigned int i = 0; i < empty.size(); i++ )
    {
        std::cout << empty[i];
        if ( i == empty.size() - 1)
            std::cout << std::endl;
        else
            std::cout << ", ";
    }

    /*COPY CONSTRUCTOR*/
    std::cout << "Copy constructor: ";
    Array<int> copied(ints);
    for ( unsigned int i = 0; i < copied.size(); i++ )
    {
        std::cout << copied[i];
        if ( i == copied.size() - 1)
            std::cout << std::endl;
        else
            std::cout << ", ";
    }

    /*DEEPNESS LEVEL*/
    std::cout << "Deep copy verification new: ";
    for ( unsigned int i = 0; i < copied.size(); i++ )
    {
        
        std::cout << ( copied[i] += copied[i] );
        if ( i == copied.size() - 1)
            std::cout << std::endl;
        else
            std::cout << ", ";
    }
    std::cout << "Deep copy verification org: ";
    for ( unsigned int i = 0; i < ints.size(); i++ )
    {
        std::cout << ints[i];
        if ( i == ints.size() - 1)
            std::cout << std::endl;
        else
            std::cout << ", ";
    }

    /*OOB CHECK*/
    std::cout << "Out Of Bounds Check error: ";
    try 
    {
        int error = ints[10];
        (void)error;
        std::cout << " this is a success";
    }
    catch ( const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Out Of Bounds Check success: ";
    try 
    {
        int success = ints[0];
        (void)success;
        std::cout << " this is a success";
    }
    catch ( const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    return ( 0 );
}