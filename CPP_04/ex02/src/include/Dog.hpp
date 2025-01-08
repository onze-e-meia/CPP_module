/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:38:33 by tforster          #+#    #+#             */
/*   Updated: 2024/12/01 17:29:33 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal {
	private:
		Brain	*_brain;

	public:
		Dog(void);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog(void);

		void		makeSound(void) const;
		std::string	getBrainAddress(void) const;
		std::string	getIdea(std::size_t index) const;
		void		setIdea(std::string idea);
};

#endif
