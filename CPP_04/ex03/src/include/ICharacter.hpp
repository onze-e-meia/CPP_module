/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:22:13 by tforster          #+#    #+#             */
/*   Updated: 2024/12/09 15:50:59 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#ifdef MSG
	#include <iostream>
	#include "../lib/color.hpp"
#endif

# include <string>

class	AMateria;

class ICharacter {
	public:
		#ifdef MSG
			ICharacter(void) {
				std::cout << GRN " - ICharacter " RST "Default constructor" ENDL;
			};
		#endif

		virtual						~ICharacter(void) {};

		virtual	const std::string	&getName(void) const = 0;
		virtual	void				equip(AMateria *materia) = 0;
		virtual	void				unequip(int index) = 0;
		virtual	void				use(int index, ICharacter &target) = 0;
};

#endif
