#include "PmergeMe.hpp"

PmergeMe::PmergeMe( int argc, char* argv[] ) 
{
    for ( int i = 1; i < argc; i++ )
    {
        for (int j = 0; argv[i][j]; j++)
        {
            if (!std::isdigit(argv[i][j]))
                throw std::runtime_error("Error");
        }
        int n = std::atoi(argv[i]);
        _vec.push_back(n);
        _deq.push_back(n);
    }
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq){}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return (*this);
}

PmergeMe::~PmergeMe(void) {}

void    PmergeMe::sort( void )
{
    std::cout << "Before: ";
    for ( size_t i = 0; i < _vec.size(); i++ )
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    clock_t v_start = clock();
    sortVector();
    clock_t v_end = clock();
    double v_time = (double)(v_end - v_start) / CLOCKS_PER_SEC * 1000000;
    
    clock_t d_start = clock();
    sortDeque();
    clock_t d_end = clock();
    double d_time = (double)(d_end - d_start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    for ( size_t i = 0; i < _vec.size(); i++ )
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " <<  _vec.size() << " elements with std::vector : " << v_time << " us" << std::endl;
    std::cout << "Time to process a range of " <<  _deq.size() << " elements with std::deque : " << d_time << " us" << std::endl;
}

void PmergeMe::sortVector( void )
{
    if ( _vec.size() <= 1 )
        return ;

    std::vector<std::pair<int, int> > pairs;
    int leftover = -1;
    bool hasLeftover = false;

    //creating the sorted pairs
    for ( size_t i = 0; i + 1 < _vec.size(); i += 2 )
    {
        int larger  = std::max(_vec[i], _vec[i + 1]);
        int smaller = std::min(_vec[i], _vec[i + 1]);
        pairs.push_back(std::make_pair(larger, smaller));
    }

    if ( _vec.size() % 2 != 0 )
    {
        leftover = _vec.back();
        hasLeftover = true;
    }

    //main chain and pending storing
    std::vector<int> main;
    std::vector<int> pend;
    for ( size_t i = 0; i < pairs.size(); i++ )
    {
        main.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    //recursive call storing _vec first
    std::vector<int> temp = _vec;
    _vec = main;
    sortVector();
    main = _vec;
    _vec = temp;

    std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[0]);
    main.insert(pos, pend[0]);

    std::vector<int> jacobsthal = generateJacobsthal(pend.size());

    //insert pend in Jacobsthal order
    int prev = 1;
    for ( size_t i = 0; i < jacobsthal.size(); i++ )
    {
        int curr = std::min(jacobsthal[i], (int)pend.size());
        for ( int j = curr - 1; j >= prev; j-- )
        {
            std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[j]);
            main.insert(pos, pend[j]);
        }
        prev = curr;
        if ( prev >= (int)pend.size() )
            break;
    }

    for ( int j = (int)pend.size() - 1; j >= prev; j-- )
    {
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[j]);
        main.insert(pos, pend[j]);
    }

    if ( hasLeftover )
    {
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), leftover);
        main.insert(pos, leftover);
    }

    _vec = main;
}

void PmergeMe::sortDeque( void )
{
    if ( _deq.size() <= 1 )
        return ;

    std::deque<std::pair<int, int> > pairs;
    int leftover = -1;
    bool hasLeftover = false;

    for ( size_t i = 0; i + 1 < _deq.size(); i += 2 )
    {
        int larger  = std::max(_deq[i], _deq[i + 1]);
        int smaller = std::min(_deq[i], _deq[i + 1]);
        pairs.push_back(std::make_pair(larger, smaller));
    }

    if ( _deq.size() % 2 != 0 )
    {
        leftover = _deq.back();
        hasLeftover = true;
    }

    std::deque<int> main;
    std::deque<int> pend;
    for ( size_t i = 0; i < pairs.size(); i++ )
    {
        main.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    std::deque<int> temp = _deq;
    _deq = main;
    sortDeque();
    main = _deq;
    _deq = temp;

    std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[0]);
    main.insert(pos, pend[0]);

    std::vector<int> jacobsthal = generateJacobsthal(pend.size());

    int prev = 1;
    for ( size_t i = 0; i < jacobsthal.size(); i++ )
    {
        int curr = std::min(jacobsthal[i], (int)pend.size());
        for ( int j = curr - 1; j >= prev; j-- )
        {
            std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[j]);
            main.insert(pos, pend[j]);
        }
        prev = curr;
        if ( prev >= (int)pend.size() )
            break;
    }

    for ( int j = (int)pend.size() - 1; j >= prev; j-- )
    {
        std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[j]);
        main.insert(pos, pend[j]);
    }

    if ( hasLeftover )
    {
        std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), leftover);
        main.insert(pos, leftover);
    }

    _deq = main;
}


std::vector<int> PmergeMe::generateJacobsthal( int n )
{
    std::vector<int> seq;
    seq.push_back(1);
    seq.push_back(3);
    while ( seq.back() < n )
        seq.push_back(seq[seq.size()-1] + 2 * seq[seq.size()-2]);
    return ( seq );
}