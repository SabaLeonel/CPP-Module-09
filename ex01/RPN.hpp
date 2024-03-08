#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stack>
#include <iterator>
#include <stdexcept>
#include <random>

#define BIGMANTING_INT 2147483647


class Rpn{
    public:
        Rpn();
        ~Rpn();
        Rpn(const Rpn& other);
        Rpn &operator=(const Rpn& other);
        void bigmanting(std::string const &str);
    private:
        std::stack<int> _stack;
};

#endif