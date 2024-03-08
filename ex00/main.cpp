#include "BitcoinExchange.hpp"


int	validateLine(std::string line);

int main(int ac, char **av)
{
    std::ifstream file;
    std::string date;

    if (ac != 2) {
        std::cerr << "Usage: ./btc data.csv input.txt" << std::endl;
        return 1;
    }

    file.open(av[1]);
    if (!file.is_open()) {
        std::cerr << "Error: file not found" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;
    std::string line;
    std::getline(file, line);
    if(line.empty() || (line == "date | value" && file.peek() == EOF))
    {
        std::cerr << "File is empty \n";
        return (1);
    }
    while(std::getline(file, line))
    {
        std::cout  << "input to check: " << line << std::endl;
        if (validateLine(line))
        {
            std::cout << "Format is valid" << "\n";
            exchange.printDbValue(line.substr(0,10), std::stof(line.substr(13, line.size() - 13)));
        }
        else
            std::cout << "Big man ting yeah not valid..." << std::endl;
        std::cout << std::endl;
    }

    file.close();
    return 0;
}
