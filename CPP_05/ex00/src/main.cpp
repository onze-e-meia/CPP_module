/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:32:04 by tforster          #+#    #+#             */
/*   Updated: 2024/12/16 15:30:12 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <exception>
#include "include/Bureaucrat.hpp"
#include "lib/color.hpp"

static void	decrement_loop(Bureaucrat &brcrt);
static void	increment_loop(Bureaucrat &brcrt);

int	main(void) {
	system("clear");

	std::cout << BOLD COP "Constructors test:" RST ENDL;
	Bureaucrat	brcrt_00;
	std::cout << brcrt_00 << ENDL;
	Bureaucrat	brcrt_01("Nina Nonsense", 100);
	std::cout << brcrt_01 << ENDL;
	Bureaucrat	brcrt_02(brcrt_01);
	std::cout << brcrt_02 << ENDL;
	brcrt_01.increment();
	brcrt_02.decrement();
	std::cout << brcrt_01 << ENDL;
	std::cout << brcrt_02 << ENDL;
	Bureaucrat	brcrt_03("Hugo Hold-up", 1);
	std::cout << brcrt_03 << ENDL;
	brcrt_03 = brcrt_00;
	std::cout << brcrt_03 << DENDL;

	int	grade = 0;
	std::cout << BOLD COP "Try to make Bureaucrat with grade " << grade << ":" RST ENDL;
	try {
		Bureaucrat	brcrt("N", grade);
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}

	grade = -2;
	std::cout << BOLD COP "Try to make Bureaucrat with grade " << grade << ":" RST ENDL;
	try {
		Bureaucrat	brcrt("N", grade);
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}

	grade = 151;
	std::cout << BOLD COP "Try to make Bureaucrat with grade " << grade << ":" RST ENDL;
	try {
		Bureaucrat	brcrt("N", grade);
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}

	grade = 148;
	std::cout << BOLD COP "Try to make Bureaucrat with grade " << grade << " and decrement it" RST ENDL;
	try {
		Bureaucrat	brcrt("Ronnie Redundant", grade);
		std::cout << brcrt << ENDL;
		decrement_loop(brcrt);
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}

	grade = 3;
	std::cout << BOLD COP "Try to make Bureaucrat with grade " << grade << " and increment it" RST ENDL;
	try {
		Bureaucrat	brcrt("Floyd Frustration", grade);
		std::cout << brcrt << ENDL;
		increment_loop(brcrt);
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}

	grade = 1;
	std::cout << BOLD COP "Try to make Bureaucrat with grade " << grade << RST ENDL;
	try {
		Bureaucrat	brcrt("Floyd Frustration", grade);
		std::cout << brcrt << DENDL;
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}

	#ifdef MSG
		std::cout << BOLD COP "Automatic " ITALIC "delete." RST ENDL;
	#endif

	return (EXIT_SUCCESS);
}

static void	decrement_loop(Bureaucrat &brcrt) {
	while (true) {
		brcrt.decrement();
		std::cout << brcrt << ENDL;
	}
}

static void	increment_loop(Bureaucrat &brcrt) {
	while (true) {
		brcrt.increment();
		std::cout << brcrt << ENDL;
	}
}
