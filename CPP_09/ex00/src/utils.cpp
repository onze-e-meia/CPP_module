/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:10:11 by tforster          #+#    #+#             */
/*   Updated: 2025/02/14 18:25:59 by tforster         ###   ########.fr       */
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

bool	str_all_space(const char *str) {
	std::string			string(str);
	const std::size_t	len = string.length();

	for (std::size_t i = 0; i < len; ++i) {
		if (std::isspace(static_cast<unsigned char>(string[i])))
			continue ;
		return (false);
	}
	return (true);
}

bool	errLog(const char *type, const std::string &string, int i) {
	std::cout << L_RED "Err Line " BOLD << i << ": " RST
			<< "Invalid " << type << " [" << string << "]" RENDL;
	return (false);
}

std::ifstream	*openFile(const std::string &path) {
	std::ifstream	*file = new std::ifstream(path.c_str());

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

bool	isStartDate(std::tm &tmS, std::time_t startDate, int i) {
	char buffer[2][20];

	strftime(buffer[0], 80, "%Y-%m-%d", &tmS);
	if ( mktime(&tmS) < startDate) {
		strftime(buffer[1], 20, "%Y-%m-%d", std::localtime(&startDate));
		std::cout << L_RED "Err line " BOLD << i << ": "
			<< RST "Date " << buffer[0] << ORG " is earlier " RST "than the start of the series "
			<< buffer[1] << RENDL;
		return (false);
	}
	return (true);
}

bool	isValidDate(const char *timeLeftOver, const std::string &RawTime,
	std::tm &tmS, std::time_t startDate, int i) {
	if (!timeLeftOver || !str_all_space(timeLeftOver))
		return (errLog(ORG "date" RST, RawTime , i));
	else if (!isValidDay(tmS.tm_year, tmS.tm_mon, tmS.tm_mday) )
		return (errLog(ORG "date" RST, RawTime , i));
	else if (!isStartDate(tmS, startDate, i))
		return (false);
	return (true);
}

void	printLog (std::time_t dateValue, float value, float xchg, int i) {
	char buffer[20];
	strftime(buffer, 80, "%Y-%m-%d", std::localtime(&dateValue));

	std::cout << D_BLU "CSV Line " BOLD << i << ": " RST H_GRN << buffer << RST
		<< " => " << value << " = " << value * xchg << ENDL;
}
