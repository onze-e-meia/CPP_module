

#include <cstddef>
#include <cstring>
#include <iostream>
#include <ctime>
// #include "lib/jacobsthal_diff.hpp"
#include "include/MemoryChunk.hpp"
#include "lib/color.hpp"

#include <vector>

#define CLOCKS_PER_MS	1000

// static void			startSort(Ctrl &var, int **input, int **swap);
// static void			merge(Ctrl &var, int **input, int **swap);
// static void			insertion(Ctrl &c, int **input, int **swap);
// static std::size_t	movesLeft_to_do(std::size_t totalMoves, std::size_t move, std::size_t jacob_diff);

void	array_Ford_Johnson(std::size_t vecSize, const std::vector<int> &parsedInput) {
	Ctrl	var(0, vecSize);
	// int		*input = new int[vecSize];
	// int		*swap = new int[vecSize];

	// std::vector<int>	input(vecSize), swap(vecSize);

	std::cout << GRN "Create class:" RENDL;
	MemoryChunk<int*>				int_ptr0;
	MemoryChunk<std::vector<int> >	vec0;
	MemoryChunk<int*>				int_ptr(vecSize, parsedInput);
	// MemoryChunk<std::vector<int> >	vec(vecSize, parsedInput);
	// MemoryChunk<std::list<int> >	list(vecSize);
	// MemoryChunk<std::deque<int> >	deque(vecSize);

	// for (std::size_t i = 0; i < vecSize; ++i)
	// 	input[i] = parsedInput[i];

	std::cout << RED "PIRNT MemoryChunk INPUT:"  RENDL;
	for (std::size_t i = 0; i < vecSize; ++i)
		std::cout << int_ptr.getInput()[i] << ", ";
	std::cout << ENDL;

	clock_t	start = clock();
	// MemoryChunk<int*>::startSort(var, &input, &swap);
	int_ptr.MemoryChunk<int*>::startSort();
	// vec.MemoryChunk<std::vector<int> >::startSort();
	// startSort(var, &input, &swap);
	clock_t	end = clock();
	std::cout << ENDL "Time to process a range of " << var._vecSize << " elements with array: "
		<< static_cast<double>(end - start) / CLOCKS_PER_MS << "ms" << std::endl;


	int	b = 1;
	for (std::size_t i = 0; i < var._vecSize - 1; ++i) {
		// if (input[i] > input[i + 1]) {
		if (int_ptr.getInput()[i] > int_ptr.getInput()[i + 1]) {
			std::cout << ENDL RED "FALSE AT index: " << i << " | " << int_ptr.getInput()[i] << RENDL;
			b = 0;
			break ;
		}
	}
	if (b)
		std::cout << ENDL BOLD GRN ">>>>>>>>> ALL GOOD!" RENDL;

	// delete[] input;
	// delete[] swap;
}

// void	startSort(Ctrl &var, int **input, int **swap) {
// 	merge(var, input, swap);
// 	while (var._level >  0) {
// 		var.down_order();
// 		// print_status(var);
// 		if (var._vecSize <= 40)
// 			printArray(var, *input, BEFORE, INSERT);
// 		insertion(var, input, swap);
// 		if (var._vecSize <= 40)
// 			printArray(var, *input, AFTER, INSERT);
// 	}
// }

// void	merge(Ctrl &var, int **input, int **swap) {
// 	int	*main = *input;
// 	int *pend = *swap;

// 	while (var._nb_pairs > 0) {
// 		// if (var._vecSize <= 40)
// 		// 	printArray(var, main, BEFORE, MERGE);

// 		for (std::size_t i = var._pairStart, g = 0 ; g < var._nb_pairs ; i += var._pairSize, ++g) {
// 			if (main[i] > main[i + var._order]) {
// 				std::size_t j = i - (var._pairStart);
// 				std::memcpy(pend, main + j, var._order * sizeof(int));
// 				std::memcpy(main + j, main + j + var._order, var._order * sizeof(int));
// 				std::memcpy(main + j + var._order, pend, var._order * sizeof(int));
// 			}
// 		}
// 		// if (var._vecSize <= 40)
// 		// 	printArray(var, main, AFTER, MERGE);
// 		var.up_order();
// 	}
// }

// void	insertion(Ctrl &var, int **input, int **swap) {
// 	int	*pend = *input;
// 	int	*main = *swap;

// 	std::memcpy(main, pend, var._pairSize * sizeof(int));
// 	std::size_t	ai = 1, bi = 1, boundIndex = ai + bi;
// 	std::size_t	copied = var._pairSize;

// 	std::size_t odd = (var._nb_unpaired - var._leftOverElements != 0 ? 1 : 0);
// 	std::size_t total_moves = var._nb_pairs + odd - bi;

// 	for (std::size_t j = 0, move = 0; move < total_moves; ++j) {
// 		std::size_t partialMove = movesLeft_to_do(total_moves, move, jacob_diff[j]);

// 		move += partialMove;
// 		boundIndex = ai + bi;

// 		for (std::size_t i = 0; ai < var._nb_pairs && i < partialMove; ++i) {
// 			memcpy(main + copied, pend + ((2 * ai + 1) * var._order), var._order * sizeof(int));
// 			copied += var._order;
// 			++ai;
// 			++boundIndex;
// 		}

// 		for (std::size_t k = 0; k < partialMove; ++k) {
// 			std::size_t reverse_bi = bi + partialMove - 1 - k;
// 			int	value = pend[var._pairStart + 2 * reverse_bi * var._order];

// 			std::size_t binaryIndex;
// 			if (reverse_bi >  ai - 1) {
// 				if (value > main[var._order * boundIndex - 1]) {
// 					binaryIndex = boundIndex;
// 				} else {
// 					binaryIndex = binarySearch<int *>::insertPos(main, value, var._order, boundIndex - 1);
// 					++boundIndex;
// 					std::size_t	to_move = copied - binaryIndex * var._order;
// 					memmove(main + (binaryIndex + 1) * var._order, main + (binaryIndex  * var._order), to_move * sizeof(int));
// 				}
// 			} else {
// 				binaryIndex = binarySearch<int *>::insertPos(main, value, var._order, boundIndex - 1);
// 				if (binaryIndex ==  boundIndex - 1)
// 					--boundIndex;
// 				std::size_t	to_move = copied - binaryIndex * var._order;
// 				memmove(main + (binaryIndex + 1) * var._order, main + (binaryIndex  * var._order), to_move * sizeof(int));
// 			}

// 			memcpy(main + binaryIndex  * var._order, pend + 2 * reverse_bi * var._order, var._order * sizeof(int));
// 			copied += var._order;
// 		}
// 		bi += partialMove;
// 	}
// 	if (var._leftOverElements)
// 		memcpy(main + copied, pend + copied, var._leftOverElements * sizeof(int));
// 	int	*tempArray = *input;
// 	*input = *swap;
// 	*swap = tempArray;
// }

std::size_t	movesLeft_to_do(std::size_t totalMoves, std::size_t move, std::size_t jacob_diff) {
	std::size_t partialMove
		= static_cast<int>(totalMoves) - (static_cast<int>(move) + static_cast<int>(jacob_diff)) > 0
		? jacob_diff
		: totalMoves - move;
	return (partialMove);
}

// std::size_t binarySearchInsertPos(const int *main, int value, std::size_t order, std::size_t bound) {
// 	// std::size_t binarySearchInsertPos(std::vector<int> &main, int value, std::size_t order, std::size_t bound) {
// 	std::size_t	low = 0;
// 	// std::cout
// 	// 	<< ENDL BOLD RED " " << bound << RST
// 	// 	<<" VALUE: "<< value
// 	// 	<< " BOUND: " << main[order * (bound + 1) - 1]
// 	// 	<< " index: " << order *(bound + 1) - 1 << ENDL;
// 	while(low < bound) {
// 		std::size_t mid = low + (bound  - low) / 2;
// 		if(value < main[order * (mid + 1) - 1])
// 			bound = mid;
// 		else
// 			low = mid + 1;
// 	}
// 	// std::cout << " BI: " GRN << low << RST " index: " GRN <<  order * (low + 1) - 1 << RENDL;
// 	return (low);
// }
