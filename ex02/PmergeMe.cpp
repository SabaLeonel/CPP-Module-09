#include "PmergeMe.hpp"
// Constructor
PmergeMe::PmergeMe(std::vector<int> &initialData, int capacity)
    : _vector(initialData), _capacity(capacity)
{
    // Optionally fill the deque with the initial data (if needed)
    std::copy(_vector.begin(), _vector.end(), std::back_inserter(_deque));
}

// Destructor
PmergeMe::~PmergeMe()
{
    // Clean up resources if needed - in this simple example, this is handled automatically
}

// Copy Constructor
PmergeMe::PmergeMe(const PmergeMe &other)
    : _capacity(other._capacity)
{
    this->_vector = other._vector;
    this->_deque = other._deque;
    *this = other;
    // This straightforward approach will copy each member as needed
}

// Assignment Operator
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    { // Protect against self-assignment
        _vector = other._vector;
        _deque = other._deque;
        // _capacity is const and cannot be assigned new value after initialization
    }
    return *this;
}

// Private method to sort the vector

void PmergeMe::containerVectorSort()
{
    clock_t startTime = clock();

    size_t const splitPoint = this->_vector.size() / 2;
    std::vector<int> initialSegment(this->_vector.begin(), this->_vector.begin() + splitPoint);
    std::vector<int> finalSegment(this->_vector.begin() + splitPoint, this->_vector.end());

    // Sorting the initial and final segments of the vector
    std::sort(initialSegment.begin(), initialSegment.end());
    std::sort(finalSegment.begin(), finalSegment.end());

    // Merging the sorted segments into the initialSegment vector
    initialSegment.insert(initialSegment.end(), finalSegment.begin(), finalSegment.end());

    // Sorting the merged vector to ensure total order
    std::sort(initialSegment.begin(), initialSegment.end());

    // Output the sorted vector
    std::cout << "After: ";
    for (std::vector<int>::iterator currentIter = initialSegment.begin(), endIter = initialSegment.end(); currentIter != endIter; ++currentIter)
    {
        std::cout << " " << *currentIter;
    }
    std::cout << std::endl;

    // Calculating the time taken for the sort process
    clock_t endTime = clock();
    double timeElapsed = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000000; // Converting clock ticks to microseconds
    std::cout << "Time to process a range of " << this->_capacity << " elements with std::vector<int> : " << timeElapsed << " us" << std::endl;
}

// Private method to sort the deque
void PmergeMe::containerDequeSort()
{
    clock_t start = clock();

    std::deque<int>::iterator it = this->_deque.begin();
    std::deque<int>::iterator ite = this->_deque.end();

    size_t const half_size = this->_deque.size() / 2;
    std::deque<int> first_half;
    std::deque<int> second_half;

    // Fill the first half
    for (size_t i = 0; i < half_size; ++i, ++it)
    {
        first_half.push_back(*it);
    }
    // Fill the second half
    for (; it != ite; ++it)
    {
        second_half.push_back(*it);
    }

    // Sort the first half using a temporary vector
    std::vector<int> temp(first_half.begin(), first_half.end());
    std::sort(temp.begin(), temp.end());
    std::copy(temp.begin(), temp.end(), first_half.begin());

    // Sort the second half using a temporary vector
    temp.assign(second_half.begin(), second_half.end());
    std::sort(temp.begin(), temp.end());
    std::copy(temp.begin(), temp.end(), second_half.begin());

    // Merge the sorted halves back into first_half
    first_half.insert(first_half.end(), second_half.begin(), second_half.end());

    // Sort the merged result using a temporary vector
    temp.assign(first_half.begin(), first_half.end());
    std::sort(temp.begin(), temp.end());
    std::copy(temp.begin(), temp.end(), first_half.begin());

    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << this->_capacity << " elements with std::deque<int> : " << duration << " us" << std::endl;
}
