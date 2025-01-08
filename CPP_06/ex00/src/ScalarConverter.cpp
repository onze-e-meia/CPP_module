/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:10:29 by tforster          #+#    #+#             */
/*   Updated: 2024/12/19 18:03:13 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include "include/ScalarConverter.hpp"
#include "lib/color.hpp"


void	print_char(const std::string &str) {
		std::cout <<
			"char  : '" << static_cast<char>(str.at(0)) << "'" ENDL
			"int   : " << static_cast<int>(str.at(0)) << ENDL
			"float : " << static_cast<float>(str.at(0)) << ".0f" ENDL
			"double: " << static_cast<double>(str.at(0)) << ".0" ENDL;
}

bool	check_decimal(char *end, std::string str) {
	(void)str;
	if (std::strlen(end) == 0 || (std::strlen(end) == 1 && end[0] == 'f'))
		return (false);
	return (true);


	// if (std::strlen(end) > 1)
	// 	return (true);
	// else if (end[0] != 'f')
	// 	return (true);
	// return (false);
}

void	ScalarConverter::convert(const std::string &str) {

	char	*end = NULL;
	char	ch = static_cast<char>(str.at(0));;
	double	value = std::strtod(str.c_str(), &end);
	std::cout << BOLD "VALUE: " RST << value << ENDL;
	std::cout << BOLD "CHAR : " RST << ch << ENDL;
	std::cout << BOLD "SIZE : " RST << str.size() << ENDL;
	std::cout << BOLD "END  : " RST << std::strlen(end) << " \"" << end << "\"" DENDL;


	// if (value == 0 && str.size() == 1) {
	if (str.size() == 1 && !std::isdigit(str.at(0))) {
		// if (value < CHAR_MIN || value > CHAR_MAX)
		// 	std::cout << "char: impossible" ENDL;
		// if (value  == 0 && (value > CHAR_MIN && value < CHAR_BIT))
		// if (value  == 0)
		// ch = static_cast<char>(str.at(0));
		// std::cout << "char: '" << ch << "'" ENDL;
		print_char(str);
		// std::cout << "char: '" << ch << "'" ENDL;
	}
	// else if ((std::strlen(end) > 1) || (value == 0 && str.at(0) != '0' && str.at(0) != '-' && str.at(0) != '+')) {
	else if (check_decimal(end, str) || (value == 0 && str.at(0) != '0' && str.at(0) != '-' && str.at(0) != '+')) {
		std::cout <<
			"1 char  : impossible" ENDL
			"1 int   : impossible" ENDL
			"1 float : impossible" ENDL
			"1 double: impossible" ENDL;
	}

	// else if (std::strlen(end) <= 2 && std::isdigit(str.at(1)) && INT_MIN < value && value < INT_MAX) {
	else if (std::strlen(end) <= 1 && INT_MIN < value && value < INT_MAX) {
		if (CHAR_MIN > value || value > CHAR_MAX || !std::isprint(static_cast<char>(value)))
			std::cout << "char  : Nom displayable" ENDL;
		else
			std::cout << "char  : '" << static_cast<char>(value) << "'" ENDL;


		std::cout << "int   : " << static_cast<int>(value) << ENDL;
	}
	// else if (value == 0)
	else
		std::cout <<
			"2 char  : impossible" ENDL
			"2 int   : impossible" ENDL
			"2 float : impossible" ENDL
			"2 double: impossible" ENDL;
	// else
	// 	std::cout << ">>> char: '" << ch << "'" ENDL;


}

ScalarConverter::ConverterException::ConverterException(const std::string &exceptionStr):
	_exceptionStr(exceptionStr) {}

ScalarConverter::ConverterException::~ConverterException(void)  throw() {}

const char	*ScalarConverter::ConverterException::what(void) const throw() {
	return (_exceptionStr.c_str());
}
