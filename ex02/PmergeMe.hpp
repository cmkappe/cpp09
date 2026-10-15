#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>

static const char* RESET = "\033[0m";
static const char* BOLD = "\033[1m";
static const char* CYAN = "\033[36m";
static const char* GREEN = "\033[32m";
static const char* RED = "\033[31m";
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

// checks whether the current bound needs to be adjusted based on the next group in the original container and the current main chain
template <typename T>
static size_t checkDistanceOfAofNplusOne(const T &container, size_t bounds, size_t n,
    const std::vector<unsigned long> &main)
{
    size_t temp = 0;

    for (size_t i = n - 1; i < container.size(); i += n)
    {
        if (bounds == container[i]
            && i + 2 * n < container.size())
            temp = container[i + 2 * n];
    }

    if (temp == 0)
        return 0;

    for (size_t i = n - 1; i < main.size(); i += n)
    {
        if (i + n >= main.size())
            return 0;

        if (main[i] == bounds && temp != main[i + n])
            return temp;
    }

    return 0;
}

template <typename T>
size_t findGroupBoundBefore(const T &container, size_t pendingValue, size_t n) {
    // std::cout << "n = " << n << std::endl;
    for (size_t i = n - 1; i < container.size(); i += n)
    {
        if (pendingValue == container[i])
            return container[i - n];
    }
    return 0;
}

template <typename T>
void jacob(T &container, unsigned long n){
    // std::cout << "Entering jacob(): n = " << n << ", size = " << container.size() << std::endl;

    if (n > container.size())
        return;

    if (n != 1) {
        auto containerParticipants = container.size() - container.size() % n;

        for (size_t i = n - 1; i < containerParticipants; i += n) {
            size_t offset = n / 2;
            // std::cout << "Offset: " << offset << std::endl;
            // Compare the groups and swap if necessary
            if (i % n == n - 1) {
                // ++comparisons;
                if (container[i - offset] > container[i])
                {
                    for (size_t temp = i; temp > i - offset; --temp){
                        std::swap(container[temp], container[temp - offset]);
                    }
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
        // std::cout << "returning: n = " << n << std::endl;
        return;
    }

    n = n >> 1;
    // std::cout << "going back to lvl: n = " << n << std::endl;

    // std::vector<unsigned long> main;
    // std::vector<unsigned long> pending;

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
    /* std::cout << YELLOW << "\nmain: " << RESET;
        for (size_t i = 0; i < main.size(); ++i)
            std::cout << main[i] << " ";

        std::cout << CYAN << "\npending: " << RESET;
        for (size_t i = 0; i < pending.size(); ++i)
            std::cout << pending[i] << " ";
        std::cout << std::endl; */

    // Insert pending groups in Jacobsthal order

    /*  counter         which pending group we're looking at
    startingBounds  where the search through main begins
    endingBounds    identifies upper bound for inserting pending element
    comparingIndex  identifies which element in pending we are trying to insert */
    int counter = 1;
    size_t startingBounds = n - 1;
    size_t endingBounds;
    size_t comparingIndex = 0;

    int jacobIndex = 2;
    int Jnum = jacobNumber(jacobIndex);

    while (!pending.empty()){
        // Calculate index of next pending group
        // Jacobsthal numbers determine insertion order
        long int temp = static_cast<long int>(Jnum - counter) * static_cast<long int>(n) - 1;

        // boundary reached, next boundary in the following step
        if (temp < 0)
    {
        // current Jacobsthal group is finished, move to the next
        counter = Jnum;
        Jnum = jacobNumber(++jacobIndex);

        // Calculate the index for the new group
        temp = static_cast<long int>(Jnum - counter) * static_cast<long int>(n) - 1;

        // Move backwards until the index is inside pending
        while (temp >= static_cast<long int>(pending.size())) {
            counter++;
            temp = static_cast<long int>(Jnum - counter) * static_cast<long int>(n) - 1;
        }
        comparingIndex = static_cast<size_t>(temp);
    }
    else {
        comparingIndex = static_cast<size_t>(temp);

        // If the index exceeds pending, use its last available element
        while (comparingIndex >= pending.size())
            comparingIndex--;
    }

        // keep index in pending
        while (comparingIndex >= pending.size())
            comparingIndex--;

        // find pendign element and its upper bound
        // std::cout << "Next pending index: " << comparingIndex << std::endl;
        endingBounds = findGroupBoundBefore(container, pending[comparingIndex], n);
        
        // std::cout << "Pending value: " << pending[comparingIndex] << std::endl;
        // std::cout << "Ending bound: " << endingBounds << std::endl;
        
        bool inserted = false;

        // search through main for insertion position
        for (size_t k = startingBounds; k < main.size(); k += n){

            // auto posForInsert = main.begin() + k - n + 1;
            auto posForInsert = main.begin() + k - n + 1;
            auto groupStartingPos = pending.begin() + comparingIndex - n + 1;
            auto groupLastPos = pending.begin() + comparingIndex + 1;
            auto posForInsertAfterBounds = main.begin() + k + 1;

            // check if bound needs to be adjusted because of relationship between neighbouring groups
            size_t offsetOfBounds = checkDistanceOfAofNplusOne(container, endingBounds, n, main);

            if (offsetOfBounds != 0)
                endingBounds = offsetOfBounds;
            
            // std::cout << "Comparing pending " << pending[comparingIndex] << " with main[" << k << "] = " << main[k] << std::endl;
            // ++comparisons;
            // if pending element is smaller than the current main element, insert it before that position
            if (pending[comparingIndex] < main[k]) {
                if (n != 1) {
                    // insert entire pending group
                    main.insert(posForInsert, groupStartingPos, groupLastPos);
                    // remove inserted group from pending
                    pending.erase(groupStartingPos, groupLastPos);
                }
                else {
                    // if group size is 1, insert a single element
                    main.insert(posForInsert, pending[comparingIndex]);
                    pending.erase(pending.begin() + comparingIndex);
                }
                inserted = true;
                break;
            }

            // if the current element is the upper bound, insert the pending group immediately after it
            else if (main[k] == endingBounds){
                // ++comparisons;
                if (n != 1) {
                    // std::cout << "Inserting before index " << k << std::endl;
                    main.insert(
                        posForInsertAfterBounds, groupStartingPos, groupLastPos);
                    pending.erase(groupStartingPos, groupLastPos);
                }
                else {
                    // main.insert(posForInsertAfterBounds, endingBounds);
                    main.insert(posForInsertAfterBounds, pending[comparingIndex]);
                    pending.erase(pending.begin() + comparingIndex);
                }
                inserted = true;
                break;
            }  
        }    
        if (!inserted) {
            // std::cout << "No insertion occurred for index " << comparingIndex << std::endl;
            return;
        }

        /* if (!pending.empty()){
        std::cout << "Pending after insertion: ";
        for (size_t i = 0; i < pending.size(); ++i)
            std::cout << pending[i] << " ";
        std::cout << std::endl;
            } */
    }

    int nonParticipating = container.size() % n;

    if (n != 1 || nonParticipating != 0){
        while (nonParticipating--)
        {
            main.push_back(
                container[container.size() - nonParticipating - 1]);
        }
    }

    // copy sorted main chain back into the original container
    container.clear();
    container.insert(container.end(), main.begin(), main.end());
}
