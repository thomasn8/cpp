#include "Account.hpp"
#include <iostream>

// **************** Setter functions ****************
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
	if (this->checkAmount() < 0)
	{
		this->_amount += withdrawal; 
		this->_nbWithdrawals -= 1;
		std::cout << "withdrawal:" << "refused" << std::endl;
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

// *********** Instance getter functions ***********
void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbWithdrawals << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

// ************* Class getter functions ************
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

// **************** Datetime function ****************
void	Account::_displayTimestamp(void)
{
	time_t		rawtime;
	struct tm	*timeinfo;
	char		datetime[18];

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime(datetime,18,"[%Y%m%d_%H%M%S]",timeinfo);
	std::cout << datetime << " ";
}

// ***************** Constr./Destr *****************
Account::Account(int initial_deposit)
{
	// attributs de class
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;

	// attributs d'instance
	this->_accountIndex = Account::_nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	// logs
	Account::_displayTimestamp();
	std::cout << "index:" <<this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::Account(void)
{
	// attributs de class
	Account::_nbAccounts += 1;
	Account::_totalAmount += 0;

	// attributs d'instance
	this->_accountIndex = Account::_nbAccounts - 1;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	// logs
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	// attributs de class
	Account::_totalAmount -= _amount;
	Account::_nbAccounts -= 1;

	// logs
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return;
}

// initialisations des attributs de class
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
