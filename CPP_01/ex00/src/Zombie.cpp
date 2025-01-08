/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:42:16 by tforster          #+#    #+#             */
/*   Updated: 2024/10/14 20:44:07 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Zombie.hpp"
#include "../include/color.hpp"

Zombie::Zombie(const std::string &nameZombie):
	_nameZombie(nameZombie)
	{};

Zombie::~Zombie() {
	std::cout << "Zombie " BOLD GRN  << _nameZombie << RST " eliminated!" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << BOLD GRN << _nameZombie << RST ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_nameZombie(const std::string nameZombie) {
	_nameZombie = nameZombie;
}

std::string	Zombie::get_nameZombie(void) const {
	return _nameZombie;
}
