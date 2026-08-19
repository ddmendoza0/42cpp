#pragma once

#include <algorithm>

template <typename T>
typename T::iterator easyfind( T& container, int n )
{
    if ( std::find( container.begin(), container.end(), n) == container.end() )
        throw std::exception();
    return (std::find( container.begin(), container.end(), n));
}
