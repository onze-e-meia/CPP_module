/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:17:16 by tforster          #+#    #+#             */
/*   Updated: 2024/11/30 17:23:52 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <cstddef>
#include <iostream>
#include "include/Brain.hpp"
#include "lib/color.hpp"

const std::string CLASS_NAME = H_YLW " - Brain" RST;

void	Brain::copy_ideas(const Brain &other) {
	_index = other._index;
	for (std::size_t i = 0; i < _brainSize; i++)
		_ideas[i] = other._ideas[i];
}

Brain::Brain(void): _index(0) {
	std::cout << CLASS_NAME << " default " H_BLU "constructor." RST ENDL;
}

Brain::Brain(const Brain &other) {
	copy_ideas(other);
	std::cout << CLASS_NAME << " copy constructor." ENDL;
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other)
		copy_ideas(other);
	std::cout << CLASS_NAME << " copy assignment operator." ENDL;
	return (*this);
}

Brain::~Brain(void) {
	std::cout << CLASS_NAME << " default " H_RED "destructor." RST ENDL;
}
