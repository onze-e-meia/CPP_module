/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:17:53 by tforster          #+#    #+#             */
/*   Updated: 2025/01/22 16:11:47 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <ostream>

template<typename Type>
class Array {
	private:
		Type		*_elements;
		std::size_t	_size;

	public:
		Array(void);
		Array(int size);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array(void);

		std::size_t	size() const;

		const Type	&operator[](const std::size_t &index) const;
		Type		&operator[](const std::size_t &index);
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &src);

# include "Array.tpp"

#endif
