#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}

void BitcoinExchange::loadPriceDb(const std::string& filename) {
    std::ifstream file(filename.c_str());
    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        double price;
        if (getline(iss, date, ',') && (iss >> price)) {
            priceDb[date] = price;
        }
    }
}

double BitcoinExchange::getPriceOnDate(const std::string& date, double value) {
    // Find the closest lower date in the DB
    std::map<std::string, double>::iterator it = priceDb.lower_bound(date);
    if (it != priceDb.begin() && (it == priceDb.end() || it->first != date)) {
        --it; // Go to the closest lower date if exact match not found
    }
    if (it == priceDb.end()) {
        std::cerr << "Error: Date not found in database." << std::endl;
        return -1; // Indicate an error
    }
    return it->second * value;
}
