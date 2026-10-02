#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
    std::ifstream file("data.csv");
    if ( !file.is_open() )
    {
        std::cerr << "Error: Could not open db." << std::endl;
    }

    std::string line;
    std::getline( file, line );
    while ( std::getline( file, line ) )
    {
        std::string date = line.substr( 0, line.find(',') );
        std::string price = line.substr( line.find(',') + 1 );
        _data[date] = atof( price.c_str() );
    }

    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _data = other._data;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}

void BitcoinExchange::process( const std::string& filename )
{
    std::ifstream file(filename.c_str());
    if ( !file.is_open() )
    {
        std::cerr << "Error: Could not open input file." << std::endl;
        return ;
    }

    std::string line;
    std::getline( file, line );
    while ( std::getline( file, line ) )
    {
        if ( line.find('|') == std::string::npos )
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr( 0, line.find('|') - 1 );
        if ( !validateDate( date ) )
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float value = atof( line.substr( line.find('|') + 2 ).c_str() );
        if ( !validateValue(value) )
        {
            if (value < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else
                std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator it = _data.lower_bound( date );
        if ( it == _data.begin() && it->first != date )
            std::cerr << "Error: bad input => " << date << std::endl;
        else
        {
            if ( it == _data.end() || it->first != date )
                --it;
            std::cout << date << " => " << value << " = " <<it->second * value << std::endl;
        }
    }

    file.close();
}

bool BitcoinExchange::validateDate(const std::string& date)
{
    if ( date.size() != 10 )
        return ( 0 );

    if (date[4] != '-' || date[7] != '-')
       return ( 0 );

    for ( int i = 0; i < 10; i++ )
    {
        if (i == 4 || i == 7)
            continue;
        if ( !std::isdigit(date[i]) )
            return ( 0 );
    }

    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    if ( month < 1 || month > 12 )
        return ( 0 );
    if ( day < 1 || day > 31 )
        return ( 0 );

    return ( 1 );
}

bool BitcoinExchange::validateValue(float value)
{
    if (value < 0)
        return ( 0 );
    if (value > 1000)
        return ( 0 );
    return ( 1 );
}
