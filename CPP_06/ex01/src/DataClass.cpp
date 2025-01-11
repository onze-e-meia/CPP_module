/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataClass.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:18:07 by tforster          #+#    #+#             */
/*   Updated: 2025/01/11 20:46:46 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/DataClass.hpp"

DataClass::DataClass(void): _someInt(0), _someFloat(0), _someText("") {}

DataClass::DataClass(int someInt, float someFloat, std::string someText):
	_someInt(someInt),
	_someFloat(someFloat),
	_someText(someText) {}

DataClass::DataClass(const DataClass &other):
	_someInt(other._someInt),
	_someFloat(other._someFloat),
	_someText(other._someText) {}

DataClass &DataClass::operator=(const DataClass &other) {
	if (this != &other) {
		_someInt = other._someInt;
		_someFloat = other._someFloat;
		_someText = other._someText;
	}
	return (*this);
}

DataClass::~DataClass(void) {}

void DataClass::setInt(int someInt) {
	_someInt = someInt;
}

void DataClass::setFloat(float someFloat) {
	_someFloat = someFloat;
}

void DataClass::setText(std::string someText) {
	_someText = someText;
}

int DataClass::getInt(void) const {
	return (_someInt);
}

float DataClass::getFloat(void) const {
	return (_someFloat);
}

std::string DataClass::getText(void) const {
	return (_someText);
}


std::ostream &operator<<(std::ostream &os, const DataClass &data) {
	return os << "[DATA] int: " << data.getInt() <<
		" float: " << data.getFloat() <<
		" text:" << data.getText();
}
