/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:32:01 by tforster          #+#    #+#             */
/*   Updated: 2024/12/16 15:26:12 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include "include/AForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/Bureaucrat.hpp"
#include "lib/color.hpp"

#ifdef MSG
	const std::string	CLASS_NAME = H_MGT " - RobotomyRequestForm " RST;
#endif

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("Robotomy Request Form", SIGN_GRADE, EXEC_GRADE),
	_target("poor bastard") {
		#ifdef MSG
			cnstr_msg(CLASS_NAME, "Default constructor");
		#endif
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm("Robotomy Request Form", SIGN_GRADE, EXEC_GRADE),
	_target(target) {
		#ifdef MSG
			cnstr_msg(CLASS_NAME, "Parametric constructor");
		#endif
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
	AForm(other),
	_target(other._target) {
		#ifdef MSG
			cnstr_msg(CLASS_NAME, "Copy constructor");
		#endif
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other)
		AForm::operator=(other);
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Assigment operator");
	#endif
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, L_RED "Destructor" RST);
	#endif
}

std::string	RobotomyRequestForm::getTarget(void) const {
	return (_target);
}

void	RobotomyRequestForm::outputStream(std::ostream &os) const {
	os << this->getName()
		<< ", sign grade: " << this->getSignGrade()
		<< ", execute grade: " << this->getExecuteGrade()
		<< ", target: " << _target
		<< ", signed: " << (this->getSigned() ? "yes" : "no");
}

void	RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const {
	if (!this->getSigned()) {
		throw SignedException(L_RED "Exception:" RST " Form NOT signed" ENDL);
	}
	if (bureaucrat.getGrade() > this->getExecuteGrade()) {
		std::ostringstream	oss;
		oss << bureaucrat.getName() << " couldn't execute " << this->getName() <<
			" (" << this->getExecuteGrade() << ")" ENDL
			L_RED "Exception:" RST " Bureaucrat grade too low (" << bureaucrat.getGrade() << ") to execute" ENDL;
		throw GradeTooLowException(oss.str());
	}
	std::cout << "BRRRZZZZZZZZZTTT" ENDL
		"KLUNK-KLUNK-KLUNK" ENDL
		"VRRRRRRRRRRRRMMMMM" ENDL;
	if (std::rand() % 100 % 2 == 0) {
		std::cout << _target << " has been successfully robotomized" ENDL;
	}
	else
		std::cout << "Robotomy of " << _target << " failed" ENDL;
}

RobotomyRequestForm::FileException::FileException(const std::string &exceptionStr):
	_exceptionStr(exceptionStr) {}

RobotomyRequestForm::FileException::~FileException(void)  throw() {}

const char	*RobotomyRequestForm::FileException::what(void)  const throw() {
	return (_exceptionStr.c_str());
}
