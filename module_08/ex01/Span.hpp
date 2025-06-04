#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
	private:
		unsigned int		_max;
		std::vector<int>	_elements;

	public:
		Span(void);
		Span(unsigned int n);
		Span& operator=(const Span& rhs);
		Span(const Span& rhs);
		~Span(void);

		void	addNumber(int nbr);
		//void	addNumber(int nbrs[]);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
		void	print(void) const;
		
};

#endif //SPAN_HPP