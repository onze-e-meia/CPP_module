/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:17:57 by tforster          #+#    #+#             */
/*   Updated: 2025/01/11 20:42:37 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <ostream>
#include <string>

class Data {
	private:
		int			_someInt;
		float		_someFloat;
		std::string	_someText;

	public:
		Data(void);
		Data(int someInt, float someFloat, const std::string &someText);
		Data(const Data &other);
		Data &operator=(const Data &other);
		~Data(void);

		void		setInt(int someInt);
		void		setFloat(float someFloat);
		void		setText(std::string someText);

		int			getInt(void) const;
		float		getFloat(void) const;
		std::string	getText(void) const;
};

std::ostream &operator<<(std::ostream &os, const Data &src);

#endif
