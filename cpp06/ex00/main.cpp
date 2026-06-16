#include "ScalarConverter.hpp"

int main( int argc, char **argv )
{
    //std::string input;
    //if (argc != 2 || !argv[1])
        //return (1);
    //input = argv[1];
    
    (void)argc;
    (void)argv;

    std::cout << "--- char literals ---" << std::endl;
    ScalarConverter::convert("'a'");
    ScalarConverter::convert("'Z'");

    std::cout << "\n--- int literals ---" << std::endl;
    ScalarConverter::convert("0");
    ScalarConverter::convert("42");
    ScalarConverter::convert("-42");
    ScalarConverter::convert("2147483647");   // INT_MAX
    ScalarConverter::convert("-2147483648");  // INT_MIN
    ScalarConverter::convert("2147483648");   // overflow

    std::cout << "\n--- float literals ---" << std::endl;
    ScalarConverter::convert("0.0f");
    ScalarConverter::convert("4.2f");
    ScalarConverter::convert("-4.2f");

    std::cout << "\n--- double literals ---" << std::endl;
    ScalarConverter::convert("0.0");
    ScalarConverter::convert("4.2");
    ScalarConverter::convert("-4.2");

    std::cout << "\n--- special literals ---" << std::endl;
    ScalarConverter::convert("nan");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("-inff");

    std::cout << "\n--- non displayable char ---" << std::endl;
    ScalarConverter::convert("0");

    std::cout << "\n--- invalid literals ---" << std::endl;
    ScalarConverter::convert("banana");
    ScalarConverter::convert("42abc");
    ScalarConverter::convert("");

    return ( 0 );
};