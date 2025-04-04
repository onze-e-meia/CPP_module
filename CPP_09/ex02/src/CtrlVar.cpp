
#include <iostream>
#include "typedef.hpp"
#include "lib/color.hpp"
#include "lib/CtrlVar.hpp"


Ctrl::Ctrl(void):
	_level(0), _cntSize(0) {
		_order = 1u << _level;
		initCtrl(_order);
	}

Ctrl::Ctrl(sz_t level, sz_t cntSize):
	_level(level), _cntSize(cntSize) {
	_order = 1u << _level;
	initCtrl(_order);
}

void	Ctrl::initCtrl(sz_t order) {
	_pairStart = order - 1;
	_pairSize = 2 * order;
	_nb_pairs = _cntSize / _pairSize;
	_nb_unpaired = _cntSize % _pairSize;
	_leftOverElements = _cntSize % order;
	_nbElements_noLeftOver = _cntSize - _leftOverElements;
}

void	Ctrl::upOrder(void) {
	++_level;
	_order <<= 1u;
	initCtrl(_order);
}

void	Ctrl::downOrder(void) {
	--_level;
	_order >>= 1u;
	initCtrl(_order);
}

void	print_status(const Ctrl &c) {
	std::cout
		<< " ARRAYS_SIZE: " << c._cntSize << ENDL
		<< " ORDER: " << c._order << " PAIR_START: " << c._pairStart << ENDL
		<< " PAIR_SIZE: " << c._pairSize << " NB_OF_PAIRS: " << c._nb_pairs << ENDL
		<< " NB_UNPAIRED_ELEMENTS: " << c._nb_unpaired << ENDL
		<< " LEFTOVER_ELEMENTS: " << c._leftOverElements << ENDL
		<< " NB_ELEMENTS_WITH_NO LEFTOVER :" << c._nbElements_noLeftOver << ENDL;
}
