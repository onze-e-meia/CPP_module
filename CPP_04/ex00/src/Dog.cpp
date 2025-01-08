/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:39:02 by tforster          #+#    #+#             */
/*   Updated: 2024/11/30 15:47:34 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Dog.hpp"
#include "lib/color.hpp"

const std::string CLASS_NAME = H_CYN " - Dog" RST;

Dog::Dog(void): Animal("Dog") {
	std::cout << CLASS_NAME << " default " H_BLU "constructor." RST ENDL;
}

Dog::Dog(const Dog &other): Animal(other._type) {
	std::cout << CLASS_NAME << " copy " H_BLU "constructor." RST ENDL;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other)
		Animal::operator=(other);
	std::cout << CLASS_NAME << " copy assignment operator." ENDL;
	return (*this);
}

Dog::~Dog(void) {
	std::cout << CLASS_NAME << " default " H_RED "destructor." RST ENDL;
}

void	Dog::makeSound(void) const {
	std::cout << BOLD GRN "Woof! Woof!" RST ENDL;
}
