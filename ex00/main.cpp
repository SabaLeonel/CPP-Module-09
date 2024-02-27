#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
    std::ifstream file;
    std::string date;
    float value;

    if (ac != 2) {
        std::cerr << "Usage: ./ex00 [filename]" << std::endl;
        return 1;
    }

    file.open(av[1]);
    if (!file.is_open()) {
        std::cerr << "Error: file not found" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;

    while (file >> date >> value) {
        exchange.AddToDb(date, value);
    }

    exchange.showDb();

    file.close();

    return 0;

}
