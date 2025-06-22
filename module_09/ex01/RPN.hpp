#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int>		_numbers;
		std::stack<char>	_operators;

		int		_getTopNumbers(void);
		char	_getTopOperators(void);
		bool	_isOperator(const char& c) const;
		bool	_insert(const std::string& expr);
		int		_calculate(int left, int right, char op);

		RPN&	operator=(const RPN& rhs); //add
		RPN(const RPN& rhs); //add

	public:
		RPN(const std::string& expr);
		~RPN(void);

		void	execute(void);
};

#endif //RPN_HPP