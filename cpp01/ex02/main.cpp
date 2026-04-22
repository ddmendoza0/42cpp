#include <string>
#include <iostream>
#include <iomanip>

int main( void)
{
    std::string     brain = "HI THIS IS BRAIN";
    std::string*    stringPTR = &brain;
    std::string&    stringREF = brain;

    std::cout << "Memory address:\n";
    std::cout << std::left << std::setw(15) << "- brain:" << &brain << '\n';
    std::cout << std::setw(15) << "- stringPTR:" << stringPTR << '\n';
    std::cout << std::setw(15) << "- stringREF:" << &stringREF << '\n';

    std::cout << "Values:\n";
    std::cout << std::setw(15) << "- brain: " << brain << '\n';
    std::cout << std::setw(15) << "- stringPTR: " << *stringPTR << '\n';
    std::cout << std::setw(15) << "- stringREF: " << stringREF << '\n';
    return (0);
}