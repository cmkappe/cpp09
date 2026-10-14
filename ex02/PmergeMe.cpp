
#include "PmergeMe.hpp"

#include <iostream>
#include <cmath>

/* template <typename T>
static size_t findAofNIndex(const T container, size_t pendingValue, size_t n) {
  // std::cout << "n = " << n << std::endl;
  for (auto i = n - 1; i < container.size(); i += n) {
    if (pendingValue == container[i]) {
      return container[i - n];
    }
  }
  return 0;
} */

/* template <typename T>
static size_t
checkDistanceOfAofNplusOne(const T container, size_t bounds, size_t n,
                           const std::vector<unsigned long> main) {
    size_t temp = 0;
    for (auto i = n - 1; i < container.size(); i += n) {
        if (bounds == container[i] && i + 2 * n < container.size()) {
        temp = container[i + 2 * n];
        }
    }
    if (temp == 0) {
        return 0;
    }

    for (size_t i = n - 1; i < main.size(); i += n) {
        if (i + n >= main.size()) {
        return 0;
        }
        if (main[i] == bounds && temp != main[i + n]) {
        return temp;
        }
    }

    return 0;
    } */

    int jacobNumber(int n){
        return std::round((std::pow(2, n + 1) + std::pow(-1, n)) / 3);
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

