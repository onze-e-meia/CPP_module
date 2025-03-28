/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:16:48 by tforster          #+#    #+#             */
/*   up_orderd: 2025/03/11 15:18:45 by tforster         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */


#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ctime>
#include "lib/parser.hpp"
#include "lib/CtrlVar.hpp"
#include "include/MemoryChunk.hpp"
#include "lib/jacobsthal_diff.hpp"
#include "lib/color.hpp"

#define CLOCKS_PER_MS	1000

// void	merge(Ctrl &c, int **input, int **swap);
// void	isertion(Ctrl &c, int **main, int **pend);

int	main(int argc, char **argv) {
	int	status = std::system("clear");
	if (status)
		return (EXIT_FAILURE);

	std::size_t vecSize = argc - 1;
	std::vector<int>	parsedInput(vecSize, 0);
	if (argc > 2) {
		try {
			parse(argc, argv, parsedInput);
		} catch (const std::exception &er) {
			std::cerr << er.what();
			return (EXIT_FAILURE);
		}
	} else {
		std::cerr
			<< BOLD L_RED "PmergeMe usage: " RST
			<< H_GRN "./PmergeMe " H_BLU "arg_1 arg_2 arg_3 ... arg_n" RENDL
			<< " (e.g.: ./PmergeMe 90 10 50)" ENDL
			<< " (e.g.: ./PmergeMe $(shuf -i 0-99 -n 10)" << ENDL
			<< " Need at least two args" RENDL;
		return (EXIT_FAILURE);
	}

	std::cout << COP "Array Size: " GRN << vecSize << RENDL;

	Ctrl	c(0, vecSize);
	int		*input = new int[vecSize];
	int		*swap = new int[vecSize];


	for (std::size_t i = 0; i < vecSize; ++i)
		input[i] = parsedInput[i];

	// clock_t	start = clock();
	// merge(c, &input, &swap);
	array_Ford_Johnson(vecSize, parsedInput);
	// clock_t	end = clock();

	// int	b = 1;
	// for (std::size_t i = 0; i < c._vecSize - 1; ++i) {
	// 	if (input[i] > input[i + 1]) {
	// 		std::cout << ENDL RED "FALSE AT " << i << " | " << input[i] << RENDL;
	// 		b = 0;
	// 		break ;
	// 	}
	// }
	// if (b)
	// 	std::cout << ENDL BOLD GRN ">>>>>>>>> ALL GOOD!" RENDL;

	// std::cout << ENDL "Time to process a range of " << c._vecSize << " elements with array: "
	// 	<< static_cast<double>(end - start) / CLOCKS_PER_MS << "ms" << std::endl;

	delete[] input;
	delete[] swap;

	return (EXIT_SUCCESS);
}
