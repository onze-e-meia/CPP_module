/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:19:10 by tforster          #+#    #+#             */
/*   Updated: 2024/10/12 10:05:52 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_HPP
# define LIB_HPP

# include <string>

void		print_centered(const std::string &text, const int width, const char *format);
void		error_text(const std::string &text);

bool		str_all_digit(const std::string &str);
bool		str_all_space(const std::string &str);

std::string trim_spaces(const std::string &str);
std::string	strip_ansi(const std::string &input);
std::string	truncate(const std::string &str, const std::size_t width, const char ch);

#endif
