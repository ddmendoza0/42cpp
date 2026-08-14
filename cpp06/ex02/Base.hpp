#pragma once
#include <cstdlib>
#include <iostream>

class   Base
{
    public:
        virtual ~Base(void);

};

    Base*   generate(void);
    void    identify(Base* p);
    void    identify(Base& P);