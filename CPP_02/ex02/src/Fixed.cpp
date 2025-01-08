/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:19:28 by tforster          #+#    #+#             */
/*   Updated: 2024/11/12 15:54:20 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#include <iostream>
#include <cmath>
#include "include/Fixed.hpp"
#include "../lib/color.hpp"

// Private member functions

// Private raw bits constructor
Fixed::Fixed(const int _raw_bits, bool): _raw_bits(_raw_bits) {}

void	Fixed::constructor_msg(std::string str, float value) const{
	std::cout << BOLD H_BLU << typeid(Fixed).name() << ": " RST << str
		<< " (" GRN << value << RST ")" ENDL;
}

bool	Fixed::isOverflow(int value) const {
	return (value > _FIXED_MAX || value < _FIXED_MIN);
}

// Default constructor
Fixed::Fixed(void): _raw_bits(0) {
	#ifdef MSG
		constructor_msg("Default constructor called", 0);
	#endif
}

// Copy constructor
Fixed::Fixed(const Fixed &other): _raw_bits(other._raw_bits) {
	#ifdef MSG
		constructor_msg("Copy constructor called", toFloat());
	#endif
}

// Copy assignment operator
Fixed &Fixed::operator = (const Fixed &other) {
	#ifdef MSG
		constructor_msg("Copy assigment constructor called", other.toFloat());
	#endif
	if (this != &other) {
		_raw_bits = other._raw_bits;
	}
	return (*this);
}

// Destructor
Fixed::~Fixed(void) {
	#ifdef MSG
		constructor_msg("Destructor called", toFloat());
	#endif
}

// Constant integer constructor
Fixed::Fixed(const int value) {
	if (isOverflow(value)) {
		constructor_msg(RED "Error: " RST "Overflow occured converting int to Fixed", static_cast<float>(value));
		_raw_bits = 0;
	}
	else {
		_raw_bits = (value << _FRAC_BITS);
		#ifdef MSG
			constructor_msg("Int constructor called", static_cast<float>(value));
		#endif
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
		#ifdef MSG
			constructor_msg("Float constructor called", value);
		#endif
	}
}

// Getters & Setters
int	Fixed::getRawBits(void) const {
	#ifdef MSG
		std::cout << BOLD H_BLU "getRawBits" RST " member function called\n";
	#endif
	return (_raw_bits);
}

void	Fixed::setRawBits(const int raw) {
	_raw_bits = raw;
}

// Static member functions
Fixed &Fixed::min(Fixed &fp1, Fixed &fp2) {
	return ( fp1 < fp2 ? fp1 : fp2);
}

Fixed &Fixed::max(Fixed &fp1, Fixed &fp2) {
	return ( fp1 > fp2 ? fp1 : fp2);
}

const Fixed &Fixed::min(const Fixed &fp1, const Fixed &fp2) {
	return ( fp1 < fp2 ? fp1 : fp2);
}

const Fixed &Fixed::max(const Fixed &fp1, const Fixed &fp2) {
	return ( fp1 > fp2 ? fp1 : fp2);
}

int	Fixed::getFracBits(void) {
	return (_FRAC_BITS);
}

int	Fixed::getFixedMax(void) {
	return (_FIXED_MAX);
}

int	Fixed::getFixedMin(void) {
	return (_FIXED_MIN);
}

// Member functions
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

// Comparison operators
bool Fixed::operator>(const Fixed &other) const {
	return (_raw_bits > other._raw_bits);
}

bool Fixed::operator>=(const Fixed &other) const {
	return (_raw_bits >= other._raw_bits);
}

bool Fixed::operator<(const Fixed &other) const {
	return (_raw_bits < other._raw_bits);
}

bool Fixed::operator<=(const Fixed &other) const {
	return (_raw_bits <= other._raw_bits);
}

bool Fixed::operator==(const Fixed &other) const {
	return (_raw_bits == other._raw_bits);
}

bool Fixed::operator!=(const Fixed &other) const {
	return (_raw_bits != other._raw_bits);
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(_raw_bits + other._raw_bits, true);
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(_raw_bits - other._raw_bits, true);
}

Fixed Fixed::operator*(const Fixed &other) const {
	long	long_this = static_cast<long>(_raw_bits);
	long	long_other = static_cast<long>(other._raw_bits);

	return Fixed(static_cast<int>((long_this * long_other) >> _FRAC_BITS), true);
}

Fixed Fixed::operator/(const Fixed &other) const {
	if (other._raw_bits == 0) {
		constructor_msg(RED "Error: " RST "Division by ", 0);
		return (Fixed());
	}

	long	long_this = static_cast<long>(_raw_bits);
	long	long_other = static_cast<long>(other._raw_bits);

	return Fixed(static_cast<int>((long_this << _FRAC_BITS) / long_other), true);
}

// Increment and Decrement operators
Fixed &Fixed::operator++(void){
	++_raw_bits;
	return (*this);
}

Fixed &Fixed::operator--(void){
	--_raw_bits;
	return (*this);
}

Fixed Fixed::operator++(int){
	return (Fixed(_raw_bits++, true));
}

Fixed Fixed::operator--(int){
	return (Fixed(_raw_bits--, true));
}
