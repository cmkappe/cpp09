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

    if (n != 1) {
        auto containerParticipants = container.size() - container.size() % n;

        for (size_t i = n - 1; i < containerParticipants; i += n) {
            size_t offset = n / 2;
            std::cout << "Offset: " << offset << std::endl;
            // Compare the groups and swap if necessary
            if (i % n == n - 1 && container[i - offset] > container[i])
            {
                for (size_t temp = i; temp > i - offset; --temp){
                    std::swap(container[temp], container[temp - offset]);
                }
            }
            /* if (container[i - offset] > container[i])
            {
                // Swap the two adjacent groups
            } */
        }
    }

    // doubles value, so /2
    n = n << 1;

    jacob(container, n);

    if (n > container.size()){
        std::cout << "returning: n = " << n << std::endl;
        return;
    }

    n = n >> 1;
    std::cout << "going back to lvl: n = " << n << std::endl;

    // Rebuild the main and pending chains

    // Insert pending groups in Jacobsthal order

    // Restore any leftover elements
}