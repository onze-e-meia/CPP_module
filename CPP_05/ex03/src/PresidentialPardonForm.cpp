/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:09:18 by tforster          #+#    #+#             */
/*   Updated: 2024/12/16 15:37:22 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include "include/AForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/Bureaucrat.hpp"
#include "lib/color.hpp"

#ifdef MSG
	const std::string	CLASS_NAME = V_BLU " - PresidentialPardonForm " RST;
#endif

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("Presidential Pardon Form", SIGN_GRADE, EXEC_GRADE),
	_target("poor bastard") {
		#ifdef MSG
			cnstr_msg(CLASS_NAME, "Default constructor");
		#endif
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm("Presidential Pardon Form", SIGN_GRADE, EXEC_GRADE),
	_target(target) {
		#ifdef MSG
			cnstr_msg(CLASS_NAME, "Parametric constructor");
		#endif
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
	AForm(other),
	_target(other._target) {
		#ifdef MSG
			cnstr_msg(CLASS_NAME, "Copy constructor");
		#endif
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
		AForm::operator=(other);
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Assigment operator");
	#endif
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, L_RED "Destructor" RST);
	#endif
}

std::string	PresidentialPardonForm::getTarget(void) const {
	return (_target);
}

void	PresidentialPardonForm::outputStream(std::ostream &os) const {
	os << this->getName()
		<< ", sign grade: " << this->getSignGrade()
		<< ", execute grade: " << this->getExecuteGrade()
		<< ", target: " << _target
		<< ", signed: " << (this->getSigned() ? "yes" : "no");
}

void	PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const {
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
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." ENDL;
}

PresidentialPardonForm::FileException::FileException(const std::string &exceptionStr):
	_exceptionStr(exceptionStr) {}

PresidentialPardonForm::FileException::~FileException(void)  throw() {}

const char	*PresidentialPardonForm::FileException::what(void)  const throw() {
	return (_exceptionStr.c_str());
}
