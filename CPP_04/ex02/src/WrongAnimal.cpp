/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:42:45 by tforster          #+#    #+#             */
/*   Updated: 2024/11/29 18:33:12 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/WrongAnimal.hpp"
#include "lib/color.hpp"

const std::string CLASS_NAME = ORG " - WrongAnimal" RST;

WrongAnimal::WrongAnimal(std::string type): _type(type) {
	std::cout << CLASS_NAME << " protected parametric " H_BLU "constructor." RST ENDL;
}

WrongAnimal::WrongAnimal(void): _type("WrongAnimal") {
	std::cout << CLASS_NAME << " default " H_BLU "constructor." RST ENDL;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other): _type(other._type) {
	std::cout << CLASS_NAME << " copy constructor." ENDL;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other)
		_type = other._type;
	std::cout << CLASS_NAME << " copy assignment operator." ENDL;
	return (*this);
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << CLASS_NAME << " default " H_RED "destructor." RST ENDL;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << BOLD GRN "generic sound." RST ENDL;
}

std::string	WrongAnimal::getType(void) const {
	return (_type);
}
