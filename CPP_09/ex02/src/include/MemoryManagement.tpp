
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include "typedef.hpp"
#include "../include/CtrlVar.hpp"

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
	static Cnt	init(sz_t cntSize) {
		return (Cnt(cntSize, 0));
	}

	static void	populate(sz_t, const std::vector<int> &parsedInput, Cnt &input) {
		std::copy(parsedInput.begin(), parsedInput.end(), input.begin());
	}

	static void	copyCnt(sz_t, const Cnt &other, Cnt &input) {
		std::copy(other.begin(), other.end(), input.begin());
	}

	// Since these containers handle their own memory, no cleanup is needed.
	static void	clear(Ctrl, Cnt, Cnt) {
	}
};

// --------------------------------------------------------------
// Specialization for dynamically allocated int arrays (int*)
// --------------------------------------------------------------
template <>
struct Memory<int*> {
	// Allocates memory dynamically for 'cntSize' integers.
	static int	*init(sz_t cntSize) {
		if (cntSize > 0) {
			return (new int[cntSize]);
		}
		return (NULL);
	}

	static void populate(sz_t cntSize, const std::vector<int> &parsedInput, int *input) {
		std::memcpy(input, parsedInput.data(), cntSize * sizeof(int));
	}

	static void	copyCnt(sz_t cntSize, int* other, int* input) {
		std::memcpy(input, other, cntSize * sizeof(int));
	}

	// Frees the allocated memory when the container is no longer needed.
	static void	clear(Ctrl var, int *input, int *swap) {
		if (var._cntSize > 0) {
			delete[] input;
			delete[] swap;
		}
	}
};
