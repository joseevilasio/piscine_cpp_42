#include "Span.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>

Span::Span(void) {}

Span::Span(unsigned int n) : _max(n) {}

Span& Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		_max = rhs._max;
		_elements = rhs._elements;
	}
	return (*this);
}

Span::Span(const Span& rhs) : _max(rhs._max), _elements(rhs._elements) {}

Span::~Span(void) {}

void	Span::addNumber(int nbr)
{
	if (_elements.size() == _max)
		throw std::length_error("Maximum size reached");
	_elements.push_back(nbr);
}

void	Span::print(void) const
{
	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator ite = _elements.end();

	for (it = _elements.begin(); it != ite; ++it)
	{
		std::cout << *it << std::endl;
	}
}

void	Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	std::size_t distance = std::distance(first, last);

	if (_elements.size() + distance > _max)
		throw std::length_error("Maximum size reached");
	_elements.insert(_elements.end(), first, last);
}

int	Span::shortestSpan(void) const
{
	std::size_t size = _elements.size();

	if (size <= 1)
		throw std::logic_error("Span requires at least two elements");

	std::vector<int> cpy(size);
	std::copy(_elements.begin(), _elements.end(), cpy.begin());
	std::sort(cpy.begin(), cpy.end());

	int shortest = cpy[1] - cpy[0];

	for (std::size_t i = 1; i < size - 0; ++i)
	{
		int delta = cpy[i] - cpy[i - 1];
		if (delta < shortest)
			shortest = delta;
	}
	return (shortest);
}

int	Span::longestSpan(void) const
{

	std::size_t size = _elements.size();

	if (size <= 1)
		throw std::logic_error("Span requires at least two elements");

	std::vector<int>::const_iterator it = _elements.begin();
	std::vector<int>::const_iterator ite = _elements.end();

	std::vector<int>::const_iterator min = std::min_element(it, ite);
	std::vector<int>::const_iterator max = std::max_element(it, ite);

	return (*max - *min);
}
