#pragma once

template <typename T, typename F>
void    iter( T* p, const int n, F f )
{
    for ( int i = 0; i < n; i++)
        f(p[i]);
}