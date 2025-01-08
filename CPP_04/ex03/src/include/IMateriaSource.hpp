/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:54:27 by tforster          #+#    #+#             */
/*   Updated: 2024/12/09 15:50:14 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#ifdef MSG
	#include <iostream>
	#include "../lib/color.hpp"
#endif

# include "string"

class AMateria;

class IMateriaSource {
	public:
		#ifdef MSG
			IMateriaSource(void) {
				std::cout << BRW " - IMateriaSource " RST "Default constructor" ENDL;
			};
		#endif

		virtual				~IMateriaSource(void) {};

		virtual void		learnMateria(AMateria *materia) = 0;
		virtual AMateria*	createMateria(const std::string &type) = 0;
};

#endif
