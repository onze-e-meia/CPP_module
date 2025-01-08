/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:09:20 by tforster          #+#    #+#             */
/*   Updated: 2024/12/16 15:10:43 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <exception>
# include "AForm.hpp"

class	PresidentialPardonForm: public AForm {
	private:
		static const int	SIGN_GRADE = 25;
		static const int	EXEC_GRADE = 5;
		const std::string	_target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm(void);

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
