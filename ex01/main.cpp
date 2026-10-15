#include "RPN.hpp"

#include <iostream>
#include <exception>

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        RPN calculator;
        std::cout << calculator.calculate(av[1]) << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << RED << "Error: " << RESET << e.what() << std::endl;
        return 1;
    }

    return 0;
}
