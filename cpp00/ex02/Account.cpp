#include "Account.hpp"


Account::Account(int initial_deposit)
{
	static int i = 0;
	this->_amount = initial_deposit;
	this->_accountIndex = i++;
}