/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:05:45 by tforster          #+#    #+#             */
/*   Updated: 2024/11/19 17:21:30 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#include <iostream>
#include "include/Point.hpp"
#include "../lib/color.hpp"

// Private member functions
void	Point::point_construc_msg(std::string str, Fixed x, Fixed y) const{
	std::cout << BOLD H_BLU << typeid(Point).name() << ": " RST << str
		<< " (" GRN << x << ", " << y << RST ")" ENDL;
}

// Default constructor
Point::Point(void): _x(0), _y(0) {
	#ifdef MSG
		point_construc_msg("Default constructor called", _x, _y);
	#endif
};

// Copy constructor
Point::Point(const Point &other): _x(other._x), _y(other._y) {
	#ifdef MSG
		point_construc_msg("Copy constructor called", other._x, other._y);
	#endif
};

// Copy assignment operator
Point &Point::operator=(const Point &other) {
	#ifdef MSG
		point_construc_msg("Copy assigment constructor called", other._x, other._y);
	#endif
	if (this != &other) {
		const_cast<Fixed&>(_x) = other._x;
		const_cast<Fixed&>(_y) = other._y;
	}
	return (*this);
}

// Destructor
Point::~Point(void) {
	#ifdef MSG
		point_construc_msg("Destructor called", _x, _y);
	#endif
}

// Two constant floating-point numbers constructor
Point::Point(const float x, const float y): _x(x), _y(y) {
	#ifdef MSG
		point_construc_msg("Two constant floating-point numbers constructor called", _x, _y);
	#endif
};

// Two constant fixed-point numbers constructor
Point::	Point(const Fixed x, const Fixed y): _x(x), _y(y) {
	#ifdef MSG
		point_construc_msg("Two constant fixed-point numbers constructor called", _x, _y);
	#endif
}

// Getters
Fixed Point::getX(void) const {
	return (_x);
}

Fixed Point::getY(void) const {
	return (_y);
}
