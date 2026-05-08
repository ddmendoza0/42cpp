#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main( void )
{
    std::cout << "--- Array of Animals ---\n";
    AAnimal* animals[10];
    for (int i = 0; i < 5; i++)
        animals[i] = new Dog();
    for (int i = 5; i < 10; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Deleting Animals ---\n";
    for (int i = 0; i < 10; i++)
        delete animals[i];

    std::cout << "\n--- Deep copy test ---\n";
    Dog dog1;
    Dog dog2(dog1);  // copy constructor
    Dog dog3;
    dog3 = dog1;     // assignment operator

    std::cout << "\n--- Basic sound test ---\n";
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    j->makeSound();
    i->makeSound();
    delete j;
    delete i;

    return ( 0 );
}