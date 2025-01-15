/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:43:06 by tforster          #+#    #+#             */
/*   Updated: 2025/01/15 15:35:22 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename Type>
void swap(Type &x0, Type &x1) {
	Type	temp = x0;
	x0 = x1;
	x1 = temp;
}

template<typename Type>
Type	min(Type &x0, Type &x1) {
	return (x0 < x1 ? x0 : x1);
}

template<typename Type>
Type	max(Type &x0, Type &x1) {
	return (x0 > x1 ? x0 : x1);
}

#endif
