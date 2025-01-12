/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:33:11 by tforster          #+#    #+#             */
/*   Updated: 2025/01/12 19:13:17 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "include/Base.hpp"
#include "include/A.hpp"
#include "include/B.hpp"
#include "include/C.hpp"

typedef Base* (*ConstructorFunc)();

Base *generate(void) {
	ConstructorFunc	constructors[] = {createDerived<A>, createDerived<B>, createDerived<C>};
	int index = std::rand() % 3;

	return (constructors[index]());
}
