/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:16:24 by tforster          #+#    #+#             */
/*   Updated: 2024/11/21 17:34:15 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/ScavTrap.hpp"
#include "lib/color.hpp"
#include "lib/lib.hpp"

const std::string	CLASSNAME = BOLD H_CYN "ScavTrap " RST;

ScavTrap::ScavTrap(void): ClapTrap("", 100, 50, 20) {
	#ifdef MSG
		construct_msg("Default " H_CYN "SCAV" RST " constructor", CLASSNAME, _name);
	#endif
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other) {
	#ifdef MSG
		construct_msg("Copy " H_CYN "SCAV" RST " constructor", CLASSNAME, _name);
	#endif
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other)
		ClapTrap::operator=(other);
	#ifdef MSG
		construct_msg("Copy assigment " H_CYN "SCAV" RST " operator", CLASSNAME, _name);
	#endif
	return (*this);
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name, 100, 50, 20) {
	#ifdef MSG
		construct_msg("String _name " H_CYN "SCAV" RST " constructor", CLASSNAME, _name);
	#endif
}

ScavTrap::~ScavTrap(void) {
	#ifdef MSG
		construct_msg(BOLD RED "Memory" RST " freed, and so am I. Peace out!", CLASSNAME, _name);
	#endif
}

void	ScavTrap::attack(const std::string& target) {
	if (str_all_space(_name))
		std::cout << CLASSNAME <<
			"How can I " GRN "attack!" RST " I don't even have a " H_RED "name" RST
			"? Give me a name!" ENDL;
	else if (_hitPoints == 0)
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" Can't " GRN "attack" RST " it's " H_RED "DEAD!" RST ENDL;
	else if (str_all_space(target) && _energyPoints > 0) {
		_energyPoints--;
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" Swings wildly and wildly and wildly at " H_RED "nothing" RST
			". A target would be good" ENDL;
	}
	else if (_energyPoints > 0) {
		_energyPoints--;
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" Preparing an attack on " GRN << target << RST "! Watch out for "
			H_RED << _attackDamage << RST " damge points!" ENDL;
	}
	else
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			H_RED " Low energy..." RST " can't "
			GRN "attack" RST "! Attempt failed." ENDL;
}

void	ScavTrap::guardGate(void) {
	if (str_all_space(_name))
		std::cout << CLASSNAME <<
			"I can't " GRN "guard!" RST " anything without a proper " H_RED "name" RST
			"? Give me a name!" ENDL;
	else if (_hitPoints == 0)
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" Can't " GRN "guard" RST " anything! It's f****g " H_RED "DEAD!" RST ENDL;
	else if (_energyPoints > 0) {
		_energyPoints--;
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" is in the scrapyard on " GRN "Gate keeper mode" ENDL;
	}
	else
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			H_RED " Low energy..." RST " can't "
			GRN "guard" RST "! Attempt failed." ENDL;
}

void	ScavTrap::displayattributes(void) {
	std::cout << CLASSNAME << BOLD GRN << _name << RST
		<< " HP: " N_RED << _hitPoints << RST
		<< " Energy: " N_RED << _energyPoints << RST
		<< " Attack: " N_RED << _attackDamage << RST ENDL;
}
