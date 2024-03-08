#include "BitcoinExchange.hpp"

bool isLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDays(int month, int year)
{
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeap(year) ? 29 : 28;
        default:
            return 0;
    }
}

int validateDate(const std::string& line)
{
    int year = std::stoi(line.substr(0, 4));
    int month = std::stoi(line.substr(5, 2));
    int day = std::stoi(line.substr(8, 2));

    for (int i = 0; i < 10; ++i) 
    {
        if (i == 4 || i == 7){
            if (line[i] != '-')
                return 0;
        } 
        else{
            if (!std::isdigit(line[i]))
                return 0;
        }
    }

    if (month < 1 || month > 12 || day < 1 || day > getDays(month, year))
        return 0;

    return 1;
}

int	validateFormat(std::string line)
{
    if (line[10] == ' ' && line[11] == '|' && line[12] == ' ')
        return (1);
    return (0);
}

bool isInteger(const std::string& str) {
    std::istringstream iss(str);
    int value;
    iss >> value;
    return !iss.fail() && iss.eof();
}

bool isFloat(const std::string& str) {
    std::istringstream iss(str);
    float value;
    iss >> value;
    return !iss.fail() && iss.eof();
}

int validateValue(const std::string& line)
{
    if (isInteger(line))
        return (1);
    else if (isFloat(line))
        return (1);
    else
        return (0);
}

int	checkIfNumberExceedsLimit(std::string line)
{
    float number = std::stof(line);

    if (number > 1000 || number < 0)
        return (0);
    return (1);
}

int	validateLine(std::string line)
{
    if (validateDate(line))
    {
        if (validateFormat(line))
        {
            std::string value = line.substr(13, line.size() - 13);
            if (validateValue(value))
                if (checkIfNumberExceedsLimit(value))
                    return (1);
        }
    }
    return (0);
}
