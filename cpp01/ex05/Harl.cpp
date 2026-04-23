#include "Harl.hpp"
#include <iostream>

Harl::Harl() {};

Harl::Harl( const Harl& ) {};

Harl& Harl::operator=( const Harl& ) { return *this; };

Harl::~Harl() {};

void    Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
};

void    Harl::info( void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";

};

void    Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
};

void    Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
};

void    Harl::complain( std::string level )
{
    void (Harl::*functions[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string level_name[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    int i = -1;
    while (++i < 4)
    {
        if (level_name[i] == level)
            break ;
    }
    if (i > 3)
        return ;
    (this->*functions[i])();
}