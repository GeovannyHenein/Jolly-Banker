#include "stdafx.h"
#include "Transaction.h"
#include <sstream>


Transaction::Transaction()
{
	valid = true;
}

Transaction::~Transaction()
{
}
char Transaction::getTransactionType() const
{
	return charType;
}
void Transaction::setTransactionType(char Type)
{
	charType = Type;
}
int Transaction::getAccountID() const
{
	return accountID;
}


int Transaction::getFundType() const
{
	return fundType;
}

void Transaction::setAccountID(int ID)
{
	accountID = ID;
}

void Transaction::setAmount(int amount)
{

}
string Transaction::historyLog() const
{
	stringstream ss;
	string type;
	ss << getTransactionType();
	ss >> type;
	string retVal = type + " " + to_string(getAccountID()) + "" +
		to_string(getFundType());
	return retVal;
}

bool Transaction::IsValid() const
{
	return valid;
}
void Transaction::setValid(bool valid)
{
	this->valid = valid;
}