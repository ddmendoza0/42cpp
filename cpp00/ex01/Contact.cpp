#include "Contact.hpp"
#include <iostream>

Contact::Contact() {}
Contact::~Contact() {}

std::string Contact::getFirstName() const { return _FirstName; }
std::string Contact::getLastName() const { return _LastName; }
std::string Contact::getNickName() const { return _NickName; }
std::string Contact::getPhoneNum() const { return _PhoneNum; }
std::string Contact::getSecret() const {return _Secret; }

static std::string sanitize(const std::string &str)
{
    std::string clean;
    clean.reserve(str.length());
    for (size_t i = 0; i < str.length(); i++)
    {
        unsigned char c = str[i];
        if (std::iscntrl(c))
            clean += ' ';
        else
            clean += c;
    }
    return ( clean );
}

static bool isBlank(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isspace(static_cast<unsigned char>(str[i])))
            return false;
    }
    return true;
}

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
        _FirstName = sanitize(_FirstName);
        if (isBlank(_FirstName))
            _FirstName = "";
    }

    while (_LastName.empty())
    {
        std::cout << "Introduce Last Name:\n";
        if (!std::getline(std::cin, _LastName))
            return false;
        _LastName = sanitize(_LastName);
        if (isBlank(_LastName))
            _LastName = "";
    }

    while (_NickName.empty())
    {
        std::cout << "Introduce Nick Name:\n";
        if (!std::getline(std::cin, _NickName))
            return false;
        _NickName = sanitize(_NickName);
        if (isBlank(_NickName))
            _NickName = "";
    }

    while (_PhoneNum.empty())
    {
        std::cout << "Introduce Phone Number:\n";
        if (!std::getline(std::cin, _PhoneNum))
            return false;
        _PhoneNum = sanitize(_PhoneNum);
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
        _Secret = sanitize(_Secret);
    }
    return true;
}