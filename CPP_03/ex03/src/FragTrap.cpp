/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:16:24 by tforster          #+#    #+#             */
/*   Updated: 2024/11/27 16:38:13 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/FragTrap.hpp"
#include "lib/color.hpp"
#include "lib/lib.hpp"

const std::string	CLASSNAME = BOLD H_MGT "FragTrap " RST;

FragTrap::FragTrap(void): ClapTrap("", 100, 100, 30) {
	#ifdef MSG
		construct_msg("Default " H_MGT "FRAG" RST " constructor", CLASSNAME, _name);
	#endif
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other) {
	#ifdef MSG
		construct_msg("Copy " H_MGT "FRAG" RST " constructor", CLASSNAME, _name);
	#endif
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other)
		ClapTrap::operator=(other);
	#ifdef MSG
		construct_msg("Copy assigment " H_MGT "FRAG" RST " operator", CLASSNAME, _name);
	#endif
	return (*this);
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name, 100, 100, 30) {
	#ifdef MSG
		construct_msg("String _name " H_MGT "FRAG" RST " constructor", CLASSNAME, _name);
	#endif
}

FragTrap::~FragTrap(void) {
	#ifdef MSG
		construct_msg(BOLD RED "EXPLODES!" RST " Good riddance!", CLASSNAME, _name);
	#endif
}

void	FragTrap::highFivesGuys(void) {
	if (str_all_space(_name))
		std::cout << CLASSNAME <<
			"I will not " GRN "high-five" RST " without a " H_RED "name" RST
			"? Give me a name!" ENDL;
	else if (_hitPoints == 0)
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" Can't " GRN "high-five" RST " anything! It's f****g " H_RED "DEAD!" RST ENDL;
	else if (_energyPoints > 0) {
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" high-fiving days are over. No more awkward palm slaps or asking for validation—finally, some peace for its circuits." ENDL;
		_energyPoints--;
	}
	else
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			H_RED " Low energy..." RST " can't "
			GRN "high-five" RST "! Attempt failed." ENDL;
}

void	FragTrap::displayattributes(void) {
	std::cout << CLASSNAME << BOLD GRN << _name << RST
		<< " HP: " N_RED << _hitPoints << RST
		<< " Energy: " N_RED << _energyPoints << RST
		<< " Attack: " N_RED << _attackDamage << RST ENDL;
}
