
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

    std::vector<int> v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(9);
    v.push_back(7);
    v.push_back(4);

    jacob(v, 1);
    return 0;

}