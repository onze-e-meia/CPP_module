/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:07:53 by tforster          #+#    #+#             */
/*   Updated: 2024/12/09 15:53:38 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/AMateria.hpp"
#include "lib/color.hpp"

#include "include/ICharacter.hpp"

const std::string	CLASS_NAME = ORG " - AMateria " RST;

void	AMateria::cnstr_msg(std::string class_name, std::string str) const {
	std::cout << class_name << str << ENDL;
}

AMateria::AMateria(void): _type("NONE"), _equiped(false) {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Default constructor");
	#endif
}

AMateria::AMateria(const AMateria &other): _type(other._type), _equiped(other._equiped) {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Copy constructor");
	#endif
}

AMateria	&AMateria::operator=(const AMateria &other) {
	if (this != &other) {
		_type = other._type;
		_equiped = other._equiped;
	}
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Copy assigment");
	#endif
	return (*this);
}

AMateria::~AMateria(void) {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, L_RED "Destructor" RST);
	#endif
}

AMateria::AMateria(const std::string &type): _type(type), _equiped(false) {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "String type constructor");
	#endif
}

const	std::string	&AMateria::getType() const {
	return (_type);
}

bool	AMateria::is_equiped(void) {
	return (_equiped);
}

void	AMateria::equip(void) {
	_equiped = true;
}
