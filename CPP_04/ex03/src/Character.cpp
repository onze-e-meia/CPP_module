/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:49:34 by tforster          #+#    #+#             */
/*   Updated: 2024/12/09 15:37:50 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <cstddef>
#include <cstddef>
#include <iostream>
// #include <string>
#include "include/Character.hpp"
#include "include/AMateria.hpp"
#include "lib/color.hpp"

const std::string	CLASS_NAME = H_GRN " - Character " RST;

void	Character::cnstr_msg(std::string class_name, std::string str) const {
	std::cout << class_name << str << ENDL;
}

void	Character::null_inventory(void) {
	for (std::size_t i = 0; i < _iventorySize; i++)
		_inventory[i] = NULL;
}

void	Character::copy_inventory(const AMateria *const inventory[]) {
	for (std::size_t i = 0; i < _iventorySize; i++)
		_inventory[i] = inventory[i] ? inventory[i]->clone() : NULL;
}

Character::Character(void): _name("Cid"), _index(0) {
	null_inventory();
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Default constructor");
	#endif
}

Character::Character(const Character &other): _name(other._name), _index(other._index) {
	copy_inventory(other._inventory);
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Copy constructor");
	#endif
}

Character	&Character::operator=(const Character &other) {
	if (this != &other) {
		_name = other._name;
		_index = other._index;
		copy_inventory(other._inventory);
	}
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Copy assigment");
	#endif
	return (*this);
}

Character::~Character(void) {
	for (std::size_t i = 0; i < _index; i++)
		delete _inventory[i];
	#ifdef MSG
		cnstr_msg(CLASS_NAME, L_RED "Destructor" RST);
	#endif
}

Character::Character(const std::string &name): _name(name), _index(0) {
	null_inventory();
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "String name constructor");
	#endif
}

const	std::string &Character::getName(void) const {
	return (_name);
}

void	Character::equip(AMateria* materia) {
	try {
		if (!materia)
			throw std::invalid_argument("Null pointer passed to equip");
		if (materia->is_equiped())
			throw std::logic_error("The materia is already equipped");
		if (_index >= _iventorySize)
			throw std::overflow_error("Inventory is full");
		materia->equip();
		_inventory[_index] = materia;
		_index++;
		std::cout << H_GRN << _name << RST " equipped " << materia->getType() << " in inventory slot: " << _index << ENDL;
	} catch (const std::invalid_argument& e) {
		std::cerr << L_RED << "Equip Error: " RST << e.what() << ENDL;
	} catch (const std::logic_error& e) {
		std::cerr << L_RED << "Equip Logic Error: " RST << e.what() << ENDL;
	} catch (const std::overflow_error& e) {
		std::cerr << L_RED << "Equip Overflow: " RST << e.what() << ENDL;
	} catch (...) {
		std::cerr << L_RED << "An unknown error occurred during equip" << RST << ENDL;
	}
}

void	Character::unequip(int index) {
	std::cout << "Unequip " << _inventory[index]->getType() << " from " << _name << ENDL;
	_inventory[index] = NULL;
}

void	Character::use(int index, ICharacter &target) {
	if (static_cast<std::size_t>(index) >= _index) {
		std::cout << "Inventory is empty or out of bounds" ENDL;
		return ;
	}
	std::cout << H_GRN << _name << RST " ";
	_inventory[index]->use(target);
}
