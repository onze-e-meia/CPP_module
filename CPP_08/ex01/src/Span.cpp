/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:31:01 by tforster          #+#    #+#             */
/*   Updated: 2025/01/23 16:29:17 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <algorithm>
#include "include/Span.hpp"
#include "lib/color.hpp"

static int randomInt(int size) {
	size *= 5;
	return (-size + std::rand() % (2 * size + 1));
}

Span::Span(void):
	_vector(0),
	_size(0) {}

Span::Span(const int size):
	_vector(0),
	_size(size) {
		if (size < 0)
			throw std::invalid_argument(L_RED "Error: " RST "Span size can't be less then zero.");
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
	std::vector<int>			sorted(_vector);
	std::sort(sorted.begin(), sorted.end());
	std::vector<int>::iterator	it = sorted.begin();
	std::vector<int>::iterator	end = sorted.end();
	int	span = INT_MAX;
	while ((it + 1) != end) {
		if (*(it + 1) - *it < span)
			span = *(it + 1) - *it;
		it++;
	}
	return (std::abs(span));
}

int	Span::longestSpan(void) const {
	if (this->_vector.size() < 2) {
		std::ostringstream	oss;
		oss << L_RED "Error: " RST "Size is less than 2, can't find longest span";
		throw (std::out_of_range(oss.str()));
	}
	int min = *std::min_element(_vector.begin(), _vector.end());
	int max = *std::max_element(_vector.begin(), _vector.end());

	return (std::abs(max - min));
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

Span	Span::sort(void) const {
	if (this->_vector.size() < 2) {
		std::ostringstream	oss;
		oss << L_RED "Error: " RST "Size is less than 2, can't sort";
		throw (std::out_of_range(oss.str()));
	}
	Span				span;
	std::vector<int>	sorted = _vector;

	std::sort(sorted.begin(), sorted.end());
	span._vector = sorted;
	return (span);
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
	throw (std::out_of_range(L_RED "Error: " RST "Index out of range"));
}

int &Span::operator[](const std::size_t &index) {
	if (index < _size)
		return _vector[index];
	throw (std::out_of_range(L_RED "Error: " RST "Index out of range"));
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
