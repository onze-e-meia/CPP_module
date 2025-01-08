/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:58:29 by tforster          #+#    #+#             */
/*   Updated: 2024/10/17 17:00:01 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/HumanB.hpp"
#include "../include/color.hpp"

HumanB::HumanB(const std::string &name):
	_name(name)
	{};

void	HumanB::set_name(const std::string &name) {
	_name = name;
}

void	HumanB::set_weapon(Weapon &weapon) {
	_weapon = &weapon;
}

void	HumanB::attack(void) {
	std::cout << BOLD GRN " - " << _name << " attacks with their "
		<< _weapon->getType() << RST << std::endl;
}
