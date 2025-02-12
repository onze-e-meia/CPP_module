/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:31:26 by tforster          #+#    #+#             */
/*   Updated: 2025/02/12 18:53:34 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>
#include "include/BitcoinExchange.hpp"
#include "include/utils.hpp"
#include "lib/color.hpp"

enum STATUS {EMPTY = 0, BUILD = 1, ERROR = 2};

const char							*BtcXchg::_PATH = "intra/data.csv";
std::map<std::time_t, std::string>	BtcXchg::_BTC_DB;
int									BtcXchg::_status = EMPTY;
std::time_t							BtcXchg::_statrtDate = 0;

void BtcXchg::checkStatus(void) {
	std::cout << BOLD COP "Build default Data Base: " << _PATH << RENDL;
	if (_status == ERROR) {
		std::cout << D_BLU "Status: " L_RED  "ERROR " RST "Inavild path or empty Data Base!" ENDL;
	} else if (_status == EMPTY) {
		buildDB();
	} else
		std::cout << D_BLU "Status: " RST "Data Base ALREADY build!" ENDL;
}

void	BtcXchg::setStatus(int status, const std::string &str) {
	_status = status;
	std::cout << D_BLU "Status: " L_RED  "ERROR " RST << str << ENDL;
}


bool	BtcXchg::validate(const std::string &line, std::tm &tmS, char delin, int i) {
	std::size_t	comma = line.find(delin);
	if (comma == std::string::npos) {
		std::cout << L_RED "Err line " BOLD << i << ": " RST
			<< "Bad input fomat \"" << line << "\"" RENDL;
		return (false);
	}
	std::string	rawDate = std::string(line.begin(), line.begin() + comma);
	char		*ptr = strptime(rawDate.c_str(), "%Y-%m-%d", &tmS);

	if (!isValidDate(ptr, rawDate, line, tmS, _statrtDate, i))
		return (false);;
	return (true);
}

void	BtcXchg::buildDB(void) {
	std::ifstream	*file;

	file =  openFile(_PATH);
	if (!file)
		return (setStatus(ERROR, "No Data Base build!"));

	std::string	line;
	line.reserve(100);
	getline(*file, line);
	// Fix to setStatus()
	if (line.compare("date,exchange_rate") != 0)
		throw (std::runtime_error("Error: invalid data header input file"));
	std::tm		tmS = {};
	std::time_t	dateValue;
	for (std::time_t i = 2; getline(*file, line); ++i) {
		if (!validate(line, tmS, ',', i))
			continue ;
		dateValue = mktime(&tmS);
		_BTC_DB.insert(std::map<std::time_t, std::string>::value_type(
			dateValue, std::string(line.begin() + line.find(',') + 1, line.end())
		));
	}
	// Fix to setStatus()
	if (file->bad()) {
		throw std::runtime_error("Error: read error occurred in 'data.csv'");
	}
	delete file;
	if (_BTC_DB.empty()) {
		// Fix to setStatus()
		_status = ERROR;
		std::cout << D_BLU "Status: " L_RED  "ERROR " RST "No Data Base build!" ENDL;
		return ;
	}
	_status = BUILD;
	std::cout << D_BLU "Status: " RST "Data Base build!" ENDL;
}

BtcXchg::BtcXchg(void): _input("No input") {checkStatus();}

BtcXchg::BtcXchg(const std::string &input): _input(input) {checkStatus();}

BtcXchg::BtcXchg(const BtcXchg &other): _input(other._input) {}

BtcXchg &BtcXchg::operator=(const BtcXchg &other) {
	if (this != &other)
		_input = other._input;
	return (*this);
};

BtcXchg::~BtcXchg(void) {}

void BtcXchg::xchgLog(void) {
	std::ifstream	*file;

	std::cout << BOLD COP "Show exchange log for: " << _input << RENDL;
	// Fix to setStatus()
	if (_status == ERROR) {
		std::cout << D_BLU "Status: " L_RED  "ERROR " RST "Inavild path or empty Data Base!" ENDL;
		return;
	}
	file =  openFile(_input);
	if (!file)
		return ;

	std::string	line;
	line.reserve(100);
	getline(*file, line);
	// Fix to setStatus()
	if (line.compare("date | value") != 0)
		throw (std::runtime_error("Error: invalid data header input file"));
	std::tm		tmS = {};
	std::time_t	dateValue;
	for (std::time_t i = 2; getline(*file, line); ++i) {
		if (!validate(line, tmS, '|', i))
			continue ;
		dateValue = mktime(&tmS);
		printLog(dateValue, i);
	}
	// Fix to setStatus()
	if (file->bad()) {
		throw std::runtime_error("Error: read error occurred in 'data.csv'");
	}
	delete file;
}
