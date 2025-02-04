/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:31:15 by tforster          #+#    #+#             */
/*   Updated: 2025/02/04 17:19:36 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BtcXchg {
	private:
		static const char							*_PATH;
		static std::map<std::string, std::string>	_BTC_DB;
		std::string									_input;
		std::map<std::string, std::string>			_xchg_db;

		static void	build_btc_db(void);
		void		build_exchg_db(void);


		// void	build_btc_db(void);
		// std::map<std::string, std::string>	build_btc_db(void);

	public:
		BtcXchg(void);
		BtcXchg(const std::string &input);
		BtcXchg(const BtcXchg &other);
		BtcXchg &operator=(const BtcXchg &other);
		~BtcXchg(void);

		void	xchg(const BtcXchg btc_xchg);
		void	printData() const;
		void	printXchg() const;

};

#endif
