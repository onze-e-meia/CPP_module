/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:14:57 by tforster          #+#    #+#             */
/*   Updated: 2024/10/22 17:48:22 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include "../include/Harl.hpp"
#include "../include/color.hpp"

int main()
{
	system("clear");
	Harl harl;
	const std::size_t		nb_lvl = 5;
	std::string		levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", "UNKNOWN"};

	std::cout << BOLD GRN "START HARL V2.0" RST;
	for (std::size_t i = 0; i < nb_lvl; i++) {
		std::cout << BOLD GRN "\nTesting " << levels[i] <<" level:" RST << std::endl;
		harl.complain(levels[i]);
	}
	return EXIT_SUCCESS;
}
