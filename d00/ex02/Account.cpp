#include <iostream>
#include <ctime>
#include "Account.class.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << 
		";deposits:" << Account::getNbDeposits() << ";withdrawals:" << 
		Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = Account::getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << 
		";created" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount <<
		";deposit:" << deposit << ";amount:";
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	this->_amount += deposit;
	std::cout << this->_amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount <<
		";withdrawal:";
	if (withdrawal <= this->_amount)
	{
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" <<
			this->_nbWithdrawals << std::endl;
		return true;
	}
	else
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	return false;
}

int Account::checkAmount() const { return this->_amount; }

void Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << 
		";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << 
		std::endl;
}

void Account::_displayTimestamp()
{
	time_t t = time(NULL);
	tm *my_time = localtime(&t);
	char *b_time = new char[19];
	strftime(b_time, 19, "[%Y%m%d_%H%M%S] \0", my_time);
	std::cout << b_time;
}

Account::~Account() 
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount <<
		";closed" << std::endl;
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
}

int Account::getNbAccounts() { return Account::_nbAccounts; }
int Account::getTotalAmount() { return Account::_totalAmount; }
int Account::getNbDeposits() { return Account::_totalNbDeposits; }
int Account::getNbWithdrawals() { return Account::_totalNbWithdrawals; }
