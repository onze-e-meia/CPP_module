/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:32:04 by tforster          #+#    #+#             */
/*   Updated: 2024/12/13 15:26:09 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iostream>
#include <exception>
#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"
#include "lib/color.hpp"

int	main(void) {
	system("clear");

	std::cout << BOLD COP "Form constructors test:" RST ENDL;
	Bureaucrat	brcrt("Dustin Forms", 50);
	std::cout << brcrt << ENDL;
	Form	form_00;
	std::cout << form_00 << ENDL;
	Form	form_01("Application for Application Approval", 100, 100);
	Form	form_02(form_01);
	brcrt.signFrom(form_02);
	std::cout << form_01 << ENDL;
	std::cout << form_02 << ENDL;
	Form	form_03("Hugo Hold-up", 1, 1);
	std::cout << form_03 << ENDL;
	form_03 = form_02;
	std::cout << form_03 << DENDL;

	int	grade = 0;
	std::cout << BOLD COP "Try to make form with sign grade " << grade << ":" RST ENDL;
	try {
		Form	form("Form", grade, 100);
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}
	std::cout << BOLD COP "Try to make form with execute grade " << grade << ":" RST ENDL;
	try {
		Form	form("Form", 100, grade);
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}

	grade = -2;
	std::cout << BOLD COP "Try to make form with sign grade " << grade << ":" RST ENDL;
	try {
		Form	form("Form", grade, 100);
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}
	std::cout << BOLD COP "Try to make form with execute grade " << grade << ":" RST ENDL;
	try {
		Form	form("Form", 100, grade);
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}

	grade = 151;
	std::cout << BOLD COP "Try to make form with sign grade " << grade << ":" RST ENDL;
	try {
		Form	form("Form", grade, 100);
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}
	std::cout << BOLD COP "Try to make form with execute grade " << grade << ":" RST ENDL;
	try {
		Form	form("Form", 100, grade);
	} catch (const std::exception &e) {
		std::cerr << e.what() << ENDL;
	}

	int b_grade = 100;
	int f_grade = 75;
	std::cout << BOLD COP "Make Bureaucrat " << b_grade << " sign form " << f_grade << ":" RST ENDL;
	{
		Bureaucrat	brcrt("Connie Congestion", b_grade);
		std::cout << brcrt << ENDL;
		Form		form("Request to Review a Previously Rejected Request", f_grade, 100);
		std::cout << form << ENDL;
		std::cout << COP "Try to sign form" RST ENDL;
		brcrt.signFrom(form);
		// form.beSigned(brcrt);
	}
	std::cout << ENDL;

	b_grade = 150;
	f_grade = 150;
	std::cout << BOLD COP "Make Bureaucrat sign signed form:" RST ENDL;
	{
		Bureaucrat	brcrt_00("Patty Paperwork", b_grade);
		std::cout << brcrt_00 << ENDL;
		Bureaucrat	brcrt_01("Timmy Delay", b_grade);
		std::cout << brcrt_01 << ENDL;
		Form		form("General Redundancy Acknowledgment", f_grade, 100);
		std::cout << form << ENDL;
		std::cout << COP "Try to sign form" RST ENDL;
		brcrt_00.signFrom(form);
		// form.beSigned(brcrt_00);
		std::cout << form << ENDL;
		std::cout << COP "Try to sign form again" RST ENDL;
		brcrt_01.signFrom(form);
		// form.beSigned(brcrt_01);
	}
	std::cout << ENDL;

	b_grade = 11;
	f_grade = 11;
	std::cout << BOLD COP "Make Bureaucrat " << b_grade << " sign form " << f_grade << ":" RST ENDL;
	{
		Bureaucrat	brcrt("Alfred Waitmore", b_grade);
		std::cout << brcrt << ENDL;
		Form		form("Inquiry Into Lost Paperwork", f_grade, 100);
		std::cout << form << ENDL;
		std::cout << COP "Try to sign form" RST ENDL;
		brcrt.signFrom(form);
		// form.beSigned(brcrt);
		std::cout << form << ENDL;
	}
	std::cout << ENDL;

	b_grade = 111;
	f_grade = 109;
	std::cout << BOLD COP "Increment Bureaucrat " << b_grade << " to sign form " << f_grade << ":" RST ENDL;
	{
		Bureaucrat	brcrt("Barney Backlog", b_grade);
		std::cout << brcrt << ENDL;
		std::cout << COP "Increment 4x" RST ENDL;
		brcrt.increment(); brcrt.increment(); brcrt.increment(); brcrt.increment();
		std::cout << brcrt << ENDL;
		Form		form("Prolonged Approval Authorization", f_grade, 100);
		std::cout << form << ENDL;
		std::cout << COP "Try to sign form" RST ENDL;
		brcrt.signFrom(form);
		// form.beSigned(brcrt);
		std::cout << form << ENDL;
	}
	std::cout << ENDL;

	#ifdef MSG
		std::cout << BOLD COP "Automatic " ITALIC "delete." RST ENDL;
	#endif
	return (EXIT_SUCCESS);
}
