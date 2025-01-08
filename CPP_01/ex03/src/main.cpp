/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:46:06 by tforster          #+#    #+#             */
/*   Updated: 2024/10/17 17:49:11 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>
#include "../include/HumanA.hpp"
#include "../include/HumanB.hpp"
#include "../include/color.hpp"

static void	print_type(std::string str, std::string	type);

int main() {
	system("clear");
	{
		std::cout << BOLD GRN << "   ***   Test with HumanA   ***   " << RST << std::endl;
		std::string	type = "crude spiked club";
		Weapon club = Weapon(type);

		print_type(" * Create club (Weapon Class) with type: ", type);
		std::cout << " * Create bob (HumanA Class) and give it a name and Weapon using:\n"
			<< S_GRN "   HumanA " H_CYN "bob" BLU "(" S_RED "\"Bob\"," H_CYN " club" BLU ")" RST ";"
			<< std::endl;
		HumanA bob("Bob", club);
		bob.attack();

		type = "some other type of club";
		club.setType(type);
		print_type("\n * Use the Weapon Class setter to change the type: ", type);
		bob.attack();

		type = "hands";
		club = Weapon(type);
		print_type("\n * Because HumanA takes a reference to the Weapon Class,\n"
			"   we can change it without using setter: ", type);
		std::cout << RED "   But we lose access to the old Weapon Object" RST << std::endl;
		bob.attack();

		const std::string	&type_ref = club.getType();
		print_type("\n * Because the getter method of the Weapon class return a const type,\n"
			"   we can't use it to change the Weapon type: ", type_ref);

		const Weapon	&weapon_ref = bob.get_weapon();
		type = weapon_ref.getType();
		print_type("\n * We also can use the getter form the HumanA Class,\n"
			"   to get a const ref to the Weapon Class and it type: ", type);
	}

	std::cout << std::endl;
	{
		std::cout << BOLD GRN << "   ***   Test with HumanB   ***   " << RST << std::endl;
		std::string	type = "crude spiked club";
		Weapon club = Weapon(type);

		print_type(" * Create club (Weapon Class) with type: ", type);
		std::cout << " * Create jin (HumanB Class) and give it a name using:\n"
			<< S_GRN "   HumanB " H_CYN "jin" BLU "(" S_RED "\"JIN\"" BLU ")" RST ";"
			<< std::endl;
		HumanB jim("Jim");
		print_type(" * Call the setter method to give Jin a Weapon: ", club.getType());
		jim.set_weapon(club);
		jim.attack();

		type = "some other type of club";
		club.setType(type);
		print_type("\n * Use the Weapon Class setter to change the type: ", type);
		jim.attack();

		type = "hands";
		club = Weapon(type);
		print_type("\n * Because HumanB takes a pointer to the Weapon Class,\n"
			"   we can change it without using setter: ", type);
		std::cout << RED "   But we lose access to the old Weapon Object" RST << std::endl;
		jim.attack();
	}
	return 0;
}

static void	print_type(std::string str, std::string	type) {
	std::cout << str << H_CYN << type << RST << std::endl;
}
