#pragma once

# include <string>
# include <cmath>
# include <cctype>
# include <limits>
# include <iostream>
# include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter(void);

        static bool    isValidLiteral(const std::string& literal);
        static double  parseToDouble(const std::string& literal);


    public:
        static void convert(const std::string& literal);

};
