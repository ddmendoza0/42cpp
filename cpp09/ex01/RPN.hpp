#pragma once
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN
{
    private:
        std::stack<int> _stack;

    public:
        RPN(void);
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN(void);

        int evaluate(const std::string& expression);

};