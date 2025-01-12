/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:55:52 by tforster          #+#    #+#             */
/*   Updated: 2025/01/12 19:13:57 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Base.hpp"
#include "include/A.hpp"
#include "include/B.hpp"
#include "include/C.hpp"
#include <iostream>

void identify(Base *base) {

	if (dynamic_cast<A *>(base))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(base))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(base))
		std::cout << "C" << std::endl;
	else if (dynamic_cast<Base *>(base))
		std::cout << "Base" << std::endl;
	else
	 	std::cout << "NULL" << std::endl;
}

void identify(Base &base) {

	try {
		A a = dynamic_cast<A &>(base);
		std::cout << "A" << std::endl;
		return ;
	} catch (std::exception &exception) {}

	try {
		B b = dynamic_cast<B &>(base);
		std::cout << "B" << std::endl;
		return ;
	} catch (std::exception &exception) {}

	try {
		C c = dynamic_cast<C &>(base);
		std::cout << "C" << std::endl;
		return ;
	} catch (std::exception &exception) {}

	try {
		Base ref = dynamic_cast<Base &>(base);
		std::cout << "Base" << std::endl;
		return ;
	} catch (std::exception &exception) {}

	std::cout << "NULL" << std::endl;
}
