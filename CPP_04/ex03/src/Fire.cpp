/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:02:09 by tforster          #+#    #+#             */
/*   Updated: 2024/12/08 19:20:23 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Fire.hpp"
#include "include/ICharacter.hpp"
#include "lib/color.hpp"

const std::string	CLASS_NAME = H_RED " - Fire " RST;

Fire::Fire(void): AMateria("fire") {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Default constructor");
	#endif
}

Fire::Fire(const Fire &other): AMateria(other){
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Copy constructor");
	#endif
}

Fire	&Fire::operator=(const Fire &other) {
	if (this != &other)
		AMateria::operator=(other);
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Copy assigment");
	#endif
	return (*this);
};

Fire::~Fire(void) {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, L_RED "Destructor" RST);
	#endif
}

AMateria	*Fire::clone() const {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Clone method");
	#endif
	return (new Fire());
}

void	Fire::use(ICharacter &target) {
	std::cout << "* shoots an " BOLD H_RED "FIRE" RST " blast at " L_RED << target.getName() << RST " *" ENDL;
}
