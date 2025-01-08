/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:10:50 by tforster          #+#    #+#             */
/*   Updated: 2024/12/09 15:36:56 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class	ICharacter;

class	AMateria {
	protected:
		std::string	_type;
		bool		_equiped;

		void		cnstr_msg(std::string class_name, std::string str) const;

	public:
		AMateria(void);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual	~AMateria(void);

		AMateria(const std::string &type);

		const std::string	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target) = 0;

		bool				is_equiped(void);
		void				equip(void);
};

#endif
