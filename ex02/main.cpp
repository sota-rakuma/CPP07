/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:22:50 by srakuma           #+#    #+#             */
/*   Updated: 2022/05/25 16:48:18 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#define NONE "\033[0m"
#define RED "\033[38;5;160m"
#define GREEN "\033[38;5;82m"
#define SKBL "\033[38;5;033m"
#define PRPL "\033[38;5;129m"

int	main(void)
{
	{
		Array<int>	a;
			try
		{
			std::cout << a.size() << std::endl;
			std::cout << a[0] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		Array<char>			b(5);
		const Array<char>	c(b);
		b[0] = 'a';
		b[1] = 'b';
		b[2] = 'c';
		b[3] = 'd';
		b[4] = 'e';

		Array<char>			d;
		d = b;
		std::cout << b.size() << std::endl;
		std::cout << c.size() << std::endl;
		std::cout << d.size() << std::endl;

		try
		{
			for (size_t i = 0; i < 6; i++)
			{
				std::cout << RED << "b._arr["<< i << "] = " << b[i] << NONE << std::endl;
				std::cout << GREEN <<"c._arr["<< i << "] = " << c[i] << NONE << std::endl;
				std::cout << SKBL << "d._arr["<< i << "] = " << d[i] << NONE << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cout << std::endl;
			std::cerr << NONE << e.what() << std::endl;
		}
	}
}