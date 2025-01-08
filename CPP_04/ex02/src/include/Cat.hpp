/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:38:33 by tforster          #+#    #+#             */
/*   Updated: 2024/12/01 15:15:15 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal {
	private:
		Brain	*_brain;

	public:
		Cat(void);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat(void);

		void		makeSound(void) const;
		std::string	getBrainAddress(void) const;
		std::string	getIdea(std::size_t index) const;
		void		setIdea(std::string idea);
};

#endif
