/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:37:35 by tforster          #+#    #+#             */
/*   Updated: 2024/12/12 21:23:06 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class	Form {
	private:
		static const int	MAX_GRADE = 1;
		static const int	MIN_GRADE = 150;
		const std::string	_name;
		const int			_signGrade;
		const int			_executeGrade;
		bool				_signed;

		#ifdef MSG
			void	cnstr_msg(std::string class_name, std::string str) const;
		#endif

	public:
		Form(void);
		Form(const std::string &name, const int &signGrade, const int &executeGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form(void);

		std::string	getName(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;
		bool		getSigned(void) const;

		void		beSigned(Bureaucrat &bureaucrat);

	class	GradeTooHighException: public std::exception {
		private:
			std::string	_exceptionStr;

		public:
			GradeTooHighException(const std::string &exceptionStr);
			~GradeTooHighException(void) throw();

			const char *what(void) const throw();
	};

	class	GradeTooLowException: public std::exception {
		private:
			std::string	_exceptionStr;

		public:
			GradeTooLowException(const std::string &exceptionStr);
			~GradeTooLowException(void) throw();

		public:
			const char *what(void) const throw();
	};

	class	AlreadySigned: public std::exception {
		public:
			const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &other);

#endif
