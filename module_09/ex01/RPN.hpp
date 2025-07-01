#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int>		_numbers;
		std::string			_expr;

		int		_getTopNumber(void);
		bool	_isOperator(const char& c) const;
		int		_calculate(int left, int right, char op);

		RPN&	operator=(const RPN& rhs);
		RPN(const RPN& rhs);

	public:
		RPN(const std::string& expr);
		~RPN(void);

		void	execute(void);
};

#endif //RPN_HPP