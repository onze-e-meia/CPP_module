/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:16:48 by tforster          #+#    #+#             */
/*   Updated: 2025/01/16 19:37:41 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include "include/Array.hpp"
#include "lib/color.hpp"

#define PRINT_TEST(test)	std::cout << ENDL COP << test << RENDL
#define PRINT_ELMTS(size, array)	std::cout \
	<< D_BLU "size: " RST << size << ENDL \
	<< D_BLU "elements: " RST << array << ENDL


int main(void) {
	std::system("clear");

	PRINT_TEST("DEFAULT CONSTRUCTOR TEST");
	Array<int> int_array = Array<int>();
	PRINT_ELMTS(int_array.size(), int_array);

	PRINT_TEST("PARAMETERIZED CONSTRUCTOR TEST");
	int_array = Array<int>(5);
	PRINT_ELMTS(int_array.size(), int_array);
	std::cout << "populate array:" ENDL;
	for (std::size_t i = 0; i < int_array.size(); i++)
		int_array[i] += i;
	PRINT_ELMTS(int_array.size(), int_array);

	PRINT_TEST("COPY CONSTRUCTOR TEST");
	Array<int> new_array(int_array);
	std::cout << "original:" ENDL;
	PRINT_ELMTS(int_array.size(), int_array);
	std::cout << "copy:" ENDL;
	PRINT_ELMTS(new_array.size(), new_array);
	std::cout << "change copy and compare arrays:" ENDL;
	for (std::size_t i = 0; i < new_array.size(); i++)
		new_array[i] *= 2;
	std::cout << "original:" ENDL;
	PRINT_ELMTS(int_array.size(), int_array);
	std::cout << "copy:" ENDL;
	PRINT_ELMTS(new_array.size(), new_array);

	PRINT_TEST("ASSIGNMENT OPERATOR TEST");
	new_array = Array<int>(int_array);
	std::cout << "original:" ENDL;
	PRINT_ELMTS(int_array.size(), int_array);
	std::cout << "copy:" ENDL;
	PRINT_ELMTS(new_array.size(), new_array);
	std::cout << "change copy and compare arrays:" ENDL;
	for (std::size_t i = 0; i < new_array.size(); i++)
		new_array[i] *= 7;
	std::cout << "original:" ENDL;
	PRINT_ELMTS(int_array.size(), int_array);
	std::cout << "copy:" ENDL;
	PRINT_ELMTS(new_array.size(), new_array);

	PRINT_TEST("INDEX OUT OF RANGE TEST");
	try {
		std::cout << int_array[12] << ENDL;
	} catch (std::exception &e) {
		std::cerr << e.what() << ENDL;
	}

	return (EXIT_SUCCESS);
}
