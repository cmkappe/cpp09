#include "RPN.hpp"

#include <sstream>
#include <stdexcept>
#include <stack>

RPN::RPN() {}

RPN::~RPN() {}


int RPN::calculate(const std::string &expression) const
{
    std::istringstream tokens(expression);
    std::string token;
    std::stack<int> numbers;

    while (tokens >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
        
        // An operator needs two operands
        if (numbers.size() < 2)
            throw std::runtime_error("Invalid expression");

        // The most recently pushed number is the right operand
        int right = numbers.top();
        numbers.pop();

        // The next number is the left operand
        int left = numbers.top();
        numbers.pop();

        int result;

        if (token == "+")
            result = left + right;
        else if (token == "-")
            result = left - right;
        else if (token == "*")
            result = left * right;
        else
        {
            // Division by zero is a nono
            if (right == 0)
                throw std::runtime_error("Division by zero");

            result = left / right;
        }

        numbers.push(result);

        }
        else {
            // check whether token is a single digit
            if (token.length() != 1 || token[0] < '0' || token[0] > '9')
                throw std::runtime_error("Invalid token");

            // Convert to int
            int number = token[0] - '0';

            numbers.push(number);
        }
    }

    // A valid expression must leave exactly one result on the stack
    if (numbers.size() != 1)
        throw std::runtime_error("Invalid expression");

    return numbers.top();
}
