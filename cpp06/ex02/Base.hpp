#pragma once
#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class   Base
{
    public:
        virtual ~Base(void);

};

    Base*   generate(void);
    void    identify(Base* p);
    void    identify(Base& P);