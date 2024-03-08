#include "RPN.hpp"

int main(int ac, char **av)
{
    Rpn rpn;

    if (ac > 2)
    {
        std::cerr << "Usage: ./rpn input" << std::endl;
        return (0);
    }
    else if (ac == 1)
    {
        std::cout << "Testing with some examples" << std::endl;
        rpn.bigmanting("3 5 + 7 *");
        rpn.bigmanting("-4 6 * 2 /");
        rpn.bigmanting("8 0 /");
        rpn.bigmanting("100 20 - 10 / 5 * 2 +");
        rpn.bigmanting("15 7 - 2 * -3 +");
        rpn.bigmanting("-5 -3 * 0 + 4 /");
        rpn.bigmanting("12 4 * 3 / 6 + 9 - 2 * 7 /");
        rpn.bigmanting("42");
    }
    else
        rpn.bigmanting(av[1]);
    return (0);
}
