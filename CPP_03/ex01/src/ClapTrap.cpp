/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:06:38 by tforster          #+#    #+#             */
/*   Updated: 2024/11/20 18:03:28 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/ClapTrap.hpp"
#include "lib/color.hpp"
#include "lib/lib.hpp"

const std::string	CLASSNAME = BOLD H_BLU "ClapTrap " RST;

void	ClapTrap::construct_msg(const std::string &str, const std::string &className,
					const std::string &name) {
	std::cout << className << str << " (" H_BLU "Name: " GRN << name << RST ")" ENDL;
}

ClapTrap::ClapTrap(const std::string &name, const unsigned int &hitPoints,
	const unsigned int &energyPoints, const unsigned int &attackDamage):
	_name(name),
	_hitPoints(hitPoints),
	_energyPoints(energyPoints),
	_attackDamage(attackDamage) {
	#ifdef MSG
		construct_msg("Private parametric constructor", CLASSNAME, _name);
	#endif
}

ClapTrap::ClapTrap(void):
	_name(""),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {
	#ifdef MSG
		construct_msg("Default constructor", CLASSNAME, _name);
	#endif
}

ClapTrap::ClapTrap(const ClapTrap &other):
	_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage) {
	#ifdef MSG
		construct_msg("Copy constructor", CLASSNAME, _name);
	#endif
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	#ifdef MSG
		construct_msg("Copy assigment operator", CLASSNAME, _name);
	#endif
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	#ifdef MSG
		construct_msg("So long, and thanks for all the " BOLD RED "RAM!" RST, CLASSNAME, _name);
	#endif
}

ClapTrap::ClapTrap(const std::string &name):
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {
	#ifdef MSG
		construct_msg("String _name constructor", CLASSNAME, _name);
	#endif
}

void	ClapTrap::attack(const std::string& target) {
	if (str_all_space(_name))
		std::cout << CLASSNAME <<
			"How can I " GRN "attack!" RST " I don't even have a " H_RED "name" RST
			"? Identity crisis detected!" ENDL;
	else if (_hitPoints == 0)
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" Can't " GRN "attack" RST " it's " H_RED "DEAD!" RST
			" You insensible bastard" ENDL;
	else if (str_all_space(target) && _energyPoints > 0) {
		_energyPoints--;
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" Swings wildly at... absolutely " H_RED "nothing" RST
			". It seems a target would be helpful here!" ENDL;
	}
	else if (_energyPoints > 0) {
		_energyPoints--;
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" Attacks " GRN << target << RST " with all its might!"
			" This might sting.... " H_RED << _attackDamage << RST
			" damge points!" ENDL;
	}
	else
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			H_RED " Low energy..." RST " must... recharge. "
			GRN "Attack" RST " attempt failed." ENDL;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (str_all_space(_name))
		std::cout << CLASSNAME <<
			"How can I " GRN "take damage!" RST " I don't even have a " H_RED "name" RST
			"? Identity crisis detected!" ENDL;
	else if (static_cast<int>(amount) <= 0)
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" Do you call that an " H_RED "attack" RST "! How pitiful!" ENDL;
	else if (_hitPoints > 0 && _hitPoints >= amount) {
		_hitPoints -= amount;
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" Yikes! That's " H_RED << amount << RST
			" HP down. My warranty better cover this." ENDL;
	}
	else if (_hitPoints > 0 && _hitPoints < amount)
	{
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			H_RED " OVERKILL! " << amount << RST " That's " H_RED << amount - _hitPoints
			<< RST " damage points over." RST ENDL;
		_hitPoints = 0;
	}
	else
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" Stop! Stop! It's already " H_RED "DEAD" RST ENDL;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (str_all_space(_name))
		std::cout << CLASSNAME <<
			"How can I " GRN "be repaired!" RST " I don't even have a " H_RED "name" RST
			"? Identity crisis detected!" ENDL;
	else if (_hitPoints == 0)
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" Can't " GRN "be repaired" RST " it's " H_RED "DEAD!" RST
			" You insensible bastard" ENDL;
	else if (static_cast<int>(amount) <= 0)
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" I'm supposed to " GRN "repair" RST " my self! Not to explode!" ENDL;
	else if (_energyPoints > 0) {
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			" Fixing myself with " GRN << amount << RST " HP. Duct tape truly is magical! " ENDL;
		_energyPoints--;
		_hitPoints += amount;
	}
	else
		std::cout << CLASSNAME << BOLD GRN << _name << RST
			H_RED " Low energy..." RST " must... recharge. " GRN "Repair" RST " attempt failed." ENDL;
}

void	ClapTrap::displayattributes(void) {
	std::cout << CLASSNAME << BOLD GRN << _name << RST
		<< " HP: " N_RED << _hitPoints << RST
		<< " Energy: " N_RED << _energyPoints << RST
		<< " Attack: " N_RED << _attackDamage << RST ENDL;
}
