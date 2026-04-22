#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
    private:
        std::string _type;
    
    public:
        Weapon();
        Weapon(const std::string& type);
        ~Weapon();
        Weapon(const Weapon& other);
        Weapon& operator=(const Weapon& other);

        const std::string&  getType( void ) const;
        void                setType(const std::string& type);
};

#endif