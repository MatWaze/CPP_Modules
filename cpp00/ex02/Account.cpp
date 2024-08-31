#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t currentTime = std::time(nullptr);

    std::tm* localTime = std::localtime(&currentTime);

    std::cout << "[" << (localTime->tm_year + 1900);
	if ((localTime->tm_mon + 1) < 10)
		std::cout << "0" << localTime->tm_mon + 1;
	else
		std::cout << localTime->tm_mon + 1;

	if (localTime->tm_mday < 10)
		std::cout << "0" << localTime->tm_mday << "_";
	else
		std::cout << localTime->tm_mday << "_";

	if (localTime->tm_hour < 10)
		std::cout << "0" << localTime->tm_hour;
    else
		std::cout << localTime->tm_hour;
	
	if (localTime->tm_min < 10)
        std::cout << "0" << localTime->tm_min;
	else
		std::cout << localTime->tm_min;
	
	if (localTime->tm_sec < 10)
		std::cout << "0" << localTime->tm_sec << "]";
	else
		std::cout << localTime->tm_sec << "]";
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();

	std::cout << " accounts:" << Account::getNbAccounts()
	<< ";total:" << Account::getTotalAmount()
	<< ";deposits:" << Account::getNbDeposits()
	<< ";withdrawals:" << Account::getNbWithdrawals()
	<< std::endl;
}

int Account::getNbAccounts()
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount()
{
	return Account::_totalAmount;
}

int Account::getNbDeposits()
{
	return Account::_totalNbDeposits;
}


int Account::getNbWithdrawals()
{
	return Account::_totalNbWithdrawals;
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	
	std::cout << " index:" << this->_accountIndex 
	<< ";amount:" << this->_amount 
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals 
	<< std::endl; 
}

Account::Account(int initial_deposit)
{
	static int i = 0;
	this->_amount = initial_deposit;
	this->_accountIndex = i++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;

	Account::_displayTimestamp();

	std::cout << " index:" << this->_accountIndex 
	<< ";amount:" << this->_amount 
	<< ";created" 
	<< std::endl; 
}

Account::~Account()
{
	Account::_displayTimestamp();

	std::cout << " index:" << this->_accountIndex 
	<< ";amount:" << this->_amount 
	<< ";closed" 
	<< std::endl; 
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();

	std::cout << " index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount 
	<< ";deposit:" << deposit;

	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;

	std::cout << ";amount:" << this->_amount
	<< ";nb_deposits:" << this->_nbDeposits
	<< std::endl;

	Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	bool	ans = false;
	Account::_displayTimestamp();

	std::cout << " index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount;

	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused";
	}
	else
	{
		ans = true;
		std::cout << ";withdrawal:" << withdrawal;

		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;

		std::cout << ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals;
	}
	std::cout << std::endl;
	return ans;
}
