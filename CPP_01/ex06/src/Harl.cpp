/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:14:15 by tforster          #+#    #+#             */
/*   Updated: 2024/10/22 19:58:13 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
#include "../include/Harl.hpp"
#include "../include/color.hpp"

Harl::Harl(void) {};

Harl::~Harl(void) {};

void	Harl::debug(void) {
	std::cout << H_YLW "[ DEBUG ]\n" RST
		"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
		"I really do!"
		<< std::endl;
}

void	Harl::info(void) {
	std::cout << YLW "[ INFO ]\n" RST
		"I cannot believe adding extra bacon costs more money.\n"
		"You didn't put enough bacon in my burger!\n"
		"If you did, I wouldn't be asking for more!"
		<< std::endl;
}

void	Harl::warning(void) {
	std::cout << H_RED "[ WARNING ]\n" RST
		"I think I deserve to have some extra bacon for free.\n"
		"I've been coming for years whereas you started working here since last month."
		<< std::endl;
}

void	Harl::error(void) {
	std::cout << RED "[ ERROR ]\n" RST
		"This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void Harl::complainFiltered(std::string level) {
	int levelIndex = -1;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; ++i) {
		if (level == levels[i]) {
			levelIndex = i;
			break;
		}
	}

	switch (levelIndex) {
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
