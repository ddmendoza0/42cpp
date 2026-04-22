#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() : _count(0), _oldest(0) {}
PhoneBook::~PhoneBook() {}

bool    PhoneBook::add()
{
    if (!_contacts[_oldest].setContact())
        return (false);
    _oldest = (_oldest + 1) % 8;
    if (_count < 8)
        _count++;
    std::cout << "Successfully added a contact\n";
    return (true);
}

std::string truncate(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

bool    PhoneBook::search()
{
    if (_count == 0)
    {
        std::cout << "No contacts to display\n";
        return true;
    }

    std::cout << '|' << std::setw(10) << "INDEX";
    std::cout << '|' << std::setw(10) << "FIRST NAME";
    std::cout << '|' << std::setw(10) << "LAST NAME";
    std::cout << '|' << std::setw(10) << "NICK NAME";
    std::cout << '|' << '\n';

    for(int i = 0; i < _count; i++)
    {
        std::cout << '|' << std::setw(10) << i;
        std::cout << '|' << std::setw(10) << truncate(_contacts[i].getFirstName());
        std::cout << '|' << std::setw(10) << truncate(_contacts[i].getLastName());
        std::cout << '|' << std::setw(10) << truncate(_contacts[i].getNickName());
        std::cout << '|' << '\n';
    }

    std::string     sel;
    bool    first = true;
    while(sel.length() != 1 || !isdigit(sel[0]) || (sel[0] - '0') >= _count)
    {
        if (!first)
            std::cout << "Invalid Index selected.\n";
        std::cout << "What contact do you wish to display? (Introduce index)\n";
        if (!std::getline(std::cin, sel))
            return false;
        first = false;
    }
    int index = std::atoi(sel.c_str());

    std::cout << "First Name: " << _contacts[index].getFirstName() << '\n';
    std::cout << "Last Name: " << _contacts[index].getLastName() << '\n';
    std::cout << "Nick Name: " << _contacts[index].getNickName() << '\n';
    std::cout << "Phone Number: " << _contacts[index].getPhoneNum() << '\n';
    std::cout << "Darkest Secret: " << _contacts[index].getSecret() << '\n';

    return (true);
}