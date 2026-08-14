#include "Base.hpp"
#include <ctime>

int main (void)
{
    std::srand(std::time(NULL));

    for  (int i = 0; i < 4; i++)
    {
        Base* obj = generate( );

        std::cout << "Pointer identify function: ";
        identify(obj);

        std::cout << "Reference identify function: ";
        identify(*obj);

        delete obj;
    }

    return ( 0 );

}