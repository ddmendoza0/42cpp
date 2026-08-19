#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(void);
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack(void);


        typedef typename std::stack<T>::container_type::iterator                iterator;
        typedef typename std::stack<T>::container_type::const_iterator          const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator        rev_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator  const_rev_iterator; 

        iterator            begin();
        iterator            end();
        const_iterator      begin() const;
        const_iterator      end() const;
        rev_iterator        rbegin();
        rev_iterator        rend();
        const_rev_iterator  rbegin() const;
        const_rev_iterator  rend() const;
};
#include "MutantStack.tpp"