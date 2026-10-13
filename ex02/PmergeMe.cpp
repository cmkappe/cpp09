
#include "PmergeMe.hpp"

#include <iostream>
#include <cmath>

int jacobNumber(int n)
{
    return std::round(
        (std::pow(2, n + 1) + std::pow(-1, n)) / 3
    );
}



/* template <typename T>
static void jacob(T &container, unsigned long n)
{
    std::cout << "Entering jacob(): n = " << n << ", size = " << container.size() << std::endl;


    if (n > container.size())
        return;

    if (n != 1) {
        auto containerParticipants = container.size() - container.size() % n;

        for (size_t i = n - 1; i < containerParticipants; i += n) {
            size_t offset = n / 2;

            // Compare the groups and swap if necessary.
        }
    }

    // doubles value, so /2
    n = n << 1;

    jacob(container, n);

    if (n > container.size()){
        std::cout << "Returning: n = " << n << std::endl;
        return;
    }

    n = n >> 1;

    // Rebuild the main and pending chains

    // Insert pending groups in Jacobsthal order

    // Restore any leftover elements
} */