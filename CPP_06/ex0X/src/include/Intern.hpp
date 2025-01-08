/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:52:12 by tforster          #+#    #+#             */
/*   Updated: 2024/12/16 18:33:41 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>

class	AForm;

class	Intern {
	#ifdef MSG
		private:
			void	cnstr_msg(std::string class_name, std::string str) const;
	#endif

	public:
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern(void);

		AForm 			*makeForm(const std::string &form, const std::string &target);

	class	FormException: public std::exception {
		private:
			std::string	_exceptionStr;

		public:
			FormException(const std::string &exceptionStr);
			~FormException(void) throw();

			const char *what(void) const throw();
	};

};

std::ostream &operator<<(std::ostream &os, const Intern &intern);

#endif
