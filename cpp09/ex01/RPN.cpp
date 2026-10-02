#include "RPN.hpp"

RPN::RPN( void ) {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _stack = other._stack;
    return (*this);
}

RPN::~RPN(void) {}

int RPN::evaluate( const std::string& expression )
{
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token)
    {
        if ( std::isdigit(token[0]) )
            _stack.push(atoi(token.c_str()));
        else if ( token == "+" || token == "-" || token == "/" || token == "*" )
        {
            if ( _stack.size() < 2 )
                throw std::runtime_error("Error");
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();

            if ( token == "+" )
                _stack.push(a + b);
            else if ( token == "-" )
                _stack.push(a - b);
            else if ( token == "/" )
            {
                if ( b == 0 )
                throw std::runtime_error("Error");
                _stack.push(a / b);
            }
            else if ( token == "*" )
                _stack.push(a * b);
        }
        else
            throw std::runtime_error("Error");
    }

    if ( _stack.size() != 1 )
        throw std::runtime_error("Error");

    return ( _stack.top() );
}