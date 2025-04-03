

#ifndef PEMERGEME_HPP
# define PEMERGEME_HPP

# include <typeinfo>
# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <list>
# include "../lib/CtrlVar.hpp"
# include "../lib/jacobsthal_diff.hpp"
# include "MemoryManagement.hpp"
# include "DataManipulation.hpp"
# include "../lib/print_array.hpp"

static const std::string	INT_PTR_STR(typeid(int*).name());
static const std::string	VECTOR_STR(typeid(std::vector<int>).name());
static const std::string	DEQUE_STR(typeid(std::deque<int>).name());
static const std::string	LIST_STR(typeid(std::list<int>).name());

void	array_Ford_Johnson(sz_t vecSize, const std::vector<int> &parsedInput);
sz_t	movesLeft_to_do(sz_t totalMoves, sz_t move, sz_t jacob_diff);

#include <ctime>
#define CLOCKS_PER_MS	1000

// General template
template <typename Cnt>
struct	binarySearch {
	typedef	typename Cnt::iterator	it_t;

	static sz_t insertPos(Cnt &main, int value, sz_t order, sz_t bound) {
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
};

template <>
struct	binarySearch<int*> {
	static sz_t insertPos(const int *main, int value, sz_t order, sz_t bound) {
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
};

template <typename Cnt>
class PmergeMe {
	private:
		enum			e_typeId {INVALID, INT_PTR_ID, VECTOR_ID, DEQUE_ID, LIST_ID};
		const e_typeId	_typeId;
		Ctrl			_var;
		Cnt				_input;
		Cnt				_swap;

	public:
		PmergeMe(void): _typeId(checkTypeID()), _var(Ctrl(0,0)) {
			std::string	idName(typeid(Cnt).name());
			if (_typeId > 0) {
				_input = Memory<Cnt>::init(0);
				_swap = Memory<Cnt>::init(0);
			} else {
				std::ostringstream	oss;
				oss << BOLD RED "Error: " RST << "{" << idName << "} is an invalid Cnt type to sort" RENDL;
				throw (std::runtime_error(oss.str()));
			}
		}

		PmergeMe(sz_t vecSize, const std::vector<int> &parsedInput)
			: _typeId(checkTypeID()), _var(Ctrl(0, vecSize)) {
			std::string	idName(typeid(Cnt).name());
			std::cout << RED << idName << " | " << _typeId;
			if (_typeId > 0) {
				std::cout << GRN " Is an Valid Cnt type" RENDL;
				_input = Memory<Cnt>::init(vecSize);
				_swap = Memory<Cnt>::init(vecSize);
				if (vecSize > 1)
					Memory<Cnt>::populate(_var._vecSize, parsedInput, _input);
			} else {
				std::ostringstream	oss;
				oss << BOLD RED "Error: " RST << "{" << idName << "} is an invalid Cnt type to sort" RENDL;
				throw (std::runtime_error(oss.str()));
			}
		}

		~PmergeMe(void) {
			Memory<Cnt>::clear(_var, _input, _swap);
		}

		Cnt		&getInput(void) { return (_input); };

		void	startSort(void) {
			mergeLoop();
			insertionLopp();
		}

	private:
		e_typeId	checkTypeID() {
			std::string	idNAme(typeid(Cnt).name());
			static const std::string	names[] = {INT_PTR_STR, VECTOR_STR, DEQUE_STR, LIST_STR};
			static const e_typeId		ids[] = {INT_PTR_ID, VECTOR_ID, DEQUE_ID, LIST_ID};

			for (short i = 0; i < 4; ++i) {
				if (names[i] == idNAme)
					return (ids[i]);
			}
			return (INVALID);
		}

	void	mergeLoop(void) {
		while (_var._nb_pairs > 0) {
			// if (var._vecSize <= 129)
			// 	printArray(var, *input, BEFORE, MERGE);
			// merge(var, input, swap);
			merge();
			// if (var._vecSize <= 129)
			// 	printArray(var, *input, AFTER, MERGE);
			_var.upOrder();
		}
	}

	typedef typename Move<Cnt>::it_t	it_t;

	inline static int	getValue(Cnt &main, sz_t i) {
		return (*Move<Cnt>::at(main, i));
	}

	inline static it_t	getIt(Cnt &main, sz_t i) {
		return (Move<Cnt>::at(main, i));
	}

	void	merge(void) {
		Cnt	&main = _input;
		Cnt	&pend = _swap;
		it_t bi = getIt(main, _var._pairStart);
		it_t ai = bi;

		std::advance(ai, _var._order);
		for (sz_t i = _var._pairStart, g = 0 ; g < _var._nb_pairs ; i += _var._pairSize, ++g) {
			if (*bi > *ai)
				Move<Cnt>::swapPair(_var, main, pend, i);
			std::advance(ai, _var._order);
			bi = ai;
			std::advance(ai, _var._order);
		}
	}

	void	insertionLopp(void) {
		while (_var._level >  0) {
			_var.downOrder();
			// if (var._vecSize <= 129)
			// 	printArray(var, *input, BEFORE, INSERT);
			// insertion(var, input, swap);
			insertion();
			// if (var._vecSize <= 129)
			// 	printArray(var, *input, AFTER, INSERT);
		}
	}

	void	insertion(void) {
		Cnt		&pend = _input;
		Cnt		&main = _swap;
		sz_t	ai = 1, bi = 1, boundI = ai + bi;
		sz_t	copied = _var._pairSize;
		sz_t	odd = (_var._nb_unpaired - _var._leftOverElements != 0 ? 1 : 0);
		sz_t	totalMoves = _var._nb_pairs + odd - bi;

		Move<Cnt>::startMain(_var._pairSize, main, pend);
		for (sz_t j = 0, move = 0; move < totalMoves; ++j) {
			sz_t partialMove = movesLeft_to_do(totalMoves, move, jacob_diff[j]);
			move += partialMove;
			boundI = ai + bi;

			for (sz_t i = 0; ai < _var._nb_pairs && i < partialMove; ++i) {
				Move<Cnt>::insertAs(_var._order, ai, copied, main, pend);
				copied += _var._order;
				++ai;
				++boundI;
			}
			for (sz_t k = 0; k < partialMove; ++k) {
				sz_t rev_bi = bi + partialMove - 1 - k;
				int	value = getValue(pend, _var._pairStart + 2 * rev_bi * _var._order);
				sz_t		iBnry, disp = 0;

				if (rev_bi >  ai - 1) {
					if (value > getValue(main, _var._order * boundI - 1)) {
						iBnry = boundI;
						disp = 1;
					} else {
						iBnry = binarySearch<Cnt>::insertPos(main, value, _var._order, boundI - 1);
						++boundI;
					}
				} else {
					iBnry = binarySearch<Cnt>::insertPos(main, value, _var._order, boundI - 1);
					if (iBnry == boundI - 1)
						--boundI;
				}
				Move<Cnt>::insertBs(_var._order, iBnry, rev_bi, copied, main, pend, Move<Cnt>::displace(disp, k));
				copied += _var._order;
			}
			bi += partialMove;
		}
		Move<Cnt>::insertLeftOver(_var._leftOverElements, copied, main, pend);
		Move<Cnt>::swapInput(&_input, &_swap);
	}
};


#endif
