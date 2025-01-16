/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:38:41 by tforster          #+#    #+#             */
/*   Updated: 2025/01/16 16:06:34 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>
#include "../lib/color.hpp"

template<typename Type, typename Func>
void	iter(Type *array, int size, Func func) {
	if (array == NULL)
		throw std::invalid_argument("Array pointer is null.");
	if (size <= 0)
		throw std::invalid_argument("Array pointer is equal or less then zero.");
	if (func == NULL)
		throw std::invalid_argument("Function pointer is null.");
	std::size_t	u_size = static_cast<std::size_t>(size);
	for (std::size_t i = 0; i < u_size; i++)
		func(array[i]);
}

template<typename Type>
Type	sum_one(Type &x) {return (x ++);}


template<typename Type>
void	print(Type &x) {std::cout << x << ENDL;}

#endif
