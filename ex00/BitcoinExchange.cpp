#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::ifstream file("data.csv");
    std::string date;
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: file not found" << std::endl;
        return;
    }
    else{
        std::getline(file, line);
        while(std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string date;
            std::string rateStr;
            float rate;

            if (std::getline(iss, date, ',') && std::getline(iss, rateStr))
            {
                rate = std::stof(rateStr);
                AddToDb(date, rate);
            }
        }

        file.close();
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    _db = other._db;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        this->_db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::AddToDb(const std::string& date, float value) {
    _db[date] = value;
}

void BitcoinExchange::showDb() const 
{
    for (std::map<std::string, float>::const_iterator it = _db.begin(); it != _db.end(); ++it) 
        std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
}

void BitcoinExchange::printDbValue(const std::string& date, float value) const
{
    std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
    if (it == _db.end())
    {
        if (!_db.empty())
        {
            --it;
            std::cout << "Closest previous date: " << it->first << ", Bitcoin value in USD: " << it->second * value << std::endl;
        } 
        else
            std::cout << "Database is empty." << std::endl;
    } 
    else if (it != _db.begin() && it->first != date)
    {
        --it;
        std::cout << "Closest previous date: " << it->first << ", Bitcoin value in USD: " << it->second * value << std::endl;
    }
    else
        std::cout << "Date: " << date << ", Bitcoin value in USD: " << it->second * value << std::endl;
}