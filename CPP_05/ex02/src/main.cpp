/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:32:04 by tforster          #+#    #+#             */
/*   Updated: 2024/12/16 15:45:33 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
// #include <exception>
#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "lib/color.hpp"

#ifdef MSG
	static void	test_constructors(void);
#endif

int	main(void) {
	system("clear");
	std::srand(static_cast<unsigned int>(std::time(0)));

	#ifdef MSG
		test_constructors();
	#endif

	std::cout << ENDL BOLD COP "Create 5 Bureaucrat:" RST ENDL;
	const std::size_t NB_BRCRT = 5;
	Bureaucrat	*brcrt[5];
	brcrt[0] = new Bureaucrat();
	std::cout << *brcrt[0] << ENDL;
	brcrt[1] = new Bureaucrat("Floyd Frustration", 100);
	std::cout << *brcrt[1] << ENDL;
	brcrt[2] = new Bureaucrat("Sally Stamp", 50);
	std::cout << *brcrt[2] << ENDL;
	brcrt[3] = new Bureaucrat("Willie Bureau", 6);
	std::cout << *brcrt[3] << ENDL;
	brcrt[4] = new Bureaucrat("Zaphod Beeblebrox", 1);
	std::cout << *brcrt[4] << DENDL;

	std::cout << BOLD COP "Make Bureaucrats sign Shrubbery Creation Form:" RST ENDL;
	ShrubberyCreationForm	shrubbery;
	std::cout << shrubbery << ENDL;
	std::cout << COP "Try to sign form" RST ENDL;
	brcrt[0]->signFrom(shrubbery);
	std::cout << COP "Try to execute form without sign" RST ENDL;
	brcrt[1]->executeForm(shrubbery);
	std::cout << COP "Sign form" RST ENDL;
	brcrt[1]->signFrom(shrubbery);
	std::cout << shrubbery << ENDL;
	std::cout << COP "Try to execute signed form" RST ENDL;
	brcrt[0]->executeForm(shrubbery);
	brcrt[1]->executeForm(shrubbery);
	std::cout << ENDL;

	std::cout << BOLD COP "Make Bureaucrats sign Robotomy Request Form:" RST ENDL;
	RobotomyRequestForm	robotomy;
	std::cout << robotomy << ENDL;
	std::cout << COP "Try to sign form" RST ENDL;
	brcrt[1]->signFrom(robotomy);
	std::cout << COP "Try to execute form without sign" RST ENDL;
	brcrt[2]->executeForm(robotomy);
	std::cout << COP "Sign form" RST ENDL;
	brcrt[2]->signFrom(robotomy);
	std::cout << robotomy << ENDL;
	std::cout << COP "Try to execute signed form" RST ENDL;
	brcrt[2]->executeForm(robotomy);
	brcrt[3]->executeForm(robotomy);
	brcrt[3]->executeForm(robotomy);
	std::cout << ENDL;

	std::cout << BOLD COP "Make Bureaucrats sign Presidential Pardon Form:" RST ENDL;
	PresidentialPardonForm	presidential;
	std::cout << presidential << ENDL;
	std::cout << COP "Try to sign form" RST ENDL;
	brcrt[2]->signFrom(presidential);
	std::cout << COP "Try to execute form without sign" RST ENDL;
	brcrt[4]->executeForm(presidential);
	std::cout << COP "Sign form" RST ENDL;
	brcrt[3]->signFrom(presidential);
	std::cout << presidential << ENDL;
	std::cout << COP "Try to execute signed form" RST ENDL;
	brcrt[2]->executeForm(presidential);
	brcrt[3]->executeForm(presidential);
	brcrt[4]->executeForm(presidential);
	std::cout << ENDL;




	#ifdef MSG
		std::cout << BOLD COP "Manual " ITALIC "delete." RST ENDL;
	#endif

	for (std::size_t i = 0; i < NB_BRCRT; i++) {
		delete brcrt[i];
	}

	#ifdef MSG
		std::cout << ENDL;
		std::cout << BOLD COP "Automatic " ITALIC "delete." RST ENDL;
	#endif
	return (EXIT_SUCCESS);
}


#ifdef MSG
static void	test_constructors(void) {
	{
		std::cout << BOLD COP "Shrubbery Creation Form constructors test:" RST ENDL;
		ShrubberyCreationForm	form_00;
		std::cout << form_00 << ENDL;
		ShrubberyCreationForm	form_01("Florbex_7");
		std::cout << form_01 << ENDL;
		ShrubberyCreationForm	form_02(form_01);
		std::cout << form_02 << ENDL;
		ShrubberyCreationForm	form_03;
		form_03 = form_00;
		std::cout << form_03 << ENDL;
	}

	{
		std::cout << ENDL BOLD COP "Robotomy Request Form constructors test:" RST ENDL;
		RobotomyRequestForm	form_00;
		std::cout << form_00 << ENDL;
		RobotomyRequestForm	form_01("some one");
		std::cout << form_01 << ENDL;
		RobotomyRequestForm	form_02(form_01);
		std::cout << form_02 << ENDL;
		RobotomyRequestForm	form_03;
		form_03 = form_00;
		std::cout << form_03 << ENDL;
	}

	{
		std::cout << ENDL BOLD COP "Presidential Pardon Form constructors test:" RST ENDL;
		PresidentialPardonForm	form_00;
		std::cout << form_00 << ENDL;
		PresidentialPardonForm	form_01("some one");
		std::cout << form_01 << ENDL;
		PresidentialPardonForm	form_02(form_01);
		std::cout << form_02 << ENDL;
		PresidentialPardonForm	form_03;
		form_03 = form_00;
		std::cout << form_03 << ENDL;
	}
}
#endif
