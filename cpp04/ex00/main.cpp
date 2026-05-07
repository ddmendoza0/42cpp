#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void )
{
    std::cout << "--- Animal tests ---\n";
    const Animal* meta = new Animal();
    const Animal* j    = new Dog();
    const Animal* i    = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    meta->makeSound();  // Animal sound
    j->makeSound();     // Dog sound through Animal pointer
    i->makeSound();     // Cat sound through Animal pointer

    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- WrongAnimal tests ---\n";
    const WrongAnimal* w  = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    wc->makeSound();  // should print WrongAnimal sound, NOT WrongCat
    w->makeSound();

    delete w;
    delete wc;

    return ( 0 );
}