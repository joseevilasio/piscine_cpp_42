#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		// MutantStack& operator=(const MutantStack& rhs);
		// MutantStack(const MutantStack& rhs);
		~MutantStack(void);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void);
		iterator	end(void);

};

#include "MutantStack.tpp"

#endif //MUTANT_STACK_HPP