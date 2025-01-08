/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:57:21 by tforster          #+#    #+#             */
/*   Updated: 2024/12/06 17:58:24 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria {
	public:
		Ice(void);
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice(void);

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
