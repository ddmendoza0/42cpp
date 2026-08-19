#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>


int main( void )
{
    /*VECTOR*/
    std::vector<int> v;
    for ( int i = 0; i < 5; i++ )
        v.push_back(i);
    std::cout << "Container: Vector" << std::endl;
    std::cout << "Searching for 3...";
    try
    {
        easyfind(v, 3);
        std::cout << " found" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << " not found" << std::endl;
    }
    std::cout << "Searching for 33...";
    try
    {
        easyfind(v, 33);
        std::cout << " found" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << " not found" << std::endl;
    }

    /*LIST*/
    std::list<int> l;
    for ( int i = 0; i < 5; i++ )
        l.push_back(i + 10);
    std::cout << "Container: List" << std::endl;
        std::cout << "Searching for 13...";
    try
    {
        easyfind(l, 13);
        std::cout << " found" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << " not found" << std::endl;
    }
    std::cout << "Searching for 33...";
    try
    {
        easyfind(l, 33);
        std::cout << " found" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << " not found" << std::endl;
    }

    /*DEQUE*/
    std::deque<int> d;
    for ( int i = 0; i < 5; i++ )
        d.push_back(i + 100);
    std::cout << "Container: Deque" << std::endl;
    std::cout << "Searching for 103...";
    try
    {
        easyfind(d, 103);
        std::cout << " found" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << " not found" << std::endl;
    }
    std::cout << "Searching for 33...";
    try
    {
        easyfind(d, 33);
        std::cout << " found" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << " not found" << std::endl;
    }

    return ( 0 ); 
}