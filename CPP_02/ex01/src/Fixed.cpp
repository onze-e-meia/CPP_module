/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:19:28 by tforster          #+#    #+#             */
/*   Updated: 2024/11/13 18:19:26 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#include <iostream>
#include <cmath>
#include "include/Fixed.hpp"
#include "../lib/color.hpp"

// Private functions
Fixed::Fixed(const int _raw_bits, bool): _raw_bits(_raw_bits) {}

void	Fixed::constructor_msg(std::string str, float value) {
	std::cout << BOLD H_BLU << typeid(Fixed).name() << ": " RST << str
		<< " (" GRN << value << RST ")" ENDL;
}

bool	Fixed::isOverflow(int value) const {
	return (value > _MAX_FIXED || value < _MIN_FIXED);
}

// Default constructor
Fixed::Fixed(void): _raw_bits(0) {
	constructor_msg("Default constructor called", 0);
}

// Copy constructor
Fixed::Fixed(const Fixed &other): _raw_bits(other._raw_bits) {
	constructor_msg("Copy constructor called", toFloat());
}

// Copy assignment operator
Fixed &Fixed::operator = (const Fixed &other) {
	constructor_msg("Copy assigment constructor called", other.toFloat());
	if (this != &other) {
		_raw_bits = other._raw_bits;
	}
	return (*this);
}

// Destructor
Fixed::~Fixed(void) {
	constructor_msg("Destructor called", toFloat());
}

// Constant integer constructor
Fixed::Fixed(const int value) {
	if (isOverflow(value)) {
		constructor_msg(RED "Error: " RST "Overflow occured converting int to Fixed", static_cast<float>(value));
		_raw_bits = 0;
	}
	else {
		_raw_bits = (value << _FRAC_BITS);
		constructor_msg("Int constructor called", static_cast<float>(value));
	}
}

// Constant floating-point constructor
Fixed::Fixed(const float value) {
	if (isOverflow(value)) {
		constructor_msg(RED "Error: " RST "Overflow occured converting float to Fixed", value);
		_raw_bits = 0;
	}
	else {
		_raw_bits = static_cast<int>(roundf(value * (1 << _FRAC_BITS)));
		constructor_msg("Float constructor called", value);
	}
}

int	Fixed::getFracBits(void) {
	return (_FRAC_BITS);
}

int	Fixed::getRawBits(void) const {
	std::cout << BOLD H_BLU "getRawBits" RST " member function called\n";
	return (_raw_bits);
}

void	Fixed::setRawBits(const int raw) {
	std::cout << BOLD H_BLU "setRawBits" RST " member function called\n";
	_raw_bits = raw;
}

int	Fixed::toInt(void) const {
	return (static_cast<int>(_raw_bits >> _FRAC_BITS));
}

float	Fixed::toFloat(void) const {
	return (static_cast<float>(_raw_bits) / (1 << _FRAC_BITS));
}

// Overload of the insertion (<<) operator
std::ostream &operator<<(std::ostream &oS, const Fixed &other) {
	oS << other.toFloat();
	return (oS);
}
