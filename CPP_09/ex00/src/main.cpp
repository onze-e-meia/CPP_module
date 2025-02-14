/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:16:48 by tforster          #+#    #+#             */
/*   Updated: 2025/02/14 18:35:59 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "include/BitcoinExchange.hpp"
#include "lib/color.hpp"


// #include <string>
// #include <cstring>
// #include <cstdlib>
#include "include/utils.hpp"

int	main(int argc, char **argv) {
	setenv("TZ", "UTC-3", 1);
	tzset();
	std::system("clear");

	std::cout << std::fixed << std::setprecision(2);

	if (argc == 2) {
		BtcXchg	db(argv[1]);
		db.xchgLog();
	} else {
		std::cerr << L_RED "Error: " RST "usage: ./btc "
			<< BOLD BLU "<" RST BOLD RED "input file" BOLD BLU ">" ENDL;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
