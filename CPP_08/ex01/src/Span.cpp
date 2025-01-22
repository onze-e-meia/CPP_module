/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:31:01 by tforster          #+#    #+#             */
/*   Updated: 2025/01/22 20:13:11 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <cstddef>
#include <cstdlib>
// #include <limits>
#include <stdexcept>
#include <string>
#include <sstream>
// #include <iostream>
#include <vector>
#include <algorithm>
#include "include/Span.hpp"
#include "lib/color.hpp"


static int randomInt(int size) {
	return (-size + std::rand() % (2 * size + 1));
}

Span::Span(void):
	_vector(0),
	_size(0) {}

Span::Span(const int size):
	_vector(0),
	_size(size) {
		_vector.reserve(_size);
}

Span::Span(const Span &other):
	_vector(other._vector),
	_size(other._size) {}


Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_vector = other._vector;
		_size = other._size;
	}
	return (*this);
}

Span::~Span(void) {}

int	Span::shortestSpan(void) const {
	if (this->_vector.size() < 2) {
		std::ostringstream	oss;
		oss << L_RED "Error: " RST "Size is less than 2, can't find shortest span";
		throw (std::out_of_range(oss.str()));
	}

	return (0);
}

int	Span::longestSpan(void) const {
	if (this->_vector.size() < 2) {
		std::ostringstream	oss;
		oss << L_RED "Error: " RST "Size is less than 2, can't find longest span";
		throw (std::out_of_range(oss.str()));
	}
	std::vector<int>	sorted(_vector);
	std::sort(sorted.begin(), sorted.end());
	return (sorted.back() - sorted.front());
}

void	Span::addNumber(int integer) {
	if (_vector.size() >= _size) {
		std::ostringstream	oss;
		oss << L_RED "Error: " RST "Can't add number, Span of size [" << _size << "] is full";
		throw (std::overflow_error(oss.str()));
	}
	_vector.push_back(integer);
}

void	Span::randomFill(void) {
	if (_vector.size() == _size) {
		std::ostringstream	oss;
		oss << L_RED "Error: " RST "Can't add number, Span of size [" << _size << "] is full";
		throw (std::overflow_error(oss.str()));
	}
	while (_vector.size() < _size) {
		_vector.push_back(randomInt(_size));
	}
}

unsigned int	Span::size() const {
	return (_vector.size());
}

unsigned int	Span::max_size() const {
	return (_size);
}

const std::vector<int>::const_iterator	Span::begin() const {
	return (_vector.begin());
}

const std::vector<int>::const_iterator	Span::end() const {
	return (_vector.end());
}

std::vector<int>::iterator	Span::begin(){
	return (_vector.begin());
}

std::vector<int>::iterator	Span::end() {
	return (_vector.end());
}

const int &Span::operator[](const std::size_t &index) const {
	if (index < _size)
		return _vector[index];
	throw (std::out_of_range("Index out of range"));
}

int &Span::operator[](const std::size_t &index) {
	if (index < _size)
		return _vector[index];
	throw (std::out_of_range("Index out of range"));
}

std::ostream &operator<<(std::ostream &os, Span &span) {
	os << "[";
	std::vector<int>::iterator it = span.begin();
	std::vector<int>::iterator end = span.end();
	while (it != end) {
		os << *it;
		it++;
		if (it != end)
			os << ", ";
	}
	os << "]";
	return (os);
}

std::ostream &operator<<(std::ostream &os, const Span &span) {
	os << "[";
	std::vector<int>::const_iterator it = span.begin();
	std::vector<int>::const_iterator end = span.end();
	while (it != end) {
		os << *it;
		it++;
		if (it != end)
			os << ", ";
	}
	os << "]";
	return (os);
}
