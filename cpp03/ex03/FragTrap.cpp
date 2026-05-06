#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
    _hp     = 100;
    _ep     = 100;
    _dmg    = 30;
    std::cout << "FragTrap " << _name << " is created\n";
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap(other)
{
    std::cout << "FragTrap " << _name << " is copied\n";
}

FragTrap& FragTrap::operator=( const FragTrap& other )
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "FragTrap " << _name << " is assigned\n";
    }
    return (*this);
}

FragTrap::~FragTrap() 
{
    std::cout << "FragTrap " << _name << " is destroyed\n";
}

void    FragTrap::highFivesGuys( void )
{
    std::cout << "FragTrap " << _name << " \"gimme a high five hommie\"\n";
}