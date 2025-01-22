/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:16:48 by tforster          #+#    #+#             */
/*   Updated: 2025/01/22 20:09:33 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <stdexcept>
#include "include/Span.hpp"
#include "lib/color.hpp"

#define PRINT_TEST(test)	std::cout << ENDL COP << test << RENDL

int	main(void) {
	std::system("clear");
	std::srand(static_cast<unsigned int>(std::time(0)));

	PRINT_TEST("Try to make negative Span:");
	try {
		Span	neg(-1);
	} catch (std::exception &e) {
		std::cerr << e.what() << ENDL;
	}

	PRINT_TEST("Make Span of size 0:");
	Span	span_0;
	std::cout << D_BLU "SIZE: " RST << span_0.size() << ENDL;
	std::cout << D_BLU "MAX_SIZE: " RST << span_0.max_size() << ENDL;
	std::cout << "Try to check position 0:" ENDL;
	try {
		std::cout << D_BLU "Number at [0]: " RST << span_0[0] << ENDL;
	} catch (std::exception &e) {
		std::cerr << e.what() << ENDL;
	}
	std::cout << "Try to add a number:" ENDL;
	try {
		span_0.addNumber(1);
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}
	std::cout << D_BLU "Span: " RST << span_0 << ENDL;


	PRINT_TEST("Make Span of size 1:");
	Span	span_1(1);
	std::cout << D_BLU "SIZE: " RST << span_1.size() << ENDL;
	std::cout << D_BLU "MAX_SIZE: " RST << span_1.max_size() << ENDL;
	std::cout << "Try to add a two numbers (99 and 1):" ENDL;
	span_1.addNumber(99);
	try {
		span_1.addNumber(1);
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}
	std::cout << D_BLU "Span: " RST << span_1 << ENDL;
	std::cout << D_BLU "SIZE: " RST << span_1.size() << ENDL;
	std::cout << "Try to get shortest span:" ENDL;
	try {
		span_1.shortestSpan();
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}
		std::cout << "Try to get longest span:" ENDL;
	try {
		span_1.longestSpan();
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}

	PRINT_TEST("Make Span of size 5:");
	Span	span_5(10);
	std::cout << D_BLU "SIZE: " RST << span_5.size() << ENDL;
	std::cout << D_BLU "MAX_SIZE: " RST << span_5.max_size() << ENDL;
	std::cout << "Fill Span with random numbers:" ENDL;
	span_5.randomFill();
	std::cout << D_BLU "Span: " RST << span_5 << ENDL;
	std::cout << D_BLU "SIZE: " RST << span_5.size() << ENDL;
	std::cout << "Get shortest span:" ENDL;

	std::cout << "Get longest span:" ENDL;
	std::cout << D_BLU "Longest: " RST << span_5.longestSpan() << ENDL;







	// std::cout << "AT 0: " << span_1[0] << ENDL;
	// std::cout << "AT 1: " << span_1[1] << ENDL;
	// std::cout << "SIZE: " << span_1.size() << ENDL;
	// std::cout << "SIZE: " << span_1.max_size() << ENDL;

	// for (int i = 0 ; i < 20; i++) {
	// 	std::cout << std::rand() << ", ";
	// }
	// std::cout << ENDL "MAX_RAND:" << RAND_MAX << DENDL;
	// std::cout << ENDL "INT_MAX:" << INT_MAX << DENDL;

	// Span	s10(10);
	// s10.randomFill();
	// std::cout << s10 << ENDL;
	// // s10.randomFill();

	// const Span s_const = s10;
	// std::cout << s_const << ENDL;







	// std::cout << "AT 3: " << span_1._vector.at(3) << ENDL;


	// Span	s1(10);
	// s1._vector[1] = 10;
	// s1._vector[2] = 20;
	// s1._vector[9] = 90;
	// s1._vector[10] = 100;
	// s1._vector[11] = 110;
	// Span	s2(s1);
	// s2._vector[3] = 30;
	// s2._vector[4] = 40;
	// s1._vector[0] = 99;
	// std::cout << "SIZE: " << s1._vector.size() << ENDL;
	// std::cout << "AT 0: " << s1._vector.at(0) << ENDL;
	// std::cout << "AT 1: " << s1._vector.at(1) << ENDL;
	// std::cout << "AT 2: " << s1._vector.at(2) << ENDL;
	// std::cout << "AT 3: " << s1._vector.at(3) << ENDL;
	// std::cout << "AT 4: " << s1._vector.at(4) << ENDL;
	// std::cout << "AT 9: " << s1._vector.at(9) << ENDL;
	// std::cout << "SIZE: " << s2._vector.size() << ENDL;
	// std::cout << "AT 0: " << s2._vector.at(0) << ENDL;
	// std::cout << "AT 1: " << s2._vector.at(1) << ENDL;
	// std::cout << "AT 2: " << s2._vector.at(2) << ENDL;
	// std::cout << "AT 3: " << s2._vector.at(3) << ENDL;
	// std::cout << "AT 4: " << s2._vector.at(4) << ENDL;


	return (EXIT_SUCCESS);
}
