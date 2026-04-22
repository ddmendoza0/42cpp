#include "Contact.hpp"
#include <iostream>

Contact::Contact() {}
Contact::~Contact() {}

std::string Contact::getFirstName() const { return _FirstName; }
std::string Contact::getLastName() const { return _LastName; }
std::string Contact::getNickName() const { return _NickName; }
std::string Contact::getPhoneNum() const { return _PhoneNum; }
std::string Contact::getSecret() const {return _Secret; }

bool Contact::setContact()
{
    _FirstName = "";
    _LastName = "";
    _NickName = "";
    _PhoneNum = "";
    _Secret = "";
    while (_FirstName.empty())
    {
        std::cout << "Introduce First Name:\n";
        if (!std::getline(std::cin, _FirstName))
            return false;
    }

    while (_LastName.empty())
    {
        std::cout << "Introduce Last Name:\n";
        if (!std::getline(std::cin, _LastName))
            return false;
    }

    while (_NickName.empty())
    {
        std::cout << "Introduce Nick Name:\n";
        if (!std::getline(std::cin, _NickName))
            return false;
    }

    while (_PhoneNum.empty())
    {
        std::cout << "Introduce Phone Number:\n";
        if (!std::getline(std::cin, _PhoneNum))
            return false;
        for (int i = 0; _PhoneNum[i]; i++)
        {
            if (i == 0 && _PhoneNum[0] == '+' && _PhoneNum[i + 1])
                continue;
            if (_PhoneNum[i] <= '9' && _PhoneNum[i] >= '0')
                continue;
            if (i != 0 && _PhoneNum[i] == ' ')
                continue;
            std::cout << "Invalid Phone Number\n";
            _PhoneNum = "";
            break;
        }
    }

    while (_Secret.empty())
    {
        std::cout << "And your darkest secret:\n";
        if (!std::getline(std::cin, _Secret))
            return false;
    }
    return true;
}