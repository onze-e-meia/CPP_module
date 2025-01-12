/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:00:05 by tforster          #+#    #+#             */
/*   Updated: 2025/01/12 19:15:36 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "include/Base.hpp"
#include "lib/color.hpp"

int	main(void) {
	system("clear");
	std::srand(static_cast<unsigned int>(std::time(0)));

	for (std::size_t i = 0; i < 9; i++) {
		Base *base = generate();
		std::cout << "TEST "<< i << ": ";
		identify(base);
		std::cout << ENDL;
	}

	return (EXIT_SUCCESS);
}
