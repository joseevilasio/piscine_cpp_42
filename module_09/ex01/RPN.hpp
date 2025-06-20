#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int>	_stack;
		// int				_right;
		// int				_left;
		// int				_operator; 

	public:
		RPN(void);
		~RPN(void);
		//copy

		void	insert(int n);
		void	remove(void);
		//validar input
};

#endif //RPN_HPP