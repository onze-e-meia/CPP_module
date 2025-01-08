/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:22:25 by tforster          #+#    #+#             */
/*   Updated: 2024/12/16 15:26:12 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "include/AForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/Bureaucrat.hpp"
#include "lib/color.hpp"

#ifdef MSG
	const std::string	CLASS_NAME = H_GRN " - ShrubberyCreationForm " RST;
#endif

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("Shrubbery Creation Form", SIGN_GRADE, EXEC_GRADE),
	_target("just_another_file") {
		#ifdef MSG
			cnstr_msg(CLASS_NAME, "Default constructor");
		#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm("Shrubbery Creation Form", SIGN_GRADE, EXEC_GRADE),
	_target(target) {
		#ifdef MSG
			cnstr_msg(CLASS_NAME, "Parametric constructor");
		#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
	AForm(other),
	_target(other._target) {
		#ifdef MSG
			cnstr_msg(CLASS_NAME, "Copy constructor");
		#endif
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		AForm::operator=(other);
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Assigment operator");
	#endif
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, L_RED "Destructor" RST);
	#endif
}

std::string	ShrubberyCreationForm::getTarget(void) const {
	return (_target);
}

void	ShrubberyCreationForm::outputStream(std::ostream &os) const {
	os << this->getName()
		<< ", sign grade: " << this->getSignGrade()
		<< ", execute grade: " << this->getExecuteGrade()
		<< ", target: " << _target
		<< ", signed: " << (this->getSigned() ? "yes" : "no");
}

void	ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const {
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
	const std::string	fileName(_target + "_shrubbery");
	if (std::ifstream(fileName.c_str())) {
		throw FileException(L_RED "Exception:" RST " File (" + fileName + ") already exist" ENDL);
	}
	std::ofstream	ofs(fileName.c_str());
	if (!ofs) {
		throw FileException(L_RED "Exception:" RST " Failed to write to file (" + fileName + ")" ENDL);
	}
	ofs <<	"         _____" 			ENDL
			"       _/o   o\\_"			ENDL
			"     _/o   Y   o\\_"		ENDL
			"    //|o   |   o|\\\\"		ENDL
			"   ///| 42 |Life|\\\\\\"	ENDL
			"   ||||____|____||||"		ENDL
			"   ||||~~~~|~~~~||||"		ENDL
			"    \\\\\\   _|_   ///"	ENDL
			"      \\_ /_|_\\ _/"		ENDL
			"       _/     \\_"			ENDL
			"      (_ DON'T _)"			ENDL
			"        |PANIC|"			ENDL;
}

ShrubberyCreationForm::FileException::FileException(const std::string &exceptionStr):
	_exceptionStr(exceptionStr) {}

ShrubberyCreationForm::FileException::~FileException(void)  throw() {}

const char	*ShrubberyCreationForm::FileException::what(void)  const throw() {
	return (_exceptionStr.c_str());
}
