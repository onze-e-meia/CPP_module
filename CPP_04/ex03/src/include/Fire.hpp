/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:57:21 by tforster          #+#    #+#             */
/*   Updated: 2024/12/04 18:14:57 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_HPP
# define FIRE_HPP

# include "AMateria.hpp"

class Fire: public AMateria {
	public:
		Fire(void);
		Fire(const Fire &other);
		Fire &operator=(const Fire &other);
		~Fire(void);

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
