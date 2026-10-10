#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>


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

    while (std::getline(file, line))
    {
        std::cout << "Database line: " << line << std::endl;
    }

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


