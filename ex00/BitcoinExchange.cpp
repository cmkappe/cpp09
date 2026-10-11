#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}


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
        std::cout << "Input line: " << line << std::endl;
    }
}


