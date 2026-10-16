
#include "PmergeMe.hpp"

#include <iostream>
#include <cmath>

// Jacobsthal numbers gives the order which pending groups to inserted next into main chain
// formular: J(n) = (2^(n + 1) + (-1)^n) / 3.
int jacobNumber(int n) {
    return std::round((std::pow(2, n + 1) + std::pow(-1, n)) / 3);
}
