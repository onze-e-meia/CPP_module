/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:18:45 by tforster          #+#    #+#             */
/*   Updated: 2024/12/16 15:26:12 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>
#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "lib/color.hpp"

#ifdef MSG
	const std::string	CLASS_NAME = BRW " - Bureaucrat " RST;

	void	Bureaucrat::cnstr_msg(std::string class_name, std::string str) const {
		std::cout << class_name << str << ENDL;
	}
#endif

static std::string	exception_str(int grade, const std::string &err) {
	std::ostringstream	oss;
	oss << L_RED "Exception:" RST " Bureaucrat grade too " << err << " (" << grade << ")" ENDL;
	return (oss.str());
}

Bureaucrat::Bureaucrat(void): _name("Cogsworth"), _grade(150) {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Default constructor");
	#endif
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade):
	_name(name),
	_grade(grade) {
		if (grade < MAX_GRADE) {
			std::string	str = exception_str(grade, "high");
			throw GradeTooHighException(str);
		};
		if (grade > MIN_GRADE) {
			std::string str = exception_str(grade, "low");
			throw GradeTooLowException(str);
		}
		#ifdef MSG
			cnstr_msg(CLASS_NAME, "Parametric constructor");
		#endif
	}

Bureaucrat::Bureaucrat(const Bureaucrat &other):
	_name(other._name),
	_grade(other._grade) {
		#ifdef MSG
			cnstr_msg(CLASS_NAME, "Copy constructor");
		#endif
	}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		_grade = other._grade;
	#ifdef MSG
		cnstr_msg(CLASS_NAME, "Assigment operator");
	#endif
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {
	#ifdef MSG
		cnstr_msg(CLASS_NAME, L_RED "Destructor" RST);
	#endif
}

std::string	Bureaucrat::getName(void) const {
	return (_name);
}

int	Bureaucrat::getGrade(void) const {
	return (_grade);
}

void	Bureaucrat::increment(void) {
	if (_grade <= MAX_GRADE) {
		std::string	str = exception_str(_grade, "high to increment");
		throw GradeTooHighException(str);
	}
	_grade--;
}

void	Bureaucrat::decrement(void) {
	if (_grade >= MIN_GRADE) {
		std::string	str = exception_str(_grade, "low to decrement");
		throw GradeTooLowException(str);
	}
	_grade++;
}

void	Bureaucrat::signFrom(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << ENDL;
	} catch (std::exception &e) {
		std::cerr << e.what();
	}
}

void 	Bureaucrat::executeForm(const AForm &form) {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << ENDL;
	}catch (std::exception &e) {
		std::cerr << e.what();
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &exceptionStr):
	_exceptionStr(exceptionStr) {}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void)  throw() {}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return (_exceptionStr.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &exceptionStr):
	_exceptionStr(exceptionStr) {}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void)  throw() {}

const char	*Bureaucrat::GradeTooLowException::what(void)  const throw() {
	return (_exceptionStr.c_str());
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	return (os << bureaucrat.getName() << ", grade: " << bureaucrat.getGrade());
}
