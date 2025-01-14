/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:55:52 by tforster          #+#    #+#             */
/*   Updated: 2025/01/14 17:04:33 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Base.hpp"
#include "include/A.hpp"
#include "include/B.hpp"
#include "include/C.hpp"


void identify(Base *base) {
	typedef bool	(*TypeCheckFunc)(Base*);
	TypeCheckFunc	typeCheckers[] = {&isType<A>, &isType<B>, &isType<C>};
	const char		typeNames[] = "ABC";

	for (std::size_t i = 0; i < 3; i++)
		if (typeCheckers[i](base)) {
			std::cout << typeNames[i];
			return;
		}
	if (dynamic_cast<Base *>(base))
		std::cout << "Base" << std::endl;
	else
	 	std::cout << "NULL" << std::endl;}

void identify(Base &base) {
	if (tryCast<A>(base))
		std::cout << "A";
	else if (tryCast<B>(base))
		std::cout << "B";
	else if (tryCast<C>(base))
		std::cout << "C";
	else
		std::cout << "Base";
}
