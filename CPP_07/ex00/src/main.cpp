/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:18:12 by tforster          #+#    #+#             */
/*   Updated: 2025/01/15 15:57:27 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iostream>
#include "include/whatever.hpp"
#include "lib/color.hpp"

#define TEST_OUT(test, type) std::cout << ENDL COP << test << " " BOLD << type << RENDL;
#define SWAP_OUT(name0, x0, name1, x1) 	std::cout \
	<< D_BLU << name0 << ": " RST << x0 << ORG TAB << &x0 << ENDL \
	<< D_BLU << name1 << ": " RST << x1 << ORG TAB << &x1 << ENDL;
#define MIN_MAX(test, rslt) std::cout << D_BLU << test << ": " RST << rslt << ENDL;


int	main(void) {
	std::system("clear");

	TEST_OUT("Test with type", "int");
	int	i0 = 11;
	int	i1 = 42;
	SWAP_OUT("i0", i0, "i1", i1);
	swap(i0, i1);
	SWAP_OUT("i0", i0, "i1", i1);
	MIN_MAX("min", min(i0, i1));
	MIN_MAX("max", max(i0, i1));

	TEST_OUT("Test with type", "float");
	float	f0 = 0.019f;
	float	f1 = 42.42f;
	SWAP_OUT("f0", f0, "f1", f1);
	swap(f0, f1);
	SWAP_OUT("f0", f0, "f1", f1);
	MIN_MAX("min", min(f0, f1));
	MIN_MAX("max", max(f0, f1));

	TEST_OUT("Test with type", "std::string");
	std::string	s0 = "String";
	std::string	s1 = "Start_";
	SWAP_OUT("s0", s0, "s1", s1);
	swap(s0, s1);
	SWAP_OUT("s0", s0, "s1", s1);
	MIN_MAX("min", min(s0, s1));
	MIN_MAX("max", max(s0, s1));

	return (EXIT_SUCCESS);
}
