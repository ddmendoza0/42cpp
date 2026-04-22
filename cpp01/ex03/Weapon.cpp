#include "Weapon.hpp"

Weapon::Weapon() : _type("") {}

Weapon::Weapon( const std::string& type ) : _type(type) {}

Weapon::Weapon(const Weapon& other) : _type(other._type) {}

Weapon& Weapon::operator=(const Weapon& other) 
{ 
    if (this != &other)
        _type = other._type;
    return *this;
 }

Weapon::~Weapon() {}

void Weapon::setType( const std::string& type ) { _type = type; }

const std::string& Weapon::getType() const { return _type; }