#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main( void )
{
    Data data;
    data.name = "test";
    data.value = 42;

    std::cout << "Original pointer: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized: " << raw << std::endl;

    Data* result = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << result << std::endl;

    if ( &data == result )
        std::cout << "Pointers match: yes" << std::endl;
    else
        std::cout << "Pointers match: no" << std::endl;
    std::cout << "Name: " << result->name << std::endl;
    std::cout << "Value: " << result->value << std::endl;

    return ( 0 );
}