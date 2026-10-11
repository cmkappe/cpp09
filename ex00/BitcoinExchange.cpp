#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

// date must have exactly ten characters, with dashes in positions 4 and 7
// every other character must be a digit
// extract day, month & year with substr & atoi
// need to account foor leap year

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10
        || date[4] != '-'
        || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1)
        return false;

    int days[] = {31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};

    bool leap = (year % 4 == 0
        && (year % 100 != 0 || year % 400 == 0));

    if (leap)
        days[1] = 29;

    if (day > days[month - 1])
        return false;

    return true;
}


static std::string trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    if (start == std::string::npos)
        return "";

    return str.substr(start, end - start + 1);
}

bool BitcoinExchange::loadDatabase(const std::string &path)
{
    std::ifstream file(path.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
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
    std::cout << "Loaded " << _rates.size() << " database entries." << std::endl;
    return true;
}



void BitcoinExchange::processInput(const std::string &path) const
{
    std::ifstream file(path.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line))
    {
        // Ignore empty lines and the header.
        if (trim(line).empty() || trim(line) == "date | value")
            continue;

        // Find the separator.
        size_t pipe = line.find('|');

        if (pipe == std::string::npos
            || line.find('|', pipe + 1) != std::string::npos){
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Extract and trim the two fields.
        std::string date = trim(line.substr(0, pipe));
        std::string value = trim(line.substr(pipe + 1));

        // Check that both fields are present.
        if (date.empty() || value.empty()) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::cout << "Parsed date: [" << date << "]" << " | Parsed value: [" << value << "]" << std::endl;
    }
}


