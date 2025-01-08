/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:03:49 by tforster          #+#    #+#             */
/*   Updated: 2024/11/30 16:56:25 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {
	private:
		void	copy_ideas(const Brain &other);

	public:
		static const std::size_t	_brainSize = 100;
		std::size_t	_index;
		std::string	_ideas[_brainSize];

		Brain(void);
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain(void);
};

#endif
