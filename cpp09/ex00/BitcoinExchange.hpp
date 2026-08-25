#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float>    _data;

        bool validateDate(const std::string& date);
        bool validateValue(float value);

    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange(void);

        void process(const std::string& filename);


};