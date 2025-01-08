/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:51:52 by tforster          #+#    #+#             */
/*   Updated: 2024/12/16 19:31:13 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <string>
#include <iostream>
#include "include/Intern.hpp"
#include "include/AForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "lib/color.hpp"


#ifdef MSG
	const std::string	CLASS_NAME = ORG " - Intern " RST;

	void	Intern::cnstr_msg(std::string class_name, std::string str) const {
		std::cout << class_name << str << ENDL;
	}
#endif

Intern::Intern(void) {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Default constructor");
	#endif
}

Intern::Intern(const Intern &other) {
	(void)other;
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Copy constructor");
	#endif
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Assigment operator");
	#endif
	return (*this);
}

Intern::~Intern(void) {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, L_RED "Destructor" RST);
	#endif
}

static AForm *robotomyRequest(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

static AForm *shrubberyRequest(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

static AForm *presidentialRequest(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

typedef AForm *(*pickForm)(const std::string &target);

AForm *Intern::makeForm(const std::string &form, const std::string &target) {
	static const pickForm func[3] = {
		&robotomyRequest,
		&shrubberyRequest,
		&presidentialRequest
	};

	static const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; ++i) {
		if (form == formNames[i]) {
			std::cout << "Intern creates " << form << " form" ENDL;
			return func[i](target);
		}
	}
	std::ostringstream oss;
	oss <<  L_RED "Exception: " RST "Form " << form << " not found" ENDL;
	throw FormException(oss.str());

}

Intern::FormException::FormException(const std::string &exceptionStr):
	_exceptionStr(exceptionStr) {}

Intern::FormException::~FormException(void)  throw() {}

const char	*Intern::FormException::what(void) const throw() {
	return (_exceptionStr.c_str());
}

std::ostream	&operator<<(std::ostream &os, const Intern &intern) {
	(void)intern;
	return (os << "Nameless Intern address: " << &intern);
}
