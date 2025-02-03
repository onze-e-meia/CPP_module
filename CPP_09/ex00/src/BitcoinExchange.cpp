/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:31:26 by tforster          #+#    #+#             */
/*   Updated: 2025/02/03 20:53:32 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <ostream>
#include <stdexcept>
#include <string>
#include "include/BitcoinExchange.hpp"
#include "lib/color.hpp"

const char							*BtcXchg::_PATH = "intra/data.csv";
std::map<std::string, std::string>	BtcXchg::_btc_db;
static const std::string			BTC_HEADER = "date,exchange_rate";
static const std::string			DATA_CSV = "default data.csv";
static const std::string			XCHG_HEADER = "date | value";
static const std::string			INPUT = "input file";

static void	build_db(const std::string &path, const std::string &header, std::map<std::string, std::string> *db) {
	std::cout << D_BLU "Try to open default data.csv file" RENDL;

	std::ifstream	file(path.c_str());

	std::cout << BOLD COP << path << RENDL;
	if (!file.is_open())
		throw (std::runtime_error("Error: Can't open data.csv"));

	std::string	line;
	line.reserve(100);

	getline(file, line);
	// if (line.compare("date,exchange_rate") != 0)
	if (line.compare(header) != 0)
		throw (std::runtime_error("Error: invalid data header input file"));

	char	div = '|';
	if (header == BTC_HEADER)
		div = ',';

	while (getline(file, line)) {
		std::size_t	comma = line.find(div);
		if (comma == std::string::npos) continue;
		// std::cout << comma << ": " << line << ENDL;

		db->insert(std::map<std::string, std::string>::value_type(
			std::string(line.begin(), line.begin() + comma),
			std::string(line.begin() + comma + 1, line.end())
		));
	}

	if (file.bad()) {
		throw std::runtime_error("Error: read error occurred in 'data.csv'");
	}
}

void	BtcXchg::build_btc_db(void) {
	std::cout << D_BLU "Try to open default data.csv file" RENDL;

	std::ifstream	file(_PATH);

	if (!file.is_open())
		throw (std::runtime_error("Error: Can't open data.csv"));

	std::string	line;
	line.reserve(100);

	getline(file, line);
	if (line.compare("date,exchange_rate") != 0)
		throw (std::runtime_error("Error: invalid data header input file"));

	while (getline(file, line)) {
		std::size_t	comma = line.find(',');
		if (comma == std::string::npos) continue;

		_btc_db.insert(std::map<std::string, std::string>::value_type(
			std::string(line.begin(), line.begin() + comma),
			std::string(line.begin() + comma + 1, line.end())
		));
	}

	if (file.bad()) {
		throw std::runtime_error("Error: read error occurred in 'data.csv'");
	}
}

void	BtcXchg::build_exchg_db(void) {
	std::cout << D_BLU "Try to build exchg db" RENDL;

	// std::ifstream	file(_input.c_str());
	std::ifstream	file("input/input.csv");

	if (!file.is_open())
		throw (std::runtime_error("Error: Can't open input for exchg"));

	std::string	line;
	line.reserve(100);

	getline(file, line);
	if (line.compare("date | value") != 0)
		throw (std::runtime_error("Error: invalid header input file"));

	// int	i = 1;
	while (getline(file, line)) {
		std::size_t	comma = line.find('|');
		if (comma == std::string::npos) continue;
		std::cout << line << " -> nb: " << comma << ENDL;

		_xchg_db.insert(std::map<std::string, std::string>::value_type(
			std::string(line.begin(), line.begin() + comma),
			std::string(line.begin() + comma + 1, line.end())
		));
	}

	if (file.bad()) {
		throw std::runtime_error("Error: read error occurred in 'data.csv'");
	}
}

BtcXchg::BtcXchg(void): _input("No input") {
	if (_btc_db.empty()) {
		std::cout << BOLD COP "++++EMPTY++++" RENDL;
		// build_btc_db();
		build_db(_PATH, BTC_HEADER, &_btc_db);
	}
}

BtcXchg::BtcXchg(const std::string &input): _input(input) {
	std::cout << BOLD COP "++++PARAMETRIC++++" RENDL;
	if (_btc_db.empty()) {
		std::cout << BOLD COP "++++EMPTY++++" RENDL;
		build_db(_PATH, BTC_HEADER, &_btc_db);

		// build_btc_db();
	}
	build_db(_input.c_str(), XCHG_HEADER, &_xchg_db);
	// build_exchg_db();
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
	// for (std::map<std::string, std::string>::const_iterator it = _btc_db.begin(); it != _btc_db.end(); ++it) {
	// 	std::cout << it->first << " -> " << it->second << std::endl;
	// }
	std::cout << BOLD COP "NAME: " << _PATH << RENDL;
	std::map<std::string, std::string>::const_iterator it = _btc_db.begin();
	for (int i = 0; i < 5; ++it, ++i) {
		std::cout << it->first << " -> " << it->second << std::endl;
	}

}

void BtcXchg::printXchg() const {
	std::cout << BOLD COP "NAME: " << _input << RENDL;
	// for (std::map<std::string, std::string>::const_iterator it = _xchg_db.begin(); it != _xchg_db.end(); ++it) {
	// 	std::cout << it->first << " -> " << it->second << std::endl;
	// }
	std::map<std::string, std::string>::const_iterator it = _xchg_db.begin();
	for (int i = 0; i < 5; ++it, ++i) {
		std::cout << "INDEX: " << i << std::endl;
		std::cout << it->first << " -> " << it->second << std::endl;
	}

}
