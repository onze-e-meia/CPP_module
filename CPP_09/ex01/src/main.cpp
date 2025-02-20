/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:16:48 by tforster          #+#    #+#             */
/*   Updated: 2025/02/20 18:41:26 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "include/RPN.hpp"
#include "lib/color.hpp"

#define PRINT_TEST(test)	std::cout << ENDL COP << test << RENDL

int	main(int argc, char ** argv) {
	// std::system("clear");

	if (argc != 2) {
		std::cerr << D_BLU "RPN: " RST "number of argumnets must be equal to 1, "
			 << argc - 1 << " were passed." ENDL ;
			return (EXIT_FAILURE);
	}
	RPN	rpn(argv[1]);
	float	nb = rpn.solver();
	nb  = 1;
	return (EXIT_SUCCESS);

}
