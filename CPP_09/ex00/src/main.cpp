/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:16:48 by tforster          #+#    #+#             */
/*   Updated: 2025/02/13 20:21:38 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <deque>
#include <list>
#include "include/BitcoinExchange.hpp"
#include "lib/color.hpp"


const std::string::size_type NPOS = std::string::npos;
#include <string>
#include <cstring>
#include <cstdlib>
#include "include/utils.hpp"


#define PRINT_TEST(test)	std::cout << ENDL COP << test << RENDL

bool	valid_decimal(char *end, std::string str) {
	if (str_all_space(end) || (std::strlen(end) == 1 && end[0] == 'f' &&
		(str.find(".") != NPOS || str.find("e") != NPOS || str == "inff" || str == "nanf")))
		return (false);
	return (true);
}

bool	check(double value, char *end, std::string str) {
	if (valid_decimal(end, str) || str.empty() ||
		(value == 0 && str.at(0) != '.' && str.at(0) != '0' && str.at(0) != '-' && str.at(0) != '+'))
		return (false);
	return (true);
}

void	printNB(const char *nb) {
	char	*end = NULL;
	double	value = std::strtod(nb, &end);

	if (check(value, end, nb)) {
		std::cout << "Number : [" << value << "]" << ENDL;
		if (end)
			std::cout << "EnD: [" << end << "]" ENDL;

	}
	else
	 	std::cout << "INVALID ND" ENDL;

}

int	main(void) {
	std::system("clear");

	setenv("TZ", "UTC-3", 1);
	tzset();
validate_date

	// std::time_t	calendar_time = std::time(0);
	// char		*dt = std::ctime(&calendar_time);
	// std::tm		*tm = std::localtime(&calendar_time);
	// tm->tm_wday = 0;
	// char		*r_tm = std::asctime(tm);
	// // std::tm		*TM = std::gmtime(&calendar_time);
	// // std::time_t	gmt = std::mktime(TM);
	// // char		*char_gmt = std::ctime(&gmt);

	// std::cout << "calendar_time: " << calendar_time << ENDL;
	// std::cout << "readable: " << dt << ENDL;
	// std::cout << "tm readable: " << r_tm << ENDL;
	// std::cout << "hour: " << tm->tm_wday << ENDL;
	// std::cout << "hour: " << tm->tm_mon << ENDL;
	// std::cout << "hour: " << tm->tm_mday << ENDL;
	// std::cout << "hour: " << tm->tm_hour << ENDL;
	// std::cout << "hour: " << tm->tm_min << ENDL;
	// std::cout << "hour: " << tm->tm_sec << ENDL;
	// std::cout << "year day: " << tm->tm_yday << ENDL;
	// std::cout << "year: " << tm->tm_year << ENDL;

	// std::cout << "hour: " << tm->tm_gmtoff << ENDL;
	// std::cout << "hour: " << tm->tm_isdst << ENDL;
	// std::cout << "hour: " << tm->tm_zone << ENDL;

	// time_t now = time(0);               // Get current time
	// std::tm* localTime = localtime(&now);	// Convert to local time

	// char buffer[80];
	// strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localTime);

	// std::tm	timeStruct = {};
	// strptime("dateTimeStr", "%Y-%m-%d %H:%M:%S", &timeStruct);

	// std::cout << "Current time: " << buffer << std::endl;




	// BtcXchg	db;
	// std::cout << BOLD COP "++++FIRST++++" RENDL;
	// db.printData();

	// BtcXchg	dd;
	// std::cout << BOLD COP "++++SECOND++++" RENDL;
	// dd.printData();



	// char	test[] = "input/input.csv";
	char	test[] = "input/input.txt";
	// BtcXchg	db_0("TEST 0");
	BtcXchg	db_0(test);
	// db_0.printData();
	// db_0.xchgLog();

	char *mm;

	mm = (char*)malloc(10);

	mm[0] = '1';
	mm[1] = '.';
	mm[2] = 'f';

	// char *crash = NULL;

	BtcXchg	db_1;
	// printNB(mm);
	// printNB(crash);
	printNB(".0f");
	// printNB("");
	printNB("11111f");
	printNB(".0   ");
	printNB("inf");
	printNB("inff");

	// char	str[] = ".0";
	// char	*end = NULL;
	// double	value = std::strtod("0.", &end);

	// if (check(value, end, str))
	// 	std::cout << "Number :" << value << ENDL;
	// else
	//  	std::cout << "INVALIS" ENDL;

	// BtcXchg	db_1(db_0);
	// std::cout << BOLD COP "++++FORTH++++" RENDL;
	// db_0.printData();

	// BtcXchg	db_2("QUINTO");
	// std::cout << BOLD COP "++++FIFITY++++" RENDL;
	// db_2.printData();

	// std::cout << BOLD COP "++++SIXTH++++" RENDL;
	// db_2 = db_0;
	// db_2.printData();


	return (EXIT_SUCCESS);
}
