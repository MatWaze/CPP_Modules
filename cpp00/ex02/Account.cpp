#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	static int i = 0;
	this->_amount = initial_deposit;
	this->_totalAmount += this->_amount;
	this->_accountIndex = i++;
}

void Account::makeDeposit(int deposit)
{
	this->_amount = deposit;
	this->_totalAmount += this->_amount;
}