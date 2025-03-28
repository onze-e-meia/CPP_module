

#ifndef CTRL_VAR_HPP
# define CTRL_VAR_HPP

# include <cstddef>

struct Ctrl {
	std::size_t	_level;
	std::size_t	_vecSize;
	std::size_t	_order;
	std::size_t	_pairStart;
	std::size_t	_pairSize;
	std::size_t	_nb_pairs;
	std::size_t	_nb_unpaired;
	std::size_t	_leftOverElements;
	std::size_t	_nbElements_noLeftOver;

	explicit Ctrl(std::size_t level, std::size_t vecSize);

	void		initCtrl(std::size_t order);
	void		upOrder(void);
	void		downOrder(void);
};

// Helper Functions
void print_status(const Ctrl &c);

#endif
