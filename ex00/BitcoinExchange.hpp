#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

class BitcoinExchange {
private:
    std::map<std::string, double> priceDb;
public:
    BitcoinExchange();
    void loadPriceDb(const std::string& filename);
    double getPriceOnDate(const std::string& date, double value);
};

#endif
