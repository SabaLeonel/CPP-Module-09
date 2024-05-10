#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>
#include <vector>
#include <deque>
#include <iterator>
#include <stdexcept>
#include <random>
#include <algorithm>
#include <ctime>
#include <list>

class PmergeMe
{
public:
    PmergeMe(std::vector <int> &initialData, int capacity);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
private:
    std::deque <int> _deque;
    std::vector <int> _vector;
    const int _capacity;
    void containerVectorSort();
    void containerDequeSort();
};

#endif