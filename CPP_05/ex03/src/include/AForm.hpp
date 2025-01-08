/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:37:35 by tforster          #+#    #+#             */
/*   Updated: 2024/12/13 19:22:06 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>

class Bureaucrat;

class	AForm {
	private:
		static const int	MAX_GRADE = 1;
		static const int	MIN_GRADE = 150;
		const std::string	_name;
		const int			_signGrade;
		const int			_executeGrade;
		bool				_signed;

	#ifdef MSG
		protected:
			void	cnstr_msg(std::string class_name, std::string str) const;
	#endif

	public:
		AForm(void);
		AForm(const std::string &name, const int signGrade, const int executeGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm(void);

		std::string		getName(void) const;
		int				getSignGrade(void) const;
		int				getExecuteGrade(void) const;
		bool			getSigned(void) const;
		virtual void	outputStream(std::ostream &os) const;

		void			beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;

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

			const char *what(void) const throw();
	};

	class	SignedException: public std::exception {
		private:
			std::string	_exceptionStr;

		public:
			SignedException(const std::string &exceptionStr);
			~SignedException(void) throw();

			const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &other);

#endif
