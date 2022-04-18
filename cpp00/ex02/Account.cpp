#include "Account.hpp"
#include <iostream>
#include <time.h> 

// **************** Setter functions **************** //
void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit; 
	this->_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	this->_amount -= withdrawal; 
	this->_nbWithdrawals += 1;
	if (this->checkAmount() >= 0)
	{
		this->_amount += withdrawal; 
		this->_nbWithdrawals -= 1;
		std::cout << "withdrawal:" << "refused";
		return (false);
	}
	else
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals += 1;
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return (true);
}

// *********** Instance getter functions *********** //
void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbWithdrawals << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

// ************* Class getter functions ************ //
int		Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int		Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

// **************** Datetime function **************** //
void	Account::_displayTimestamp(void)
{
	time_t		rawtime;
	struct tm	*timeinfo;
	char		datetime[15+1];

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime(datetime,15+1,"[%Y%m%d_%H%M%S]",timeinfo);
	std::cout << datetime << " ";
}

// ***************** Constr./Destr ***************** //
Account::Account(int initial_deposit)
{
	// attributs de class
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	Account::_totalNbDeposits += 1;
	Account::_totalNbWithdrawals += 0;

	// attributs d'instance
	Account::_accountIndex += 1;
	Account::_amount = initial_deposit;
	Account::_nbDeposits = 1;
	Account::_nbWithdrawals = 0;

	// logs
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "created" << std::endl;
}

Account::Account(void)
{
	// attributs de class
	Account::_nbAccounts += 1;
	Account::_totalAmount += 0;
	Account::_totalNbDeposits += 0;
	Account::_totalNbWithdrawals += 0;

	// attributs d'instance
	Account::_accountIndex += 1;
	Account::_amount = 0;
	Account::_nbDeposits = 1;
	Account::_nbWithdrawals = 0;

	// logs
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	// attributs de class
	Account::_totalAmount -= _amount;
	Account::_nbAccounts -= 1;

	// logs
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "closed" << std::endl;
	return;
}
