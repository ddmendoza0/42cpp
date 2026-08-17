#pragma once

template <typename T>
void    iter( T* p, const int n, void (*f)(T&) )
{
    for ( int i = 0; i < n; i++)
        f(p[i]);
}