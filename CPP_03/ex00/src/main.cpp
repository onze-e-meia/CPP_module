/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:23:17 by tforster          #+#    #+#             */
/*   Updated: 2024/11/21 17:55:11 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include "include/ClapTrap.hpp"
#include "lib/color.hpp"

int	main() {
	system("clear");

	ClapTrap	empty;
	ClapTrap	null(empty);
	std::cout << ENDL N_RED "TEST: ClapTrap with empty name" ENDL;
	empty.attack("Trash");
	empty.takeDamage(1);
	empty.beRepaired(1);

	ClapTrap	tabulation(" 	\n");
	std::cout << ENDL N_RED "TEST: ClapTrap with spaces chars name" ENDL;
	tabulation.attack("Trash");
	tabulation.takeDamage(1);
	tabulation.beRepaired(1);

	std::string name = "Trash Can";
	ClapTrap	b(name);
	std::cout << ENDL N_RED "TEST: ClapTrap with name: " GRN << name << RST ENDL;
	std::cout << N_RED "ATTACK:" RST ENDL;
	std::string target = "garbage";
	std::cout << N_RED "1 " RST ; b.attack("");
	std::cout << N_RED "2 " RST; b.attack(" 	\n");
	for (std::size_t i = 3; i <= 9 ; i++) {
		std::cout << N_RED << i << " " RST;
		b.attack(target);
	}
	std::cout << N_RED "10 " RST; b.beRepaired(5);
	std::cout << N_RED "11 " RST; b.beRepaired(5);
	std::cout << N_RED "12 " RST; b.attack(target);
	std::cout << N_RED "13 " RST; b.attack("");

	std::cout << ENDL N_RED "DAMAGE:" RST ENDL;
	b.takeDamage(-10);
	b.takeDamage(0);
	b.takeDamage(4);
	b.takeDamage(5);
	b.takeDamage(6);
	b.takeDamage(1);
	b.attack(target);
	b.beRepaired(1);

	name = "NEO Trash";
	ClapTrap	c(name);
	b = c;
	std::cout << ENDL N_RED "TEST: ClapTrap with name: " GRN << name << RST ENDL;
	b.displayattributes();
	b.beRepaired(-10);
	b.beRepaired(0);
	b.takeDamage(2);
	b.beRepaired(2);
	b.takeDamage(20);
	b.takeDamage(20);
	b.attack(target);
	b.beRepaired(-1);
	b.displayattributes();
}
