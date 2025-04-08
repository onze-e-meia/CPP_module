/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:25:31 by tforster          #+#    #+#             */
/*   Updated: 2025/04/08 15:25:52 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "include/typedef.hpp"
#include "lib/print_array.hpp"

const sz_t	CNT_SIZE = 30;

std::string strip_ansi(const std::string &str) {
	const sz_t	len = str.length();
	std::ostringstream	output;

	for (size_t i = 0; i < len; ++i) {
		if (str[i] == '\033') {
			while (i < len && str[i] != 'm')
				i++;
			if (i < len && str[i] == 'm')
				continue ;
		}
		output << str[i];
	}
	return (output.str());
}
