/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:07:48 by tforster          #+#    #+#             */
/*   Updated: 2024/10/17 16:54:43 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "../include/Weapon.hpp"
#include <string>

class HumanA {
	private:
		std::string	_name;
		Weapon	&_weapon;

	public:
		HumanA(const std::string &name, Weapon &weapon);

		void	set_name(const std::string &name);
		void	set_weapon(Weapon &weapon);

		const Weapon	&get_weapon(void) const;

		void	attack(void);
};

#endif
