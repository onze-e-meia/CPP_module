/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:10:29 by tforster          #+#    #+#             */
/*   Updated: 2025/01/11 19:12:08 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <cstdlib>
#include <cstring>
#include "include/ScalarConverter.hpp"
#include "lib/color.hpp"

const std::string::size_type NPOS = std::string::npos;

void	print_char(const std::string &str) {
	std::cout << BOLD D_BLU "char  : " RST H_GRN "'" << static_cast<char>(str.at(0)) << "'" RST ENDL
		BOLD D_BLU "int   : " RST H_GRN << static_cast<int>(str.at(0)) << RST ENDL
		BOLD D_BLU "float : " RST H_GRN << static_cast<float>(str.at(0)) << ".0f" RST ENDL
		BOLD D_BLU "double: " RST H_GRN << static_cast<double>(str.at(0)) << ".0" RST ENDL;
}

bool	valid_decimal(char *end, std::string str) {
	if (std::strlen(end) == 0 || (std::strlen(end) == 1 && end[0] == 'f' &&
		(str.find(".") != NPOS || str.find("e") != NPOS || str == "inff" || str == "nanf")))
		return (false);
	return (true);
}

void	ScalarConverter::convert(const std::string &str) {
	char	*end = NULL;
	double	value = std::strtod(str.c_str(), &end);

	if (str.size() == 1 && !std::isdigit(str.at(0)))
		print_char(str);
	else if (valid_decimal(end, str) || str.empty() ||
		(value == 0 && str.at(0) != '.' && str.at(0) != '0' && str.at(0) != '-' && str.at(0) != '+'))
		std::cout << BOLD D_BLU "char  : " RST L_RED "Impossible" ENDL
			BOLD D_BLU "int   : " RST L_RED "Impossible" RST ENDL
			BOLD D_BLU "float : " RST L_RED "Impossible" RST ENDL
			BOLD D_BLU "double: " RST L_RED "Impossible" RST ENDL;
	else if (std::strlen(end) <= 1) {
		if (CHAR_MIN > value || value > CHAR_MAX || !std::isprint(static_cast<char>(value)))
			std::cout << BOLD D_BLU "char  : " RST COP "Nom Displayable" RST ENDL;
		else
			std::cout << BOLD D_BLU "char  : " RST H_GRN "'" << static_cast<char>(value) << "'" RST ENDL;
		cast_print<int>(value);
		cast_print<float>(value);
		cast_print<double>(value);
	}
}
