/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:37:12 by tforster          #+#    #+#             */
/*   Updated: 2024/12/16 15:26:12 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>
#include "include/Form.hpp"
#include "include/Bureaucrat.hpp"
#include "lib/color.hpp"

#ifdef MSG
	const std::string	CLASS_NAME = TEAL " - Form " RST;

	void	Form::cnstr_msg(std::string class_name, std::string str) const {
		std::cout << class_name << str << ENDL;
	}
#endif

static int	max_grade(int signGrade, int executeGrade) {
	return (signGrade < executeGrade ? signGrade : executeGrade);
}

static std::string	max_type(int signGrade, int executeGrade) {
	return (signGrade < executeGrade ? "sign grade" : "execute grade");
}

static int	min_grade(int signGrade, int executeGrade) {
	return (signGrade > executeGrade ? signGrade : executeGrade);
}

static std::string	min_type(int signGrade, int executeGrade) {
	return (signGrade > executeGrade ? "sign grade" : "execute grade");
}

static std::string	exception_str(int grade, std::string type, std::string err) {
	std::ostringstream	oss;
	oss << L_RED "Exception:" RST " Form " << type << " too " << err << " (" << grade << ")" ENDL;
	return (oss.str());
}

Form::Form(void):
	_name("Form 404: Purpose Not Found"),
	_signGrade(150),
	_executeGrade(150),
	_signed(false) {
		#ifdef MSG
			cnstr_msg(CLASS_NAME, "Default constructor");
		#endif
	}

Form::Form(const std::string &name, const int &signGrade, const int &executeGrade):
	_name(name),
	_signGrade(signGrade),
	_executeGrade(executeGrade),
	_signed(false) {
		int	grade = max_grade(_signGrade, _executeGrade);
		std::string	type = max_type(_signGrade, _executeGrade);
		std::string	str = exception_str(grade, type, "high");
		if (signGrade < MAX_GRADE || executeGrade < MAX_GRADE) throw GradeTooHighException(str);

		grade = min_grade(_signGrade, _executeGrade);
		type = min_type(_signGrade, _executeGrade);
		str = exception_str(grade, type, "low");
		if (signGrade > MIN_GRADE || executeGrade > MIN_GRADE) throw GradeTooLowException(str);
		#ifdef MSG
			cnstr_msg(CLASS_NAME, "Parametric constructor");
		#endif
	}

Form::Form(const Form &other):
	_name(other._name),
	_signGrade(other._signGrade),
	_executeGrade(other._executeGrade),
	_signed(other._signed) {
		#ifdef MSG
			cnstr_msg(CLASS_NAME, "Copy constructor");
		#endif
 	}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		_signed = other._signed;
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Assigment operator");
	#endif
	return (*this);
}

Form::~Form(void) {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, L_RED "Destructor" RST);
	#endif
}

std::string	Form::getName(void) const {
	return (_name);
}

int	Form::getSignGrade(void) const {
	return (_signGrade);
}

int	Form::getExecuteGrade(void) const {
	return (_executeGrade);
}

bool	Form::getSigned(void) const {
	return (_signed);
}

void	Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade) {
		std::ostringstream	oss;
		oss << bureaucrat.getName() << " couldn't sign " << _name <<
			" (" << _signGrade << ")" ENDL
			L_RED "Exception:" RST " Bureaucrat grade too low (" << bureaucrat.getGrade() << ")" ENDL;
		throw GradeTooLowException(oss.str());
	}
	if (_signed) throw AlreadySigned();
	_signed = true;
}

Form::GradeTooHighException::GradeTooHighException(const std::string &exceptionStr):
	_exceptionStr(exceptionStr) {}

Form::GradeTooHighException::~GradeTooHighException(void)  throw() {}

const char *Form::GradeTooHighException::what(void) const throw() {
	return (_exceptionStr.c_str());
}

Form::GradeTooLowException::GradeTooLowException(const std::string &exceptionStr):
	_exceptionStr(exceptionStr) {}

Form::GradeTooLowException::~GradeTooLowException(void)  throw() {}

const char *Form::GradeTooLowException::what(void) const throw() {
	return (_exceptionStr.c_str());
}

const char	*Form::AlreadySigned::what(void)  const throw() {
	return (L_RED "Exception:" RST " Form already signed\n");
}

std::ostream	&operator<<(std::ostream &os, const Form &form) {
	return (os << form.getName()
		<< ", sign grade: " << form.getSignGrade()
		<< ", execute grade: " << form.getExecuteGrade()
		<< " signed: " << (form.getSigned() ? "yes" : "no"));
}
