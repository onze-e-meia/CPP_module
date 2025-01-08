/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:07:48 by tforster          #+#    #+#             */
/*   Updated: 2024/10/17 16:41:55 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/HumanA.hpp"
#include "../include/color.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon):
	_name(name),
	_weapon(weapon)
	{};

void	HumanA::set_name(const std::string &name) {
	_name = name;
}

void	HumanA::set_weapon(Weapon &weapon) {
	_weapon = weapon;
}

const Weapon	&HumanA::get_weapon(void) const {
	return _weapon;
}

void	HumanA::attack(void) {
	std::cout << BOLD GRN " - " << _name << " attacks with their "
		<< _weapon.getType() << RST << std::endl;
}
