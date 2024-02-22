#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange exchange;
    exchange.loadPriceDb("data.csv"); // Assuming the DB filename

    std::string line;
    while (getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string date, temp;
        double value;
        if (getline(iss, date, '|') && getline(iss, temp, '|') && (std::istringstream(temp) >> value)) {
            if (value < 0 || value > 1000) {
                std::cerr << "Error: Value out of range." << std::endl;
                continue;
            }
            double result = exchange.getPriceOnDate(date, value);
            if (result != -1) {
                std::cout << date << " => " << value << " = " << result << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }

    return 0;
}