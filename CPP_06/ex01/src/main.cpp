/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:47:30 by tforster          #+#    #+#             */
/*   Updated: 2025/01/12 17:45:12 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "include/Serializer.hpp"
#include "include/Data.hpp"
#include "lib/color.hpp"

#define STR_BOOL(x, y) std::string (x == y ? "TRUE" : "FALSE")
#define SHOWDATA(string, data) std::cout << COP << string << RENDL << *data << ENDL << data << ENDL

int	main(void) {
	std::system("clear");
	uintptr_t	ptr = 0;
	Data		*null_data = NULL;
	Data		*data = new Data();

	SHOWDATA("Data contents and adress of Original data: ", data);

	ptr = Serializer::serialize(data);
	Data *des_data = Serializer::deserializer(ptr);
	std::cout << ENDL COP "Serialize Data: " RST << ptr << ENDL
		COP "Deserialize Data: " RST << des_data << ENDL
		COP "Compare adress: " RST << STR_BOOL(data, des_data) << ENDL;
	SHOWDATA("Check contents and adress of Deserialized Data: ", des_data);

	std::cout << ENDL COP "Change values on original data: " ENDL;
	data->setInt(42);
	data->setFloat(42.42f);
	data->setText("Some 42 data.");
	SHOWDATA("Original Data: ", data);
	SHOWDATA("Deserialized Data: ", data);

	std::cout << ENDL COP "Atribute Deserialized Data to a new Data" RENDL;
	Data		*new_data;
	new_data = des_data;
	SHOWDATA("New Data: ", new_data);

	std::cout << ENDL COP "Test with data null pointer: " RENDL;
	ptr = Serializer::serialize(null_data);
	des_data = Serializer::deserializer(ptr);
	std::cout << COP "Serialize Data: " RST << ptr << ENDL
		COP "Deserialize Data: " RST << des_data << ENDL
		COP "Compare adress: " RST << STR_BOOL(null_data, des_data) << DENDL;

	std::cout << COP "Some unsafe shit: " RENDL;
	ptr = Serializer::serialize(data) + 1;
	des_data = Serializer::deserializer(ptr);
	std::cout << COP "Serialize Data: " RST << ptr << ENDL
		COP "Deserialize Data: " RST << des_data << ENDL
		COP "Compare adress: " RST << STR_BOOL(data, des_data) << ENDL;
	// SHOWDATA("Check contents and adress of Deserialized Data: ", des_data);

	delete data;
	return (EXIT_SUCCESS);
}
