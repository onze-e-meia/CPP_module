/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:33:18 by tforster          #+#    #+#             */
/*   Updated: 2025/01/08 13:37:37 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "../include/Account.hpp"
#include "../include/color.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) :
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout
		<< "index:" L_BLU << _accountIndex << RST << ";"
		<< "amount:" L_BLU << _amount << RST << ";"
		<< "created"
		<< std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout
		<< "index:" L_BLU << _accountIndex << RST << ";"
		<< "amount:" L_BLU << _amount << RST << ";"
		<< "closed"
		<< std::endl;
}

int Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int Account::getTotalAmount(void) {
	return (_totalAmount);
}

int Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout
		<< "accounts:" L_BLU << _nbAccounts << RST << ";"
		<< "total:" L_BLU << _totalAmount << RST << ";"
		<< "deposits:" L_BLU << _totalNbDeposits << RST << ";"
		<< "withdrawals:" L_BLU << _totalNbWithdrawals << RST
		<< std::endl;
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout
		<< "index:" L_BLU << _accountIndex << RST << ";"
		<< "amount:" L_BLU << _amount << RST << ";"
		<< "deposits:" L_BLU << _nbDeposits << RST << ";"
		<< "withdrawals:" L_BLU << _nbWithdrawals << RST
		<< std::endl;
}

void	Account::makeDeposit(int deposit) {
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;

	_displayTimestamp();
	std::cout
		<< "index:" L_BLU << _accountIndex << RST << ";"
		<< "p_amount:" L_BLU << _amount << RST << ";"
		<< "deposits:" L_BLU << deposit << RST << ";";
	_amount += deposit;
	std::cout << "amount:" L_BLU << _amount << RST  << ";"
		<< "deposits:" L_BLU << _nbDeposits << RST
		<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (checkAmount() > withdrawal) {
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
	}
	else
		withdrawal = 0;
	std::cout
		<< "index:" L_BLU << _accountIndex << RST << ";"
		<< "p_amount:" L_BLU << _amount << RST << ";";
	if (withdrawal > 0) {
		std::cout
			<< "withdrawal:" L_BLU << withdrawal << RST << ";";
		_amount -= withdrawal;
		std::cout << "amount:" L_BLU << _amount << RST  << ";"
			<< "nb_withdrawals:" L_BLU << _nbDeposits << RST
			<< std::endl;
		return (true);
	}
	std::cout << "withdrawal:refused" << std::endl;
	return (false);
}

int		Account::checkAmount( void ) const {
	return (_amount);
}

void	Account::_displayTimestamp( void ) {
	char		buffer[20];
	std::time_t	now = std::time(0);
	std::tm		*ltm = std::localtime(&now);

	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", ltm);
	std::cout << buffer;
}
