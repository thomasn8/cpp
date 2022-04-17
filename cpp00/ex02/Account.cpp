#include "Account.hpp"
#include <iostream>
#include <time.h> 


// **************** Getter functions **************** //
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
	std::cout << "account:" << Account::getNbAccounts() << ";";
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
	static int	index = 0;

	// attributs de class
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	Account::_totalNbDeposits += 1;
	Account::_totalNbWithdrawals += 0;

	// attributs d'instance
	Account::_accountIndex = ++index;
	Account::_amount = initial_deposit;
	Account::_nbDeposits = 1;
	Account::_nbWithdrawals = 0;

	// logs
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex;
	std::cout << ";amount:" << Account::_amount;
	std::cout << "created" << std::endl;
}

// Account::Account(void)
// {
// 	return;
// }

Account::~Account(void)
{
	Account::_nbAccounts -= 1;
	return;
}