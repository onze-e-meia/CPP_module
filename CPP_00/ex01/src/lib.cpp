/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:56:41 by tforster          #+#    #+#             */
/*   Updated: 2024/10/14 13:27:54 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "../include/lib.hpp"
#include "../include/color.hpp"

void	print_centered(const std::string& str, const int width, const char *format) {
	const std::size_t	padding = (width - strip_ansi(str).length()) / 2;
	std::cout << format << std::setw(padding + str.length()) << str << RST << std::endl;
}

void	error_text(const std::string &str) {
	std::time_t	now = time(0);
	std::tm		*ltm = localtime(&now);

	std::cerr << RED BOLD "ERROR"  RST RED << " ["
		<< 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday << " "
		<< ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec
		<< "] " << str << RST << std::endl;
}

bool	str_all_digit(const std::string &str) {
	const size_t	len = str.length();

	if (len == 0)
		return (false);
	for (std::size_t i = 0; i < len; ++i)
	{
		if (std::isdigit(static_cast<unsigned char>(str[i])))
			continue ;
		else
			return (false);
	}
	return (true);
}

bool	str_all_space(const std::string &str) {
	const std::size_t	len = str.length();

	if (len == 0)
		return (false);
	for (std::size_t i = 0; i < len; ++i) {
		if (std::isspace(static_cast<unsigned char>(str[i])))
			continue ;
		else
			return (false);
	}
	return (true);
}

std::string trim_spaces(const std::string &str) {
	std::istringstream	iss(str);
	std::string			word;
	std::ostringstream	oss;
	bool				first_word = true;

	while (iss >> word) {
		if (!first_word)
			oss << ' ';
		oss << word;
		first_word = false;
	}
	return oss.str();
}

std::string	truncate(const std::string &str, const std::size_t width, const char ch) {
	if (str.length() > width)
		return str.substr(0, width - 1) + ch;
	return (str);
}

std::string strip_ansi(const std::string &str) {
	const std::size_t	len = str.length();
	std::ostringstream	output;

	for (size_t i = 0; i < len; ++i) {
		if (str[i] == '\033') {
			while (i < len && str[i] != 'm')
				i++;
			if (i < len && str[i] == 'm')
				continue ;
		}
		output << str[i];
	}
	return (output.str());
}
