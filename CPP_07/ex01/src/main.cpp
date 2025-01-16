/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:02:13 by tforster          #+#    #+#             */
/*   Updated: 2025/01/16 19:35:56 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include "include/iter.hpp"
#include "lib/color.hpp"

#define TEST_OUT(test, type)	std::cout << ENDL COP << test << " " BOLD << type << RENDL
#define ERR		L_RED "Error: " RST

typedef void (*func_any)(int);

int	main(void) {
	std::system("clear");

	char	std[] = "HAL";
	int			*array_null = NULL;
	int			array[4] = {1, -1, -1, 0};
	func_any	func_null = NULL;

	TEST_OUT("Test iter with", "char");
	iter(std, 3, sum_one<char>);
	iter(std, 3, print<char>);

	TEST_OUT("Test iter with", "int");
	iter(array, 4, sum_one<int>);
	iter(array, 4, print<int>);

	TEST_OUT("Test iter with", "NULL array");
	try {
		iter(array_null, 4, sum_one<int>);
	} catch (const std::invalid_argument &e) {
		std::cerr << ERR << e.what() << ENDL;
	}

	TEST_OUT("Test iter with", "size -1");
	try {
		iter(array, -1, sum_one<int>);
	} catch (const std::invalid_argument &e) {
		std::cerr << ERR << e.what() << ENDL;
	}

	TEST_OUT("Test iter with", "size 0");
	try {
		iter(array, 0, sum_one<int>);
		iter(array, 0, print<int>);
	} catch (const std::invalid_argument &e) {
		std::cerr << ERR << e.what() << ENDL;
	}

	TEST_OUT("Test iter with", "NULL function");
	try {
		iter(array, 4, func_null);
	} catch (const std::invalid_argument &e) {
		std::cerr << ERR << e.what() << ENDL;
	}

	return (EXIT_SUCCESS);
}
