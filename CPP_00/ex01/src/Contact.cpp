/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:52:22 by tforster          #+#    #+#             */
/*   Updated: 2024/10/12 13:03:32 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

const std::string	PROMPTS[FIELD_COUNT] = {
	"First Name",
	"Last Name",
	"Nick Name",
	"Phone Number",
	"Darkest Secret"
};

Contact::Contact():
	_firstName(""),
	_lastName(""),
	_nickName(""),
	_phoneNumber(""),
	_darkestSecret("")
	{}

Contact::Contact(const Contact &obj):
	_firstName(obj._firstName),
	_lastName(obj._lastName),
	_nickName(obj._nickName),
	_phoneNumber(obj._phoneNumber),
	_darkestSecret(obj._darkestSecret)
	{}

Contact &Contact::operator=(const Contact &obj) {
	if (this == &obj)
		return (*this);

	_firstName = obj._firstName;
	_lastName = obj._lastName;
	_nickName = obj._nickName;
	_phoneNumber = obj._phoneNumber;
	_darkestSecret = obj._darkestSecret;
	return (*this);
}

Contact::~Contact(){}

void	Contact::set_fisrtName(const std::string &fisrtName) {
	_firstName = fisrtName;
}

void	Contact::set_lastName(const std::string &lastName) {
	_lastName = lastName;
}

void	Contact::set_nickName(const std::string &nickName) {
	_nickName = nickName;
}

void	Contact::set_phoneNumber(const std::string &phoneNumber) {
	_phoneNumber = phoneNumber;
}

void	Contact::set_darkestSecret(const std::string &darkestSecret) {
	_darkestSecret = darkestSecret;
}

Contact::ContactSetter	Contact::setters[FIELD_COUNT] = {
	&Contact::set_fisrtName,
	&Contact::set_lastName,
	&Contact::set_nickName,
	&Contact::set_phoneNumber,
	&Contact::set_darkestSecret,
};

std::string	Contact::get_firsteName(void) const {
	return (_firstName);
}

std::string	Contact::get_lastName(void) const {
	return (_lastName);
}

std::string	Contact::get_nickName(void) const {
	return (_nickName);
}

std::string	Contact::get_phoneNumber(void) const {
	return (_phoneNumber);
}

std::string	Contact::get_darkestSecret(void) const {
	return (_darkestSecret);
}

Contact::ContactGetter	Contact::getters[FIELD_COUNT] = {
	&Contact::get_firsteName,
	&Contact::get_lastName,
	&Contact::get_nickName,
	&Contact::get_phoneNumber,
	&Contact::get_darkestSecret,
};
