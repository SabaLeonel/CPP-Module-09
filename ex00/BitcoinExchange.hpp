#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

// #define INT_MAX 2147483647

class BitcoinExchange {
private:
    std::map<std::string, float> _db;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange &operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    void AddToDb(const std::string& date, float value);
    void showDb() const;
    void printDbValue(const std::string& date, float value) const;
};

#endif
