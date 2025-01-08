/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:02:09 by tforster          #+#    #+#             */
/*   Updated: 2024/12/08 19:20:27 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Cure.hpp"
#include "include/ICharacter.hpp"
#include "lib/color.hpp"

const std::string	CLASS_NAME = TEAL " - Cure " RST;

Cure::Cure(void): AMateria("cure") {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Default constructor");
	#endif
}

Cure::Cure(const Cure &other): AMateria(other){
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Copy constructor");
	#endif
}

Cure	&Cure::operator=(const Cure &other) {
	if (this != &other)
		AMateria::operator=(other);
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Copy assigment");
	#endif
	return (*this);
};

Cure::~Cure(void) {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, L_RED "Destructor" RST);
	#endif
}

AMateria	*Cure::clone() const {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Clone method");
	#endif
	return (new Cure());
}

void	Cure::use(ICharacter &target) {
	std::cout << "* use " BOLD TEAL "CURE" RST " at " L_RED << target.getName() << RST " *" ENDL;
}
