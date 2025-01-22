/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:32:04 by tforster          #+#    #+#             */
/*   Updated: 2025/01/22 14:57:23 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <exception>
# include "AForm.hpp"

class	RobotomyRequestForm: public AForm {
	private:
		static const int	SIGN_GRADE = 72;
		static const int	EXEC_GRADE = 45;
		const std::string	_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm(void);

		std::string	getTarget(void) const;
		void		outputStream(std::ostream &os) const;

		void		execute(Bureaucrat const &executor) const;

	class	FileException: public std::exception {
		private:
			std::string	_exceptionStr;

		public:
			FileException(const std::string &exceptionStr);
			~FileException(void) throw();

			const char *what(void) const throw();
	};
};

#endif
