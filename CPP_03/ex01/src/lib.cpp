/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:07:23 by tforster          #+#    #+#             */
/*   Updated: 2024/11/19 18:12:43 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/lib.hpp"

bool	str_all_space(const std::string &str) {
	const std::size_t	len = str.length();

	if (str.empty())
		return (true);
	for (std::size_t i = 0; i < len; ++i)
		if (!std::isspace((str.at(i))))
			return (false);
	return (true);
}
