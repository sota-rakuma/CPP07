/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:22:42 by srakuma           #+#    #+#             */
/*   Updated: 2022/05/25 16:47:38 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#ifndef __MACH__
#include <cstdlib>
#endif
#include <stdexcept>

template <typename T>
class Array
{
	private:
		unsigned int	_size;
		T				*_arr;
	public:
		Array();
		Array(unsigned int);
		Array(const Array&);
		~Array();
		Array&			operator=(const Array&);
		T&				operator[](unsigned int);
		const T&		operator[](unsigned int) const;
		unsigned int	size() const;
};

template <typename T>
Array<T>::Array()
{
	_arr = new T[0];
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int size)
: _size(size)
{
	try
	{
		_arr = new T[size];
		if (_arr == NULL)
			throw (std::bad_alloc());
	}
	catch(const std::bad_alloc & e)
	{
		std::cerr << e.what() << '\n';
		std::exit(1);
	}
}

template <typename T>
Array<T>::Array(const Array& arr)
: _size(arr._size)
{
	try
	{
		_arr = new T[arr._size];
		if (_arr == NULL)
			throw (std::bad_alloc());
	}
	catch(const std::bad_alloc & e)
	{
		std::cerr << e.what() << '\n';
		std::exit(1);
	}
	for (size_t i = 0; i < arr._size; i++)
	{
		_arr[i] = arr._arr[i];
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& arr)
{
	if (this == &arr)
		return (*this);
	delete [] _arr;
	_size = arr._size;
	try
	{
		_arr = new T[arr._size];
		if (_arr == NULL)
			throw (std::bad_alloc());
	}
	catch(const std::bad_alloc & e)
	{
		std::cerr << e.what() << '\n';
		std::exit(1);
	}
	for (size_t i = 0; i < _size; i++)
	{
		_arr[i] = arr._arr[i];
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (_size <= index)
		throw (std::range_error("out of range"));
	return (*(_arr + index));
}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (_size <= index)
		throw (std::range_error("out of range"));
	return (*(_arr + index));
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

template <typename T>
Array<T>::~Array()
{
	delete [] _arr;
}

#endif /* ARRAY_HPP */
