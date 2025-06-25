#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int size, char** argv) : _vectorElapsedTime(0), _dequeElapsedTime(0)
{
	int nbr;

	for (int i = 1; i <= size; ++i)
	{
		nbr = _convert(argv[i]);
		_vectorBefore.push_back(nbr);
		_dequeBefore.push_back(nbr);
	}

	if (!(_isSorted(_vectorBefore, &_vectorElapsedTime)
		&& _isSorted(_dequeBefore, &_dequeElapsedTime)))
	{
		std::clock_t startV = std::clock();
		_sortVector(_vectorBefore, _vectorAfter);
		std::clock_t endV = std::clock();
		_vectorElapsedTime = _elapsedTime(startV, endV);

		std::clock_t startD = std::clock();
		_sortDeque(_dequeBefore, _dequeAfter);
		std::clock_t endD = std::clock();
		_dequeElapsedTime = _elapsedTime(startD, endD);
	}
	else
	{
		_vectorAfter = _vectorBefore;
		_dequeAfter = _dequeBefore;
	}
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
	{
		_vectorBefore = rhs._vectorBefore;
		_dequeBefore = rhs._dequeBefore;
		_vectorAfter = rhs._vectorAfter;
		_dequeAfter = rhs._dequeAfter;
		_vectorElapsedTime = rhs._vectorElapsedTime;
		_dequeElapsedTime = rhs._dequeElapsedTime;
	}
	return (*this);
}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
	*this = rhs;
}

PmergeMe::~PmergeMe(void) {}

void	PmergeMe::info(void) const
{
	int size = _vectorBefore.size();

	std::cout << "Before: ";
	_printContainer(_vectorBefore);
	
	std::cout << "\nAfter: ";
	_printContainer(_vectorAfter);

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "\nTime to process a range of " << size
		<< " elements with std::vector : " << _vectorElapsedTime << " us";

	std::cout << "\nTime to process a range of " << size
		<< " elements with std::deque : " << _dequeElapsedTime << " us\n";
}

int	PmergeMe::_convert(char* src) const
{
	char* end;
	errno = 0;
	long num = std::strtol(src, &end, 10);

	if (*end == '\0' && errno == 0 && num >= 0 && num <= UINT_MAX)
		return (static_cast<int>(num));
	throw std::invalid_argument("Invalid Argument");
}

double	PmergeMe::_elapsedTime(std::clock_t start, std::clock_t end) const
{
	double elapsed = 1e6 * (end - start) / CLOCKS_PER_SEC;
	return (elapsed);
}

void	PmergeMe::_sortVector(std::vector<int>& before, std::vector<int>& after)
{
	if (before.size() <= 1)
	{
		after = before;
		return ;
	}

	std::vector<int> bigger;
	std::vector<int> smaller;

	for (std::size_t i = 0; i + 1 < before.size(); i += 2)
	{
		int a = before[i];
		int b = before[i + 1];

		if (a > b)
		{
			bigger.push_back(a);
			smaller.push_back(b);
		}
		else
		{
			bigger.push_back(b);
			smaller.push_back(a);
		}
	}

	std::vector<int> sortedBigger;
	_sortVector(bigger, sortedBigger);

	for (std::size_t i = 0; i < smaller.size(); ++i)
		_insertVector(sortedBigger, smaller[i]);

	if (before.size() % 2 != 0)
		_insertVector(sortedBigger, before.back());
	
	after = sortedBigger;
}

void	PmergeMe::_insertVector(std::vector<int>& container, int value)
{
	std::vector<int>::iterator it = container.begin();
	std::vector<int>::iterator ite = container.end();

	while (it < ite)
	{
		std::vector<int>::iterator mid = it + (ite - it) / 2;
		if (*mid < value)
			it = mid + 1;
		else
			ite = mid;
	}
	container.insert(it, value);
}

void	PmergeMe::_sortDeque(std::deque<int>& before, std::deque<int>& after)
{
	if (before.size() <= 1)
	{
		after = before;
		return ;
	}

	std::deque<int> bigger;
	std::deque<int> smaller;

	for (std::size_t i = 0; i + 1 < before.size(); i += 2)
	{
		int a = before[i];
		int b = before[i + 1];

		if (a > b)
		{
			bigger.push_back(a);
			smaller.push_back(b);
		}
		else
		{
			bigger.push_back(b);
			smaller.push_back(a);
		}
	}

	std::deque<int> sortedBigger;
	_sortDeque(bigger, sortedBigger);

	for (std::size_t i = 0; i < smaller.size(); ++i)
		_insertDeque(sortedBigger, smaller[i]);

	if (before.size() % 2 != 0)
		_insertDeque(sortedBigger, before.back());
	
	after = sortedBigger;
}

void	PmergeMe::_insertDeque(std::deque<int>& container, int value)
{
	std::deque<int>::iterator it = container.begin();
	std::deque<int>::iterator ite = container.end();

	while (it < ite)
	{
		std::deque<int>::iterator mid = it + (ite - it) / 2;
		if (*mid < value)
			it = mid + 1;
		else
			ite = mid;
	}
	container.insert(it, value);
}
