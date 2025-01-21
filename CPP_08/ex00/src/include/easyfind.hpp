/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:22:43 by tforster          #+#    #+#             */
/*   Updated: 2025/01/21 16:58:00 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include "../lib/color.hpp"

template<typename C>
typename C::iterator easyfind(C &cnt, int integer) {
	return (std::find(cnt.begin(), cnt.end(), integer));
}

// Helper functions
template<typename C>
void	print_cnt(C cnt) {
	std::cout << "[";
	typename C::iterator it = cnt.begin();
	while (it != cnt.end()) {
		std::cout << *it;
		it++;
		if (it != cnt.end())
			std::cout << ", ";
	}
	std::cout << "]" ENDL;
}

template<typename C>
void	search_print(C cnt, int integer) {
	typename C::iterator	it = easyfind(cnt, integer);

	std::cout << D_BLU ">> Search for: " RST << integer << ENDL;
	if (it != cnt.end())
		std::cout << D_BLU "Found: " RST << *it
		<< D_BLU " at position: " RST << std::distance(cnt.begin(), it) << ENDL;
	else
		std::cout << L_RED "Not found" RENDL;
}

template<typename C>
void	fill_container_multy(C &cnt, std::size_t size, int multy) {
	for (std::size_t i = 0; i < size; i++)
		cnt.push_back(multy * i);
}

#endif
