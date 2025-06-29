#include "RPN.hpp"
#include <string>

RPN::RPN(const std::string& expr) : _expr(expr) {}

RPN::~RPN(void) {}

RPN::RPN(const RPN& rhs) {*this = rhs;}

RPN& RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
	{
		_numbers = rhs._numbers;
	}
	return (*this);
}

int	RPN::_getTopNumbers()
{
	int item = _numbers.top();
	_numbers.pop();
	return (item);
}

bool	RPN::_isOperator(const char& c) const
{
	if (c == '*' || c == '+' || c == '-' || c == '/')
		return (true);
	return (false);
}

void	RPN::execute(void)
{
	std::string::const_iterator it;

	for (it = _expr.begin(); it != _expr.end(); ++it)
	{
		if (std::isspace(*it))
			continue ;

		if (std::isdigit(*it))
			_numbers.push(*it - '0');
		else if (_isOperator(*it))
		{
			if (_numbers.size() < 2)
				throw std::invalid_argument("Error");
			
			int right = _getTopNumbers();
			int left = _getTopNumbers();
			int result = _calculate(left, right, *it);
			_numbers.push(result);
		}
		else
			throw std::invalid_argument("Error");
	}

	if (_numbers.size() != 1)
		throw std::invalid_argument("Error");

	std::cout << _getTopNumbers() << std::endl;
}

int	RPN::_calculate(int left, int right, char op)
{
	if (op == '+')
		return (left + right);
	else if (op == '-')
		return (left - right);
	else if (op == '*')
		return (left * right);
	else
	{
		if (right == 0)
			throw std::invalid_argument("Error: Division by zero");
		else
			return (left / right);
	}
}
