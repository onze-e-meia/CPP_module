/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CtrlVar.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:23:30 by tforster          #+#    #+#             */
/*   Updated: 2025/04/08 15:23:35 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	Ctrl(const Ctrl &other);

	void		initCtrl(sz_t order);
	void		upOrder(void);
	void		downOrder(void);
};

#endif
