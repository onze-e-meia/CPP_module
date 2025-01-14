/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:00:05 by tforster          #+#    #+#             */
/*   Updated: 2025/01/14 16:46:47 by tforster         ###   ########.fr       */
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

	std::cout <<  BOLD COP "Test with Base Class:" RENDL;
	Base	base;
	identify(base);

	std::cout << ENDL BOLD COP "Test with null pointer:" RENDL;
	Base	*null_prt = NULL;
	identify(null_prt);

	std::cout <<  BOLD COP "Test with Base Class Pointer:" RENDL;
	Base	*base_ptr = new Base();
	identify(base_ptr);
	delete base_ptr;

	std::cout <<  BOLD COP "Test with Base Class Reference:" RENDL;
	Base	&base_ref = *(new Base());
	identify(base_ref);
	delete &base_ref;

	std::cout << DENDL BOLD COP "Test with 9 random derived Base Class Pointers:" RENDL;
	for (std::size_t i = 0; i < 9; i++) {
		Base *ptr = generate();
		std::cout << D_BLU "TEST "<< i + 1 << ": " RST;
		identify(ptr);
		std::cout << ENDL;
		delete ptr;
	}

	// std::cout << ENDL BOLD COP "Test with null Reference:" ENDL
	// 	"(dereferencing a nullptr, will segfault)" RENDL;
	// Base	&null_ref = *null_prt;
	// identify(null_ref);

	std::cout << ENDL BOLD COP "Test with 9 random derived Base Class References:" RENDL;
	for (std::size_t i = 0; i < 9; i++) {
		Base &ref = *generate();
		std::cout << D_BLU "TEST "<< i + 1 << ": " RST;
		identify(ref);
		std::cout << ENDL;
		delete &ref;
	}

	return (EXIT_SUCCESS);
}
