/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:31:26 by tforster          #+#    #+#             */
/*   Updated: 2025/02/13 19:35:21 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "include/BitcoinExchange.hpp"
#include "include/utils.hpp"
#include "lib/color.hpp"

enum STATUS {EMPTY = 0, BUILD = 1, ERROR = 2};
const char *MSG[3] = {"EMPTY", "BUILD", "ERROR"};

const char						*BtcXchg::_PATH = "intra/data.csv";
std::map<std::time_t, double>	BtcXchg::_BTC_DB;
int								BtcXchg::_status = EMPTY;
std::time_t						BtcXchg::_statrtDate = 0;

static void	errtStatus(int &status, const char *str) {
	status = ERROR;
	std::cout << D_BLU "Status: " L_RED  "ERROR " RST << str << ENDL;
}

std::string	checkHeader(int &status, std::ifstream *file, const char *header) {
	std::string	line;
	line.reserve(100);
	getline(*file, line);
	if (status == EMPTY && line.compare(header) != 0)
		errtStatus(status, "Invalid Data header file");
	return (line);
}

void BtcXchg::checkStatus(void) {
	std::cout << BOLD COP "Build default Data Base: " << _PATH
		<< " [" GRN << MSG[_status] << COP "]" << RENDL;
	if (_status == ERROR) {
		std::cout << D_BLU "Status: " L_RED  "ERROR " RST "Inavild path or empty Data Base!" ENDL;
	} else if (_status == EMPTY) {
		buildDB();
	} else
		std::cout << D_BLU "Status: " RST "Data Base ALREADY build!" ENDL;
}

// bool	isValidValue() {
// 	return (true);
// }

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

	(file = openFile(_PATH)) == NULL ? errtStatus(_status, "No Data Base build!") : (void)0;
	std::string	line = _status == EMPTY ? checkHeader(_status, file, "date,exchange_rate") : "";

	std::tm		tmS = {};
	std::time_t	dateValue;
	for (std::time_t i = 2; _status == EMPTY && getline(*file, line); ++i) {
		if (!validate(line, tmS, ',', i))
			continue ;
		dateValue = mktime(&tmS);
		std::string btc = std::string(line.begin() + line.find(',') + 1, line.end());
		// std::cout << btc << "    " << std::strtod(btc.c_str(), NULL);
		_BTC_DB.insert(std::map<std::time_t, double>::value_type(
			dateValue,
			std::strtod(btc.c_str(), NULL)
		));
	}
	if (_status == EMPTY && file->bad())
		errtStatus(_status, "read error occurred in intra/data.csv");
	delete file;
	if (_status == EMPTY && _BTC_DB.empty())
		errtStatus(_status, "No Data Base build!");
	if (_status == ERROR)
		return ;
	_status = BUILD;
	std::cout << D_BLU "Status: " RST "Data Base build!" ENDL;
	// for (std::map<std::time_t, double>::iterator it = _BTC_DB.begin(); it != _BTC_DB.end(); ++it) {
	// 	std::cout << "At: " << it->first << ", Key: " << ctime(&it->first) << ", Value: " << it->second << std::endl;
	// }

	// std::cout << _BTC_DB.at(1648155600) << ENDL;
	// std::cout << _BTC_DB.begin()->first << ENDL;
	// std::cout << _BTC_DB.end()->first << ENDL;

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
	int				log = EMPTY;
	std::ifstream	*file;

	std::cout << BOLD COP "Show exchange log for: " << _input << RENDL;
	_status == ERROR ? errtStatus(log, "Inavild path or empty Data Base!") : (void)0;
	(file = openFile(_input)) == NULL ? errtStatus(log, "Can't show exchange log!") : (void)0;
	std::string	line = log == EMPTY ? checkHeader(log, file, "date | value") : "";

	std::tm		tmS = {};
	std::time_t	dateValue;
	for (std::time_t i = 2; log == EMPTY && getline(*file, line); ++i) {
		if (!validate(line, tmS, '|', i))
			continue ;
		dateValue = mktime(&tmS);
		printLog(dateValue, i);
	}
	if (log == EMPTY && file->bad())
		errtStatus(_status, "read error occurred in input file");
	delete file;
}
