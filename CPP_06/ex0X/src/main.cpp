/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:32:04 by tforster          #+#    #+#             */
/*   Updated: 2024/12/16 19:33:29 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <exception>
#include "include/Bureaucrat.hpp"
#include "include/Intern.hpp"
#include "include/AForm.hpp"
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

	std::cout << BOLD COP "Try to make invalid form with intern:" RST ENDL;
	Intern	*intern = new Intern();

	try {
		AForm *form;
		form = intern->makeForm("Randon", "target");
	}catch (std::exception &e) {
		std::cerr << e.what();
	}

	try {
		AForm *form;
		form = intern->makeForm("", "target");
	}catch (std::exception &e) {
		std::cerr << e.what();
	}

	std::cout << ENDL BOLD COP "Make valid form with intern:" RST ENDL;
	AForm *shrubbery = intern->makeForm("shrubbery creation", "Marvin");
	std::cout << *shrubbery << ENDL;
	AForm *robotomy = intern->makeForm("robotomy request", "Marvin");
	std::cout << *robotomy << ENDL;
	AForm *presidential = intern->makeForm("presidential pardon", "Marvin");
	std::cout << *presidential << ENDL;

	std::cout << ENDL BOLD COP "Make Bureaucrat sign and execute:" RST ENDL;
	Bureaucrat *low = new Bureaucrat();
	std::cout << *low << ENDL;
	Bureaucrat *high = new Bureaucrat("Zaphod Beeblebrox", 1);
	std::cout << *high << ENDL;

	std::cout << ENDL COP "shrubbery creation" RST ENDL;
	low->signFrom(*shrubbery);
	high->signFrom(*shrubbery);
	std::cout << *shrubbery << ENDL;
	low->executeForm(*shrubbery);
	high->executeForm(*shrubbery);

	std::cout << ENDL COP "robotomy request" RST ENDL;
	low->signFrom(*robotomy);
	high->signFrom(*robotomy);
	std::cout << *robotomy << ENDL;
	low->executeForm(*robotomy);
	high->executeForm(*robotomy);

	std::cout << ENDL COP "presidential pardon" RST ENDL;
	low->signFrom(*presidential);
	high->signFrom(*presidential);
	std::cout << *presidential << ENDL;
	low->executeForm(*presidential);
	high->executeForm(*presidential);

	#ifdef MSG
		std::cout << ENDL;
		std::cout << BOLD COP "Manual " ITALIC "delete." RST ENDL;
	#endif

	delete intern;
	delete shrubbery;
	delete robotomy;
	delete presidential;
	delete low;
	delete high;

	#ifdef MSG
		std::cout << ENDL;
		std::cout << BOLD COP "Automatic " ITALIC "delete." RST ENDL;
	#endif
	return (EXIT_SUCCESS);
}

#ifdef MSG
static void	test_constructors(void) {
	{
		std::cout << BOLD COP "Intern constructors test:" RST ENDL;
		Intern	intern_00;
		std::cout << intern_00 << ENDL;
		Intern	intern_01(intern_00);
		std::cout << intern_01 << ENDL;
		Intern	intern_02;
		intern_02 = intern_00;
		std::cout << intern_02 << ENDL;
	}
	std::cout << ENDL;
}
#endif
