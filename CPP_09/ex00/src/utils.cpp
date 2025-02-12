/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:10:11 by tforster          #+#    #+#             */
/*   Updated: 2025/02/12 18:55:54 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <ctime>
#include "include/utils.hpp"
#include "lib/color.hpp"

bool	str_all_space(const std::string &str) {
	const std::size_t	len = str.length();

	if (len == 0)
		return (true);
	for (std::size_t i = 0; i < len; ++i) {
		if (std::isspace(static_cast<unsigned char>(str[i])))
			continue ;
		return (false);
	}
	return (true);
}

std::ifstream	*openFile(const std::string &path) {
	std::ifstream	*file;
	file = new std::ifstream(path.c_str());
	try {
		if (!file->is_open()) {
			std::ostringstream	oss;
			oss << L_RED "Error: " RST "Can't open " << path;
			delete file;
			throw (std::runtime_error(oss.str()));
		}
	} catch (const std::runtime_error &e) {
		std::cerr << e.what() << ENDL;
		return (NULL);
	}
	return (file);
}

bool	isValidDay(int year, int month, int day) {
	year += 1900;
	int	leapYear = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	int	daysMoth[] = {31, 28 + leapYear, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return (day >= 1 && day <= daysMoth[month]);
}

bool	isValidDate(const char *ptr, const std::string &rawDate,
	const std::string &line, std::tm &tmS, std::time_t startDate, int i) {
	if (!ptr) {
		std::cout << L_RED "Err Line " BOLD << i << ": " RST
			<< "Invalid date \"" <<  rawDate << "\"" RENDL;
		return (false);
	}

	std::string	str(ptr);
	if (!str_all_space(str)) {
		std::cout << L_RED "Err line " BOLD << i << ": "
			<< RST "Bad input fomat \"" << line << "\"" RENDL;
		return (false);
	} else if (!isValidDay(tmS.tm_year, tmS.tm_mon, tmS.tm_mday) || !str_all_space(str)) {
		std::cout << L_RED "Err Line " BOLD << i << ": " RST
			<< "Invalid date \"" <<  rawDate << "\"" RENDL;
		return (false);
	} else {
		char buffer[2][20];
		std::time_t	dateValue = mktime(&tmS);

		strftime(buffer[0], 80, "%Y-%m-%d", &tmS);
		if (dateValue < startDate) {
			std::tm	*tm_StartDate = std::localtime(&startDate);
			strftime(buffer[1], 20, "%Y-%m-%d", tm_StartDate);
			std::cout << L_RED "Err line " BOLD << i << ": "
				<< RST "Date "<< buffer[0] << " is earlier than the start of the series "
				<< buffer[1] << RENDL;
			return (false);
		}
	}
	return (true);
}

void	printLog (std::time_t dateValue, int i) {
	char buffer[2][20];
	std::tm		*tm = std::localtime(&dateValue);
	strftime(buffer[0], 80, "%Y-%m-%d", tm);

	std::cout << D_BLU "CSV Line " BOLD << i << ": " RST H_GRN << buffer[0] << RENDL;
}
