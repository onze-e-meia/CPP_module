/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:11:20 by tforster          #+#    #+#             */
/*   Updated: 2025/03/19 18:25:13 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UITLS_HPP
# define UITLS_HPP

# include <cstddef>

std::size_t binarySearchInsertPos(const int *main, int value, std::size_t order, std::size_t bound);
	std::size_t movesLeft_to_do(std::size_t totalMoves,
	std::size_t move, std::size_t jacobsthal_diff);

#endif
