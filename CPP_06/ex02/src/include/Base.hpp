/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:01:57 by tforster          #+#    #+#             */
/*   Updated: 2025/01/14 17:04:54 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <cstddef>
# include <exception>
class	Base {
	public:
		virtual	~Base(void);
};

template<typename T>
Base *createDerived(void) {
	return (new T());
}

template <typename T>
bool isType(Base *base) {
	return (dynamic_cast<T*>(base) != NULL);
}

template <typename T>
bool tryCast(Base& base) {
	try {
		(void) dynamic_cast<T&>(base);
		return (true);
	} catch (std::exception &exception) {
		return (false);
	}
}

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
