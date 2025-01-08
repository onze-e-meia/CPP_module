/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:19:26 by tforster          #+#    #+#             */
/*   Updated: 2025/01/08 14:01:50 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Point.hpp"
#include "../lib/color.hpp"

static float	cross_product(const Point v1, const Point v2) {
	float	rslt = v1.getX().toFloat() * v2.getY().toFloat() - v1.getY().toFloat() * v2.getX().toFloat();
	if (rslt < 0 )
		rslt = -rslt;
	return (rslt);
}

static float	triangle_area(const Point a, const Point b, const Point c) {
	Point	vec_ab(b.getX() - a.getX(), b.getY() - a.getY());
	Point	vec_ac(c.getX() - a.getX(), c.getY() - a.getY());

	return (cross_product(vec_ab,  vec_ac) / 2);
}

bool bsp(const Point a, const Point b, const Point c, const Point p) {
	float	area = triangle_area(a, b, c);
	if (area == 0) {
		std::cout << N_RED "The points don't form a triamgle" RST ENDL;
		return (false);
	}
	float	area_1 = triangle_area(a, b, p);
	if (area_1 == 0)
		return (false);
	float	area_2 = triangle_area(a, c, p);
	if (area_2 == 0)
		return (false);
	float	area_3 = triangle_area(b, c, p);
	if (area_3 == 0)
		return (false);

	return ((area_1 + area_2 + area_3) > area ? false : true);
}
