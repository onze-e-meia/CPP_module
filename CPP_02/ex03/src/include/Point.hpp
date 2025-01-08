/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:39:21 by tforster          #+#    #+#             */
/*   Updated: 2024/11/12 19:51:56 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;

		// Private raw bits constructor
		void	point_construc_msg(std::string str, Fixed x, Fixed y) const;

	public:
		// Default constructor
		Point(void);
		// Copy constructor
		Point(const Point &other);
		// Copy assignment operator
		Point &operator=(const Point &other);
		// Destructor
		~Point(void);

		// Two constant floating-point numbers constructor
		Point(const float x, const float y);

		// Two constant fixed-point numbers constructor
		Point(const Fixed x, const Fixed y);

		// Getters
		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
