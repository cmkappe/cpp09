#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <list>
#include <string>


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

};

#endif



