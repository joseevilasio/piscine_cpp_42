#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename A, typename S, typename F>
void	iter(A *address, S length, F function)
{
	for (int i = 0; i < length; i++)
	{
		function(address[i]);
	}
}

template <typename T>
void	ft_print(T a)
{
	std::cout << a << std::endl;
}

#endif //ITER_HPP