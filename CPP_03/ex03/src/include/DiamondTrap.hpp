/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:15:06 by tforster          #+#    #+#             */
/*   Updated: 2024/11/20 19:46:49 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
# include <string>

class DiamondTrap:
	public ScavTrap,
	public FragTrap {
	private:
		std::string	_name;

	public:
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap(void);

		DiamondTrap(const std::string &name);

		void	whoAmI(void);
		void	displayattributes(void);
};

#endif
