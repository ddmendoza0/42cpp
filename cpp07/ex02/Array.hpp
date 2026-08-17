#pragma once

template <typename T>
class Array
{
    private:
        T*              _arr;
        unsigned int    _size;
    public:

        Array(void);
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array(void);

        T& operator[](unsigned int idx);
        const T& operator[](unsigned int idx) const;
        unsigned int size(void) const;


};
#include "Array.tpp"