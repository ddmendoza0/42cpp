#include "AMateria.hpp"

AMateria::AMateria( std::string const & type ) : _type(type) {}

AMateria::AMateria( const AMateria&  other ) : _type(other._type) {}

AMateria& AMateria::operator=( const AMateria& other )
{
    if (this != &other)
        _type = other._type;
    return ( *this );
}

AMateria::~AMateria( void ) {}

std::string const & AMateria::getType() const { return ( _type ); };

void    AMateria::use( ICharacter& target ) {};