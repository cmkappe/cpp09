/*

1. Create main to take arguements and error check them!
2. Read the data.csv and load it in the memory using a Map container.
3. Open the input.txt file (arg name) read line by line.
    a. error check line
    b. look for the date in the database
    c. if    i.) date is a match them multiply the value and go next line.
       else ii.) find the closest date before the given date and do calculations
*/

#include "BitcoinExchange.hpp"

#include <iterator> 
#include <stdexcept>
#include <iostream>
#include <string>

/* 
• Each line in this file must use the following format: "date | value".
• A valid date will always be in the following format: Year-Month-Day.
• A valid value must be either a float or a positive integer, between 0 and 1000.
 */




int main (int ac, char **av) {

    if (ac != 2){
        std::cout << "Error: could not open file." << std::endl;
        return(1);
    }

    BitcoinExchange table;

    if (!table.loadDatabase("data.csv")){
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    table.processInput(av[1]);


    return 0;
}