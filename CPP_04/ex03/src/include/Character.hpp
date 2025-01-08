/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:47:42 by tforster          #+#    #+#             */
/*   Updated: 2024/12/09 15:51:28 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class	AMateria;

class Character: public ICharacter {
	private:
		std::string					_name;
		std::size_t					_index;
		static const std::size_t	_iventorySize = 4;
		AMateria					*_inventory[_iventorySize];

		void	cnstr_msg(std::string class_name, std::string str) const;
		void	null_inventory(void);
		void	copy_inventory(const AMateria * const inventory[]);

	public:
		Character(void);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character(void);

		Character(const std::string &name);

		const	std::string &getName(void) const;
		void	equip(AMateria *materia);
		void	unequip(int index);
		void	use(int index, ICharacter &target);
};

#endif
