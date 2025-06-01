#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

template <template <typename> class Container>
int	easyfind(Container<int> obj, int x)
{
	std::Container<int>::iterator it = std::find(obj.begin(), obj.end(), x);
	if (it != obj.end())
		return (*it);
	return (-1);
}

#endif //EASY_FIND_HPP