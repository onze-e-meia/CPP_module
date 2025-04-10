/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:15:05 by tforster          #+#    #+#             */
/*   Updated: 2025/01/11 19:03:54 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iostream>
#include "include/ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Too few argumets: " << argc - 1 << std::endl;
		return EXIT_FAILURE;
	}
	else if (argc > 2) {
		std::cout << "Too many argumets: " << argc - 1 << std::endl;
		return EXIT_FAILURE;
	}
	ScalarConverter::convert(argv[1]);
	return (EXIT_SUCCESS);
}
