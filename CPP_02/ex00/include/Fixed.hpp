/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:09:16 by tforster          #+#    #+#             */
/*   Updated: 2024/10/30 14:14:04 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed {
	private:
		int _value;
		static const int _FRAC_BITS = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed &operator = (const Fixed &other);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(const int raw);
};

#endif
