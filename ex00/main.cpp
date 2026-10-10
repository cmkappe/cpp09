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



bool    checkArguments(int ac, char **av){

    for (int i = 1; i <= ac; i++){
        std::string  date;
        double  value;
        if (!date = validateLine(av[i]))
            throw std::exception("invalid argument");
        int line = av[i];
            validateDate(date, line);

    }
}



int main (int ac, char **av) {

    if (ac < 2){
        std::cout << "Error: could not open file." << std::endl;
        return(1);
    }

    BitcoinExchange table;

    if (!checkArguments(ac, av)){
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    if (!table.loadDatabase("data.csv")){
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    table.processInput();


    return 0;
}