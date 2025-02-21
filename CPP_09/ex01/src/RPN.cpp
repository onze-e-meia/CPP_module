/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:20:58 by tforster          #+#    #+#             */
/*   Updated: 2025/02/21 17:38:25 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include "include/RPN.hpp"
#include "lib/color.hpp"

const	std::string::size_type NPOS = std::string::npos;

static void	isValidInput(const std::string &input) {
	std::string::size_type index = input.find_first_not_of("0123456789-+/* \t\n");
	if (index != NPOS) {
		std::ostringstream oss;
		oss << L_RED "Error: " RST "Invalid char " << "[" << input.at(index) << "]"
			<< " at position " << index;
		throw (std::runtime_error(oss.str()));
	}
}

int	RPN::plus::operator()(int top, int bellow) {return (bellow + top); };
int RPN::minus::operator()(int top, int bellow) {return (bellow - top); };
int RPN::multiplies::operator()(int top, int bellow) {return (bellow * top); };
int RPN::divides::operator()(int top, int bellow) {return (bellow / top); };

void	RPN::getOperator(const char *token) {
	switch (*token) {
		case '+': process_operation(plus(), token); break;
		case '-': process_operation(minus(), token); break;
		case '*': process_operation(multiplies(), token); break;
		case '/': process_operation(divides(), token); break;
		default:
			this->push(static_cast<int>(std::strtol(token, NULL, 10)));
	}
}

RPN::RPN(void): _input() {};

RPN::RPN(const std::string input):
	std::stack<int>(),
	_input(input) {};

RPN::RPN(const RPN &other):
	std::stack<int>(other),
	_input(other._input) {}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		std::stack<int>::operator=(other);
		_input = other._input;
	}
	return (*this);
}

RPN::~RPN(void) {}

int RPN::pop() {
			if (!this->empty()) {
				int	nb = this->top();
				std::stack<int>::pop();
				return (nb);
			}
			std::ostringstream oss;
			oss << L_RED "Error: " RST << "Stack is empty, cannot pop!";
			throw (std::runtime_error("Stack is empty, cannot pop!"));
		}

RPN::const_it	RPN::begin() const {return (this->c.begin());}
RPN::const_it	RPN::end() const {return (this->c.end());}
RPN::it			RPN::begin(){return (this->c.begin());}
RPN::it			RPN::end() {return (this->c.end());}

int	RPN::solver(void) {
	std::cout << D_BLU "INPUT string: " RST << _input << ENDL;
	try {
		isValidInput(_input);
		std::istringstream	iss(_input);
		std::string			token;
		while (iss >> token) {
			if (token.size() != 1) {
				std::ostringstream oss;
				oss << L_RED "Error: " RST "Invalid input format [" << token << "]";
				throw (std::runtime_error(oss.str()));
			}
			getOperator(token.c_str());
		}
		if (this->size() != 1) {
			std::ostringstream oss;
			oss << L_RED "Error: " RST << "Stack [" << *this << "] "
				<< "lack operators to do numbers";
			throw (std::runtime_error(oss.str()));
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
		return (NAN);
	}
	std::cout << H_GRN "Result: " RST << this->top() << ENDL;
	return (11);
}

std::ostream &operator<<(std::ostream &os, RPN &rpn) {
	RPN::it	begin = rpn.begin();
	RPN::it	end = rpn.end();
	while (begin != end) {
		os << *begin;
		++begin;
		if (begin != end)
			os << ", ";
	}
	return (os);
}

std::ostream &operator<<(std::ostream &os, const RPN &rpn) {
	RPN::const_it	begin = rpn.begin();
	RPN::const_it	end = rpn.end();
	while (begin != end) {
		os << *begin;
		++begin;
		if (begin != end)
			os << ", ";
	}
	return (os);
}
