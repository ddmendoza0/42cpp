#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <cmath>
# include <cctype>
# include <limits>
# include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter(void);

        bool    isValidLiteral(const std::string& literal);
        double  parseToDouble(const std::string& literal);


    public:
        static void convert(const std::string& literal);

};

#endif