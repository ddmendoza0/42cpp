#pragma once
#include <deque>
#include <ctime>
#include <cerrno>
#include <vector>
#include <climits>
#include <cstdlib>
#include <iostream>

class PmergeMe
{
    private:
        std::vector<int>    _vec;
        std::deque<int>     _deq;
        int                 _argc;
        char**              _argv;

        void    loadVector( void );
        void    loadDeque( void );
        void    sortVector(void);
        void    sortDeque(void);
        int     parsePositive( const char* s );
        std::vector<int> generateJacobsthal(int n);

    public:
        PmergeMe(int argc, char* argv[]);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe(void);

        void sort(void);

};