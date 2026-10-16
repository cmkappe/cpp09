#include "PmergeMe.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <chrono>
#include <iomanip>


int main (int ac, char **av){
    
    if (ac < 2){
        std::cerr << RED <<"Usage: ./PmergeMe <numbers...>" << RESET << std::endl;
        return 1;
    }

    std::vector<unsigned long> numbers;
    std::deque<unsigned long> dequeNumbers(numbers.begin(), numbers.end());

    for (int i = 1; i < ac; ++i) {
    // reject empty arguments and anything other than digits
    if (av[i][0] == '\0') {
        std::cerr << RED << "Error!\nUsage: ./PmergeMe <numbers...>" << RESET << std::endl;
        return 1;
    }

    for (int j = 0; av[i][j] != '\0'; ++j) {
        if (!std::isdigit(static_cast<unsigned char>(av[i][j]))) {
            std::cerr << RED << "Error: Invalid argument!\nUsage: ./PmergeMe <numbers...>" << RESET << std::endl;
            return 1;
        }
    }

    // convert to number
    errno = 0;
    char *end = NULL;
    unsigned long value = std::strtoul(av[i], &end, 10);

    // reject overflow, zero, and values above INT_MAX
    if (errno == ERANGE || *end != '\0' || value == 0
        || value > static_cast<unsigned long>(INT_MAX)){
        std::cerr << RED << "Error: Invalid value!\nUsage: ./PmergeMe <numbers...>" << RESET << std::endl;
        return 1;
    }

    numbers.push_back(value);
    dequeNumbers.push_back(value);
}

    std::cout << CYAN << BOLD << "\n------------ Vector ------------" << RESET << std::endl;
    std::cout << BOLD << "\nVector before sorting: " << RESET;
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    // size_t comparisons = 0;

    std::chrono::steady_clock::time_point vectorStart = std::chrono::steady_clock::now();
    jacob(numbers, 1);
    std::chrono::steady_clock::time_point vectorEnd = std::chrono::steady_clock::now();
    double vectorTime = std::chrono::duration<double, std::micro>(vectorEnd - vectorStart).count();

    std::cout << std::boolalpha << "\nIs the container sorted: " << std::is_sorted(numbers.begin(), numbers.end()) << std::endl;
    std::cout << BOLD << GREEN << "\nResult: " << RESET;
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << "\n" << std::endl;
    // std::cout << YELLOW << "Total comparisons: " << comparisons << RESET << "\n" << std::endl;


    std::cout << CYAN << BOLD << "\n------------ Deque ------------" << RESET << std::endl;
    std::cout << BOLD << "\nDeque before sorting: " << RESET;
    for (size_t i = 0; i < dequeNumbers.size(); ++i)
        std::cout << dequeNumbers[i] << " ";
    std::cout << std::endl;

    // size_t dequeComparisons = 0;
    
    std::chrono::steady_clock::time_point dequeStart = std::chrono::steady_clock::now();
    jacob(dequeNumbers, 1);
    std::chrono::steady_clock::time_point dequeEnd = std::chrono::steady_clock::now();
    double dequeTime = std::chrono::duration<double, std::micro>(dequeEnd - dequeStart).count();

    std::cout << std::boolalpha << "\nDeque sorted: " << std::is_sorted(dequeNumbers.begin(), dequeNumbers.end()) << std::endl;

    std::cout << BOLD << GREEN << "Deque result: " << RESET;
    for (size_t i = 0; i < dequeNumbers.size(); ++i)
        std::cout << dequeNumbers[i] << " ";
    std::cout << std::endl;
    // std::cout << YELLOW << "Total comparisons: " << dequeComparisons << RESET << std::endl;

    std::cout << std::fixed << std::setprecision(3);

    std::cout << "Time to process a range of " << numbers.size() << " elements with std::vector: "
            << vectorTime << " microseconds" << std::endl;

    std::cout << "Time to process a range of " << dequeNumbers.size() << " elements with std::deque: "
            << dequeTime << " microseconds" << std::endl;

    return 0;
}

/* int main(void) { 

    // _________________ Vector 1 _________________
    std::vector<unsigned long> v1 = {9, 5, 3, 7, 1};

    std::cout << BOLD << YELLOW << "\nOriginal: " << RESET;
    for (size_t i = 0; i < v1.size(); ++i)
        std::cout << v1[i] << " ";
    std::cout << "\n" << std::endl;

    jacob(v1, 1);
    std::cout << std::boolalpha << "Is the container sorted: " << std::is_sorted(v1.begin(), v1.end()) << std::endl;


    std::cout << BOLD << GREEN << "\nResult: " << RESET;
    for (size_t i = 0; i < v1.size(); ++i)
        std::cout << v1[i] << " ";
    std::cout << "\n" << std::endl;


    // _________________ Vector 2 _________________
    std::vector<unsigned long> v2 = {12, 4, 9, 2, 15, 7, 1};

    std::cout << BOLD << YELLOW << "\nOriginal: " << RESET;
    for (size_t i = 0; i < v2.size(); ++i)
        std::cout << v2[i] << " ";
    std::cout << "\n" << std::endl;

    jacob(v2, 1);
    std::cout << std::boolalpha << "Is the container sorted: " << std::is_sorted(v2.begin(), v2.end()) << std::endl;


    std::cout << BOLD << GREEN << "\nResult: " << RESET;
    for (size_t i = 0; i < v2.size(); ++i)
        std::cout << v2[i] << " ";
    std::cout << "\n" << std::endl;


    // _________________ Duplicate _________________
    std::vector<unsigned long> dup = {5, 3, 5, 1, 3, 1};

    std::cout << BOLD << YELLOW << "\nOriginal: " << RESET;
    for (size_t i = 0; i < dup.size(); ++i)
        std::cout << dup[i] << " ";
    std::cout << "\n" << std::endl;

    jacob(dup, 1);
    std::cout << std::boolalpha << "Is the container sorted: " << std::is_sorted(dup.begin(), dup.end()) << std::endl;


    std::cout << BOLD << GREEN << "\nResult: " << RESET;
    for (size_t i = 0; i < dup.size(); ++i)
        std::cout << dup[i] << " ";
    std::cout << "\n" << std::endl;

    return 0;

} */
