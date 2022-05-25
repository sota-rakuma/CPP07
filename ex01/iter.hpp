/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 01:14:18 by srakuma           #+#    #+#             */
/*   Updated: 2021/12/03 16:04:57 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T* ptr, size_t len, void (*f)(T&))
{
	for (size_t i = 0; i < len; i++)
	{
		f(ptr[i]);
	}
}

template <typename T>
void	iter(T const * ptr, size_t len, void (*f)(T const &))
{
	for (size_t i = 0; i < len; i++)
	{
		f(ptr[i]);
	}
}

#endif /* ITER_HPP */
