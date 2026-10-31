#pragma once
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float>    _data;

        bool isValidDate(const std::string& date) const;
        bool isValidValue(float value) const;
        bool isValidNumber( const std::string& s ) const;

    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange(void);

        void process(const std::string& filename);


};