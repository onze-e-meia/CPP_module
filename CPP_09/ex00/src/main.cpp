/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:16:48 by tforster          #+#    #+#             */
/*   Updated: 2025/02/03 20:40:47 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "include/BitcoinExchange.hpp"
#include "lib/color.hpp"

#define PRINT_TEST(test)	std::cout << ENDL COP << test << RENDL

int	main(void) {
	std::system("clear");

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
