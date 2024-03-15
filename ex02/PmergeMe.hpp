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

class PmergeMe
{
public:
    PmergeMe(int ac, char **av);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    template <typename T>
    void display(const T &container);

    std::deque<std::pair<int, int>> makePair(const std::deque<int> &original);
    std::vector<std::pair<int, int>> makePairVector(const std::vector<int> &original);
    std::deque<int> sortDeque(std::deque<int> &arr);
    std::vector<int> sortVector(std::vector<int> &arr);
    
    void separatePairs(const std::deque<std::pair<int, int>> &pairedDeque, std::deque<int> &mainList, std::deque<int> &pendingList);
    void insertSmallestToFront(std::list<int> &mainList, std::list<int> &pendingList);
    void insertWithBinarySearch(std::deque<int> &mainDeque, const int element);
    void insertAllWithBinarySearch(std::deque<int> &mainDeque, std::deque<int> &pendingDeque);
    bool isSorted(const std::deque<int> &myDeque);
    void separatePairsVector(const std::vector<std::pair<int, int>> &pairedVector, std::vector<int> &mainList, std::vector<int> &pendingList);
    void insertionSortPairsVector(std::vector<std::pair<int, int>> &pairedVector);
    void insertAllWithBinarySearchVector(std::vector<int> &mainVector, std::vector<int> &pendingVector);
    void insertWithBinarySearchVector(std::vector<int> &mainVector, const int element);
    void insertionSortPairs(std::deque<std::pair<int, int>> &pairedDeque);
    void displayPair(std::deque<std::pair<int, int>> &pairedDeque);
};

#endif