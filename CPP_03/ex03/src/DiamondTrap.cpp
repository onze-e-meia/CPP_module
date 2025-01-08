/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:16:24 by tforster          #+#    #+#             */
/*   Updated: 2024/11/20 19:47:53 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/DiamondTrap.hpp"
#include "include/ClapTrap.hpp"
#include "lib/color.hpp"
// #include "lib/lib.hpp"

// FIX NAMES!!!!!!!!!

const std::string	CLASSNAME = BOLD H_YLW "DiamondTrap " RST;

DiamondTrap::DiamondTrap(void): ClapTrap("", 100, 50, 30) {
	_name = ClapTrap::_name;
	ClapTrap::_name.append("_clap_trap");
	#ifdef MSG
		construct_msg("Default " H_YLW "DIAMOND" RST " constructor", CLASSNAME, _name);
	#endif
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other) {
	_name = other._name;
	#ifdef MSG
		construct_msg("Copy " H_YLW "DIAMOND" RST " constructor", CLASSNAME, _name);
	#endif
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
	}
	#ifdef MSG
		construct_msg("Copy assigment " H_YLW "DIAMOND" RST " operator", CLASSNAME, _name);
	#endif
	return (*this);
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name, 100, 50, 30) {
	_name = ClapTrap::_name;
	ClapTrap::_name.append("_clap_trap");
	#ifdef MSG
		construct_msg("String _name " H_YLW "DIAMOND" RST " constructor", CLASSNAME, _name);
	#endif
}

DiamondTrap::~DiamondTrap(void) {
	#ifdef MSG
		construct_msg(BOLD RED "IT'S NUCLEAR! KABOOMM!" RST, CLASSNAME, _name);
	#endif
}

void	DiamondTrap::whoAmI(void) {
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" Who? Name: " H_YLW << _name << RST " ClapTrap Name : " H_BLU << ClapTrap::_name << RST ENDL;
}


void	DiamondTrap::displayattributes(void) {
	std::cout << CLASSNAME << BOLD GRN << _name << RST
		<< " HP: " N_RED << _hitPoints << RST
		<< " Energy: " N_RED << _energyPoints << RST
		<< " Attack: " N_RED << _attackDamage << RST ENDL;
}
