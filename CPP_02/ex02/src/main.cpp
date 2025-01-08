/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:22:34 by tforster          #+#    #+#             */
/*   Updated: 2024/11/12 15:51:01 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <string>
#include "include/Fixed.hpp"
#include "../lib/color.hpp"

const int	FRAC_BITS = Fixed::getFracBits();
const int	BITS = 1 << FRAC_BITS;
const float	PRECISION = (float)1 / BITS;

static void comp_msg(std::string comp, Fixed a,  Fixed b);
static bool comp_result(std::string comp, Fixed a,  Fixed b);

static void oprt_msg(std::string oprt, Fixed a, Fixed b);
static Fixed oprt_result(std::string oprt, Fixed a, Fixed b);

static void	function_msg(std::string func, Fixed fb1, Fixed fb2, Fixed rslt);

int main(int argc, char **argv) {
	system("clear");
	std::cout << N_RED "Argument <s> for subject test." ENDL
		"Argument <p> for 4 decimlas places." RST ENDL;

	std::string	str;
	if (argc == 2 && (str = argv[1]) == "s") {
		Fixed	a;
		Fixed	b(Fixed(5.05f) * Fixed(2));

		std::cout << N_RED "Subject test:" RST ENDL;
		std::cout << a << ENDL
			<< ++a << ENDL
			<< a << ENDL
			<< a++ << ENDL
			<< a << ENDL;

		std::cout << b << ENDL
			<< Fixed::max(a, b) << ENDL;

		return EXIT_SUCCESS;
	}

	if (argc == 2 && (str = argv[1]) == "p") {
			std::cout << std::fixed << std::setprecision(4);
	}
	const Fixed	min = Fixed::getFixedMin();
	const Fixed minus = -1;
	const Fixed	zero = 0;
	const Fixed	epsilon = PRECISION;
	const Fixed	one = 1;
	const Fixed frac = 1.f/3;
	const Fixed ft = 42;
	const Fixed	max = Fixed::getFixedMax();

	std::cout << N_RED "Test wiht comparison operators:" RST ENDL;
	comp_msg(">", ft * epsilon, one + minus);
	comp_msg(">", zero, zero);
	comp_msg(">=", ft / frac, ft / frac);
	comp_msg(">=", ft * ft, max);
	comp_msg("<", one - frac, one - minus);
	comp_msg("<", frac, frac);
	comp_msg("<=", one, ft * (one + one));
	comp_msg("<=", max, ft * ft * ft);
	comp_msg("==" , one + frac, one + frac);
	comp_msg("==" , min * frac, epsilon);
	comp_msg("!=" , minus * one, zero);
	comp_msg("!=" , epsilon, epsilon);

	std::cout << ENDL N_RED "Test with arithmetic operators:" RST ENDL;
	oprt_msg("+", one, zero);
	oprt_msg("+", minus, ft);
	oprt_msg("-", one, minus);
	oprt_msg("-", max, max / Fixed(2));
	std::cout << N_RED "The overlod will work with a int and convert it to a Fixed" ENDL;
	oprt_msg("-", max, max / 2);
	oprt_msg("*", ft, ft);
	oprt_msg("*", epsilon, ft * ft);
	oprt_msg("/", ft, frac);
	oprt_msg("/", frac, frac);

	std::cout << ENDL N_RED "Euler's number:" RST ENDL;
	Fixed e = 1;
	for (int i = 1, j = 1; i <= 10; i++) {
		j *= i;
		e = e + one / Fixed (j);
	}
	std::cout << BOLD H_BLU << "e" RST " = " GRN << e << RST ENDL
		BOLD H_BLU << "number of epsilon" RST " = " GRN << e / epsilon << RST ENDL
		BOLD H_BLU << "raw bits" RST " = " GRN << e.getRawBits() << RST ENDL;
	Fixed e_int = e.toInt();
	std::cout << BOLD H_BLU << "e to int" RST " = " GRN << e_int << RST ENDL
		BOLD H_BLU << "e int raw bits" RST " = " GRN << e_int.getRawBits() << RST ENDL;


	std::cout << ENDL N_RED "Test with increment/decrement operators:" RST ENDL;
	Fixed x = 1;
	std::cout <<  BOLD H_BLU "++1 = " RST GRN << ++x << RST ENDL;
	x = 1;
	std::cout <<  BOLD H_BLU "1++ = " RST GRN << x++ << RST " (After " GRN << x << RST ")"<< ENDL;
	x = 1;
	std::cout <<  BOLD H_BLU "--1 = " RST GRN << --x << RST ENDL;
	x = 1;
	std::cout <<  BOLD H_BLU "1-- = " RST GRN << x-- << RST " (After " GRN << x << RST ")"<< ENDL;

	std::cout << ENDL N_RED "Test with min/max static member function:" RST ENDL;
	function_msg("min", x, epsilon, Fixed::min(x, epsilon));
	function_msg("min", min, zero, Fixed::min(min, zero));
	function_msg("min", Fixed(3), Fixed(11), Fixed::min(Fixed(3), Fixed(11)));
	function_msg("max", frac, e, Fixed::max(frac, e));
	function_msg("max", e, x, Fixed::max(e, x));
	function_msg("max", Fixed(3.33f), Fixed(11.11f), Fixed::max(Fixed(3.33f), Fixed(11.11f)));

	return EXIT_SUCCESS;
}

static void	comp_msg(std::string comp, Fixed a, Fixed b) {
	std::cout << H_BLU << a << BOLD GRN " " << comp << " " RST H_BLU << b << RST
		<< " is " GRN << (comp_result(comp, a, b) ? "TRUE" : "FALSE") << RST ENDL;
}

static bool	comp_result(std::string comp, Fixed a, Fixed b) {
	if (comp == "==") {
		return (a == b);
	} else if (comp == "!=") {
		return (a != b);
	} else if (comp == "<") {
		return (a < b);
	} else if (comp == "<=") {
		return (a <= b);
	} else if (comp == ">") {
		return (a > b);
	} else if (comp == ">=") {
		return (a >= b);
	} else {
		return ("Invalid comparison operator.");
	}
}

static void	oprt_msg(std::string oprt, Fixed a, Fixed b) {
	std::cout << H_BLU << a << BOLD GRN " " << oprt << " " RST H_BLU << b << RST
		" = " GRN << oprt_result(oprt, a, b) << RST ENDL;
}

static	Fixed oprt_result(std::string oprt, Fixed a, Fixed b) {
	if (oprt == "+") {
		return (a + b);
	} else if (oprt == "-") {
		return (a - b);
	} else if (oprt == "/") {
		return (a / b);
	} else if (oprt == "*") {
		return (a * b);
	} else {
		std::cout << "Invalid math operator." ENDL;
		return (0);
	}
}

static void	function_msg(std::string func, Fixed fb1, Fixed fb2, Fixed rslt) {
	std::cout << GRN << func << RST "(" H_BLU << fb1 << RST ", " H_BLU << fb2 << RST
		") is " GRN << rslt << ENDL;
}
