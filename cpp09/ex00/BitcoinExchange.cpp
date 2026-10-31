#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
    std::ifstream file("data.csv");
    if ( !file.is_open() )
        throw std::runtime_error("Error: could not open database file");

    std::string line;
    std::getline( file, line );
    while ( std::getline( file, line ) )
    {
        if ( line.find(',') == std::string::npos )
            continue ;
        std::string date = line.substr( 0, line.find(',') );
        std::string price = line.substr( line.find(',') + 1 );
        _data[date] = atof( price.c_str() );
    }

    if ( _data.empty() )
        throw std::runtime_error("Error: empty db.");

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
        throw std::runtime_error("Error: could not open input file.");

    std::string line;
    std::getline( file, line );
    while ( std::getline( file, line ) )
    {
        size_t sep = line.find( " | " );
        if ( sep == std::string::npos )
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr( 0, sep );
        std::string valueStr = line.substr( sep + 3 );

        if ( !isValidDate( date ) || !isValidNumber( valueStr ) )
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float value = atof( valueStr.c_str() );
        if ( !isValidValue(value) )
        {
            if (value < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else
                std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        if ( value == 0 )
            value = 0;

        std::map<std::string, float>::iterator it = _data.lower_bound( date );
        if ( it == _data.begin() && it->first != date )
            std::cerr << "Error: bad input => " << line << std::endl;
        else
        {
            if ( it == _data.end() || it->first != date )
                --it;
            std::cout << date << " => " << value << " = " <<it->second * value << std::endl;
        }
    }

    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) const
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

    int year  = atoi( date.substr(0, 4).c_str() );
    int month = atoi( date.substr(5, 2).c_str() );
    int day   = atoi( date.substr(8, 2).c_str() );

    if ( month < 1 || month > 12 || day < 1 )
        return ( 0 );

    int maxDay = 31;
    if ( month == 4 || month == 6 || month == 9 || month == 11 )
        maxDay = 30;
    else if ( month == 2 )
    {
        bool bisiesto = ( year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0;
        if (bisiesto)
            maxDay = 29;
        else
            maxDay = 28;
    }

    return ( day <= maxDay );
}

bool BitcoinExchange::isValidValue(float value) const
{
    if (value < 0)
        return ( 0 );
    if (value > 1000)
        return ( 0 );
    return ( 1 );
}

bool BitcoinExchange::isValidNumber( const std::string& s ) const
{
    size_t i = 0;
    bool digits = false;
    bool dot = false;

    if ( s.empty() )
        return ( false );
    if ( s[i] == '-' || s[i] == '+' )
        i++;
    for ( ; i < s.size(); i++ )
    {
        if ( std::isdigit( s[i] ) )
            digits = true;
        else if ( s[i] == '.' && !dot )
            dot = true;
        else
            return ( false );
    }
    return ( digits );
}
