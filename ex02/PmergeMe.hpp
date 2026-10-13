#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

static const char* RESET = "\033[0m";
static const char* BOLD = "\033[1m";
static const char* CYAN = "\033[36m";
static const char* GREEN = "\033[32m";
//static const char* RED = "\033[31m";
static const char* YELLOW = "\033[33m";

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

// MAIN contains the elements/groups already being used as the sorted insertion chain
// PENDING contains the elements/groups that still need to be inserted into main

class pMerge {
    private:

        pMerge() = delete;
        ~pMerge() = delete;
        pMerge(int container) = delete;
        pMerge(const pMerge &other) = delete;
        pMerge &operator=(const pMerge &other) = delete;

    public:
        
        // merge(T container);
        
};

int jacobNumber(int n);

template <typename T>
void jacob(T &container, unsigned long n)
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

    std::vector<unsigned long> main;
    std::vector<unsigned long> pending;

    size_t j = 0;

    // first two groups go into main
    while (j < n * 2 && j < container.size())
        main.push_back(container[j++]);

    // remaining complete groups alternate between pending and main
    size_t participating = container.size() - (container.size() % n);
    bool stop = false;

    while (j < participating){
        for (size_t k = 0; k < n && j < participating; ++k, ++j) {
            if (stop)
                main.push_back(container[j]);
            else
                pending.push_back(container[j]);
        }
        stop = !stop;
    }  

    // Rebuild the main and pending chains
    std::cout << YELLOW << "\nmain: " << RESET;
        for (size_t i = 0; i < main.size(); ++i)
            std::cout << main[i] << " ";

        std::cout << CYAN << "\npending: " << RESET;
        for (size_t i = 0; i < pending.size(); ++i)
            std::cout << pending[i] << " ";
        std::cout << std::endl;

    // Insert pending groups in Jacobsthal order

    int counter = 1;
    size_t comparingIndex = 0;

    int jacobIndex = 2;
    int Jnum = jacobNumber(jacobIndex);

    while (!pending.empty())
    {
        long int temp = static_cast<long int>(Jnum - counter)
                    * static_cast<long int>(n) - 1;

        if (temp < 0){
            break; 
        }

        comparingIndex = static_cast<size_t>(temp);

        while (comparingIndex >= pending.size())
            comparingIndex--;

        std::cout << "Next pending index: "
                << comparingIndex << std::endl;

        break;
    }

/*  counter         which pending group we're looking at
    startingBounds  where the search through main begins
    endingBounds    identifies upper bound for inserting pending element
    comparingIndex  identifies which element in pending we are trying to insert */
    /* int counter = 1;
    // size_t startingBounds = n - 1;
    // size_t endingBounds;
    size_t comparingIndex;

    int jacobIndex = 2;
    int Jnum = jacobNumber(jacobIndex);

    while (pending.size() != 0)
    {
        size_t jprev = Jnum;
        long int temp = (Jnum - counter) * n - 1;

        if (temp < 0){
            counter = jprev;
            Jnum = jacobNumber(++jacobIndex);

            comparingIndex = (Jnum - counter) * n - 1;

            while (comparingIndex >= pending.size()){
                counter++;
                comparingIndex = (Jnum - counter) * n - 1;
            }
        }
        else {
            comparingIndex = temp;

            while (comparingIndex >= pending.size())
                comparingIndex--;
        }

    }
    std::cout << "Next pending index: " << comparingIndex << std::endl; */
    // Actual insertion comes next.

    // Restore any leftover elements
}
