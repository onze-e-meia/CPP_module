/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:16:48 by tforster          #+#    #+#             */
/*   Updated: 2025/01/27 16:12:40 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include "include/Span.hpp"
#include "lib/color.hpp"

#define PRINT_TEST(test)	std::cout << ENDL BOLD COP << test << RENDL

int	main(void) {
	std::system("clear");
	std::srand(static_cast<unsigned int>(std::time(0)));

	PRINT_TEST("Subject test:");
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	PRINT_TEST("Try to make negative Span:");
	try {
		Span	neg(-1);
	} catch (std::exception &e) {
		std::cerr << e.what() << ENDL;
	}

	PRINT_TEST("Make Span of size 0:");
	Span	span_0;
	std::cout << D_BLU "SIZE: " RST << span_0.size() << ENDL
		<< D_BLU "MAX_SIZE: " RST << span_0.max_size() << ENDL
		<< "Try to check position 0:" ENDL;
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
	std::cout << D_BLU "SIZE: " RST << span_1.size() << ENDL
		<< D_BLU "MAX_SIZE: " RST << span_1.max_size() << ENDL
		<< "Try to add a two numbers (99 and 1):" ENDL;
	span_1.addNumber(99);
	try {
		span_1.addNumber(1);
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}
	std::cout << D_BLU "Span: " RST << span_1 << ENDL
		<< D_BLU "SIZE: " RST << span_1.size() << ENDL
		<< "Try to get shortest span:" ENDL;
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
	std::cout << "Try to sort:" ENDL;
	try {
		span_1.sort();
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}

	PRINT_TEST("Make Span of size 2:");
	Span	span_2(2);
	std::cout << D_BLU "SIZE: " RST << span_2.size() << ENDL
		<< D_BLU "MAX_SIZE: " RST << span_2.max_size() << ENDL
		<< "Fill Span with random numbers:" ENDL;
	span_2.randomFill();
	std::cout << D_BLU "Span       : " RST << span_2 << ENDL
		<< D_BLU "Sorted Span: " RST << span_2.sort() << ENDL
		<< D_BLU "SIZE: " RST << span_2.size() << ENDL;
	std::cout << "Try to add a number (99):" ENDL;
	try {
		span_2.addNumber(99);
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}
	std::cout << "Try to check position 2:" ENDL;
	try {
		std::cout << D_BLU "Number at [2]: " RST << span_2[2] << ENDL;
	} catch (std::exception &e) {
		std::cerr << e.what() << ENDL;
	}
	std::cout << "Get shortest span:" ENDL
		<< D_BLU "Shortest: " RST << span_2.shortestSpan() << ENDL
		<< "Get longest span:" ENDL
		<< D_BLU "Longest: " RST << span_2.longestSpan() << ENDL;

	PRINT_TEST("Make Span of size 10:");
	Span	span_10(10);
	std::cout << D_BLU "SIZE: " RST << span_10.size() << ENDL
		<< D_BLU "MAX_SIZE: " RST << span_10.max_size() << ENDL
		<< "Fill Span with random numbers:" ENDL;
	span_10.randomFill();
	const Span	const_span(span_10);
	std::cout << D_BLU "Span       : " RST << span_10 << ENDL
		<< D_BLU "Sorted Span: " RST << span_10.sort() << ENDL
		<< D_BLU "SIZE: " RST << span_10.size() << ENDL
		<< "Get shortest span:" ENDL
		<< D_BLU "Shortest: " RST << span_10.shortestSpan() << ENDL
		<< "Get longest span:" ENDL
		<< D_BLU "Longest: " RST << span_10.longestSpan() << ENDL
		<< "Test with const Span:" ENDL
		<< D_BLU "Span       : " RST << const_span << ENDL;

	PRINT_TEST("Make Span of size 10.000:");
	Span	big_span(10000);
	std::cout << D_BLU "SIZE: " RST << big_span.size() << ENDL
		<< D_BLU "MAX_SIZE: " RST << big_span.max_size() << ENDL
		<< "Fill Span with random numbers:" ENDL;
	big_span.randomFill();
	std::cout << D_BLU "SIZE: " RST << big_span.size() << ENDL
		<< "Get shortest span:" ENDL
		<< D_BLU "Shortest: " RST << big_span.shortestSpan() << ENDL
		<< "Get longest span:" ENDL
		<< D_BLU "Longest: " RST << big_span.longestSpan() << ENDL;

	return (EXIT_SUCCESS);
}
