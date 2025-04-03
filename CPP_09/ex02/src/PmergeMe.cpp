

#include <cstddef>
#include <cstring>
#include <iostream>
#include <ctime>
// #include "lib/jacobsthal_diff.hpp"
#include "include/PmergeMe.hpp"
#include "lib/color.hpp"

#include <vector>
#include <deque>
#include <list>

#define CLOCKS_PER_MS	1000

void	array_Ford_Johnson(sz_t vecSize, const std::vector<int> &parsedInput) {
	Ctrl	var(0, vecSize);
	// int		*input = new int[vecSize];
	// int		*swap = new int[vecSize];

	// std::vector<int>	input(vecSize), swap(vecSize);

	// for (sz_t i = 0; i < vecSize; ++i)
	// 	input[i] = parsedInput[i];

	// INT_PTR
	std::cout << ENDL GRN " ___PTR_COPY___: " ENDL;
	PmergeMe<int*>				intPtr(vecSize, parsedInput);
	for (sz_t i = 0; i < vecSize; ++i)
		std::cout << intPtr.getInput()[i] << " ";
	std::cout << ENDL;

	// PmergeMe<int*> xxxx = PmergeMe<int*>(vecSize, parsedInput);
	// intPtr = intPtr;

	clock_t	start0 = clock();
	intPtr.PmergeMe<int*>::startSort();
	clock_t	end0 = clock();

	// VECTOR
	std::cout << ENDL GRN " ___VECTOR___: " ENDL;
	PmergeMe<std::vector<int> >	vector(vecSize, parsedInput);
	// for (sz_t i = 0; i < vecSize; ++i)
	// 	std::cout << vector.getInput()[i] << " ";
	// std::cout << ENDL;

	clock_t	start1 = clock();
	vector.PmergeMe<std::vector<int> >::startSort();
	clock_t	end1 = clock();

	// DEQUE
	std::cout << ENDL GRN " ___DEQUE___: " ENDL;
	PmergeMe<std::deque<int> >	deque(vecSize, parsedInput);
	// for (sz_t i = 0; i < vecSize; ++i)
	// 	std::cout << deque.getInput()[i] << " ";
	// std::cout << ENDL;

	clock_t	start2 = clock();
	deque.PmergeMe<std::deque<int> >::startSort();
	clock_t	end2 = clock();

	// LIST
	std::cout << ENDL GRN " ___LIST___ : " ENDL;
	PmergeMe<std::list<int> >	list(vecSize, parsedInput);
	std::list<int>::iterator	it = list.getInput().begin();
	// for (sz_t i = 0; i < vecSize; ++i) {
	// 	std::cout << *it << " ";
	// 	std::advance(it, 1);
	// }
	// std::cout << ENDL;

	clock_t	start3 = clock();
	list.PmergeMe<std::list<int> >::startSort();
	clock_t	end3 = clock();

	std::cout << "Time to process a range of " << var._vecSize << " elements with INT_PTR: "
		<< static_cast<double>(end0 - start0) / CLOCKS_PER_MS << "ms" ENDL;

	std::cout << "Time to process a range of " << var._vecSize << " elements with VECTOR: "
		<< static_cast<double>(end1 - start1) / CLOCKS_PER_MS << "ms" ENDL;

	std::cout << "Time to process a range of " << var._vecSize << " elements with DEQUE: "
		<< static_cast<double>(end2 - start2) / CLOCKS_PER_MS << "ms" ENDL;

	std::cout << "Time to process a range of " << var._vecSize << " elements with LIST: "
		<< static_cast<double>(end3 - start3) / CLOCKS_PER_MS << "ms" ENDL;

	int	b;
	b = 1;
	for (sz_t i = 0; i < var._vecSize - 1; ++i) {
		if (intPtr.getInput()[i] > intPtr.getInput()[i + 1]) {
			std::cout << ENDL RED "FALSE AT index: " << i << " | " << intPtr.getInput()[i] << RENDL;
			b = 0; break ; }
	}
	if (b) 	std::cout << ENDL BOLD GRN ">>>>>>>>> INT_PTR ALL GOOD!" RENDL;
	for (sz_t i = 0; i < vecSize; ++i)
		std::cout << intPtr.getInput()[i] << " ";
	std::cout << ENDL;

	b = 1;
	for (sz_t i = 0; i < var._vecSize - 1; ++i) {
		if (vector.getInput()[i] > vector.getInput()[i + 1]) {
			std::cout << ENDL RED "FALSE AT index: " << i << " | " << vector.getInput()[i] << RENDL;
			b = 0; break ; }
	}
	if (b) 	std::cout << ENDL BOLD GRN ">>>>>>>>> VECTOR ALL GOOD!" RENDL;
	for (sz_t i = 0; i < vecSize; ++i)
		std::cout << vector.getInput()[i] << " ";
	std::cout << ENDL;

	b = 1;
	for (sz_t i = 0; i < var._vecSize - 1; ++i) {
		if (deque.getInput()[i] > deque.getInput()[i + 1]) {
			std::cout << ENDL RED "FALSE AT index: " << i << " | " << deque.getInput()[i] << RENDL;
			b = 0; break ; }
	}
	if (b) std::cout << ENDL BOLD GRN ">>>>>>>>> DEQUE ALL GOOD!" RENDL;
	for (sz_t i = 0; i < vecSize; ++i)
		std::cout << deque.getInput()[i] << " ";
	std::cout << ENDL;

	b = 1;
	it = list.getInput().begin();
	std::list<int>::iterator	next = list.getInput().begin();
	std::advance(next, 1);
	for (sz_t i = 0; i < var._vecSize - 1; ++i) {
		if (*it > *next) {
			std::cout << ENDL RED "LIST FALSE AT index: " << i << " | " << *it << RENDL;
			b = 0; 	break ; }
		it = next;
		std::advance(next, 1);
	}
	if (b)
		std::cout << ENDL BOLD GRN ">>>>>>>>> LIST ALL GOOD!" RENDL;
	it = list.getInput().begin();
	for (sz_t i = 0; i < vecSize; ++i) {
		std::cout << *it << " ";
		std::advance(it, 1);
	}
	std::cout << ENDL;
}

sz_t	movesLeft_to_do(sz_t totalMoves, sz_t move, sz_t jacob_diff) {
	sz_t partialMove
		= static_cast<int>(totalMoves) - (static_cast<int>(move) + static_cast<int>(jacob_diff)) > 0
		? jacob_diff
		: totalMoves - move;
	return (partialMove);
}
