/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:15:56 by tforster          #+#    #+#             */
/*   Updated: 2024/11/28 14:45:56 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

# define FIELD_COUNT	5

extern const		std::string PROMPTS[FIELD_COUNT];

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:
		// Default constructor
		Contact();

		// Copy constructor
		Contact(const Contact& obj);

		// Assignment operator
		Contact& operator=(const Contact& other);

		// Destructor
		~Contact();

		// Setter methods
		void		set_fisrtName(const std::string &fisrtName);
		void		set_lastName(const std::string &lastName);
		void		set_nickName(const std::string &nickName);
		void		set_phoneNumber(const std::string &phoneNumber);
		void		set_darkestSecret(const std::string &darkestSecret);

		typedef void			(Contact::*ContactSetter)(const std::string&);
		static ContactSetter	setters[FIELD_COUNT];

		// Getter methods
		std::string	get_firsteName(void) const;
		std::string	get_lastName(void) const;
		std::string	get_nickName(void) const;
		std::string	get_phoneNumber(void) const;
		std::string	get_darkestSecret(void) const;

		typedef std::string		(Contact::*ContactGetter)(void) const;
		static ContactGetter	getters[FIELD_COUNT];
};

#endif
