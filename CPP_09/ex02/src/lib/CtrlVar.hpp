

#ifndef CTRL_VAR_HPP
# define CTRL_VAR_HPP

# include "typedef.hpp"

struct Ctrl {
	sz_t	_level;
	sz_t	_cntSize;
	sz_t	_order;
	sz_t	_pairStart;
	sz_t	_pairSize;
	sz_t	_nb_pairs;
	sz_t	_nb_unpaired;
	sz_t	_leftOverElements;
	sz_t	_nbElements_noLeftOver;

	Ctrl(void);
	Ctrl(sz_t level, sz_t cntSize);

	void		initCtrl(sz_t order);
	void		upOrder(void);
	void		downOrder(void);
};

// Helper Functions
void print_status(const Ctrl &c);

#endif
