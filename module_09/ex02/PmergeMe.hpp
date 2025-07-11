#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>

class PmergeMe
{
	private:
		std::vector<int>	_vectorBefore;
		std::deque<int>		_dequeBefore;
		std::vector<int>	_vectorAfter;
		std::deque<int>		_dequeAfter;
		double				_vectorElapsedTime;
		double				_dequeElapsedTime;

		int				_convert(char* src) const;
		double			_elapsedTime(std::clock_t start, std::clock_t end) const;

		void			_sortVector(std::vector<int>& before, std::vector<int>& after);
		void			_insertVector(std::vector<int>& container, int value);
		std::vector<std::size_t>	_jacobsthalVectorOrder(std::size_t n) const;

		void			_sortDeque(std::deque<int>& before, std::deque<int>& after);
		void			_insertDeque(std::deque<int>& container, int value);
		std::deque<std::size_t>	_jacobsthalDequeOrder(std::size_t n) const;

		std::size_t		_jacobsthal(std::size_t n) const;

		template <typename Container>
		bool			_isSorted(const Container& src, double* elapsedTime);

		template <typename Container>
		void			_printContainer(const Container& src) const;

	public:
		PmergeMe(int size, char** argv);
		PmergeMe& operator=(const PmergeMe& rhs);
		PmergeMe(const PmergeMe& rhs);
		~PmergeMe(void);

		void	info(void) const;
};


template <typename Container>
bool	PmergeMe::_isSorted(const Container& src, double* elapsedTime)
{
	std::clock_t start = std::clock();

	if (src.size() == 1)
		return (true);

	typename Container::const_iterator it = src.begin();
	typename Container::const_iterator next = it;
	++next;

	while (next != src.end())
	{
		if (*it > *next)
			return (false);
		++it;
		++next;
	}
	std::clock_t end = std::clock();
	*elapsedTime = _elapsedTime(start, end);
	return (true);
}

template <typename Container>
void	PmergeMe::_printContainer(const Container& src) const
{
	typename Container::const_iterator it;
	for (it = src.begin(); it != src.end(); ++it)
		std::cout << *it << " ";
}

#endif //PMERGE_ME_HPP