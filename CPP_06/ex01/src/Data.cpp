/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:18:07 by tforster          #+#    #+#             */
/*   Updated: 2025/01/11 20:46:46 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Data.hpp"

Data::Data(void): _someInt(0), _someFloat(0.0f), _someText("Empty") {}

Data::Data(int someInt, float someFloat, const std::string &someText):
	_someInt(someInt), _someFloat(someFloat), _someText(someText) {}

Data::Data(const Data &other):
	_someInt(other._someInt), _someFloat(other._someFloat), _someText(other._someText) {}

Data &Data::operator=(const Data &other) {
	if (this != &other) {
		_someInt = other._someInt;
		_someFloat = other._someFloat;
		_someText = other._someText;
	}
	return (*this);
}

Data::~Data(void) {}

void	Data::setInt(int someInt) {
	_someInt = someInt;
}

void	Data::setFloat(float someFloat) {
	_someFloat = someFloat;
}

void	Data::setText(std::string someText) {
	_someText = someText;
}

int	Data::getInt(void) const {
	return (_someInt);
}

float	Data::getFloat(void) const {
	return (_someFloat);
}

std::string Data::getText(void) const {
	return (_someText);
}

std::ostream &operator<<(std::ostream &os, const Data &data) {
	return (os << "[DATA] {int: " << data.getInt() <<
		" float: " << data.getFloat() <<
		" text: " << data.getText() << "}");
}
