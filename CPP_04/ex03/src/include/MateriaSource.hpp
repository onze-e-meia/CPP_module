/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:05:34 by tforster          #+#    #+#             */
/*   Updated: 2024/12/09 15:51:12 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "string"
# include "IMateriaSource.hpp"

class AMateria;

class MateriaSource: public IMateriaSource {
	private:
		std::size_t					_index;
		static const std::size_t	_sourceSize = 4;
		AMateria					*_source[_sourceSize];

		void		cnstr_msg(std::string class_name, std::string str) const;
		void		null_source(void);
		void		copy_source(const AMateria * const source[]);

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);
		~MateriaSource(void);

		void		learnMateria(AMateria *materia);
		AMateria*	createMateria(const std::string &type);
};

#endif
