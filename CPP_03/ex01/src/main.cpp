/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:23:17 by tforster          #+#    #+#             */
/*   Updated: 2024/11/21 17:38:20 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "include/ScavTrap.hpp"
#include "lib/color.hpp"

int	main() {
	system("clear");

	ScavTrap	a;
	ScavTrap	b("SCAV");
	ScavTrap	c(b);
	c = a;

	a.attack("garbage");
	a.guardGate();
	b.displayattributes();
	b.attack("garbage");
	b.attack(" ");
	b.guardGate();
	b.takeDamage(50);
	b.beRepaired(100);
	b.takeDamage(1000);
	b.beRepaired(100);
	b.guardGate();
	b.displayattributes();

	std::cout << ENDL N_RED "Manual delete" ENDL;
	ScavTrap	*d = new ScavTrap("New Scav");
	std::cout << ENDL N_RED "Automatic delete" ENDL;
	delete d;
}
