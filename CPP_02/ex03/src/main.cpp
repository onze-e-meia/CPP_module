/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:22:34 by tforster          #+#    #+#             */
/*   Updated: 2024/11/19 17:21:32 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include "include/Fixed.hpp"
#include "include/Point.hpp"
#include "../lib/color.hpp"

bool	format = false;

static std::string	p_str(Point p);
static void	triangle_points(Point a, Point b, Point c);
static void	test_point(Point a, Point b, Point c, Point p);

int main(int argc, char **argv) {
	system("clear");

	std::cout << N_RED "Argument <p> for 4 decimlas places." RST ENDL;
	std::string	str;
	if (argc == 2 && (str = argv[1]) == "p") {
			std::cout << std::fixed << std::setprecision(6);
			format = true;
	}

	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(2.5f, 5.0f);
	triangle_points(a, b, c);
	Point p1(2.5f, 2.0f);	// Inside
	Point p2(5.0f, 5.0f);	// Outside
	Point p3(2.5f, 0.0f);	// Outside (edge)
	Point p4(0.0f, 0.0f);	// Outside (vertex)
	test_point(a, b, c, p1);
	test_point(a, b, c, p2);
	test_point(a, b, c, p3);
	test_point(a, b, c, p4);
	std::cout << ENDL;

	Point a1(0, 0);
	Point b1(5, 10);
	Point c1(0, 10);
	triangle_points(a1, b1, c1);
	Point p11(0.1f, 5);	// Inside
	Point p21(4.9f, 4.9f);	// Outside
	Point p31(10, 10);	// Outside (edge)
	Point p41(5, 10);	// Outside (vertex)
	test_point(a1, b1, c1, p11);
	test_point(a1, b1, c1, p21);
	test_point(a1, b1, c1, p31);
	test_point(a1, b1, c1, p41);
	std::cout << ENDL;

	Point a2(-10, -10);
	Point b2(10, -10);
	Point c2(0, 10);
	triangle_points(a2, b2, c2);
	Point p12(-4.9f, 0);	// Inside
	Point p22(5.1f, 0);	// Outside
	Point p32(0, -10);	// Outside (edge)
	Point p42(0, 10);	// Outside (vertex)
	test_point(a2, b2, c2, p12);
	test_point(a2, b2, c2, p22);
	test_point(a2, b2, c2, p32);
	test_point(a2, b2, c2, p42);
	std::cout << ENDL;

	Fixed	pe = ++Fixed();
	Fixed	ne = --Fixed();
	Point	a3(ne, ne);
	Point	b3(pe, ne);
	Point	c3(0, pe);
	triangle_points(a3, b3, c3);
	Point	p13(0, 0);	// Inside
	Point	p23(pe, pe);	// Outside
	Point	p33(0, ne);	// Outside (edge)
	Point	p43(0, pe);	// Outside (vertex)
	test_point(a3, b3, c3, p13);
	test_point(a3, b3, c3, p23);
	test_point(a3, b3, c3, p33);
	test_point(a3, b3, c3, p43);
	return EXIT_SUCCESS;
}

static std::string	p_str(Point p) {
	std::ostringstream	oss;

	if (format)
		oss << std::fixed << std::setprecision(6);
	oss << "(" GRN << p.getX() << RST ", " GRN << p.getY() << RST ")";

	return (oss.str());
}

static void	triangle_points(Point a, Point b, Point c) {
	std::cout << "Triangle " BOLD H_BLU "point " RST H_BLU "{" RST
		<< p_str(a) << ", " << p_str(b) << ", " << p_str(c)
		<< H_BLU "}" RST ENDL;
}

static void	test_point(Point a, Point b, Point c, Point p) {
	std::cout << "Test " BOLD H_BLU "point " RST << p_str(p)
		<< " is " << (bsp(a, b, c, p) ? GRN "inside" : RED "outside")
		<< RST " the triangle" ENDL;

}
