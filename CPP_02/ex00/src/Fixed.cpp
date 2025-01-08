/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:19:28 by tforster          #+#    #+#             */
/*   Updated: 2024/11/13 18:18:29 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include "../include/Fixed.hpp"
#include "../include/color.hpp"


Fixed::Fixed(void): _value(0) {
	std::cout << BOLD H_BLU << typeid(Fixed).name()
		<< ": " RST "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other): _value(other._value) {
	std::cout << BOLD H_BLU << typeid(Fixed).name()
		<< ": " RST "Copy constructor called\n";
}

Fixed &Fixed::operator = (const Fixed &other) {
	std::cout << BOLD H_BLU << typeid(Fixed).name()
		<< ": " RST "Copy assigment constructor called\n";
	if (this != &other) {
		_value = other._value;
	}
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << BOLD H_BLU << typeid(Fixed).name()
		<< ": " RST "Destructor called\n";
}

int Fixed::getRawBits(void) const {
	std::cout << BOLD H_BLU "getRawBits" RST " member function called\n";
	return (_value);
}

void Fixed::setRawBits(const int raw) {
	std::cout << BOLD H_BLU "setRawBits" RST " member function called\n";
	_value = raw;
}
