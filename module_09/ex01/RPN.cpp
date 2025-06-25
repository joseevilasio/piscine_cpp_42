#include "RPN.hpp"
#include <string>

RPN::RPN(const std::string& expr)
{
	if (!_insert(expr))
		throw std::invalid_argument("Error");
}

RPN::~RPN(void) {}

RPN::RPN(const RPN& rhs) {*this = rhs;}

RPN& RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
	{
		_numbers = rhs._numbers;
		_operators = rhs._operators;
	}
	return (*this);
}

int	RPN::_getTopNumbers()
{
	int item = _numbers.top();
	_numbers.pop();
	return (item);
}

char	RPN::_getTopOperators()
{
	char item = _operators.top();
	_operators.pop();
	return (item);
}

bool	RPN::_isOperator(const char& c) const
{
	if (c == '*' || c == '+' || c == '-' || c == '/')
		return (true);
	return (false);
}

bool	RPN::_insert(const std::string& expr)
{
	std::string::const_reverse_iterator it;

	for (it = expr.rbegin(); it != expr.rend(); ++it)
	{
		if (std::isspace(*it))
			continue ;
		if (_isOperator(*it))
		{
			if (it + 1 != expr.rend() && std::isspace(*(it + 1)))
				_operators.push(*it);
			else
				return (false);
		}
		else if (std::isdigit(*it))
		{
			if (it + 1 == expr.rend() || (it + 1 != expr.rend() && std::isspace(*(it + 1))))
				_numbers.push(*it - 48);
			else
				return (false);
		}
		else
			return (false);
	}
	return (true);
}


void	RPN::execute(void)
{
	size_t	size = _operators.size();

	for (size_t i = 0; i != size; ++i)
	{
		if (_numbers.size() >= 2 && _operators.size() >= 1)
		{
			int left = _getTopNumbers();
			int right = _getTopNumbers();
			char op = _getTopOperators();
			int nbr = _calculate(left, right, op);
			_numbers.push(nbr);
		}
	}
	if (_numbers.size() == 1 && _operators.size() == 0)
		std::cout << _getTopNumbers() << std::endl;
	else
		throw std::invalid_argument("Error");
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
