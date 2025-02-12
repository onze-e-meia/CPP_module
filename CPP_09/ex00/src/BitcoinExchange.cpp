/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:31:26 by tforster          #+#    #+#             */
/*   Updated: 2025/02/11 23:17:30 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "include/BitcoinExchange.hpp"
#include "lib/color.hpp"

#include <locale.h>

enum STATUS {
	EMPTY = 0,
	BUILD = 1,
	ERROR = 2
};

const char							*BtcXchg::_PATH = "intra/data.csv";
std::map<std::time_t, std::string>	BtcXchg::_BTC_DB;
int									BtcXchg::_status = EMPTY;
std::time_t							BtcXchg::_statrtDate = 0;

static std::ifstream *openFile(std::string path) {
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
		std::cerr << e.what() << ENDL
			D_BLU "Status: " RST "No Data Base build!" ENDL;
		return (NULL);
	}
	return (file);
}

bool	str_all_space(const std::string &str) {
	const std::size_t	len = str.length();

	if (len == 0)
		return (true);
	for (std::size_t i = 0; i < len; ++i) {
		if (std::isspace(static_cast<unsigned char>(str[i])))
			continue ;
		// else
		return (false);
	}
	return (true);
}

static bool	isValidDay(int year, int month, int day) {
	year += 1900;
	int	leapYear = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	int	daysMoth[] = {31, 28 + leapYear, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return (day >= 1 && day <= daysMoth[month]);
}

static bool isValidDate(const char *ptr, const std::string &rawDate,
	const std::string &line, const std::tm &tmS, int i) {
	if (!ptr) {
		std::cout << L_RED "Err Line " BOLD << i << ": " RST
			<< "Invalid date \"" <<  rawDate << "\"" RENDL;
		return (0);
	} else  {
		std::string	str(ptr);
		if (!str_all_space(str)) {
			std::cout << L_RED "Err line " BOLD << i << ": "
				<< RST "Bad input fomat \"" << line << "\"" RENDL;
			return (0);
		}
		if (!isValidDay(tmS.tm_year, tmS.tm_mon, tmS.tm_mday) || !str_all_space(str))
			return (0);
	}
	return (1);
}

static bool printLog (std::time_t dateValue, std::time_t startDate, int i, bool print = false) {
	char buffer[2][20];
	std::tm		*tm = std::localtime(&dateValue);
	strftime(buffer[0], 80, "%Y-%m-%d", tm);

	if (dateValue < startDate) {
		std::tm	*tm_StartDate = std::localtime(&startDate);
		strftime(buffer[1], 20, "%Y-%m-%d", tm_StartDate);
		std::cout << L_RED "Err line " BOLD << i << ": "
			<< RST "Date "<< buffer[0] << " is earlier than the start of the series "
			<< buffer[1] << RENDL;
		return (false);
	}
	if (print)
		std::cout << D_BLU "CSV Line " BOLD << i << ": " RST H_GRN << buffer[0] << RENDL;
	return (true);
}

void	BtcXchg::buildDB(void) {
	std::string		DB = "default data.csv";
	std::map<std::time_t, std::string>	*db = &_BTC_DB;
	std::ifstream	*file;

	std::cout << BOLD TEAL "Build default Data Base: " << _PATH << RENDL;
	file =  openFile(_PATH);
	if (!file) {
		_status = ERROR;
		return ;
	}

	std::string	line;
	line.reserve(100);
	getline(*file, line);
	if (line.compare("date,exchange_rate") != 0)
		throw (std::runtime_error("Error: invalid data header input file"));
	std::tm		tmS = {};
	std::time_t	dateValue;
	for (std::time_t i = 2; getline(*file, line); ++i) {
		std::size_t	comma = line.find(',');
		if (comma == std::string::npos) {
			std::cout << L_RED "Err line " BOLD << i << ": " RST
				<< "Bad input fomat \"" << line << "\"" RENDL;
			continue;
		}

		std::string	rawDate = std::string(line.begin(), line.begin() + comma);
		char		*ptr = strptime(rawDate.c_str(), "%Y-%m-%d", &tmS);

		if (!isValidDate(ptr, rawDate, line, tmS, i))
			continue;
		dateValue = mktime(&tmS);
		if (!printLog(dateValue, _statrtDate, i))
				continue;
		db->insert(std::map<std::time_t, std::string>::value_type(
			dateValue,
			std::string(line.begin() + comma + 1, line.end())
		));
	}
	if (file->bad()) {
		throw std::runtime_error("Error: read error occurred in 'data.csv'");
	}
	delete file;
	_status = BUILD;
	std::cout << D_BLU "Status: " RST "Data Base build!" ENDL;
}

BtcXchg::BtcXchg(void): _input("No input") {
	if (_status == ERROR) {
		std::cout << BOLD COP "++++INVALID DB++++" RENDL;
		return;
	}
	else if (_status == EMPTY) {
	// if (_BTC_DB.empty()) {
		std::cout << BOLD COP "++++EMPTY++++" RENDL;
		buildDB();
	}
	else
		std::cout << D_BLU "Status: " RST "Data Base ALREADY build!" ENDL;

}

BtcXchg::BtcXchg(const std::string &input): _input(input) {
	std::cout << BOLD COP "++++PARAMETRIC++++" RENDL;
	if (_status == ERROR)
		std::cout << BOLD COP "++++INVALID DB++++" RENDL;

	if (_status == EMPTY) {
	// if (_BTC_DB.empty()) {
		std::cout << BOLD COP "++++EMPTY++++" RENDL;
		buildDB();
	}
}

BtcXchg::BtcXchg(const BtcXchg &other):
	_input(other._input) {}

BtcXchg &BtcXchg::operator=(const BtcXchg &other) {
	if (this != &other)
		_input = other._input;
	return (*this);
};

BtcXchg::~BtcXchg(void) {}

void BtcXchg::xchgLog(void) {
	std::ifstream	*file;

	if (_status == ERROR) {
		std::cout << BOLD COP "++++INVALID DB++++" RENDL;
		return;
	}

	file =  openFile(_input);
	if (!file)
		return ;

	std::string	line;
	line.reserve(100);
	getline(*file, line);
	if (line.compare("date | value") != 0)
		throw (std::runtime_error("Error: invalid data header input file"));
	std::tm		tmS = {};
	std::time_t	dateValue;
	for (std::time_t i = 2; getline(*file, line); ++i) {
		std::size_t	comma = line.find('|');
		if (comma == std::string::npos) {
			std::cout << L_RED "Err line " BOLD << i << ": " RST "Bad input fomat \"" << line << "\"" RENDL;
			continue;
		}

		std::string	rawDate = std::string(line.begin(), line.begin() + comma);
		char		*ptr = strptime(rawDate.c_str(), "%Y-%m-%d", &tmS);

		if (!isValidDate(ptr, rawDate, line, tmS, i))
			continue;
		dateValue = mktime(&tmS);
		printLog(dateValue, _statrtDate, i, true);
	}
	if (file->bad()) {
		throw std::runtime_error("Error: read error occurred in 'data.csv'");
	}
	delete file;
}


void BtcXchg::printData() const {
	// for (std::map<std::string, std::string>::const_iterator it = _BTC_DB.begin(); it != _BTC_DB.end(); ++it) {
	// 	std::cout << it->first << " -> " << it->second << std::endl;
	// }
	std::cout << BOLD COP "NAME: " << _PATH << RENDL;
	// std::map<std::string, std::string>::const_iterator it = _BTC_DB.begin();
	std::map<std::time_t, std::string>::const_iterator it = _BTC_DB.begin();
	for (int i = 0; i < 5; ++it, ++i) {
		std::tm		*tm = std::localtime(&it->first);
		char buffer[80];
		strftime(buffer, 80, "%Y-%m-%d", tm);

		// std::cout << it->first << " -> " << it->second << std::endl;
		std::cout << buffer << " -> " << it->second << std::endl;
	}

}



// 2010-11-19
