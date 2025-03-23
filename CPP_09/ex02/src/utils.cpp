/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:12:09 by tforster          #+#    #+#             */
/*   Updated: 2025/03/22 21:46:11 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/utils.hpp"

#include <cstddef>
#include <iostream>
#include "lib/color.hpp"

std::size_t binarySearchInsertPos(const int *main, int value, std::size_t order, std::size_t bound) {
	std::size_t	low = 0;
	// std::cout
	// 	<< BOLD "VALUE: "<< value
	// 	<< " | BOUND[i: " << order * bound - 1 << "|v: " << main[order * bound - 1] << "]" ENDL;
	while(low < bound) {
		std::size_t mid = low + ((bound - 1) - low) / 2;
		if(value < main[order * (mid + 1) - 1])
			bound = mid;
		else
			low = mid + 1;
	}
	return (low);
}

std::size_t movesLeft_to_do(std::size_t totalMoves,
	std::size_t move, std::size_t jacobsthal_diff) {
	std::size_t partialMove
		= static_cast<int>(totalMoves) - (static_cast<int>(move) + static_cast<int>(jacobsthal_diff)) > 0
		? jacobsthal_diff
		: totalMoves - move;
	return (partialMove);
}
