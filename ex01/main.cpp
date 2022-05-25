/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 01:14:26 by srakuma           #+#    #+#             */
/*   Updated: 2022/05/24 17:52:21 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <float.h>
#define LEN 5

template <typename T>
void	twice_ref(T &x)
{
	x += x;
}

template <typename T>
void	twice(T x)
{
	x += x;
}

void	increment_char(char &x)
{
	x++;
}

void	str_at_2_into_x(std::string& str)
{
	if (strlen(str.c_str()) == 1)
	{
		std::cerr << "the string passed by parameter is too short" << std::endl;
		return ;
	}
	str.at(1) = 'x';
}

template <typename T>
void	print(const T& ele)
{
	std::cout << "[ " << ele << " ] " << std::flush;
}

template <typename T>
void	test(const std::string& type, T *ptr, size_t len, void (*f)(T&))
{
	std::cout << "\n" << type << " test" << "\nbefore iter: ";
	iter(ptr, len, print);
	std::cout << std::endl;
	iter(ptr, len, f);
	std::cout << "after iter : ";
	iter(ptr, len, print);
	std::cout << std::endl;
}

template <typename T>
void	test(const std::string& type, T const *ptr, size_t len, void (*f)(T const &))
{
	std::cout << "\n" << type << "test" << "\nbefore iter: ";
	for (size_t i = 0; i < len; i++)
	{
		std::cout << ptr[i];
		if (i != len - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
	iter(ptr, len, f);
	std::cout << "after iter: ";
	for (size_t i = 0; i < len; i++)
	{
		std::cout << ptr[i];
		if (i != len - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int	main(void)
{
	char		char_arr[LEN] = {'a', 'c', 'e', 'g', 'i'};
	std::string	str_arr[LEN] = {"aaa", "bbb", "ccc", "ddd", "eee"};
	int			int_arr[LEN] = {1, 2, 3, 4, 5};
	long		long_arr[LEN] = {INT_MAX, INT_MIN, (long)INT_MAX * 4, (long)INT_MIN * 4};
	float		float_arr[LEN] = {1.0f, 0.5f, 0.375, 1.25f, 0.3f};
	double		double_arr[LEN] = {1.0, 2.0, 3.14159265358979323846264, 1.1, 0.3};

	test("char array", char_arr, LEN, increment_char);
	test("str array", str_arr, LEN, str_at_2_into_x);

	test("integer array", int_arr, LEN, twice_ref);
	test("long array", long_arr, LEN, twice_ref);
	test("float array", float_arr, LEN, twice_ref);
	test("double array", double_arr, LEN, twice_ref);

	test("integer array", int_arr, LEN, twice);
	test("long array", long_arr, LEN, twice);
	test("float array", float_arr, LEN, twice);
	test("double array", double_arr, LEN, twice);
}
