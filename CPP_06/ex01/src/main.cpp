/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:47:30 by tforster          #+#    #+#             */
/*   Updated: 2025/01/11 20:51:00 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "include/Serializer.hpp"
#include "include/DataClass.hpp"

int	main(void) {
	DataClass	data;

	data.setInt(42);
	data.setFloat(42.42);
	data.setText("Just some data");

	uintptr_t	ptr = 0;

	std::cout << "Data before serialize" << std::endl;
	std::cout << data << std::endl;
	std::cout << "uintptr_t: " << ptr << std::endl;

	ptr = Serializer::serialize(data);

	std::cout << "Data after serialize" << std::endl;
	std::cout << "uintptr_t: " << ptr << std::endl;

	Data *testData;

	testData = Serializer::deserializer(ptr);

	std::cout << "Data after deserializer" << std::endl;
	std::cout << *testData << std::endl;
	std::cout << "uintptr_t: " << ptr << std::endl;



	return (EXIT_SUCCESS);
}
