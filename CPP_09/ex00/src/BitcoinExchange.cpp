/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:31:26 by tforster          #+#    #+#             */
/*   Updated: 2025/02/05 17:37:16 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctime>
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

const char							*BtcXchg::_PATH = "intra/data.csv";
std::map<std::time_t, std::string>	BtcXchg::_BTC_DB;
static const std::string			BTC_HEADER = "date,exchange_rate";
static const std::string			DATA_CSV = "default data.csv";
static const std::string			XCHG_HEADER = "date | value";
static const std::string			INPUT = "input file";

// static void	build_db(const std::string &path, const std::string &header, const std::string &er, std::map<std::time_t, std::string> *db) {
// 	std::cout << D_BLU "Try to open default " << er << RENDL;

// 	std::ifstream	file(path.c_str());

// 	std::cout << BOLD COP << path << RENDL;
// 	if (!file.is_open()) {
// 		std::ostringstream	oss;
// 		oss << L_RED "Error: " RST "Can't open " << er;
// 		throw (std::runtime_error(oss.str()));
// 	}

// 	std::string	line;
// 	line.reserve(100);

// 	getline(file, line);
// 	if (line.compare(header) != 0)
// 		throw (std::runtime_error("Error: invalid data header input file"));

// 	char	div = '|';
// 	if (header == BTC_HEADER)
// 		div = ',';

// 	while (getline(file, line)) {
// 		std::size_t	comma = line.find(div);
// 		if (comma == std::string::npos) {
// 			std::cout << line << "Bad format input\n";
// 			continue;
// 		}
// 		std::time_t	timeValue = 0;
// 		std::tm		timeStruct = {};
// 		char	*ptr = strptime(std::string(line.begin(), line.begin() + comma).c_str(), "%Y-%m-%e ", &timeStruct);
// 		timeValue = mktime(&timeStruct);
// 		if (er == INPUT) {
// 			std::tm	start = {.tm_mday = 1, .tm_mon = 2, .tm_year = 50};
// 			if (ptr == NULL)
// 				std::cout << line << " " << std::asctime(&timeStruct) << " [ " << timeValue << " ]" << " NULL PTR\n";
// 			else if (mktime(&timeStruct) < mktime(&start))
// 				std::cout << line << " " << std::asctime(&timeStruct) << " [ " << timeValue << " ]" << " Before 1950\n";
// 			// else if ()
// 			// 	std::cout << line << "Invalid date\n";
// 			else
// 				std::cout << line << " " << std::asctime(&timeStruct) << " [ " << timeValue << " ]" << " Normal?\n";
// 		}
// 		// char buffer[80];
// 		// strftime(buffer, 80, "%Y-%m-%d", &timeStruct);
// 		db->insert(std::map<std::time_t, std::string>::value_type(
// 			// std::ctime(&timeValue),
// 			// buffer,
// 			timeValue,
// 			std::string(line.begin() + comma + 1, line.end())
// 		));
// 		// db->insert(std::map<std::string, std::string>::value_type(
// 		// 	std::string(line.begin(), line.begin() + comma),
// 		// 	std::string(line.begin() + comma + 1, line.end())
// 		// ));
// 	}
// 	if (file.bad()) {
// 		throw std::runtime_error("Error: read error occurred in 'data.csv'");
// 	}
// }

void	BtcXchg::buildDB(bool defaultDB) {
	std::string		PATH = _input;
	std::string		HEADER = "date | value";
	std::string		DB = _input + " file";
	char			div = '|';
	std::map<std::time_t, std::string>	db = _xchg_db;
	if (defaultDB) {
		PATH = "intra/data.csv";
		HEADER = "date,exchange_rate";
		DB = "default data.csv";
		div = ',';
		db = _BTC_DB;
	}

	std::cout << D_BLU "Try to open " << DB << RENDL;

	std::ifstream	file(PATH.c_str());

	std::cout << BOLD COP << PATH << RENDL;
	if (!file.is_open()) {
		std::ostringstream	oss;
		oss << L_RED "Error: " RST "Can't open " << DB;
		throw (std::runtime_error(oss.str()));
	}

	std::string	line;
	line.reserve(100);

	getline(file, line);
	if (line.compare(HEADER) != 0)
		throw (std::runtime_error("Error: invalid data header input file"));

	while (getline(file, line)) {
		std::size_t	comma = line.find(div);
		if (comma == std::string::npos) {
			std::cout << line << "Bad format input\n";
			continue;
		}
		std::time_t	timeValue = 0;
		std::tm		timeStruct = {};
		char	*ptr = strptime(std::string(line.begin(), line.begin() + comma).c_str(), "%Y-%m-%e ", &timeStruct);
		timeValue = mktime(&timeStruct);
		if (!defaultDB) {
			std::tm	start = {.tm_mday = 1, .tm_mon = 2, .tm_year = 50};
			if (ptr == NULL)
				std::cout << line << " " << std::asctime(&timeStruct) << " [ " << timeValue << " ]" << " NULL PTR\n";
			else if (mktime(&timeStruct) < mktime(&start))
				std::cout << line << " " << std::asctime(&timeStruct) << " [ " << timeValue << " ]" << " Before 1950\n";
			// else if ()
			// 	std::cout << line << "Invalid date\n";
			else
				std::cout << line << " " << std::asctime(&timeStruct) << " [ " << timeValue << " ]" << " Normal?\n";
		}
		db.insert(std::map<std::time_t, std::string>::value_type(
			timeValue,
			std::string(line.begin() + comma + 1, line.end())
		));
	}
	if (file.bad()) {
		throw std::runtime_error("Error: read error occurred in 'data.csv'");
	}
}


void	BtcXchg::build_btc_db(void) {
	// std::cout << D_BLU "Try to open default data.csv file" RENDL;

	// std::ifstream	file(_PATH);

	// if (!file.is_open())
	// 	throw (std::runtime_error("Error: Can't open data.csv"));

	// std::string	line;
	// line.reserve(100);

	// getline(file, line);
	// if (line.compare("date,exchange_rate") != 0)
	// 	throw (std::runtime_error("Error: invalid data header input file"));

	// while (getline(file, line)) {
	// 	std::size_t	comma = line.find(',');
	// 	if (comma == std::string::npos) continue;

	// 	_BTC_DB.insert(std::map<std::string, std::string>::value_type(
	// 		std::string(line.begin(), line.begin() + comma),
	// 		std::string(line.begin() + comma + 1, line.end())
	// 	));
	// }

	// if (file.bad()) {
	// 	throw std::runtime_error("Error: read error occurred in 'data.csv'");
	// }
}

void	BtcXchg::build_exchg_db(void) {
	// std::cout << D_BLU "Try to build exchg db" RENDL;

	// // std::ifstream	file(_input.c_str());
	// std::ifstream	file("input/input.csv");

	// if (!file.is_open())
	// 	throw (std::runtime_error("Error: Can't open input for exchg"));

	// std::string	line;
	// line.reserve(100);

	// getline(file, line);
	// if (line.compare("date | value") != 0)
	// 	throw (std::runtime_error("Error: invalid header input file"));

	// // int	i = 1;
	// while (getline(file, line)) {
	// 	std::size_t	comma = line.find('|');
	// 	if (comma == std::string::npos) continue;
	// 	std::cout << line << " -> nb: " << comma << ENDL;

	// 	_xchg_db.insert(std::map<std::string, std::string>::value_type(
	// 		std::string(line.begin(), line.begin() + comma),
	// 		std::string(line.begin() + comma + 1, line.end())
	// 	));
	// }

	// if (file.bad()) {
	// 	throw std::runtime_error("Error: read error occurred in 'data.csv'");
	// }
}

BtcXchg::BtcXchg(void): _input("No input") {
	if (_BTC_DB.empty()) {
		std::cout << BOLD COP "++++EMPTY++++" RENDL;
		// build_BTC_DB();
		// build_db(_PATH, BTC_HEADER, DATA_CSV, &_BTC_DB);
		buildDB();
	}
}

BtcXchg::BtcXchg(const std::string &input): _input(input) {
	std::cout << BOLD COP "++++PARAMETRIC++++" RENDL;
	if (_BTC_DB.empty()) {
		std::cout << BOLD COP "++++EMPTY++++" RENDL;
		// build_BTC_DB();
		// build_db(_PATH, BTC_HEADER, DATA_CSV, &_BTC_DB);
		buildDB();

	}
	// build_exchg_db();
	// build_db(_input.c_str(), XCHG_HEADER, INPUT, &_xchg_db);
	buildDB(true);
}

BtcXchg::BtcXchg(const BtcXchg &other):
	_input(other._input),
	_xchg_db(other._xchg_db) {}

BtcXchg &BtcXchg::operator=(const BtcXchg &other) {
	if (this != &other) {
		_input = other._input;
		_xchg_db = other._xchg_db;
	}
	return (*this);
};

BtcXchg::~BtcXchg(void) {}

void xchg(const BtcXchg btc_xchg) {


	(void) btc_xchg;
};


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

void BtcXchg::printXchg() const {
	std::cout << BOLD COP "NAME: " << _input << RENDL;
	// for (std::map<std::string, std::string>::const_iterator it = _xchg_db.begin(); it != _xchg_db.end(); ++it) {
	for (std::map<std::time_t, std::string>::const_iterator it = _xchg_db.begin(); it != _xchg_db.end(); ++it) {
		std::tm		*tm = std::localtime(&it->first);
		char buffer[80];
		strftime(buffer, 80, "%Y-%m-%d", tm);

		std::cout << buffer << " -> " << it->second << std::endl;
	}
	// std::map<std::string, std::string>::const_iterator it = _xchg_db.begin();
	// for (int i = 0; i < 5; ++it, ++i) {
	// 	// std::cout << "INDEX: " << i << std::endl;
	// 	std::cout << it->first << " -> " << it->second << std::endl;
	// }

}



// 2010-11-19
