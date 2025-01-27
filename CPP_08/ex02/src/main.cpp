/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:16:48 by tforster          #+#    #+#             */
/*   Updated: 2025/01/27 19:07:11 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "include/MutantStack.hpp"
#include "lib/color.hpp"

#define PRINT_TEST(test)	std::cout << ENDL BOLD COP << test << RENDL

int	main(void) {
	std::system("clear");

	{
		PRINT_TEST("Creata a default stack (deque) of int:");
		MutantStack<int>	stack;
		std::cout << "-> Check contents: " ENDL
			<< D_BLU "Empty: " RST << stack.empty() << ENDL
			<< D_BLU "Size: " RST << stack.size() << ENDL
			<< "-> Push 111, 25, 42, -7, 0 and check contents:: " ENDL;
		stack.push(111); stack.push(25); stack.push(42); stack.push(-7); stack.push(0);
		std::cout << D_BLU "Empty: " RST << stack.empty() << ENDL
			<< D_BLU "Size: " RST << stack.size() << ENDL
			<< "-> Print stack:" ENDL;
		print_stack(stack, false);
		std::cout << "-> Print reverse stack:" ENDL;
		print_stack(stack, true);
		std::cout << "-> Check top element:" ENDL
			<< D_BLU "Top: " RST << stack.top() << ENDL;
		stack.pop();
		std::cout << "-> Pop top element:" ENDL
			<< D_BLU "Top: " RST << stack.top() << ENDL
			<< "-> Copy and print const stack:" ENDL;
		const MutantStack<int>	c_stack(stack);
		print_stack(c_stack, false);
	}

	{
		PRINT_TEST("Creata a stack (vector) of char:");
		MutantStack<char, std::vector<char> >	stack;
		std::cout << "-> Check contents: " ENDL
			<< D_BLU "Empty: " RST << stack.empty() << ENDL
			<< D_BLU "Size: " RST << stack.size() << ENDL
			<< "-> Push a, *, ~, Z, n and check contents:: " ENDL;
		stack.push('a'); stack.push('*'); stack.push('~'); stack.push('Z'); stack.push('n');
		std::cout << D_BLU "Empty: " RST << stack.empty() << ENDL
			<< D_BLU "Size: " RST << stack.size() << ENDL
			<< "-> Print stack:" ENDL;
		print_stack(stack, false);
		std::cout << "-> Print reverse stack:" ENDL;
		print_stack(stack, true);
		std::cout << "-> Check top element:" ENDL
			<< D_BLU "Top: " RST << stack.top() << ENDL;
		stack.pop();
		std::cout << "-> Pop top element:" ENDL
			<< D_BLU "Top: " RST << stack.top() << ENDL
			<< "-> Copy and print const stack:" ENDL;
		const MutantStack<char, std::vector<char> >	c_stack(stack);
		print_stack(c_stack, false);
	}

	{
		PRINT_TEST("Creata a stack (list) of string:");
		MutantStack<std::string, std::list<std::string> >	stack;
		std::cout << "-> Check contents: " ENDL
			<< D_BLU "Empty: " RST << stack.empty() << ENDL
			<< D_BLU "Size: " RST << stack.size() << ENDL
			<< "-> Push Fisrt, Second, Last and check contents:: " ENDL;
		stack.push("Fisrt"); stack.push("Second"); stack.push("Last");
		std::cout << D_BLU "Empty: " RST << stack.empty() << ENDL
			<< D_BLU "Size: " RST << stack.size() << ENDL
			<< "-> Print stack:" ENDL;
		print_stack(stack, false);
		std::cout << "-> Print reverse stack:" ENDL;
		print_stack(stack, true);
		std::cout << "-> Check top element:" ENDL
			<< D_BLU "Top: " RST << stack.top() << ENDL;
		stack.pop();
		std::cout << "-> Pop top element:" ENDL
			<< D_BLU "Top: " RST << stack.top() << ENDL
			<< "-> Copy and print const stack:" ENDL;
		const MutantStack<std::string, std::list<std::string> >	c_stack(stack);
		print_stack(c_stack, false);
	}

	return (EXIT_SUCCESS);
}
