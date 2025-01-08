/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:34:36 by tforster          #+#    #+#             */
/*   Updated: 2024/11/30 18:41:54 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class	Animal {
	protected:
		std::string	_type;
		Animal(std::string type);

	public:
		Animal(void);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal(void);

		virtual void		makeSound(void) const;
		std::string			getType(void) const;
		virtual std::string	getBrainAddress(void) const;
		virtual std::string	getIdea(std::size_t index) const;
		virtual void		setIdea(std::string idea);
};

#endif
