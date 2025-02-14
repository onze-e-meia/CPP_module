/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:31:26 by tforster          #+#    #+#             */
/*   Updated: 2025/02/14 18:09:27 by tforster         ###   ########.fr       */
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
std::map<std::time_t, float>	BtcXchg::_BTC_DB;
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
	std::cout << BOLD CYN "Build default Data Base: " << _PATH
		<< " [" GRN << MSG[_status] << COP "]" << RENDL;
	if (_status == ERROR) {
		std::cout << D_BLU "Status: " L_RED  "ERROR " RST "Inavild path or empty Data Base!" ENDL;
	} else if (_status == EMPTY) {
		buildDB();
	} else
		std::cout << D_BLU "Status: " RST "Data Base ALREADY build!" ENDL;
}

bool	BtcXchg::validateDate(const std::string &line, std::tm &tmS, char delin, int i) {
	std::size_t	comma = line.find(delin);
	if (comma == std::string::npos) {
		std::cout << L_RED "Err line " BOLD << i << ": " RST
			<< "Bad input fomat, no delimeter \"" << line << "\"" RENDL;
		return (false);
	}
	std::string	rawTime = std::string(line.begin(), line.begin() + comma);
	char		*timeLeftOver = strptime(rawTime.c_str(), "%Y-%m-%d", &tmS);

	if (!isValidDate(timeLeftOver, rawTime, tmS, _statrtDate, i))
		return (false);;
	return (true);
}

bool	BtcXchg::validateValue(const std::string &line, float *value, int i) {
	char	*end = NULL;

	*value = std::strtod(line.c_str(), &end);
	if (!str_all_space(end) || line.empty() || *value < 0 ||
		(value == 0 && line.at(0) != '.' && line.at(0) != '0' && line.at(0) != '+'))
			return (errLog(COP "value" RST, line, i));
	return (true);
}

void	BtcXchg::buildDB(void) {
	std::ifstream	*file;

	(file = openFile(_PATH)) == NULL ? errtStatus(_status, "No Data Base build!") : (void)0;
	std::string	line = _status == EMPTY ? checkHeader(_status, file, "date,exchange_rate") : "";

	std::tm		tmS = {};
	std::time_t	dateValue = 0;
	float		value = 0;
	for (std::time_t i = 2; _status == EMPTY && getline(*file, line); ++i) {
		if (!validateDate(line, tmS, ',', i))
			continue ;
		line = std::string(line.begin() + line.find(',') + 1, line.end());
		if (!validateValue(line, &value, i))
			continue ;
		dateValue = mktime(&tmS);
		_BTC_DB.insert(std::map<std::time_t, float>::value_type(dateValue, value));
	}
	if (_status == EMPTY && file->bad())
		errtStatus(_status, "read error occurred in intra/data.csv");
	delete file;
	if (_status == EMPTY && _BTC_DB.empty())
		errtStatus(_status, "No Data Base build!");
	if (_status == ERROR)
		return ;
	_status = BUILD;
	_statrtDate = _BTC_DB.begin()->first;
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
	int				log = EMPTY;
	std::ifstream	*file;

	std::cout << BOLD CYN "Show exchange log for: " << _input << RENDL;
	_status == ERROR ? errtStatus(log, "Inavild path or empty Data Base!") : (void)0;
	(file = openFile(_input)) == NULL ? errtStatus(log, "Can't show exchange log!") : (void)0;
	std::string	line = log == EMPTY ? checkHeader(log, file, "date | value") : "";

	std::tm		tmS = {};
	std::time_t	dateValue = 0;
	float		value = 0;
	for (std::time_t i = 2; log == EMPTY && getline(*file, line); ++i) {
		if (!validateDate(line, tmS, '|', i))
			continue ;
		line = std::string(line.begin() + line.find('|') + 1, line.end());
		if (!validateValue(line , &value, i))
			continue ;
		if (value > 1000) {
			errLog(COP "value (BTC: too large)" RST, line, i);
			continue ;
		}

		dateValue = mktime(&tmS);
		std::map<std::time_t, float>::iterator	lowerDate = _BTC_DB.lower_bound(dateValue);
		lowerDate = lowerDate->first == dateValue ? lowerDate : --lowerDate;

		printLog(dateValue, value, lowerDate->second, i);
	}
	if (log == EMPTY && file->bad())
		errtStatus(_status, "read error occurred in input file");
	delete file;
}
