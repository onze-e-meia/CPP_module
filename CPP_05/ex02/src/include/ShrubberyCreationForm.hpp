/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:22:23 by tforster          #+#    #+#             */
/*   Updated: 2024/12/13 19:23:45 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <exception>
# include "AForm.hpp"

class	ShrubberyCreationForm: public AForm {
	private:
		static const int	SIGN_GRADE = 145;
		static const int	EXEC_GRADE = 137;
		const std::string	_target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm(void);

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
