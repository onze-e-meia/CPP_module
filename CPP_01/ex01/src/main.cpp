/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:00:16 by tforster          #+#    #+#             */
/*   Updated: 2024/11/30 16:44:25 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <string>
#include <iostream>
#include "../include/Zombie.hpp"
#include "../include/color.hpp"

static void	horde_annouce(Zombie *horde, const std::size_t N);

int	main(void) {
	system("clear");
	std::size_t	N = 0;
	Zombie	*horde;
	std::cout << BOLD GRN "Create the hordeless, " BOLD "N = " << N << RST << std::endl;
	horde = zombieHorde(N, "hordeless");
	horde_annouce(horde, N);

	N = 1;
	std::cout << BOLD GRN "Create ONE Zombie horde, " BOLD "N = " << N << RST << std::endl;
	horde = zombieHorde(N, "Shirley Shufflebottom");
	horde_annouce(horde, N);
	std::cout << BOLD RED "Delete" GRN " the HORDE!" RST << std::endl;
	delete[] horde;
	horde = NULL;
	std::cout << std::endl;

	N = 7;
	std::cout << BOLD GRN "Create Zombie horde, " BOLD "N = " << N << RST << std::endl;
	horde = zombieHorde(N, "Lady Loosened Joints");
	horde_annouce(horde, N);
	std::cout << BOLD RED "Delete" GRN " the HORDE!" RST << std::endl;
	delete []horde;
	horde = NULL;
	std::cout << std::endl;

	std::cout << BOLD GRN "No Horde left to eleminate!" RST << std::endl;
	return EXIT_SUCCESS;
}

static void	horde_annouce(Zombie *horde, const std::size_t N) {
	if (!horde)
		std::cout << "No horde was created!\n" << std::endl;
	else {
		for (std::size_t i = 0; i < N; i++) {
			std::cout << i + 1 << " ";
			horde[i].announce();
		}
	}
}
