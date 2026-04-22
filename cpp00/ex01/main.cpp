#include <iostream>
#include <limits>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int    main()
{
    PhoneBook   phonebook;

    std::cout << "Welcome to your phone book\n";

    while (true)
    {
        std::cout << "Select an option: (ADD, SEARCH, EXIT)\n";
        std::string sel;
        if (!(std::cin >> sel))
            break;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (sel == "ADD")
        {
            if (!phonebook.add())
                break;
        }
        else if (sel == "SEARCH")
        {
            if (!phonebook.search())
                break;
        }
        else if (sel == "EXIT")
            break;
        else
            std::cout << "Invalid input\n";
    }
    return (0);
}