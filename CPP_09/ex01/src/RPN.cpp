/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:20:58 by tforster          #+#    #+#             */
/*   Updated: 2025/02/19 19:22:24 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <functional>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include "include/RPN.hpp"
#include "lib/color.hpp"

const	std::string::size_type NPOS = std::string::npos;

struct plus			{ int operator()(int l, int r) {return (l + r); } };
struct minus		{ int operator()(int l, int r) {return (l - r); } };
struct multiplies	{ int operator()(int l, int r) {return (l * r); } };
struct divides		{ int operator()(int l, int r) {return (l / r); } };

static void	isValidInput(const std::string &input) {
	std::string::size_type index = input.find_first_not_of("0123456789-+/* \t\n");
	if (index != NPOS) {
		std::ostringstream oss;
		oss << "Invalid input at " << index << "[" << input.at(index) << "]";
		throw (std::runtime_error(oss.str()));
	}
}

void	RPN::getOperator(const char token) {
	switch (token) {
		case '+': process_operation(plus()); break;
		case '-': process_operation(minus()); break;
		case '*': process_operation(multiplies()); break;
		case '/': process_operation(divides()); break;
		default: {
			std::cout << " ADD to stack [" << token << "]" ENDL;
			_stack.push(static_cast<int>(std::strtol(&token, NULL, 10)));
			break;
		}
	}
}

RPN::RPN(void): _stack(), _input() {};

RPN::RPN(const std::string input):
	_stack(),
	_input(input) {};

RPN::RPN(const RPN &other):
	_stack(other._stack),
	_input(other._input) {}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		_input = other._input;
		_stack = other._stack;
	}
	return (*this);
}

RPN::~RPN(void) {}

int	RPN::solver(void) {
	std::cout << D_BLU "INPUT string: " RST << _input << ENDL;
	try {
		isValidInput(_input);
		std::istringstream	iss(_input);
		std::string			token;
		while (iss >> token) {
			if (token.size() != 1) {
				std::ostringstream oss;
				oss << "Invalid input: " << token;
				throw (std::runtime_error(oss.str()));
			}
			getOperator(token.at(0));
			// std::cout << " ADD to stack [" << token << "]" ENDL;


			// _stack.push(static_cast<int>(std::strtol(token.c_str(), NULL, 10)));

		}
		if (_stack.size() != 1) {
			std::ostringstream oss;
			oss << "Stack not empty.";
			throw (std::runtime_error(oss.str()));

		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
		return (NAN);
	}
	std::cout << "Result: [" << _stack.top() << "]" ENDL;
	return (11);
}


// ➜  ex01 git:(master) ✗ ./RPN "1 1 1 -+ +"
// Error
// ➜  ex01 git:(master) ✗ ./RPN "1 1 1 - +"
// 1
// ➜  ex01 git:(master) ✗ ./RPN "1 1 - 1 +"
// 1
// ➜  ex01 git:(master) ✗ ./RPN "1 2 - 1 +"
// 0
// ➜  ex01 git:(master) ✗ ./RPN "1 2 1 - +"
// 2
