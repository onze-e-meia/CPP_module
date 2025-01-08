/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:14:15 by tforster          #+#    #+#             */
/*   Updated: 2024/10/22 16:48:27 by tforster         ###   ########.fr       */
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

void Harl::complain(std::string level) {
	std::string		levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	complainFunc	funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; ++i) {
		if (level == levels[i]) {
			(this->*funcs[i])();
			return;
		}
	}
	std::cout << MGT "[ UNKNOWN ]\n" RST
		"Harl doesn't understand this level of complaint."
		<< std::endl;
}
