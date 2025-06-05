#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
		std::stack<T>	_stack;
		T*				_begin;
		T*				_end;

	public:
		MutantStack(void);
		// MutantStack& operator=(const MutantStack& rhs);
		// MutantStack(const MutantStack& rhs);
		~MutantStack(void);

		void		push(const T& n);
		typedef T*	iterator;
		iterator	begin(void);
		iterator	end(void);

};

#include "MutantStack.tpp"

#endif //MUTANT_STACK_HPP