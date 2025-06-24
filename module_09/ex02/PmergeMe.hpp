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

		int	_convert(char* src) const;
		double			_elapsedTime(std::clock_t start, std::clock_t end) const;

		void			_sortVector(std::vector<int>& before, std::vector<int>& after);
		void			_insertVector(std::vector<int>& container, int value);

		void			_sortDeque(std::deque<int>& container);
		void			_insertDeque(std::deque<int>& container, int value);

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

#endif //PMERGE_ME_HPP