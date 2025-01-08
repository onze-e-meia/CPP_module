/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:29:23 by tforster          #+#    #+#             */
/*   Updated: 2024/12/09 15:48:19 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>
#include <string>
#include "include/AMateria.hpp"
#include "include/MateriaSource.hpp"
#include "lib/color.hpp"

const std::string	CLASS_NAME = M_ORG " - MateriaSource " RST;

void	MateriaSource::cnstr_msg(std::string class_name, std::string str) const {
	std::cout << class_name << str << ENDL;
}

void	MateriaSource::null_source(void) {
	for (std::size_t i = 0; i < _sourceSize; i++)
		_source[i] = NULL;
}

void	MateriaSource::copy_source(const AMateria *const source[]) {
	for (std::size_t i = 0; i < _sourceSize; i++)
		_source[i] = source[i] ? source[i]->clone() : NULL;
}

MateriaSource::MateriaSource(void): _index(0) {
	null_source();
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Default constructor");
	#endif
}

MateriaSource::MateriaSource(const MateriaSource &other): _index(other._index) {
	copy_source(other._source);
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Copy constructor");
	#endif
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		_index = other._index;
		copy_source(other._source);
	}
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Copy assigment");
	#endif
	return (*this);
}

MateriaSource::~MateriaSource(void) {
	for (std::size_t i = 0; i < _index; i++)
			delete _source[i];
	#ifdef MSG
		cnstr_msg(CLASS_NAME, L_RED "Destructor" RST);
	#endif
}

void	MateriaSource::learnMateria(AMateria* materia) {
	try {
		if (!materia)
			throw std::invalid_argument("Null pointer passed to learn");
		if (materia->is_equiped())
			throw std::logic_error("The materia is already learned");
		if (_index >= _sourceSize)
			throw std::overflow_error("Source is full");
		materia->equip();
		_source[_index] = materia;
		_index++;
		std::cout << materia->getType() << " added to source slot: " << _index << ENDL;
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

AMateria	*MateriaSource::createMateria(const std::string &type) {
	for (std::size_t i = 0; i < _index; i++)
		if (_source[i]->getType() == type) {
			return (_source[i]->clone());
		}
	std::cout << "Can't create " L_RED << type << RST " Materia" ENDL;
	return (NULL);
}
