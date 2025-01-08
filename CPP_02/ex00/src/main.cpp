/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:22:34 by tforster          #+#    #+#             */
/*   Updated: 2024/11/13 18:17:51 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "../include/Fixed.hpp"
#include "../include/color.hpp"

int main(void) {
	std::cout << CL_SCREEN CURSOR_HM;
	// Default constructor called
	Fixed a;
	// Copy constructor called
	Fixed b(a);
	// Default constructor called
	Fixed c;

	// Copy assigment constructor called
	c = b;

	std::cout << "\n";

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	b.setRawBits(256);
	std::cout << b.getRawBits() << std::endl;
	c = b;
	std::cout << c.getRawBits() << std::endl;

	std::cout << "\n";

	return 0;
}
