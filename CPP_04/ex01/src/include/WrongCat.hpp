/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:38:33 by tforster          #+#    #+#             */
/*   Updated: 2024/11/30 17:22:45 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include "Brain.hpp"

class	WrongCat: public WrongAnimal {
	private:
		Brain	*_brain;

	public:
		WrongCat(void);
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
		~WrongCat(void);

		void		makeSound(void) const;
		std::string	getBrainAddress(void) const;
		std::string	getIdea(std::size_t index) const;
		void		setIdea(std::string idea);
};

#endif
