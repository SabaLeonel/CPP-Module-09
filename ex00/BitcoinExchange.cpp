#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::ifstream file;
    std::string date;
    float value;

    file.open("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error: file not found" << std::endl;
        return;
    }

    while (file >> date >> value) {
        AddToDb(date, value);
    }
    file.close();
    showDb();
    return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    _db = other._db;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other) {
    _db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    _db.clear();
}

void BitcoinExchange::AddToDb(const std::string& date, float value) {
    _db[date] = value;
}

void BitcoinExchange::showDb() const {
    for (auto it = _db.begin(); it != _db.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void BitcoinExchange::printDbValue(const std::string& date, float value) const 
{
    std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
    if (it == _db.end())
    {
        if (!_db.empty())
        {
            --it;
            std::cout << "Closest previous key: " << it->first << ", Bitcoin value in USD: " << it->second * value << std::endl;
        } 
        else
            std::cout << "Database is empty." << std::endl;
    } 
    else if (it != _db.begin() && it->first != date)
    {
        --it;
        std::cout << "Closest previous key: " << it->first << ", Bitcoin value in USD: " << it->second * value << std::endl;
    }
    else
        std::cout << "Key: " << date << ", Bitcoin value in USD: " << it->second * value << std::endl;
}