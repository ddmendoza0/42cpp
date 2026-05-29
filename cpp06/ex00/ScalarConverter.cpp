#include "ScalarConverter.hpp"

bool    ScalarConverter::isValidLiteral(const std::string& literal)
{
    // check if char literal
    if ( literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'' )
        return ( true );

    // check if special literal
    if ( literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff" )
        return ( true );

    // check if valid int (only digits with optional sign)
    int i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    for ( i; i < (int)literal.size(); i++ )
    {
        if ( !isdigit( literal[i] ) )
            break ;
    }
    if (i == (int)literal.size())
        return ( true );

    // check if valid float (digits, one dot, ends with f)
    // check if valid double (digits, one dot, no f)
    bool    maxDot = false;
    i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    for ( i; i < (int)literal.size(); i++ )
    {
        if ( literal[i] == '.' && !maxDot )
        {
            maxDot = true;
            i++;
        }
        if ( !isdigit( literal[i] ) )
            break;
    }
    if (literal[i] == 'f')
            i++;
    if (i == (int)literal.size() && maxDot)
        return ( true );

    std::cout << "Non valid literal" << std::endl;
    return ( false );
}

double  ScalarConverter::parseToDouble(const std::string& literal)
{
    if ( ( literal[0] == '\'' ) && ( literal[literal.size()-1] == '\'' ) )
        return ( static_cast<double>( literal[1] ) );
    else
        return ( atof( literal.c_str() ) );
}

void ScalarConverter::convert( const std::string& literal )
{
    if ( !isValidLiteral( literal ) )
        return ;

    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return ;
    }
    if (literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return ;
    }

    double  value = parseToDouble( literal );

    //DISPLAYS + STATIC CAST
    // char
    char c = static_cast<char>(value);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    // int
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    // float
    float f = static_cast<float>(value);
    std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;

    // double
    std::cout << std::fixed << std::setprecision(1) << "double: " << value << std::endl;
}

