/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:07:14 by tforster          #+#    #+#             */
/*   Updated: 2024/10/22 18:02:35 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "../include/Harl.hpp"
#include "../include/color.hpp"

int main(int argc, char *argv[]) {
	system("clear");
	Harl	harl;

	std::cout << BOLD GRN "START HARL FILTER" RST << std::endl;
	if (argc != 2) {
		std::cout << "Usage: ./harlFilter <log level>" << std::endl;
		return EXIT_FAILURE;
	}

	std::string	level(argv[1]);
	harl.complainFiltered(level);

	return EXIT_SUCCESS;
}
