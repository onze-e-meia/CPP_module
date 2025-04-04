

#include <vector>
#include <deque>
#include <list>
#include "typedef.hpp"
#include "../lib/CtrlVar.hpp"

// ==============================
// Memory Management Templates
// ==============================
// These templates handle the initialization and deallocation
// of containers or dynamically allocated arrays for PmergeMe.

// -------------------------------------------------------------------------------
// Generic template for STL containers like std::vector, std::deque, std::list
// -------------------------------------------------------------------------------
template <typename Cnt>
struct Memory {
	// Initializes a container with the given size.
	static Cnt	init(sz_t vecSize) {
		return (Cnt(vecSize, 0));
	}

	static void	populate(sz_t vecSize, const std::vector<int> &parsedInput, Cnt &input) {
		typename Cnt::iterator it = input.begin();
		for (sz_t i = 0; i < vecSize; ++i)
			*(it++) = parsedInput.at(i);
	}

	// Since these containers handle their own memory, no cleanup is needed.
	static void	clear(Ctrl var, Cnt input, Cnt swap) {
		(void)var;
		(void)input;
		(void)swap;
	}
};

// --------------------------------------------------------------
// Specialization for dynamically allocated int arrays (int*)
// --------------------------------------------------------------
template <>
struct Memory<int*> {
	// Allocates memory dynamically for 'vecSize' integers.
	static int	*init(sz_t vecSize) {
		if (vecSize > 0) {
			return (new int[vecSize]);
		}
		return (NULL);
	}

	static void populate(sz_t vecSize, const std::vector<int> &parsedInput, int *input) {
		for (sz_t i = 0; i < vecSize; ++i)
			input[i] = parsedInput.at(i);
	}

	// Frees the allocated memory when the container is no longer needed.
	static void	clear(Ctrl var, int *input, int *swap) {
		if (var._cntSize > 0) {
			delete[] input;
			delete[] swap;
		}
	}
};
