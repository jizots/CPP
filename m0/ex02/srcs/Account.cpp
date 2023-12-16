#include "Account.hpp"
#include <time.h>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void    Account::_displayTimestamp(void)
{
	time_t  	tmp;
	struct tm	*timeinfo;

	time(&tmp);
	timeinfo = localtime(&tmp);

	std::cout << '['\
	<< timeinfo->tm_year + 1900 << timeinfo->tm_mon + 1 << timeinfo->tm_mday\
	<< '_'\
	<< timeinfo->tm_hour << timeinfo->tm_min << timeinfo->tm_sec\
	<< ']' << ' ';
}

void    Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ';';
	std::cout << "total:" << Account::getTotalAmount();
	std::cout << ';';
	std::cout << "deposits:" << Account::getNbDeposits();
	std::cout << ';';
	std::cout << "withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
}

Account::Account(int deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ';';
	std::cout << "amount:" << _amount;
	std::cout << ';';
	std::cout << "created";
	std::cout << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ';';
	std::cout << "amount:" << _amount;
	std::cout << ';';
	std::cout << "closed";
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ';';
	std::cout << "p_amount:" << _amount;
	std::cout << ';';
	std::cout << "deposit:" << deposit;
	std::cout << ';';
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "amount:" << _amount;
	std::cout << ';';
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ';';
	std::cout << "p_amount:" << _amount;
	std::cout << ';';
	if (_amount >= withdrawal)
	{
		std::cout << "withdrawal:" << withdrawal;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << ';';
		std::cout << "amount:" << _amount;
		std::cout << ';';
		std::cout << "nb_withdrawals:" << _nbWithdrawals;
		std::cout << std::endl;
		return (true);
	}
	std::cout << "withdrawal:" << "refused";
	std::cout << std::endl;
	return (false);
};

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ';';
	std::cout << "amount:" << _amount;
	std::cout << ';';
	std::cout << "deposits:" << _nbDeposits;
	std::cout << ';';
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

