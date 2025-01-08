/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:37:31 by tforster          #+#    #+#             */
/*   Updated: 2024/10/14 14:07:38 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"
#include "../include/lib.hpp"
#include "../include/color.hpp"

PhoneBook::PhoneBook():
	_index(0),
	_nb_contacts(0),
	_over_load(false)
	{}

PhoneBook::~PhoneBook(){}

void	PhoneBook::add_contact(void) {
	std::string	input;

	_over_load = _buffer_over_load(_over_load);
	std::cout << GRN BOLD << "ADD " << RST
		<< GRN << "Contact number " << _index + 1 << RST << std::endl;
	for (int i = 0; i < FIELD_COUNT; i++) {
		input = _get_values(i);
		(_contacts[_index].*Contact::setters[i])(input);
	}
	std::cout << GRN BOLD << "CONTACT " << _index + 1 << RST
		GRN << " successfully added to PHONE BOOK!" << RST << std::endl;
	if (_index == TOTAL_CONTACS - 1)
		_over_load = true;
	_index = (_index + 1) % TOTAL_CONTACS;
	if (_nb_contacts < TOTAL_CONTACS)
		_nb_contacts++;
}

bool	PhoneBook::_buffer_over_load(const bool over_load) {
	if (over_load)
		error_text("CODE 12 (ENOMEM):\nOut of memory - Contact buffer exceeded!");
	return (false);
}

std::string	PhoneBook::_get_values(const std::size_t i) {
	std::string			input;
	bool				err = false;

	while (true) {
		std::cout << CYN "Input " << PROMPTS[i] << ": " << RST;
		std::getline(std::cin, input);
		if (input.empty() || str_all_space(input)) {
			err = _clear_prompt(err);
			std::cout << RED "Empty input, type a valid "
				<< BOLD << PROMPTS[i] << RST << std::endl;
		}
		else if (i == 3 && !str_all_digit(trim_spaces(input))) {
			err = _clear_prompt(err);
			std::cout << RED "Non-numeric input, type a valid "
				<< BOLD << PROMPTS[i] << RST << std::endl;
		}
		else {
			if (std::cin.eof())
				std::cout << std::endl;
			return trim_spaces(input);
		}
	}
}

void	PhoneBook::search_contact(void) const {
	const std::size_t	WIDTH = 10;
	std::string			input;
	std::ostringstream	output;
	const std::string	colors[2] = {RST, BG_CHARCOAL};

	if (_nb_contacts > 0) {
		output << BG_CYN BLK BOLD << std::setw(WIDTH) << "INDEX";
		for (std::size_t i = 0; i < 3; i++)
			output << _table_line(PROMPTS[i]);
		print_centered(output.str(), HEADER_WIDTH, RST);
		output.str("");
		output.clear();
		for (int nb = 0; nb < _nb_contacts; nb++) {
			output << colors[nb % 2] << std::setw(WIDTH) << nb + 1;
			for (std::size_t i = 0; i < 3; i++)
				output << _table_line((_contacts[nb].*Contact::getters[i])());
			print_centered(output.str(), HEADER_WIDTH, RST);
			output.str("");
			output.clear();
		}
		pick_contact();
		return ;
	}
	std::cout << RED << "No Contacts added to " BOLD "PHONE BOOK!" << RST << std::endl;
}

std::string	PhoneBook::_table_line(const std::string &str) {
	const std::size_t	WIDTH = 10;
	std::ostringstream	output;

	output << "|" << std::setw(WIDTH) << truncate(str, WIDTH, '.');
	return (output.str());
}


void	PhoneBook::pick_contact(void) const {
	std::string			input;
	std::istringstream	iss;
	bool				err = false;
	int					index;

	while (true) {
		std::cout << GRN "Pick the " BOLD "INDEX" RST GRN " of the entry to display: " << RST;
		std::getline(std::cin, input);
		if (input.empty() || str_all_space(input)) {
			err = _clear_prompt(err);
			std::cout << RED "Empty input, type a valid " BOLD "INDEX." RST << std::endl;
			continue ;
		}
		input = trim_spaces(input);
		if (str_all_digit(input)) {
			std::istringstream	iss(input);
			iss >> index;
			if (index <=  0 || index >= _nb_contacts + 1) {
				err = _clear_prompt(err);
				std::cout << RED BOLD "INDEX" RST RED " out of Bounds!" << std::endl;
			}
			else {
				if (std::cin.eof())
					std::cout << input << std::endl;
				_display_contact(_contacts[index - 1]);
				break ;
			}
		}
		else {
			err = _clear_prompt(err);
			std::cout << RED "Invalid input, type a valid " BOLD "INDEX." RST << std::endl;
		}
	}
}

void	PhoneBook::_display_contact(const Contact &_contact) {
	for (std::size_t i = 0; i < FIELD_COUNT; i++)
		std::cout << _field_name(i) << " "
			<< (_contact.*Contact::getters[i])() << std::endl;
}

std::string	PhoneBook::_field_name(const std::size_t i) {
	const std::size_t	LEN = 14;
	std::ostringstream	oss;

	oss << BG_CYN BOLD BLK << std::setw(LEN) << PROMPTS[i] << ":" << RST;
	return (oss.str());
}

bool PhoneBook::_clear_prompt(const bool err) {
	if (std::cin.eof())
		std::cout << std::endl;
	std::cin.clear();
	std::clearerr(stdin);
	std::cout << UP_LN CL_LN;
	if (err)
		std::cout << UP_LN CL_LN;
	return (true);
}
