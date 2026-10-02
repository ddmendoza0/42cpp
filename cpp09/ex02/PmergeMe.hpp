#pragma once
#include <deque>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <iostream>

class PmergeMe
{
    private:
        std::vector<int>    _vec;
        std::deque<int>     _deq;

        void sortVector(void);
        void sortDeque(void);
        std::vector<int> generateJacobsthal(int n);

    public:
        PmergeMe(int argc, char* argv[]);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe(void);

        void sort(void);

};