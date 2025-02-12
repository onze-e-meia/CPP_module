/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:10:02 by tforster          #+#    #+#             */
/*   Updated: 2025/02/12 17:22:24 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <string>
#include <fstream>

bool	str_all_space(const std::string &str);
std::ifstream *openFile(const std::string &path);
bool	isValidDay(int year, int month, int day);
bool isValidDate(const char *ptr, const std::string &rawDate,
	const std::string &line, std::tm &tmS, std::time_t startDate, int i);
void printLog (std::time_t dateValue, int i);
