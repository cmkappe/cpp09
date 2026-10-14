
#include "PmergeMe.hpp"

#include <vector>
#include <string>
#include <iostream>


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


int main (int ac, char **av){
    
    if (ac < 2){
        std::cerr << "Usage: ./PmergeMe <numbers...>" << std::endl;
        return 1;
    }

    std::vector<unsigned long> numbers;

    for (int i = 1; i < ac; ++i)
        numbers.push_back(std::strtoul(av[i], NULL, 10));

    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    jacob(numbers, 1);
    std::cout << std::boolalpha << "\nIs the container sorted: " << std::is_sorted(numbers.begin(), numbers.end()) << std::endl;
    std::cout << BOLD << GREEN << "\nResult: " << RESET;
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << "\n" << std::endl;

    return 0;
}