
#include <iostream>
#include "lib/color.hpp"
#include "lib/CtrlVar.hpp"


Ctrl::Ctrl(std::size_t level, std::size_t vecSize):
	_level(level), _vecSize(vecSize) {
	_order = 1u << level;
	initCtrl(_order);
}

void	Ctrl::initCtrl(std::size_t order) {
	_pairStart = order - 1;
	_pairSize = 2 * order;
	_nb_pairs = _vecSize / _pairSize;
	_nb_unpaired = _vecSize % _pairSize;
	_leftOverElements = _vecSize % order;
	_nbElements_noLeftOver = _vecSize - _leftOverElements;
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
		<< " ARRAYS_SIZE: " << c._vecSize << ENDL
		<< " ORDER: " << c._order << " PAIR_START: " << c._pairStart << ENDL
		<< " PAIR_SIZE: " << c._pairSize << " NB_OF_PAIRS: " << c._nb_pairs << ENDL
		<< " NB_UNPAIRED_ELEMENTS: " << c._nb_unpaired << ENDL
		<< " LEFTOVER_ELEMENTS: " << c._leftOverElements << ENDL
		<< " NB_ELEMENTS_WITH_NO LEFTOVER :" << c._nbElements_noLeftOver << ENDL;
}
