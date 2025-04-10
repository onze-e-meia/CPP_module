/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:23:41 by tforster          #+#    #+#             */
/*   Updated: 2025/04/08 15:30:39 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEMERGEME_HPP
# define PEMERGEME_HPP

# include <string>
# include <ctime>
# include <vector>
# include "typedef.hpp"
# include "CtrlVar.hpp"

extern const int			CLOCKS_PER_MS;
extern const std::string	INT_PTR_TYPE;
extern const std::string	VECTOR_TYPE;
extern const std::string	DEQUE_TYPE;
extern const std::string	LIST_TYPE;
extern const char			*CNT_NAMES[4];
extern const sz_t			JACOB_DIFF[];

template <typename Cnt>
class PmergeMe {
	private:
		bool		_isSorted;
		enum		e_id {INVALID, INT_PTR_ID, VECTOR_ID, DEQUE_ID, LIST_ID};
		const e_id	_id;
		Ctrl		_var;
		Cnt			_input;
		Cnt			_swap;
		sz_t		_comparisons;

	public:
		PmergeMe(void);
		explicit PmergeMe(const std::vector<int> &parsedInput);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe<Cnt> &other);
		~PmergeMe(void);

		const Cnt		&getInput(void);
		void			startSort(void);

	private:
		static	sz_t	getParsedSize(const std::vector<int> &parsedInput);
		static e_id		checkTypeID(void);
		void			initVars(const std::vector<int> &parsedInput);

		void			mergeLoop(void);
		void			insertionLopp(void);
		void			merge(void);
		void			insertion(void);
		static sz_t		movesLeft_to_do(sz_t totalMoves, sz_t move, sz_t JACOB_DIFF);
};

# include "PmergeMe.tpp"

#endif
