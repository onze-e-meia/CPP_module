

#ifndef ARRAY_SOLUTION_HPP
# define ARRAY_SOLUTION_HPP

# include <typeinfo>
# include <sstream>
# include <vector>
# include <deque>
# include <list>
# include "../lib/CtrlVar.hpp"
# include "../lib/jacobsthal_diff.hpp"
# include "../lib/print_array.hpp"

static const std::string	INT_PTR_STR(typeid(int*).name());
static const std::string	VECTOR_STR(typeid(std::vector<int>).name());
static const std::string	DEQUE_STR(typeid(std::deque<int>).name());
static const std::string	LIST_STR(typeid(std::list<int>).name());

void		array_Ford_Johnson(std::size_t vecSize, const std::vector<int> &parsedInput);
std::size_t	movesLeft_to_do(std::size_t totalMoves, std::size_t move, std::size_t jacob_diff);

// General template
template <typename Container>
struct binarySearch {
	static std::size_t insertPos(Container *main, int value, std::size_t order, std::size_t bound) {
		std::size_t	low = 0;
		while(low < bound) {
			std::size_t mid = low + (bound  - low) / 2;
			if(value < main[order * (mid + 1) - 1])
				bound = mid;
			else
				low = mid + 1;
		}
		return (low);
	}

	static std::size_t insertPos(const int *main, int value, std::size_t order, std::size_t bound) {
		std::size_t	low = 0;
		while(low < bound) {
			std::size_t mid = low + (bound  - low) / 2;
			if(value < main[order * (mid + 1) - 1])
				bound = mid;
			else
				low = mid + 1;
		}
		return (low);
	}
};

// ===========================
// Memory Management Templates
// ===========================
// These templates handle the initialization and deallocation
// of containers or dynamically allocated arrays for MemoryChunk.

// ---------------------------
// Initialization Templates
// ---------------------------

// Forward declaration of the ContainerType template for specialization
template <typename Container>
struct ContainerType;

// Generic template for STL containers like std::vector, std::deque, std::list.
// It initializes a container with the given size.
template <typename Container>
struct ContainerType {
	static Container	initContainer (std::size_t vecSize) {
		return (Container(vecSize));
	}
};

// Specialization for dynamically allocated int arrays (int*).
// Allocates memory dynamically for 'vecSize' integers.
template <>
struct ContainerType<int*> {
	static int	*initContainer (std::size_t vecSize) {
		if (vecSize > 0) {
			// std::cout << RED "Creata int array of size: " << vecSize << RENDL;
			return (new int[vecSize]);
		}
		return (NULL);
	}
};

// ---------------------------
// Memory Cleanup Templates
// ---------------------------

// Forward declaration of the ClearMemory template for specialization
template <typename Container>
struct ClearMemory;

// Generic template for STL containers like std::vector, std::deque, std::list.
// Since these containers handle their own memory, no cleanup is needed.
template <typename Container>
struct ClearMemory {
	static void	clear (Ctrl var, Container input, Container swap) {
		(void)var;
		(void)input;
		(void)swap;
	}
};

// Specialization for dynamically allocated int arrays (int*).
// Frees the allocated memory when the container is no longer needed.
template <>
struct ClearMemory<int*> {
	static void	clear (Ctrl var, int *input, int *swap) {
		if (var._vecSize > 0) {
			delete[] input;
			delete[] swap;
		}
	}
};



template <typename Container>
class MemoryChunk {
	private:
		enum			e_typeId {INVALID, INT_PTR_ID, VECTOR_ID, DEQUE_ID, LIST_ID};
		const e_typeId	_typeId;
		Ctrl			_var;
		Container		_input;
		Container		_swap;

	public:

		MemoryChunk(void): _typeId(checkTypeID()), _var(Ctrl(0,0)) {
			std::string	idName(typeid(Container).name());
			std::cout << RED << idName << " | " << _typeId;
			if (_typeId > 0) {
				std::cout << GRN " Is an Valid Container type" RENDL;
				_input = ContainerType<Container>::initContainer(0);
				_swap = ContainerType<Container>::initContainer(0);
			} else {
				std::ostringstream	oss;
				oss << BOLD RED "Error: " RST << "{" << idName << "} is an invalid Container type to sort" RENDL;
				throw (std::runtime_error(oss.str()));
			}
		}

		MemoryChunk(std::size_t vecSize, const std::vector<int> &parsedInput)
			: _typeId(checkTypeID()), _var(Ctrl(0, vecSize)) {
			std::string	idName(typeid(Container).name());
			std::cout << RED << idName << " | " << _typeId;
			if (_typeId > 0) {
				std::cout << GRN " Is an Valid Container type" RENDL;
				_input = ContainerType<Container>::initContainer(vecSize);
				_swap = ContainerType<Container>::initContainer(vecSize);
				if (vecSize > 0)
					fillContainer(parsedInput, _input);
			} else {
				std::ostringstream	oss;
				oss << BOLD RED "Error: " RST << "{" << idName << "} is an invalid Container type to sort" RENDL;
				throw (std::runtime_error(oss.str()));
			}
		}

		~MemoryChunk(void) {
			ClearMemory<Container>::clear(getCrtlVar(), getInput(), getSwap());
		}

		Ctrl		&getCrtlVar(void) { return (_var); }
		Container	&getInput(void) { return (_input); }
		Container	&getSwap(void) { return (_swap); }

		// void	startSort(Ctrl &var, Container *input, Container *swap) {
		void	startSort(void) {
			std::cout << RED "ON START SORT PIRNT MemoryChunk INPUT:"  RENDL;
			for (std::size_t i = 0; i < _var._vecSize; ++i)
				std::cout << _input[i] << ", ";
			std::cout << ENDL;

			// mergeLoop(var, input, swap);
			// insertionLopp(var, input, swap);
			mergeLoop(_var, &_input, &_swap);
			insertionLopp(_var, &_input, &_swap);
		}

	private:
		// void fillContainer(const std::vector<int> &parsedInput, Container &input) {
		// 	for (std::size_t i = 0; i < _var._vecSize; ++i)
		// 		input[i] = parsedInput[i];
		// }

		e_typeId	checkTypeID() {
			std::string	idNAme(typeid(Container).name());
			std::string	names[] = {INT_PTR_STR, VECTOR_STR, DEQUE_STR, LIST_STR};
			e_typeId	ids[] = {INT_PTR_ID, VECTOR_ID, DEQUE_ID, LIST_ID};

			for (short i = 0; i < 4; ++i) {
				if (names[i] == idNAme)
					return (ids[i]);
			}
			return (INVALID);
		}

		void fillContainer(const std::vector<int> &parsedInput, int *input) {
			for (std::size_t i = 0; i < _var._vecSize; ++i)
			input[i] = parsedInput[i];
		}

		void fillContainer(const std::vector<int> &parsedInput, std::vector<int> input) {
			for (std::size_t i = 0; i < _var._vecSize; ++i)
			input[i] = parsedInput[i];
		}


	static void	mergeLoop(Ctrl &var, Container *input, Container *swap) {
		while (var._nb_pairs > 0) {
			if (var._vecSize <= 40)
				printArray(var, *input, BEFORE, MERGE);
			merge(var, input, swap);
			if (var._vecSize <= 40)
				printArray(var, *input, AFTER, MERGE);
			var.upOrder();
		}
	}

	static void	merge(Ctrl &var, Container *input, Container *swap) {
		Container	&main = *input;
		Container	&pend = *swap;

		for (std::size_t i = var._pairStart, g = 0 ; g < var._nb_pairs ; i += var._pairSize, ++g) {
			if (main[i] > main[i + var._order]) {
				// std::size_t j = i - (var._pairStart);
				swapChunk(var, main, pend, i);
			}
		}
	}

	static void swapChunk(Ctrl &var, int *main, int *pend, std::size_t i) {
		std::size_t ai = i + 1;
		std::size_t bi = i - (var._pairStart);
		std::memcpy(pend, main + bi, var._order * sizeof(int));
		// std::memcpy(main + bi, main + bi + var._order, var._order * sizeof(int));
		// std::memcpy(main + bi + var._order, pend, var._order * sizeof(int));
		std::memcpy(main + bi, main + ai, var._order * sizeof(int));
		std::memcpy(main + ai, pend, var._order * sizeof(int));
	}

	// static void swapChunk(Ctrl &var, Container main, Container pend, std::size_t i) {
	// 	std::size_t ai = i + 1;
	// 	std::size_t bi = i - (var._pairStart);
	// 	std::memcpy(&pend[0], &main[bi], var._order * sizeof(int));
	// 	// std::memcpy(&main[bi], &main[bi + var._order], var._order * sizeof(int));
	// 	// std::memcpy(&main[bi + var._order], &pend[0], var._order * sizeof(int));
	// 	std::memcpy(&main[bi], &main[ai], var._order * sizeof(int));
	// 	std::memcpy(&main[ai], &pend[0], var._order * sizeof(int));
	// }

	static void	insertionLopp(Ctrl &var, Container *input, Container *swap) {
		while (var._level >  0) {
			var.downOrder();
			if (var._vecSize <= 40)
				printArray(var, *input, BEFORE, INSERT);
			insertion(var, input, swap);
			if (var._vecSize <= 40)
				printArray(var, *input, AFTER, INSERT);
		}
	}

	static void	insertion(Ctrl &var, Container *input, Container *swap) {
		Container	&pend = *input;
		Container	&main = *swap;

		std::memcpy(main, pend, var._pairSize * sizeof(int));
		std::size_t	ai = 1, bi = 1, boundIndex = ai + bi;
		std::size_t	copied = var._pairSize;

		std::size_t odd = (var._nb_unpaired - var._leftOverElements != 0 ? 1 : 0);
		std::size_t total_moves = var._nb_pairs + odd - bi;

		for (std::size_t j = 0, move = 0; move < total_moves; ++j) {
			std::size_t partialMove = movesLeft_to_do(total_moves, move, jacob_diff[j]);

			move += partialMove;
			boundIndex = ai + bi;

			for (std::size_t i = 0; ai < var._nb_pairs && i < partialMove; ++i) {
				memcpy(main + copied, pend + ((2 * ai + 1) * var._order), var._order * sizeof(int));
				copied += var._order;
				++ai;
				++boundIndex;
			}

			for (std::size_t k = 0; k < partialMove; ++k) {
				std::size_t reverse_bi = bi + partialMove - 1 - k;
				int	value = pend[var._pairStart + 2 * reverse_bi * var._order];

				std::size_t binaryIndex;
				if (reverse_bi >  ai - 1) {
					if (value > main[var._order * boundIndex - 1]) {
						binaryIndex = boundIndex;
					} else {
						binaryIndex = binarySearch<int *>::insertPos(main, value, var._order, boundIndex - 1);
						++boundIndex;
						std::size_t	to_move = copied - binaryIndex * var._order;
						memmove(main + (binaryIndex + 1) * var._order, main + (binaryIndex  * var._order), to_move * sizeof(int));
					}
				} else {
					binaryIndex = binarySearch<int *>::insertPos(main, value, var._order, boundIndex - 1);
					if (binaryIndex ==  boundIndex - 1)
						--boundIndex;
					std::size_t	to_move = copied - binaryIndex * var._order;
					memmove(main + (binaryIndex + 1) * var._order, main + (binaryIndex  * var._order), to_move * sizeof(int));
				}

				memcpy(main + binaryIndex  * var._order, pend + 2 * reverse_bi * var._order, var._order * sizeof(int));
				copied += var._order;
			}
			bi += partialMove;
		}
		if (var._leftOverElements)
			memcpy(main + copied, pend + copied, var._leftOverElements * sizeof(int));
		int	*tempArray = *input;
		*input = *swap;
		*swap = tempArray;
	}

	static void	mainStart (int *main, int *pend, std::size_t pairSize) {
		std::memcpy(main, pend, pairSize * sizeof(int));
	}
};







// // Generic template for any container with begin() and end()
// template <typename Container>
// struct binarySearch {
// 	static std::size_t indexPos(Container& data) {
// 		std::cout << "Generic container specialization\n";
// 		for (typename Container::iterator it = data.begin(); it != data.end(); ++it) {
// 			std::cout << *it << " ";
// 		}
// 		std::cout << std::endl;
// 		return (1);
// 	}
// };

// // Specialization for int*
// template <>
// struct binarySearch<int *> {
// 	static std::size_t insertPos(const int *main, int value, std::size_t order, std::size_t bound) {
// 		std::size_t	low = 0;
// 		while(low < bound) {
// 			std::size_t mid = low + (bound  - low) / 2;
// 			if(value < main[order * (mid + 1) - 1])
// 				bound = mid;
// 			else
// 				low = mid + 1;
// 		}
// 		return (low);
// 	}
// };

// std::size_t binarySearchInsertPos(const int *main, int value, std::size_t order, std::size_t bound);
// std::size_t binarySearchInsertPos(std::vector<int> &main, int value, std::size_t order, std::size_t bound);

// std::size_t	movesLeft_to_do(std::size_t totalMoves,
// 	std::size_t move, std::size_t jacobsthal_diff);

#endif
