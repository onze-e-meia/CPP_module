/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:39:02 by tforster          #+#    #+#             */
/*   Updated: 2024/11/30 15:48:03 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/WrongCat.hpp"
#include "lib/color.hpp"

const std::string CLASS_NAME = H_MGT " - WrongCat" RST;

WrongCat::WrongCat(void): WrongAnimal("WrongCat") {
	std::cout << CLASS_NAME << " default " H_BLU "constructor." RST ENDL;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other._type) {
	std::cout << CLASS_NAME << " copy " H_BLU "constructor." RST ENDL;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << CLASS_NAME << " copy assignment operator." ENDL;
	return (*this);
}

WrongCat::~WrongCat(void) {
	std::cout << CLASS_NAME << " default " H_RED "destructor." RST ENDL;
}

void	WrongCat::makeSound(void) const {
	std::cout << BOLD GRN "Meeoow!!" RST ENDL;
}
