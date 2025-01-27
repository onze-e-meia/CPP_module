/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:15:43 by tforster          #+#    #+#             */
/*   Updated: 2025/01/27 19:12:01 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTESTACK_HPP
# define MUTANTESTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include "../lib/color.hpp"

template<typename Type, typename Cnt = std::deque<Type> >
class MutantStack: public std::stack<Type, Cnt> {
	private:

	public:
		MutantStack(void) {}
		MutantStack(const MutantStack<Type> &other): std::stack<Type>(other) {}
		MutantStack &operator=(const MutantStack<Type> &other) {
			if (this != &other)
				std::stack<Type>::operator=(other);
			return (*this);
		}
		~MutantStack(void) {}

	typedef typename std::stack<Type, Cnt>::container_type::const_iterator			const_it;
	typedef typename std::stack<Type, Cnt>::container_type::const_reverse_iterator	const_rit;
	typedef typename std::stack<Type, Cnt>::container_type::iterator				it;
	typedef typename std::stack<Type, Cnt>::container_type::reverse_iterator		rit;

	const_it	begin() const {return (this->c.begin());}
	const_it	end() const {return (this->c.end());}
	it			begin(){return (this->c.begin());}
	it			end() {return (this->c.end());}

	const_rit	rbegin() const {return this->c.rbegin();}
	const_rit	rend() const {return this->c.rend();}
	rit			rbegin() {return this->c.rbegin();}
	rit			rend() {return this->c.rend();}
};

// Helper Functions:
template <typename It>
void print_stack(It begin, It end) {
	std::cout << D_BLU "Stack: " RST "[";
	while (begin != end) {
		std::cout << *begin;
		++begin;
		if (begin != end)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

template <typename Type, typename Cnt>
void print_stack(const MutantStack<Type, Cnt> &stack, bool reverse = false) {
	if (reverse)
		print_stack<typename std::stack<Type, Cnt>::container_type::const_reverse_iterator>
			(stack.rbegin(), stack.rend());
	else
		print_stack<typename std::stack<Type, Cnt>::container_type::const_iterator>
			(stack.begin(), stack.end());
}

#endif
