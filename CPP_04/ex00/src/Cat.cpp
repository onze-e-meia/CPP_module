/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:39:02 by tforster          #+#    #+#             */
/*   Updated: 2024/11/30 15:47:44 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Cat.hpp"
#include "lib/color.hpp"

const std::string CLASS_NAME = H_MGT " - Cat" RST;

Cat::Cat(void): Animal("Cat") {
	std::cout << CLASS_NAME << " default " H_BLU "constructor." RST ENDL;
}

Cat::Cat(const Cat &other): Animal(other._type) {
	std::cout << CLASS_NAME << " copy " H_BLU "constructor." RST ENDL;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
		Animal::operator=(other);
	std::cout << CLASS_NAME << " copy assignment operator." ENDL;
	return (*this);
}

Cat::~Cat(void) {
	std::cout << CLASS_NAME << " default " H_RED "destructor." RST ENDL;
}

void	Cat::makeSound(void) const {
	std::cout << BOLD GRN "Meeoow!!" RST ENDL;
}
