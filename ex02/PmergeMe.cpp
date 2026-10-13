#include "PmergeMe.hpp"

#include <iostream>

template <typename T>
static void jacob(T &container, unsigned long n)
{
    std::cout << "Entering jacob(): n = " << n << ", size = " << container.size() << std::endl;


    if (n > container.size())
        return;

    if (n != 1)
    {
        // Compare adjacent groups of size n / 2
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
}