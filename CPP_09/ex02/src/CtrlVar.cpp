
#include <iostream>
#include "typedef.hpp"
#include "lib/color.hpp"
#include "include/CtrlVar.hpp"


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

Ctrl::Ctrl(const Ctrl &other):
	_level(other._level),
	_cntSize(other._cntSize),
	_order(other._order),
	_pairStart(other._pairStart),
	_pairSize(other._pairSize),
	_nb_pairs(other._nb_pairs),
	_nb_unpaired(other._nb_unpaired),
	_leftOverElements(other._leftOverElements),
	_nbElements_noLeftOver(other._nbElements_noLeftOver) {}

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
