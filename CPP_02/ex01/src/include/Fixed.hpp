/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:09:16 by tforster          #+#    #+#             */
/*   Updated: 2024/11/06 16:04:51 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed {
	private:
		int 				_raw_bits;
		static const int	_FRAC_BITS = 8;
		static const int	_MAX_FIXED = (1 << (31 - _FRAC_BITS)) - 1;
		static const int	_MIN_FIXED = -(1 << (31 - _FRAC_BITS));

		Fixed(const int _raw_bits, bool);
		void	constructor_msg(std::string str, float value);
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

		static int	getFracBits(void);
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

// Overload of the insertion (<<) operator
std::ostream &operator<<(std::ostream &oS, const Fixed &other);

#endif
