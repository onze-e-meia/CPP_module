/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:09:16 by tforster          #+#    #+#             */
/*   Updated: 2024/11/12 18:41:28 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed {
	private:
		int 				_raw_bits;
		static const int	_FRAC_BITS = 8;
		static const int	_FIXED_MAX = (1 << (31 - _FRAC_BITS)) - 1;
		static const int	_FIXED_MIN = -(1 << (31 - _FRAC_BITS));

		// Private raw bits constructor
		Fixed(const int _raw_bits, bool);
		void	constructor_msg(std::string str, float value) const;
		bool	isOverflow(int value) const;

	public:
		// Default constructor
		Fixed(void);
		// Copy constructor
		Fixed(const Fixed &other);
		// Copy assignment operator
		Fixed &operator=(const Fixed &other);
		// Destructor
		~Fixed(void);

		// Constant integer constructor
		Fixed(const int value);
		// Constant floating-point constructor
		Fixed(const float value);

		// Static member function
		static Fixed &min(Fixed &fp1, Fixed &fp2);
		static Fixed &max(Fixed &fp1, Fixed &fp2);
		static const Fixed &min(const Fixed &fp1, const Fixed &fp2);
		static const Fixed &max(const Fixed &fp1, const Fixed &fp2);

		static int	getFracBits(void);
		static int	getFixedMax(void);
		static int	getFixedMin(void);

		// Getters & Setters
		int		getRawBits(void) const;
		void	setRawBits(const int raw);

		// Member function
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed	abs(void) const;

		// Comparison operators
		bool operator>(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// Arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// Increment and Decrement operators
		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
};

// Overload of the insertion (<<) operator
std::ostream &operator<<(std::ostream &oS, const Fixed &other);

#endif
