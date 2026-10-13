#pragma once

#include <iostream>


/* 1. Pair and compare groups
Compare the larger elements of adjacent groups and swap groups when necessary soo that the higher number comes second (b1 a1)

2. Recurse with doubled group size
Call jacob(container, n * 2) recurisevly to sort increasingly large groups

3. Build MAIN and PENDING chains
Separate the groups that are already in the main chain from the groups waiting for insertion
b to pending, a to main

4. Insert in Jacobsthal order
Insert pending groups into bounded portions of the main chain, then handle leftover elements */

//pMerge: utility class, dosn't hold data or actual object

class pMerge {
    private:

        pMerge() = delete;
        ~pMerge() = delete;
        pMerge(int container) = delete;
        pMerge(const pMerge &other) = delete;
        pMerge &operator=(const pMerge &other) = delete;

    public:
    
        // merge(T container);
        template <typename T>
            void jacob(T &container, unsigned long n);
};

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