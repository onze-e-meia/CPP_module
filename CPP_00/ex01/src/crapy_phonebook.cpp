/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:50:07 by tforster          #+#    #+#             */
/*   Updated: 2024/10/14 14:17:15 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "../include/PhoneBook.hpp"
#include "../include/lib.hpp"
#include "../include/color.hpp"

static void	header(void);
static bool	cmd_empty(const std::string &input, bool *err);
std::size_t	cmd_add(PhoneBook &phonebook, const std::size_t nb);
static void	cmd_search(PhoneBook &phonebook);
static void	cmd_exit(const std::size_t nb);
static bool	cmd_invalid(void);

int main(void)
{
	std::size_t		nb = 0;
	std::string		input;
	PhoneBook		phonebook;
	bool			err = false;

	header();
	while (true)
	{
		std::cout << CYN BOLD "COMMAND: " RST;
		if (!std::getline(std::cin, input)) {
			std::cin.clear();
			freopen("/dev/tty", "r", stdin);
			std::cout << CL_LN UP_LN;
			if (err)
				std::cout << CL_LN UP_LN;
			err = true;
			std::cout << std::endl
				<< RED BOLD "EOF" RST RED" (Ctrl+D) received. Switching to manual input."
				<< std::endl;
			continue ;
		}
		else if (cmd_empty(input, &err))
			continue ;
		input = trim_spaces(input);
		if (input == "ADD")
			nb = cmd_add(phonebook, nb);
		else if (input == "SEARCH")
			cmd_search(phonebook);
		else if (input == "EXIT") {
			cmd_exit(nb);
			break;
		}
		else
			err = cmd_invalid();
	}
	return (0);
}

static void	header(void) {
	system("clear");
	print_centered("PHONE BOOK.", HEADER_WIDTH, BOLD);
	print_centered("Welcome to the 80s and their unbelievable technology!", HEADER_WIDTH, RST);
	print_centered("Save all your contacs in one place!", HEADER_WIDTH, RST);
	print_centered("COMMANDS:", HEADER_WIDTH, BOLD);
	print_centered(BOLD "ADD" RST " to save a new Contact.", HEADER_WIDTH, RST);
	print_centered(BOLD "SEARCH" RST " for specific Contact Details.", HEADER_WIDTH, RST);
	print_centered(BOLD "EXIT" RST " to exit and save your new Contacts!", HEADER_WIDTH, RST);
	std::cout << std::endl;
}

static bool	cmd_empty(const std::string &input, bool *err) {
	if (input.empty() || str_all_space(input)) {
		header();
		std::cin.clear();
		std::clearerr(stdin);
		std::cout << RED "Empty input, type a valid " << BOLD "COMMAND." RST << std::endl;
		*err = true;
		return (true);
	}
	return (false);
}

std::size_t	cmd_add(PhoneBook &phonebook, const std::size_t nb) {
	header();
	phonebook.add_contact();
	return ((nb < TOTAL_CONTACS) * (nb + 1) + (nb == TOTAL_CONTACS) * nb);
}

static void	cmd_search(PhoneBook &phonebook) {
	header();
	phonebook.search_contact();
}

static void cmd_exit(const std::size_t nb) {
	header();
	if (nb == 0)
		std::cout << GRN BOLD "EXIT" RST
		<< GRN " PHONE BOOK, no Contacts to save!" RST << std::endl;
	else
		error_text("CODE 13 (EACCES):\nPermission denied - Failed to save contacts!");
}

static bool	cmd_invalid(void) {
	header();
	std::cout << RED "Invalid input, type a valid " << BOLD "COMMAND." RST << std::endl;
	return (true);
}
