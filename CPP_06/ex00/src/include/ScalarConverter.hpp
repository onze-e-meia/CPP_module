/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:31:20 by tforster          #+#    #+#             */
/*   Updated: 2025/01/11 20:28:47 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

/**
 * @class ScalarConverter
 * @brief A utility class for scalar type conversions.
 *
 * The ScalarConverter class provides a static method to convert a given string
 * into various scalar types (e.g., char, int, float, double).
 *
 * @note
 * - This class does not need to store any state and is therefore designed to be non-instantiable.
 * - Users can only interact with it through its static method.
 * - Since this class does not have member variables or require dynamic behavior,
 *   the Orthodox Canonical Form is not applicable.
 */

# include <string>
# include <typeinfo>
# include <limits>
# include <cmath>
# include <iostream>
# include "../lib/color.hpp"

class	ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
		static void convert(const std::string &str);
};

template <typename Target>
void cast_print(const double value) {
	std::string	type, p0, p1;

	if (*typeid(Target).name() == 'i') {type = "int   : "; p0 = ""; p1 = "";}
	else if (*typeid(Target).name() == 'f') {type = "float : "; p0 = ".0f"; p1 = "f";}
	else if (*typeid(Target).name() == 'd') {type = "double: "; p0 = ".0"; p1 = "";}

	Target	nb = static_cast<Target>(value);
	if (-std::numeric_limits<Target>::max() <= nb
		&& nb <= std::numeric_limits<Target>::max()) {
		double	integerPart;
		double	fractionalPart = std::modf(nb, &integerPart);

		std::string	str = (fractionalPart == 0 && nb <= 999999 ? p0 : p1);
		std::cout << BOLD D_BLU << type << RST H_GRN << nb << str << RST ENDL;
	}
	// The condition nb != nb will be true only if nb is NaN,
	// because NaN is the only value that is not equal to itself.
	else if (nb != nb || nb == INFINITY || nb == -INFINITY)
		std::cout << BOLD D_BLU << type << RST H_GRN << nb << p1 << RST ENDL;
	else
		std::cout << BOLD D_BLU << type << RST L_RED "Impossible" RST ENDL;
}

#endif
