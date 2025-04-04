

#ifndef PEMERGEME_HPP
# define PEMERGEME_HPP

# include <typeinfo>
# include <iostream>
# include <sstream>
# include <ctime>
# include <vector>
# include <deque>
# include <list>
# include "typedef.hpp"
# include "../lib/CtrlVar.hpp"
# include "../lib/print_array.hpp"

extern const int			CLOCKS_PER_MS;
extern const std::string	INT_PTR_TYPE;
extern const std::string	VECTOR_TYPE;
extern const std::string	DEQUE_TYPE;
extern const std::string	LIST_TYPE;
extern const char			*CNT_NAMES[4];
extern const std::size_t	JACOB_DIFF[];

void	array_Ford_Johnson(sz_t vecSize, std::vector<int> &parsedInput);

template <typename Cnt>
class PmergeMe {
	private:
		enum		e_id {INVALID, INT_PTR_ID, VECTOR_ID, DEQUE_ID, LIST_ID};
		const e_id	_id;
		Ctrl		_var;
		Cnt			_input;
		Cnt			_swap;

	public:
		PmergeMe(void);
		PmergeMe(const std::vector<int> &parsedInput);
		// PmergeMe(PmergeMe);
		// PmergeMe operator(PmergeMe);

		~PmergeMe(void);

		const Cnt	&getInput(void);
		void		startSort(void);

	private:
		static	sz_t	checkParsedSize(const std::vector<int> &parsedInput);
		e_id	checkTypeID(void);
		void	initVars(const std::vector<int> &parsedInput);

		void	mergeLoop(void);
		void	insertionLopp(void);
		void	merge(void);
		void	insertion(void);
		sz_t	movesLeft_to_do(sz_t totalMoves, sz_t move, sz_t JACOB_DIFF);
};

# include "PmergeMe.tpp"

#endif
