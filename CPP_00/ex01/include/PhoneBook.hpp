/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:28:06 by tforster          #+#    #+#             */
/*   Updated: 2024/10/14 13:46:44 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define HEADER_WIDTH	55
# define TOTAL_CONTACS	8

class PhoneBook
{
	private:
		Contact		_contacts[TOTAL_CONTACS];
		int			_index;
		int			_nb_contacts;
		bool		_over_load;

		static bool			_buffer_over_load(const bool over_load);
		static std::string	_get_values(const std::size_t i);
		static std::string	_table_line(const std::string &str);
		static void			_display_contact(const Contact &contact);
		static std::string	_field_name(const std::size_t i);
		static bool			_clear_prompt(const bool err);

	public:
		// Default constructor
		PhoneBook();

		// Destructor
		~PhoneBook();

		// Methods
		void	add_contact(void);
		void	pick_contact(void) const;
		void	search_contact(void) const;
};

#endif
