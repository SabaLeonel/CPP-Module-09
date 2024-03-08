#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <regex>
# include <string>
# include <vector>
# include <deque>
# include <iterator>
# include <stdexcept>
# include <random>
# include <algorithm>
# include <ctime>



class PmergeMe{
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        void Vectorfill();
        void Dequefill();
    private:
        std::deque<std::string> _deque;
        std::vector<std::string> _vector;
        int _size;
};

#endif