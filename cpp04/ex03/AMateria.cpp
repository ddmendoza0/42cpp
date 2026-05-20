#include "AMateria.hpp"

AMateria::AMateria( std::string const & type ) : _type(type) {}

AMateria::AMateria( const AMateria&  other ) : _type(other._type) {}

AMateria& AMateria::operator=( const AMateria& other )
{
    ( void )other;
    return ( *this );
}

AMateria::~AMateria( void ) {}

std::string const & AMateria::getType() const { return ( _type ); }

void    AMateria::use( ICharacter& ) {}