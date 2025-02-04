/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:16:48 by tforster          #+#    #+#             */
/*   Updated: 2025/02/04 18:11:30 by tforster         ###   ########.fr       */
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

// #include <cstring>

#define PRINT_TEST(test)	std::cout << ENDL COP << test << RENDL

int	main(void) {
	std::system("clear");

	std::time_t	calendar_time = std::time(0);
	char		*dt = std::ctime(&calendar_time);
	std::tm		*tm = std::localtime(&calendar_time);
	tm->tm_wday = 0;
	char		*r_tm = std::asctime(tm);
	// std::tm		*TM = std::gmtime(&calendar_time);
	// std::time_t	gmt = std::mktime(TM);
	// char		*char_gmt = std::ctime(&gmt);


	std::cout << "calendar_time: " << calendar_time << ENDL;
	std::cout << "readable: " << dt << ENDL;
	std::cout << "tm readable: " << r_tm << ENDL;
	std::cout << "hour: " << tm->tm_wday << ENDL;
	std::cout << "hour: " << tm->tm_mon << ENDL;
	std::cout << "hour: " << tm->tm_mday << ENDL;
	std::cout << "hour: " << tm->tm_hour << ENDL;
	std::cout << "hour: " << tm->tm_min << ENDL;
	std::cout << "hour: " << tm->tm_sec << ENDL;
	std::cout << "hour: " << tm->tm_yday << ENDL;
	std::cout << "hour: " << tm->tm_year << ENDL;

	std::cout << "hour: " << tm->tm_gmtoff << ENDL;
	std::cout << "hour: " << tm->tm_isdst << ENDL;
	std::cout << "hour: " << tm->tm_zone << ENDL;

	time_t now = time(0);               // Get current time
	std::tm* localTime = localtime(&now);	// Convert to local time

	char buffer[80];
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localTime);

	std::tm	timeStruct = {};
	strptime("dateTimeStr", "%Y-%m-%d %H:%M:%S", &timeStruct);

	std::cout << "Current time: " << buffer << std::endl;

	// std::cout << "GMT: " << char_gmt << ENDL;



	// BtcXchg	db;
	// std::cout << BOLD COP "++++FIRST++++" RENDL;
	// db.printData();

	// BtcXchg	dd;
	// std::cout << BOLD COP "++++SECOND++++" RENDL;
	// dd.printData();



	char	test[] = "input/input.csv";
	// BtcXchg	db_0("TEST 0");
	BtcXchg	db_0(test);
	std::cout << BOLD COP "++++THIRD++++" RENDL;
	db_0.printData();
	db_0.printXchg();

	// BtcXchg	db_1(db_0);
	// std::cout << BOLD COP "++++FORTH++++" RENDL;
	// db_0.printData();

	// BtcXchg	db_2("QUINTO");
	// std::cout << BOLD COP "++++FIFITY++++" RENDL;
	// db_2.printData();

	// std::cout << BOLD COP "++++SIXTH++++" RENDL;
	// db_2 = db_0;
	// db_2.printData();



}
