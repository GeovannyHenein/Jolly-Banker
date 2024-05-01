
#include "Transaction.h"
#include "stdafx.h"
#include "TransferTransaction.h"
TransferTransaction::TransferTransaction()
{
}

TransferTransaction::TransferTransaction(istream& istr)
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

		string secondID;
		istr >> secondID;
		int secondLength = secondID.length();
	
		if (secondLength  > MAX_ID_LENGTH || secondLength  < MAX_ID_LENGTH)
		{
			setValid(false);
			cerr << "Error: Invalid Account Input" << endl;
			
		}
		else
		{
		
			secondFundType = secondID[secondID.length() - 1] - '0';
			secondID.resize(secondID.length() - 1);
			secondaryID = stoi(secondID);
			setValid(true);
		}

	}	

}


TransferTransaction::~TransferTransaction()
{
}
bool TransferTransaction::IsValid() const
{
	return valid;
}
int TransferTransaction::getSecondaryID() const
{
	return secondaryID;
}

int TransferTransaction::getFundType() const
{
	return fundType;
}

int TransferTransaction::getSecondFundType() const
{
	return secondFundType;
}

int TransferTransaction::getAmount() const
{
	return amount;
}

string TransferTransaction::historyLog() const
{
	stringstream ss;
	string type;
	ss << getTransactionType();
	ss >> type;
	string retVal = type + " " + to_string(getAccountID()) + "" +
		to_string(getFundType()) + " " + to_string(getAmount()) +  " " + 
			to_string(getSecondaryID()) + "" + to_string(getSecondFundType());
	return retVal;
}

void TransferTransaction::setAmount(int amount)
{
	this->amount = amount;
}