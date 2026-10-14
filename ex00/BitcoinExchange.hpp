#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <list>
#include <string>

static const char* RESET = "\033[0m";
static const char* BOLD = "\033[1m";
// static const char* CYAN = "\033[36m";
static const char* GREEN = "\033[32m";
static const char* RED = "\033[31m";
static const char* YELLOW = "\033[33m";

class BitcoinExchange {
    private:
        std::list<std::pair<std::string, double> > _rates;
        // std::string _date;
        // double _value;

        // BitcoinExchange() = delete;
        BitcoinExchange(const BitcoinExchange &other) = delete;
        BitcoinExchange &operator=(const BitcoinExchange &other) = delete;

    public:

        BitcoinExchange();
        ~BitcoinExchange();

        bool loadDatabase(const std::string& path);
        void processInput(const std::string& path) const;

        static bool isValidDate(const std::string &date);
        static bool isValidValue(const std::string &value, double &outValue);

        double getExchangeRate(const std::string &date) const;
};

#endif



