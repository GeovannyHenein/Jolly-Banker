#include "stdafx.h"
#include "DepositTransaction.h"

DepositTransaction::DepositTransaction()
{
}
DepositTransaction::DepositTransaction(istream& istr)
{
	string ID;

	istr >> ID;
	int length = ID.length();
	if (length > MAX_ID_LENGTH || length < MAX_ID_LENGTH)
	{
		setValid(false);
		cerr << "Error: Invalid Account Input" << endl;
		
	}
	else
	{
		fundType = ID[ID.length() - 1] - '0';
		ID.resize(ID.length() - 1);
		accountID = stoi(ID);
		istr >> amount;
		setValid(true);
	}
}

DepositTransaction::~DepositTransaction()
{
}

int DepositTransaction::getAmount() const
{
	return amount;
}

string DepositTransaction::historyLog() const
{
	string retVal = Transaction::historyLog();
	retVal += " " + to_string(getAmount());
	return retVal;
}

void DepositTransaction::setAmount(int amount)
{
	this->amount = amount;
}
bool DepositTransaction::IsValid() const
{
	return valid;
}
