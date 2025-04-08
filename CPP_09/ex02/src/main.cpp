/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:16:48 by tforster          #+#    #+#             */
/*   Updated: 2025/04/08 15:25:05 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ctime>
#include "lib/parser.hpp"
#include "include/PmergeMe.hpp"
#include "lib/color.hpp"

static void	printBefore(const std::vector<int> &parsedInput, sz_t cntSize);

int	main(int argc, char **argv) {
	#ifdef ARRAY
		int	status = std::system("clear");
		if (status)
			return (EXIT_FAILURE);
	#endif

	std::size_t cntSize = argc - 1;
	std::vector<int>	parsedInput(cntSize, 0);
	if (argc > 2) {
		try {
			parse(argc, argv, parsedInput);
		} catch (const std::exception &er) {
			std::cerr << er.what();
			return (EXIT_FAILURE);
		}
	} else {
		std::cerr
			<< BOLD COP " >> PmergeMe usage: " RST
			<< "./PmergeMe " H_BLU "arg_1 arg_2 arg_3 ... arg_n" RENDL
			<< " e.g.: ./PmergeMe 90 7 10 50" ENDL
			<< " e.g.: ./PmergeMe $(shuf -i0-99 -n16)" TAB H_GRN "#non-repeating numbers." << RENDL
			<< " e.g.: ./PmergeMe $(shuf -i0-99 -n16 -r)" TAB H_GRN "#repeating numbers." << RENDL
			<< " e.g.: ./PmergeMe $(seq 15 -1 0)" TAB H_GRN "#reverse sequence numbers." << RENDL
			<< COP " Need at least two args." RENDL;
		return (EXIT_FAILURE);
	}

	printBefore(parsedInput, parsedInput.size());

	PmergeMe<int*>	intArray(parsedInput);
	intArray.PmergeMe<int*>::startSort();
	std::cout << ENDL;

	#ifdef ARRAY
		return (EXIT_SUCCESS);
	#endif

	PmergeMe<std::vector<int> >	vector(parsedInput);
	vector.PmergeMe<std::vector<int> >::startSort();
	std::cout << ENDL;

	PmergeMe<std::deque<int> >	deque(parsedInput);
	deque.PmergeMe<std::deque<int> >::startSort();
	std::cout << ENDL;

	PmergeMe<std::list<int> >	list(parsedInput);
	list.PmergeMe<std::list<int> >::startSort();
	std::cout << ENDL;

	return (EXIT_SUCCESS);
}

static void	printBefore(const std::vector<int> &parsedInput, sz_t cntSize) {
	sz_t	printTo = 10;
	if (cntSize < printTo)
		printTo = cntSize;
	std::cout << COP "Before: " RST;
	for (sz_t i = 0; i < printTo; ++i)
		std::cout << parsedInput.at(i) << " ";
	if (cntSize > 10)
		std::cout << "[...]";
	std::cout << DENDL;
}
