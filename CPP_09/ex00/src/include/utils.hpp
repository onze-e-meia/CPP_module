/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:10:02 by tforster          #+#    #+#             */
/*   Updated: 2025/02/14 17:54:02 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <string>
#include <fstream>

bool			str_all_space(const char *str);
bool			errLog(const char *type, const std::string &string, int i);
std::ifstream	*openFile(const std::string &path);
bool			isValidDay(int year, int month, int day);
bool			isStartDate(std::tm &tmS, std::time_t startDate, int i);
bool 			isValidDate(const char *timeLeftOver, const std::string &rawTime,
					std::tm &tmS, std::time_t startDate, int i);
void			printLog (std::time_t dateValue, float value, float xchg, int i);
