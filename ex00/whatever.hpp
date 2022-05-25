/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:13:33 by srakuma           #+#    #+#             */
/*   Updated: 2021/11/23 01:12:55 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(const T &a, const T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T	max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif /* WHATEVER_HPP */
