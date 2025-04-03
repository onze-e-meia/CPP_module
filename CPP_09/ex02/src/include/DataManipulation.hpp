


#ifndef DATAMANIPULATION_HPP
# define DATAMANIPULATION_HPP

# include <cstddef>
# include <algorithm>
# include "typedef.hpp"
# include "../lib/CtrlVar.hpp"

// ==============================
// Data Manipulation Templates
// ==============================
// These templates handle the movement and swapping of data
// within containers or dynamically allocated arrays for PmergeMe.


// -------------------------------------------------------------------------------
// Generic template for STL containers like std::vector, std::deque, std::list.
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
		sz_t ai = i + 1;
		sz_t bi = i - (var._pairStart);
		(void)pend;

		std::swap_ranges(at(main, bi), at(main, ai), at(main, ai));
	}

	static void	startMain(sz_t pairSize, Cnt &main, Cnt &pend) {
		main.clear();
		main.insert(at(main, 0), at(pend, 0), at(pend, pairSize));
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
		// main.insert(at(main, copied), at(pend, (2 * ai + 1) * order), at(pend, 2 * (ai + 1) * order));
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
		// main.insert(at(main, iBnry * order), at(pend, 2 * rev_bi * order), at(pend, (2 * rev_bi + 1) * order));
	}

	static void	insertLeftOver(sz_t leftOverElements, sz_t copied, Cnt &main, Cnt &pend) {
		if (leftOverElements) {
			it_t	pendSart, pendEnd;
			(void)copied;

			pendEnd = pend.end();
			pendSart = pendEnd;
			std::advance(pendSart, -leftOverElements);
			main.insert(main.end(), pendSart, pendEnd);
			// main.insert(at(main, copied), at(pend, copied), at(pend, copied + leftOverElements));
		}
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
};

// --------------------------------------------------------------
// Specialization for dynamically allocated int arrays (int*).
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

	static void	swapInput(int **input, int **swap) {
		int	*tempArray = *input;
		*input = *swap;
		*swap = tempArray;
	}

	inline static sz_t	displace(sz_t disp, sz_t k) {
		(void)k;
		return (disp);
	}
};

#endif
