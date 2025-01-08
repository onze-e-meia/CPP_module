/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:58:18 by tforster          #+#    #+#             */
/*   Updated: 2024/10/17 14:05:34 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {
	private:
		std::string _type;

	public:
		Weapon();
		Weapon(const std::string &type);

		void				setType(std::string type);
		const std::string	&getType(void) const;
};

#endif
