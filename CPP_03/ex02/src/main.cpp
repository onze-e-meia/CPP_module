/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:23:17 by tforster          #+#    #+#             */
/*   Updated: 2024/11/21 17:37:16 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"
#include "lib/color.hpp"

int	main() {
	system("clear");

	FragTrap	a;
	FragTrap	b("FRAG");
	FragTrap	c(b);
	c = a;

	a.attack("garbage");
	a.highFivesGuys();
	b.displayattributes();
	b.attack("garbage");
	b.attack(" ");
	b.highFivesGuys();
	b.takeDamage(50);
	b.beRepaired(100);
	b.takeDamage(1000);
	b.beRepaired(100);
	b.highFivesGuys();
	b.displayattributes();

	std::cout << ENDL N_RED "Manual delete" ENDL;
	FragTrap	*d = new FragTrap("New Scav");
	d->highFivesGuys();
	delete d;
	std::cout << N_RED "END" RST DENDL;

	ClapTrap	f("Old Clap");
	ScavTrap	g("Just Scav");
	std::cout << ENDL N_RED "Automatic delete" ENDL;
}
