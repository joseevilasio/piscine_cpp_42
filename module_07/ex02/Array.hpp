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

		unsigned int	size(void) const;
		const T&	operator[](unsigned int i) const;
		T&	operator[](unsigned int i);
};

template <typename T>
Array<T>::Array(void) : _elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]), _size(n) {}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	if (this != &rhs)
	{
		delete[] _elements;
		_elements = NULL;
		_size = 0;
		if (rhs._size > 0)
		{
			_elements = new T[rhs._size];
			for(unsigned int i = 0; i < rhs._size; i++)
			{
				_elements[i] = rhs._elements[i];
			}
			_size = rhs._size;
		}
	}
	return (*this);
}

template <typename T>
Array<T>::Array(const Array<T>& rhs) : _elements(NULL), _size(0)
{
	if (rhs._size > 0)
	{
		_elements = new T[rhs._size];
		for(unsigned int i = 0; i < rhs._size; i++)
		{
			_elements[i] = rhs._elements[i];
		}
		_size = rhs._size;
	}
}

template <typename T>
Array<T>::~Array(void) {delete[] _elements;}

template <typename T>
unsigned int	Array<T>::size(void) const {return (_size);}

template <typename T>
const T&	Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::out_of_range("Outside the interval");
	return (_elements[i]);
}

template <typename T>
T&	Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::out_of_range("Outside the interval");
	return (_elements[i]);
}

#endif //ARRAY_HPP