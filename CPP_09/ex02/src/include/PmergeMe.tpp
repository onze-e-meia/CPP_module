

#include "PmergeMe.hpp"
#include "MemoryManagement.tpp"
#include "DataManipulation.tpp"

// ============================================
// Iterator and Dereference Helper Templates
// ============================================
// These templates handle the iterator and dereference
// of data the containers.

template <typename Cnt>
inline int	getValue(Cnt &container, sz_t i) {
	return (*Move<Cnt>::at(container, i));
}

template <typename Cnt>
inline typename Move<Cnt>::it_t	getIt(Cnt &container, sz_t i) {
	return (Move<Cnt>::at(container, i));
}

// ===============================
// Class Templates for PmergeMe
// ===============================
// Templates for member functions.

// ------------------------
// Constructor functions
// ------------------------
template <typename Cnt>
PmergeMe<Cnt>::PmergeMe(void): _id(checkTypeID()), _var(Ctrl()) {
	const std::vector<int>	parsedInput;
	initVars(parsedInput);
}

template <typename Cnt>
PmergeMe<Cnt>::PmergeMe(const std::vector<int> &parsedInput)
	: _id(checkTypeID()), _var(Ctrl(0, checkParsedSize(parsedInput))) {
		initVars(parsedInput);
}

// ----------------------
// Destructor function
// ----------------------
template <typename Cnt>
PmergeMe<Cnt>::~PmergeMe(void) {
	Memory<Cnt>::clear(_var, _input, _swap);
}

// --------------------------
// Public member functions
// --------------------------
template <typename Cnt>
const Cnt	&PmergeMe<Cnt>::getInput(void) { return (_input); };

template <typename Cnt>
void	PmergeMe<Cnt>::startSort(void) {
	if (_var._cntSize > 1) {
		clock_t	start = clock();
		mergeLoop();
		insertionLopp();
		clock_t	end = clock();
		std::cout
			<< "Time to sort elements with " << CNT_NAMES[_id - 1] << ": "
			<< static_cast<double>(end - start) / CLOCKS_PER_MS << "ms" ENDL;
		Cnt		&main = _input;
		Move<Cnt>::checkSort(main, _var._cntSize);
	}
	else
		std::cout << "Is of size 1" << ENDL;
}

// ---------------------------
// Private member functions
// ---------------------------
template <typename Cnt>
sz_t	PmergeMe<Cnt>::checkParsedSize(const std::vector<int> &parsedInput) {
	return (parsedInput.size());
}

template <typename Cnt>
typename PmergeMe<Cnt>::e_id	PmergeMe<Cnt>::checkTypeID(void) {
	const std::string			idNAme(typeid(Cnt).name());
	static const std::string	types[] = {INT_PTR_TYPE, VECTOR_TYPE, DEQUE_TYPE, LIST_TYPE};
	static const e_id			ids[] = {INT_PTR_ID, VECTOR_ID, DEQUE_ID, LIST_ID};

	for (short i = 0; i < 4; ++i) {
		if (types[i] == idNAme)
			return (ids[i]);
	}
	return (INVALID);
}

template <typename Cnt>
void	PmergeMe<Cnt>::initVars(const std::vector<int> &parsedInput) {
	std::string	idName(typeid(Cnt).name());
	if (_id > 0) {
		std::cout
			<< H_GRN << CNT_NAMES[_id - 1] << RST " is an valid container type " H_BLU "{"
			<< H_GRN "size = " << _var._cntSize << H_BLU "}." RENDL;
		_input = Memory<Cnt>::init(_var._cntSize);
		_swap = Memory<Cnt>::init(_var._cntSize);
		if (_var._cntSize > 1)
			Memory<Cnt>::populate(_var._cntSize, parsedInput, _input);
	} else {
		std::ostringstream	oss;
		oss << BOLD L_RED "Error: " <<  idName << RST " is an invalid container type." RENDL;
		throw (std::runtime_error(oss.str()));
	}
}

template <typename Cnt>
void	PmergeMe<Cnt>::mergeLoop(void) {
	while (_var._nb_pairs > 0) {
		// std::cout << COP "Merge:" RENDL;
		// if (_var._cntSize <= 129) {
		// 	std::cout << COP "BEFORE:" RST;
		// 	printArray(_var, _input);
		// }
		merge();
		// if (_var._cntSize <= 129) {
		// 	std::cout << COP "AFTER :" RST;
		// 	printArray(_var, _input);
		// 	std::cout << ENDL;
		// }
		_var.upOrder();
	}
}

template <typename Cnt>
void	PmergeMe<Cnt>::insertionLopp(void) {
	while (_var._level >  0) {
		_var.downOrder();
		// std::cout << COP "Insert:" RENDL;
		// if (_var._cntSize <= 129) {
		// 	std::cout << COP "BEFORE    > " RST;
		// 	printArray(_var, _input);
		// }
		insertion();
		// if (_var._cntSize <= 129) {
		// 	std::cout << COP "AFTER     > " RST;
		// 	printArray(_var, _input);
		// 	std::cout << ENDL;
		// }
	}
}

template <typename Cnt>
void	PmergeMe<Cnt>::merge(void) {
	typedef typename Move<Cnt>::it_t	it_t;
	Cnt		&main = _input;
	Cnt		&pend = _swap;
	it_t	bi = getIt(main, _var._pairStart);
	it_t	ai = bi;

	std::advance(ai, _var._order);
	for (sz_t i = _var._pairStart, g = 0 ; g < _var._nb_pairs ; i += _var._pairSize, ++g) {
		if (*bi > *ai)
			Move<Cnt>::swapPair(_var, main, pend, i);
		std::advance(ai, _var._order);
		bi = ai;
		std::advance(ai, _var._order);
	}
}

template <typename Cnt>
void	PmergeMe<Cnt>::insertion(void) {
	Cnt		&pend = _input;
	Cnt		&main = _swap;
	sz_t	ai = 1, bi = 1, boundI = ai + bi;
	sz_t	copied = _var._pairSize;
	sz_t	odd = (_var._nb_unpaired - _var._leftOverElements != 0 ? 1 : 0);
	sz_t	totalMoves = _var._nb_pairs + odd - bi;

	// for (sz_t i = 0; i < _var._cntSize; ++i) {
	// 	main[i] = -1;
	// }

	Move<Cnt>::startMain(_var._pairSize, main, pend);

	// std::cout << COP "START     > " RST;
	// printArray(_var, main);

	for (sz_t j = 0, move = 0; move < totalMoves; ++j) {
		sz_t partialMove = movesLeft_to_do(totalMoves, move, JACOB_DIFF[j]);
		move += partialMove;
		boundI = ai + bi;

		sz_t i = 0;
		for (; ai < _var._nb_pairs && i < partialMove; ++i) {
			Move<Cnt>::insertAs(_var._order, ai, copied, main, pend);
			copied += _var._order;
			++ai;
			++boundI;
		}

		// if (i) {
		// 	std::cout << COP "INSERT As > " RST;
		// 	printArray(_var, main);
		// }

		for (sz_t k = 0; k < partialMove; ++k) {
			sz_t rev_bi = bi + partialMove - 1 - k;
			int	value = getValue(pend, _var._pairStart + 2 * rev_bi * _var._order);
			sz_t		iBnry, disp = 0;

			if (rev_bi >  ai - 1) {
				if (value > getValue(main, _var._order * boundI - 1)) {
					iBnry = boundI;
					disp = 1;
				} else {
					iBnry = Move<Cnt>::binarySearch(main, value, _var._order, boundI - 1);
					++boundI;
				}
			} else {
				iBnry = Move<Cnt>::binarySearch(main, value, _var._order, boundI - 1);
				if (iBnry == boundI - 1)
					--boundI;
			}
			Move<Cnt>::insertBs(_var._order, iBnry, rev_bi, copied, main, pend, Move<Cnt>::displace(disp, k));
			copied += _var._order;

			// std::cout << COP "INSERT Bs > " << RST;
			// printArray(_var, main);
		}
		// std::cout << ENDL;
		bi += partialMove;
	}
	Move<Cnt>::insertLeftOver(_var._leftOverElements, copied, main, pend);
	Move<Cnt>::swapInput(&_input, &_swap);
}

template <typename Cnt>
sz_t	PmergeMe<Cnt>::movesLeft_to_do(sz_t totalMoves, sz_t move, sz_t JACOB_DIFF) {
	sz_t partialMove
		= static_cast<int>(totalMoves) - (static_cast<int>(move) + static_cast<int>(JACOB_DIFF)) > 0
		? JACOB_DIFF
		: totalMoves - move;
	return (partialMove);
}
