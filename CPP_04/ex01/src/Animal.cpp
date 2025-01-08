/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:42:45 by tforster          #+#    #+#             */
/*   Updated: 2024/11/30 18:48:18 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Animal.hpp"
#include "lib/color.hpp"

const std::string CLASS_NAME = ORG " - Animal" RST;

Animal::Animal(std::string type): _type(type) {
	std::cout << CLASS_NAME << " protected parametric " H_BLU "constructor." RST ENDL;
}

Animal::Animal(void): _type("Animal") {
	std::cout << CLASS_NAME << " default " H_BLU "constructor." RST ENDL;
}

Animal::Animal(const Animal &other): _type(other._type) {
	std::cout << CLASS_NAME << " copy constructor." ENDL;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other)
		_type = other._type;
	std::cout << CLASS_NAME << " copy assignment operator." ENDL;
	return (*this);
}

Animal::~Animal(void) {
	std::cout << CLASS_NAME << " default " H_RED "destructor." RST ENDL;
}

void	Animal::makeSound(void) const {
	std::cout << BOLD GRN "generic sound" RST ENDL;
}

std::string	Animal::getType(void) const {
	return (_type);
}

std::string	Animal::getBrainAddress(void) const {
	std::cout << H_RED "ERROR:" RST " Generic" << CLASS_NAME << " don't hava a Brain!" ENDL;
	return ("");
}

std::string	Animal::getIdea(std::size_t index) const {
	(void) index;
	std::cout << H_RED "ERROR:" RST " Generic" << CLASS_NAME << " don't hava a Brain!" ENDL;
	return ("");
}

void	Animal::setIdea(std::string idea) {
	(void) idea;
	std::cout << H_RED "ERROR:" RST " Generic" << CLASS_NAME << " don't hava a Brain!" ENDL;
}
