/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:01:57 by tforster          #+#    #+#             */
/*   Updated: 2025/01/14 14:26:01 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class	Base {
	public:
		virtual	~Base(void);
};

template<typename T>
Base *createDerived(void) {
	return (new T());
}

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
