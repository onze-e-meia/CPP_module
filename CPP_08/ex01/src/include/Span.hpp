/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:24:16 by tforster          #+#    #+#             */
/*   Updated: 2025/01/22 18:22:17 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <ostream>
#include <vector>

class	Span {
	private:
		std::vector<int>	_vector;
		unsigned int		_size;


	public:
		Span(void);
		Span(int size);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span(void);

		int		shortestSpan(void) const;
		int		longestSpan(void) const;
		void	addNumber(int integer);
		void	randomFill(void);

		unsigned int				size() const;
		unsigned int				max_size() const;
		const std::vector<int>::const_iterator	begin() const;
		const std::vector<int>::const_iterator	end() const;
		std::vector<int>::iterator	begin();
		std::vector<int>::iterator	end();

		const int	&operator[](const std::size_t &index) const;
		int			&operator[](const std::size_t &index);

};

std::ostream &operator<<(std::ostream &os, Span &span);
std::ostream &operator<<(std::ostream &os, const Span &span);

#endif
