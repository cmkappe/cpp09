
#include "PmergeMe.hpp"

#include <vector>
#include <string>
#include <iostream>


int main(void){
    
/*     std::vector<std::string> arg;

    if (ac < 3) {
        std::cerr << "Required a sequence of numbers more than 3" << std::endl;
        return -1;
    }

    for (int i = 1; av[i]; ++i) {
        arg.push_back(av[i]);
        jacob();
    } */

    std::vector<unsigned long> v = {9, 5, 3, 7};

    jacob(v, 1);

    std::cout << BOLD << GREEN << "\n\nResult: " << RESET;
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << "\n" << std::endl;

    return 0;

}