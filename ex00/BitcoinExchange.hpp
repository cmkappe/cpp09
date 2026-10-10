#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

/* A map associates a unique key with a value.
- Key: the date, represented as a string.
- Value: the exchange rate, represented as a double

also, std::map keeps its keys sorted! */

class BitcoinExchange {
private:
    std::string _date;
    double _value;

    BitcoinExchange() = delete;
    BitcoinExchange(const BitcoinExchange &other) = delete;
    BitcoinExchange &operator=(const BitcoinExchange &other) = delete;
    BitcoinExchange(const std::string &str);
    ~BitcoinExchange();

    bool loadDatabase(const std::string& path);
    void processInput(const std::string& path) const;

public:
    std::map<std::string, double> _rates;

    static bool isValidDate(const std::string& date);
    static bool isValidValue(const std::string& value, double& outValue);
    static std::string trim(const std::string& str);
    static double parseAmount(const std::string& value);
    double findRateForDate(const std::string& date) const;

    static void exchange(const std::string &string);
};

#endif



