/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:20:58 by tforster          #+#    #+#             */
/*   Updated: 2025/04/08 15:19:01 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
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
			<< " at position " << index << ENDL
			<< L_RED "Invalid Result!" RST;
		throw (std::runtime_error(oss.str()));
	}
}

int	RPN::plus::operator()(int left, int right) {return (left + right); };
int RPN::minus::operator()(int left, int right) {return (left - right); };
int RPN::multiplies::operator()(int left, int right) {return (left * right); };
int RPN::divides::operator()(int left, int right) {
	if (right == 0) {
		std::ostringstream	oss;
		oss << L_RED "Error: " RST "Division by 0 {" << left << "/" << right << "}" ENDL
			<< L_RED "Invalid Result!" RST;
		throw (std::runtime_error(oss.str()));
	}
	return (left / right);
};

void	RPN::getOperator(const char *token) {
	switch (*token) {
		case '+': process_operation(plus(), token); break;
		case '-': process_operation(minus(), token); break;
		case '*': process_operation(multiplies(), token); break;
		case '/': process_operation(divides(), token); break;
		default : push(*token - '0');
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

RPN::const_it	RPN::begin() const {return (c.begin());}
RPN::const_it	RPN::end() const {return (c.end());}
RPN::it			RPN::begin(){return (c.begin());}
RPN::it			RPN::end() {return (c.end());}

int	RPN::solver(void) {
	std::cout << D_BLU "INPUT string: " RST << _input << ENDL;
	try {
		isValidInput(_input);
		std::istringstream	iss(_input);
		std::string			token;
		while (iss >> token) {
			if (token.size() != 1) {
				std::ostringstream oss;
				oss << L_RED "Error: " RST "Invalid input format [" << token << "]" ENDL
					<< L_RED "Invalid Result!" RST;
				throw (std::runtime_error(oss.str()));
			}
			getOperator(token.c_str());
		}
		if (size() != 1) {
			std::ostringstream oss;
			oss << L_RED "Error: " RST << "Stack [" << *this << "] "
				<< "lack operators to do numbers" ENDL
				<< L_RED "Invalid Result!" RST;
			throw (std::runtime_error(oss.str()));
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
		return (INT_MIN);
	}
	return (top());
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
