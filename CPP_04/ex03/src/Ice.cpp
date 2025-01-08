/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:02:09 by tforster          #+#    #+#             */
/*   Updated: 2024/12/08 17:57:59 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Ice.hpp"
#include "include/AMateria.hpp"
#include "include/ICharacter.hpp"
#include "lib/color.hpp"

const std::string	CLASS_NAME = V_BLU " - ICE " RST;

Ice::Ice(void): AMateria("ice") {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Default constructor");
	#endif
}

Ice::Ice(const Ice &other): AMateria(other){
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Copy constructor");
	#endif
}

Ice	&Ice::operator=(const Ice &other) {
	if (this != &other)
		AMateria::operator=(other);
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Copy assigment");
	#endif
	return (*this);
};

Ice::~Ice(void) {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, L_RED "Destructor" RST);
	#endif
}

AMateria	*Ice::clone() const {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Clone method");
	#endif
	return (new Ice());
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an " BOLD V_BLU "ICE" RST " bolt at " L_RED << target.getName() << RST " *" ENDL;
}
