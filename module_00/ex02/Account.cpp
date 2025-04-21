#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void ) //fazer correcao
{
	std::time_t	timestamp = std::time(0);

	std::cout << "[" << timestamp << "] ";
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++), _amount(initial_deposit) 
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< _amount << ";created" << std::endl;
	return ;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< _amount << ";closed" << std::endl;
	return ;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:"
		<< Account::getTotalAmount() << ";deposits:" 
		<< Account::getNbDeposits() << ";withdrawals:"
		<< Account::getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}
