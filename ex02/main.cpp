#include "PMergeMe.hpp"

int check_input(char *str)
{
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (!std::isdigit(str[i]))
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Need more than 1 inputs !" << std::endl;
        return (1);
    }

    for (int i = 1; i < ac; i++)
    {
        if (check_input(av[i]))
        {
            std::cerr << "Error: Only positiv inputs are allowed !" << std::endl;
            return (1);
        }
    }



    return (0);
}


