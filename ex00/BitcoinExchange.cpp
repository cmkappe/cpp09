#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>


// ________________  Constructor  ________________
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}


// ________________  Utils  ________________
static std::string trim(const std::string &str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    if (start == std::string::npos)
        return "";

    return str.substr(start, end - start + 1);
}


// ________________  Validation  ________________
bool BitcoinExchange::isValidDate(const std::string &date) {
    // date must have exactly ten characters, with dashes in positions 4 and 7
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    // every other character must be a digit
    for (size_t i = 0; i < date.length(); ++i) {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }
    
    // extract day, month & year and convert to int
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (month < 1 || month > 12 || day < 1)
        return false;
    
    // max days per month
    int days[] = {31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31};
        
    // need to account foor leap year
    bool leap = (year % 4 == 0
        && (year % 100 != 0 || year % 400 == 0));

    if (leap)
        days[1] = 29;

    if (day > days[month - 1])
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string &value, double &amount) {
    if (value.empty())
        return false;

    // end points to the first character that could not be converted
    char *end;
    double number = std::strtod(value.c_str(), &end);

    // reject strings that contain no number or extra characters
    if (end == value.c_str() || *end != '\0')
        return false;

    // reject special values like inf and nan
    if (!std::isfinite(number))
        return false;

/*     if (number < 0){
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    if (number > 1000){
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    } */

    amount = number;
    return true;
}




// ________________  Data Input  ________________

bool BitcoinExchange::loadDatabase(const std::string &path) {
    std::ifstream file(path.c_str());

    if (!file.is_open())
    {
        std::cerr << RED << "Error:" << RESET << " could not open database file." << std::endl;
        return false;
    }

    std::string line;

    // Skip the CSV header.
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t comma = line.find(',');

        if (comma == std::string::npos)
            continue;

        std::string date = line.substr(0, comma);
        std::string rateStr = line.substr(comma + 1);

        double rate = std::atof(rateStr.c_str());

        _rates.push_back(std::make_pair(date, rate));
    }
    std::cout << "\nLoaded " << YELLOW << BOLD << _rates.size() << RESET << " database entries." << std::endl;
    return true;
}


double BitcoinExchange::getExchangeRate(const std::string &date) const
{
    // most recent rate that is not later than the input date
    double rate = -1.0;

    // Go through the database in chronological order
    for (std::list<std::pair<std::string, double> >::const_iterator it
            = _rates.begin(); it != _rates.end(); ++it)
    {
        // Stop when the database date is later than the input date
        if (it->first > date)
            break;

        // valid rate
        rate = it->second;
    }

    // Returns -1 if no database date was early enough
    return rate;
}


void BitcoinExchange::processInput(const std::string &path) const {
    std::ifstream file(path.c_str());

    if (!file.is_open()) {
        std::cerr << RED << "Error: " << RESET << "could not open file." << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        // Ignore empty lines and the header.
        if (trim(line).empty() || trim(line) == "date | value")
            continue;

        size_t pipe = line.find('|');

        // valid line contains ONE seperator
        if (pipe == std::string::npos || line.find('|', pipe + 1) != std::string::npos){
            std::cout << RED << "Error: " << RESET << "bad input => " << line << std::endl;
            continue;
        }

        // Extract and trim the two fields.
        std::string date = trim(line.substr(0, pipe));
        std::string value = trim(line.substr(pipe + 1));

        // Check that both fields are present.
        if (date.empty() || value.empty()) {
            std::cout << RED << "Error: " << RESET << "bad input => " << line << std::endl;
            continue;
        }

        if (!isValidDate(date)) {
            std::cout << RED << "Error: " << RESET << "bad input => " << line << std::endl;
            continue;
        }

        double amount;

        if (!isValidValue(value, amount)) {
            std::cout << RED << "Error: " << RESET << "bad input => " << line << std::endl;
            continue;
        }

        if (amount < 0) {
            std::cout << RED << "Error: " << RESET << "not a positive number." << std::endl;
            continue;
        }

        if (amount > 1000) {
            std::cout << RED << "Error: " << RESET << "too large a number." << std::endl;
            continue;
        }

    std::cout << BOLD << "\nValid date: " << date << " | Valid amount: " << amount << RESET << std::endl;

    double rate = getExchangeRate(date);

    if (rate < 0){
        std::cout << "Error: no earlier exchange rate found for " << date << std::endl;
        continue;
    }

    std::cout << "Date: " << date << " | Amount: " << amount << " | Rate: " << rate << std::endl;
    

    // multiply the input amount by the exchange rate
    double result = amount * rate;

    std::cout << date << " => " << amount << " = " << GREEN << BOLD << result << RESET << "\n" << std::endl;
    }
} 

