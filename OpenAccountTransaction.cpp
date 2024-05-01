#include "stdafx.h"
#include "OpenAccountTransaction.h"


OpenAccountTransaction::OpenAccountTransaction()
{
}

OpenAccountTransaction::OpenAccountTransaction(istream& istr)
{
	istr >> lastName;
	istr >> firstName;
	string ID;
	istr >> ID;
	int length = ID.length();
	if (length != 4)
	{
		setValid(false);
		cerr << "Error: Invalid Account Input" << endl;
		
	}
	else
	{
		accountID = stoi(ID);
		setValid(true);
	}
}

bool OpenAccountTransaction::IsValid() const
{
	return valid;
}

OpenAccountTransaction::~OpenAccountTransaction()
{
}
string OpenAccountTransaction::getFirstName() const
{
	return firstName;
}
string OpenAccountTransaction::getLastName() const
{
	return lastName;
}