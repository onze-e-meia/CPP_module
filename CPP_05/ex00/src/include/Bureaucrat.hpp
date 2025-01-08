/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:31:45 by tforster          #+#    #+#             */
/*   Updated: 2024/12/12 18:15:22 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>

class	Bureaucrat {
	private:
		static const int	MAX_GRADE = 1;
		static const int	MIN_GRADE = 150;
		const std::string	_name;
		int					_grade;

		#ifdef MSG
			void	cnstr_msg(std::string class_name, std::string str) const;
		#endif

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, const int &grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		std::string	getName(void) const;
		int			getGrade(void) const;

		void		increment(void);
		void		decrement(void);

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
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other);

#endif
