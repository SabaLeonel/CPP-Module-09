#include "RPN.hpp"

Rpn::Rpn() {}
Rpn::~Rpn() {}

Rpn::Rpn(const Rpn &other)
{
    _stack = other._stack;
}

Rpn &Rpn::operator=(const Rpn &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}


void printError(const std::string &msg)
{
    std::cerr << "Error: " << msg << std::endl;
}

void Rpn::bigmanting(const std::string &str)
{
    std::istringstream iss(str);
    std::string token;
    std::stack<int> _stack;

    try
    {
        while (iss >> token)
        {
            if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1))
            {
                _stack.push(atoi(token.c_str()));
            }
            else if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                if (_stack.size() < 2)
                {
                    printError(str);
                    return;
                }
                int operand2 = _stack.top();
                _stack.pop();
                int operand1 = _stack.top();
                _stack.pop();

                switch (token[0])
                {
                case '+':
                    _stack.push(operand1 + operand2);
                    break;
                case '-':
                    _stack.push(operand1 - operand2);
                    break;
                case '*':
                    _stack.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0)
                    {
                        printError("Division by zero");
                        return;
                    }
                    _stack.push(operand1 / operand2);
                    break;
                }
            }
            else
            {
                printError("Invalid token");
                return;
            }
        }

        if (_stack.size() != 1)
        {
            printError("Invalid expression");
            return;
        }
        int result = _stack.top();
        _stack.pop();
        std::cout << "The result of " << str << " is: " << result << std::endl;
    }
    catch (std::exception &e)
    {
        printError(str);
    }
}