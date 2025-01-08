/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:22:34 by tforster          #+#    #+#             */
/*   Updated: 2024/11/13 18:29:41 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include "include/Fixed.hpp"
#include "../lib/color.hpp"

const int	FRAC_BITS = Fixed::getFracBits();
const int	BITS = 256;
const float	PRECISION = (float)1 / BITS;
const int	MAX_FIXED = (1 << (31 - FRAC_BITS)) - 1;

static void	explain_0(void);
static void	explain_1(void);
static void	explain_2(void);

static void	example(std::string str, float nb);

int main(int argc, char **argv) {
	system("clear");

	std::string	str;
	if (argc == 2 && (str = argv[1]) == "e") {
		explain_0();
		example("1", 2.3333);
		example("2", 2.9999);

		explain_1();
		example("3", 0.0019);
		example("4", 0.002);
		example("One and a half times the precision - epsilon (0.00000001)", PRECISION + PRECISION/2 - 0.00000001);
		example("Two times the precision", 2 * PRECISION);

		explain_2();
		std::cout << std::fixed << std::setprecision(4);
		example("Max Fixed (8388607.749)", 8388607.749f);
		example("Overflow (8388607.75)", 8388607.75f);

		std::cout << ENDL N_RED
			"   Using double to get the value of the max fixed:" RST ENDL
			N_RED "   INT MAX: " RST << INT_MAX << ENDL
			N_RED "   To Fixed: " RST << (double)INT_MAX/BITS << ENDL
			N_RED "   Back to float: " RST << (double)8388607.9961 * BITS << ENDL;
		return EXIT_SUCCESS;
	}

	// DEFAULT constructor called
	Fixed a;
	// INT constructor called
	Fixed b(10);
	// FLOAT constructor called
	Fixed c(42.42f);
	// COPY assigment constructor called
	Fixed const d(b);

	// COPY assigment constructor called
	a = Fixed(1234.4321f);
	std::cout << ENDL;

	std::cout << std::fixed << std::setprecision(4)
		<< N_RED "Printing with 4 decimlas places" RST ENDL
		"a is " << a << ENDL
		"b is " << b << ENDL
		"c is " << c << ENDL
		"d is " << d << ENDL
		ENDL;

	std::cout << std::scientific
		<< N_RED "Printing with 0 decimlas places (as int)" RST ENDL
		"a is " << a.toInt() << " as integer" << ENDL
		"b is " << b.toInt() << " as integer" << ENDL
		"c is " << c.toInt() << " as integer" << ENDL
		"d is " << d.toInt() << " as integer" << ENDL
		ENDL;

	// std::cout.unsetf(std::ios_base::floatfield);
	std::cout
		<< N_RED "Printing with scientific notation (as float)" RST ENDL
		"a is " << a.toFloat() << " as float" << ENDL
		"b is " << b.toFloat() << " as float" << ENDL
		"c is " << c.toFloat() << " as float" << ENDL
		"d is " << d.toFloat() << " as float" << ENDL
		ENDL;


	std::cout << std::fixed << std::setprecision(0)
		<< N_RED "Check int MAX_FIXED and overflow" RST ENDL;
	Fixed max_int = Fixed(8388607);
	Fixed int_over = Fixed(8388608);
	std::cout<< "max_int " << max_int.getRawBits() << ENDL
		"int overflow is " << int_over.getRawBits() << ENDL
		ENDL;

	std::cout << std::fixed << std::setprecision(4)
		<< N_RED "Check float MAX_FIXED and overflow" RST ENDL;
	std::cout << "8388607.749 to ";
	Fixed max_float = Fixed(8388607.749f);
	std::cout << "8388607.75 to ";
	Fixed float_over = Fixed(8388607.75f);
	std::cout << "max_int " << max_float.getRawBits() << ENDL
		"float overflow is " << float_over.getRawBits() << ENDL
		ENDL;

	std::cout << N_RED "CLEAR OBJECTS" RST ENDL;
	return EXIT_SUCCESS;
}

static void explain_0(void) {
	std::cout << N_RED
		"The expression (1 << bits) computes 2^8." ENDL
		"In binary this left shift 00000001 to 100000000 (wich is 256)." ENDL
		"The result of the multiplication is rounded to the nearest integer," ENDL
		"Then cast to (int), trunacing the fractional part." ENDL RST;
}

static void explain_1(void) {
	std::cout << ENDL N_RED
		"The smallest increment that we can represent is 2^(-8) = 1/256." ENDL
		"   smallest:" RST ENDL
		"   " << PRECISION << ENDL;
		N_RED "So any float number that we convert will have at best that precision:" RST ENDL;
}

static void explain_2(void) {
	std::cout << ENDL N_RED
		"The biggest int can be calculated using the following:" ENDL
		"(1 << (31 - _FRAC_BITS)) - 1 = 111.1111.1111.1111.1111.1111" ENDL
		"   biggest int:" RST ENDL
		"   " << MAX_FIXED << ENDL;
}

static void example(std::string str, float nb) {
	int			raw;

	std::cout << N_RED ENDL
		"   Example: " << str << RST ENDL
		"   " << nb << " * " << BITS << " = " << nb * BITS << ENDL;
	raw = roundf(nb * BITS);
	std::cout << N_RED
		"   Roundig to the nearest integer we get the RawBits:" RST ENDL
		"   roundf(" << nb * BITS << ") = " << raw << ENDL ;
	nb = (float)raw / BITS;
	std::cout << N_RED
		"   Converting back to (float); RawBits / (1 << bits):" RST ENDL
		"   " << nb << ENDL;
}
