/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:19:09 by tforster          #+#    #+#             */
/*   Updated: 2025/01/08 13:24:54 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	for (int i = 1; i < argc; i++) {
		std::string	str(argv[i]);
		std::size_t	len = str.length();
		for (std::size_t j = 0; j < len; j++) {
			str.at(j) = static_cast<char>(toupper(str.at(j)));
		}
		std::cout << str;
	}

	std::cout << '\n';
	return (EXIT_SUCCESS);
}
