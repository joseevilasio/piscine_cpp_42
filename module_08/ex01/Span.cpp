#include "Span.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>

Span::Span(void) {}

Span::Span(unsigned int n) : _max(n) {}

// Span& Span::operator=(const Span& rhs)

// Span::Span(const Span& rhs) {}

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

// void	Span::addNumber(int* nbrs)
// {
// 	std::size_t size = nbrs / sizeof(int);

// 	if (_elements.size() == _max)
// 		throw std::length_error("Maximum size reached");
// 	_elements.push_back(nbr);
// }

int	Span::shortestSpan(void) const
{
	std::size_t size = _elements.size();

	if (size <= 1)
		return (0);

	std::vector<int> cpy(size);
	std::copy(_elements.begin(), _elements.end(), cpy.begin());
	std::sort(cpy.begin(), cpy.end());

	std::vector<int>::const_iterator it = cpy.begin();
	std::vector<int>::const_iterator ite = cpy.end();

	int shortest = *ite - *it;
	int tmp = shortest;

	for (it = cpy.begin(); it != ite; ++it)
	{
		//std::cout << *it << std::endl;
		if (it != (ite - 1))
			tmp = *(it + 1) - *it;
		if (tmp < shortest)
			shortest = tmp;
	}
	return (tmp);
}

int	Span::longestSpan(void) const
{

	std::size_t size = _elements.size();

	if (size <= 1)
		return (0);
	// std::size_t size = _elements.size();
	// std::vector<int> cpy(size);
	// std::copy(_elements.begin(), _elements.end(), cpy.begin());
	// std::sort(cpy.begin(), cpy.end());

	// return (cpy[size - 1] - cpy[0]);
	std::vector<int>::const_iterator it = _elements.begin();
	std::vector<int>::const_iterator ite = _elements.end();
	std::vector<int>::const_iterator min = std::min_element(it, ite);
	std::vector<int>::const_iterator max = std::max_element(it, ite);
	return (*max - *min);
}

//int		Span::longestSpan(void) const;