/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:00:16 by tforster          #+#    #+#             */
/*   Updated: 2024/10/30 13:17:59 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iostream>
#include "../include/Zombie.hpp"
#include "../include/color.hpp"

static void	killcheck_zombie(const Zombie *zombie);

int	main(void) {
	system("clear");
	std::cout << BG_GRN BLK "*** Assemble the horde!!! ***\n" RST << std::endl;
	std::cout << BG_GRN BLK "* Create Zombie from Class Constructor, using a std::string:" RST << std::endl;
	std::string	name = "Sir Stumbleton Shambles";
	Zombie	z_00(name);
	z_00.announce();

	std::cout << BG_GRN BLK "* Create Zombie from Class Constructor, using a string literal:" RST << std::endl;
	Zombie	z_01("Lord Rottingham McDecay");
	z_01.announce();

	std::cout << BG_GRN BLK "* Create Zombie from newZombie() function:" RST << std::endl;
	std::cout << BG_GRN BLK "** You should kill it after!!" << RST << std::endl;
	Zombie	*z_02  = newZombie("Baron Von Brainsnack");
	z_02->announce();

	std::cout << BG_GRN BLK "* Create Zombie from randomChump() function:" << RST << std::endl;
	std::cout << BG_GRN BLK "** It will born DEAD! (stack)" << RST << std::endl;
	randomChump("Lady Gutsalot the Grim");

	std::cout << BG_GRN BLK "* Create Zombie using keyword new:" RST << std::endl;
	std::cout << BG_GRN BLK "** You should kill it after!!" << RST << std::endl;
	Zombie* z_04 = new Zombie("Count Draggingfoot");
	z_04->announce();

	std::cout << std::endl;
	std::cout << BG_GRN BLK "* Check the Zombies to " BOLD "KILL:" RST << std::endl;
	killcheck_zombie(z_02);
	killcheck_zombie(z_04);
	std::cout << BG_GRN BLK "* Kill the Zombies: (heap)" RST << std::endl;
	delete z_02;
	delete z_04;
	z_02 = NULL;
	z_04 = NULL;
	std::cout << BG_GRN BLK "* Check the Zombies to " BOLD "KILL:" RST << std::endl;
	killcheck_zombie(z_02);
	killcheck_zombie(z_04);

	std::cout << BG_GRN BLK "* Leftover Zombies: (stack)" RST << std::endl;
	return EXIT_SUCCESS;
}

void	killcheck_zombie(const Zombie *zombie) {
	if (zombie)
		std::cout << BOLD GRN << zombie->get_nameZombie() << RST " is " BOLD "alive!" << RST << std::endl;
	else
		std::cout << "Zombie is " BOLD "DEAD!" RST << std::endl;
}
