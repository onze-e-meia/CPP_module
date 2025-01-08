/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:46:06 by tforster          #+#    #+#             */
/*   Updated: 2024/10/15 18:06:19 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "../include/color.hpp"

int main(void) {
	system("clear");
	std::string	str = "HI THIS IS BRAIN";
	std::cout << BG_H_BLU BOLD BLK << str << RST << std::endl;

	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Memory address of the string variable: "
		BOLD H_BLU << &str << RST << std::endl;
	std::cout << "Memory address held by stringPTR: "
		BOLD H_BLU << stringPTR << RST << std::endl;
	std::cout << "Memory address held by stringREF "
		BOLD H_BLU << &stringREF << RST << std::endl;

	std::cout << std::endl;

	std::cout << "Value of the string variable: "
		BOLD H_BLU << str << RST << std::endl;
	std::cout << "Value pointed to by stringPTR: "
		BOLD H_BLU << *stringPTR << RST << std::endl;
	std::cout << "Value pointed to by stringREF: "
		BOLD H_BLU << stringREF << RST << std::endl;
}
