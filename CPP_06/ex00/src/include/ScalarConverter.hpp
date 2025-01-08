/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:31:20 by tforster          #+#    #+#             */
/*   Updated: 2024/12/19 16:12:47 by tforster         ###   ########.fr       */
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
# include <exception>

class	ScalarConverter {
	public:
		static void convert(const std::string &str);

	class	ConverterException: public std::exception {
		private:
			std::string	_exceptionStr;

		public:
			ConverterException(const std::string &exceptionStr);
			~ConverterException(void) throw();

			const char *what(void) const throw();
	};
};

#endif
