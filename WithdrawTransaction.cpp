#include "stdafx.h"
#include "WithdrawTransaction.h"


WithdrawTransaction::WithdrawTransaction()
{
}

WithdrawTransaction::~WithdrawTransaction()
{
}

WithdrawTransaction::WithdrawTransaction(istream& istr)
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

int WithdrawTransaction::getAmount() const
{
	return amount;
}

string WithdrawTransaction::historyLog() const
{
	string retVal = Transaction::historyLog();
	retVal += " " + to_string(amount);
	return retVal;
}

void WithdrawTransaction::setAmount(int amount)
{
	this->amount = amount;
}

bool WithdrawTransaction::IsValid() const
{
	return valid;
}