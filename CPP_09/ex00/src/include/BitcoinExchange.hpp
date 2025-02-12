/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:31:15 by tforster          #+#    #+#             */
/*   Updated: 2025/02/12 18:23:28 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <ctime>
#include <map>
#include <string>

class BtcXchg {
	private:
		static const char							*_PATH;
		static	std::map<std::time_t, std::string>	_BTC_DB;
		static	int									_status;
		static	std::time_t							_statrtDate;
		std::string									_input;

		void	checkStatus(void);
		void	setStatus(int status, const std::string &str);
		bool	validate(const std::string &line, std::tm &tmS, char delin, int i);
		void	buildDB(void);

	public:
		BtcXchg(void);
		BtcXchg(const std::string &input);
		BtcXchg(const BtcXchg &other);
		BtcXchg &operator=(const BtcXchg &other);
		~BtcXchg(void);

		void	xchgLog(void);
};

#endif
