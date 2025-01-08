/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:39:02 by tforster          #+#    #+#             */
/*   Updated: 2024/11/30 17:25:45 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "include/WrongCat.hpp"
#include "lib/color.hpp"

const std::string CLASS_NAME = H_MGT " - WrongCat" RST;
const std::string WRONGCAT_BRAIN = H_YLW " Brain" RST;

WrongCat::WrongCat(void):
	WrongAnimal("WrongCat"),
	_brain(new Brain()) {
	std::cout << CLASS_NAME << " default " H_BLU "constructor." RST ENDL;
}

WrongCat::WrongCat(const WrongCat &other):
	WrongAnimal(other._type),
	_brain(other._brain) {
	std::cout << CLASS_NAME << " copy " H_BLU "constructor." RST ENDL;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
		delete _brain;
		_brain = other._brain;
	}
	std::cout << CLASS_NAME << " copy assignment operator." ENDL;
	return (*this);
}

WrongCat::~WrongCat(void) {
	delete _brain;
	std::cout << CLASS_NAME << " default " H_RED "destructor." RST ENDL;
}

void	WrongCat::makeSound(void) const {
	std::cout << BOLD GRN "Meeoow!!" RST ENDL;
}

std::string	WrongCat::getBrainAddress(void) const {
	std::ostringstream oss;
	oss << _brain;
	return (oss.str());
}

std::string	WrongCat::getIdea(std::size_t index) const {
	if (index < Brain::_brainSize) {
		if (_brain->_ideas[index].empty())
			return ("Brain is Empty");
		return (_brain->_ideas[index]);
	}
	std::cout << H_RED "ERROR:" RST " Index " << index << " is out of Brain.";
	return ("");
}

void	WrongCat::setIdea(std::string idea) {
	if (_brain->_index < Brain::_brainSize) {
		_brain->_ideas[_brain->_index] = idea;
		std::cout << CLASS_NAME << WRONGCAT_BRAIN << " add idea " << _brain->_index << ": " H_GRN << idea << RST ENDL;
		_brain->_index++;
	}
	else
		std::cout << CLASS_NAME << WRONGCAT_BRAIN << " is " ITALIC H_RED "full" RST ENDL;
}
