/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:16:48 by tforster          #+#    #+#             */
/*   Updated: 2025/01/21 16:57:18 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
#include <list>

#include "include/easyfind.hpp"
#include "lib/color.hpp"

#define PRINT_TEST(test)	std::cout << ENDL COP << test << RENDL


int	main(void) {
	std::system("clear");
	int	integer = 0;

	PRINT_TEST("Test with vector");
	std::vector<int>	vec;
	fill_container_multy(vec, 5, 2);
	print_cnt(vec);
	search_print(vec, integer);

	integer = 12;
	vec.push_back(integer);
	print_cnt(vec);
	search_print(vec, integer);

	integer = 99;
	search_print(vec, integer);

	PRINT_TEST("Test with list");
	std::list<int>	list;
	fill_container_multy(list, 5, 3);
	print_cnt(list);
	search_print(list, integer);

	integer = 3;
	search_print(list, integer);

	PRINT_TEST("Test with deque");
	std::deque<int>	deque;
	fill_container_multy(deque, 5, 4);
	print_cnt(deque);
	search_print(deque, integer);

	integer = 8;
	search_print(deque, integer);
}
