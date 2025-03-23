/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:16:48 by tforster          #+#    #+#             */
/*   up_orderd: 2025/03/11 15:18:45 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <cmath>
#include "lib/color.hpp"

// void	merge(std::vector<int> &vec);
void	merge(int *input);
// void	printMerge(std::size_t level, std::vector<int> &vec, bool before, bool merge);
void	printMerge(std::size_t level, int *vec, bool before, bool merge);

struct ctrl {
	std::size_t _level;
	std::size_t _vecSize;
	std::size_t _order;
	std::size_t _pairStart;
	std::size_t _pairSize;
	std::size_t _nb_pairs;
	std::size_t _nbElements_completePs;
	std::size_t _leftOverElements;
	std::size_t _nbElements_noLeftOver;

	// void up_order(std::size_t level, const std::vector<int> &vec) {
	void up_order(std::size_t level) {
		_level = level;
		// _vecSize = vec.size();
		_order = 1ull << level;
		_pairStart = _order - 1;
		_pairSize = 2 * _order;
		_nb_pairs = _vecSize / _pairSize;
		_nbElements_completePs = _nb_pairs * _pairSize;
		_leftOverElements = (_vecSize - _nbElements_completePs) % _order;
		_nbElements_noLeftOver = _vecSize - _leftOverElements;
	}

	// void down_order(std::size_t level, const std::vector<int> &vec) {
	void down_order(std::size_t level) {
		_level = level;
		// _vecSize = vec.size();
		_order >>= 1;
		_pairStart = _order - 1;
		_pairSize = 2 * _order;
		_nb_pairs = _vecSize / _pairSize;
		_nbElements_completePs = _nb_pairs * _pairSize;
		_leftOverElements = (_vecSize - _nbElements_completePs) % _order;
		_nbElements_noLeftOver = _vecSize - _leftOverElements;
	}
};

void	print_status(ctrl *c) {
	std::cout
		<< " ORDER: " << c->_order << " PAIR_START: " << c->_pairStart << ENDL
		<< " PAIR_SIZE: " << c->_pairSize << " NB_OF_PAIRS: " << c->_nb_pairs << ENDL
		<< " NB_ELEMENTS_OF_COMPLETE_PAIRS: " << c->_nbElements_completePs << ENDL
		<< " LEFTOVER_ELEMENTS: " << c->_leftOverElements % c->_order << ENDL
		<< " NB_ELEMENTS_WITH_NO LEFTOVER :" << c->_nbElements_noLeftOver << ENDL;
}


int	main(int argc, char ** argv) {
	std::system("clear");
	(void)argc;
	(void)argv;
	std::cout << "Number of arg: " << argc - 1 << ENDL;

	// int	input[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	// // int	input[] = {17, 2, 11, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	// // int	input[] = {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	// std::size_t			size = 22;
	// std::vector<int>	vector(22);

	int input[] = {25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	std::size_t			size = 26;
	std::vector<int>	vector(26);

	std::cout << "CAPACITY " << vector.capacity() << ENDL;
	std::cout << "SIZE " << vector.size() << ENDL;
	std::cout << "MAX_SIZE " << vector.max_size() << ENDL;
	for (std::size_t i = 0; i < size; ++i) {std::cout << vector[i] << " | ";}
	std::cout << ENDL;

	for (std::size_t i = 0; i < size; ++i) {vector[i] = input[i];}

	std::cout << "ORIGINAL: " ENDL;
	for (std::size_t i = 0; i < size; ++i) {std::cout << vector[i] << " | ";}
	std::cout << ENDL << ENDL;

	// merge(vector);
	merge(input);
	std::cout << ENDL;

	return (EXIT_SUCCESS);
}

// void	merge(std::vector<int> &vec00) {
void	merge(int *input) {
	// std::vector<int>	*main = &vec00;
	// std::vector<int>	*pend = NULL;
	// std::vector<int>	*tempVec = NULL;

	int	*main = input;
	int	tempHolder[26];
	int	*pend = tempHolder;

	for (int i = 0; i < 26; ++i)
		tempHolder[i] = -1;

	ctrl	c;
	c._vecSize = 26;

	// c.up_order(0, *main);
	c.up_order(0);

	while (c._nb_pairs > 0) {
		print_status(&c);
		// printMerge(c._level, *main, true, true);
		printMerge(c._level, main, true, true);

		// for (std::size_t i = c._pairStart, g = 0 ; g < c._nb_pairs ; i += c._pairSize, ++g) {
		// 	if ((*main)[i] > (*main)[i + c._order]) {
		// 		// std::cout << "TRUE: " << vec[i] << " | " << vec[i + order] << ENDL;
		// 		for (std::size_t j = i - (c._pairStart), k = 0; k < c._order; j++, k++) {
		// 			// std::cout << "IN FOR\n";
		// 			int	temp = (*main)[j];
		// 			(*main)[j] = (*main)[j + c._order];
		// 			(*main)[j + c._order] = temp;
		// 		}
		// 	}
		// }

		for (std::size_t i = c._pairStart, g = 0 ; g < c._nb_pairs ; i += c._pairSize, ++g) {
			if (main[i] > main[i + c._order]) {
				// std::cout << "TRUE: " << vec[i] << " | " << vec[i + order] << ENDL;
				for (std::size_t j = i - (c._pairStart), k = 0; k < c._order; j++, k++) {
					// std::cout << "IN FOR\n";
					int	temp = main[j];
					main[j] = main[j + c._order];
					main[j + c._order] = temp;
				}
			}
		}

		// printMerge(c._level, *main, false, true);
		// c.up_order(++c._level, *main);
		printMerge(c._level, main, false, true);
		c.up_order(++c._level);

	}

	std::cout << BOLD COP ">>> START OF ISERTION <<<" << RENDL;

	// std::vector<int>	vec01(c._vecSize);
	// pend = &vec01;
	int	*tempArray = NULL;
	// pend = vec01;


	// c.down_order(--c._level, *main);
	c.down_order(--c._level);
	print_status(&c);

	// printMerge(c._level, *main, true, false);
	printMerge(c._level, main, true, false);


	if (c._nbElements_noLeftOver > c._nbElements_completePs) {
		// for (std::size_t i = 1; i <= 2 * c._nb_pairs + 1; ++i) {
		// 	std::cout
		// 		<< " START COPY: " << (i - 1) * c._order << " AT: " << pend + (i * c._order) << ENDL
		// 		<< " MAIN: " << i * c._pairStart << ENDL
		// 		<< " CHECK: " << 2 * c._nb_pairs + 1 << ENDL
		// 		<< " PEND: " << (2 * c._nb_pairs + 1) * c._pairStart << ENDL;
		// 	if ((*main)[i * c._pairStart] > (*main)[(2 * c._nb_pairs + 1) * c._pairStart]) {
		// 		std::cout << BOLD "IS TRUE" << RENDL;
		// 		std::memcpy(pend + (i * c._order), main + (2 * c._nb_pairs + 1), c._order);
		// 		break ;
		// 	}
		// }

		for (std::size_t i = 1; i <= 2 * c._nb_pairs + 1; ++i) {
			std::size_t	dest_index = (i - 1) * c._order;
			std::size_t	src_index = (2 * c._nb_pairs) * c._order;
			std::size_t	aValue = i * c._pairStart;
			std::size_t	bValue = (2 * c._nb_pairs + 1) * c._order - 1;

			std::cout
				<< " DEST INDEX: " << dest_index << " AT: " << *(main + (dest_index)) << ENDL
				<< " A_VALUE: " << aValue << ENDL
				<< " CHECK: " << 2 * c._nb_pairs + 1 << ENDL
				<< " SRC INDEX: " << src_index
				<< " AT: " << *(main + src_index) << ENDL;


			if (main[aValue] > main[bValue]) {
				std::cout << BOLD "IS TRUE: " << main[aValue] << " | " << main[bValue] << RENDL;
				std::memcpy(pend + dest_index, main + src_index, c._order * sizeof(int));

				src_index = dest_index;
				std::size_t	n = c._nbElements_noLeftOver - (i * c._order);
				++i;
				dest_index = (i - 1) * c._order;

				std::cout << c._nbElements_noLeftOver << " | " << i <<" REST: " << n << ENDL;

				std::memcpy(pend + dest_index, main + src_index, n * sizeof(int));
				n = c._vecSize - c._nbElements_noLeftOver;
				std::memcpy(pend + c._nbElements_noLeftOver, main + c._nbElements_noLeftOver, n * sizeof(int));


				break ;
			}
		}

		// printMerge(c._level, (*main), false, false);
		// printMerge(c._level, (*pend), false, false);
		printMerge(c._level, pend, false, false);

		// for (std::size_t i = 0, left = 0; i < c._vecSize; ++i) {
		// 	if (i < c._pairSize && left < c._order && ((*main)[i] > (*main)[c._pairSize + left])) {
		// 		// std::cout << i << " TRUE\n";
		// 		(*pend)[i] = (*main)[c._pairSize + left];
		// 		++left;
		// 	}
		// 	else if(i < c._pairSize + left)
		// 		(*pend)[i] = (*main)[i - left];
		// 	else
		// 		(*pend)[i] = (*main)[i];;
		// }

		tempArray = main;
		main = pend;
		pend = tempArray;
	}
	printMerge(c._level, main, false, false);

	// printMerge(c._level, (*main), false, false);
	// printMerge(c._level, main, false, false);

	// c.down_order(--c._level, *main);
	// printMerge(c._level, (*main), true, false);
	c.down_order(--c._level);
	printMerge(c._level, main, true, false);
};

// void	printMerge(std::size_t level, std::vector<int> &vec, bool before, bool merge) {
void	printMerge(std::size_t level, int *vec, bool before, bool merge) {
	// std::size_t vecSize = vec.size();
	std::size_t vecSize = 26;
	std::size_t order = 1ull << level;
	std::size_t	pairStart = order - 1;
	std::size_t	pairSize = 2 * order;
	std::size_t	nb_pairs = vecSize / pairSize;

	std::size_t	nbElements_completePs = nb_pairs * pairSize;
	std::size_t	leftOverElements = (vecSize - nbElements_completePs) % order;
	std::size_t	nbElements_noLeftOver = vecSize - leftOverElements;

	std::size_t	pos = 0;
	bool		backGround = true;
	if (before) {
		if (merge)
			std::cout << BOLD COP "Merge iteration level: " << level << ENDL
				<< "BEFORE: " RST;
		else
			std::cout << BOLD COP "Insertion sort iteration level: " << level << ENDL
				<< "BEFORE: " RST;
	} else
		std::cout << BOLD COP "AFTER:  " RST;

	for (std::size_t i = 0, groupNb = 0; i <  vecSize; ++i) {
		if (i < nbElements_noLeftOver) {
			if (groupNb >= nb_pairs)
				std::cout << U_LINE O_LINE;

			if (backGround)
				std::cout << BG_GS_0;
			else if (i < nbElements_noLeftOver)
				std::cout << BG_GS_15;

			if (i <= pairStart) {
				std::cout << YLW;
				if (i == pairStart)
					std::cout << H_YLW BOLD ITALIC;
			} else if (i >= pairStart + 1) {
				std::cout << D_BLU;
				if (i == pairStart + order){
					std::cout << V_BLU BOLD ITALIC;
					pairStart += pairSize;
				}
			}
		} else
			std::cout << REVERSE BOLD;

		std::cout << " " << vec[i] << " ";
		if (++pos == pairSize) {
			backGround = !backGround;
			pos = 0;
			++groupNb;
		}
		std::cout << RST;
	}
	std::cout << RENDL;
}
