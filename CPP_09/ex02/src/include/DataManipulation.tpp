




#include <cstring>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include "typedef.hpp"
#include "../lib/CtrlVar.hpp"
#include "../lib/color.hpp"

// ==============================
// Data Manipulation Templates
// ==============================
// These templates handle the movement and swapping of data
// within containers or dynamically allocated arrays for PmergeMe.


// -------------------------------------------------------------------------------
// Generic template for STL containers like std::vector, std::deque, std::list
// -------------------------------------------------------------------------------

template <typename Cnt>
struct	Move {
	typedef	typename Cnt::iterator	it_t;

	inline static it_t	at(Cnt &container, sz_t i) {
		it_t it = container.begin();
		std::advance(it, i);
		return (it);
	}

	// Performs an in-place swap of a chunk of data within the container.
	static void	swapPair(Ctrl &var, Cnt &main, Cnt &pend, sz_t i) {
		static	sz_t	index = 0;
		static	it_t	bi = main.begin();
		static	it_t	ai = at(main, var._order);
		(void)pend;

		if (i == var._pairStart) {
			bi = main.begin();
			ai = bi;
			std::advance(ai, var._order);
			index = 0;
		} else if (index == 0){
			bi = at(main, i - var._pairStart);
			ai = at(main, i + 1);
			index = i;
		} else {
			bi = ai;
			std::advance(bi, i - index - var._order);
			ai = bi;
			std::advance(ai, var._order);
			index = i;
		}
		std::swap_ranges(bi, ai, ai);
	}

	static void	startMain(sz_t pairSize, Cnt &main, Cnt &pend) {
		main.clear();
		main.insert(main.begin(), pend.begin(), at(pend, pairSize));
	}

	static void	insertAs(sz_t order, sz_t ai, sz_t copied, Cnt &main, Cnt &pend) {
		static	it_t	aFirst, aLast;
		(void)copied;

		if (ai == 1) {
			aFirst = at(pend, (2 * ai + 1) * order);
			aLast = aFirst;
			std::advance(aLast, order);
		} else {
			aFirst = aLast;
			std::advance(aFirst, order);
			aLast = aFirst;
			std::advance(aLast, order);
		}
		main.insert(main.end(), aFirst, aLast);
	}

	static void	insertBs(sz_t order, sz_t iBnry, sz_t rev_bi, sz_t copied, Cnt &main, Cnt &pend, sz_t displace) {
		static	it_t	bFirst, bLast;
		(void)copied;
		(void)displace;

		if (displace == 0) {
			bFirst = at(pend, 2 * rev_bi * order);
			bLast = bFirst;
			std::advance(bLast, order);
		} else {
			bLast = bFirst;
			std::advance(bLast, -order);
			bFirst = bLast;
			std::advance(bFirst, -order);
		}
		main.insert(at(main, iBnry * order), bFirst, bLast);
	}

	static void	insertLeftOver(sz_t leftOverElements, sz_t copied, Cnt &main, Cnt &pend) {
		if (leftOverElements) {
			it_t	pendStart, pendEnd;
			(void)copied;

			pendEnd = pend.end();
			pendStart = pendEnd;
			std::advance(pendStart, -leftOverElements);
			main.insert(main.end(), pendStart, pendEnd);
		}
	}

	static sz_t binarySearch(Cnt &main, int value, sz_t order, sz_t bound) {
		sz_t	low = 0, mid = 0, i = 0, j = 0;
		it_t	it = main.begin();

		while(low < bound) {
			mid = low + (bound  - low) / 2;
			i = (order * (mid + 1) - 1);
			std::advance(it, i - j);
			if(value < *it)
				bound = mid;
			else
				low = mid + 1;
			j = i;
		}
		return (low);
	}

	static void	swapInput(Cnt *input, Cnt *swap) {
		Cnt	*tempCnt = input;
		*input = *swap;
		*swap = *tempCnt;
	}

	inline static sz_t	displace(sz_t disp, sz_t k) {
		(void)disp;
		return (k);
	}

	static void	checkSort(Cnt &main, sz_t cntSize) {
		sz_t	printTo = 10;
		bool	sorted = true;
		it_t	it = main.begin();
		it_t	next = at(main, 1);

		if (cntSize < 10)
			printTo = cntSize;
		for (sz_t i = 0; i < cntSize - 1; ++i) {
			if (*it > *next) {
				std::cout << L_RED " >>> NOT Sorted!" RENDL;
				sorted = false;
				break ;
			}
			it = next;
			std::advance(next, 1);
		}
		if (sorted)
			std::cout << H_GRN ">>> Is SORTED!" RENDL;
		std::cout << COP "After: " RST;
		it = main.begin();
		for (sz_t i = 0; i < printTo; ++i) {
			std::cout << *it << " ";
			std::advance(it, 1);
		}
		if (cntSize > 10)
			std::cout << "[...]";
		std::cout << ENDL;
	}

};

// --------------------------------------------------------------
// Specialization for dynamically allocated int arrays (int*)
// --------------------------------------------------------------
template <>
struct	Move<int*> {
	typedef	int* it_t;

	inline static it_t	at(int *ptr, sz_t i) {
		return (ptr + i);
	}

	// Uses raw pointers for memory manipulation and performs an in-place swap.
	static void	swapPair(Ctrl &var, int *main, int *pend, sz_t i) {
		sz_t ai = i + 1;
		sz_t bi = i - (var._pairStart);
		std::memcpy(pend, main + bi, var._order * sizeof(int));
		std::memcpy(main + bi, main + ai, var._order * sizeof(int));
		std::memcpy(main + ai, pend, var._order * sizeof(int));
	}

	static void	startMain(sz_t pairSize, int *main, int *pend) {
		std::memcpy(main, pend, pairSize * sizeof(int));
	}

	static void	insertAs(sz_t order, sz_t ai, sz_t copied, int *main, int *pend) {
		std::memcpy(main + copied, pend + ((2 * ai + 1) * order), order * sizeof(int));
	}

	static void	insertBs(sz_t order, sz_t iBnry, sz_t rev_bi, sz_t copied, int *main, int *pend, sz_t displace) {
		if (!displace) {
			sz_t	toMove = copied - iBnry * order;
			std::memmove(main + (iBnry + 1) * order, main + (iBnry * order), toMove * sizeof(int));
		}
		std::memcpy(main + iBnry * order, pend + 2 * rev_bi * order, order * sizeof(int));
	}

	static void	insertLeftOver(sz_t leftOverElements, sz_t copied, int *main, int *pend) {
		if (leftOverElements)
			std::memcpy(main + copied, pend + copied, leftOverElements * sizeof(int));
	}

	static sz_t binarySearch(const int *main, int value, sz_t order, sz_t bound) {
		sz_t	low = 0;

		while(low < bound) {
			sz_t mid = low + (bound  - low) / 2;
			if(value < main[order * (mid + 1) - 1])
				bound = mid;
			else
				low = mid + 1;
		}
		return (low);
	}

	static void	swapInput(int **input, int **swap) {
		int	*tempArray = *input;
		*input = *swap;
		*swap = tempArray;
	}

	inline static sz_t	displace(sz_t disp, sz_t k) {
		(void)k;
		return (disp);
	}

	static void	checkSort(int *main, sz_t cntSize) {
		sz_t	printTo = 10;
		bool	sorted = true;

		if (cntSize < 10)
			printTo = cntSize;
		for (sz_t i = 0; i < cntSize - 1; ++i) {
			if (main[i] > main[i + 1]) {
				std::cout << L_RED " >>> NOT Sorted!" RENDL;
				sorted = false;
				break ;
			}
		}
		if (sorted)
			std::cout << H_GRN ">>> Is SORTED!" RENDL;
		std::cout << COP "After: " RST;
		for (sz_t i = 0; i < printTo; ++i)
			std::cout << main[i] << " ";
		if (cntSize > 10)
			std::cout << "[...]";
		std::cout << ENDL;
	}
};
