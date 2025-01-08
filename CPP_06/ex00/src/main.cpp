/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:15:05 by tforster          #+#    #+#             */
/*   Updated: 2024/12/19 15:23:24 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <string>
#include <iostream>
#include "include/ScalarConverter.hpp"
#include "lib/color.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Too few argumets" << std::endl;
		return EXIT_FAILURE;
	}

	// std::string	str[] ={"", "a", "-a", "nan", "nanf", "-inf", "inf", "+inf", "  inff", "11.f"};

	// std::size_t size = sizeof(str) / sizeof(str[0]);

	// std::cout << "size = " << size << ENDL;

	// for (std::size_t i = 0; i < size; i++) {
	// 	std::cout << "STRING: " << str[i].c_str() <<
	// 		" FLOAT: " << std::strtof(str[i].c_str(), NULL) <<
	// 		" DOUBLE: " << std::strtod(str[i].c_str(), NULL) << ENDL;
	// }

	// // std::string s = "1111";
	// // float ff = 11.f;
	// // double dd = 1.;

	// std::string	test = "   11111111111111111111111111111111111111.1f";
	// char	*end;
	// double	d = std::strtod(test.c_str(), &end);
	// std::cout << d << ENDL;
	// std::cout << end << ENDL;
	// std::cout << *end << *(end + 1) << DENDL;
	// float	f = std::strtof(test.c_str(), &end);
	// std::cout << f << ENDL;
	// std::cout << end << ENDL;
	// std::cout << *end << *(end + 1) << DENDL;

	ScalarConverter::convert(argv[1]);

	return (EXIT_SUCCESS);
}
