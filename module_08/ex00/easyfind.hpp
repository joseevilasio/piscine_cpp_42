#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
int	easyfind(const T& container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		return (*it);
	throw std::runtime_error("Value not found");
}

#endif //EASY_FIND_HPP