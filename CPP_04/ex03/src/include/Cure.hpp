/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:57:19 by tforster          #+#    #+#             */
/*   Updated: 2024/12/01 18:04:51 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria {
	public:
		Cure(void);
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		~Cure(void);

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
