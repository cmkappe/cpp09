#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

RPN::RPN() {}

RPN::~RPN() {}


int RPN::calculate(const std::string &expression) const
{
    std::istringstream tokens(expression);
    std::string token;

    while (tokens >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {

        }
        else {
            // check whether token is a single digit
            if (token.length() != 1
                || token[0] < '0' || token[0] > '9')
                throw std::runtime_error("Invalid token");


        }
    }

    return 0;
}
