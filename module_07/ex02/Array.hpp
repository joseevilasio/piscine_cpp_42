#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T*				_elements;
		unsigned int	_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array& operator=(const Array& rhs);
		Array(const Array& rhs);
		~Array(void);

		unsigned int	size(void);
		T&	operator[](unsigned int i);
};

template <typename T>
Array<T>::Array(void) : _elements(new T()), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]), _size(n) {}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	if (this != &rhs)
	{
		_elements = rhs._elements;
	}
	return (*this);
}

template <typename T>
Array<T>::Array(const Array<T>& rhs)
{
	this = rhs;
}

template <typename T>
Array<T>::~Array(void) {delete[] _elements;}

template <typename T>
unsigned int	Array<T>::size(void) {return (_size);}

template <typename T>
T&	Array<T>::operator[](unsigned int i)
{
	if (i > _size)
		throw std::out_of_range::out_of_range();
	return (_elements[i]);
}

#endif //ARRAY_HPP