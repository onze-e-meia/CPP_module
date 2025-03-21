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

// ./your_program $(shuf -i 0-99 -n 10)


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

static const std::size_t jacobsthal_diff[] = {
	2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
	2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
	1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
	178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
	11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
	366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
	11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
	375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
	6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
	96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
	1537228672809129216u, 3074457345618258432u, 6148914691236516864u
};

struct ctrl {
	std::size_t _level;
	std::size_t _vecSize;
	std::size_t _order;
	std::size_t _pairStart;
	std::size_t _pairSize;
	std::size_t _nb_pairs;
	std::size_t	_nb_unpaired;
	std::size_t _nbElements_completePs;
	std::size_t _leftOverElements;
	std::size_t _nbElements_noLeftOver;

	ctrl(std::size_t level, std::size_t vecSize): _level(level), _vecSize(vecSize) {
		_order = 1u << level;
		init_ctrl(_order);
	}

	void	init_ctrl(std::size_t order) {
		_pairStart = order - 1;
		_pairSize = 2 * order;
		_nb_pairs = _vecSize / _pairSize;
		_nbElements_completePs = _nb_pairs * _pairSize;
		_nb_unpaired = _vecSize % _pairSize;
		_leftOverElements = _vecSize % order;
		_nbElements_noLeftOver = _vecSize - _leftOverElements;
	}

	ctrl up_order() {
		++_level;
		_order <<= 1u;
		init_ctrl(_order);
		return (*this);
	}

	ctrl down_order() {
		--_level;
		_order >>= 1u;
		init_ctrl(_order);
		return (*this);
	}
};

void	merge(int *input, ctrl *c);
void	printMerge(ctrl *c, int *vec, bool before, bool merge);
void	isertion(ctrl *c, int **main, int **pend);

void	print_status(ctrl *c) {
	std::cout << DENDL
		<< " ORDER: " << c->_order << " PAIR_START: " << c->_pairStart << ENDL
		<< " PAIR_SIZE: " << c->_pairSize << " NB_OF_PAIRS: " << c->_nb_pairs << ENDL
		<< " NB_ELEMENTS_OF_COMPLETE_PAIRS: " << c->_nbElements_completePs << ENDL
		<< " NB_UNPAIRED_ELEMENTS: " << c->_nb_unpaired << ENDL
		// << " LEFTOVER_ELEMENTS: " << c->_leftOverElements % c->_order << ENDL
		<< " LEFTOVER_ELEMENTS: " << c->_leftOverElements << ENDL
		<< " NB_ELEMENTS_WITH_NO LEFTOVER :" << c->_nbElements_noLeftOver << ENDL;
}

int	main(int argc, char **argv) {
	std::system("clear");
	std::size_t vecSize = argc - 1;

	int	*input = new int[vecSize];

	std::cout << "VEC_SIZE: " << vecSize << ENDL;

	for (std::size_t i = 0; i < vecSize; ++i)
		input[i] = static_cast<int>(std::strtol(argv[i + 1], NULL, 10));


	// std::cout << "Number of arg: " << argc - 1 << ENDL;

	// std::size_t	vecSize = 22;
	// int	input[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	// int	input[] = {17, 2, 11, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	// int	input[] = {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	// std::size_t	vecSize = 26;
	// int input[] = {25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	// int input[] = {26, 1, 25, 2, 24, 3, 23, 4, 22, 5, 21, 6, 20, 7, 19, 8, 18, 9, 17, 10, 16, 11, 15, 12, 14, 13};
	// int input[] = {13, 1, 25, 2, 24, 3, 23, 4, 18, 5, 21, 6, 20, 7, 19, 8, 22, 9, 17, 10, 16, 11, 15, 12, 14, 26};

	// std::size_t	vecSize = 30;
	// int	input[]	=
	// 	{
	// 		30, 29, 28, 27, 26, 25, 24, 23, 22, 21,
	// 		20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
	// 		10,  9,  8,  7,  6,  5,  4,  3,  2,  1
	// 	};

	// std::size_t	vecSize = 30;
	// int	input[]	=
	// 	{
	// 		30, 15, 29, 14, 28, 13, 27, 12, 26, 11,
	// 		25, 10, 24,  9, 23,  8, 22,  7, 21,  6,
	// 		20,  5, 19,  4, 18,  3, 17,  2, 16,  1,
	// 	};

	// std::size_t	vecSize = 34;
	// int	input[]	=
	// 	{	32, 31,
	// 		30, 15, 29, 14, 28, 13, 27, 12, 26, 11,
	// 		25, 10, 24,  9, 23,  8, 22,  7, 21,  6,
	// 		20,  5, 19,  4, 18,  3, 17,  2, 16,  1,
	// 		0, 50
	// 	};

	ctrl		c(0, vecSize);

	// std::vector<int>	vector(26);
	// std::cout << "CAPACITY " << vector.capacity() << ENDL;
	// std::cout << "SIZE " << vector.size() << ENDL;
	// std::cout << "MAX_SIZE " << vector.max_size() << ENDL;
	// for (std::size_t i = 0; i < size; ++i) {std::cout << vector[i] << " | ";}
	// std::cout << ENDL;

	// for (std::size_t i = 0; i < size; ++i) {vector[i] = input[i];}

	// for (std::size_t i = 0; i < size; ++i) {std::cout << vector[i] << " | ";}

	merge(input, &c);

	delete[] input;

	return (EXIT_SUCCESS);
}

void	merge(int *input, ctrl *c) {

	int	*main = input;
	int	tempHolder[c->_vecSize];
	int	*pend = tempHolder;

	for (std::size_t i = 0; i < c->_vecSize; ++i)
		tempHolder[i] = -1;

	while (c->_nb_pairs > 0) {
		// print_status(c);
		printMerge(c, main, true, true);

		for (std::size_t i = c->_pairStart, g = 0 ; g < c->_nb_pairs ; i += c->_pairSize, ++g) {
			if (main[i] > main[i + c->_order]) {
				// std::cout << "TRUE: " << vec[i] << " | " << vec[i + order] << ENDL;
				for (std::size_t j = i - (c->_pairStart), k = 0; k < c->_order; j++, k++) {
					// std::cout << "IN FOR\n";
					int	temp = main[j];
					main[j] = main[j + c->_order];
					main[j + c->_order] = temp;
				}
			}
		}
		printMerge(c, main, false, true);
		c->up_order();
	}

	std::cout << BOLD COP ENDL ">>> START OF ISERTION <<<" << RENDL;
	while (c->_level >  0)
	{
		c->down_order();
		// print_status(c);
		printMerge(c, main, true, false);
		isertion(c, &main, &pend);
	}

	for (std::size_t i = 0; i < c->_vecSize - 1; ++i) {
		if (main[i] > main[i + 1]) {
			std::cout << "FALSE AT " << i << " | " << main[i] << ENDL;
			break ;
		}
	}
};

void	del_main(int *temp, std::size_t vecSize) {
	for (std::size_t i = 0; i < vecSize; ++i)
		temp[i] = -1;
}

void	isertion(ctrl *c, int **m, int **p) {

	int	*temp = *m;
	int	*main = *p;
	del_main(main, c->_vecSize);

	std::memcpy(main, temp, c->_pairSize * sizeof(int));
	std::size_t	bi = 1;
	std::size_t	ai = 1;
	std::size_t	copied = c->_pairSize;
	// if (c->_nb_pairs > 1) {
	// 	std::memcpy(main + c->_pairSize, temp + 3 * c->_order, c->_order * sizeof(int));
	// 	copied += c->_order;
	// 	++ai;
	// }

		while (ai < c->_nb_pairs) {
			// std::cout << BOLD RED ">>> REMAINING AS" ENDL;
			memcpy(main + copied, temp + ((2 * ai + 1) * c->_order), c->_order * sizeof(int));
			copied += c->_order;
			++ai;
		}
		// printMerge(c, main, false, false);

	// printMerge(c->_level, main, false, false);
	std::size_t total_moves = c->_nb_pairs + (c->_nb_unpaired - c->_leftOverElements != 0 ? 1 : 0) - 1;


	// std::cout << BOLD " TOTAL_MOVES: " << total_moves << RENDL;
	for (std::size_t j = 0, moves = 0; moves < total_moves; ++j) {
		// moves += static_cast<int>(total_moves) - static_cast<int>(jacobsthal_diff[j]) > 0 ? jacobsthal_diff[j] : total_moves - moves;
		std::size_t partialMove = static_cast<int>(total_moves) - (static_cast<int>(moves) + static_cast<int>(jacobsthal_diff[j])) > 0 ? jacobsthal_diff[j] : total_moves - moves;
		moves += partialMove;
		// std::cout
		// 	<< BOLD " >>>>>>>>>>>> MOVES: " << moves << ENDL
		// 	<< " JACOBSTHAL_DIFF: " << jacobsthal_diff[j] << ENDL
		// 	<< " PARTIAL_MOVES: " << partialMove << RENDL;

		// std::size_t	s = bi;
		// for (std::size_t k = 0; k < jacobsthal_diff[j]; ++k) {
		for (std::size_t k = 0; k < partialMove; ++k) {
			// std::cout << BOLD " ACTUAL_MOVE: " << k << " ON B" << bi << RENDL;
			// for (std::size_t i = c->_pairStart, p = 0; p < ai + bi;  i += c->_order, ++p) {
			for (std::size_t i = c->_pairStart, p = 0; 1;  i += c->_order, ++p) {
				// std::size_t r = s + (partialMove - 1);

				if (main[i] > temp[c->_pairStart + 2 * bi * c->_order]) {
				// if (main[i] > temp[c->_pairStart + 2 * r * c->_order]) {
					// std::cout
					// 	<< " COMPARE: " << main[i] << " | "
					// 	<< " WITH " << temp[c->_pairStart + 2 * bi  * c->_order] << " | "
					// 	<< " PAIR_SIZE: " << 2 * c->_order << ENDL;
					if (p < ai + bi) {
						std::size_t	to_move = copied - p * c->_order;
						memcpy(main + ((p + 1) * c->_order), main + (p * c->_order), to_move * sizeof(int));
						// printMerge(c, main, false, false);
					}
					// std::cout << BOLD RED ">>> INSERTION" ENDL;

					memcpy(main + (p * c->_order), temp + 2 * bi * c->_order, c->_order * sizeof(int));
					// memcpy(main + (p * c->_order), temp + 2 * r * c->_order, c->_order * sizeof(int));
					copied += c->_order;
					++bi;
					// printMerge(c, main, false, false);

					// while (bi >= ai && bi < c->_nb_pairs) {
					// 	std::cout << BOLD RED ">>> REMAINING AS" ENDL;
					// 	memcpy(main + copied, temp + ((2 * ai + 1) * c->_order), c->_order * sizeof(int));
					// 	copied += c->_order;
					// 	++ai;
					// 	printMerge(c, main, false, false);
					// }
					break ;
				}
				else if (main[i] < temp[c->_pairStart + 2 * bi * c->_order] && p + 1 == ai + bi){
				// else if (main[i] < temp[c->_pairStart + 2 * r * c->_order] && p + 1 == ai + bi){
					// std::cout << BOLD RED ">>> INSERTION" ENDL;
					// memcpy(main + (p * c->_order), temp + 2 * bi * c->_order, c->_order * sizeof(int));


					memcpy(main + copied, temp + 2 * bi * c->_order, c->_order * sizeof(int));
					// memcpy(main + copied, temp + 2 * r * c->_order, c->_order * sizeof(int));
					copied += c->_order;
					++bi;

					// printMerge(c, main, false, false);
					break;
				}
			}
		}
		// std::cout << BOLD RED "BEFORE THE Assssss" RENDL;
		// while (bi > 2 && bi >= ai && bi < c->_nb_pairs) {

		// while (bi > 2 && bi >= ai) {
		// 	if (ai < c->_nb_pairs) {
		// 		// std::cout << BOLD RED ">>> REMAINING AS" ENDL;
		// 		memcpy(main + copied, temp + ((2 * ai + 1) * c->_order), c->_order * sizeof(int));
		// 		copied += c->_order;
		// 	}
		// 	++ai;
		// 	// printMerge(c, main, false, false);
		// }

	}
	if (c->_leftOverElements)
		memcpy(main + copied, temp + copied, c->_leftOverElements * sizeof(int));

	int	*tempArray = *m;
	*m = *p;
	*p = tempArray;
	// std::cout << BOLD RED ">>> FINAL: " ENDL;
	printMerge(c, main, false, false);
}

void	printMerge(ctrl *c, int *vec, bool before, bool merge) {

	std::size_t	start = c->_pairStart;
	std::size_t	pos = 0;
	bool		backGround = true;
	if (before) {
		if (merge)
			std::cout << BOLD COP " >>> Merge iteration level: " << c->_level << ENDL
				<< "BEFORE: " RST;
		else
			std::cout << BOLD COP " >>> Insertion sort iteration level: " << c->_level << ENDL
				<< "BEFORE: " RST;
	} else
		std::cout << BOLD COP "AFTER:  " RST;

	for (std::size_t i = 0, groupNb = 0; i <  c->_vecSize; ++i) {
		if (i < c->_nbElements_noLeftOver) {
			if (groupNb >= c->_nb_pairs)
				std::cout << U_LINE O_LINE;

			if (backGround)
				std::cout << BG_GS_0;
			else if (i < c->_nbElements_noLeftOver)
				std::cout << BG_GS_15;

			if (i <= start) {
				std::cout << YLW;
				if (i == start)
					std::cout << H_YLW BOLD ITALIC;
			} else if (i >= start + 1) {
				std::cout << D_BLU;
				if (i == start + c->_order){
					std::cout << V_BLU BOLD ITALIC;
					start += c->_pairSize;
				}
			}
		} else
			std::cout << REVERSE BOLD;

		std::cout << " " << vec[i] << " ";
		if (++pos == c->_pairSize) {
			backGround = !backGround;
			pos = 0;
			++groupNb;
		}
		std::cout << RST;
	}
	std::cout << RENDL;
}
