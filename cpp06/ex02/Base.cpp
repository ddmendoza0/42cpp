#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {}

Base* generate(void)
{
    int r = std::rand() % 3;
    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try {
        A& tmp = dynamic_cast<A&>(p);
        (void)tmp;
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception&) {}

    try { 
        B& tmp = dynamic_cast<B&>(p);
        (void)tmp;
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception&) {}

    try {
        C& tmp = dynamic_cast<C&>(p);
        (void)tmp;
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception&) {}
}