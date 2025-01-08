/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:43:09 by tforster          #+#    #+#             */
/*   Updated: 2024/10/17 16:17:04 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"
#include <string>

Weapon::Weapon(): _type("bare hands") {};
Weapon::Weapon(const std::string &type): _type(type) {};


void	Weapon::setType(std::string type) {
	_type = type;
}

const std::string	&Weapon::getType(void) const {
	return _type;
}
