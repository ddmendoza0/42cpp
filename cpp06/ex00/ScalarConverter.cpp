#include "ScalarConverter.hpp"

void ScalarConverter::convert( const std::string& literal )
{
    /*if ( std::isinf( atof(literal.c_str()) ) )
        std::cout << "Conversion from inf not posible" << std::endl;
    else if ( literal.isnan() )
        std::cout << "Conversion from nan not posible" << std::endl;
    else */if ( ( literal[0] == '\'' ) && ( literal[literal.size()-1] == '\'' ) )
        std::cout << "is char" << std::endl;
    else if ( ( literal[literal.size()] == 'f' ) && ( literal.find(".") ) )
        std::cout << "is float" << std::endl;
    else if ( literal.find(".") )
        std::cout << "is double" << std::endl;
    else
        std::cout << "is int" << std::endl;


}

