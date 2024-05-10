#include "PmergeMe.hpp"
// int check_input(char *str)
// {
//     for (size_t i = 0; i < strlen(str); i++)
//     {
//         if (!std::isdigit(str[i]))
//             return (1);
//     }
//     return (0);
// }

int main(int ac, char **av)
{
    if (ac < 3)
    {
        std::cerr << "Error: Need more than 1 inputs !" << std::endl;
        return (1);
    }

     std::vector<int> input;
    int nb;
    int i;

    // Parse command-line arguments
    for (i = 1; av[i] != NULL; i++) {
        // Check if all characters are digits
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (!isdigit(av[i][j])) {
                std::cout << "[Error] Non-numeric character detected." << std::endl;
                return 1;
            }
        }
        nb = atoi(av[i]);
        if (nb < 0) {
            std::cout << "[Error] Negative number detected." << std::endl;
            return 1;
        }
        input.push_back(nb);
    }

    // Output the numbers before sorting
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // Create an instance of PmergeMe with the input vector and the number of elements
    PmergeMe instance(input, i - 1);

    // Output the results after operations
    std::cout << "After sorting: ";
    for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    return 0;
}


