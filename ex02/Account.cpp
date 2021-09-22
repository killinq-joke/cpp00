/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:24:35 by ztouzri           #+#    #+#             */
/*   Updated: 2021/07/08 15:31:37 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

void	printtimestamp( void )
{
	time_t	now = time(0);
	tm	*ltm = localtime(&now);

	std::cout << "[" << 1900 + ltm->tm_year;
	if (ltm->tm_mon < 10)
		std::cout << "0";
	std::cout << ltm->tm_mon;
	if (ltm->tm_mday < 10)
		std::cout << "0";
	std::cout << ltm->tm_mday << "_";
	if (ltm->tm_hour < 10)
		std::cout << "0";
	std::cout << ltm->tm_hour;
	if (ltm->tm_min < 10)
		std::cout << "0";
	std::cout << ltm->tm_min;
	if (ltm->tm_sec < 10)
		std::cout << "0";
	std::cout << ltm->tm_sec << "]";
}

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0)
{
	static int	i = 1;

	Account::_totalAmount += _amount;
	Account::_totalNbDeposits += _nbDeposits;
	Account::_nbAccounts++;
	this->_accountIndex = i++;
	this->_nbWithdrawals = 0;
}

Account::~Account(void)
{
	printtimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_totalAmount += deposit;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	this->_nbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > this->_amount)
		return (false);
	Account::_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	this->_nbWithdrawals += 1;
	return (true);
}

int	Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	printtimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	printtimestamp();
	std::cout << " accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
