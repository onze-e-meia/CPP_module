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

	void up_order(std::size_t level) {
		_level = level;
		// _vecSize = vec.size();
		_order = 1ull << level;
		_pairStart = _order - 1;
		_pairSize = 2 * _order;
		_nb_pairs = _vecSize / _pairSize;
		_nb_unpaired = _vecSize % _pairSize;;
		_nbElements_completePs = _nb_pairs * _pairSize;
		_leftOverElements = (_vecSize - _nbElements_completePs) % _order;
		_nbElements_noLeftOver = _vecSize - _leftOverElements;
	}

	void down_order(std::size_t level) {
		_level = level;
		// _vecSize = vec.size();
		_order >>= 1;
		_pairStart = _order - 1;
		_pairSize = 2 * _order;
		_nb_pairs = _vecSize / _pairSize;
		_nb_unpaired = _vecSize % _pairSize;
		_nbElements_completePs = _nb_pairs * _pairSize;
		_leftOverElements = (_vecSize - _nbElements_completePs) % _order;
		// _leftOverElements =  std::abs(static_cast<int>(_order) - static_cast<int>(_nb_unpaired));
		_nbElements_noLeftOver = _vecSize - _leftOverElements;
	}
};

void	merge(int *input);
void	printMerge(std::size_t level, int *vec, bool before, bool merge);
void	isertion(ctrl c, int **main, int **pend);

void	print_status(ctrl *c) {
	std::cout
		<< " ORDER: " << c->_order << " PAIR_START: " << c->_pairStart << ENDL
		<< " PAIR_SIZE: " << c->_pairSize << " NB_OF_PAIRS: " << c->_nb_pairs << ENDL
		<< " NB_ELEMENTS_OF_COMPLETE_PAIRS: " << c->_nbElements_completePs << ENDL
		<< " NB_UNPAIRED_ELEMENTS: " << c->_nb_unpaired << ENDL
		<< " LEFTOVER_ELEMENTS: " << c->_leftOverElements % c->_order << ENDL
		<< " NB_ELEMENTS_WITH_NO LEFTOVER :" << c->_nbElements_noLeftOver << ENDL;
}

// int	main(int argc, char **argv) {
int	main(void) {
	std::system("clear");
	// (void)argc;
	// (void)argv;
	// std::cout << "Number of arg: " << argc - 1 << ENDL;

	// int	input[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	// // int	input[] = {17, 2, 11, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	// // int	input[] = {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	// std::size_t			size = 22;
	// std::vector<int>	vector(22);

	// int input[] = {25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	// int input[] = {26, 1, 25, 2, 24, 3, 23, 4, 22, 5, 21, 6, 20, 7, 19, 8, 18, 9, 17, 10, 16, 11, 15, 12, 14, 13};
	int input[] = {13, 1, 25, 2, 24, 3, 23, 4, 18, 5, 21, 6, 20, 7, 19, 8, 22, 9, 17, 10, 16, 11, 15, 12, 14, 26};

	std::size_t			size = 26;

	// std::vector<int>	vector(26);
	// std::cout << "CAPACITY " << vector.capacity() << ENDL;
	// std::cout << "SIZE " << vector.size() << ENDL;
	// std::cout << "MAX_SIZE " << vector.max_size() << ENDL;
	// for (std::size_t i = 0; i < size; ++i) {std::cout << vector[i] << " | ";}
	// std::cout << ENDL;

	// for (std::size_t i = 0; i < size; ++i) {vector[i] = input[i];}

	std::cout << "ORIGINAL: " ENDL;
	// for (std::size_t i = 0; i < size; ++i) {std::cout << vector[i] << " | ";}
	std::cout << ENDL << ENDL;

	merge(input);
	std::cout << ENDL;

	return (EXIT_SUCCESS);
}

void	merge(int *input) {

	int	*main = input;
	int	tempHolder[26];
	int	*pend = tempHolder;

	for (int i = 0; i < 26; ++i)
		tempHolder[i] = -1;

	ctrl	c;
	c._vecSize = 26;

	c.up_order(0);

	while (c._nb_pairs > 0) {
		print_status(&c);
		printMerge(c._level, main, true, true);

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
		printMerge(c._level, main, false, true);
		c.up_order(++c._level);
	}

	std::cout << BOLD COP ENDL ">>> START OF ISERTION <<<" << RENDL;
	c.down_order(--c._level);
	print_status(&c);
	printMerge(c._level, main, true, false);
	isertion(c, &main, &pend);

	c.down_order(--c._level);
	print_status(&c);
	printMerge(c._level, main, true, false);
	isertion(c, &main, &pend);

	c.down_order(--c._level);
	print_status(&c);
	printMerge(c._level, main, true, false);
	isertion(c, &main, &pend);

	c.down_order(--c._level);
	print_status(&c);
	printMerge(c._level, main, true, false);
	isertion(c, &main, &pend);

};

void	del_main(int *temp, std::size_t vecSize) {
	for (std::size_t i = 0; i < vecSize; ++i)
		temp[i] = -1;
}

void	isertion(ctrl c, int **m, int **p) {

	int	*temp = *m;
	int	*main = *p;
	del_main(main, c._vecSize);

	std::memcpy(main, temp, c._pairSize * sizeof(int));
	std::size_t	bi = 1;
	std::size_t	ai = 1;
	std::size_t	copied = c._pairSize;
	if (c._nb_pairs > 1) {
		std::memcpy(main + c._pairSize, temp + 3 * c._order, c._order * sizeof(int));
		copied += c._order;
		++ai;
	}

	printMerge(c._level, main, false, false);
	std::size_t ele_move = c._nb_pairs + (c._nb_unpaired - c._leftOverElements != 0 ? 1 : 0) - 1;

	// for (std::size_t j = 0; j < c._nb_pairs && bi <= c._nb_pairs; ++j) {
	for (std::size_t j = 0; j < ele_move; ++j) {
		std::cout << BOLD << ele_move << " >>> STRAT <<< Bi: "<< bi << " | " << " J: " << j << RENDL;
	// while (bi <= c._nb_pairs) {
		// for (std::size_t i = c._pairStart, p = 0; p < 2 * c._nb_pairs;  i += c._order, ++p) {
		// std::size_t	p = 0;
		for (std::size_t i = c._pairStart, p = 0; p < ai + bi;  i += c._order, ++p) {
			if (main[i] > temp[c._pairStart + 2 * bi  * c._order]) {
				std::cout
					<< p << " COMPARE: " << main[i] << " | "
					<< "WITH " << temp[c._pairStart + 2 * bi  * c._order] << " | "
					<< " PAIR_SIZE: " << 2 * c._order << ENDL;
				// if (p < 2 * c._nb_pairs) {
				if (p < ai + bi) {
					std::size_t	to_move = copied - p * c._order;
					memcpy(main + ((p + 1) * c._order), main + (p * c._order), to_move * sizeof(int));
					std::cout << "TRUE NEED TO MOVE!\n";
					printMerge(c._level, main, false, false);
				}
				memcpy(main + (p * c._order), temp + 2 * bi * c._order, c._order * sizeof(int));
				copied += c._order;
				++bi;
				std::cout << "INSERTION!\n";
				printMerge(c._level, main, false, false);


				if (bi >= ai && bi < c._nb_pairs) {
					std::cout << "IS TRUE FOR REMANING AS!\n";
					memcpy(main + copied, temp + ((2 * ai + 1) * c._order), c._order * sizeof(int));
					copied += c._order;
					++ai;
				}
				printMerge(c._level, main, false, false);
				break ;
			}
			else if (main[i] < temp[c._pairStart + 2 * bi  * c._order] && p + 1== ai + bi){
				std::cout << copied << ">>>> TRUE P: " << p << " ai: " << ai << " bi: " << bi << ENDL;
				// memcpy(main + (p * c._order), temp + 2 * bi * c._order, c._order * sizeof(int));
				memcpy(main + copied, temp + copied, c._order * sizeof(int));

				copied += c._order;
				++bi;
				// printMerge(c._level, main, false, false);

				break;
			}
		}

		// std::cout << " P: " << p << " ai: " << ai << " bi: " << bi << " " << ((p + 1) == (ai + bi)) << ENDL;
		// if (p == ai + bi) {
		// 	std::cout << copied << ">>>> TRUE P: " << p << " ai: " << ai << " bi: " << bi << ENDL;
		// 	memcpy(main + (p * c._order), temp + 2 * bi * c._order, c._order * sizeof(int));
		// 	memcpy(main + copied, temp + copied, c._order * sizeof(int));

		// 	copied += c._order;
		// 	++bi;
		// 	printMerge(c._level, main, false, false);

		// 	break;
		// }
	}

	// FIX THSI ONE LIKE THE ONE ABOVE
	// if (c._nbElements_noLeftOver > c._nbElements_completePs) {
	// 	// std::cout << "TRUE\n";
	// 	for (std::size_t i = c._pairStart, p = 0; p < 2 * c._nb_pairs;  i += c._order, ++p) {
	// 		if (main[i] > temp[c._pairStart + 2 * c._order]) {
	// 			if (p < 2 * c._nb_pairs) {
	// 				std::size_t	to_move = copied - p * c._order;
	// 				memcpy(main + ((p + 1) * c._order), main + (p * c._order), to_move * sizeof(int));
	// 			}
	// 			memcpy(main + (p * c._order), temp + (2 * c._order), c._order * sizeof(int));
	// 			copied += c._order;
	// 		}
	// 	}
	// }

	if (c._leftOverElements) {
		std::cout << "LEFT: " << c._leftOverElements << " COPIED: " << copied << ENDL;
		memcpy(main + copied, temp + copied, c._leftOverElements * sizeof(int));
	}


	// if (c._nbElements_noLeftOver == c._nbElements_completePs) {
	// 	std::cout << BOLD COP " >>>>> BUILD temp" RENDL;

	// 	std::memcpy(main, temp, c._pairSize);
	// 	std::memcpy(main + 8, temp + 12, c._order * sizeof(int));
	// 	// size_t i = 2 + 1;
	// 	// std::memcpy(main + c._pairSize, temp + i * c._order, c._order * sizeof(int));
	// 	for (std::size_t i = 1; i < c._nb_pairs; ++i) {
	// 		std::cout << i << " | " << i + 1 << " | " << 2 * i + 1<< ENDL;
	// 		std::memcpy(main + (i + 1) * c._order, temp + (2 * i + 1) * c._order, c._order * sizeof(int));
	// 	}

	// 	// std::cout << BOLD COP " >>>>> BUILD main" RENDL;

	// 	// for (std::size_t i = 1; i < c._nb_pairs; ++i) {
	// 	// 	std::memcpy(main + c._order, temp + (2 + i) * c._order, c._order * sizeof(int));
	// 	// }
	// }

	// if (c._nbElements_noLeftOver > c._nbElements_completePs) {
	// 	for (std::size_t i = 1; i <= 2 * c._nb_pairs + 1; ++i) {
	// 		std::size_t	dest_index = (i - 1) * c._order;
	// 		std::size_t	src_index = (2 * c._nb_pairs) * c._order;
	// 		std::size_t	aValue = i * c._order - 1;
	// 		std::size_t	bValue = (2 * c._nb_pairs + 1) * c._order - 1;

	// 		std::cout
	// 			<< " DEST INDEX: " << dest_index << " AT: " << *(temp + (dest_index)) << ENDL
	// 			<< " A_VALUE INEX: " << aValue << " VALUE: " << temp[aValue] << ENDL
	// 			<< " CHECK: " << 2 * c._nb_pairs + 1 << ENDL
	// 			<< " SRC INDEX: " << src_index
	// 			<< " AT: " << *(temp + src_index) << DENDL;

	// 		if (temp[aValue] > temp[bValue]) {
	// 			std::cout << BOLD "IS TRUE: " << temp[aValue] << " | " << temp[bValue] << RENDL;
	// 			std::memcpy(main + dest_index, temp + src_index, c._order * sizeof(int));

	// 			src_index = dest_index;
	// 			std::size_t	n = c._nbElements_noLeftOver - (i * c._order);
	// 			++i;
	// 			dest_index = (i - 1) * c._order;

	// 			// std::cout << c._nbElements_noLeftOver << " | " << i <<" REST: " << n << ENDL;

	// 			std::memcpy(main + dest_index, temp + src_index, n * sizeof(int));
	// 			n = c._vecSize - c._nbElements_noLeftOver;
	// 			std::memcpy(main + c._nbElements_noLeftOver, temp + c._nbElements_noLeftOver, n * sizeof(int));
	// 			break ;
	// 		}
	// 		else
	// 			std::memcpy(main + dest_index, temp + dest_index, c._order * sizeof(int));
	// 	}
	// }

	int	*tempArray = *m;
	*m = *p;
	*p = tempArray;

	// tempArray = temp;
	// temp = main;
	// main = tempArray;

	// m = &main;
	// p = &temp;

	printMerge(c._level, main, false, false);
}

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
