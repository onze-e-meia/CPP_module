/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:58:27 by tforster          #+#    #+#             */
/*   Updated: 2024/10/17 17:06:57 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "../include/Weapon.hpp"
#include <string>

class HumanB {
	private:
		std::string	_name;
		Weapon	*_weapon;

	public:
		HumanB(const std::string &name);

		void	set_name(const std::string &name);
		void	set_weapon(Weapon &weapon);

		void	attack(void);
};

#endif
