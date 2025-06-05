#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) {}

// template <typename T>
// MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& rhs)
// {
// 	if (this != &rhs)
// 	{
// 		delete[] _elements;
// 		_elements = NULL;
// 		_size = 0;
// 		if (rhs._size > 0)
// 		{
// 			_elements = new T[rhs._size];
// 			for(unsigned int i = 0; i < rhs._size; i++)
// 			{
// 				_elements[i] = rhs._elements[i];
// 			}
// 			_size = rhs._size;
// 		}
// 	}
// 	return (*this);
// }

// template <typename T>
// MutantStack<T>::MutantStack(const MutantStack<T>& rhs) : _elements(NULL), _size(0)
// {
// 	if (rhs._size > 0)
// 	{
// 		_elements = new T[rhs._size];
// 		for(unsigned int i = 0; i < rhs._size; i++)
// 		{
// 			_elements[i] = rhs._elements[i];
// 		}
// 		_size = rhs._size;
// 	}
// }

template <typename T>
void	MutantStack<T>::push(const T& n)
{
	if (_stack.empty())
	{
		_stack.push(n);
		_end = _stack.top();
		_begin = _stack.top();
	}
	else
	{
		_stack.push(n);
		_begin = _stack.top();
	}
}

template <typename T>
MutantStack<T>::~MutantStack(void) {}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (_begin);
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (_end);
}