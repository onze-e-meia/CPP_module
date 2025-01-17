/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:16:48 by tforster          #+#    #+#             */
/*   Updated: 2025/01/17 16:11:04 by tforster         ###   ########.fr       */
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

	PRINT_TEST("INDEX TEST");
	std::cout << "original:" ENDL
		D_BLU "index 4: " RST << int_array[4] << ENDL;
	std::cout << "copy:" ENDL
		D_BLU "index 4: " RST << new_array[4] << ENDL;

	PRINT_TEST("INDEX OUT OF RANGE TEST");
	try {
		std::cout << int_array[12] << ENDL;
	} catch (std::exception &e) {
		std::cerr << e.what() << ENDL;
	}

	PRINT_TEST("ARRAY CHAR TEST");
	Array<char>	text_array(20);
	text_array[0] = 't'; text_array[1] = 'e'; text_array[2] = 's'; text_array[3] = 't';
	PRINT_ELMTS(text_array.size(), text_array);

	PRINT_TEST("ARRAY OF ARRAY OF FLOAT TEST");
	Array<Array<float> >	float_array(3);
	float_array[0] = Array<float>(1);
	float_array[0][0] = 0.0;
	float_array[1] = Array<float>(2);
	float_array[1][0] = 1.0;
	float_array[1][1] = 1.1;
	float_array[2] = Array<float>(3);
	float_array[2][0] = 2.0;
	float_array[2][1] = 2.1;
	float_array[2][2] = 2.2;
	PRINT_ELMTS(float_array.size(), float_array);
	PRINT_ELMTS(float_array[1].size(), float_array[1]);

	return (EXIT_SUCCESS);
}
